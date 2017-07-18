#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEGraphicsMesh.h"
#include "OEGraphicsDeviceContext.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT C_GraphicsModel
	{
		public:
			C_GraphicsModel();
			~C_GraphicsModel();

			//TODO: Crear estandar de métodos
			//TODO: Crear clase material
			//TODO:	Cada mesh tiene un material
			void Init();
			bool LoadFromFile(const char* strFileName);
			void Render();
			void Release();

			Vector<C_GraphicsMesh*> m_Meshes;

	};

}