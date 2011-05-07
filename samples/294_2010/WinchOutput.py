from wpilib import PIDOutput

class WinchOutput(PIDOutput):
    def __init__(self, winchMotor, enc, backLimitSwitch):
        PIDOutput.__init__(self)
        self.winchMotor = winchMotor
        self.enc = enc
        self.backLimit = backLimitSwitch

    def Set(self, speed):
        if speed < 0 and self.backLimit.Get() == 0:
            self.winchMotor.Set(0.0)
        else:
            self.winchMotor.Set(speed)

    def PIDWrite(self, output):
        self.Set(output)

