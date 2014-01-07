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

class AnalogChannel : SensorBase, PIDSource
{
%TypeHeaderCode
#include <WPILib/AnalogChannel.h>
%End

public:
	enum { kAccumulatorModuleNumber = 1 };
	enum { kAccumulatorNumChannels = 2 };
	//static const uint32_t kAccumulatorChannels[kAccumulatorNumChannels];

	AnalogChannel(uint8_t moduleNumber, uint32_t channel);
	explicit AnalogChannel(uint32_t channel);
	virtual ~AnalogChannel();

	AnalogModule *GetModule();

	int16_t GetValue();
	int32_t GetAverageValue();

	float GetVoltage();
	float GetAverageVoltage();

	uint8_t GetModuleNumber();
	uint32_t GetChannel();

	void SetAverageBits(uint32_t bits);
	uint32_t GetAverageBits();
	void SetOversampleBits(uint32_t bits);
	uint32_t GetOversampleBits();

	uint32_t GetLSBWeight();
	int32_t GetOffset();

	bool IsAccumulatorChannel();
	void InitAccumulator();
	void SetAccumulatorInitialValue(int64_t value);
	void ResetAccumulator();
	void SetAccumulatorCenter(int32_t center);
	void SetAccumulatorDeadband(int32_t deadband);
	int64_t GetAccumulatorValue();
	uint32_t GetAccumulatorCount();
	void GetAccumulatorOutput(int64_t *value, uint32_t *count);
	void SetVoltageForPID(bool shouldUseVoltageForPID);

	double PIDGet();
};
