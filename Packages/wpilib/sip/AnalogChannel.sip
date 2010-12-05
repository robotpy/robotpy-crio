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
	enum { kAccumulatorSlot = 1 };
	enum { kAccumulatorNumChannels = 2 };
	//static const UINT32 kAccumulatorChannels[kAccumulatorNumChannels];

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
