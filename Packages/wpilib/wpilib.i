/*
 *  wpilib.i - SWIG bindings for wpilib
 *  RobotPy
 *
 *  Copyright (c) 2010 Ross Light, Peter Johnson
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

%module wpilib
%{
#include <WPILib/WPILib.h>
#include <CANJaguar/CANJaguar.h>
%}

typedef signed char INT8;
typedef signed short INT16;
typedef signed int INT32;
typedef signed long long INT64;

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;

/*** ABSTRACT BASES ***/
class ErrorBase;

class Error
{
public:
    typedef tRioStatusCode Code;

	Error();
	~Error();
	Code GetCode() const;
	const char *GetMessage() const;
	const char *GetFilename() const;
	UINT32 GetLineNumber() const;
    const ErrorBase* GetOriginatingObject() const;
	void Clear();
	void Set(Code code, const char* filename, UINT32 lineNumber, const ErrorBase* originatingObject);
};

class ErrorBase
{
public:
	virtual ~ErrorBase();
	virtual Error& GetError();
	virtual const Error& GetError() const;
	virtual void SetError(Error::Code code, const char* filename, UINT32 lineNumber) const;
    virtual void ClearError();
    virtual bool StatusIsFatal() const;
    static Error& GetGlobalError();
protected:
	ErrorBase();
};

class SensorBase: public ErrorBase
{
public:
	static const UINT32 kSystemClockTicksPerMicrosecond = 40;

	SensorBase();
	virtual ~SensorBase();
	static void SetDefaultAnalogModule(UINT32 slot);
	static void SetDefaultDigitalModule(UINT32 slot);
	static void SetDefaultSolenoidModule(UINT32 slot);
	static void DeleteSingletons();
	static UINT32 GetDefaultAnalogModule() { return m_defaultAnalogModule; }
	static UINT32 GetDefaultDigitalModule() { return m_defaultDigitalModule; }
	static UINT32 GetDefaultSolenoidModule() { return m_defaultSolenoidModule; }
	static bool CheckDigitalModule(UINT32 slot);
	static bool CheckRelayModule(UINT32 slot);
	static bool CheckPWMModule(UINT32 slot);
	static bool CheckSolenoidModule(UINT32 slot);
	static bool CheckAnalogModule(UINT32 slot);
	static bool CheckDigitalChannel(UINT32 channel);
	static bool CheckRelayChannel(UINT32 channel);
	static bool CheckPWMChannel(UINT32 channel);
	static bool CheckAnalogChannel(UINT32 channel);
	static bool CheckSolenoidChannel(UINT32 channel);

	static const UINT32 kDigitalChannels = 14;
	static const UINT32 kAnalogChannels = 8;
	static const UINT32 kAnalogModules = 2;
	static const UINT32 kDigitalModules = 2;
	static const UINT32 kSolenoidChannels = 8;
    static const UINT32 kSolenoidModules = 2;
	static const UINT32 kPwmChannels = 10;
	static const UINT32 kRelayChannels = 8;
	static const UINT32 kChassisSlots = 8;
};

class InterruptableSensorBase : public SensorBase
{
public:
	InterruptableSensorBase();
	virtual ~InterruptableSensorBase();
	virtual void RequestInterrupts() = 0;		///< Synchronus Wait version.
	virtual void CancelInterrupts();			///< Free up the underlying chipobject functions.
	virtual void WaitForInterrupt(float timeout); ///< Synchronus version.
	virtual void EnableInterrupts();			///< Enable interrupts - after finishing setup.
	virtual void DisableInterrupts();		///< Disable, but don't deallocate.
	virtual double ReadInterruptTimestamp();		///< Return the timestamp for the interrupt that occurred.
};

class I2C : private SensorBase
{
	friend class DigitalModule;
public:
	virtual ~I2C();
	bool Transaction(UINT8 *dataToSend, UINT8 sendSize, UINT8 *dataReceived, UINT8 receiveSize);
	bool AddressOnly();
	bool Write(UINT8 registerAddress, UINT8 data);
	bool Read(UINT8 registerAddress, UINT8 count, UINT8 *data);
	void Broadcast(UINT8 registerAddress, UINT8 data);

	bool VerifySensor(UINT8 registerAddress, UINT8 count, const UINT8 *expected);
private:
	I2C(DigitalModule *module, UINT8 deviceAddress);
};

class DigitalSource: public InterruptableSensorBase
{
public:
	virtual ~DigitalSource();
	virtual UINT32 GetChannelForRouting() = 0;
	virtual UINT32 GetModuleForRouting() = 0;
	virtual bool GetAnalogTriggerForRouting() = 0;
	virtual void RequestInterrupts() = 0;
};

class CounterBase
{
public:
	typedef enum {k1X, k2X, k4X} EncodingType;

	virtual ~CounterBase() {}
	virtual void Start() = 0;
	virtual INT32 Get() = 0;
	virtual void Reset() = 0;
	virtual void Stop() = 0;
	virtual double GetPeriod() = 0;
	virtual void SetMaxPeriod(double maxPeriod) = 0;
	virtual bool GetStopped() = 0;
	virtual bool GetDirection() = 0;
};

class SpeedController
{
public:
	virtual ~SpeedController() {};
	virtual void Set(float speed) = 0;
	virtual float Get() = 0;
};

class PWM : public SensorBase
{
public:
	typedef enum {kPeriodMultiplier_1X = 1, kPeriodMultiplier_2X = 2, kPeriodMultiplier_4X = 4} PeriodMultiplier;

	explicit PWM(UINT32 channel);
	PWM(UINT32 slot, UINT32 channel);
	virtual ~PWM();
	void SetRaw(UINT8 value);
	UINT8 GetRaw();
	void SetPeriodMultiplier(PeriodMultiplier mult);
	void EnableDeadbandElimination(bool eliminateDeadband);
	void SetBounds(INT32 max, INT32 deadbandMax, INT32 center, INT32 deadbandMin, INT32 min);
};

class GenericHID
{
public:
	typedef enum {
		kLeftHand = 0,
		kRightHand = 1
	} JoystickHand;

	virtual ~GenericHID() {}

	virtual float GetX(JoystickHand hand = kRightHand) = 0;
	virtual float GetY(JoystickHand hand = kRightHand) = 0;
	virtual float GetZ() = 0;
	virtual float GetTwist() = 0;
	virtual float GetThrottle() = 0;
	virtual float GetRawAxis(UINT32 axis) = 0;

	virtual bool GetTrigger(JoystickHand hand = kRightHand) = 0;
	virtual bool GetTop(JoystickHand hand = kRightHand) = 0;
	virtual bool GetBumper(JoystickHand hand = kRightHand) = 0;
	virtual bool GetRawButton(UINT32 button) = 0;
};

class PIDOutput
{
public:
	virtual void PIDWrite(float output) = 0;
};

class PIDSource
{
public:
	virtual double PIDGet() = 0;
};

class Module: public SensorBase
{
public:
	UINT32 GetSlot() {return m_slot;}

protected:
	explicit Module(UINT32 slot);
	virtual ~Module();
};

/*** CONCRETE CLASSES ***/

class ADXL345_I2C : public SensorBase
{
public:
	enum DataFormat_Range {kRange_2G=0x00, kRange_4G=0x01, kRange_8G=0x02, kRange_16G=0x03};
	enum Axes {kAxis_X=0x00, kAxis_Y=0x02, kAxis_Z=0x04};

	explicit ADXL345_I2C(UINT32 slot, DataFormat_Range range=kRange_2G);
	virtual ~ADXL345_I2C();
	double GetAcceleration(Axes axis);
};

class Accelerometer : public SensorBase, public PIDSource
{
public:
	explicit Accelerometer(UINT32 channel);
	Accelerometer(UINT32 slot, UINT32 channel);
	explicit Accelerometer(AnalogChannel *channel);
	virtual ~Accelerometer();

	float GetAcceleration();
	void SetSensitivity(float sensitivity);
	void SetZero(float zero);
	double PIDGet();
};

class AnalogChannel : public SensorBase, public PIDSource
{
public:
	static const UINT32 kAccumulatorSlot = 1;
	static const UINT32 kAccumulatorNumChannels = 2;
	static const UINT32 kAccumulatorChannels[kAccumulatorNumChannels];

	AnalogChannel(UINT32 slot, UINT32 channel);
	explicit AnalogChannel(UINT32 channel);
	virtual ~AnalogChannel();

	AnalogModule *GetModule();

	INT16 GetValue();
	INT32 GetAverageValue();

	float GetVoltage();
	float GetAverageVoltage();

	UINT32 GetSlot();
	UINT32 GetChannel();

	void SetAverageBits(UINT32 bits);
	UINT32 GetAverageBits();
	void SetOversampleBits(UINT32 bits);
	UINT32 GetOversampleBits();

	UINT32 GetLSBWeight();
	INT32 GetOffset();

	bool IsAccumulatorChannel();
	void InitAccumulator();
	void SetAccumulatorInitialValue(INT64 value);
	void ResetAccumulator();
	void SetAccumulatorCenter(INT32 center);
	void SetAccumulatorDeadband(INT32 deadband);
	INT64 GetAccumulatorValue();
	UINT32 GetAccumulatorCount();
	void GetAccumulatorOutput(INT64 *value, UINT32 *count);
    
    double PIDGet();
};

class AnalogModule: public Module
{ 
public:
	static const long kTimebase = 40000000; ///< 40 MHz clock
	static const long kDefaultOversampleBits = 0;
	static const long kDefaultAverageBits = 7;
	static const float kDefaultSampleRate = 50000.0;

	void SetSampleRate(float samplesPerSecond);
	float GetSampleRate();
	void SetAverageBits(UINT32 channel, UINT32 bits);
	UINT32 GetAverageBits(UINT32 channel);
	void SetOversampleBits(UINT32 channel, UINT32 bits);
	UINT32 GetOversampleBits(UINT32 channel);
	INT16 GetValue(UINT32 channel);
	INT32 GetAverageValue(UINT32 channel);
	float GetAverageVoltage(UINT32 channel);
	float GetVoltage(UINT32 channel);
	UINT32 GetLSBWeight(UINT32 channel);
	INT32 GetOffset(UINT32 channel);
	INT32 VoltsToValue(INT32 channel, float voltage);

	static UINT32 SlotToIndex(UINT32 slot);
	static AnalogModule* GetInstance(UINT32 slot);

protected:
	explicit AnalogModule(UINT32 slot);
	virtual ~AnalogModule();
};

class AnalogTrigger: public SensorBase
{
	friend class AnalogTriggerOutput;
public:
	AnalogTrigger(UINT32 slot, UINT32 channel);
	explicit AnalogTrigger(UINT32 channel);
	explicit AnalogTrigger(AnalogChannel *channel);
	virtual ~AnalogTrigger();

	void SetLimitsVoltage(float lower, float upper);
	void SetLimitsRaw(INT32 lower, INT32 upper);
	void SetAveraged(bool useAveragedValue);
	void SetFiltered(bool useFilteredValue);
	UINT32 GetIndex();
	bool GetInWindow();
	bool GetTriggerState();
	AnalogTriggerOutput *CreateOutput(AnalogTriggerOutput::Type type);
};

class AnalogTriggerOutput: public DigitalSource
{
	friend class AnalogTrigger;
public:
	typedef enum {kInWindow=0, kState=1, kRisingPulse=2, kFallingPulse=3} Type;
	
	virtual ~AnalogTriggerOutput();
	bool Get();

	// DigitalSource interface
	virtual UINT32 GetChannelForRouting();
	virtual UINT32 GetModuleForRouting();
	virtual bool GetAnalogTriggerForRouting();
	virtual void RequestInterrupts();		///< Synchronus Wait version.
protected:
	AnalogTriggerOutput(AnalogTrigger *trigger, Type outputType);
};

class Compressor: public SensorBase
{
public:
	Compressor(UINT32 pressureSwitchChannel, UINT32 compressorRelayChannel);
	Compressor(UINT32 pressureSwitchSlot, UINT32 pressureSwitchChannel,
				UINT32 compresssorRelaySlot, UINT32 compressorRelayChannel);
	~Compressor();

	void Start();
	void Stop();
	bool Enabled();
	UINT32 GetPressureSwitchValue();
	void SetRelayValue(Relay::Value relayValue);
};

class Counter : public SensorBase, public CounterBase
{
public:
	typedef enum {kTwoPulse=0, kSemiperiod=1, kPulseLength=2, kExternalDirection=3} Mode;

	Counter();
	explicit Counter(UINT32 channel);
	Counter(UINT32 slot, UINT32 channel);
	explicit Counter(DigitalSource *source);
	explicit Counter(AnalogTrigger *trigger);
	Counter(EncodingType encodingType, DigitalSource *upSource, DigitalSource *downSource, bool inverted);
	virtual ~Counter();

	void SetUpSource(UINT32 channel);
	void SetUpSource(UINT32 slot, UINT32 channel);
	void SetUpSource(AnalogTrigger *analogTrigger, AnalogTriggerOutput::Type triggerType);
	void SetUpSource(DigitalSource *source);
	void SetUpSourceEdge(bool risingEdge, bool fallingEdge);
	void ClearUpSource();

	void SetDownSource(UINT32 channel);
	void SetDownSource(UINT32 slot, UINT32 channel);
	void SetDownSource(AnalogTrigger *analogTrigger, AnalogTriggerOutput::Type triggerType);
	void SetDownSource(DigitalSource *source);
	void SetDownSourceEdge(bool risingEdge, bool fallingEdge);
	void ClearDownSource();

	void SetUpDownCounterMode();
	void SetExternalDirectionMode();
	void SetSemiPeriodMode(bool highSemiPeriod);
	void SetPulseLengthMode(float threshold);

	void SetReverseDirection(bool reverseDirection);

	// CounterBase interface
	void Start();
	INT32 Get();
	void Reset();
	void Stop();
	double GetPeriod();
	void SetMaxPeriod(double maxPeriod);
	void SetUpdateWhenEmpty(bool enabled);
	bool GetStopped();
	bool GetDirection();
};

class Dashboard : public ErrorBase
{
public:
	enum Type {kI8, kI16, kI32, kU8, kU16, kU32, kFloat, kDouble, kBoolean, kString, kOther};
	enum ComplexType {kArray, kCluster};

	void AddI8(INT8 value);
	void AddI16(INT16 value);
	void AddI32(INT32 value);
	void AddU8(UINT8 value);
	void AddU16(UINT16 value);
	void AddU32(UINT32 value);
	void AddFloat(float value);
	void AddDouble(double value);
	void AddBoolean(bool value);
	void AddString(char* value);
	void AddString(char* value, INT32 length);

	void AddArray(void);
	void FinalizeArray(void);
	void AddCluster(void);
	void FinalizeCluster(void);

	void Printf(const char *writeFmt, ...);

	INT32 Finalize(void);
private:
	Dashboard(SEM_ID statusDataSemaphore);
	virtual ~Dashboard();
};

class DigitalInput : public DigitalSource
{
public:
	explicit DigitalInput(UINT32 channel);
	DigitalInput(UINT32 slot, UINT32 channel);
	~DigitalInput();
	UINT32 Get();
	UINT32 GetChannel();

	// Digital Source Interface
	virtual UINT32 GetChannelForRouting();
	virtual UINT32 GetModuleForRouting();
	virtual bool GetAnalogTriggerForRouting();
	
	// Interruptable Interface
	virtual void RequestInterrupts();		///< Synchronus Wait version.
	void SetUpSourceEdge(bool risingEdge, bool fallingEdge);
};

class DigitalModule: public Module
{
	friend class I2C;

protected:
	explicit DigitalModule(UINT32 slot);
	virtual ~DigitalModule();

public:
	void SetPWM(UINT32 channel, UINT8 value);
	UINT8 GetPWM(UINT32 channel);
	void SetPWMPeriodScale(UINT32 channel, UINT32 squelchMask);
	void SetRelayForward(UINT32 channel, bool on);
	void SetRelayReverse(UINT32 channel, bool on);
	bool GetRelayForward(UINT32 channel);
	UINT8 GetRelayForward(void);
	bool GetRelayReverse(UINT32 channel);
	UINT8 GetRelayReverse(void);
	bool AllocateDIO(UINT32 channel, bool input);
	void FreeDIO(UINT32 channel);
	void SetDIO(UINT32 channel, short value);
	bool GetDIO(UINT32 channel);
	UINT16 GetDIO(void);
	bool GetDIODirection(UINT32 channel);
	UINT16 GetDIODirection(void);
	void Pulse(UINT32 channel, float pulseLength);
	bool IsPulsing(UINT32 channel);
	bool IsPulsing();

	I2C* GetI2C(UINT32 address);

	static UINT32 SlotToIndex(UINT32 slot);
	static DigitalModule* GetInstance(UINT32 slot);
	static UINT8 RemapDigitalChannel(UINT32 channel) { return 15 - channel; }; // TODO: Need channel validation
	static UINT8 UnmapDigitalChannel(UINT32 channel) { return 15 - channel; }; // TODO: Need channel validation
};

class DigitalOutput : public SensorBase
{
public:
	explicit DigitalOutput(UINT32 channel);
	DigitalOutput(UINT32 slot, UINT32 channel);
	~DigitalOutput();
	void Set(UINT32 value);
	void Pulse(float length);
	bool IsPulsing();
};

class DriverStation : public SensorBase
{
public:
	enum Alliance {kRed, kBlue, kInvalid};

	virtual ~DriverStation();
	static DriverStation *GetInstance();

	static const UINT32 kBatterySlot = 1;
	static const UINT32 kBatteryChannel = 8;
	static const UINT32 kJoystickPorts = 4;
	static const UINT32 kJoystickAxes = 6;

	float GetStickAxis(UINT32 stick, UINT32 axis);
	short GetStickButtons(UINT32 stick);

	float GetAnalogIn(UINT32 channel);
	bool GetDigitalIn(UINT32 channel);
	void SetDigitalOut(UINT32 channel, bool value);
	bool GetDigitalOut(UINT32 channel);

	bool IsEnabled();
	bool IsDisabled();
	bool IsAutonomous();
	bool IsOperatorControl();
	bool IsNewControlData();
	bool IsFMSAttached();

	UINT32 GetPacketNumber();
	Alliance GetAlliance();
	UINT32 GetLocation();

	float GetBatteryVoltage();

	Dashboard& GetHighPriorityDashboardPacker(void) {return m_dashboardHigh;}
	Dashboard& GetLowPriorityDashboardPacker(void) {return m_dashboardLow;}
	DriverStationEnhancedIO& GetEnhancedIO(void) {return m_enhancedIO;}
protected:
	DriverStation();
};

class DriverStationEnhancedIO : public ErrorBase
{
public:
	enum tDigitalConfig {kUnknown, kInputFloating, kInputPullUp, kInputPullDown, kOutput, kPWM, kAnalogComparator};
	enum tAccelChannel {kAccelX = 0, kAccelY = 1, kAccelZ = 2};
	enum tPWMPeriodChannels {kPWMChannels1and2, kPWMChannels3and4};

	double GetAcceleration(tAccelChannel channel);
	double GetAnalogIn(UINT32 channel);
	double GetAnalogInRatio(UINT32 channel);
	double GetAnalogOut(UINT32 channel);
	void SetAnalogOut(UINT32 channel, double value);
	bool GetButton(UINT32 channel);
	UINT8 GetButtons();
	void SetLED(UINT32 channel, bool value);
	void SetLEDs(UINT8 value);
	bool GetDigital(UINT32 channel);
	UINT16 GetDigitals();
	void SetDigitalOutput(UINT32 channel, bool value);
	tDigitalConfig GetDigitalConfig(UINT32 channel);
	void SetDigitalConfig(UINT32 channel, tDigitalConfig config);
	double GetPWMPeriod(tPWMPeriodChannels channels);
	void SetPWMPeriod(tPWMPeriodChannels channels, double period);
	bool GetFixedDigitalOutput(UINT32 channel);
	void SetFixedDigitalOutput(UINT32 channel, bool value);
	INT16 GetEncoder(UINT32 encoderNumber);
	void ResetEncoder(UINT32 encoderNumber);
	bool GetEncoderIndexEnable(UINT32 encoderNumber);
	void SetEncoderIndexEnable(UINT32 encoderNumber, bool enable);
	double GetTouchSlider();
	double GetPWMOutput(UINT32 channel);
	void SetPWMOutput(UINT32 channel, double value);
	UINT8 GetFirmwareVersion();
private:
	DriverStationEnhancedIO();
	virtual ~DriverStationEnhancedIO();
};

class DriverStationLCD : public SensorBase
{
public:
	static const UINT32 kSyncTimeout_ms = 20;
	static const UINT16 kFullDisplayTextCommand = 0x9FFF;
	static const INT32 kLineLength = 21;
	static const INT32 kNumLines = 6;
	enum Line {kMain_Line6=0, kUser_Line1=0, kUser_Line2=1, kUser_Line3=2, kUser_Line4=3, kUser_Line5=4, kUser_Line6=5};

	virtual ~DriverStationLCD();
	static DriverStationLCD *GetInstance();

	void UpdateLCD();
 
	void Clear();
    
    %extend
    {
        void Print(Line line, INT32 startingColumn, const char *s)
        {
            $self->Printf(line, startingColumn, "%s", s);
        }
        
        void PrintLine(Line line, const char *s)
        {
            $self->PrintfLine(line, "%s", s);
        }
    }

protected:
	DriverStationLCD();
};

class Encoder: public SensorBase, public CounterBase
{
public:
	Encoder(UINT32 aChannel, UINT32 bChannel, bool reverseDirection=false, EncodingType encodingType = k4X);
	Encoder(UINT32 aSlot, UINT32 aChannel, UINT32 bSlot, UINT32 _bChannel, bool reverseDirection=false, EncodingType encodingType = k4X);
	Encoder(DigitalSource *aSource, DigitalSource *bSource, bool reverseDirection=false, EncodingType encodingType = k4X);
	virtual ~Encoder();

	// CounterBase interface
	void Start();
	INT32 Get();
	INT32 GetRaw();
	void Reset();
	void Stop();
	double GetPeriod();
	void SetMaxPeriod(double maxPeriod);
	bool GetStopped();
	bool GetDirection();
	double GetDistance();
	double GetRate();
	void SetMinRate(double minRate);
	void SetDistancePerPulse(double distancePerPulse);
	void SetReverseDirection(bool reverseDirection);
};

class GearTooth : public Counter
{
public:
	/// 55 uSec for threshold
	static const double kGearToothThreshold = 55e-6;
	GearTooth(UINT32 channel, bool directionSensitive = false);
	GearTooth(UINT32 slot, UINT32 channel, bool directionSensitive = false);
	GearTooth(DigitalSource *source, bool directionSensitive = false);
	virtual ~GearTooth();
	void EnableDirectionSensing(bool directionSensitive);
};

class Gyro : public SensorBase, public PIDSource
{
public:
	static const UINT32 kOversampleBits = 10;
	static const UINT32 kAverageBits = 0;
	static const float kSamplesPerSecond = 50.0;
	static const float kCalibrationSampleTime = 5.0;
	static const float kDefaultVoltsPerDegreePerSecond = 0.007;

	Gyro(UINT32 slot, UINT32 channel);
	explicit Gyro(UINT32 channel);
	explicit Gyro(AnalogChannel *channel);
	virtual ~Gyro();
	float GetAngle();
	void SetSensitivity(float voltsPerDegreePerSecond);
	void Reset();
	
	double PIDGet();
};

class HiTechnicCompass : public SensorBase
{
public:
	explicit HiTechnicCompass(UINT32 slot);
	virtual ~HiTechnicCompass();
	float GetAngle();
};

class Jaguar : public PWM, public SpeedController, public PIDOutput
{
public:
	explicit Jaguar(UINT32 channel);
	Jaguar(UINT32 slot, UINT32 channel);
	virtual ~Jaguar();
	float Get();
	void Set(float value);
    
	void PIDWrite(float output);
};

class CANJaguar : public SpeedController, public PIDOutput
{
public:
	typedef enum {kPercentVoltage, kSpeed, kPosition, kCurrent} ControlMode;
	typedef enum {kCurrentFault = 1, kTemperatureFault = 2, kBusVoltageFault = 4} Faults;
	typedef enum {kForwardLimit = 1, kReverseLimit = 2} Limits;

	explicit CANJaguar(UINT8 deviceNumber, ControlMode controlMode = kPercentVoltage);
	virtual ~CANJaguar();

	float Get();
	void Set(float value);

	void PIDWrite(float output);

	float GetBusVoltage();
	float GetOutputVoltage();
	float GetOutputCurrent();
	float GetTemperature();
	double GetPosition();
	double GetSpeed();
	bool GetForwardLimitOK();
	bool GetReverseLimitOK();
	UINT16 GetFaults();
	bool GetPowerCycled();
	UINT32 GetFirmwareVersion();
};

class Joystick : public GenericHID
{
public:
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 3;
	static const UINT32 kDefaultTwistAxis = 4;
	static const UINT32 kDefaultThrottleAxis = 3;
	typedef enum
	{
		kXAxis, kYAxis, kZAxis, kTwistAxis, kThrottleAxis, kNumAxisTypes
	} AxisType;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 2;
	typedef enum
	{
		kTriggerButton, kTopButton, kNumButtonTypes
	} ButtonType;

	explicit Joystick(UINT32 port);
	Joystick(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);
	virtual ~Joystick();

	UINT32 GetAxisChannel(AxisType axis);
	void SetAxisChannel(AxisType axis, UINT32 channel); 

	virtual float GetX(JoystickHand hand = kRightHand);
	virtual float GetY(JoystickHand hand = kRightHand);
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	virtual float GetAxis(AxisType axis);
	float GetRawAxis(UINT32 axis);

	virtual bool GetTrigger(JoystickHand hand = kRightHand);
	virtual bool GetTop(JoystickHand hand = kRightHand);
	virtual bool GetBumper(JoystickHand hand = kRightHand);
	virtual bool GetButton(ButtonType button);
	bool GetRawButton(UINT32 button);
	static Joystick* GetStickForPort(UINT32 port);
	
	virtual float GetMagnitude();
	virtual float GetDirectionRadians();
	virtual float GetDirectionDegrees();
};

class PIDController
{
public:
	PIDController(float p, float i, float d,
					PIDSource *source, PIDOutput *output,
					float period = 0.05);
	~PIDController();
	float Get();
	void SetContinuous(bool continuous = true);
	void SetInputRange(float minimumInput, float maximumInput);
	void SetOutputRange(float mimimumOutput, float maximumOutput);
	void SetPID(float p, float i, float d);
	float GetP();
	float GetI();
	float GetD();
	
	void SetSetpoint(float setpoint);
	float GetSetpoint();

	float GetError();
	
	void SetTolerance(float percent);
	bool OnTarget();
	
	void Enable();
	void Disable();
	
	void Reset();
};

class Relay : public SensorBase
{
public:
	typedef enum {kOff, kOn, kForward, kReverse} Value;
	typedef enum {kBothDirections, kForwardOnly, kReverseOnly} Direction;

	Relay(UINT32 slot, UINT32 channel, Direction direction);
	virtual ~Relay();

	void Set(Value value);
	void SetDirection(Direction direction);
};

class RobotDrive
{
public:
	typedef enum
	{
		kFrontLeftMotor = 0,
		kFrontRightMotor = 1,
		kRearLeftMotor = 2,
		kRearRightMotor = 3
	} MotorType;

	RobotDrive(UINT32 leftMotorChannel, UINT32 rightMotorChannel, float sensitivity = 0.5);
	RobotDrive(UINT32 frontLeftMotorChannel, UINT32 rearLeftMotorChannel,
				UINT32 frontRightMotorChannel, UINT32 rearRightMotorChannel, float sensitivity = 0.5);
	RobotDrive(SpeedController *leftMotor, SpeedController *rightMotor, float sensitivity = 0.5);
	RobotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
				SpeedController *frontRightMotor, SpeedController *rearRightMotor,
				float sensitivity = 0.5);
	virtual ~RobotDrive();

	void Drive(float speed, float curve);
	void TankDrive(GenericHID *leftStick, GenericHID *rightStick);
	void TankDrive(GenericHID *leftStick, UINT32 leftAxis, GenericHID *rightStick, UINT32 rightAxis);
	void TankDrive(float leftValue, float rightValue);
	void ArcadeDrive(GenericHID *stick, bool squaredInputs = true);
	void ArcadeDrive(GenericHID *moveStick, UINT32 moveChannel, GenericHID *rotateStick, UINT32 rotateChannel, bool squaredInputs = true);
	void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs = true);
	void MecanumDrive_Cartesian(float x, float y, float rotation, float gyroAngle = 0.0);
	void MecanumDrive_Polar(float magnitude, float direction, float rotation);
	void HolonomicDrive(float magnitude, float direction, float rotation);
	void SetLeftRightMotorSpeeds(float leftSpeed, float rightSpeed);
	void SetInvertedMotor(MotorType motor, bool isInverted);
};

class SerialPort
{
public:
	typedef enum {kParity_None=0, kParity_Odd=1, kParity_Even=2, kParity_Mark=3, kParity_Space=4} Parity;
	typedef enum {kStopBits_One=10, kStopBits_OnePointFive=15, kStopBits_Two=20} StopBits;
	typedef enum {kFlowControl_None=0, kFlowControl_XonXoff=1, kFlowControl_RtsCts=2, kFlowControl_DtrDsr=4} FlowControl;
	typedef enum {kFlushOnAccess=1, kFlushWhenFull=2} WriteBufferMode;

	SerialPort(UINT32 baudRate, UINT8 dataBits = 8, Parity parity = kParity_None, StopBits stopBits = kStopBits_One);
	~SerialPort();
	void SetFlowControl(FlowControl flowControl);
	void EnableTermination(char terminator = '\n');
	void DisableTermination();
	INT32 GetBytesReceived();
	UINT32 Read(char *buffer, INT32 count);
	UINT32 Write(const char *buffer, INT32 count);
	void SetTimeout(float timeout);
	void SetReadBufferSize(UINT32 size);
	void SetWriteBufferSize(UINT32 size);
	void SetWriteBufferMode(WriteBufferMode mode);
	void Flush();
	void Reset();
};

class Servo : public PWM, public SpeedController
{
public:
	explicit Servo(UINT32 channel);
	Servo(UINT32 slot, UINT32 channel);
	virtual ~Servo();
	void Set(float value);
	float Get();
	void SetAngle(float angle);
	float GetAngle();
	static float GetMaxAngle() { return kMaxServoAngle; };
	static float GetMinAngle() { return kMinServoAngle; };
};

class Solenoid : public SensorBase
{
public:
	explicit Solenoid(UINT32 channel);
	Solenoid(UINT32 slot, UINT32 channel);
	~Solenoid();
	void Set(bool on);
	bool Get();
	char GetAll();
};

class Timer
{
public:
	Timer();
	virtual ~Timer();
	double Get();
	void Reset();
	void Start();
	void Stop();
	bool HasPeriodPassed(double period);

	static double GetFPGATimestamp(void);
	static double GetPPCTimestamp(void);
};
void Wait(double seconds);

class Ultrasonic: public SensorBase, public PIDSource
{
public:
	typedef enum {
		kInches = 0,
		kMilliMeters = 1
	} DistanceUnit;
	
	Ultrasonic(DigitalOutput *pingChannel, DigitalInput *echoChannel, DistanceUnit units = kInches);
	Ultrasonic(UINT32 pingChannel, UINT32 echoChannel, DistanceUnit units = kInches);
	Ultrasonic(UINT32 pingSlot, UINT32 pingChannel, UINT32 echoSlot, UINT32 echoChannel, DistanceUnit units = kInches);
	virtual ~Ultrasonic();

	void Ping();
	bool IsRangeValid();
	static void SetAutomaticMode(bool enabling);
	double GetRangeInches();
	double GetRangeMM();
	bool IsEnabled() { return m_enabled; }
	void SetEnabled(bool enable) { m_enabled = enable; }
	
	double PIDGet();
	void SetDistanceUnits(DistanceUnit units);
	DistanceUnit GetDistanceUnits();
};

class Victor : public PWM, public SpeedController, public PIDOutput
{
public:
	explicit Victor(UINT32 channel);
	Victor(UINT32 slot, UINT32 channel);
	virtual ~Victor();
	void Set(float value);
	float Get();
    
	void PIDWrite(float output);
};

class Watchdog : public SensorBase
{
public:
	static const double kDefaultWatchdogExpiration = 0.5;

	Watchdog();
	virtual ~Watchdog();
	bool Feed();
	void Kill();
	double GetTimer();
	double GetExpiration();
	void SetExpiration(double expiration);
	bool GetEnabled();
	void SetEnabled(bool enabled);
	bool IsAlive();
	bool IsSystemActive();
};

/*** ROBOT RUNTIME INFORMATION ***/

%{

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

%}

%inline %{

bool IsEnabled()
{
    return MyRobotBase::getInstance().IsEnabled();
}

bool IsDisabled()
{
    return MyRobotBase::getInstance().IsDisabled();
}

bool IsAutonomous()
{
    return MyRobotBase::getInstance().IsAutonomous();
}

bool IsOperatorControl()
{
    return MyRobotBase::getInstance().IsOperatorControl();
}

bool IsSystemActive()
{
    return MyRobotBase::getInstance().IsSystemActive();
}

bool IsNewDataAvailable()
{
    return MyRobotBase::getInstance().IsNewDataAvailable();
}

Watchdog *GetWatchdog()
{
    return &MyRobotBase::getInstance().GetWatchdog();
}

%}
