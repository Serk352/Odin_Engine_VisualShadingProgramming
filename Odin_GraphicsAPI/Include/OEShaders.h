#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEShaders.h"

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include <d3d11.h>
#endif

namespace OE_SDK
{
	struct ShaderData
	{
#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32

		ShaderData() :
			myShader(nullptr), pErrors(nullptr), myPixelShader(nullptr), myVertexShader(nullptr)
		{

		}
	//public:
		ID3D10Blob* myShader;
		ID3D10Blob* pErrors;
		ID3D11PixelShader* myPixelShader;
		ID3D11VertexShader* myVertexShader;
		ID3D11HullShader* myHullShader;
		ID3D11DomainShader* myDomainShader;

#endif
	};

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsShaders
	{
	public:
		C_GraphicsShaders();
		virtual ~C_GraphicsShaders();


		ShaderData* m_ShaderData;

	//	virtual void CompileFromFile(const WCHAR* FileName, const char* EntryPoint, const char* ShaderModel) = 0;
		virtual void Create(const String FileName, const String EntryPoint){}
	//	virtual void Set( GraphicsDeviceContext* pDeviceContext) = 0;
		virtual void Release();



	};

}