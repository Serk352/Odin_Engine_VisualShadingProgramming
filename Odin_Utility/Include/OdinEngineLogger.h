#pragma once
#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	class C_Logger
	{

	public:
		enum e_MessageType
		{
			MESSAGE,
			WARNING,
			EROR,
			CRITICAL_ERROR
		};
		


	public:
		void SetMessage(e_MessageType eType);
		void PrintMessage(char* prmMessage);
		

	public:
		C_Logger();
		~C_Logger();


	public:
		e_MessageType m_eMessage;
	
	private:
		C_File m_File;



	};
}