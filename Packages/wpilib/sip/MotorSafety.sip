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

class MotorSafety
{
%TypeHeaderCode
#include <WPILib/MotorSafety.h>
%End

public:
	virtual void SetExpiration(float timeout) = 0;
	virtual float GetExpiration() = 0;
	virtual bool IsAlive() = 0;
	virtual void StopMotor() = 0;
	virtual void SetSafetyEnabled(bool enabled) = 0;
	virtual bool IsSafetyEnabled() = 0;
	virtual const char* GetDescription() = 0 [void (char *)];
%MethodCode
	char result[100];
	result[0] = '\0';
	sipCpp->GetDescription(result);
	sipRes = result;
%End
%VirtualCatcherCode
	PyObject *result = sipCallMethod(&sipIsErr, sipMethod, "");
	if (result != NULL)
	{
		const char *s;
		sipParseResult(&sipIsErr, sipMethod, result, "A8", &s);
		strcpy(a0, s);
	}
%End
};
