/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef SOLENOID_BASE_H_
#define SOLENOID_BASE_H_

#include "Resource.h"
#include "SensorBase.h"
#include "ChipObject.h"

/**
 * SolenoidBase class is the common base class for the Solenoid and
 * DoubleSolenoid classes.
 */
class SolenoidBase : public SensorBase {
public:
	virtual ~SolenoidBase();
	UINT8 GetAll();

protected:
	explicit SolenoidBase(UINT32 slot);
	UINT32 SlotToIndex(UINT32 slot);
	void Set(UINT8 value, UINT8 mask);
	virtual void InitSolenoid() = 0;

	UINT32 m_chassisSlot; ///< Slot number where the module is plugged into the chassis.
	static Resource *m_allocated;

private:
	static tSolenoid *m_fpgaSolenoidModule; ///< FPGA Solenoid Module object.
	static UINT32 m_refCount; ///< Reference count for the chip object.
	static SEM_ID m_semaphore;
};

#endif
