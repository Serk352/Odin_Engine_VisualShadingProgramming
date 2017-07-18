#pragma once
#include "PrerequisitesVSP.h"
#include "C_Node.h"


namespace OE_SDK
{
	class ODIN_ENGINE_VSP_API_UTILITY_EXPORT  C_Color : public C_Node
	{

		float color[4];

		void setColor(float red, float green, float blue, float alpha);


	};
}