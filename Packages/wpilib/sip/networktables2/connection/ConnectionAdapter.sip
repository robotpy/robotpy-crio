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

class ConnectionAdapter /Abstract/
{
%TypeHeaderCode
#include <WPILib/networktables2/connection/ConnectionAdapter.h>
%End
public:
	virtual ~ConnectionAdapter();
	virtual bool keepAlive() = 0;
	virtual void clientHello(ProtocolVersion protocolRevision) = 0;
	virtual void serverHelloComplete() = 0;
	virtual void protocolVersionUnsupported(ProtocolVersion protocolRevision) = 0;
	virtual void offerIncomingAssignment(NetworkTableEntry* newEntry) = 0;
	//virtual void offerIncomingUpdate(NetworkTableEntry* newEntry, SequenceNumber sequenceNumber, EntryValue value) = 0;
	virtual NetworkTableEntry* GetEntry(EntryId) = 0;

	//virtual void badMessage(BadMessageException& e) = 0;
	//virtual void ioException(IOException& e) = 0;
};
