#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"

namespace OE_SDK
{
	//Esta clase estará encarga de cargar y administrar el uso de recursos
	//dentro del sistema de gráficos.
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEResourceMnager
	{
	public:

		void loadTexture(String SourcePath);
		void loadModel  (String SourcePath);
		void LoadShader (String SourcePath);


	};

}