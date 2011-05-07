import wpilib
from DualSpeedController import DualSpeedController
from EncoderSource import EncoderSource
from WinchOutput import WinchOutput

# Joysticks
lstick = wpilib.Joystick(1)
rstick = wpilib.Joystick(2)
stick3 = wpilib.Joystick(3)

# Motors and drive system
leftFrontMotor = wpilib.CANJaguar(2)
leftRearMotor = wpilib.CANJaguar(7)
leftMotor = DualSpeedController(leftFrontMotor, leftRearMotor, 1)
rightFrontMotor = wpilib.CANJaguar(4)
rightRearMotor = wpilib.CANJaguar(6)
rightMotor = DualSpeedController(rightFrontMotor, rightRearMotor, 2)
kickerMotor1 = wpilib.CANJaguar(5)
kickerMotor2 = wpilib.CANJaguar(8)
kickerMotor = DualSpeedController(kickerMotor1, kickerMotor2, 3)
intakeMotor = wpilib.CANJaguar(3)

drive = wpilib.RobotDrive(leftMotor, rightMotor)

# Pneumatics
shifter1 = wpilib.Solenoid(7, 1)
shifter2 = wpilib.Solenoid(7, 2)
ratchet1 = wpilib.Solenoid(7, 3)
ratchet2 = wpilib.Solenoid(7, 4)
compressor = wpilib.Compressor(8, 1)

# Sensors
frontLimitSwitch = wpilib.DigitalInput(6)
backLimitSwitch = wpilib.DigitalInput(5)
kickerEncoder = wpilib.Encoder(9, 10, True)
leftDriveEncoder = wpilib.Encoder(13, 14, True)
rightDriveEncoder = wpilib.Encoder(11, 12)

# Global settings
gDriveTicksPerInch = 11
gWinchOut = 570             # fully winched out and ready to kick
gWinchFull = 290            # fully winched back (full power kick)
gWinchDeadband = 8          # deadband on encoder controller

# how long to wait after kick pneumatic release to start winching back
gWinchWaitTime = 0.25

# how long to wait after kick pneumatic release until we can kick again
# (rule: 2 seconds between kicks)
gBetweenKickTime = 2.375

# PID controllers
winchEnc = EncoderSource(kickerEncoder)
winchOutput = WinchOutput(kickerMotor, kickerEncoder, backLimitSwitch)
winchControl = wpilib.PIDController(-1.0/25.0, 0.0, -1.0/25.0, winchEnc,
                                    winchOutput)

# Core utility functions
def HaveBall():
    return intakeMotor.GetOutputCurrent() > 10

def ResetDriveEncoders():
    leftDriveEncoder.Reset()
    rightDriveEncoder.Reset()

def CheckRestart():
    if lstick.GetRawButton(10):
        raise RuntimeError("Restart")

