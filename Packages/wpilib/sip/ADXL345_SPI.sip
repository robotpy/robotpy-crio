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

class ADXL345_SPI : SensorBase
{
%TypeHeaderCode
#include <WPILib/ADXL345_SPI.h>
%End

protected:
	enum { kPowerCtlRegister = 0x2D };
	enum { kDataFormatRegister = 0x31 };
	enum { kDataRegister = 0x32 };
	//enum { kGsPerLSB = 0.00390625 };
	enum SPIAddressFields {kAddress_Read=0x80, kAddress_MultiByte=0x40};
	enum PowerCtlFields {kPowerCtl_Link=0x20, kPowerCtl_AutoSleep=0x10, kPowerCtl_Measure=0x08, kPowerCtl_Sleep=0x04};
	enum DataFormatFields {kDataFormat_SelfTest=0x80, kDataFormat_SPI=0x40, kDataFormat_IntInvert=0x20,
		kDataFormat_FullRes=0x08, kDataFormat_Justify=0x04};

public:
	enum DataFormat_Range {kRange_2G=0x00, kRange_4G=0x01, kRange_8G=0x02, kRange_16G=0x03};
	enum Axes {kAxis_X=0x00, kAxis_Y=0x02, kAxis_Z=0x04};
	struct AllAxes
	{
		double XAxis;
		double YAxis;
		double ZAxis;
	};

public:
	ADXL345_SPI(DigitalOutput &clk, DigitalOutput &mosi, DigitalInput &miso,
		DigitalOutput &cs, DataFormat_Range range=kRange_2G);
	ADXL345_SPI(DigitalOutput *clk, DigitalOutput *mosi, DigitalInput *miso,
		DigitalOutput *cs, DataFormat_Range range=kRange_2G);
	ADXL345_SPI(uint8_t moduleNumber, uint32_t clk, uint32_t mosi, uint32_t miso, uint32_t cs,
		DataFormat_Range range=kRange_2G);
	virtual ~ADXL345_SPI();
	virtual double GetAcceleration(Axes axis);
	virtual AllAxes GetAccelerations();

protected:
	void Init(DigitalOutput *clk, DigitalOutput *mosi, DigitalInput *miso,
		DigitalOutput *cs, DataFormat_Range range);
};

