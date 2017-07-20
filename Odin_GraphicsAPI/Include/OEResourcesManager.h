#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"

namespace OE_SDK
{
	//Esta clase estar� encarga de cargar y administrar el uso de recursos
	//dentro del sistema de gr�ficos.
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEResourceMnager
	{
	public:

		void loadTexture(String SourcePath);
		void loadModel  (String SourcePath);
		void LoadShader (String SourcePath);


	};

}