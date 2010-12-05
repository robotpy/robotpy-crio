import wpilib

stick1 = wpilib.Joystick(1)
stick2 = wpilib.Joystick(2)

leftMotor1 = wpilib.Victor(1)
leftMotor2 = wpilib.Victor(3)
rightMotor1 = wpilib.Victor(2)
rightMotor2 = wpilib.Victor(4)

drive = wpilib.RobotDrive(leftMotor1, leftMotor2, rightMotor1, rightMotor2)

def checkRestart():
    if stick1.GetRawButton(10):
        raise RuntimeError("Restart")

def disabled():
    while wpilib.IsDisabled():
        checkRestart()
        wpilib.Wait(0.01)

def autonomous():
    wpilib.GetWatchdog().SetEnabled(False)
    while wpilib.IsAutonomous() and wpilib.IsEnabled():
        checkRestart()
        wpilib.Wait(0.01)

def teleop():
    dog = wpilib.GetWatchdog()
    dog.SetEnabled(True)
    dog.SetExpiration(0.25)

    while wpilib.IsOperatorControl() and wpilib.IsEnabled():
        dog.Feed()
        drive.TankDrive(stick1, stick2)
        checkRestart()
        wpilib.Wait(0.01)

def run():
    """Main loop"""
    while 1:
        if wpilib.IsDisabled():
            print("Running disabled()")
            disabled()
            while wpilib.IsDisabled():
                wpilib.Wait(0.01)
        elif wpilib.IsAutonomous():
            print("Running autonomous()")
            autonomous()
            while wpilib.IsAutonomous() and wpilib.IsEnabled():
                wpilib.Wait(0.01)
        else:
            print("Running teleop()")
            teleop()
            while wpilib.IsOperatorControl() and wpilib.IsEnabled():
                wpilib.Wait(0.01)

