#pragma once
#include "OETexture.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_Texture1D : public C_GraphicsTexture
	{
	public:

		C_Texture1D();
		virtual ~C_Texture1D();

		virtual void LoadFromFile(const char* FileName);
		virtual void CreateEmpty();
		virtual void Release();

	};
}