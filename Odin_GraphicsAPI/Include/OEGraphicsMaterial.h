#pragma once
#include "OEPrerequisitesGraphics.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsMaterial
	{
	public:

		C_GraphicsMaterial();
		~C_GraphicsMaterial();


//		Color m_Lambert;
		int32 m_Irradescent;
		int32 m_AO_Intensity;

	//Texture

	protected: 

		struct Color
		{
			int8 Red;
			int8 Green;
			int8 Blue;
			int8 Alpha;

		};

		Color m_Color;
	};

}
