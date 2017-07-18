#pragma once

#include "PrerequisitesUtil.h"
#include "Matrix4.h"
#include "Matrix3.h"

namespace OE_SDK {

	class ODIN_ENGINE_UTILITY_EXPORT C_Quaternion
	{
	public:
		C_Quaternion();
		~C_Quaternion();


		float m_x; 
		float m_y;
		float m_z;
		float m_w;


		C_Quaternion Slerp(C_Quaternion q1, C_Quaternion q2, float t);
		C_Matrix4 GetAsMatrix4();
		C_Matrix3 GetAsMatrix3();

	};
}

