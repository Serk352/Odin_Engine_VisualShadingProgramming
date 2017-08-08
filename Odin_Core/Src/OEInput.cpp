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
		result = DirectInput8Create(hInstance, 0x0800, IID_IDirectInput8, (void**)&m_DirectInput, NULL);
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
	
	}

	bool OEInput::IsEscapePressed()
	{}
	void OEInput::GetMouseLocation(int& , int&)
	{}



	bool OEInput::ReadKeyboard()
	{}
	bool OEInput::ReadMouse()
	{}
	void OEInput::ProcessInput()
	{}

}