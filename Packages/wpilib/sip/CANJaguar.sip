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

class CANJaguar : SpeedController, PIDOutput
{
%TypeHeaderCode
#include <CANJaguar/CANJaguar.h>
%End

public:
	enum ControlMode {kPercentVoltage, kSpeed, kPosition, kCurrent};
	enum Faults {kCurrentFault = 1, kTemperatureFault = 2, kBusVoltageFault = 4};
	enum Limits {kForwardLimit = 1, kReverseLimit = 2};

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
