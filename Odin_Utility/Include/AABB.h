#pragma once
#include "PrerequisitesUtil.h"
#include "Vector3f.h"


//Axis Aligned Bouncing Box
namespace OE_SDK
{
	class  ODIN_ENGINE_UTILITY_EXPORT C_AABB
	{
	public:
		C_AABB();
		~C_AABB();

		C_Vector3f a;
		C_Vector3f b;

	};

}
