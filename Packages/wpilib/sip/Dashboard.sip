// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2010 Peter Johnson
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

class Dashboard : DashboardBase
{
%TypeHeaderCode
#include <WPILib/Dashboard.h>
%End

public:
	explicit Dashboard(SEM_ID statusDataSemaphore);
	virtual ~Dashboard();

	enum Type {kI8, kI16, kI32, kU8, kU16, kU32, kFloat, kDouble, kBoolean, kString, kOther};
	enum ComplexType {kArray, kCluster};

	void AddI8(int8_t value);
	void AddI16(int16_t value);
	void AddI32(int32_t value);
	void AddU8(uint8_t value);
	void AddU16(uint16_t value);
	void AddU32(uint32_t value);
	void AddFloat(float value);
	void AddDouble(double value);
	void AddBoolean(bool value);
	void AddString(char* value);
	void AddString(char* value, int32_t length);

	void AddArray();
	void FinalizeArray();
	void AddCluster();
	void FinalizeCluster();

	void Print(const char *s);
%MethodCode
	sipCpp->Printf("%s", a0);
%End

	int32_t Finalize();
	void GetStatusBuffer(char** userStatusData /Out,Array/, int32_t* userStatusDataSize /Out,ArraySize/);
%MethodCode
            Py_BEGIN_ALLOW_THREADS
            int32_t a1_int;
            sipSelfWasArg ? sipCpp->Dashboard::GetStatusBuffer(&a0,&a1_int) : sipCpp->GetStatusBuffer(&a0,&a1_int);
            a1 = a1_int;
            Py_END_ALLOW_THREADS
%End
	void Flush();
};
