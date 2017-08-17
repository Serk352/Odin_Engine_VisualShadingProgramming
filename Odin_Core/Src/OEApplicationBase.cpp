#pragma once
#include "OEApplicationBase.h"
#include <windows.h>
#include <dinput.h>

namespace OE_SDK
{
//Constructor//
	C_ApplicationBase::C_ApplicationBase()
	{
		m_Input = nullptr;
		LBMStillPressed = false; 
		RBMStillPressed = false;
		a = 0;
		K1StillPressed = false;
		K2StillPressed = false; 
		KWStillPressed = false;
		KSStillPressed = false;
		KAStillPressed = false;
		KDStillPressed = false;

		//////////////////////////////////////////////////////////////////////////
		KKStillPressed = false;
		KJStillPressed = false;
		//////////////////////////////////////////////////////////////////////
		KOStillPressed = false;
		KLStillPressed = false;
		//////////////////////////////////////////////////////////////////////
		KZStillPressed = false;
		KXStillPressed = false;

		m_WasScaled = false;

		EyeX = 5.0f;
		EyeY = 5.0f;
		EyeZ = 5.0f;

		m_ScaleFactorX=1.0f;
		m_ScaleFactorY=1.0f;
		m_ScaleFactorZ=1.0f;

		m_RotateFactorX=0.0f;
		m_RotateFactorY=0.0f;
		m_RotateFactorZ=0.0f;

		m_TranslateFactorX=0.0f;
		m_TranslateFactorY=0.0f;
		m_TranslateFactorZ=0.0f;

		Eye = C_Vector3f(0.0f, 1.0f, 6.0f);
		At	= C_Vector3f(0.0f, 1.0f, 0.0f);
		Up	= C_Vector3f(0.0f, -1.0f, 0.0f);
	}

//Destructor//
	C_ApplicationBase::~C_ApplicationBase()
	{				
		m_Input->ShutDown();
	}																								                   	

	
	
	HINSTANCE HInst;
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
	
		HRESULT result; 
		WNDCLASSEXW wcex;

		//Esto es necesario para que la creación del input sea posible (3 dias encontrar este miserable error ¬_¬, aun debo entender el porqué)
		HInst = GetModuleHandle(NULL);

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = HInst;
		wcex.hIcon = 0;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = 0;
		wcex.lpszMenuName = 0;
		wcex.lpszClassName = (L"ODIN_ENGINE_APP_CLASS");
		wcex.hIconSm = 0;

		RegisterClassExW(&wcex);


		/*HWND hWnd = CreateWindowW((L"ODIN_ENGINE_APP_CLASS"), (L"VENTANITA"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, Height, width, nullptr, nullptr, 0, nullptr);
			*/


		HWND hWnd = CreateWindowW((L"ODIN_ENGINE_APP_CLASS"), (L"VENTANITA"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, Height, width, nullptr, nullptr, HInst, nullptr);


		ShowWindow(hWnd, SW_SHOW);
		UpdateWindow(hWnd);

		RECT clientRect;	
		::GetClientRect(hWnd, &clientRect);

		//Create Input Object 

		m_Input = new OEInput; 


		//Initialize the input object

	

		g_GraphicsAPI().startUp();

		//Inicializa DirectX
		g_GraphicsAPI().Init(reinterpret_cast<void*>(hWnd),
			               clientRect.right - clientRect.left, 
			               clientRect.bottom - clientRect.top, 
			               false);
	

		result = m_Input->Initialize(HInst, hWnd, width, Height);

		if (FAILED(result))
		{

		}


		OnInit();
		InitResources(width, Height);
		
	}

	void C_ApplicationBase::Destroy()
	{
		//Destroy input
		m_Input->ShutDown();
		delete m_Input;
		m_Input = 0;

		//Destruye DirectX
		g_GraphicsAPI().shutDown();
		OnDestroy();

	}


	int C_ApplicationBase::Run(int width, int Height)
	{
		Init(Height, width);
		int a = 0;
		int b = 0;
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
			
			
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_1_Pressed() && K1StillPressed == false)
			{
				K1StillPressed = true;
				if (m_WasScaled == false)
				{
					m_ScaleFactorX = 0.5;
					m_ScaleFactorY = 0.5;
					m_ScaleFactorZ = 0.5;
					m_WasScaled = true;
				}
				else if(m_WasScaled ==true)
				{
					m_ScaleFactorX = 1.0;
					m_ScaleFactorY = 1.0;
					m_ScaleFactorZ = 1.0;
					m_WasScaled = false;

				}


				std::cout << "uno presionado"<<std::endl;
			}
			else if (m_Input->Is_1_Pressed() == false)
			{
				K1StillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_2_Pressed() && K2StillPressed == false)
			{
				K2StillPressed = true;
				if (m_WasScaled == false)
				{
					m_ScaleFactorX = 1.2;
					m_ScaleFactorY = 1.2;
					m_ScaleFactorZ = 1.2;
					m_WasScaled = true;
				}
				else if (m_WasScaled == true)
				{
					m_ScaleFactorX = 1.0;
					m_ScaleFactorY = 1.0;
					m_ScaleFactorZ = 1.0;
					m_WasScaled = false;

				}


				std::cout << "uno presionado" << std::endl;
			}
			else if (m_Input->Is_2_Pressed() == false)
			{
				K2StillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////			
			if (m_Input->Is_W_Pressed() && KWStillPressed == false)
			{
				KWStillPressed = true;
				if (m_RotateFactorX < 6.28319)
				{
					m_RotateFactorX += 0.05;
				}
				std::cout << m_RotateFactorX <<std::endl;
			}
			else if (m_Input->Is_W_Pressed() == false)
			{
				KWStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_S_Pressed() && KSStillPressed == false)
			{
				KSStillPressed = true;
				if (m_RotateFactorX >= -6.28319)
				{
					m_RotateFactorX -= 0.05;
				}
				std::cout << m_RotateFactorX << std::endl;
			}
			else if (m_Input->Is_S_Pressed() == false)
			{
				KSStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_A_Pressed() && KAStillPressed == false)
			{
				KAStillPressed = true;
				if (m_RotateFactorY >= -6.28319)
				{
					m_RotateFactorY -= 0.05;
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_A_Pressed() == false)
			{
				KAStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_D_Pressed() && KDStillPressed == false)
			{
				KDStillPressed = true;
				if (m_RotateFactorY < 6.28319)
				{
					m_RotateFactorY += 0.05;
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_D_Pressed() == false)
			{	
				KDStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			

			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_K_Pressed() && KKStillPressed == false)
			{
				KKStillPressed = true;
				if (EyeX < 10)
				{
					Eye.X += 0.1;
					At.X += 0.1;
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_K_Pressed() == false)
			{
				KKStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_J_Pressed() && KJStillPressed == false)
			{
				KJStillPressed = true;
				if (EyeX > -10)
				{
					Eye.X -= 0.1;
					At.X  -= 0.1;
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_J_Pressed() == false)
			{
				KJStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_O_Pressed() && KOStillPressed == false)
			{
				KOStillPressed = true;
				if (EyeY < 10)
				{
					Eye.Y += 0.1;
					At.Y  += 0.1;
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_O_Pressed() == false)
			{
				KOStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_L_Pressed() && KLStillPressed == false)
			{
				KLStillPressed = true;
				if (EyeY > -10)
				{
					Eye.Y -= 0.1;
					At.Y -= 0.1;
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_L_Pressed() == false)
			{
				KLStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_Z_Pressed() && KZStillPressed == false)
			{
				KZStillPressed = true;
				if (EyeZ < 10)
				{
					Eye.Z -= 0.1;
					//At.Y = 
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_Z_Pressed() == false)
			{
				KZStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_X_Pressed() && KXStillPressed == false)
			{
				KXStillPressed = true;
				if (EyeZ < 10)
				{
					Eye.Z += 0.1;
					//At.Y = 
				}
				std::cout << m_RotateFactorY << std::endl;
			}
			else if (m_Input->Is_X_Pressed() == false)
			{
				KXStillPressed = false;
			}

			

			m_Input->Is_ScrollWheelMouse_Moving(a);
			a += a;
			if (Eye.Z > -100 && Eye.Z < 100)
			{
				Eye.Z += a; 
			}


			std::cout << a<<std::endl;

			
			
			//////////////////////////////////////////////////////////////////////////
			if (m_Input->Is_LeftMouseButton_Pressed()==true &&LBMStillPressed == false)
			{
				LBMStillPressed = true;
				a+= 5;
				m_Input->GetMouseLocation(m_MouseX, m_MouseY);
				std::cout << "click izquierdo"<<"X= "<< m_MouseX <<"y= "<< m_MouseY <<std::endl;
				
			}
			else if (m_Input->Is_LeftMouseButton_Pressed() == false)
			{
				LBMStillPressed = false;
			}
			//////////////////////////////////////////////////////////////////////////

			
		}

		Destroy();

		return (int)msg.wParam;
	}

	void C_ApplicationBase::Update(float)
	{
		int mouseX = 0;
		int mouseY = 0;



		m_Input->Frame();

		//Get the location of the mouse from the input object
		m_Input->GetMouseLocation(m_MouseX, m_MouseY);


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