#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"

namespace OE_SDK
{
	//Esta clase estará encarga de cargar y administrar el uso de recursos
	//dentro del sistema de gráficos.
	/*
	El mecanismo de manager funcionará cargando los archivos usando el nombre
	de los archivos y, aquellos que hagan un call de ese objeto solo recibirán
	un puntero o referencia a la memoria donde está alojado el objeto.
	*/

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEResourceManager
	{
	public:

		//Cargar una textura
		void loadTexture(String SourcePath, int& m_Width, int& m_Height);
		//Cargar un model
		void loadModel  (String SourcePath);
		//Cargar un shader
		void LoadShader (String SourcePath);

	};

}