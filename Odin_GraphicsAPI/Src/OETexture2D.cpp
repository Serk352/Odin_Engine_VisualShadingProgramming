
#include "OETexture2D.h"
#include "OEGraphicsAPI.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <d3d11.h>

namespace OE_SDK
{

	struct OETexture2D::TextureData
	{
		ID3D11Texture2D* myTexture;
	};

	OETexture2D::OETexture2D()
	{
		m_Texture = new TextureData;
		m_Texture->myTexture = nullptr;
	}

	OETexture2D::~OETexture2D()
	{
		SAFE_RELEASE(m_Texture->myTexture);
		SAFE_DELETE(m_Texture);
	}


	

	void OETexture2D::Create(int Width, 
								int Height, 
								bool isWritrable, 
								nFormats::eFormat myFormat,
								nBindFlags::eBindFlag  prmBind)
	{
	
		UNREFERENCED_PARAMETER(isWritrable);
		//Descriptor de la textura, esto se usará para generar la textura
		D3D11_TEXTURE2D_DESC TexDesc;
		ZeroMemory(&TexDesc, sizeof(TexDesc));
		TexDesc.Width = Width;
		TexDesc.Height = Height;
		TexDesc.MipLevels = 1;
		TexDesc.ArraySize = 1;
		TexDesc.Format = nFormats::TranslateFormat(myFormat);
		TexDesc.SampleDesc.Count = 1;
		TexDesc.SampleDesc.Quality = 0;
		TexDesc.BindFlags = TranslateBindFlag(prmBind);
		TexDesc.CPUAccessFlags = 0;
		TexDesc.MiscFlags = 0;
		TexDesc.Usage = D3D11_USAGE_DEFAULT;

		m_Format = myFormat;
		//Crea la textura en el Device con la información del archivo, el descriptor de la textura y el destino,
		//lienzo donde pintaré.

		HRESULT result;

		ID3D11Device* Device = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());

		result = Device->CreateTexture2D(&TexDesc, NULL, &m_Texture->myTexture);
		if (FAILED(result))
			{
			//return result;
			}
		}



	void OETexture2D::LoadFromFile(char* FileName, 
								   bool isWritable, 
								   int DesireNumChannels, 
								   nFormats::eFormat myFormat,
								   nBindFlags::eBindFlag prmBind)
	{


	   //Se obtiene la información del archivo y se guarda en las variables
		uint8* MyImage = stbi_load(FileName, &m_Width, &m_Height, &m_NumChannels, DesireNumChannels);


		//Descriptor de la textura, esto se usará para generar la textura
		D3D11_TEXTURE2D_DESC TexDesc;
		memset(&TexDesc, 0, sizeof(D3D11_TEXTURE2D_DESC));
		
		TexDesc.Width = m_Width;
		TexDesc.Height = m_Height;
		TexDesc.MipLevels = 1;
		TexDesc.ArraySize = 1;
		TexDesc.Format = nFormats::TranslateFormat(myFormat);
		TexDesc.SampleDesc.Count = 1;
		TexDesc.SampleDesc.Quality = 0;
		TexDesc.BindFlags = TranslateBindFlag(prmBind);
		TexDesc.CPUAccessFlags = 0;
		TexDesc.MiscFlags = 0;
		if (isWritable)
		{
			TexDesc.Usage = D3D11_USAGE_DEFAULT;
		}
		else
		{
			TexDesc.Usage = D3D11_USAGE_IMMUTABLE;
		}

		m_Format = myFormat;
		//Se genera un buffer con  la información de la textura
		D3D11_SUBRESOURCE_DATA data;
		data.pSysMem = (void*)MyImage;
		data.SysMemPitch = m_Width * 4;
		data.SysMemSlicePitch = m_Width * m_Height * 4;

		//Crea la textura en el Device con la información del archivo, el descriptor de la textura y el destino,
		//lienzo donde pintaré.

		HRESULT hr;
		ID3D11Device* pDevice = reinterpret_cast<ID3D11Device*>(g_GraphicsAPI().GetDevice());


		hr = pDevice->CreateTexture2D(&TexDesc, &data, &m_Texture->myTexture);

		if (FAILED(hr))
		{
			return;
		}

		stbi_image_free(MyImage);
	}

	void* OETexture2D::GetObj()
	{
		return reinterpret_cast<void*> (m_Texture->myTexture);
	}

	void** OETexture2D::GetReference()
	{
		return reinterpret_cast<void**> (&m_Texture->myTexture);
	}

}




