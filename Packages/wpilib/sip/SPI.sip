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

class SPI : SensorBase
{
%TypeHeaderCode
#include <WPILib/SPI.h>
%End

public:
	enum tFrameMode {kChipSelect, kPreLatchPulse, kPostLatchPulse, kPreAndPostLatchPulse};
	enum tSPIConstants {kReceiveFIFODepth=512, kTransmitFIFODepth=512};

	SPI(DigitalOutput &clk, DigitalOutput &mosi, DigitalInput &miso);
	SPI(DigitalOutput *clk, DigitalOutput *mosi, DigitalInput *miso);
	SPI(DigitalOutput &clk, DigitalOutput &mosi);
	SPI(DigitalOutput *clk, DigitalOutput *mosi);
	SPI(DigitalOutput &clk, DigitalInput &miso);
	SPI(DigitalOutput *clk, DigitalInput *miso);
	virtual ~SPI();

	void SetBitsPerWord(uint32_t bits);
	uint32_t GetBitsPerWord();
	void SetClockRate(double hz);

	void SetMSBFirst();
	void SetLSBFirst();

	void SetSampleDataOnFalling();
	void SetSampleDataOnRising();

	void SetSlaveSelect(DigitalOutput *ss, tFrameMode mode=kChipSelect, bool activeLow=false);
	void SetSlaveSelect(DigitalOutput &ss, tFrameMode mode=kChipSelect, bool activeLow=false);
	DigitalOutput *GetSlaveSelect(tFrameMode *mode=NULL, bool *activeLow=NULL);

	void SetClockActiveLow();
	void SetClockActiveHigh();

	virtual void ApplyConfig();

	virtual uint16_t GetOutputFIFOAvailable();
	virtual uint16_t GetNumReceived();

	virtual bool IsDone();
	bool HadReceiveOverflow();

	virtual void Write(uint32_t data);
	virtual uint32_t Read(bool initiate = false);

	virtual void Reset();
	virtual void ClearReceivedData();

private:
	SPI(const SPI&);
};
