/*
 * ArrayEntryType.h
 *
 *  Created on: Nov 14, 2012
 *      Author: Mitchell Wills
 */

#ifndef ARRAYENTRYTYPE_H_
#define ARRAYENTRYTYPE_H_

#include <stdlib.h>
#include <stdio.h>
#ifndef _WRS_KERNEL
#include <stdint.h>
#endif

class ArrayEntryType;

#include "ArrayData.h"
#include "ComplexEntryType.h"

struct ArrayEntryData{
	uint8_t length;
	EntryValue* array;
};
typedef struct ArrayEntryData ArrayEntryData;

/**
 *
 * @author Mitchell
 */
class ArrayEntryType : public ComplexEntryType {//TODO allow for array of complex type
private:
    NetworkTableEntryType& m_elementType;
    
public:
    ArrayEntryType(TypeId id, NetworkTableEntryType& elementType);

	EntryValue copyElement(EntryValue value);
	void deleteElement(EntryValue value);
    
	void sendValue(EntryValue value, DataIOStream& os);

	EntryValue readValue(DataIOStream& is);
    
	EntryValue copyValue(EntryValue value);
	void deleteValue(EntryValue value);

	EntryValue internalizeValue(std::string& key, ComplexData& externalRepresentation, EntryValue currentInteralValue);

	void exportValue(std::string& key, EntryValue internalData, ComplexData& externalRepresentation);
    
    
    
};

#endif /* ARRAYENTRYTYPE_H_ */
