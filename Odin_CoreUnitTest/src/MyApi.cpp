#pragma once
#include "MyApi.h"
#include "OEGraphicsAPI.h"
#include "OEPixelShader.h"
#include "OEVertexShader.h"
#include "OEModel.h"
#include "OEInputLayout.h"
#include <DirectXMath.h>
#include "OEDevice.h"
#include "OEShaderResource.h"
#include "OEFormats.h"
#include "OEVertex.h"
#include "Matrix4.h"
#include "OEFormats.h"
#include "OEDepthStencil.h"

//////////////////////////////////////////////////////////////////////////



namespace OE_SDK
{
	
	

	MyApi::MyApi()
	{

	}

	MyApi::~MyApi()
	{

	}
	

	 void MyApi::InitResources(int width, int Height)
	{

	 //Shaders
		 m_VShader.Create("Resources/Shaders/TestShader.hlsl", "VS_MAIN");
																									
		 m_PShader.Create("Resources/Shaders/TestShader.hlsl", "PS_MAIN");
		
		 //LayOut
		LayOut.AddInputElement("POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT,                                 0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0);
		LayOut.AddInputElement("COLOR",		0, DXGI_FORMAT_R32G32B32_FLOAT/*DXGI_FORMAT_R8G8B8A8_UINT*/,	0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0);
		LayOut.AddInputElement("NORMAL",	0, DXGI_FORMAT_R32G32B32_FLOAT,                                 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0);
		LayOut.AddInputElement("TEXCOORD",	0, DXGI_FORMAT_R32G32_FLOAT,	                                0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0);
		LayOut.AddInputElement("BINORMAL",	0, DXGI_FORMAT_R32G32B32_FLOAT,                                 0, 36, D3D11_INPUT_PER_VERTEX_DATA, 0);
		LayOut.AddInputElement("TANGENT",	0, DXGI_FORMAT_R32G32B32_FLOAT,                                 0, 48, D3D11_INPUT_PER_VERTEX_DATA, 0);


		LayOut.create(&m_VShader);
		

	//Texturas
	
		m_Color.LoadFromFile("Resources/Textures/M.jpg", true, 4, nFormats::FORMAT_R8G8B8A8_UNORM, nBindFlags::BIND_SHADER_RESOURCE);
		m_Normal.LoadFromFile("Resources/Textures/N2.jpg", true, 4, nFormats::FORMAT_R8G8B8A8_UNORM, nBindFlags::BIND_SHADER_RESOURCE);

		//Recurso para el shader
		OEShaderResource ColorView;
		OEShaderResource NormalView;
		
		ColorView.Create(m_Color, 1, 0);
		NormalView.Create(m_Normal, 1, 0);



		//Crea el estado del sampler
		//m_GraphicsAPI.m_APIData->m_Device.pDevice->CreateSamplerState(&samplerDesc, &TextureSampler);
		m_SamplerColor.CreateSamplerState(nSamplingFilters::FILTER_MIN_MAG_MIP_LINEAR,
										  nTextureAddresModes::TEXTURE_ADDRESS_WRAP, 
										  nTextureAddresModes::TEXTURE_ADDRESS_WRAP,
										  nTextureAddresModes::TEXTURE_ADDRESS_WRAP, 
										  nComparisonFunctions::COMPARISON_NEVER);

		m_NormalSampler.CreateSamplerState(nSamplingFilters::FILTER_MIN_MAG_MIP_LINEAR,
										   nTextureAddresModes:: TEXTURE_ADDRESS_WRAP,
										   nTextureAddresModes :: TEXTURE_ADDRESS_WRAP,
										   nTextureAddresModes :: TEXTURE_ADDRESS_WRAP,
										   nComparisonFunctions:: COMPARISON_NEVER);






		//////////////////////////////////////////////////////////////////////////
		//Crear buffers
		m_DirectionalLightBuffer.Create(nullptr, sizeof(C_Vector4f));

		m_ViewMatrixBuffer.Create(nullptr, sizeof(C_Matrix4));

		m_ProjMatrixBuffer.Create(nullptr, sizeof(C_Matrix4));
		
		//////////////////////////////////////////////////////////////////////////
		C_Vector3f Eye(0.0f, 1.0f, 6.0f);
		C_Vector3f At(0.0f, 1.0f, 0.0f);
		C_Vector3f Up(0.0f, -1.0f, 0.0f);
		//////////////////////////////////////////////////////////////////////////
		
		
		m_ViewMatrix = myCam.LookAtMatrix(Eye,Up,At);
		m_ViewMatrix.Transposed();

		m_ViewMatrixBuffer.SetData(&m_ViewMatrix, sizeof(C_Matrix4));


		//////////////////////////////////////////////////////////////////////////
		m_ProjectionMatrix= myCam.PerpsProjectedSpace(35.0f * PlatformMath::DEGTORAD, (float)Height / (float)width, 0.01f, 1000.0f);
		m_ProjectionMatrix.Transposed();
		
		
		m_ProjMatrixBuffer.SetData(&m_ProjectionMatrix, sizeof(C_Matrix4));

	
		//////////////////////////////////////////////////////////////////////////
		
//		m_DirectionalLight = C_Vector4f(-30.0f, 2.0f, 1.0f, 0.0f);


		m_DirectionalLight = C_Vector4f(1.0f, 0.0f, 0.0f, 0.0f);
		m_DirectionalLightBuffer.SetData(&m_DirectionalLight, sizeof(C_Vector4f));

		

		
		// Color
		ColorView.SetForPixelShader(0, 1);
		//Normal
		NormalView.SetForPixelShader(1, 1);

		

		//Load the 3D Model
		myModel.LoadFromFile("Resources/Models/kratos.obj");



	}






	void MyApi::Render()
	{
		ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().GetDeviceContext());
		ID3D11RenderTargetView* shaderResourceView = reinterpret_cast<ID3D11RenderTargetView*>(g_GraphicsAPI().GetRenderTargetViewObject());

		C_Vector4f clearColor = { 0.0f, 0.0f, 1.0f, 1.0f };
		pDeviceContext->ClearRenderTargetView(shaderResourceView, &clearColor.X_Axis);

		g_GraphicsAPI().ClearDepthStencil();
		 LayOut.Set();

		 m_SamplerColor.SetForPixelShader(0, 1);
		 //Normal
		 m_NormalSampler.SetForPixelShader(1, 1);

		 //////////////////////////////////////////////////////////////////////////

		 m_ViewMatrixBuffer.SetForVertexShader(0);

		 //////////////////////////////////////////////////////////////////////////
	
		 m_ProjMatrixBuffer.SetForVertexShader(1);
	
		 //////////////////////////////////////////////////////////////////////////

		 m_DirectionalLightBuffer.SetForPixelSahder(2);
		 //////////////////////////////////////////////////////////////////////////
		 myModel.Render();

	//	 RenderInterface();

		 g_GraphicsAPI().PresentSwapChain();
	 }





}	