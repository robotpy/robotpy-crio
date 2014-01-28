from .core import *
from _wpilib import  __version__

print("WPILib was compiled from revision %s" % __version__)

try:
    with open('/c/FRC_Lib_Version.ini', 'w') as fp:
        fp.write(__version__)
except:
    print("!! Exception occurred when writing library version to disk")
