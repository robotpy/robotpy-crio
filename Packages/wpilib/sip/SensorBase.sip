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

class SensorBase: ErrorBase
{
%TypeHeaderCode
#include <WPILib/SensorBase.h>
%End

public:
	enum { kSystemClockTicksPerMicrosecond = 40 };

	SensorBase();
	virtual ~SensorBase();
	static void DeleteSingletons();
	static uint32_t GetDefaultAnalogModule();
	static uint32_t GetDefaultDigitalModule();
	static uint32_t GetDefaultSolenoidModule();
	static bool CheckAnalogModule(uint8_t moduleNumber);
	static bool CheckDigitalModule(uint8_t moduleNumber);
	static bool CheckPWMModule(uint8_t moduleNumber);
	static bool CheckRelayModule(uint8_t moduleNumber);
	static bool CheckSolenoidModule(uint8_t moduleNumber);
	static bool CheckDigitalChannel(uint32_t channel);
	static bool CheckRelayChannel(uint32_t channel);
	static bool CheckPWMChannel(uint32_t channel);
	static bool CheckAnalogChannel(uint32_t channel);
	static bool CheckSolenoidChannel(uint32_t channel);

	enum {
		kDigitalChannels = 14,
		kAnalogChannels = 8,
		kAnalogModules = 2,
		kDigitalModules = 2,
		kSolenoidChannels = 8,
		kSolenoidModules = 2,
		kPwmChannels = 10,
		kRelayChannels = 8,
		kChassisSlots = 8
	};

private:
	SensorBase(const SensorBase&);
};
