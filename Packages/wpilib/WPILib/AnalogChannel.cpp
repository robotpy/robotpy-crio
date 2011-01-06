/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "AnalogChannel.h"
#include "AnalogModule.h"
#include "Resource.h"
#include "Utility.h"
#include "WPIStatus.h"

static Resource *channels = NULL;

const UINT32 AnalogChannel::kAccumulatorSlot;
const UINT32 AnalogChannel::kAccumulatorNumChannels;
const UINT32 AnalogChannel::kAccumulatorChannels[] = {1, 2};

/**
 * Common initialization.
 */
void AnalogChannel::InitChannel(UINT32 slot, UINT32 channel)
{
	Resource::CreateResourceObject(&channels, kAnalogModules * kAnalogChannels);
	CheckAnalogModule(slot);
	CheckAnalogChannel(slot);
	channels->Allocate(AnalogModule::SlotToIndex(slot) * kAnalogModules + channel - 1);
	m_channel = channel;
	m_module = AnalogModule::GetInstance(slot);
	if (IsAccumulatorChannel())
	{
		m_accumulator = new tAccumulator(channel - 1, &status);
		m_accumulatorOffset=0;
	}
	else
	{
		m_accumulator = NULL;
	}
}

/**
 * Construct an analog channel on a specified module.
 * 
 * @param slot The slot that the analog module is plugged into.
 * @param channel The channel number to represent.
 */
AnalogChannel::AnalogChannel(UINT32 slot, UINT32 channel)
{
	InitChannel(slot, channel);
}

/**
 * Construct an analog channel on the default module.
 * 
 * @param channel The channel number to represent.
 */
AnalogChannel::AnalogChannel(UINT32 channel)
{
	InitChannel(GetDefaultAnalogModule(), channel);
}

/**
 * Channel destructor.
 */
AnalogChannel::~AnalogChannel()
{
	channels->Free(AnalogModule::SlotToIndex(GetSlot()) * kAnalogModules + m_channel - 1);
}

/**
 * Get the analog module that this channel is on.
 * @return A pointer to the AnalogModule that this channel is on.
 */
AnalogModule *AnalogChannel::GetModule()
{
	return m_module;
}

/**
 * Get a sample straight from this channel on the module.
 * The sample is a 12-bit value representing the -10V to 10V range of the A/D converter in the module.
 * The units are in A/D converter codes.  Use GetVoltage() to get the analog value in calibrated units.
 * @return A sample straight from this channel on the module.
 */
INT16 AnalogChannel::GetValue()
{
	return m_module->GetValue(m_channel);
}

/**
 * Get a sample from the output of the oversample and average engine for this channel.
 * The sample is 12-bit + the value configured in SetOversampleBits().
 * The value configured in SetAverageBits() will cause this value to be averaged 2**bits number of samples.
 * This is not a sliding window.  The sample will not change until 2**(OversamplBits + AverageBits) samples
 * have been acquired from the module on this channel.
 * Use GetAverageVoltage() to get the analog value in calibrated units.
 * @return A sample from the oversample and average engine for this channel.
 */
INT32 AnalogChannel::GetAverageValue()
{
	return m_module->GetAverageValue(m_channel);
}

/**
 * Get a scaled sample straight from this channel on the module.
 * The value is scaled to units of Volts using the calibrated scaling data from GetLSBWeight() and GetOffset().
 * @return A scaled sample straight from this channel on the module.
 */
float AnalogChannel::GetVoltage()
{
	return m_module->GetVoltage(m_channel);
}

/**
 * Get a scaled sample from the output of the oversample and average engine for this channel.
 * The value is scaled to units of Volts using the calibrated scaling data from GetLSBWeight() and GetOffset().
 * Using oversampling will cause this value to be higher resolution, but it will update more slowly.
 * Using averaging will cause this value to be more stable, but it will update more slowly.
 * @return A scaled sample from the output of the oversample and average engine for this channel.
 */
float AnalogChannel::GetAverageVoltage()
{
	return m_module->GetAverageVoltage(m_channel);
}

/**
 * Get the factory scaling least significant bit weight constant.
 * The least significant bit weight constant for the channel that was calibrated in
 * manufacturing and stored in an eeprom in the module.
 * 
 * Volts = ((LSB_Weight * 1e-9) * raw) - (Offset * 1e-9)
 * 
 * @return Least significant bit weight.
 */
UINT32 AnalogChannel::GetLSBWeight()
{
	return m_module->GetLSBWeight(m_channel);
}

/**
 * Get the factory scaling offset constant.
 * The offset constant for the channel that was calibrated in manufacturing and stored
 * in an eeprom in the module.
 * 
 * Volts = ((LSB_Weight * 1e-9) * raw) - (Offset * 1e-9)
 * 
 * @return Offset constant.
 */
INT32 AnalogChannel::GetOffset()
{
	return m_module->GetOffset(m_channel);
}

/**
 * Get the channel number.
 * @return The channel number.
 */
UINT32 AnalogChannel::GetChannel()
{
	return m_channel;
}

/**
 * Get the slot that the analog module is plugged into.
 * @return The slot that the analog module is plugged into.
 */
UINT32 AnalogChannel::GetSlot()
{
	return m_module->GetSlot();
}

/**
 * Set the number of averaging bits.
 * This sets the number of averaging bits. The actual number of averaged samples is 2**bits.
 * Use averaging to improve the stability of your measurement at the expense of sampling rate.
 * The averaging is done automatically in the FPGA.
 * 
 * @param bits Number of bits of averaging.
 */
void AnalogChannel::SetAverageBits(UINT32 bits)
{
	m_module->SetAverageBits(m_channel, bits);
}

/**
 * Get the number of averaging bits previously configured.
 * This gets the number of averaging bits from the FPGA. The actual number of averaged samples is 2**bits.
 * The averaging is done automatically in the FPGA.
 * 
 * @return Number of bits of averaging previously configured.
 */
UINT32 AnalogChannel::GetAverageBits()
{
	return m_module->GetAverageBits(m_channel);
}

/**
 * Set the number of oversample bits.
 * This sets the number of oversample bits. The actual number of oversampled values is 2**bits.
 * Use oversampling to improve the resolution of your measurements at the expense of sampling rate.
 * The oversampling is done automatically in the FPGA.
 * 
 * @param bits Number of bits of oversampling.
 */
void AnalogChannel::SetOversampleBits(UINT32 bits)
{
	m_module->SetOversampleBits(m_channel, bits);
}

/**
 * Get the number of oversample bits previously configured.
 * This gets the number of oversample bits from the FPGA. The actual number of oversampled values is
 * 2**bits. The oversampling is done automatically in the FPGA.
 * 
 * @return Number of bits of oversampling previously configured.
 */
UINT32 AnalogChannel::GetOversampleBits()
{
	return m_module->GetOversampleBits(m_channel);
}

/**
 * Is the channel attached to an accumulator.
 * 
 * @return The analog channel is attached to an accumulator.
 */
bool AnalogChannel::IsAccumulatorChannel()
{
	if(m_module->GetSlot() != kAccumulatorSlot) return false;
	for (UINT32 i=0; i<kAccumulatorNumChannels; i++)
	{
		if (m_channel == kAccumulatorChannels[i]) return true;
	}
	return false;
}

/**
 * Initialize the accumulator.
 */
void AnalogChannel::InitAccumulator()
{
	m_accumulatorOffset = 0;
	SetAccumulatorCenter(0);
	ResetAccumulator();
}


/**
 * Set an inital value for the accumulator.
 * 
 * This will be added to all values returned to the user.
 * @param initialValue The value that the accumulator should start from when reset.
 */
void AnalogChannel::SetAccumulatorInitialValue(INT64 initialValue)
{
	m_accumulatorOffset = initialValue;
}

/**
 * Resets the accumulator to the initial value.
 */
void AnalogChannel::ResetAccumulator()
{
	if (m_accumulator == NULL)
	{
		wpi_fatal(NullParameter);
		return;
	}
	m_accumulator->strobeReset(&status);
	wpi_assertCleanStatus(status);
}

/**
 * Set the center value of the accumulator.
 * 
 * The center value is subtracted from each A/D value before it is added to the accumulator. This
 * is used for the center value of devices like gyros and accelerometers to make integration work
 * and to take the device offset into account when integrating.
 * 
 * This center value is based on the output of the oversampled and averaged source from channel 1.
 * Because of this, any non-zero oversample bits will affect the size of the value for this field.
 */
void AnalogChannel::SetAccumulatorCenter(INT32 center)
{
	if (m_accumulator == NULL)
	{
		wpi_fatal(NullParameter);
		return;
	}
	m_accumulator->writeCenter(center, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Set the accumulator's deadband.
 */
void AnalogChannel::SetAccumulatorDeadband(INT32 deadband)
{
	if (m_accumulator == NULL)
	{
		wpi_fatal(NullParameter);
		return;
	}
	m_accumulator->writeDeadband(deadband, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Read the accumulated value.
 * 
 * Read the value that has been accumulating on channel 1.
 * The accumulator is attached after the oversample and average engine.
 * 
 * @return The 64-bit value accumulated since the last Reset().
 */
INT64 AnalogChannel::GetAccumulatorValue()
{
	if (m_accumulator == NULL)
	{
		wpi_fatal(NullParameter);
		return 0;
	}
	INT64 value = m_accumulator->readOutput_Value(&status) + m_accumulatorOffset;
	wpi_assertCleanStatus(status);
	return value;
}

/**
 * Read the number of accumulated values.
 * 
 * Read the count of the accumulated values since the accumulator was last Reset().
 * 
 * @return The number of times samples from the channel were accumulated.
 */
UINT32 AnalogChannel::GetAccumulatorCount()
{
	status = 0;
	if (m_accumulator == NULL)
	{
		wpi_fatal(NullParameter);
		return 0;
	}
	UINT32 count = m_accumulator->readOutput_Count(&status);
	wpi_assertCleanStatus(status);
	return count;
}


/**
 * Read the accumulated value and the number of accumulated values atomically.
 * 
 * This function reads the value and count from the FPGA atomically.
 * This can be used for averaging.
 * 
 * @param value Pointer to the 64-bit accumulated output.
 * @param count Pointer to the number of accumulation cycles.
 */
void AnalogChannel::GetAccumulatorOutput(INT64 *value, UINT32 *count)
{
	status = 0;
	if (m_accumulator == NULL)
	{
		wpi_fatal(NullParameter);
		return;
	}
	if (value == NULL || count == NULL)
	{
		wpi_fatal(NullParameter);
		return;
	}

	tAccumulator::tOutput output = m_accumulator->readOutput(&status);
	*value = output.Value + m_accumulatorOffset;
	*count = output.Count;
	wpi_assertCleanStatus(status);
}

/**
 * Get the Average voltage for the PID Source base object.
 * 
 * @return The average voltage.
 */
double AnalogChannel::PIDGet() 
{
	return GetAverageValue();
}
