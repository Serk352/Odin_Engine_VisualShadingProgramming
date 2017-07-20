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
		OEPixelShader m_PShader;
		OEVertexShader m_VShader;
		
		//Input Layout
		OEInputLayout LayOut;

		//Texturas
		OETexture2D m_Color;
		OETexture2D m_Normal;

		//Samplers
		OESampler m_SamplerColor;
		OESampler m_NormalSampler;


		OEBuffer m_DirectionalLightBuffer;
		OEBuffer m_ViewMatrixBuffer;
		OEBuffer m_ProjMatrixBuffer;
	
		//MAtrix
		C_Matrix4  m_ViewMatrix;
		C_Matrix4  m_ProjectionMatrix;
		C_Matrix4  m_WorldMatrix;
		C_Vector4f m_DirectionalLight;



		//3D Model
		OEModel myModel;

		OEVertexBuffer m_GuiVertexBuffer;
		C_IndexBuffer32 m_GuiIndexBuffer;




	protected:
		//struct ApiData;
	//	ApiData* m_GraphicsAPI;

	};
}