import wpilib

class MyRobot(wpilib.SimpleRobot):
    def __init__(self):
        super().__init__()
        self.dog = self.GetWatchdog()
        self.stick1 = wpilib.Joystick(1)
        self.stick2 = wpilib.Joystick(2)
        self.stick3 = wpilib.Joystick(3)

        self.leftArmStick = wpilib.KinectStick(1)
        self.rightArmStick = wpilib.KinectStick(2)

        self.motor1 = wpilib.CANJaguar(1)
        self.motor2 = wpilib.CANJaguar(2)

        self.leftArm = wpilib.Servo(1)
        self.rightArm = wpilib.Servo(2)
        self.leftLeg = wpilib.Servo(3)
        self.rightLeg = wpilib.Servo(4)
        self.spinner = wpilib.Servo(5)

        self.compressor = wpilib.Compressor(1, 1)
        self.compressor.Start()
        self.relayMotor = wpilib.Relay(2)

        self.solenoid1 = wpilib.Solenoid(1)
        self.solenoid2 = wpilib.Solenoid(2)

    def Disabled(self):
        while self.IsDisabled():
            wpilib.Wait(0.01)

    def Autonomous(self):
        self.dog.SetEnabled(False)
        while self.IsAutonomous() and self.IsEnabled():
            wpilib.Wait(0.01)

    def OperatorControl(self):
        self.dog.SetEnabled(True)
        self.dog.SetExpiration(0.25)

        solenoidTimer = wpilib.Timer()
        solenoidTimer.Start()

        while wpilib.IsOperatorControl() and wpilib.IsEnabled():
            self.dog.Feed()

            if self.stick1.GetRawButton(6):
                raise SystemRestart

            # Normal motors
            yval = self.stick2.GetY()
            self.motor1.Set(yval)
            self.motor2.Set(yval)

            # Solenoid control
            if self.stick1.GetTrigger():
                self.solenoid1.Set(True)
                self.solenoid2.Set(False)
                solenoidTimer.Reset()
            if self.stick2.GetTrigger():
                self.solenoid1.Set(False)
                self.solenoid2.Set(True)
                solenoidTimer.Reset()
            if solenoidTimer.Get() > 0.2:
                self.solenoid1.Set(False)
                self.solenoid2.Set(False)

            # Relay driven motor
            if self.stick3.GetTrigger():
                self.relayMotor.Set(wpilib.Relay.kForward)
            elif self.stick3.GetTop():
                self.relayMotor.Set(wpilib.Relay.kReverse)
            else:
                self.relayMotor.Set(wpilib.Relay.kOff)

            # Servo control
            serveMan = (1.0 + self.stick3.GetY()) / 2.0

            # Left Arm
            if self.stick3.GetRawButton(7):
                self.leftArm.Set(serveMan)
            else:
                self.leftArm.Set((1.0 + self.leftArmStick.GetY()) / 2.0)

            # Right Arm
            if self.stick3.GetRawButton(8):
                self.rightArm.Set((1.0 - self.stick3.GetY()) / 2.0)
            else:
                self.rightArm.Set((1.0 - self.rightArmStick.GetY()) / 2.0)

            # Left Leg
            if self.stick3.GetRawButton(9):
                self.leftLeg.Set(serveMan)
            else:
                self.leftLeg.Set(0.2 + 0.36 * (1.0 + self.leftArmStick.GetX()) / 2.0)
            #elif self.leftArmStick.GetRawButton(3):
            #    self.leftLeg.Set(0.2)
            #else:
            #    self.leftLeg.Set(0.56)

            # Right Leg
            if self.stick3.GetRawButton(10):
                self.rightLeg.Set(serveMan)
            else:
                self.rightLeg.Set(0.58 + 0.42 * (1.0 - self.rightArmStick.GetX()) / 2.0)
            #elif self.leftArmStick.GetRawButton(2):
            #    self.rightLeg.Set(1.0)
            #else:
            #    self.rightLeg.Set(0.58)

            # Spinner
            if self.stick3.GetRawButton(11):
                self.spinner.Set(serveMan)
            elif self.leftArmStick.GetY() < -0.5 and self.rightArmStick.GetY() < -0.5:
                self.spinner.Set(1.0)
            else:
                self.spinner.Set(0.5)

            wpilib.Wait(0.04)

def run():
    robot = MyRobot()
    robot.StartCompetition()

