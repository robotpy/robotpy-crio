import wpilib

lstick = wpilib.Joystick(1)

motor = wpilib.CANJaguar(8)
analog = wpilib.AnalogChannel(1)

class MotorOutput(wpilib.PIDOutput):
    def __init__(self, motor):
        super().__init__()
        self.motor = motor

    def PIDWrite(self, output):
        self.motor.Set(output)

class AnalogSource(wpilib.PIDSource):
    def __init__(self, analog):
        super().__init__()
        self.analog = analog

    def PIDGet(self):
        return analog.GetVoltage()

pidSource = AnalogSource(analog)
pidOutput = MotorOutput(motor)
pidController = wpilib.PIDController(1.0, 0.0, 0.0, pidSource, pidOutput)

def CheckRestart():
    if lstick.GetRawButton(10):
        raise RuntimeError("Restart")

class MyRobot(wpilib.SimpleRobot):
    def Disabled(self):
        while self.IsDisabled():
            CheckRestart()
            wpilib.Wait(0.01)

    def Autonomous(self):
        self.GetWatchdog().SetEnabled(False)
        while self.IsAutonomous() and self.IsEnabled():
            CheckRestart()
            wpilib.Wait(0.01)

    def OperatorControl(self):
        dog = self.GetWatchdog()
        dog.SetEnabled(True)
        dog.SetExpiration(0.25)

        pidController.Enable()

        while self.IsOperatorControl() and self.IsEnabled():
            dog.Feed()
            CheckRestart()

            # Motor control
            pidController.SetSetpoint(2.5+lstick.GetY()*2.5)

            wpilib.Wait(0.04)

def run():
    robot = MyRobot()
    robot.StartCompetition()
