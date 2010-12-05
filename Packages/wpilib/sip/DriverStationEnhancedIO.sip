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

class DriverStationEnhancedIO : ErrorBase
{
%TypeHeaderCode
#include <WPILib/DriverStationEnhancedIO.h>
%End

public:
	enum tDigitalConfig {kUnknown, kInputFloating, kInputPullUp, kInputPullDown, kOutput, kPWM, kAnalogComparator};
	enum tAccelChannel {kAccelX = 0, kAccelY = 1, kAccelZ = 2};
	enum tPWMPeriodChannels {kPWMChannels1and2, kPWMChannels3and4};

	double GetAcceleration(tAccelChannel channel);
	double GetAnalogIn(UINT32 channel);
	double GetAnalogInRatio(UINT32 channel);
	double GetAnalogOut(UINT32 channel);
	void SetAnalogOut(UINT32 channel, double value);
	bool GetButton(UINT32 channel);
	UINT8 GetButtons();
	void SetLED(UINT32 channel, bool value);
	void SetLEDs(UINT8 value);
	bool GetDigital(UINT32 channel);
	UINT16 GetDigitals();
	void SetDigitalOutput(UINT32 channel, bool value);
	tDigitalConfig GetDigitalConfig(UINT32 channel);
	void SetDigitalConfig(UINT32 channel, tDigitalConfig config);
	double GetPWMPeriod(tPWMPeriodChannels channels);
	void SetPWMPeriod(tPWMPeriodChannels channels, double period);
	bool GetFixedDigitalOutput(UINT32 channel);
	void SetFixedDigitalOutput(UINT32 channel, bool value);
	INT16 GetEncoder(UINT32 encoderNumber);
	void ResetEncoder(UINT32 encoderNumber);
	bool GetEncoderIndexEnable(UINT32 encoderNumber);
	void SetEncoderIndexEnable(UINT32 encoderNumber, bool enable);
	double GetTouchSlider();
	double GetPWMOutput(UINT32 channel);
	void SetPWMOutput(UINT32 channel, double value);
	UINT8 GetFirmwareVersion();

private:
	DriverStationEnhancedIO();
	virtual ~DriverStationEnhancedIO();
};
