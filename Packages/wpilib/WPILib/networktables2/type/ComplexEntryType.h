/*
 * ComplexEntryType.h
 *
 *  Created on: Sep 24, 2012
 *      Author: Mitchell Wills
 */

#ifndef COMPLEXENTRYTYPE_H_
#define COMPLEXENTRYTYPE_H_

class ComplexEntryType;

#include "networktables2/type/NetworkTableEntryType.h"

class ComplexEntryType : public NetworkTableEntryType
{
protected:
	ComplexEntryType(TypeId id, const char* name);
public:
	virtual ~ComplexEntryType()
	{
	}
	virtual bool isComplex();
	virtual EntryValue internalizeValue(std::string& key, ComplexData& externalRepresentation, EntryValue currentInteralValue) = 0;
	virtual void exportValue(std::string& key, EntryValue internalData, ComplexData& externalRepresentation) = 0;
};

#endif /* COMPLEXENTRYTYPE_H_ */
