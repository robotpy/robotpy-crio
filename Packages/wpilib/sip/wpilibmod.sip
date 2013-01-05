//
//  wpilibmod.sip - SIP bindings for wpilib
//  This file is part of RobotPy.
//

%Module _wpilib

%Copying
Copyright (c) 2010 Peter Johnson

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
%End

%DefaultEncoding "UTF-8"

typedef signed char INT8 /PyInt/;
typedef short INT16;
typedef int INT32;
typedef long long INT64;

typedef unsigned char UINT8 /PyInt/;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;

typedef struct semaphore * SEM_ID;

%Include nLoadOut.sip
%Include FRCComm.sip
%Include stdstring.sip

%ModuleCode
#include <WPILib/RobotBase.h>

class MyRobotBase : public RobotBase
{
public:
	static RobotBase &getInstance();
	void StartCompetition();
};

RobotBase &
MyRobotBase::getInstance()
{
	RobotBase* inst = &RobotBase::getInstance();
	if (!inst)
	{
		inst = new MyRobotBase;
		RobotBase::setInstance(inst);
	}
	return *inst;
}

void
MyRobotBase::StartCompetition()
{
}
%End

bool IsEnabled();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsEnabled();
%End

bool IsDisabled();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsDisabled();
%End

bool IsAutonomous();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsAutonomous();
%End

bool IsOperatorControl();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsOperatorControl();
%End

bool IsTest();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsTest();
%End

bool IsSystemActive();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsSystemActive();
%End

bool IsNewDataAvailable();
%MethodCode
	sipRes = MyRobotBase::getInstance().IsNewDataAvailable();
%End

Watchdog *GetWatchdog();
%MethodCode
	sipRes = &MyRobotBase::getInstance().GetWatchdog();
%End

%Include Accelerometer.sip
%Include ADXL345_I2C.sip
%Include ADXL345_SPI.sip
%Include AnalogChannel.sip
%Include AnalogModule.sip
%Include AnalogTrigger.sip
%Include AnalogTriggerOutput.sip
%Include CANJaguar.sip
%Include Compressor.sip
%Include Controller.sip
%Include Counter.sip
%Include CounterBase.sip
%Include Dashboard.sip
%Include DashboardBase.sip
%Include DigitalInput.sip
%Include DigitalModule.sip
%Include DigitalOutput.sip
%Include DigitalSource.sip
%Include DoubleSolenoid.sip
%Include DriverStation.sip
%Include DriverStationEnhancedIO.sip
%Include DriverStationLCD.sip
%Include Encoder.sip
%Include Error.sip
%Include ErrorBase.sip
%Include GearTooth.sip
%Include GenericHID.sip
%Include Gyro.sip
%Include HiTechnicCompass.sip
%Include I2C.sip
%Include InterruptableSensorBase.sip
%Include Jaguar.sip
%Include Joystick.sip
%Include Kinect.sip
%Include KinectStick.sip
%Include Module.sip
%Include MotorSafety.sip
%Include MotorSafetyHelper.sip
%Include Notifier.sip
%Include PIDController.sip
%Include PIDOutput.sip
%Include PIDSource.sip
%Include PWM.sip
%Include Relay.sip
%Include RobotDrive.sip
%Include SafePWM.sip
%Include SensorBase.sip
%Include SerialPort.sip
%Include Servo.sip
%Include Skeleton.sip
%Include Solenoid.sip
%Include SolenoidBase.sip
%Include SPI.sip
%Include SpeedController.sip
%Include Talon.sip
%Include Timer.sip
%Include Ultrasonic.sip
%Include UsageReporting.sip
%Include Utility.sip
%Include Victor.sip
%Include Watchdog.sip
