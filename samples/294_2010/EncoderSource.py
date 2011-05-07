from wpilib import PIDSource

class EncoderSource(PIDSource):
    def __init__(self, enc):
        PIDSource.__init__(self)
        self.enc = enc

    def PIDGet(self):
        return self.enc.Get()

