from wpilib import SpeedController, CANJaguar

class DualSpeedController(SpeedController):
    def __init__(self, controller1, controller2, syncGroup=0):
        SpeedController.__init__(self)
        self.controller1 = controller1
        self.controller2 = controller2
        self.syncGroup = syncGroup
        self.inverted = [1, 1]

    def SetInverted(self, motor, isInverted):
        self.inverted[motor] = isInverted and -1 or 1

    def Set(self, speed, syncGroup=0):
        self.controller1.Set(speed * self.inverted[0], self.syncGroup)
        self.controller2.Set(speed * self.inverted[1], self.syncGroup)
        if self.syncGroup != 0:
            CANJaguar.UpdateSyncGroup(self.syncGroup)

    def Get(self):
        return self.controller1.Get() * self.inverted[0]

    def Disable(self):
        self.controller1.Disable()
        self.controller2.Disable()

