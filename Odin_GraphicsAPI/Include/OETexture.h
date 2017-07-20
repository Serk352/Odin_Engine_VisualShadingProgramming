#pragma once
#include "OEPrerequisitesGraphics.h"
#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include<d3d11.h>
#endif

namespace OE_SDK
{


	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEGraphicsTexture
	{
	public:
		OEGraphicsTexture() {};
		virtual ~OEGraphicsTexture() {};

	protected:

		struct TextureData
		{
#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
			ID3D11Texture1D* myTexture1D;
			ID3D11Texture2D* myTexture2D;
#endif
		};

	public:
		TextureData* m_TextureData;

		//Cargar Textura desde un archivo
		//Crear una vacía

		virtual void LoadFromFile(const char* FileName) = 0;
		virtual void CreateEmpty() = 0;
		virtual void Release() = 0;
	};

}