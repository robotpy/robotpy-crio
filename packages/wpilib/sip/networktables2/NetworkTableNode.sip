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

class NetworkTableNode : TableListenerManager, ClientConnectionListenerManager, IRemote
{
%TypeHeaderCode
#include <WPILib/networktables2/NetworkTableNode.h>
%End
public:

protected:
	NetworkTableNode(AbstractNetworkTableEntryStore& entryStore);
	
public:
	AbstractNetworkTableEntryStore& GetEntryStore();
	virtual ~NetworkTableNode();
	
	void PutBoolean(std::string& name, bool value);
	bool GetBoolean(std::string& name);

	void PutDouble(std::string& name, double value);
	double GetDouble(std::string& name);

	void PutString(std::string& name, std::string& value);
	std::string& GetString(std::string& name);
        
	void PutComplex(std::string& name, ComplexData& value);
        
	void retrieveValue(std::string& name, ComplexData& externalData);
	//void PutValue(std::string& name, NetworkTableEntryType* type, EntryValue value);
	//void PutValue(NetworkTableEntry* entry, EntryValue value);
	//EntryValue GetValue(std::string& name);
	
	bool ContainsKey(std::string& key);

	virtual void Close() = 0;
};
