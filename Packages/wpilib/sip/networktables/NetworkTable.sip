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

class NetworkTableKeyCache : StringCache
{
%TypeHeaderCode
#include <WPILib/networktables/NetworkTable.h>
%End

public: 
	NetworkTableKeyCache(std::string path);
	~NetworkTableKeyCache();

	std::string Calc(const std::string& key);
};

class EntryCache
{
%TypeHeaderCode
#include <WPILib/networktables/NetworkTable.h>
%End

public:
	EntryCache(std::string& path);
	~EntryCache();
	
	NetworkTableEntry* Get(std::string& key);
};

class NetworkTable : ITable, IRemote
{
%TypeHeaderCode
#include <WPILib/networktables/NetworkTable.h>
%End

public:
	static void Initialize();
	static void SetServerMode();
	static void SetTableProvider(NetworkTableProvider* provider);
	static void SetClientMode();

	static void SetTeam(int team);
	static void SetIPAddress(const char* address);
	static NetworkTable* GetTable(std::string key);

	NetworkTable(std::string path, NetworkTableProvider& provider);
	virtual ~NetworkTable();
	
	bool IsConnected();

	bool IsServer();
	
	void AddConnectionListener(IRemoteConnectionListener* listener, bool immediateNotify);
	void RemoveConnectionListener(IRemoteConnectionListener* listener);

	void AddTableListener(ITableListener* listener);
	void AddTableListener(ITableListener* listener, bool immediateNotify);
	void AddTableListener(std::string key, ITableListener* listener, bool immediateNotify);
	void AddSubTableListener(ITableListener* listener);

	void RemoveTableListener(ITableListener* listener);

	virtual NetworkTable* GetSubTable(std::string key);
	bool ContainsKey(std::string key);
	bool ContainsSubTable(std::string key);

	void PutNumber(std::string key, double value);
	double GetNumber(std::string key) throw(TableKeyNotDefinedException);
	double GetNumber(std::string key, double defaultValue);

	void PutString(std::string key, std::string value);
	std::string GetString(std::string key) throw(TableKeyNotDefinedException);
	std::string GetString(std::string key, std::string defaultValue);

	void PutBoolean(std::string key, bool value);
	bool GetBoolean(std::string key) throw(TableKeyNotDefinedException);
	bool GetBoolean(std::string key, bool defaultValue);

	//void PutValue(std::string key, NetworkTableEntryType* type, EntryValue value);
	//void RetrieveValue(std::string key, ComplexData& externalValue /Out/);
	void PutValue(std::string key, ComplexData& value);
	//EntryValue GetValue(std::string key) throw(TableKeyNotDefinedException);
	//EntryValue GetValue(std::string key, EntryValue defaultValue);

private:
	NetworkTable(const NetworkTable&);
};
