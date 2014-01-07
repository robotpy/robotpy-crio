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

class DashboardBase : ErrorBase
{
%TypeHeaderCode
#include <WPILib/DashboardBase.h>
%End

public:
	virtual void GetStatusBuffer(char** userStatusData /Out,Array/, int32_t* userStatusDataSize /Out,ArraySize/) = 0;
%MethodCode
            Py_BEGIN_ALLOW_THREADS
            int32_t a1_int;
            sipCpp->GetStatusBuffer(&a0,&a1_int);
            a1 = a1_int;
            Py_END_ALLOW_THREADS
%End
	virtual void Flush() = 0;
	virtual ~DashboardBase();

protected:
	DashboardBase();

private:
	DashboardBase(const DashboardBase&);
};
