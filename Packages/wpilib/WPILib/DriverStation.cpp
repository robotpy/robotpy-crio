/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DriverStation.h"
#include "AnalogChannel.h"
#include "Synchronized.h"
#include "Timer.h"
#include "Utility.h"
#include "WPIStatus.h"
#include "NetworkCommunication/FRCComm.h"
#include <strLib.h>
#include "MotorSafetyHelper.h"

const UINT32 DriverStation::kBatterySlot;
const UINT32 DriverStation::kBatteryChannel;
const UINT32 DriverStation::kJoystickPorts;
const UINT32 DriverStation::kJoystickAxes;
const float DriverStation::kUpdatePeriod;
DriverStation* DriverStation::m_instance = NULL;
UINT8 DriverStation::m_updateNumber = 0;

/**
 * DriverStation contructor.
 * 
 * This is only called once the first time GetInstance() is called
 */
DriverStation::DriverStation()
	: m_controlData (NULL)
	, m_digitalOut (0)
	, m_batteryChannel (NULL)
	, m_statusDataSemaphore (semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE))
	, m_task ("DriverStation", (FUNCPTR)DriverStation::InitTask)
	, m_dashboardHigh(m_statusDataSemaphore)
	, m_dashboardLow(m_statusDataSemaphore)
	, m_dashboardInUseHigh(&m_dashboardHigh)
	, m_dashboardInUseLow(&m_dashboardLow)
	, m_newControlData (false)
	, m_packetDataAvailableSem (0)
	, m_enhancedIO()
{
	// Create a new semaphore
	m_packetDataAvailableSem = semBCreate (SEM_Q_PRIORITY, SEM_EMPTY);

	// Register that semaphore with the network communications task.
	// It will signal when new packet data is available. 
	setNewDataSem(m_packetDataAvailableSem);

	m_controlData = new FRCCommonControlData;

	// initialize packet number and control words to zero;
	m_controlData->packetIndex = 0;
	m_controlData->control = 0;

	// set all joystick axis values to neutral; buttons to OFF
	m_controlData->stick0Axis1 = m_controlData->stick0Axis2 = m_controlData->stick0Axis3 = 0;
	m_controlData->stick1Axis1 = m_controlData->stick1Axis2 = m_controlData->stick1Axis3 = 0;
	m_controlData->stick2Axis1 = m_controlData->stick2Axis2 = m_controlData->stick2Axis3 = 0;
	m_controlData->stick3Axis1 = m_controlData->stick3Axis2 = m_controlData->stick3Axis3 = 0;
	m_controlData->stick0Axis4 = m_controlData->stick0Axis5 = m_controlData->stick0Axis6 = 0;
	m_controlData->stick1Axis4 = m_controlData->stick1Axis5 = m_controlData->stick1Axis6 = 0;
	m_controlData->stick2Axis4 = m_controlData->stick2Axis5 = m_controlData->stick2Axis6 = 0;
	m_controlData->stick3Axis4 = m_controlData->stick3Axis5 = m_controlData->stick3Axis6 = 0;
	m_controlData->stick0Buttons = 0;
	m_controlData->stick1Buttons = 0;
	m_controlData->stick2Buttons = 0;
	m_controlData->stick3Buttons = 0;

	// initialize the analog and digital data.
	m_controlData->analog1 = 0;
	m_controlData->analog2 = 0;
	m_controlData->analog3 = 0;
	m_controlData->analog4 = 0;
	m_controlData->dsDigitalIn = 0;

	m_batteryChannel = new AnalogChannel(kBatterySlot, kBatteryChannel);

	AddToSingletonList();

	if (!m_task.Start((INT32)this))
	{
		wpi_fatal(DriverStationTaskError);
	}
}

DriverStation::~DriverStation()
{
	m_task.Stop();
	semDelete(m_statusDataSemaphore);
	delete m_batteryChannel;
	delete m_controlData;
	m_instance = NULL;
	// Unregister our semaphore.
	setNewDataSem(0);
	semDelete(m_packetDataAvailableSem);
}

void DriverStation::InitTask(DriverStation *ds)
{
	ds->Run();
}

void DriverStation::Run()
{
	int period = 0;
	while (true)
	{
		semTake(m_packetDataAvailableSem, WAIT_FOREVER);
		SetData();
		m_enhancedIO.UpdateData();
		GetData();
		if (++period >= 4)
		{
			MotorSafetyHelper::CheckMotors();
			period = 0;
		}
	}
}

/**
 * Return a pointer to the singleton DriverStation.
 */
DriverStation* DriverStation::GetInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new DriverStation();
	}
	return m_instance;
}

/**
 * Copy data from the DS task for the user.
 * If no new data exists, it will just be returned, otherwise
 * the data will be copied from the DS polling loop.
 */
void DriverStation::GetData()
{
	getCommonControlData(m_controlData, WAIT_FOREVER);
	m_newControlData = true;
}

/**
 * Copy status data from the DS task for the user.
 */
void DriverStation::SetData()
{
	char *userStatusDataHigh;
	INT32 userStatusDataHighSize;
	char *userStatusDataLow;
	INT32 userStatusDataLowSize;

	Synchronized sync(m_statusDataSemaphore);

	m_dashboardInUseHigh->GetStatusBuffer(&userStatusDataHigh, &userStatusDataHighSize);
	m_dashboardInUseLow->GetStatusBuffer(&userStatusDataLow, &userStatusDataLowSize);
	setStatusData(GetBatteryVoltage(), m_digitalOut, m_updateNumber,
		userStatusDataHigh, userStatusDataHighSize, userStatusDataLow, userStatusDataLowSize, WAIT_FOREVER);
	
	m_dashboardInUseHigh->Flush();
	m_dashboardInUseLow->Flush();
}

/**
 * Read the battery voltage from the specified AnalogChannel.
 * 
 * This accessor assumes that the battery voltage is being measured
 * through the voltage divider on an analog breakout.
 * 
 * @return The battery voltage.
 */
float DriverStation::GetBatteryVoltage()
{
	wpi_assert(m_batteryChannel != NULL);

	// The Analog bumper has a voltage divider on the battery source.
	// Vbatt *--/\/\/\--* Vsample *--/\/\/\--* Gnd
	//         680 Ohms            1000 Ohms
	return m_batteryChannel->GetAverageVoltage() * (1680.0 / 1000.0);
}

/**
 * Get the value of the axis on a joystick.
 * This depends on the mapping of the joystick connected to the specified port.
 * 
 * @param stick The joystick to read.
 * @param axis The analog axis value to read from the joystick.
 * @return The value of the axis on the joystick.
 */
float DriverStation::GetStickAxis(UINT32 stick, UINT32 axis)
{
	if (axis < 1 || axis > kJoystickAxes)
	{
		wpi_fatal(BadJoystickAxis);
		return 0.0;
	}

	INT8 value;
	switch (stick)
	{
		case 1:
			value = m_controlData->stick0Axes[axis-1];
			break;
		case 2:
			value = m_controlData->stick1Axes[axis-1];
			break;
		case 3:
			value = m_controlData->stick2Axes[axis-1];
			break;
		case 4:
			value = m_controlData->stick3Axes[axis-1];
			break;
		default:
			wpi_fatal(BadJoystickIndex);
			return 0.0;
	}
	
	float result;
	if (value < 0)
		result = ((float) value) / 128.0;
	else
		result = ((float) value) / 127.0;
	wpi_assert(result <= 1.0 && result >= -1.0);
	if (result > 1.0)
		result = 1.0;
	else if (result < -1.0)
		result = -1.0;
	return result;
}

/**
 * The state of the buttons on the joystick.
 * 12 buttons (4 msb are unused) from the joystick.
 * 
 * @param stick The joystick to read.
 * @return The state of the buttons on the joystick.
 */
short DriverStation::GetStickButtons(UINT32 stick)
{
	wpi_assert ((stick >= 1) && (stick <= 4));
	switch (stick)
	{
	case 1:
		return m_controlData->stick0Buttons;
	case 2:
		return m_controlData->stick1Buttons;
	case 3:
		return m_controlData->stick2Buttons;
	case 4:
		return m_controlData->stick3Buttons;
	}
	return 0;
}

// 5V divided by 10 bits
#define kDSAnalogInScaling ((float)(5.0 / 1023.0))

/**
 * Get an analog voltage from the Driver Station.
 * The analog values are returned as voltage values for the Driver Station analog inputs.
 * These inputs are typically used for advanced operator interfaces consisting of potentiometers
 * or resistor networks representing values on a rotary switch.
 * 
 * @param channel The analog input channel on the driver station to read from. Valid range is 1 - 4.
 * @return The analog voltage on the input.
 */
float DriverStation::GetAnalogIn(UINT32 channel)
{
	wpi_assert ((channel >= 1) && (channel <= 4));
	switch (channel)
	{
	case 1:
		return kDSAnalogInScaling * m_controlData->analog1;
	case 2:
		return kDSAnalogInScaling * m_controlData->analog2;
	case 3:
		return kDSAnalogInScaling * m_controlData->analog3;
	case 4:
		return kDSAnalogInScaling * m_controlData->analog4;
	}
	return 0.0;
}

/**
 * Get values from the digital inputs on the Driver Station.
 * Return digital values from the Drivers Station. These values are typically used for buttons
 * and switches on advanced operator interfaces.
 * @param channel The digital input to get. Valid range is 1 - 8.
 */
bool DriverStation::GetDigitalIn(UINT32 channel)
{
	wpi_assert ((channel >= 1) && (channel <= 8));
	return ((m_controlData->dsDigitalIn >> (channel-1)) & 0x1) ? true : false;
}

/**
 * Set a value for the digital outputs on the Driver Station.
 * 
 * Control digital outputs on the Drivers Station. These values are typically used for
 * giving feedback on a custom operator station such as LEDs.
 * 
 * @param channel The digital output to set. Valid range is 1 - 8.
 * @param value The state to set the digital output.
 */
void DriverStation::SetDigitalOut(UINT32 channel, bool value) 
{
	wpi_assert ((channel >= 1) && (channel <= 8));
	m_digitalOut &= ~(0x1 << (channel-1));
	m_digitalOut |= ((UINT8)value << (channel-1));
}

/**
 * Get a value that was set for the digital outputs on the Driver Station.
 * @param channel The digital ouput to monitor. Valid range is 1 through 8.
 * @return A digital value being output on the Drivers Station.
 */
bool DriverStation::GetDigitalOut(UINT32 channel) 
{
	wpi_assert ((channel >= 1) && (channel <= 8));
	return ((m_digitalOut >> (channel-1)) & 0x1) ? true : false;;
}

bool DriverStation::IsEnabled()
{
	return m_controlData->enabled;
}

bool DriverStation::IsDisabled()
{
	return !m_controlData->enabled;
}

bool DriverStation::IsAutonomous()
{
	return m_controlData->autonomous;
}

bool DriverStation::IsOperatorControl()
{
	return !m_controlData->autonomous;
}

/**
 * Has a new control packet from the driver station arrived since the last time this function was called?
 * @return True if the control data has been updated since the last call.
 */
bool DriverStation::IsNewControlData()
{
	bool newData = m_newControlData;
	m_newControlData = false;
	return newData;
}

/**
 * Is the driver station attached to a Field Management System?
 * Note: This does not work with the Blue DS.
 * @return True if the robot is competing on a field being controlled by a Field Management System
 */
bool DriverStation::IsFMSAttached()
{
	return m_controlData->fmsAttached;
}

/**
 * Return the DS packet number.
 * The packet number is the index of this set of data returned by the driver station.
 * Each time new data is received, the packet number (included with the sent data) is returned.
 */
UINT32 DriverStation::GetPacketNumber()
{
	return m_controlData->packetIndex;
}


DriverStation::Alliance DriverStation::GetAlliance()
{
	if (m_controlData->dsID_Alliance == 'R') return kRed;
	if (m_controlData->dsID_Alliance == 'B') return kBlue;
	wpi_assert(false);
	return kInvalid;
}

UINT32 DriverStation::GetLocation()
{
	wpi_assert ((m_controlData->dsID_Position >= '1') && (m_controlData->dsID_Position <= '3'));
	return m_controlData->dsID_Position - '0';
}

