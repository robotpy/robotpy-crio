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

typedef signed char int8_t /PyInt/;
typedef short int16_t;
typedef long int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t /PyInt/;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef struct semaphore * SEM_ID;

%Include nLoadOut.sip
%Include FRCComm.sip
%Include stdstring.sip

%ModuleCode
#include "RobotPy.h"
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

const char * __version__ = SVN_REV;

%End

const char * __version__;

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

%Include tables/TableKeyNotDefinedException.sip
%Include networktables2/connection/BadMessageException.sip
%Include networktables2/util/IOException.sip
%Include networktables2/util/EOFException.sip
%Include networktables2/util/IllegalStateException.sip
%Include networktables2/TableKeyExistsWithDifferentTypeException.sip

%Include Buttons/AnalogIOButton.sip
%Include Buttons/Button.sip
%Include Buttons/ButtonScheduler.sip
%Include Buttons/CancelButtonScheduler.sip
%Include Buttons/DigitalIOButton.sip
%Include Buttons/HeldButtonScheduler.sip
%Include Buttons/InternalButton.sip
%Include Buttons/JoystickButton.sip
%Include Buttons/NetworkButton.sip
%Include Buttons/PressedButtonScheduler.sip
%Include Buttons/ReleasedButtonScheduler.sip
%Include Buttons/ToggleButtonScheduler.sip
%Include Buttons/Trigger.sip
%Include Commands/Command.sip
%Include Commands/CommandGroup.sip
%Include Commands/CommandGroupEntry.sip
%Include Commands/PIDCommand.sip
%Include Commands/PIDSubsystem.sip
%Include Commands/PrintCommand.sip
%Include Commands/Scheduler.sip
%Include Commands/StartCommand.sip
%Include Commands/Subsystem.sip
%Include Commands/WaitCommand.sip
%Include Commands/WaitForChildren.sip
%Include Commands/WaitUntilCommand.sip
%Include Interfaces/Potentiometer.sip
%Include LiveWindow/LiveWindow.sip
%Include LiveWindow/LiveWindowSendable.sip
%Include LiveWindow/LiveWindowStatusListener.sip
%Include networktables/NetworkTable.sip
%Include networktables/NetworkTableConnectionListenerAdapter.sip
%Include networktables/NetworkTableKeyListenerAdapter.sip
%Include networktables/NetworkTableListenerAdapter.sip
%Include networktables/NetworkTableMode.sip
%Include networktables/NetworkTableProvider.sip
%Include networktables/NetworkTableSubListenerAdapter.sip
%Include networktables2/client/ClientConnectionAdapter.sip
%Include networktables2/client/ClientConnectionListenerManager.sip
%Include networktables2/client/ClientConnectionState.sip
%Include networktables2/client/ClientNetworkTableEntryStore.sip
%Include networktables2/client/NetworkTableClient.sip
%Include networktables2/connection/ConnectionAdapter.sip
%Include networktables2/connection/ConnectionMonitorThread.sip
%Include networktables2/connection/DataIOStream.sip
%Include networktables2/connection/NetworkTableConnection.sip
%Include networktables2/server/NetworkTableServer.sip
%Include networktables2/server/ServerAdapterManager.sip
%Include networktables2/server/ServerConnectionAdapter.sip
%Include networktables2/server/ServerConnectionList.sip
%Include networktables2/server/ServerConnectionState.sip
%Include networktables2/server/ServerIncomingConnectionListener.sip
%Include networktables2/server/ServerIncomingStreamMonitor.sip
%Include networktables2/server/ServerNetworkTableEntryStore.sip
%Include networktables2/stream/FDIOStream.sip
%Include networktables2/stream/IOStream.sip
%Include networktables2/stream/IOStreamFactory.sip
%Include networktables2/stream/IOStreamProvider.sip
%Include networktables2/stream/SocketServerStreamProvider.sip
%Include networktables2/stream/SocketStreamFactory.sip
%Include networktables2/stream/SocketStreams.sip
%Include networktables2/thread/DefaultThreadManager.sip
%Include networktables2/thread/NTThread.sip
%Include networktables2/thread/NTThreadManager.sip
%Include networktables2/thread/PeriodicRunnable.sip
%Include networktables2/type/ArrayData.sip
%Include networktables2/type/ArrayEntryType.sip
%Include networktables2/type/BooleanArray.sip
%Include networktables2/type/ComplexData.sip
%Include networktables2/type/ComplexEntryType.sip
%Include networktables2/type/NetworkTableEntryType.sip
%Include networktables2/type/NetworkTableEntryTypeManager.sip
%Include networktables2/type/NumberArray.sip
%Include networktables2/type/StringArray.sip
%Include networktables2/util/StringCache.sip
%Include networktables2/AbstractNetworkTableEntryStore.sip
%Include networktables2/FlushableOutgoingEntryReceiver.sip
%Include networktables2/IncomingEntryReceiver.sip
%Include networktables2/NetworkTableEntry.sip
%Include networktables2/NetworkTableMessageType.sip
%Include networktables2/NetworkTableNode.sip
%Include networktables2/OutgoingEntryReceiver.sip
%Include networktables2/TransactionDirtier.sip
%Include networktables2/WriteManager.sip
%Include SmartDashboard/NamedSendable.sip
%Include SmartDashboard/Sendable.sip
%Include SmartDashboard/SendableChooser.sip
%Include SmartDashboard/SmartDashboard.sip
%Include tables/IRemote.sip
%Include tables/IRemoteConnectionListener.sip
%Include tables/ITable.sip
%Include tables/ITableListener.sip
%Include tables/ITableProvider.sip
%Include Accelerometer.sip
%Include ADXL345_I2C.sip
%Include ADXL345_SPI.sip
%Include AnalogChannel.sip
%Include AnalogModule.sip
%Include AnalogPotentiometer.sip
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
%Include HiTechnicColorSensor.sip
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
%Include Preferences.sip
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
