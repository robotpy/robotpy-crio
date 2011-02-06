/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Counter.h"
#include "AnalogTrigger.h"
#include "DigitalInput.h"
#include "Resource.h"
#include "Utility.h"
#include "WPIStatus.h"

static Resource *counters = NULL;

/**
 * Create an instance of a counter object.
 * This creates a ChipObject counter and initializes status variables appropriately
 */
void Counter::InitCounter(Mode mode)
{
	Resource::CreateResourceObject(&counters, tCounter::kNumSystems);
	m_index = counters->Allocate();
	m_counter = new tCounter(m_index, &status);
	m_counter->writeConfig_Mode(mode, &status);
	m_upSource = NULL;
	m_downSource = NULL;
	m_allocatedUpSource = false;
	m_allocatedDownSource = false;
	m_counter->writeTimerConfig_AverageSize(1, &status);
}

/**
 * Create an instance of a counter where no sources are selected.
 * Then they all must be selected by calling functions to specify the upsource and the downsource
 * independently.
 */
Counter::Counter()
{
	InitCounter();
}

/**
 * Create an instance of a counter from a Digital Input.
 * This is used if an existing digital input is to be shared by multiple other objects such
 * as encoders.
 */
Counter::Counter(DigitalSource *source)
{
	InitCounter();
	SetUpSource(source);
	ClearDownSource();
}

Counter::Counter(DigitalSource &source)
{
	InitCounter();
	SetUpSource(&source);
	ClearDownSource();
}

/**
 * Create an instance of a Counter object.
 * Create an up-Counter instance given a channel. The default digital module is assumed.
 */
Counter::Counter(UINT32 channel)
{
	InitCounter();
	SetUpSource(channel);
	ClearDownSource();
}

/**
 * Create an instance of a Counter object.
 * Create an instance of an up-Counter given a digital module and a channel.
 * @param slot The cRIO chassis slot for the digital module used
 * @param channel The channel in the digital module
 */
Counter::Counter(UINT32 slot, UINT32 channel)
{
	InitCounter();
	SetUpSource(slot, channel);
	ClearDownSource();
}

/**
 * Create an instance of a Counter object.
 * Create an instance of a simple up-Counter given an analog trigger.
 * Use the trigger state output from the analog trigger.
 */
Counter::Counter(AnalogTrigger *trigger)
{
	InitCounter();
	SetUpSource(trigger->CreateOutput(AnalogTriggerOutput::kState));
	ClearDownSource();
	m_allocatedUpSource = true;
}

Counter::Counter(AnalogTrigger &trigger)
{
	InitCounter();
	SetUpSource(trigger.CreateOutput(AnalogTriggerOutput::kState));
	ClearDownSource();
	m_allocatedUpSource = true;
}

Counter::Counter(EncodingType encodingType, DigitalSource *upSource, DigitalSource *downSource, bool inverted)
{
	wpi_assert(encodingType == k1X || encodingType == k2X);
	InitCounter(kExternalDirection);
	SetUpSource(upSource);
	SetDownSource(downSource);

	if (encodingType == k1X)
	{
		SetUpSourceEdge(true, false);
		m_counter->writeTimerConfig_AverageSize(1, &status);
	}
	else
	{
		SetUpSourceEdge(true, true);
		m_counter->writeTimerConfig_AverageSize(2, &status);
	}

	SetDownSourceEdge(inverted, true);
}

/**
 * Delete the Counter object.
 */
Counter::~Counter()
{
	SetUpdateWhenEmpty(true);
	wpi_assert(m_counter != NULL);
	if (m_allocatedUpSource)
	{
		delete m_upSource;
		m_upSource = NULL;
	}
	if (m_allocatedDownSource)
	{
		delete m_downSource;
		m_downSource = NULL;
	}
	delete m_counter;
	m_counter = NULL;
	counters->Free(m_index);
}

/**
 * Set the up source for the counter as digital input channel and slot.
 */
void Counter::SetUpSource(UINT32 slot, UINT32 channel)
{
	SetUpSource(new DigitalInput(slot, channel));
	m_allocatedUpSource = true;
}

/**
 * Set the upsource for the counter as a digital input channel.
 * The slot will be the default digital module slot.
 */
void Counter::SetUpSource(UINT32 channel)
{
	SetUpSource(GetDefaultDigitalModule(), channel);
	m_allocatedUpSource = true;
}

/**
 * Set the up counting source to be an analog trigger.
 * @param analogTrigger The analog trigger object that is used for the Up Source
 * @param triggerType The analog trigger output that will trigger the counter.
 */
void Counter::SetUpSource(AnalogTrigger *analogTrigger, AnalogTriggerOutput::Type triggerType)
{
	SetUpSource(analogTrigger->CreateOutput(triggerType));
	m_allocatedUpSource = true;
}

/**
 * Set the up counting source to be an analog trigger.
 * @param analogTrigger The analog trigger object that is used for the Up Source
 * @param triggerType The analog trigger output that will trigger the counter.
 */
void Counter::SetUpSource(AnalogTrigger &analogTrigger, AnalogTriggerOutput::Type triggerType)
{
	SetUpSource(&analogTrigger, triggerType);
}

/**
 * Set the source object that causes the counter to count up.
 * Set the up counting DigitalSource.
 */
void Counter::SetUpSource(DigitalSource *source)
{
	if (m_allocatedUpSource)
	{
		delete m_upSource;
		m_upSource = NULL;
		m_allocatedUpSource = false;
	}
	m_upSource = source;
	m_counter->writeConfig_UpSource_Module(source->GetModuleForRouting(), &status);
	m_counter->writeConfig_UpSource_Channel(source->GetChannelForRouting(), &status);
	m_counter->writeConfig_UpSource_AnalogTrigger(source->GetAnalogTriggerForRouting(), &status);

	if(m_counter->readConfig_Mode(&status) == kTwoPulse ||
			m_counter->readConfig_Mode(&status) == kExternalDirection)
	{
		SetUpSourceEdge(true, false);
	}
	m_counter->strobeReset(&status);
	wpi_assertCleanStatus(status);
}

/**
 * Set the source object that causes the counter to count up.
 * Set the up counting DigitalSource.
 */
void Counter::SetUpSource(DigitalSource &source)
{
	SetUpSource(&source);
}

/**
 * Set the edge sensitivity on an up counting source.
 * Set the up source to either detect rising edges or falling edges.
 */
void Counter::SetUpSourceEdge(bool risingEdge, bool fallingEdge)
{
	wpi_assert(m_upSource != NULL);
	m_counter->writeConfig_UpRisingEdge(risingEdge, &status);
	m_counter->writeConfig_UpFallingEdge(fallingEdge, &status);
}

/**
 * Disable the up counting source to the counter.
 */
void Counter::ClearUpSource()
{
	if (m_allocatedUpSource)
	{
		delete m_upSource;
		m_upSource = NULL;
		m_allocatedUpSource = false;
	}
	bool state = m_counter->readConfig_Enable(&status);
	m_counter->writeConfig_Enable(false, &status);
	m_counter->writeConfig_UpFallingEdge(false, &status);
	m_counter->writeConfig_UpRisingEdge(false, &status);
	// Index 0 of digital is always 0.
	m_counter->writeConfig_UpSource_Channel(0, &status);
	m_counter->writeConfig_UpSource_AnalogTrigger(false, &status);
	m_counter->writeConfig_Enable(state, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Set the down counting source to be a digital input channel.
 * The slot will be set to the default digital module slot.
 */
void Counter::SetDownSource(UINT32 channel)
{
	SetDownSource(new DigitalInput(channel));
	m_allocatedDownSource = true;
}

/**
 * Set the down counting source to be a digital input slot and channel.
 */
void Counter::SetDownSource(UINT32 slot, UINT32 channel)
{
	SetDownSource(new DigitalInput(slot, channel));
	m_allocatedDownSource = true;
}

/**
 * Set the down counting source to be an analog trigger.
 * @param analogTrigger The analog trigger object that is used for the Down Source
 * @param triggerType The analog trigger output that will trigger the counter.
 */
void Counter::SetDownSource(AnalogTrigger *analogTrigger, AnalogTriggerOutput::Type triggerType)
{
	SetDownSource(analogTrigger->CreateOutput(triggerType));
	m_allocatedDownSource = true;
}

/**
 * Set the down counting source to be an analog trigger.
 * @param analogTrigger The analog trigger object that is used for the Down Source
 * @param triggerType The analog trigger output that will trigger the counter.
 */
void Counter::SetDownSource(AnalogTrigger &analogTrigger, AnalogTriggerOutput::Type triggerType)
{
	SetDownSource(&analogTrigger, triggerType);
}

/**
 * Set the source object that causes the counter to count down.
 * Set the down counting DigitalSource.
 */
void Counter::SetDownSource(DigitalSource *source)
{
	if (m_allocatedDownSource)
	{
		delete m_downSource;
		m_downSource = NULL;
		m_allocatedDownSource = false;
	}
	unsigned char mode = m_counter->readConfig_Mode(&status);
	wpi_assert(mode == kTwoPulse || mode == kExternalDirection);
	m_downSource = source;
	m_counter->writeConfig_DownSource_Module(source->GetModuleForRouting(), &status);
	m_counter->writeConfig_DownSource_Channel(source->GetChannelForRouting(), &status);
	m_counter->writeConfig_DownSource_AnalogTrigger(source->GetAnalogTriggerForRouting(), &status);

	SetDownSourceEdge(true, false);
	m_counter->strobeReset(&status);
	wpi_assertCleanStatus(status);
}

/**
 * Set the source object that causes the counter to count down.
 * Set the down counting DigitalSource.
 */
void Counter::SetDownSource(DigitalSource &source)
{
	SetDownSource(&source);
}

/**
 * Set the edge sensitivity on a down counting source.
 * Set the down source to either detect rising edges or falling edges.
 */
void Counter::SetDownSourceEdge(bool risingEdge, bool fallingEdge)
{
	wpi_assert(m_downSource != NULL);
	m_counter->writeConfig_DownRisingEdge(risingEdge, &status);
	m_counter->writeConfig_DownFallingEdge(fallingEdge, &status);
}

/**
 * Disable the down counting source to the counter.
 */
void Counter::ClearDownSource()
{
	if (m_allocatedDownSource)
	{
		delete m_downSource;
		m_downSource = NULL;
		m_allocatedDownSource = false;
	}
	bool state = m_counter->readConfig_Enable(&status);
	m_counter->writeConfig_Enable(false, &status);
	m_counter->writeConfig_DownFallingEdge(false, &status);
	m_counter->writeConfig_DownRisingEdge(false, &status);
	// Index 0 of digital is always 0.
	m_counter->writeConfig_DownSource_Channel(0, &status);
	m_counter->writeConfig_DownSource_AnalogTrigger(false, &status);
	m_counter->writeConfig_Enable(state, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Set standard up / down counting mode on this counter.
 * Up and down counts are sourced independently from two inputs.
 */
void Counter::SetUpDownCounterMode()
{
	m_counter->writeConfig_Mode(kTwoPulse, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Set external direction mode on this counter.
 * Counts are sourced on the Up counter input.
 * The Down counter input represents the direction to count.
 */
void Counter::SetExternalDirectionMode()
{
	m_counter->writeConfig_Mode(kExternalDirection, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Set Semi-period mode on this counter.
 * Counts up on both rising and falling edges. 
 */
void Counter::SetSemiPeriodMode(bool highSemiPeriod)
{
	m_counter->writeConfig_Mode(kSemiperiod, &status);
	m_counter->writeConfig_UpRisingEdge(highSemiPeriod, &status);
	SetUpdateWhenEmpty(false);
	wpi_assertCleanStatus(status);
}

/**
 * Configure the counter to count in up or down based on the length of the input pulse.
 * This mode is most useful for direction sensitive gear tooth sensors.
 * @param threshold The pulse length beyond which the counter counts the opposite direction.  Units are seconds.
 */
void Counter::SetPulseLengthMode(float threshold)
{
	m_counter->writeConfig_Mode(kPulseLength, &status);
	m_counter->writeConfig_PulseLengthThreshold((UINT32)(threshold * 1.0e6) * kSystemClockTicksPerMicrosecond, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Start the Counter counting.
 * This enables the counter and it starts accumulating counts from the associated
 * input channel. The counter value is not reset on starting, and still has the previous value.
 */
void Counter::Start()
{
	m_counter->writeConfig_Enable(1, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Read the current counter value.
 * Read the value at this instant. It may still be running, so it reflects the current value. Next
 * time it is read, it might have a different value.
 */
INT32 Counter::Get()
{
	INT32 value = m_counter->readOutput_Value(&status);
	wpi_assertCleanStatus(status);
	return value;
}

/**
 * Reset the Counter to zero.
 * Set the counter value to zero. This doesn't effect the running state of the counter, just sets
 * the current value to zero.
 */
void Counter::Reset()
{
	m_counter->strobeReset(&status);
	wpi_assertCleanStatus(status);
}

/**
 * Stop the Counter.
 * Stops the counting but doesn't effect the current value.
 */
void Counter::Stop()
{
	m_counter->writeConfig_Enable(0, &status);
	wpi_assertCleanStatus(status);
}

/*
 * Get the Period of the most recent count.
 * Returns the time interval of the most recent count. This can be used for velocity calculations
 * to determine shaft speed.
 * @returns The period of the last two pulses in units of seconds.
 */
double Counter::GetPeriod()
{
	tCounter::tTimerOutput output = m_counter->readTimerOutput(&status);
	double period;
	if (output.Stalled)
	{
		// Return infinity
		double zero = 0.0;
		period = 1.0 / zero;
	}
	else
	{
		// output.Period is a fixed point number that counts by 2 (24 bits, 25 integer bits)
		period = (double)(output.Period << 1) / (double)output.Count;
	}
	wpi_assertCleanStatus(status);
	return period * 1.0e-6;
}

/**
 * Set the maximum period where the device is still considered "moving".
 * Sets the maximum period where the device is considered moving. This value is used to determine
 * the "stopped" state of the counter using the GetStopped method.
 * @param maxPeriod The maximum period where the counted device is considered moving in
 * seconds.
 */
void Counter::SetMaxPeriod(double maxPeriod)
{
	m_counter->writeTimerConfig_StallPeriod((UINT32)(maxPeriod * 1.0e6), &status);
}

/**
 * Select whether you want to continue updating the event timer output when there are no samples captured.
 * The output of the event timer has a buffer of periods that are averaged and posted to
 * a register on the FPGA.  When the timer detects that the event source has stopped
 * (based on the MaxPeriod) the buffer of samples to be averaged is emptied.  If you
 * enable the update when empty, you will be notified of the stopped source and the event
 * time will report 0 samples.  If you disable update when empty, the most recent average
 * will remain on the output until a new sample is acquired.  You will never see 0 samples
 * output (except when there have been no events since an FPGA reset) and you will likely not
 * see the stopped bit become true (since it is updated at the end of an average and there are
 * no samples to average).
 */
void Counter::SetUpdateWhenEmpty(bool enabled)
{
	m_counter->writeTimerConfig_UpdateWhenEmpty(enabled, &status);
}

/**
 * Determine if the clock is stopped.
 * Determine if the clocked input is stopped based on the MaxPeriod value set using the
 * SetMaxPeriod method. If the clock exceeds the MaxPeriod, then the device (and counter) are
 * assumed to be stopped and it returns true.
 * @return Returns true if the most recent counter period exceeds the MaxPeriod value set by
 * SetMaxPeriod.
 */
bool Counter::GetStopped()
{
	return m_counter->readTimerOutput_Stalled(&status);
}

/**
 * The last direction the counter value changed.
 * @return The last direction the counter value changed.
 */
bool Counter::GetDirection()
{
	bool value = m_counter->readOutput_Direction(&status);
	wpi_assertCleanStatus(status);
	return value;
}

/**
 * Set the Counter to return reversed sensing on the direction.
 * This allows counters to change the direction they are counting in the case of 1X and 2X
 * quadrature encoding only. Any other counter mode isn't supported.
 * @param reverseDirection true if the value counted should be negated.
 */
void Counter::SetReverseDirection(bool reverseDirection)
{
	if (m_counter->readConfig_Mode(&status) == kExternalDirection)
	{
		if (reverseDirection)
			SetDownSourceEdge(true, true);
		else
			SetDownSourceEdge(false, true);
	}
}
