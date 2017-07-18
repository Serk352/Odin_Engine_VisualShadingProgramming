#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEShaders.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_DomainShader : public C_GraphicsShaders
	{
	public:
		C_DomainShader();
		~C_DomainShader();


		void Create(const String FileName, const String EntryPoint);
	public:
		static const char* DS_SM;
	};
	
}