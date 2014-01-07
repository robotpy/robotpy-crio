// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2013 Peter Johnson
// 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

class ArrayEntryType : ComplexEntryType
{
%TypeHeaderCode
#include <WPILib/networktables2/type/ArrayEntryType.h>
%End
public:
    ArrayEntryType(TypeId id, NetworkTableEntryType& elementType);

	//EntryValue copyElement(EntryValue value);
	//void deleteElement(EntryValue value);
    //void areElementsEqual(EntryValue v1, EntryValue v2);
    
	//void sendValue(EntryValue value, DataIOStream& os);

	//EntryValue readValue(DataIOStream& is);
    
	//EntryValue copyValue(EntryValue value);
	//void deleteValue(EntryValue value);
	//bool areEqual(EntryValue v1, EntryValue v2);

	//EntryValue internalizeValue(std::string& key, ComplexData& externalRepresentation, EntryValue currentInteralValue);

	//void exportValue(std::string& key, EntryValue internalData, ComplexData& externalRepresentation);
};
