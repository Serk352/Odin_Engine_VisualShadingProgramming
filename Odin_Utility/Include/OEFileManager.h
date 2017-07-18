#pragma once

#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	using std::ios;

	class ODIN_ENGINE_UTILITY_EXPORT C_File
	{
	public:
		void Open(const char* psFileName);
		void Write(const char* buffer, SIZE_T numBytes);
		void Read(char* outBuffer, SIZE_T numBytes);
		void Seek(SIZE_T position);
		SIZE_T GetIndexPos();
		SIZE_T ReadAndSave(const char * strFileName, char *& pOutData, SIZE_T & outSize);
		void Close();

	public:
		C_File();
		C_File(const char* psName);
		~C_File();

	private:
		FileStream m_File;
		String m_strFileName;
		WString a;
		SIZE_T m_Size;
		SIZE_T m_Position;
	};


}

