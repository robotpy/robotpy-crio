/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Relay.h"

#include "DigitalModule.h"
#include "Resource.h"
#include "Utility.h"

// Allocate each direction separately.
static Resource *relayChannels = NULL;

/**
 * Common relay intitialization methode.
 * This code is common to all Relay constructors and initializes the relay and reserves
 * all resources that need to be locked. Initially the relay is set to both lines at 0v.
 * @param slot The module slot number this relay is connected to.
 */
void Relay::InitRelay (UINT32 slot)
{
	Resource::CreateResourceObject(&relayChannels, tDIO::kNumSystems * kRelayChannels * 2);
	if (SensorBase::CheckRelayModule(slot) && SensorBase::CheckRelayChannel(m_channel))
	{
		if (m_direction == kBothDirections || m_direction == kForwardOnly)
		{
			relayChannels->Allocate((DigitalModule::SlotToIndex(slot) * kRelayChannels + m_channel - 1) * 2);
		}
		if (m_direction == kBothDirections || m_direction == kReverseOnly)
		{
			relayChannels->Allocate((DigitalModule::SlotToIndex(slot) * kRelayChannels + m_channel - 1) * 2 + 1);
		}
		m_module = DigitalModule::GetInstance(slot);
		m_module->SetRelayForward(m_channel, false);
		m_module->SetRelayReverse(m_channel, false);
	}
}

/**
 * Relay constructor given the module and the channel.
 * @param slot The module slot number this relay is connected to.
 * @param channel The channel number within the module for this relay.
 * @param direction The direction that the Relay object will control.
 */
Relay::Relay(UINT32 slot, UINT32 channel, Relay::Direction direction)
	: m_channel (channel)
	, m_direction (direction)
{
	InitRelay(slot);
}

/**
 * Relay constructor given a channel only where the default digital module is used.
 * @param channel The channel number within the default module for this relay.
 * @param direction The direction that the Relay object will control.
 */
Relay::Relay(UINT32 channel, Relay::Direction direction)
	: m_channel (channel)
	, m_direction (direction)
{
	InitRelay(GetDefaultDigitalModule());
}

/**
 * Free the resource associated with a relay.
 * The relay channels are set to free and the relay output is turned off.
 */
Relay::~Relay()
{
	m_module->SetRelayForward(m_channel, false);
	m_module->SetRelayReverse(m_channel, false);

	if (m_direction == kBothDirections || m_direction == kForwardOnly)
	{
		relayChannels->Free((DigitalModule::SlotToIndex(m_module->GetSlot()) * kRelayChannels + m_channel - 1) * 2);
	}
	if (m_direction == kBothDirections || m_direction == kReverseOnly)
	{
		relayChannels->Free((DigitalModule::SlotToIndex(m_module->GetSlot()) * kRelayChannels + m_channel - 1) * 2 + 1);
	}
}

/**
 * Set the relay state.
 * 
 * Valid values depend on which directions of the relay are controlled by the object.
 * 
 * When set to kBothDirections, the relay can only be one of the three reasonable
 *    values, 0v-0v, 0v-12v, or 12v-0v.
 * 
 * When set to kForwardOnly or kReverseOnly, you can specify the constant for the
 *    direction or you can simply specify kOff and kOn.  Using only kOff and kOn is
 *    recommended.
 * 
 * @param value The state to set the relay.
 */
void Relay::Set(Relay::Value value)
{
	switch (value)
	{
	case kOff:
		if (m_direction == kBothDirections || m_direction == kForwardOnly)
		{
			m_module->SetRelayForward(m_channel, false);
		}
		if (m_direction == kBothDirections || m_direction == kReverseOnly)
		{
			m_module->SetRelayReverse(m_channel, false);
		}
		break;
	case kOn:
		wpi_assert(m_direction != kBothDirections);
		if (m_direction == kForwardOnly)
		{
			m_module->SetRelayForward(m_channel, true);
		}
		else if (m_direction == kReverseOnly)
		{
			m_module->SetRelayReverse(m_channel, true);
		}
		break;
	case kForward:
		wpi_assert(m_direction != kReverseOnly);
		if (m_direction == kBothDirections || m_direction == kForwardOnly)
		{
			m_module->SetRelayForward(m_channel, true);
		}
		if (m_direction == kBothDirections)
		{
			m_module->SetRelayReverse(m_channel, false);
		}
		break;
	case kReverse:
		wpi_assert(m_direction != kForwardOnly);
		if (m_direction == kBothDirections)
		{
			m_module->SetRelayForward(m_channel, false);
		}
		if (m_direction == kBothDirections || m_direction == kReverseOnly)
		{
			m_module->SetRelayReverse(m_channel, true);
		}
		break;
	default:
		wpi_assert(false);
	}
}


/**
 * Set the Relay Direction
 * 
 * Changes which values the relay can be set to depending on which direction is 
 * used
 * 
 * Valid inputs are kBothDirections, kForwardOnly, and kReverseOnly
 * 
 *@param direction The direction for the relay to operate in
 */ 
void Relay::SetDirection(Relay::Direction direction){
	if(m_direction == direction)
		return;
	m_module->SetRelayForward(m_channel, false);
	m_module->SetRelayReverse(m_channel, false);
	switch(direction)
	{
	case kBothDirections:
		m_direction = kBothDirections;
		break;
	case kForwardOnly:
		m_direction = kForwardOnly;
		break;
	case kReverseOnly:
		m_direction = kReverseOnly;
		break;
	default:
		wpi_assert(false);
	}
}

