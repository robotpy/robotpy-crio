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
	explicit DigitalModule(UINT32 slot);
	virtual ~DigitalModule();

public:
	void SetPWM(UINT32 channel, UINT8 value);
	UINT8 GetPWM(UINT32 channel);
	void SetPWMPeriodScale(UINT32 channel, UINT32 squelchMask);
	void SetRelayForward(UINT32 channel, bool on);
	void SetRelayReverse(UINT32 channel, bool on);
	bool GetRelayForward(UINT32 channel);
	UINT8 GetRelayForward();
	bool GetRelayReverse(UINT32 channel);
	UINT8 GetRelayReverse();
	bool AllocateDIO(UINT32 channel, bool input);
	void FreeDIO(UINT32 channel);
	void SetDIO(UINT32 channel, short value);
	bool GetDIO(UINT32 channel);
	UINT16 GetDIO();
	bool GetDIODirection(UINT32 channel);
	UINT16 GetDIODirection();
	void Pulse(UINT32 channel, float pulseLength);
	bool IsPulsing(UINT32 channel);
	bool IsPulsing();

	I2C* GetI2C(UINT32 address);

	static UINT32 SlotToIndex(UINT32 slot);
	static DigitalModule* GetInstance(UINT32 slot);
	static UINT8 RemapDigitalChannel(UINT32 channel);
	static UINT8 UnmapDigitalChannel(UINT32 channel);
};
