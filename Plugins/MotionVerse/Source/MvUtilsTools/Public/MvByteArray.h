#pragma once

//#include <stdint.h>
//#include <string.h>
#include <iostream>

class MVUTILSTOOLS_API MvByteArray
{
public:
	MvByteArray();

	~MvByteArray();

	uint8_t* Data() { return m_data; }
	int Length() { return m_length; }

	uint8_t* RemainData() { return &m_data[m_currentPos]; }
	int RemainLength() { return m_validLength - m_currentPos; }

	//////////////////////////////////////////////////////
	uint8_t ReadByte8();
	bool ReadBool8();
	uint16_t ReadShort16();
	int ReadInt32();
	uint64_t ReadLong64();
	float ReadFloat32();
	double ReadDouble64();
	int ReadUTF(uint8_t* arr, int arrLength);
	//////////////////////////////////////////////////////
	void ensureCapacity(int);
	//////////////////////////////////////////////////////
	void WriteByte8(uint8_t);
	void WriteBool8(bool);
	void WriteShort16(uint16_t);
	void WriteInt32(int);
	void WriteLong64(uint64_t);
	void WriteFloat32(float);
	void WriteDouble64(double);
	void WriteUTF(uint8_t* bytesPtr, int num);
	void WriteRawBytes(uint8_t* bytesPtr, int num);
	//////////////////////////////////////////////////////
	int ReadHeadInt();
	void UpdateHeadInt32(int val);
	//////////////////////////////////////////////////////
	void CopyData(uint8_t* data, int length);
	//////////////////////////////////////////////////////
	void ResetPos() { m_currentPos = 0; m_validLength = 0; }
	void EndPos() { m_currentPos = m_length; }
	int GetPos() { return m_currentPos; }
	//////////////////////////////////////////////////////
	const static int BYTE_SIZE = 1;
	const static int BOOL_SIZE = 1;
	const static int CHAR_SIZE = 1;
	const static int SHORT_SIZE = 2;
	const static int INT_SIZE = 4;
	const static int LONG64_SIZE = 8;
	const static int FLOAT_SIZE = 4;
	const static int DOUBLE_SIZE = 8;
	//////////////////////////////////////////////////////

public:
	static int ReadInt32(uint8_t* data);

private:
	uint8_t* m_data = nullptr;
	int m_length = 0;
	int m_currentPos = 0;
	int m_validLength = 0;
};
