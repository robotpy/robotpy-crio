/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "AnalogTrigger.h"

#include "AnalogChannel.h"
#include "AnalogModule.h"
#include "Resource.h"
#include "Utility.h"
#include "WPIStatus.h"

static Resource *triggers = NULL;

/**
 * Initialize an analog trigger from a slot and channel.
 * This is the common code for the two constructors that use a slot and channel.
 */
void AnalogTrigger::InitTrigger(UINT32 slot, UINT32 channel)
{
	Resource::CreateResourceObject(&triggers, tAnalogTrigger::kNumSystems);
	m_channel = channel;
	m_analogModule = AnalogModule::GetInstance(slot);
	m_index = triggers->Allocate();
	m_trigger = new tAnalogTrigger(m_index, &status);
	m_trigger->writeSourceSelect_Channel(m_channel - 1, &status);
	m_trigger->writeSourceSelect_Module(AnalogModule::SlotToIndex(slot), &status);
	wpi_assertCleanStatus(status);
}

/**
 * Constructor for an analog trigger given a channel number.
 * The default module is used in this case.
 */
AnalogTrigger::AnalogTrigger(UINT32 channel)
{
	InitTrigger(GetDefaultAnalogModule(), channel);
}

/**
 * Constructor for an analog trigger given both the slot and channel.
 */
AnalogTrigger::AnalogTrigger(UINT32 slot, UINT32 channel)
{
	InitTrigger(slot, channel);
}

/**
 * Construct an analog trigger given an analog channel.
 * This should be used in the case of sharing an analog channel between the trigger
 * and an analog input object.
 */
AnalogTrigger::AnalogTrigger(AnalogChannel *channel)
{
	InitTrigger(channel->GetSlot(), channel->GetChannel());
}

AnalogTrigger::~AnalogTrigger()
{
	triggers->Free(m_index);
	delete m_trigger;
}

/**
 * Set the upper and lower limits of the analog trigger.
 * The limits are given in ADC codes.  If oversampling is used, the units must be scaled
 * appropriately.
 */
void AnalogTrigger::SetLimitsRaw(INT32 lower, INT32 upper)
{
	if (lower > upper)
	{
		wpi_fatal(AnalogTriggerLimitOrderError);
	}
	m_trigger->writeLowerLimit(lower, &status);
	m_trigger->writeUpperLimit(upper, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Set the upper and lower limits of the analog trigger.
 * The limits are given as floating point voltage values.
 */
void AnalogTrigger::SetLimitsVoltage(float lower, float upper)
{
	if (lower > upper)
	{
		wpi_fatal(AnalogTriggerLimitOrderError);
	}
	// TODO: This depends on the averaged setting.  Only raw values will work as is.
	m_trigger->writeLowerLimit(m_analogModule->VoltsToValue(m_channel, lower), &status);
	m_trigger->writeUpperLimit(m_analogModule->VoltsToValue(m_channel, upper), &status);
	wpi_assertCleanStatus(status);
}

/**
 * Configure the analog trigger to use the averaged vs. raw values.
 * If the value is true, then the averaged value is selected for the analog trigger, otherwise
 * the immediate value is used.
 */
void AnalogTrigger::SetAveraged(bool useAveragedValue)
{
	wpi_assert(m_trigger->readSourceSelect_Filter(&status) == 0);
	m_trigger->writeSourceSelect_Averaged(useAveragedValue, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Configure the analog trigger to use a filtered value.
 * The analog trigger will operate with a 3 point average rejection filter. This is designed to
 * help with 360 degree pot applications for the period where the pot crosses through zero.
 */
void AnalogTrigger::SetFiltered(bool useFilteredValue)
{
	wpi_assert(m_trigger->readSourceSelect_Averaged(&status) == 0);
	m_trigger->writeSourceSelect_Filter(useFilteredValue, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Return the index of the analog trigger.
 * This is the FPGA index of this analog trigger instance.
 * @return The index of the analog trigger.
 */
UINT32 AnalogTrigger::GetIndex()
{
	return m_index;
}

/**
 * Return the InWindow output of the analog trigger.
 * True if the analog input is between the upper and lower limits.
 * @return The InWindow output of the analog trigger.
 */
bool AnalogTrigger::GetInWindow()
{
	return m_trigger->readOutput_InHysteresis(m_index, &status) != 0;
}

/**
 * Return the TriggerState output of the analog trigger.
 * True if above upper limit.
 * False if below lower limit.
 * If in Hysteresis, maintain previous state.
 * @return The TriggerState output of the analog trigger.
 */
bool AnalogTrigger::GetTriggerState()
{
	return m_trigger->readOutput_OverLimit(m_index, &status) != 0;
}

/**
 * Creates an AnalogTriggerOutput object.
 * Gets an output object that can be used for routing.
 * Caller is responsible for deleting the AnalogTriggerOutput object.
 * @param type An enum of the type of output object to create.
 * @return A pointer to a new AnalogTriggerOutput object.
 */
AnalogTriggerOutput *AnalogTrigger::CreateOutput(AnalogTriggerOutput::Type type)
{
	return new AnalogTriggerOutput(this, type);
}

