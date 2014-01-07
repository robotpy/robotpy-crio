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

class DriverStationLCD : SensorBase
{
%TypeHeaderCode
#include <WPILib/DriverStationLCD.h>
%End

public:
	enum { kSyncTimeout_ms = 20 };
	enum { kFullDisplayTextCommand = 0x9FFF };
	enum { kLineLength = 21 };
	enum { kNumLines = 6 };
	enum Line {kMain_Line6=0, kUser_Line1=0, kUser_Line2=1, kUser_Line3=2, kUser_Line4=3, kUser_Line5=4, kUser_Line6=5};

	virtual ~DriverStationLCD();
	static DriverStationLCD *GetInstance();

	void UpdateLCD();
 
	void Clear();
    
        void Print(Line line, int32_t startingColumn, const char *s);
%MethodCode
	Py_BEGIN_ALLOW_THREADS
	sipCpp->Printf(a0, a1, "%s", a2);
	Py_END_ALLOW_THREADS
%End
        
        void PrintLine(Line line, const char *s);
%MethodCode
	Py_BEGIN_ALLOW_THREADS
	sipCpp->PrintfLine(a0, "%s", a1);
	Py_END_ALLOW_THREADS
%End

protected:
	DriverStationLCD();
};
