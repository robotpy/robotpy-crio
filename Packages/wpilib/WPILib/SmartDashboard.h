/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef _SMARTDASHBOARD_H_
#define _SMARTDASHBOARD_H_

#include "DashboardBase.h"
#include "Timer.h"
#include <vxWorks.h>
#include <cstring>
#include <map>

using std::map;

class SmartDashboard : public DashboardBase {
public:
	// These protocol values must match the SmartDashboard client receiver.
	typedef enum {
		BYTE_TYPE = 0, CHAR_UTF16_TYPE = 1, INT_TYPE = 2, LONG_TYPE = 3,
		SHORT_TYPE = 4, FLOAT_TYPE = 5, DOUBLE_TYPE = 6, STRING_UTF16_TYPE = 7,
		BOOL_TYPE = 8, STRING_UTF8_TYPE = 9
	} FIELD_TYPE;
	typedef enum { SUCCESS, ERR_BUFFER_FULL, ERROR_STRING_TOO_LONG } RETCODE;

	static const INT32 BUFFER_SIZE;

	explicit SmartDashboard(SEM_ID statusDataSemaphore);

	//** Initialize the SmartDashboard. The Log() methods will call this if needed. */
	static void init();
	void GetStatusBuffer(char **userStatusData, INT32* userStatusDataSize);

	/** Send a value with the given name to the dashboard. */
	static RETCODE LogChar(char value, const char* name);
	static RETCODE LogChar(wchar_t value, const char* name);
	static RETCODE Log(INT32 value, const char* name);
	static RETCODE Log(INT64 value, const char* name);
	static RETCODE Log(bool value, const char* name);
	static RETCODE Log(float value, const char* name);
	static RETCODE Log(double value, const char* name);
	static RETCODE Log(const char* value, const char* name);

	void Flush();

	class Buffer {
		private:
			char* m_buff;
			INT32 m_buffIndex;
			INT32 m_capacity;
			DISALLOW_COPY_AND_ASSIGN(Buffer);
		public:
			explicit Buffer(INT32 capacity);
			~Buffer();
			void WriteByte(UINT8 c);
			void WriteShort(UINT16 s);
			template<class Char> static int Utf8Length(const Char* s);
			template<class Char> void WriteUTF(const Char* s);
			void Flush();
			bool HasRoom(INT32 length);
			char* GetBuffer() {return m_buff;}
			INT32 GetBufferSize() {return m_buffIndex;}
		};

private:
	struct FieldRecord {
		int id;
		FIELD_TYPE type;
		const char* name;
	};
	struct CStringLessThan {
		bool operator()(const char* s1, const char* s2) const {
			return std::strcmp(s1, s2) < 0;
		}
	};

	static const double REANNOUNCEMENT_INTERVAL_SEC;
	static SmartDashboard* instance;
	static bool initialized;
	static SmartDashboard* GetInstance() {return instance;}

	Buffer m_buff;
	typedef map<const char*, FieldRecord, CStringLessThan> FieldMap;
	FieldMap m_fields;
	Timer m_reannouncementTimer;
	SEM_ID m_userStatusDataSem;

	DISALLOW_COPY_AND_ASSIGN(SmartDashboard);

	static RETCODE LogNumber(INT64 value, int numBytes, FIELD_TYPE type,
			const char* name);
	RETCODE AnnounceIfNecessary(FIELD_TYPE type, const char* name);
	void PeriodicallyReannounce();
	RETCODE UpdatePrefix(const char* name, int dataLength);
};

#endif
