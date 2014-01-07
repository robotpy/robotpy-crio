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

class SerialPort : ErrorBase
{
%TypeHeaderCode
#include <WPILib/SerialPort.h>
%End

public:
	enum Parity {kParity_None=0, kParity_Odd=1, kParity_Even=2, kParity_Mark=3, kParity_Space=4};
	enum StopBits {kStopBits_One=10, kStopBits_OnePointFive=15, kStopBits_Two=20};
	enum FlowControl {kFlowControl_None=0, kFlowControl_XonXoff=1, kFlowControl_RtsCts=2, kFlowControl_DtrDsr=4};
	enum WriteBufferMode {kFlushOnAccess=1, kFlushWhenFull=2};

	SerialPort(uint32_t baudRate, uint8_t dataBits = 8, Parity parity = kParity_None, StopBits stopBits = kStopBits_One);
	~SerialPort();
	void SetFlowControl(FlowControl flowControl);
	void EnableTermination(char terminator);
	void EnableTermination();
	void DisableTermination();
	int32_t GetBytesReceived();
	void Print(const char *s);
%MethodCode
	Py_BEGIN_ALLOW_THREADS
	sipCpp->Printf("%s", a0);
	Py_END_ALLOW_THREADS
%End
	uint32_t Read(char *buffer, int32_t count);
	uint32_t Write(const char *buffer, int32_t count);
	void SetTimeout(float timeout);
	void SetReadBufferSize(uint32_t size);
	void SetWriteBufferSize(uint32_t size);
	void SetWriteBufferMode(WriteBufferMode mode);
	void Flush();
	void Reset();

private:
        SerialPort(const SerialPort&);
};
