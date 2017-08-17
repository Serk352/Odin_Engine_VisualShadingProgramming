#pragma once
#include "OEPrerequisitesGraphics.h"
#include "OEFormats.h"

namespace OE_SDK
{


	
	class ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT OETexture2D
	{

	public:
		OETexture2D();
		~OETexture2D();
	
	
		
		int32 m_Width;
		int32 m_Height;
		int32 m_NumChannels;
		nFormats::eFormat m_Format;
		nBindFlags::eBindFlag m_BindingFlag;


		void Create(int Width, 
					int Height, 
					bool isWritrable,
					nFormats::eFormat prmFormat,
					nBindFlags::eBindFlag prmBind);

		void LoadFromFile(char* FileName, 
						  bool isWritable, 
						  int DesireNumChannels, 
						  nFormats::eFormat myFormat,
						  nBindFlags::eBindFlag prmBind);
		
		void* GetObj();
		void** GetReference();

	protected:
		struct TextureData;
		TextureData* m_Texture;


	};

}