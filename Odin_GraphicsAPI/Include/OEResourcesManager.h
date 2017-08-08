#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OETexture2D.h"
#include "OEModel.h"
#include "OEPixelShader.h"
#include "OEVertexShader.h"
#include "OEResources.h"
#include "OEFormats.h"

namespace OE_SDK
{
	//Esta clase estar� encarga de cargar y administrar el uso de recursos
	//dentro del sistema de gr�ficos.
	/*
	El mecanismo de manager funcionar� cargando los archivos usando el nombre
	de los archivos y, aquellos que hagan un call de ese objeto solo recibir�n
	un puntero o referencia a la memoria donde est� alojado el objeto.
	*/

	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OEResourceManager
	{
	public:

		//Cargar una textura
		void loadResource(const String* sSourcePath, nResourceType::eResourceType ResourceType);
		//Cargar un model
		void loadModel(const String* sSourcePath);
		//Cargar un shader
		void LoadShader (const String* sSourcePath);

		void RequestResource(const String* sSourcePath);
		void RequestModel();
		void RequestShader();


	protected: 
		Vector<OEResource*> m_LoadedResources;
		bool IsLoaded(const String* sSourcePath);

	};

}