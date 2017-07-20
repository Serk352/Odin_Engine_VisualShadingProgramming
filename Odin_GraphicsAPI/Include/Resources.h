#pragma once
#include "OEPrerequisitesGraphics.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT Resources
	{
	public:

		virtual void load(const String& sFilePath)  = 0;
		String name;

	};


}