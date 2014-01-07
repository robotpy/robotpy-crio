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

class Preferences : ErrorBase, ITableListener
{
%TypeHeaderCode
#include <WPILib/Preferences.h>
%End

public:
	static Preferences *GetInstance();

	//std::vector<std::string> GetKeys();
	std::string GetString(const char *key, const char *defaultValue = "");
	int GetString(const char *key, char *value, int valueSize, const char *defaultValue = "");
	int GetInt(const char *key, int defaultValue = 0);
	double GetDouble(const char *key, double defaultValue = 0.0);
	float GetFloat(const char *key, float defaultValue = 0.0);
	bool GetBoolean(const char *key, bool defaultValue = false);
	int64_t GetLong(const char *key, int64_t defaultValue = 0);
	void PutString(const char *key, const char *value);
	void PutInt(const char *key, int value);
	void PutDouble(const char *key, double value);
	void PutFloat(const char *key, float value);
	void PutBoolean(const char *key, bool value);
	void PutLong(const char *key, int64_t value);
	void Save();
	bool ContainsKey(const char *key);
	void Remove(const char *key);
	
	void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);

protected:
	Preferences();
	virtual ~Preferences();
};
