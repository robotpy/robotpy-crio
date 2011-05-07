import wpilib
from Config import *

__all__ = ["Autonomous"]

class Autonomous:
    def __init__(self, kicker):
        self.kicker = kicker
        self.autoMode = 1

    def DisplayMode(self):
        dselcd = wpilib.DriverStationLCD.GetInstance()
        autoModes = [
            ("do nothing", "do nothing"),
            ("far 8ft 0s", "kick everything for 8 ft in far zone, no delay"),
            ("far 8ft 1s", "kick everything for 8 ft in far zone, 1 sec delay"),
            ("far 8ft 2s", "kick everything for 8 ft in far zone, 2 sec delay"),
            ("mid 8ft 0s", "kick everything for 8 ft in mid zone, no delay"),
            ("mid 8ft 1s", "kick everything for 8 ft in mid zone, 1 sec delay"),
            ("mid 8ft 2s", "kick everything for 8 ft in mid zone, 2 sec delay"),
            ("near 8ft 0s", "near zone"),
            ("far 0s over", "kick everything for 8 ft in far zone, no delay, drive over bump"),
            ("far 0s over bounce", "Autonomous kick everything for 8 ft in far zone, no delay, with bounce")]

        dselcd.PrintLine(wpilib.DriverStationLCD.kUser_Line1,
                         "A%d: %s" % (self.autoMode, autoModes[self.autoMode][0]))
        print("Autonomous %s" % autoModes[self.autoMode][1])
        dselcd.UpdateLCD()

    def SelectMode(self, down, up):
        display = False
        if down:
            self.autoMode -= 1
            display = True
        elif up:
            self.autoMode += 1
            display = True

        if self.autoMode < 0:
            self.autoMode = 0
            display = False
        elif self.autoMode > 9:
            self.autoMode = 9
            display = False

        if display:
            self.DisplayMode()

    def Run(self):
        wpilib.GetWatchdog().SetExpiration(1.0)
        wpilib.GetWatchdog().SetEnabled(True)
        time = wpilib.Timer()
        haveTime = wpilib.Timer()
        waitTime = wpilib.Timer()

        ResetDriveEncoders()
        kickerEncoder.Reset() #zeroing kicker

        time.Start()
        haveTime.Start()
        waitTime.Start()

        prevState = -1
        state = 0
        i = 0
        kickPower = 188
        kickPowerFar = [188 + 66, 188 + 66, 152 + 66, 152 + 33, 152 + 33]
        #kickPowerFar = [50, 50, 50, 50, 50]
        kickPowerFarBounce = [188 - 66, 188 - 99, 152 - 66, 152 - 66, 152 - 66]
        kickPowerMid = [50 + 33, 50 + 33, 50 + 33, 50 + 33, 50 + 33]
        kickPowerNear = [0]*5
        ballsKicked = 0
        intakeSpeed = -1.0

        # Set up kick power for each mode
        autoConfig = [
            (kickPowerNear, 0.0),       # do nothing
            (kickPowerFar, 0.0),        # 1
            (kickPowerFar, 1.0),        # 2
            (kickPowerFar, 2.0),        # 3
            (kickPowerMid, 0.0),        # 4
            (kickPowerMid, 1.0),        # 5
            (kickPowerMid, 2.0),        # 6
            (kickPowerNear, 0.0),       # 7
            (kickPowerFar, 0.0),        # 8
            (kickPowerFarBounce, 0.0)]  # 9
        kickPowerUse, startDelay = autoConfig[self.autoMode]

        while wpilib.IsAutonomous() and wpilib.IsEnabled():
            CheckRestart()
            wpilib.GetWatchdog().Feed()

            # check the kicker pneumatics
            self.kicker.AutoPeriodic()

            # always run the intake motor
            intakeMotor.Set(intakeSpeed)
            if prevState != state:
                print("AUTO mode:%d state:%d" % (self.autoMode, state))
            prevState = state

            # ball detection
            if not HaveBall():
                haveTime.Reset()

            i += 1

            if (self.autoMode >= 1 and self.autoMode <= 6 or self.autoMode == 8
                    or self.autoMode == 9):
                # drive forward and auto-kick
                if state == 0:
                    # Wait to start
                    if time.Get() > startDelay:
                        state = 1
                elif state == 1:
                    # Drive forward while setting up for kick
                    if i%8 == 0:
                        print("S0: moving to ball; winch:%d" % kickerEncoder.Get())
                    self.kicker.AutoArm(kickPowerUse[ballsKicked])
                    drive.ArcadeDrive(-0.5, 0.0, False) # half speed drive

                    if time.Get() > 0.25 and HaveBall():
                        print("GOT BALL!!")
                        # got a ball; kick it!
                        drive.ArcadeDrive(0.0, 0.0, False)
                        state = 2

                    if leftDriveEncoder.Get() > 102*gDriveTicksPerInch:
                        state = 4
                    # stop after 2 balls kicked in mid zone
                    if (self.autoMode >= 4 and self.autoMode <= 6 and
                            ballsKicked >= 2):
                        state = 4
                    # stop after 3 balls kicked in far zone
                    if ((self.autoMode == 8 or self.autoMode == 9) and
                            ballsKicked >= 3):
                        state = 4
                elif state == 2:
                    # wait until we're ready to fire, then fire!
                    if i%8 == 0:
                        print("S1: firing ball; winch:%d" % kickerEncoder.Get())
                    if self.kicker.AutoArm(kickPowerUse[ballsKicked]):
                        self.kicker.Fire()
                        ballsKicked += 1
                        if ballsKicked > 4:
                            ballsKicked = 4
                        state = 3
                elif state == 3:
                    # wait until we finished kicking
                    if i%8 == 0:
                        print("S2: waiting to finish kick")
                    if self.kicker.IsKickComplete():
                        state = 1
                elif state == 4:
                    if self.autoMode >= 4 and self.autoMode <= 6:
                        # mid zone modes
                        state = 5
                    elif self.autoMode == 8 or self.autoMode == 9:
                        # far zone go over bump
                        state = 8
                    else:
                        state = 20
                elif state == 5:
                    # back up
                    self.kicker.AutoArm(kickPowerUse[ballsKicked])
                    drive.ArcadeDrive(1.0, 0.0, False)
                    if leftDriveEncoder.Get() < 24*gDriveTicksPerInch:
                        waitTime.Reset()
                        state = 6
                elif state == 6:
                    # spin 90 deg
                    self.kicker.AutoArm(kickPowerUse[ballsKicked])
                    drive.ArcadeDrive(0.0, 0.85, False)
                    if waitTime.Get() > 0.85:
                        state = 20
                elif state == 8:
                    # dry kick before driving over bump if we're armed
                    if self.kicker.armed:
                        # finish arming and fire
                        if self.kicker.AutoArm(kickPowerUse[ballsKicked]):
                            FireKicker()
                            state = 9
                    else:
                        state = 10
                elif state == 9:
                    if self.kicker.IsKickComplete():
                        state = 10
                elif state == 10:
                    # drive over bump
                    intakeSpeed = 1.0 # run roller out so we don't get penalties
                    self.kicker.AutoArm(kickPowerUse[ballsKicked], False)
                    if leftDriveEncoder.Get() > (96+36)*gDriveTicksPerInch:
                        waitTime.Reset()
                        state = 11
                    drive.ArcadeDrive(-0.5, 0.0, False) # drive forward
                elif state == 11:
                    self.kicker.AutoArm(kickPowerUse[ballsKicked], False)
                    drive.ArcadeDrive(-0.85, 0.0, False) # drive forward higher power
                    if waitTime.Get() > 3.0:
                        state = 20
                elif state == 20:
                    # make sure we winch back so we don't get a penalty
                    if i%8 == 0:
                        print("S10: done")
                    self.kicker.AutoArm(kickPowerUse[ballsKicked], False)
                    drive.ArcadeDrive(0.0, 0.0, False)
            elif self.autoMode == 7:
                # near zone: drive forward and auto-kick 1 ball, then back up
                if state == 0:
                    # Wait to start
                    if time.Get() > startDelay:
                        state = 1
                elif state == 1:
                    # Drive forward while setting up for kick
                    if i%8 == 0:
                        print("S0: moving to ball; winch:%d" % kickerEncoder.Get())
                    self.kicker.AutoArm(kickPowerNear[0])
                    drive.ArcadeDrive(-0.5, 0.0, False) # half speed drive
                    if time.Get() > 0.25 and haveTime.Get() > 0.25:
                        print("GOT BALL!!")
                        # got a ball; kick it!
                        drive.ArcadeDrive(0.0, 0.0, False)
                        state = 2
                    if leftDriveEncoder.Get() > 6*12*gDriveTicksPerInch:
                        state = 4
                elif state == 2:
                    # wait until we're ready to fire, then fire!
                    if i%8 == 0:
                        print("S1: firing ball; winch:%d" % kickerEncoder.Get())
                    if self.kicker.AutoArm(kickPowerNear[0]):
                        self.kicker.Fire()
                        state = 3
                elif state == 3:
                    # wait until we finished kicking
                    if i%8 == 0:
                        print("S2: waiting to finish kick")
                    if self.kicker.IsKickComplete():
                        state = 4
                elif state == 4:
                    if i%8 == 0:
                        print("S4: driving back")
                    drive.ArcadeDrive(1.0, 0.0, False) # full speed drive backwards
                    if leftDriveEncoder.Get() < 24*gDriveTicksPerInch:
                        waitTime.Reset()
                        state = 5
                    if (self.kicker.IsKickComplete() and
                            self.kicker.AutoArm(kickPowerNear[0]) and
                            haveTime.Get() > 0.25):
                        self.kicker.Fire()
                elif state == 5:
                    if i%8 == 0:
                        print("S5: wait to drive forward again")
                    if (self.kicker.IsKickComplete() and
                            self.kicker.AutoArm(kickPowerNear[0]) and
                            haveTime.Get() > 0.25):
                        self.kicker.Fire()
                    if waitTime.Get() > 5.0:
                        state = 6
                elif state == 6:
                    if i%8 == 0:
                        print("S5: drive forward slowly kicking balls again")
                    if (self.kicker.IsKickComplete() and
                            self.kicker.AutoArm(kickPowerNear[0]) and
                            haveTime.Get() > 0.25):
                        self.kicker.Fire()
                    drive.ArcadeDrive(-0.35, 0.0, False) # quarter speed drive
                    if leftDriveEncoder.Get() > 10*12*gDriveTicksPerInch:
                        state = 10
                elif state == 10:
                    # make sure we winch back so we don't get a penalty
                    if i%8 == 0:
                        print("S10: done")
                    if (self.kicker.IsKickComplete() and
                            self.kicker.AutoArm(kickPowerNear[0]) and
                            haveTime.Get() > 0.25):
                        self.kicker.Fire()
                    drive.ArcadeDrive(0.0, 0.0, False)

            wpilib.Wait(0.01)

