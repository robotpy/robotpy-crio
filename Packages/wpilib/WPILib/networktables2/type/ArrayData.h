/*
 * ArrayData.h
 *
 *  Created on: Nov 14, 2012
 *      Author: Mitchell Wills
 */

#ifndef ARRAYDATA_H_
#define ARRAYDATA_H_

class ArrayData;

#include "ArrayEntryType.h"
#include "ComplexData.h"
#include "networktables2/NetworkTableEntry.h"

/**
 *
 * @author Mitchell
 */
class ArrayData : public ComplexData{
private:
    ArrayEntryType& m_data_type;
    unsigned int m_size;
    EntryValue* data;
public:
    ArrayData(ArrayEntryType& type);
    
protected:
    EntryValue _get(unsigned int index);
    void _set(unsigned int index, EntryValue value);
    void _add(EntryValue value);
    
public:
    void remove(unsigned int index);
    void setSize(unsigned int size);
    unsigned int size();

    friend class ArrayEntryType;
};



#endif /* ARRAYDATA_H_ */
