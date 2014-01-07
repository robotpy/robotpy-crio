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

class DigitalModule: Module
{
%TypeHeaderCode
#include <WPILib/DigitalModule.h>
%End

protected:
	explicit DigitalModule(uint8_t moduleNumber);
	virtual ~DigitalModule();

public:
	void SetPWM(uint32_t channel, uint8_t value);
	uint8_t GetPWM(uint32_t channel);
	void SetPWMPeriodScale(uint32_t channel, uint32_t squelchMask);
	void SetRelayForward(uint32_t channel, bool on);
	void SetRelayReverse(uint32_t channel, bool on);
	bool GetRelayForward(uint32_t channel);
	uint8_t GetRelayForward();
	bool GetRelayReverse(uint32_t channel);
	uint8_t GetRelayReverse();
	bool AllocateDIO(uint32_t channel, bool input);
	void FreeDIO(uint32_t channel);
	void SetDIO(uint32_t channel, short value);
	bool GetDIO(uint32_t channel);
	uint16_t GetDIO();
	bool GetDIODirection(uint32_t channel);
	uint16_t GetDIODirection();
	void Pulse(uint32_t channel, float pulseLength);
	bool IsPulsing(uint32_t channel);
	bool IsPulsing();
	uint32_t AllocateDO_PWM();
	void FreeDO_PWM(uint32_t pwmGenerator);
	void SetDO_PWMRate(float rate);
	void SetDO_PWMDutyCycle(uint32_t pwmGenerator, float dutyCycle);
	void SetDO_PWMOutputChannel(uint32_t pwmGenerator, uint32_t channel);
	uint16_t GetLoopTiming();

	I2C* GetI2C(uint32_t address);

	static DigitalModule* GetInstance(uint8_t moduleNumber);

	static uint8_t RemapDigitalChannel(uint32_t channel);
	static uint8_t UnmapDigitalChannel(uint32_t channel);
};
