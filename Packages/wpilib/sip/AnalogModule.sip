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

class AnalogModule: Module
{
%TypeHeaderCode
#include <WPILib/AnalogModule.h>
%End

public:
	enum { kTimebase = 40000000 };
	enum { kDefaultOversampleBits = 0 };
	enum { kDefaultAverageBits = 7 };
	enum { kDefaultSampleRate = 50000 };

	void SetSampleRate(float samplesPerSecond);
	float GetSampleRate();
	void SetAverageBits(uint32_t channel, uint32_t bits);
	uint32_t GetAverageBits(uint32_t channel);
	void SetOversampleBits(uint32_t channel, uint32_t bits);
	uint32_t GetOversampleBits(uint32_t channel);
	int16_t GetValue(uint32_t channel);
	int32_t GetAverageValue(uint32_t channel);
	float GetAverageVoltage(uint32_t channel);
	float GetVoltage(uint32_t channel);
	uint32_t GetLSBWeight(uint32_t channel);
	int32_t GetOffset(uint32_t channel);
	int32_t VoltsToValue(int32_t channel, float voltage);

	static AnalogModule* GetInstance(uint8_t moduleNumber);

protected:
	explicit AnalogModule(uint8_t moduleNumber);
	virtual ~AnalogModule();
};
