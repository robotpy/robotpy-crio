/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef _SMARTDASHBOARDPACKETFACTORY_H_
#define _SMARTDASHBOARDPACKETFACTORY_H_

#include "SmartDashboard.h"

class SmartDashboardPacketFactory {
public:
	// These protocol values must match the SmartDashboard client receiver.
	enum FRAME_TYPE {
		ANNOUNCE_FRAME = 0, UPDATE_FRAME = 1, ANNOUNCE_PROFILE_FRAME = 2,
	};

	static void Announce(SmartDashboard::Buffer& buf, char id,
			SmartDashboard::FIELD_TYPE type, const char* name);
	static int GetAnnounceLength(const char* name);
	static void UpdatePrefix(SmartDashboard::Buffer& buf, char id,
			int dataLength);
	static int GetUpdateLength(int dataLength);

private:
	DISALLOW_COPY_AND_ASSIGN(SmartDashboardPacketFactory);
};

#endif
