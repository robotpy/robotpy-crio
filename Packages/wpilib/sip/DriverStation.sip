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

	enum { kBatteryModuleNumber = 1 };
	enum { kBatteryChannel = 8 };
	enum { kJoystickPorts = 4 };
	enum { kJoystickAxes = 6 };

	float GetStickAxis(uint32_t stick, uint32_t axis);
	short GetStickButtons(uint32_t stick);

	float GetAnalogIn(uint32_t channel);
	bool GetDigitalIn(uint32_t channel);
	void SetDigitalOut(uint32_t channel, bool value);
	bool GetDigitalOut(uint32_t channel);

	bool IsEnabled();
	bool IsDisabled();
	bool IsAutonomous();
	bool IsOperatorControl();
	bool IsTest();
	bool IsNewControlData();
	bool IsFMSAttached();

	uint32_t GetPacketNumber();
	Alliance GetAlliance();
	uint32_t GetLocation();
	void WaitForData();
	double GetMatchTime();
	float GetBatteryVoltage();
	uint16_t GetTeamNumber();

	Dashboard& GetHighPriorityDashboardPacker();
	Dashboard& GetLowPriorityDashboardPacker();

	DashboardBase* GetHighPriorityDashboardPackerInUse();
	DashboardBase* GetLowPriorityDashboardPackerInUse();
	void SetHighPriorityDashboardPackerToUse(DashboardBase* db);
	void SetLowPriorityDashboardPackerToUse(DashboardBase* db);

	DriverStationEnhancedIO& GetEnhancedIO();

	void IncrementUpdateNumber();
	SEM_ID GetUserStatusDataSem();

	void InDisabled(bool entering);
	void InAutonomous(bool entering);
	void InOperatorControl(bool entering);
	void InTest(bool entering);

protected:
	DriverStation();
};
