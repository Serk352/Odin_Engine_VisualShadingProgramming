#include "OEInput.h"


namespace OE_SDK
{

	OEInput::OEInput()
	{
		m_DirectInput = nullptr;
		m_Keyboard = nullptr;
		m_Mouse = nullptr;
	}

	OEInput::~OEInput()
	{}

	bool OEInput::Initialize(HINSTANCE hInstance, HWND hwnd, int widht, int heigt)
	{

		HRESULT result;

		m_screenWidth = widht;
		m_screenHeight = heigt;
		
		m_mouseX = 0;
		m_mouseY = 0;

		//Initialize the main DirectInput interface.
		//DirectInputCreateEx(hInstance, DIRECTINPUT_VERSION, )
		result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_DirectInput, NULL);
		if (FAILED(result))
		{
			return false;
		}
		//Initialize the DirectInput interface for the keyboard
		result = m_DirectInput->CreateDevice(GUID_SysKeyboard, &m_Keyboard, NULL);
		if (FAILED(result))
		{
			return false;
		} 

		//Set the data format, In this case since it is a Keyboard we can use the predefined data format
		result = m_Keyboard->SetDataFormat(&c_dfDIKeyboard);
		if (FAILED(result))
		{
			return false;
		}

		//Set the coperative level of the keyboard to not share with other programs
		result = m_Keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
		if (FAILED(result))
		{
			return false;
		}

		//Acquire the keyboard
		result = m_Keyboard->Acquire();
		if (FAILED(result))
		{
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		/////////////////////////Mouse/////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		
		//Initialize the DirectInput interface for the mouse
		result = m_DirectInput->CreateDevice(GUID_SysMouse, &m_Mouse, NULL);
		if (FAILED(result))
		{
			return false;
		}


		//Set the data format forthe mouse using the pre-defined mouse data format.
		result = m_Mouse->SetDataFormat(&c_dfDIMouse);
		if (FAILED(result))
		{
			return false;
		}

		//Set teh cooperative level of the mouse to share with other programs.
		result = m_Mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
		if (FAILED(result))
		{
			return false;
		}

		//Acquire the mouse
		result = m_Mouse->Acquire();
		if (FAILED(result))
		{
			return false;
		}

		return true;

	}

	void OEInput::ShutDown()
	{
		//Release the mouse

		if (m_Mouse)
		{
			m_Mouse->Unacquire();
			m_Mouse->Release();
			m_Mouse = 0;
		}

		//Release the Keyboard
		if (m_Keyboard)
		{
			m_Keyboard->Unacquire();
			m_Keyboard->Release();
			m_Keyboard = 0;
		}

		//Release the main interface to DirectInput
		if (m_DirectInput)
		{
			m_DirectInput->Release();
			m_DirectInput = 0;
		}

	}

	bool OEInput::Frame()
	{
		bool result;

		//Read the current state of the keyboard
		result = ReadKeyboard();
		if (FAILED(result))
		{
			return false;
		}
		//Read the current state fo the mouse
		result = ReadMouse();
		if (FAILED(result))
		{
			return false;
		}

		//Process the changes in the mouse and keyboard
		ProcessInput();

		return true; 

	}


	//Template function for all the key pressed in the keyboar
	bool OEInput::Is_Escape_Pressed()
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_ESCAPE] & 0x80)
		{
			return true;
		}
		return false;
	}
	bool OEInput::Is_W_Pressed() 
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_W] & 0x80)
		{
			return true;
		}
		return false;
	}
	bool OEInput::Is_S_Pressed() 
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_S] & 0x80)
		{
			return true;
		}
		return false;
	}
	bool OEInput::Is_A_Pressed() 
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_A] & 0x80)
		{
			return true;
		}
		return false;
	}
	bool OEInput::Is_D_Pressed() 
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_D] & 0x80)
		{
			return true;
		}
		return false;
	}
	bool OEInput::Is_1_Pressed()
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_1] & 0x80)
		{
			return true;
		}
		return false;
	}
	bool OEInput::Is_2_Pressed()
	{	
		//Do a bitwise and on the keyboard state to check if the scape key is currently being pressed.
		if (m_KeyboardState[DIK_2] & 0x80)
		{
			return true;
		}
		return false;
	}

	void OEInput::GetMouseLocation(int& MouseX, int& MouseY)
	{
		MouseX = m_mouseX;
		MouseY = m_mouseY;
		return;
	}



	bool OEInput::ReadKeyboard()
	{
		HRESULT result;
		//Read the keyboard device 
		result = m_Keyboard->GetDeviceState(sizeof(m_KeyboardState), (LPVOID)&m_KeyboardState);
		if (FAILED(result))
		{
			//If the keyboard lost focus or was not acquired then try to get control back
			if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
			{
				m_Keyboard->Acquire();
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	bool OEInput::ReadMouse()
	{
		HRESULT result;
		//Read the mouse device
		result = m_Mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_MouseState);
		if (FAILED(result))
		{
			//If the mouse lost focus or was not acquired then try to get control back
			if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
			{
				m_Mouse->Acquire();
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	void OEInput::ProcessInput()
	{
		//Update the location of the mouse cursor based on the change of the mouse locantion during the frame
		m_mouseX += m_MouseState.lX;
		m_mouseY += m_MouseState.lY;

		//Ensure the mouse locantion doesn´t exceed the screen widht or height
		if (m_mouseX < 0) 
		{ 
			m_mouseX = 0; 
		}
		if (m_mouseY < 0)
		{
			m_mouseY = 0; 
		}

		//(m_mouseX < 0) ? m_mouseX = 0 : ;
		//(m_mouseY < 0) ? m_mouseY= 0 : ;

		if (m_mouseX > m_screenWidth)
		{
			m_mouseX = m_screenWidth;
		}
		if (m_mouseY > m_screenHeight)
		{
			m_mouseY = m_screenHeight;
		}
		return;
	}

}