import wpilib
from Config import *
from Kicker import *
from Autonomous import *

class MyRobot(wpilib.SimpleRobot):
    def __init__(self):
        super().__init__()
        self.kicker = Kicker()
        self.auto = Autonomous(self.kicker)

    def RobotInit(self):
        wpilib.Wait(0.25)
        winchControl.SetOutputRange(-1.0, 1.0)
        kickerEncoder.Start()
        leftDriveEncoder.Start()
        rightDriveEncoder.Start()
        compressor.Start()

    def Disabled(self):
        rPrevious = False
        lPrevious = False
        self.auto.DisplayMode()

        while self.IsDisabled():
            CheckRestart()

            self.auto.SelectMode(lstick.GetTrigger() and not lPrevious,
                                 rstick.GetTrigger() and not rPrevious)
            rPrevious = rstick.GetTrigger()
            lPrevious = lstick.GetTrigger()

            wpilib.Wait(0.01)

    def Autonomous(self):
        self.auto.Run()

    def OperatorControl(self):
        dog = self.GetWatchdog()
        dog.SetEnabled(True)
        dog.SetExpiration(0.25)
        shiftTime = wpilib.Timer()
        haveTime = wpilib.Timer()

        shiftTime.Start()
        haveTime.Start()

        intakeVelocity = -0.75

        while self.IsOperatorControl() and self.IsEnabled():
            dog.Feed()
            CheckRestart()

            if not HaveBall():
                haveTime.Reset()

            # Reset pneumatics
            if shiftTime.Get() > 0.3:
                shifter1.Set(False)
                shifter2.Set(False)

            # Kicker control
            self.kicker.OperatorControl()

            # Drive control
            drive.TankDrive(lstick, rstick)

            # Shifter control
            if rstick.GetTrigger():
                shifter1.Set(True)
                shifter2.Set(False)
                shiftTime.Reset()
            elif lstick.GetTrigger():
                shifter1.Set(False)
                shifter2.Set(True)
                shiftTime.Reset()

            # Intake motor
            if stick3.GetRawButton(6):
                intakeVelocity = 1.0
            elif stick3.GetRawButton(7):
                intakeVelocity = -0.75
            elif stick3.GetRawButton(8):
                intakeVelocity = 0.0
            #elif rstick.GetRawButton(11):
            #    intakeVelocity = 0.75

            # The motors are stopped when kicking; start them up again after
            # timeout
            if self.kicker.kickTime.Get() > 0.1:
                if (haveTime.Get() > 2.0 and intakeVelocity < 0.0
                    and lstick.GetY() <= 0.0 and rstick.GetY() <= 0.0):
                    intakeMotor.Set(-0.35)
                else:
                    intakeMotor.Set(intakeVelocity)

            wpilib.Wait(0.01)

def run():
    robot = MyRobot()
    robot.StartCompetition()

