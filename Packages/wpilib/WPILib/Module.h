/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef MODULE_H_
#define MODULE_H_

#include "SensorBase.h"

class Module: public SensorBase
{
public:
	UINT32 GetSlot() {return m_slot;}

protected:
	explicit Module(UINT32 slot);
	virtual ~Module();

	UINT32 m_slot; ///< Slot number where the module is plugged into the chassis.

	// Slots are 1 based, so ignore element 0.
	static Module* m_modules[kChassisSlots + 1];
};

#endif
