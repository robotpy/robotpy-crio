/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Synchronized.h"
#include "DriverStation.h"
#include "SmartDashboard.h"
#include "SmartDashboardPacketFactory.h"

const INT32 SmartDashboard::BUFFER_SIZE = 768;
const double SmartDashboard::REANNOUNCEMENT_INTERVAL_SEC = 5.0;
SmartDashboard* SmartDashboard::instance =
	new SmartDashboard(DriverStation::GetInstance()->GetUserStatusDataSem());
bool SmartDashboard::initialized = false;

SmartDashboard::SmartDashboard(SEM_ID statusDataSemaphore)
	: m_buff(BUFFER_SIZE),
	  m_reannouncementTimer(),
	  m_userStatusDataSem(statusDataSemaphore) {
	m_reannouncementTimer.Reset();
	m_reannouncementTimer.Start();
}

void SmartDashboard::init() {
	DriverStation::GetInstance()->SetHighPriorityDashboardPackerToUse(instance);
	initialized = true;
}

/**
 * Called by the DriverStation class to retrieve buffers, sizes, etc. for
 * writing to the NetworkCommunication task.
 * This function is called while holding the m_statusDataSemaphore.
 */
void SmartDashboard::GetStatusBuffer(char** userStatusData,
		INT32* userStatusDataSize) {
	*userStatusData = m_buff.GetBuffer();
	*userStatusDataSize = m_buff.GetBufferSize();
}

/**
 * Log a character (7-bit ASCII or 8-bit LATIN-1 encoding).
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::LogChar(char value, const char* name) {
	// Zero-extend 7-bit ASCII or 8-bit LATIN-1 to wchar_t which is UTF-16 in
	// most C++ compilers.
	return LogChar((wchar_t) (unsigned char) value, name);
}

/**
 * Log a wide character (Unicode's UTF-16 encoding).
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::LogChar(wchar_t value, const char* name) {
	// Try to get the right value whether the compiler defines wchar_t as 8 or
	// 16 bits, signed or unsigned.
	return LogNumber((UINT16) (unsigned wchar_t) value, 2, CHAR_UTF16_TYPE, name);
}

/**
 * Log a 32-bit signed integer value.
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::Log(INT32 value, const char* name) {
	return LogNumber(value, 4, INT_TYPE, name);
}

/**
 * Log a 64-bit signed integer value.
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::Log(INT64 value, const char* name) {
	return LogNumber(value, 8, LONG_TYPE, name);
}

/**
 * Log a boolean value.
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::Log(bool value, const char* name) {
	return LogNumber((unsigned char) value, 1, BOOL_TYPE, name);
}

/**
 * Log a single precision floating point value.
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::Log(float value, const char* name) {
	INT32 ivalue = *reinterpret_cast<INT32*>(&value);
	return LogNumber(ivalue, 4, FLOAT_TYPE, name);
}

/**
 * Log a double precision floating point value.
 * SmartDashboard assumes the name string will remain valid. It does not make a copy.
 */
SmartDashboard::RETCODE SmartDashboard::Log(double value, const char* name) {
	INT64 ivalue = *reinterpret_cast<INT64*>(&value);
	return LogNumber(ivalue, 8, DOUBLE_TYPE, name);
}

/**
 * Log a C string value (7-bit ASCII or 8-bit LATIN-1 encoding).
 * SmartDashboard assumes the name string will remain valid. It does not make a
 * copy. It does copy the value string.
 */
SmartDashboard::RETCODE SmartDashboard::Log(const char* value, const char* name) {
	if (!initialized)
		init();

	RETCODE code;
	// *** Begin Critical Region ***
	Synchronized sync(instance->m_userStatusDataSem);

	if ((code = instance->AnnounceIfNecessary(STRING_UTF8_TYPE, name)) != SUCCESS)
		return code;
	UINT16 length = Buffer::Utf8Length(value);
	if (length > 127) // clip it? 255 is the max for the UINT8 data length field
		return ERROR_STRING_TOO_LONG;
	if ((code = instance->UpdatePrefix(name, length + 2)) != SUCCESS)
		return code;
	instance->m_buff.WriteUTF(value);

	instance->PeriodicallyReannounce();

	DriverStation::GetInstance()->IncrementUpdateNumber();

	return SUCCESS;
	// *** End Critical Region (upon auto-destruction of sync) ***
}

/**
 * Log a number of the given size and type in Java's DataInputStream format.
 * This writes a big-endian number no matter what the CPU endianness.
 */
SmartDashboard::RETCODE SmartDashboard::LogNumber(INT64 value, int numBytes,
		FIELD_TYPE type, const char* name) {
	if (!initialized)
		init();

	RETCODE code;
	// *** Begin Critical Region ***
	Synchronized sync(instance->m_userStatusDataSem);

	if ((code = instance->AnnounceIfNecessary(type, name)) != SUCCESS)
		return code;
	if ((code = instance->UpdatePrefix(name, numBytes)) != SUCCESS)
		return code;
	for (int shift = (numBytes - 1) * 8; shift >= 0; shift -= 8) {
		instance->m_buff.WriteByte((value >> shift) & 0xFF);
	}

	instance->PeriodicallyReannounce();

	DriverStation::GetInstance()->IncrementUpdateNumber();

	return SUCCESS;
	// *** End Critical Region (upon auto-destruction of sync) ***
}

SmartDashboard::RETCODE SmartDashboard::AnnounceIfNecessary(FIELD_TYPE type,
		const char* name) {
	if (m_fields.count(name) < 1) {
		if (!m_buff.HasRoom(
				SmartDashboardPacketFactory::GetAnnounceLength(name)))
			return ERR_BUFFER_FULL;

		FieldRecord r;
		r.name = name;
		r.type = type;
		r.id = m_fields.size();

		m_fields[name] = r;

		SmartDashboardPacketFactory::Announce(m_buff, r.id, r.type, r.name);
		DriverStation::GetInstance()->IncrementUpdateNumber();
	}

	return SUCCESS;
}

/** Periodically re-announce all fields for receivers that tune in late. */
void SmartDashboard::PeriodicallyReannounce() {
	if (m_reannouncementTimer.HasPeriodPassed(REANNOUNCEMENT_INTERVAL_SEC)) {
		for (FieldMap::iterator it = m_fields.begin(); it != m_fields.end(); it++) {
			FieldRecord &r = it->second;
			if (m_buff.HasRoom(SmartDashboardPacketFactory::GetAnnounceLength(r.name))) {
				SmartDashboardPacketFactory::Announce(m_buff, r.id, r.type, r.name);
			} else {
				// there isn't enough room for this name but there might be room
				// for a shorter name; hopefully there'll be room next time
			}
		}
	}
}

SmartDashboard::RETCODE SmartDashboard::UpdatePrefix(const char* name,
		int dataLen) {
	if (!m_buff.HasRoom(SmartDashboardPacketFactory::GetUpdateLength(dataLen)))
		return ERR_BUFFER_FULL;

	FieldRecord& r = m_fields[name];
	SmartDashboardPacketFactory::UpdatePrefix(m_buff, r.id, dataLen);
	return SUCCESS;
}

void SmartDashboard::Flush() {
	m_buff.Flush();
}


SmartDashboard::Buffer::Buffer(INT32 capacity)
		: m_buffIndex(0), m_capacity(capacity) {
	m_buff = new char[m_capacity];
}

SmartDashboard::Buffer::~Buffer() {
	delete[] m_buff;
}

void SmartDashboard::Buffer::WriteByte(UINT8 c) {
	m_buff[m_buffIndex++] = c;
}

/** Write an unsigned 16-bit big endian number. */
void SmartDashboard::Buffer::WriteShort(UINT16 s) {
	WriteByte((s >> 8) & 0xFF);
	WriteByte(s        & 0xFF);
}

/**
 * Return the "UTF length" of the DataInput-modified UTF-8 string encoding. This
 * works for NUL-terminated strings of char or wchar_t (wide char) but maybe not
 * for signed char. Unicode characters > 0x7FF (including supplementary chars
 * and their surrogate pair encodings) are not currently supported.
 */
template<class Char> int SmartDashboard::Buffer::Utf8Length(const Char* s) {
	int length = 0;
	for (int i = 0; s[i] != 0; ++i) {
		unsigned wchar_t c = s[i];
		if (c >= 0x80) ++length;
		++length;
	}
	return length;
}

/**
 * Emulate Java's DataOutput#writeUTF(), writing a 2-byte count of bytes
 * followed by Utf8Length(s) bytes of Java's modified UTF-8 encoded text. See
 * http://download.oracle.com/javase/6/docs/api/java/io/DataInput.html#modified-utf-8
 * http://download.oracle.com/javase/6/docs/api/java/io/DataOutput.html#writeUTF%28java.lang.String%29
 * 
 * This works for NUL-terminated strings of char or wchar_t (wide char) but
 * maybe not for signed char.
 *
 * Encode characters in [1 .. 0x7F] as themselves.
 * Encode characters in [0x80 .. 0x7FF] as a pair of bytes.
 * Unicode characters > 0x7FF (including supplementary chars and their surrogate
 * pair encodings) are not currently supported.
 * Character 0 (NUL) is the C string terminator so we never have to encode one.
 */
template<class Char> void SmartDashboard::Buffer::WriteUTF(const Char* s) {
	UINT16 length = Utf8Length(s);
	this->WriteShort(length);
	for (int i = 0; s[i] != 0; ++i) {
		unsigned wchar_t c = s[i];
		if (c < 0x80) {
			WriteByte(c);
		} else {
			WriteByte((char) (0xC0 | (0x1F & (c >> 6))));
			WriteByte((char) (0x80 | (0x3F & c)));
		}
	}
}

void SmartDashboard::Buffer::Flush() {
	m_buffIndex = 0;
}

bool SmartDashboard::Buffer::HasRoom(INT32 length) {
	bool result = (m_buffIndex + length) <= m_capacity;
	return result;
}
