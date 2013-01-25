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

class SmartDashboard : SensorBase
{
%TypeHeaderCode
#include <WPILib/SmartDashboard/SmartDashboard.h>
%End

public:
	static void init();
	
	static void PutData(std::string key, Sendable *data);
	static void PutData(NamedSendable *value);
	//static Sendable* GetData(std::string keyName) throw(TableKeyNotDefinedException);
	
	static void PutBoolean(std::string keyName, bool value);
	static bool GetBoolean(std::string keyName) throw(TableKeyNotDefinedException);
	
	static void PutNumber(std::string keyName, double value);
	static double GetNumber(std::string keyName) throw(TableKeyNotDefinedException);
	
	static void PutString(std::string keyName, std::string value);
	//static int GetString(std::string keyName, char *value, unsigned int valueLen);
	static std::string GetString(std::string keyName) throw(TableKeyNotDefinedException);
	
	static void PutValue(std::string keyName, ComplexData& value);
	//static void RetrieveValue(std::string keyName, ComplexData& value /Out/) throw(TableKeyNotDefinedException);

private:
	SmartDashboard();
	SmartDashboard(const SmartDashboard&);
	virtual ~SmartDashboard();
};
