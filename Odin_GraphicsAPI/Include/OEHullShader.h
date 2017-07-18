#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEGraphicsShaders.h"


namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_HullShader : public C_GraphicsShaders
	{
	public:

		C_HullShader();
		virtual ~C_HullShader();

	
		void Create(const String FileName, const String EntryPoint);
	public:
		static const char* HS_SM;
	};


}
