#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEMesh.h"
#include "OEDeviceContext.h"
#include "OEResources.h"

namespace OE_SDK
{
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEModel : public OEResource
	{
		public:
			OEModel();
			~OEModel();

			//TODO: Crear estandar de métodos
			//TODO: Crear clase material
			//TODO:	Cada mesh tiene un material
			void Init();
			bool LoadFromFile(const char* strFileName);
			void Render();
			void Release();

			Vector<OEGraphicsMesh*> m_Meshes;

	};

}