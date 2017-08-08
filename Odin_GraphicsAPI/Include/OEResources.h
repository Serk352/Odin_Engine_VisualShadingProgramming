#include "OEPrerequisitesGraphics.h"
#pragma once


namespace OE_SDK
{
	class OEResource
	{
	public:

		OEResource() {};
		virtual ~OEResource() {};

		String m_Name;
		void* m_Info;
		
	};
}