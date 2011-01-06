/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "SensorBase.h"

#include "Utility.h"
#include "WPIStatus.h"

const UINT32 SensorBase::kSystemClockTicksPerMicrosecond;
const UINT32 SensorBase::kDigitalChannels;
const UINT32 SensorBase::kAnalogChannels;
const UINT32 SensorBase::kAnalogModules;
const UINT32 SensorBase::kDigitalModules;
const UINT32 SensorBase::kSolenoidChannels;
const UINT32 SensorBase::kSolenoidModules;
const UINT32 SensorBase::kPwmChannels;
const UINT32 SensorBase::kRelayChannels;
const UINT32 SensorBase::kChassisSlots;
UINT32 SensorBase::m_defaultAnalogModule = 1;
UINT32 SensorBase::m_defaultDigitalModule = 4;
UINT32 SensorBase::m_defaultSolenoidModule = 8;
SensorBase *SensorBase::m_singletonList = NULL;

// Slots are one based index, so ignore element 0.
static const UINT32 modulePopulation[] = {0,  9201, 9201, 0, 9403, 0, 9403, 9472, 9472};

/**
 * Creates an instance of the sensor base and gets an FPGA handle
 */
SensorBase::SensorBase()
{
}

/**
 * Frees the resources for a SensorBase.
 */
SensorBase::~SensorBase()
{
}

/**
 * Add sensor to the singleton list.
 * Add this sensor to the list of singletons that need to be deleted when
 * the robot program exits. Each of the sensors on this list are singletons,
 * that is they aren't allocated directly with new, but instead are allocated
 * by the static GetInstance method. As a result, they are never deleted when
 * the program exits. Consequently these sensors may still be holding onto
 * resources and need to have their destructors called at the end of the program.
 */
void SensorBase::AddToSingletonList()
{
	m_nextSingleton = m_singletonList;
	m_singletonList = this;
}

/**
 * Delete all the singleton classes on the list.
 * All the classes that were allocated as singletons need to be deleted so
 * their resources can be freed.
 */
void SensorBase::DeleteSingletons()
{
	for (SensorBase *next = m_singletonList; next != NULL;)
	{
		SensorBase *tmp = next;
		next = next->m_nextSingleton;
		delete tmp;
	}
	m_singletonList = NULL;
}

/**
 * Sets the default Digital Module.
 * This sets the default digital module to use for objects that are created without
 * specifying the digital module in the constructor. The default module is initialized
 * to the first module in the chassis.
 */
void SensorBase::SetDefaultDigitalModule(UINT32 slot)
{
	wpi_assert(slot <= kChassisSlots && modulePopulation[slot] == 9403);
	m_defaultDigitalModule = slot;
}

/**
 * Sets the default Analog module.
 * This sets the default analog module to use for objects that are created without
 * specifying the analog module in the constructor. The default module is initialized
 * to the first module in the chassis.
 */
void SensorBase::SetDefaultAnalogModule(UINT32 slot)
{
	wpi_assert(slot <= kChassisSlots && modulePopulation[slot] == 9201);
	m_defaultAnalogModule = slot;
}

/**
 * Set the default location for the Solenoid (9472) module.
 * Currently the module must be in slot 8, but it might change in the future.
 */
void SensorBase::SetDefaultSolenoidModule(UINT32 slot)
{
	wpi_assert(slot <= kChassisSlots && modulePopulation[slot] == 9472);
	m_defaultSolenoidModule = slot;
}

/**
 * Check that the digital module number is valid.
 * Module numbers are the slot number that they are inserted in.
 */
bool SensorBase::CheckDigitalModule(UINT32 slot)
{
	if (slot <= kChassisSlots && modulePopulation[slot] == 9403)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Check that the digital module number is valid.
 * Module numbers are the slot number that they are inserted in.
 */
bool SensorBase::CheckRelayModule(UINT32 slot)
{
	return CheckDigitalModule(slot);
}

/**
 * Check that the digital module number is valid.
 * Module numbers are the slot number that they are inserted in.
 */
bool SensorBase::CheckPWMModule(UINT32 slot)
{
	return CheckDigitalModule(slot);
}

/**
 * Check that the analog module number is valid.
 * Module numbers are the slot numbers that they are inserted in.
 */
bool SensorBase::CheckAnalogModule(UINT32 slot)
{
	if (slot <= kChassisSlots && modulePopulation[slot] == 9201)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Verify that the solenoid module is correct.
 * Verify that the solenoid module is slot 8 or 7.
 */
bool SensorBase::CheckSolenoidModule(UINT32 slot)
{
	if (slot <= kChassisSlots && modulePopulation[slot] == 9472)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Check that the digital channel number is valid.
 * Verify that the channel number is one of the legal channel numbers. Channel numbers are
 * 1-based.
 */
bool SensorBase::CheckDigitalChannel(UINT32 channel)
{
	if (channel > 0 && channel <= kDigitalChannels)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Check that the digital channel number is valid.
 * Verify that the channel number is one of the legal channel numbers. Channel numbers are
 * 1-based.
 */
bool SensorBase::CheckRelayChannel(UINT32 channel)
{
	if (channel > 0 && channel <= kRelayChannels)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Check that the digital channel number is valid.
 * Verify that the channel number is one of the legal channel numbers. Channel numbers are
 * 1-based.
 */
bool SensorBase::CheckPWMChannel(UINT32 channel)
{
	if (channel > 0 && channel <= kPwmChannels)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Check that the analog channel number is value.
 * Verify that the analog channel number is one of the legal channel numbers. Channel numbers
 * are 1-based.
 */
bool SensorBase::CheckAnalogChannel(UINT32 channel)
{
	if (channel > 0 && channel <= kAnalogChannels)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

/**
 * Verify that the solenoid channel number is within limits.
 */
bool SensorBase::CheckSolenoidChannel(UINT32 channel)
{
	if (channel > 0 && channel <= kSolenoidChannels)
		return true;
	wpi_fatal(IndexOutOfRange);
	return false;
}

