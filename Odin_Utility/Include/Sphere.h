#pragma once

#include "PrerequisitesUtil.h"
#include "Vector3f.h"

namespace OE_SDK
{
	class ODIN_ENGINE_UTILITY_EXPORT C_Sphere
	{
	public:
		C_Sphere();
		~C_Sphere();

		C_Vector3f m_Center; 
		float m_RadialDistance;
	};
}
