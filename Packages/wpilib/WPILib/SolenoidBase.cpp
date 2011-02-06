/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "SolenoidBase.h"

#include "Synchronized.h"
#include "Utility.h"

SEM_ID SolenoidBase::m_semaphore = NULL;
Resource *SolenoidBase::m_allocated = NULL;

tSolenoid *SolenoidBase::m_fpgaSolenoidModule = NULL;
UINT32 SolenoidBase::m_refCount = 0;


/**
 * Constructor
 * 
 * @param slot The slot that this SolenoidBase accesses.
 */
SolenoidBase::SolenoidBase(UINT32 slot)
	: m_chassisSlot (slot)
{
	m_refCount++;
	if (m_refCount == 1)
	{
		// Needs to be global since the protected resource spans all Solenoid objects.
		m_semaphore = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
		m_fpgaSolenoidModule = new tSolenoid(&status);
	}
	wpi_assertCleanStatus(status);
}

/**
 * Destructor.
 */
SolenoidBase::~SolenoidBase()
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		if (m_refCount == 1)
		{
			delete m_fpgaSolenoidModule;
			m_fpgaSolenoidModule = NULL;
			semDelete(m_semaphore);
			m_semaphore = NULL;
		}
		m_refCount--;
	}
}

/**
 * Convert slot number to index.
 * 
 * @param slot The slot in the chassis where the module is plugged in.
 * @return An index to represent the module internally.
 */
UINT32 SolenoidBase::SlotToIndex(UINT32 slot)
{
	return 8 - slot;
}

/**
 * Set the value of a solenoid.
 * 
 * @param value The value you want to set on the module.
 * @param mask The channels you want to be affected.
 */
void SolenoidBase::Set(UINT8 value, UINT8 mask)
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		Synchronized sync(m_semaphore);
		UINT8 currentValue = m_fpgaSolenoidModule->readDO7_0(SlotToIndex(m_chassisSlot), &status);
		// Zero out the values to change
		currentValue = currentValue & ~mask;
		currentValue = currentValue | (value & mask);
		m_fpgaSolenoidModule->writeDO7_0(SlotToIndex(m_chassisSlot), currentValue, &status);
	}

	wpi_assertCleanStatus(status);
}

/**
 * Read all 8 solenoids as a single byte
 * 
 * @return The current value of all 8 solenoids on the module.
 */
UINT8 SolenoidBase::GetAll()
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		return m_fpgaSolenoidModule->readDO7_0(SlotToIndex(m_chassisSlot), &status);
	}
	return 0;
}
