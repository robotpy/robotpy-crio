/*
 * NetworkTableEntryTypeManager.h
 *
 *  Created on: Sep 16, 2012
 *      Author: Mitchell Wills
 */

#ifndef NETWORKTABLEENTRYTYPEMANAGER_H_
#define NETWORKTABLEENTRYTYPEMANAGER_H_

class NetworkTableEntryTypeManager;

#include "NetworkTableEntryType.h"

class NetworkTableEntryTypeManager
{
private:
	NetworkTableEntryType* entryTypes[MAX_NUM_TABLE_ENTRY_TYPES];
public:
	NetworkTableEntryTypeManager();
	NetworkTableEntryType* GetType(TypeId type);
	void RegisterType(NetworkTableEntryType& type);
};

#endif /* NETWORKTABLEENTRYTYPEMANAGER_H_ */
