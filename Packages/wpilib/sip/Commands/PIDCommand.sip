// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2013 Peter Johnson
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

class PIDCommand : Command, PIDOutput, PIDSource
{
%TypeHeaderCode
#include <WPILib/Commands/PIDCommand.h>
%End

public:
	PIDCommand(const char *name, double p, double i, double d);
	PIDCommand(const char *name, double p, double i, double d, double period);
	PIDCommand(const char *name, double p, double i, double d, double f, double perioid);
	PIDCommand(double p, double i, double d);
	PIDCommand(double p, double i, double d, double period);
	PIDCommand(double p, double i, double d, double f, double period);
	virtual ~PIDCommand();
	
	void SetSetpointRelative(double deltaSetpoint);

	// PIDOutput interface
	virtual void PIDWrite(float output);

	// PIDSource interface
	virtual double PIDGet();
protected:
	PIDController *GetPIDController();
	virtual void _Initialize();
	virtual void _Interrupted();
	virtual void _End();
	void SetSetpoint(double setpoint);
	double GetSetpoint();
	double GetPosition();

	virtual double ReturnPIDInput() = 0;
	virtual void UsePIDOutput(double output) = 0;

public:
	virtual void InitTable(ITable* table);
	virtual std::string GetSmartDashboardType();
};
