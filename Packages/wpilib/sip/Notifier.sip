// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2012 Peter Johnson
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

typedef void (*TimerEventHandler)(void *);

class Notifier : ErrorBase /NoDefaultCtors/
{
%TypeHeaderCode
#include <WPILib/Notifier.h>
%End

public:
	Notifier(SIP_PYCALLABLE handler) [(TimerEventHandler handler, void *param)];
%MethodCode
	void notifier_TimerEventHandler(void *);
	Py_BEGIN_ALLOW_THREADS
	sipCpp = new sipNotifier(notifier_TimerEventHandler, a0);
	Py_END_ALLOW_THREADS
	Py_INCREF(a0);
%End
	virtual ~Notifier();
%MethodCode
	PyObject *res = (PyObject *)(sipCpp->GetParam());
	Py_XDECREF(res);
%End
	void StartSingle(double delay);
	void StartPeriodic(double period);
	void Stop();

private:
	Notifier(const Notifier&);
};

%ModuleCode
void notifier_TimerEventHandler(void *param)
{
	PyObject *res;
	SIP_BLOCK_THREADS
	res = sipCallMethod(0, (PyObject *)param, "");
	Py_XDECREF(res);
	if (res == NULL)
		PyErr_Print();
	SIP_UNBLOCK_THREADS
}
%End
