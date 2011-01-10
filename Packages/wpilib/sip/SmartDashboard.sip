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

class SmartDashboard : DashboardBase
{
%TypeHeaderCode
#include <WPILib/SmartDashboard.h>
%End

public:
	enum FIELD_TYPE {
		BYTE_TYPE = 0, CHAR_UTF16_TYPE = 1, INT_TYPE = 2, LONG_TYPE = 3,
		SHORT_TYPE = 4, FLOAT_TYPE = 5, DOUBLE_TYPE = 6, STRING_UTF16_TYPE = 7,
		BOOL_TYPE = 8, STRING_UTF8_TYPE = 9
	};
	enum RETCODE { SUCCESS, ERR_BUFFER_FULL, ERROR_STRING_TOO_LONG };

	static const INT32 BUFFER_SIZE;

	explicit SmartDashboard(SEM_ID statusDataSemaphore);

	static void init();
	void GetStatusBuffer(char **userStatusData /Out,Array/, INT32* userStatusDataSize /Out,ArraySize/);
%MethodCode
            Py_BEGIN_ALLOW_THREADS
            int a1_int;
            (sipSelfWasArg ? sipCpp->SmartDashboard::GetStatusBuffer(&a0,&a1_int) : sipCpp->GetStatusBuffer(&a0,&a1_int));
            a1 = a1_int;
            Py_END_ALLOW_THREADS
%End

	static RETCODE LogChar(char value, const char* name);
	//static RETCODE LogChar(wchar_t value, const char* name);
	//static RETCODE Log(INT32 value, const char* name);
	static RETCODE Log(INT64 value /Constrained/, const char* name);
	static RETCODE Log(bool value, const char* name);
	//static RETCODE Log(float value, const char* name);
	static RETCODE Log(double value /Constrained/, const char* name);
	static RETCODE Log(const char* value, const char* name);

	void Flush();

	class Buffer {
		public:
			explicit Buffer(INT32 capacity);
			~Buffer();
			void WriteByte(UINT8 c);
			void WriteShort(UINT16 s);
			static int Utf8Length(const char* s);
			void WriteUTF(const char* s);
			void Flush();
			bool HasRoom(INT32 length);
			char* GetBuffer();
			INT32 GetBufferSize();
		private:
			Buffer(const SmartDashboard::Buffer&);
		};

private:
	SmartDashboard(const SmartDashboard&);
};
