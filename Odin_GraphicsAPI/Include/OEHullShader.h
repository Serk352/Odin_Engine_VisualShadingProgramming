#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEShaders.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEHullShader : public OEGraphicsShaders
	{
	public:

		OEHullShader();
		virtual ~OEHullShader();

	
		void Create(const String FileName, const String EntryPoint);
	public:
		static const char* HS_SM;
	};


}
