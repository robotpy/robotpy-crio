#ifndef _LIVE_WINDOW_H
#define _LIVE_WINDOW_H

#include "LiveWindow/LiveWindowSendable.h"
#include "tables/ITable.h"
#include "Commands/Scheduler.h"
#include <vector>

/**
 * The LiveWindow class is the public interface for putting sensors and actuators
 * on the LiveWindow.
 *
 * @author Brad Miller
 */
class LiveWindow {
public:
	static LiveWindow * GetInstance();
	void Run();
	void AddSensor(char *subsystem, char *name, LiveWindowSendable *component);
	void AddActuator(char *subsystem, char *name, LiveWindowSendable *component);
	void AddComponent(char *subsystem, char *name, LiveWindowSendable *component);
	
	bool IsEnabled() { return m_enabled; }
	void SetEnabled(bool enabled);

protected:
	LiveWindow();
	virtual ~LiveWindow();

private:
	void UpdateValues();
	void Initialize();
	
	std::vector<LiveWindowSendable *> m_sensors;
	std::vector<LiveWindowSendable *> m_actuators;
	std::vector<LiveWindowSendable *> m_components;
	
	static LiveWindow *m_instance;
	ITable *m_liveWindowTable;
	ITable *m_statusTable;
	
	Scheduler *m_scheduler;
	
	bool m_enabled;
};

#endif

