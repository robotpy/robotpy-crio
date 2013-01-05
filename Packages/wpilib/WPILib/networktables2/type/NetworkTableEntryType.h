/*
 * NetworkTableEntryType.h
 *
 *  Created on: Sep 16, 2012
 *      Author: Mitchell Wills
 */

#ifndef NETWORKTABLEENTRYTYPE_H_
#define NETWORKTABLEENTRYTYPE_H_

#include <stdlib.h>
#include <stdio.h>
#ifndef _WRS_KERNEL
#include <stdint.h>
#endif

typedef uint8_t TypeId;
class NetworkTableEntryType;

#define MAX_NUM_TABLE_ENTRY_TYPES 256

#include <string>
#include "networktables2/connection/DataIOStream.h"
#include "networktables2/NetworkTableEntry.h"
#include "tables/ITable.h"


class NetworkTableEntryType{
public:
	const TypeId id;
	const char* name;
	virtual bool isComplex();
	virtual void sendValue(EntryValue value, DataIOStream& os) = 0;
	virtual EntryValue readValue(DataIOStream& is) = 0;
	virtual EntryValue copyValue(EntryValue value);
	virtual void deleteValue(EntryValue value);
	virtual ~NetworkTableEntryType();
protected:
	NetworkTableEntryType(TypeId id, const char* name);
};

#endif /* NETWORKTABLEENTRYTYPE_H_ */
