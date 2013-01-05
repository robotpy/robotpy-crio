/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "Commands/Command.h"
#include "ErrorBase.h"
#include "SmartDashboard/NamedSendable.h"
#include <list>
#include <map>
#include <set>
#include <vector>

class ButtonScheduler;
class Subsystem;

class Scheduler : public ErrorBase
{
public:
	static Scheduler *GetInstance();

	void AddCommand(Command* command);
	void AddButton(ButtonScheduler* button);
	void RegisterSubsystem(Subsystem *subsystem);
	void Run();	
	void Remove(Command *command);
	void RemoveAll();
	void SetEnabled(bool enabled);

private:
	Scheduler();
	virtual ~Scheduler();

	void ProcessCommandAddition(Command *command);

	static Scheduler *_instance;
	Command::SubsystemSet m_subsystems;
	SEM_ID m_buttonsLock;
	typedef std::vector<ButtonScheduler *> ButtonVector;
	ButtonVector m_buttons;
	typedef std::vector<Command *> CommandVector;
	SEM_ID m_additionsLock;
	CommandVector m_additions;
	typedef std::set<Command *> CommandSet;
	CommandSet m_commands;
	bool m_adding;
	bool m_enabled;
};
#endif

