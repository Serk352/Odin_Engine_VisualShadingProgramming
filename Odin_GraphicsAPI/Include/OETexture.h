#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEResources.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEGraphicsTexture : public OEResource
	{
	public:
		OEGraphicsTexture() {};
		virtual ~OEGraphicsTexture() {};



		//Cargar Textura desde un archivo
		//Crear una vacía

		virtual void LoadFromFile(const char* FileName) = 0;
		virtual void CreateEmpty() = 0;
		virtual void Release() = 0;
	protected:

		struct TextureData;
		TextureData* m_TextureData;

	};
}