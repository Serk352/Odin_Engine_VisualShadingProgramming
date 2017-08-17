#pragma once
#include "OEPrerequisitesCore.h"
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

namespace OE_SDK
{
	//Abstract Direct Input Objects to only be used in .cpp
	class	ODIN_ENGINE_COREUTILITY_EXPORT OEInput
	{
	public: 
		OEInput();
		~OEInput();

		//////////////////////////////////////////////////////////////////////////
		bool Initialize(HINSTANCE hInstance, HWND hwnd, int widht, int heigt);
		void ShutDown();
		bool Frame();
		//////////////////////////////////////////////////////////////////////////
		//Check for some keyboard keys 
		bool Is_Escape_Pressed();

		bool Is_W_Pressed();
		bool Is_S_Pressed();
		bool Is_A_Pressed(); 
		bool Is_D_Pressed();

		//Zoom Camara
		bool Is_Z_Pressed(); //Acercar
		bool Is_X_Pressed(); //Alejar
		//Mover en X
		bool Is_K_Pressed();
		bool Is_J_Pressed();
		//Mover en Y
		bool Is_O_Pressed();
		bool Is_L_Pressed();


		bool Is_1_Pressed();
		bool Is_2_Pressed();

		//Mouse buttons
		bool Is_LeftMouseButton_Pressed();
		bool Is_RightMouseButton_Pressed();

		void GetMouseLocation(uint32& MouseX, uint32& MouseY);

	private:
		//////////////////////////////////////////////////////////////////////////
		bool ReadKeyboard();
		bool ReadMouse();
		void ProcessInput();

		//Interfaces para el uso de DirectInput
		//Interfaces for use  of Direct Input
		IDirectInput8* m_DirectInput;
		IDirectInputDevice8* m_Keyboard;
		IDirectInputDevice8* m_Mouse;

		//////////////////////////////////////////////////////////////////////////
		unsigned char  m_KeyboardState[256];
		DIMOUSESTATE m_MouseState; 

		uint32 m_screenWidth;
		uint32 m_screenHeight;

		int32 m_mouseX;
		int32 m_mouseY;

	public:
		bool m_leftMouseButtonState;
		bool m_PinLeft;
		bool m_RightMouseButtonState;

	};
}