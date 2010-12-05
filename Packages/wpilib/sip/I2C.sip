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

class I2C : SensorBase
{
%TypeHeaderCode
#include <WPILib/I2C.h>
%End

public:
	virtual ~I2C();
	bool Transaction(UINT8 *dataToSend, UINT8 sendSize, UINT8 *dataReceived /Out/, UINT8 receiveSize);
	bool AddressOnly();
	bool Write(UINT8 registerAddress, UINT8 data);
	bool Read(UINT8 registerAddress, UINT8 count, UINT8 *data /Out/);
	void Broadcast(UINT8 registerAddress, UINT8 data);

	bool VerifySensor(UINT8 registerAddress, UINT8 count, const UINT8 *expected);
private:
	I2C(DigitalModule *module, UINT8 deviceAddress);
};
