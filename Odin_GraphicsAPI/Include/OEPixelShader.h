#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEGraphicsShaders.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT  C_PixelShader : public C_GraphicsShaders
	{
	public: 
		C_PixelShader();
		virtual ~C_PixelShader();

		
		//virtual void CompileFromFile(const WCHAR* FileName, const char* EntryPoint, const char* ShaderModel);
		void Create(const String FileName, const String EntryPoint);
		//virtual void Create(const GraphicsDevice* pDevice);
		//virtual void Set(GraphicsDeviceContext* pDeviceContext);
	
	public:
		static const char* PS_SM;
	};
}