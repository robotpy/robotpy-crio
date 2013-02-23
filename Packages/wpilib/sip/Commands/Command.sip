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

class Command : ErrorBase, NamedSendable, ITableListener
{
%TypeHeaderCode
#include <WPILib/Commands/Command.h>
%End

public:
	Command();
	Command(const char *name);
	Command(double timeout);
	Command(const char *name, double timeout);
	virtual ~Command();
	double TimeSinceInitialized();
	void Requires(Subsystem *s);
	bool IsCanceled();
	void Start();
	bool Run();
	void Cancel();
	bool IsRunning();
	bool IsInterruptible();
	void SetInterruptible(bool interruptible);
	bool DoesRequire(Subsystem *subsystem);
	//typedef std::set<Subsystem *> SubsystemSet;
	//SubsystemSet GetRequirements();
	CommandGroup *GetGroup();
	void SetRunWhenDisabled(bool run);
	bool WillRunWhenDisabled();
	int GetID();

	virtual std::string GetName();
	virtual void InitTable(ITable* table);
	virtual ITable* GetTable();
	virtual std::string GetSmartDashboardType();
	//virtual void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);

protected:
	void SetTimeout(double timeout);
	bool IsTimedOut();
	bool AssertUnlocked(const char *message);
	void SetParent(CommandGroup *parent);
	virtual void Initialize() = 0;
	virtual void Execute() = 0;
	virtual bool IsFinished() = 0;
	virtual void End() = 0;
	virtual void Interrupted() = 0;
	virtual void _Initialize();
	virtual void _Interrupted();
	virtual void _Execute();
	virtual void _End();
	virtual void _Cancel();
};
