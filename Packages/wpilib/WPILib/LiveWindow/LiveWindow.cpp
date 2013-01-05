#include "LiveWindow/LiveWindow.h"
#include "networktables/NetworkTable.h"

LiveWindow* LiveWindow::m_instance = NULL;

/**
 * Get an instance of the LiveWindow main class
 * This is a singleton to guarantee that there is only a single instance regardless of
 * how many times GetInstance is called.
 */
LiveWindow * LiveWindow::GetInstance() {
	if (m_instance == NULL) {
		m_instance = new LiveWindow();
	}
	return m_instance;
}

/**
 * LiveWindow constructor.
 * Allocate the necessary tables.
 */
LiveWindow::LiveWindow() {
	m_enabled = false;
	m_liveWindowTable = NetworkTable::GetTable("LiveWindow");
	m_statusTable = m_liveWindowTable->GetSubTable("~STATUS~");
	m_scheduler = Scheduler::GetInstance();
}

/**
 * Change the enabled status of LiveWindow
 * If it changes to enabled, start livewindow running otherwise stop it
 */
void LiveWindow::SetEnabled(bool enabled) {
	if (m_enabled == enabled) return;
	if (enabled) {
		printf("Starting live window mode\n");
		m_scheduler->SetEnabled(false);
		m_scheduler->RemoveAll();
		for (unsigned int i = 0; i < m_components.size(); i++) {
			m_components[i]->StartLiveWindowMode();
		}
	} else {
		printf("Ending LiveWindow mode\n");
		for (unsigned int i = 0; i < m_components.size(); i++) {
			m_components[i]->StopLiveWindowMode();
		}
		m_scheduler->SetEnabled(true);
	}
	m_enabled = enabled;
	m_statusTable->PutBoolean("LW Enabled", m_enabled);
}

LiveWindow::~LiveWindow() {
}

/**
 * Add a Sensor associated with the subsystem and with call it by the given name.
 * @param subsystem The subsystem this component is part of.
 * @param name The name of this component.
 * @param component A LiveWindowSendable component that represents a sensor.
 */
void LiveWindow::AddSensor(char *subsystem, char *name, LiveWindowSendable *component) {
	AddComponent(subsystem, name, component);
	m_sensors.push_back(component);
}

/**
 * Add an Actuator associated with the subsystem and with call it by the given name.
 * @param subsystem The subsystem this component is part of.
 * @param name The name of this component.
 * @param component A LiveWindowSendable component that represents a actuator.
 */
void LiveWindow::AddActuator(char *subsystem, char *name, LiveWindowSendable *component) {
	AddComponent(subsystem, name, component);
	m_actuators.push_back(component);
}

/**
 * Add a Component associated with the subsystem and with call it by the given name.
 * @param subsystem The subsystem this component is part of.
 * @param name The name of this component.
 * @param component A LiveWindowSendable component that represents a component.
 */
void LiveWindow::AddComponent(char *subsystem, char *name, LiveWindowSendable *component) {
	m_liveWindowTable->GetSubTable(subsystem)->PutString("~TYPE~", "LW Subsystem");
	ITable *table = m_liveWindowTable->GetSubTable(subsystem)->GetSubTable(name);
	table->PutString("~TYPE~", component->GetSmartDashboardType());
	table->PutString("Name", name);
	table->PutString("Subsystem", subsystem);
	component->InitTable(table);
	m_components.push_back(component);
}

/**
 * Tell all the sensors to update (send) their values
 * Actuators are handled through callbacks on their value changing from the
 * SmartDashboard widgets.
 */
void LiveWindow::UpdateValues() {
	for (unsigned int i = 0; i < m_sensors.size(); i++) {
		m_sensors[i]->UpdateTable();
	}
}

/**
 * This method is called periodically to cause the sensors to send new values
 * to the SmartDashboard.
 */
void LiveWindow::Run() {
	if (m_enabled) {
		UpdateValues();
	}
}

