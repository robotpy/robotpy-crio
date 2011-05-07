import wpilib
from Config import *

__all__ = ["Kicker"]

class Kicker:
    def __init__(self):
        self.armed = False
        self.retraction = 0
        self.winchTarget = 0
        self.kickTime = wpilib.Timer()
        self.pneumaticTime = wpilib.Timer()

        self.kickTime.Start()
        self.pneumaticTime.Start()

        self.prevFrontLimitSwitch = frontLimitSwitch.Get()
        self.raw10Previous = False
        self.raw11Previous = False

    def RunWinch(self):
        """Winch control of kicker (used in both auto and teleop).
        Returns True when winch target reached."""
        if self.IsWinchOnTarget():
            winchControl.Disable()
            return True
        # Use PID control
        winchControl.Enable()
        winchControl.SetSetpoint(self.winchTarget)
        if self.armed:
            winchControl.SetPID(-1.0/50.0, 0.0, -1.0/50.0)
        else:
            winchControl.SetPID(-1.0/30.0, 0.0, 0.0)
        return self.IsWinchOnTarget()

    def IsWinchOnTarget(self):
        if self.winchTarget >= gWinchFull and backLimitSwitch.Get() == 0:
            return True
        error = kickerEncoder.Get() - self.winchTarget
        if error < -gWinchDeadband:
            return False
        elif error > gWinchDeadband:
            return False
        else:
            return True

    def IsKickComplete(self):
        return self.kickTime.Get() > gWinchWaitTime

    def Arm(self):
        ratchet1.Set(True)
        ratchet2.Set(False)
        self.armed = True
        self.pneumaticTime.Reset()
        print("ARMED!!")

    def Fire(self):
        intakeMotor.Set(0.0)
        ratchet1.Set(False)
        ratchet2.Set(True)
        self.armed = False
        self.pneumaticTime.Reset()
        self.kickTime.Reset()
        print("KICKED!!")

    def ClearRatchetPneumatics(self):
        ratchet1.Set(False)
        ratchet2.Set(False)

    def AutoArm(self, power, do_arm=True):
        """Autonomous-only arming of kicker.
        Returns True when kicker is ready to fire."""
        if not self.armed:
            # winch back
            self.winchTarget = power
            if self.RunWinch() and do_arm:
                self.Arm()      # arm when we're done winching back
        else:
            # we're armed, so unwinch
            self.winchTarget = -gWinchOut
            if self.RunWinch() and self.kickTime.Get() > gBetweenKickTime:
                return True     # armed and ready to fire!
        return False

    def AutoPeriodic(self):
        # Reset pneumatics
        if self.pneumaticTime.Get() > 0.3:
            self.ClearRatchetPneumatics()

    def OperatorControl(self):
        # Reset pneumatics
        if self.pneumaticTime.Get() > 0.3:
            self.ClearRatchetPneumatics()

        # Set kicker strength
        if stick3.GetRawButton(3):
            self.retraction = 50 + 33
        elif stick3.GetRawButton(5):
            self.retraction = 188 + 66
        elif stick3.GetRawButton(4):
            self.retraction = 0

        # Kicker debug code
        if stick3.GetRawButton(10) and not self.raw10Previous:
            self.retraction -= 33
        elif stick3.GetRawButton(11) and not self.raw11Previous:
            self.retraction += 33
        self.raw10Previous = stick3.GetRawButton(10)
        self.raw11Previous = stick3.GetRawButton(11)

        if self.retraction < 0:
            self.retraction = 0
        elif self.retraction > gWinchFull:
            self.retraction = gWinchFull

        # Kicker arm and fire control
        if not self.armed:
            # wait after kick before starting to winch back
            if self.IsKickComplete():
                self.winchTarget = self.retraction
                if self.IsWinchOnTarget():
                    # auto arming mode
                    autoArm = False  #not dseio.GetDigital(15)

                    # arm; this starts the unwinch
                    if (stick3.GetTop() and not autoArm) or autoArm:
                        self.Arm()
        else: # armed
            # unwinch
            self.winchTarget = -gWinchOut
            if kickerEncoder.Get() < (self.winchTarget + gWinchDeadband):
                pass#dseio.SetDigitalOutput(3, 1)
            # fire!
            if (self.kickTime.Get() > gBetweenKickTime
                and kickerEncoder.Get() < (self.winchTarget + gWinchDeadband)
                and stick3.GetTrigger()):
                self.Fire()

        # manual control override on winch
        if stick3.GetRawButton(9):
            winchControl.Disable()
            kickerMotor.Set(stick3.GetY())
            self.armed = False
            self.retraction = 0

            # Kicker auto-zero using front limit switch rising edge
            # (pressed -> not pressed)
            # XXX: how does this interact with PID?
            if (frontLimitSwitch.Get() == 1
                and self.prevFrontLimitSwitch == 0):
                kickerEncoder.Reset()   # zeroing kicker
            self.prevFrontLimitSwitch = frontLimitSwitch.Get()
        else:
            # automatic winch control
            #if i%20 == 0:
            #    print("E: %i" % kickerEncoder.Get())
            #    print("T: %i" % self.winchTarget)
            #    print("BL: %i  TL: %i" % (self.winchTarget-gWinchDeadband,
            #                              self.winchTarget+gWinchDeadband))
            #    print("")
            self.RunWinch()

        # Manual override on kicker pneumatic
        if rstick.GetTop():
            ratchet1.Set(True)
            ratchet2.Set(False)
            self.pneumaticTime.Reset()
        elif lstick.GetTop():
            ratchet1.Set(False)
            ratchet2.Set(True)
            self.pneumaticTime.Reset()

