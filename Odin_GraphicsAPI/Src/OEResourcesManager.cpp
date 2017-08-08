#include "OEResourcesManager.h"
//Libreria necesaria para abrir imagenes.
#include <Externals/stb_image.h>

namespace OE_SDK
{
	void OEResourceManager::loadResource(const String* sSourcePath,nResourceType::eResourceType ResourceType)
	{
		if (IsLoaded(sSourcePath));
		{
			///nada
		}
		else
		{
			if (ResourceType == TEXTURE_2D)
			{
				Resources a;

				a.name = sSourcePath;
				const char* ccPath = sSourcePath->c_str();
				uint8* LoadTexture = stbi_load(ccPath, &rWidth, &rHeight, NULL, rNumChannels);
				a.m_Info = reinterpret_cast<void*>(LoadTexture);


				m_LoadedResources.push(a);




				stbi_image_free(LoadTexture);
			}
		}

	}



}