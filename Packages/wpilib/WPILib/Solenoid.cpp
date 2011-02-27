/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Solenoid.h"

/**
 * Common function to implement constructor behavior.
 */
void Solenoid::InitSolenoid()
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		CheckSolenoidChannel(m_channel);
		Resource::CreateResourceObject(&m_allocated, tSolenoid::kNumDO7_0Elements * kSolenoidChannels);
	
		m_allocated->Allocate(SlotToIndex(m_chassisSlot) * kSolenoidChannels + m_channel - 1);
	}
}

/**
 * Constructor.
 * 
 * @param channel The channel on the module to control.
 */
Solenoid::Solenoid(UINT32 channel)
	: SolenoidBase (GetDefaultSolenoidModule())
	, m_channel (channel)
{
	InitSolenoid();
}

/**
 * Constructor.
 * 
 * @param slot The slot that the 9472 module is plugged into.
 * @param channel The channel on the module to control.
 */
Solenoid::Solenoid(UINT32 slot, UINT32 channel)
	: SolenoidBase (slot)
	, m_channel (channel)
{
	InitSolenoid();
}

/**
 * Destructor.
 */
Solenoid::~Solenoid()
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		m_allocated->Free(SlotToIndex(m_chassisSlot) * kSolenoidChannels + m_channel - 1);
	}
}

/**
 * Set the value of a solenoid.
 * 
 * @param on Turn the solenoid output off or on.
 */
void Solenoid::Set(bool on)
{
	UINT8 value = on ? 0xFF : 0x00;
	UINT8 mask = 1 << (m_channel - 1);

	SolenoidBase::Set(value, mask);
}

/**
 * Read the current value of the solenoid.
 * 
 * @return The current value of the solenoid.
 */
bool Solenoid::Get()
{
	UINT8 value = GetAll() & ( 1 << (m_channel - 1));
	return (value != 0);
}
