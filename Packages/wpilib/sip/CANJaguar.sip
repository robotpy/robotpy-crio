// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2010 Peter Johnson
// 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

class CANJaguar : MotorSafety, SpeedController, ErrorBase, LiveWindowSendable, ITableListener
{
%TypeHeaderCode
#include <WPILib/CANJaguar.h>
%End

public:
	enum {kControllerRate = 1000, kApproxBusVoltage = 12};
	enum ControlMode {kPercentVbus, kCurrent, kSpeed, kPosition, kVoltage};
	enum Faults {kCurrentFault = 1, kTemperatureFault = 2, kBusVoltageFault = 4};
	enum Limits {kForwardLimit = 1, kReverseLimit = 2};
	enum PositionReference {kPosRef_QuadEncoder = 0, kPosRef_Potentiometer = 1, kPosRef_None = 0xFF};
	enum SpeedReference {kSpeedRef_Encoder = 0, kSpeedRef_InvEncoder = 2, kSpeedRef_QuadEncoder = 3, kSpeedRef_None = 0xFF};
	enum NeutralMode {kNeutralMode_Jumper = 0, kNeutralMode_Brake = 1, kNeutralMode_Coast = 2};
	enum LimitMode {kLimitMode_SwitchInputsOnly = 0, kLimitMode_SoftPositionLimits = 1};

	explicit CANJaguar(uint8_t deviceNumber, ControlMode controlMode = kPercentVbus);
	virtual ~CANJaguar();

	virtual float Get();
	virtual void Set(float value, uint8_t syncGroup=0);
	virtual void Disable();

	virtual void PIDWrite(float output);

	void SetSpeedReference(SpeedReference reference);
	SpeedReference GetSpeedReference();
	void SetPositionReference(PositionReference reference);
	PositionReference GetPositionReference();
	void SetPID(double p, double i, double d);
	double GetP();
	double GetI();
	double GetD();
	void EnableControl(double encoderInitialPosition = 0.0);
	void DisableControl();
	void ChangeControlMode(ControlMode controlMode);
	ControlMode GetControlMode();
	float GetBusVoltage();
	float GetOutputVoltage();
	float GetOutputCurrent();
	float GetTemperature();
	double GetPosition();
	double GetSpeed();
	bool GetForwardLimitOK();
	bool GetReverseLimitOK();
	uint16_t GetFaults();
	bool GetPowerCycled();
	void SetVoltageRampRate(double rampRate);
	virtual uint32_t GetFirmwareVersion();
	uint8_t GetHardwareVersion();
	void ConfigNeutralMode(NeutralMode mode);
	void ConfigEncoderCodesPerRev(uint16_t codesPerRev);
	void ConfigPotentiometerTurns(uint16_t turns);
	void ConfigSoftPositionLimits(double forwardLimitPosition, double reverseLimitPosition);
	void DisableSoftPositionLimits();
	void ConfigMaxOutputVoltage(double voltage);
	void ConfigFaultTime(float faultTime);

	static void UpdateSyncGroup(uint8_t syncGroup);

	void SetExpiration(float timeout);
	float GetExpiration();
	bool IsAlive();
	void StopMotor();
	bool IsSafetyEnabled();
	void SetSafetyEnabled(bool enabled);
	const char* GetDescription() [void (char *)];
%MethodCode
	char result[100];
	result[0] = '\0';
	sipSelfWasArg ? sipCpp->CANJaguar::GetDescription(result) : sipCpp->GetDescription(result);
	sipRes = result;
%End
protected:
	void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);
	void UpdateTable();
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	std::string GetSmartDashboardType();
	void InitTable(ITable *subTable);
	ITable * GetTable();

private:
	CANJaguar(const CANJaguar&);
};
