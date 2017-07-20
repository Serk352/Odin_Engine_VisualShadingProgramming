#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEShaders.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT  OEPixelShader : public OEGraphicsShaders
	{
	public: 
		OEPixelShader();
		virtual ~OEPixelShader();

		
		//virtual void CompileFromFile(const WCHAR* FileName, const char* EntryPoint, const char* ShaderModel);
		void Create(const String FileName, const String EntryPoint);
		//virtual void Create(const GraphicsDevice* pDevice);
		//virtual void Set(GraphicsDeviceContext* pDeviceContext);
	
	public:
		static const char* PS_SM;
	};
}