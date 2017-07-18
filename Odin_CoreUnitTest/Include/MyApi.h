#pragma once
#include "C_ApplicationBase.h"
#include "OETexture2D.h"
#include "OESampler.h"
#include "OEBuffer.h"
#include "OEPixelShader.h"
#include "OEVertexShader.h"
#include <Camera.h>

namespace OE_SDK
{
	class MyApi : public /*OE_SDK::*/C_ApplicationBase
	{
	public:

		MyApi();
		virtual ~MyApi();

		

		//////////////////////////////////////////////////////////////////////////
		////////////////////////////////Métodos///////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		virtual void InitResources(int width, int Height);
		virtual void Render();
		

		//////////////////////////////////////////////////////////////////////////
		////////////////////////////////Miembros//////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		

		//Cámara
		C_Camera myCam;
		
		//Shaders
		C_PixelShader m_PShader;
		C_VertexShader m_VShader;
		
		//Input Layout
		C_InputLayout LayOut;

		//Texturas
		C_Texture2D m_Color;
		C_Texture2D m_Normal;

		//Samplers
		C_Sampler m_SamplerColor;
		C_Sampler m_NormalSampler;


		C_Buffer m_DirectionalLightBuffer;
		C_Buffer m_ViewMatrixBuffer;
		C_Buffer m_ProjMatrixBuffer;
	
		//MAtrix
		C_Matrix4  m_ViewMatrix;
		C_Matrix4  m_ProjectionMatrix;
		C_Matrix4  m_WorldMatrix;
		C_Vector4f m_DirectionalLight;



		//3D Model
		C_GraphicsModel myModel;

		C_VertexBuffer m_GuiVertexBuffer;
		C_IndexBuffer32 m_GuiIndexBuffer;




	protected:
		//struct ApiData;
	//	ApiData* m_GraphicsAPI;

	};
}