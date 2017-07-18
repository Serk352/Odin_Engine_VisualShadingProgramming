#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"
#include <matrix4x4.h>

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsMaterial
	{
	public:

		C_GraphicsMaterial();
		~C_GraphicsMaterial();


		C_Texture2D m_Normal;
		C_Texture2D m_Albedo; 

		C_Matrix4 

	};

}
