/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef SYNCHRONIZED_H
#define SYNCHRONIZED_H

#include "semLib.h"

#define CRITICAL_REGION(s) { Synchronized _sync(s);
#define END_REGION }

/**
 * Provide easy support for critical regions.
 * A critical region is an area of code that is always executed under mutual exclusion. Only
 * one task can be executing this code at any time. The idea is that code that manipulates data
 * that is shared between two or more tasks has to be prevented from executing at the same time
 * otherwise a race condition is possible when both tasks try to update the data. Typically
 * semaphores are used to ensure only single task access to the data.
 * Synchronized objects are a simple wrapper around semaphores to help ensure that semaphores
 * are always signaled (semGive) after a wait (semTake).
 */
class Synchronized
{
public:
	explicit Synchronized(SEM_ID);
	virtual ~Synchronized();
private:
	SEM_ID m_semaphore;
};

#endif
