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

class TableListenerManager /Abstract/
{
%TypeHeaderCode
#include <WPILib/networktables2/AbstractNetworkTableEntryStore.h>
%End
public:
	virtual ~TableListenerManager();
	//virtual void FireTableListeners(std::string& name, EntryValue value, bool isNew) = 0;
};

class AbstractNetworkTableEntryStore : IncomingEntryReceiver /Abstract/
{
%TypeHeaderCode
#include <WPILib/networktables2/AbstractNetworkTableEntryStore.h>
%End
protected:
	AbstractNetworkTableEntryStore(TableListenerManager& lstnManager);

	virtual bool addEntry(NetworkTableEntry* entry) = 0;
	//virtual bool updateEntry(NetworkTableEntry* entry, SequenceNumber sequenceNumber, EntryValue value) = 0;
	
public:
	virtual ~AbstractNetworkTableEntryStore();

	NetworkTableEntry* GetEntry(EntryId entryId);
	NetworkTableEntry* GetEntry(std::string& name);

	//std::vector<std::string>* keys();
	void clearEntries();
	void clearIds();

	void SetOutgoingReceiver(OutgoingEntryReceiver* receiver);
	void SetIncomingReceiver(OutgoingEntryReceiver* receiver);
	
	//void PutOutgoing(std::string& name, NetworkTableEntryType* type, EntryValue value);
	//void PutOutgoing(NetworkTableEntry* tableEntry, EntryValue value);

	void offerIncomingAssignment(NetworkTableEntry* entry);
	//void offerIncomingUpdate(NetworkTableEntry* entry, EntryId sequenceNumber, EntryValue value);
	
	void notifyEntries(ITable* table, ITableListener* listener);
};
