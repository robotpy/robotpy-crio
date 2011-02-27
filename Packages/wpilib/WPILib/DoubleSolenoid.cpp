/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DoubleSolenoid.h"

/**
 * Common function to implement constructor behavior.
 */
void DoubleSolenoid::InitSolenoid()
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		CheckSolenoidChannel(m_forwardChannel);
		CheckSolenoidChannel(m_reverseChannel);
		Resource::CreateResourceObject(&m_allocated, tSolenoid::kNumDO7_0Elements * kSolenoidChannels);

		m_allocated->Allocate(SlotToIndex(m_chassisSlot) * kSolenoidChannels + m_forwardChannel - 1);
		m_allocated->Allocate(SlotToIndex(m_chassisSlot) * kSolenoidChannels + m_reverseChannel - 1);
	}
	m_forwardMask = 1 << (m_forwardChannel - 1);
	m_reverseMask = 1 << (m_reverseChannel - 1);
}

/**
 * Constructor.
 * 
 * @param forwardChannel The forward channel on the module to control.
 * @param reverseChannel The reverse channel on the module to control.
 */
DoubleSolenoid::DoubleSolenoid(UINT32 forwardChannel, UINT32 reverseChannel)
	: SolenoidBase (GetDefaultSolenoidModule())
	, m_forwardChannel (forwardChannel)
	, m_reverseChannel (reverseChannel)
{
	InitSolenoid();
}

/**
 * Constructor.
 * 
 * @param slot The slot that the 9472 module is plugged into.
 * @param forwardChannel The forward channel on the module to control.
 * @param reverseChannel The reverse channel on the module to control.
 */
DoubleSolenoid::DoubleSolenoid(UINT32 slot, UINT32 forwardChannel, UINT32 reverseChannel)
	: SolenoidBase (slot)
	, m_forwardChannel (forwardChannel)
	, m_reverseChannel (reverseChannel)
{
	InitSolenoid();
}

/**
 * Destructor.
 */
DoubleSolenoid::~DoubleSolenoid()
{
	if (CheckSolenoidModule(m_chassisSlot))
	{
		m_allocated->Free(SlotToIndex(m_chassisSlot) * kSolenoidChannels + m_forwardChannel - 1);
		m_allocated->Free(SlotToIndex(m_chassisSlot) * kSolenoidChannels + m_reverseChannel - 1);
	}
}

/**
 * Set the value of a solenoid.
 * 
 * @param value Move the solenoid to forward, reverse, or don't move it.
 */
void DoubleSolenoid::Set(Value value)
{
	UINT8 rawValue;

	switch(value)
	{
	case kOff:
		rawValue = 0x00;
		break;
	case kForward:
		rawValue = m_forwardMask;
		break;
	case kReverse:
		rawValue = m_reverseMask;
		break;
	}

	SolenoidBase::Set(rawValue, m_forwardMask | m_reverseMask);
}

/**
 * Read the current value of the solenoid.
 * 
 * @return The current value of the solenoid.
 */
DoubleSolenoid::Value DoubleSolenoid::Get()
{
	UINT8 value = GetAll();

	if (value & m_forwardMask) return kForward;
	if (value & m_reverseMask) return kReverse;
	return kOff;
}
