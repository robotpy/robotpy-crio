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

typedef unsigned short EntryId;
typedef unsigned short SequenceNumber;

class NetworkTableEntry
{
%TypeHeaderCode
#include <WPILib/networktables2/NetworkTableEntry.h>
%End
public:
	//NetworkTableEntry(std::string& name, NetworkTableEntryType* type, EntryValue value);
	//NetworkTableEntry(EntryId id, std::string& name, SequenceNumber sequenceNumber, NetworkTableEntryType* type, EntryValue value);
	virtual ~NetworkTableEntry();

	EntryId GetId();
	//EntryValue GetValue();
	NetworkTableEntryType* GetType();
	//bool PutValue(SequenceNumber newSequenceNumber, EntryValue newValue);
	//void ForcePut(SequenceNumber newSequenceNumber, EntryValue newValue);
	//void ForcePut(SequenceNumber newSequenceNumber, NetworkTableEntryType* type, EntryValue newValue);
	void MakeDirty();
	void MakeClean();
	bool IsDirty();
	void SendValue(DataIOStream& iostream);
	SequenceNumber GetSequenceNumber();
	void SetId(EntryId id);
	void ClearId();
	void Send(NetworkTableConnection& connection);
	void FireListener(TableListenerManager& listenerManager);
private:
	NetworkTableEntry();
	NetworkTableEntry(const NetworkTableEntry&);
};
