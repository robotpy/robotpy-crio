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

class Joystick : GenericHID
{
%TypeHeaderCode
#include <WPILib/Joystick.h>
%End

public:
	enum { kDefaultXAxis = 1 };
	enum { kDefaultYAxis = 2 };
	enum { kDefaultZAxis = 3 };
	enum { kDefaultTwistAxis = 4 };
	enum { kDefaultThrottleAxis = 3 };
	enum AxisType
	{
		kXAxis, kYAxis, kZAxis, kTwistAxis, kThrottleAxis, kNumAxisTypes
	};
	enum { kDefaultTriggerButton = 1 };
	enum { kDefaultTopButton = 2 };
	enum ButtonType
	{
		kTriggerButton, kTopButton, kNumButtonTypes
	};

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

private:
	Joystick(const Joystick&);
};
