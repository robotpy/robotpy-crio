/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Module.h"

Module* Module::m_modules[kChassisSlots + 1] = {NULL};

/**
 * Constructor.
 * 
 * @param slot The slot in the chassis where the module is plugged in.
 */
Module::Module(UINT32 slot)
	: m_slot (slot)
{
}

/**
 * Destructor.
 */
Module::~Module()
{
}
