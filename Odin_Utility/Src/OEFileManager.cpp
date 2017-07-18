#include "OEFileManager.h"
#include <string.h>


namespace OE_SDK
{

	C_File::C_File()
	{
		m_Position = 0;
	}

	C_File::C_File(const char* cName)
	{
		Open(cName);
	}

	C_File::~C_File()
	{

	}

	void C_File::Open(const char * psFileName)
	{
		if (m_File.is_open())
		{
			Close();
		}

		m_strFileName = String(psFileName);
		m_File = FileStream(psFileName, ios::in | ios::out | ios::binary | ios::ate);
		
		m_Size = static_cast<SIZE_T>(m_File.tellg());
		
		m_File.seekg(0, ios::beg);
		m_Position = 0;

	}	 

	void C_File::Write(const char* buffer, SIZE_T numBytes)
	{	
		if (!m_File.is_open())
		{
			return;
		}
		
		m_File.write(buffer, numBytes);
		m_Position += numBytes;
	}	 		 
	void C_File::Read(char* outBuffer, SIZE_T numBytes)
	{	
		if (!m_File.is_open())
		{
			return;
		}
		
		SIZE_T bytesTorRead = numBytes;

		if ((bytesTorRead + m_Position) > m_Size) {
			bytesTorRead = m_Size - m_Position;
		}

		m_File.read(outBuffer, bytesTorRead);
	}
	void C_File::Seek(SIZE_T position)
	{	
		if (!m_File.is_open())
		{
			return;
		}

		m_File.seekp(position);
	}	 	 
	SIZE_T C_File::GetIndexPos()
	{
		if (!m_File.is_open())
		{
			return 0;
		}

		return static_cast<SIZE_T>(m_File.tellp());
	}	 
	SIZE_T C_File::ReadAndSave(const char* strFileName, char*& pOutData, SIZE_T& outSize)
	{
	/*	std::streampos begin, end;
		std::ifstream myfile(strFileName, std::ios::binary);

		if (!myfile.is_open())
		{
			return 0;
		}

		//Obtenemos la posición al inicio del archivo
		begin = myfile.tellg();

		//Buscamos la posición al final del archivo
		myfile.seekg(0, std::ios::end);
		end = myfile.tellg();
		outSize = (size_t)(end - begin);

		myfile.seekg(0, begin);

		//Leemos el archivo
		pOutData = new char[outSize];
		myfile.read(pOutData, outSize);

		myfile.close();

		return outSize;*/

		if (m_File.is_open())
		{
			Close();
		}

		m_strFileName = String(strFileName);
		m_File = FileStream(strFileName, ios::in | ios::out | ios::binary | ios::ate);

		m_Size = static_cast<SIZE_T>(m_File.tellg());

		m_File.seekg(0, ios::beg);
		m_Position = 0;

		pOutData = new char[outSize];
		m_File.read(pOutData, outSize);

		m_File.close();

		return outSize;

	}


	void C_File::Close()
	{
		if (!m_File.is_open())
		{
			return;
		}
		
		m_File.close();
	}
}