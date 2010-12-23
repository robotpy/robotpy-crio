/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "InterruptableSensorBase.h"
#include "Utility.h"

InterruptableSensorBase::InterruptableSensorBase()
{
	m_manager = NULL;
	m_interrupt = NULL;
}

InterruptableSensorBase::~InterruptableSensorBase()
{

}

void InterruptableSensorBase::AllocateInterrupts(bool watcher)
{
	wpi_assert(m_interrupt == NULL);
	wpi_assert(m_manager == NULL);
	// Expects the calling leaf class to allocate an interrupt index.
	m_interrupt = new tInterrupt(m_interruptIndex, &status);
	m_interrupt->writeConfig_WaitForAck(false, &status);
	m_manager = new tInterruptManager(1 << m_interruptIndex, watcher, &status);
}

/**
 * Cancel interrupts on this device.
 * This deallocates all the chipobject structures and disables any interrupts.
 */
void InterruptableSensorBase::CancelInterrupts()
{
	wpi_assert(m_manager != NULL);
	wpi_assert(m_interrupt != NULL);
	delete m_interrupt;
	delete m_manager;
	m_interrupt = NULL;
	m_manager = NULL;
}

/**
 * In synchronous mode, wait for the defined interrupt to occur.
 * @param timeout Timeout in seconds
 */
void InterruptableSensorBase::WaitForInterrupt(float timeout)
{
	wpi_assert(m_manager != NULL);
	wpi_assert(m_interrupt != NULL);
	m_manager->watch((INT32)(timeout * 1e3), &status);
	wpi_assertCleanStatus(status);
}

/**
 * Enable interrupts to occur on this input.
 * Interrupts are disabled when the RequestInterrupt call is made. This gives time to do the
 * setup of the other options before starting to field interrupts.
 */
void InterruptableSensorBase::EnableInterrupts()
{
	wpi_assert(m_manager != NULL);
	wpi_assert(m_interrupt != NULL);
	m_manager->enable(&status);
	wpi_assertCleanStatus(status);
}

/**
 * Disable Interrupts without without deallocating structures.
 */
void InterruptableSensorBase::DisableInterrupts()
{
	wpi_assert(m_manager != NULL);
	wpi_assert(m_interrupt != NULL);
	m_manager->disable(&status);
	wpi_assertCleanStatus(status);
}

/**
 * Return the timestamp for the interrupt that occurred most recently.
 * This is in the same time domain as GetClock().
 * @return Timestamp in seconds since boot.
 */
double InterruptableSensorBase::ReadInterruptTimestamp()
{
	wpi_assert(m_interrupt != NULL);
	return m_interrupt->readTimeStamp(&status) * 1e-6;
}
