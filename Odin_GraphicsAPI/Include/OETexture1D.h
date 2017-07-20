#pragma once
#include "OETexture.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OETexture1D : public OEGraphicsTexture
	{
	public:

		OETexture1D();
		virtual ~OETexture1D();

		virtual void LoadFromFile(const char* FileName);
		virtual void CreateEmpty();
		virtual void Release();

	};
}