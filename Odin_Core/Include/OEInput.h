#pragma once
#include "PrerequisitesCore.h"
#include <dinput.h>

namespace OE_SDK
{
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
		bool IsEscapePressed();
		void GetMouseLocation(int&, int&);

	private:
		//////////////////////////////////////////////////////////////////////////
		bool ReadKeyboard();
		bool ReadMouse();
		void ProcessInput();

		//Interfaces para el uso de DirectInput
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

	};
}