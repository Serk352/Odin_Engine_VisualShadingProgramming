#pragma once

#include "Vector3f.h"
#include "PrerequisitesUtil.h"

namespace OE_SDK
{

	class ODIN_ENGINE_UTILITY_EXPORT C_Rayf
	{
	public:
		C_Rayf();
		~C_Rayf();

		C_Vector3f m_Ray;
		float m_Length;

		
	};

}