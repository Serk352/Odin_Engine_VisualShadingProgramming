#pragma once

#include "OEPrerequisitesGraphics.h"
#include "OEGraphicsShaders.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT  C_VertexShader : public C_GraphicsShaders
	{
	public:
		C_VertexShader();
		virtual ~C_VertexShader();

		//virtual void CompileFromFile(const WCHAR* FileName, const char* EntryPoint, const char* ShaderModel);
		void Create(const String FileName, const String EntryPoint);
		//virtual void Set(GraphicsDeviceContext* pDeviceContext);

	public:
		static const char* VS_SM;

	};


}