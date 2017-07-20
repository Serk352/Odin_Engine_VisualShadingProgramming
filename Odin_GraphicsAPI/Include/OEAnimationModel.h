#pragma once

#include "OEMesh.h"
#include "OEAnimationMesh.h"
#include "OEDeviceContext.h"

namespace OE_SDK
{

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEAnimationModel
	{
	public:
		OEAnimationModel();
		~OEAnimationModel();


		void Init();
		bool LoadFromFile(const char* strFileName, OEGraphicsDevice* prmDevice);
		void Render(OEGraphicsDeviceContext* prmDeviceContext);
		void Release();

		Vector<OEAnimationMesh*> m_Meshes;


	};

}