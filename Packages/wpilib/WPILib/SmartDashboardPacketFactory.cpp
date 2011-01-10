/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "SmartDashboardPacketFactory.h"
#include "SmartDashboard.h"
#include <strLib.h>

/** Announces a field to the client. */
void SmartDashboardPacketFactory::Announce(SmartDashboard::Buffer& buf, char id,
		SmartDashboard::FIELD_TYPE type, const char* name) {
	buf.WriteByte(ANNOUNCE_FRAME);
	buf.WriteByte(id);
	buf.WriteByte(type);
	buf.WriteUTF(name);
}

/** Returns the length (in chars) required to announce a particular field. */
int SmartDashboardPacketFactory::GetAnnounceLength(const char* name) {
	return 5 + SmartDashboard::Buffer::Utf8Length(name);
}

/** Indicates that the data follows for the field with the given ID. */
void SmartDashboardPacketFactory::UpdatePrefix(SmartDashboard::Buffer& buf,
		char id, int dataLength) {
	buf.WriteByte(UPDATE_FRAME);
	buf.WriteByte(id);
	buf.WriteByte(dataLength);
}

/** Returns the length (in chars) required to update a particular field. */
int SmartDashboardPacketFactory::GetUpdateLength(int dataLength) {
	return 3 + dataLength;
}
