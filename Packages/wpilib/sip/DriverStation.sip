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

class DriverStation : SensorBase
{
%TypeHeaderCode
#include <WPILib/DriverStation.h>
%End

public:
	enum Alliance {kRed, kBlue, kInvalid};

	virtual ~DriverStation();
	static DriverStation *GetInstance();

	enum { kBatterySlot = 1 };
	enum { kBatteryChannel = 8 };
	enum { kJoystickPorts = 4 };
	enum { kJoystickAxes = 6 };

	float GetStickAxis(UINT32 stick, UINT32 axis);
	short GetStickButtons(UINT32 stick);

	float GetAnalogIn(UINT32 channel);
	bool GetDigitalIn(UINT32 channel);
	void SetDigitalOut(UINT32 channel, bool value);
	bool GetDigitalOut(UINT32 channel);

	bool IsEnabled();
	bool IsDisabled();
	bool IsAutonomous();
	bool IsOperatorControl();
	bool IsNewControlData();
	bool IsFMSAttached();

	UINT32 GetPacketNumber();
	Alliance GetAlliance();
	UINT32 GetLocation();

	float GetBatteryVoltage();

	Dashboard& GetHighPriorityDashboardPacker();
	Dashboard& GetLowPriorityDashboardPacker();

	DashboardBase* GetHighPriorityDashboardPackerInUse();
	DashboardBase* GetLowPriorityDashboardPackerInUse();
	void SetHighPriorityDashboardPackerToUse(DashboardBase* db);
	void SetLowPriorityDashboardPackerToUse(DashboardBase* db);

	DriverStationEnhancedIO& GetEnhancedIO();

	void IncrementUpdateNumber();
	SEM_ID GetUserStatusDataSem();

protected:
	DriverStation();
};
