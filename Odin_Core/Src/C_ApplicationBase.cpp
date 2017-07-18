#pragma once
#include "C_ApplicationBase.h"
#include <windows.h>


namespace OE_SDK
{
//Constructor//
	C_ApplicationBase::C_ApplicationBase()
	{
	}

//Destructor//
	C_ApplicationBase::~C_ApplicationBase()
	{																					 
	}																								                   	

//TODO: Terminar la bomba de mensajes, en especial re-size 
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}


	void C_ApplicationBase::Init(int width, int Height)
	{
		WNDCLASSEXW wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = 0;
		wcex.hIcon = 0;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = 0;
		wcex.lpszMenuName = 0;
		wcex.lpszClassName = (L"ODIN_ENGINE_APP_CLASS");
		wcex.hIconSm = 0;

		RegisterClassExW(&wcex);

		HWND hWnd = CreateWindowW((L"ODIN_ENGINE_APP_CLASS"), (L"VENTANITA"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, Height, width, nullptr, nullptr, 0, nullptr);


		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);

		RECT clientRect;	
		::GetClientRect(hWnd, &clientRect);

		g_GraphicsAPI().startUp();

		//Inicializa DirectX
		g_GraphicsAPI().Init(reinterpret_cast<void*>(hWnd),
			               clientRect.right - clientRect.left, 
			               clientRect.bottom - clientRect.top, 
			               false);
	
		OnInit();
		InitResources(width, Height);
		
	}

	void C_ApplicationBase::Destroy()
	{
		//Destruye DirectX
		g_GraphicsAPI().shutDown();
		OnDestroy();

	}


	int C_ApplicationBase::Run(int width, int Height)
	{
		Init(Height, width);

		MSG msg;
		while(true)
		{
			while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			if (msg.message == WM_QUIT)
			{
				break;
			}

			//TODO: Usar un contador de tiempo real para actualizar la lógica
			Update(1.f/60.f);
			Render();
		}

		Destroy();

		return (int)msg.wParam;
	}

	void C_ApplicationBase::Update(float)
	{

	}

	void C_ApplicationBase::Render()
	{
		
	}

	void C_ApplicationBase::InitResources(int width, int Height)
	{
		UNREFERENCED_PARAMETER(width);
		UNREFERENCED_PARAMETER(Height);
	}

}