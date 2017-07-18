#include "OdinEngineTimer.h"

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include "windows.h"
#endif

namespace OE_SDK
{
	struct C_Timer::DataTimer
	{
		LARGE_INTEGER m_Frequency;
		LARGE_INTEGER m_Count;
	};

	C_Timer::C_Timer()
	{
		m_Data = new C_Timer::DataTimer;
	}

	C_Timer::~C_Timer()
	{
		delete m_Data;
		m_Data = nullptr;
	}

	void C_Timer::Reset()
	{
		QueryPerformanceFrequency(&m_Data->m_Frequency);
		QueryPerformanceCounter(&m_Data->m_Count);
	}

	float C_Timer::GetMillisecondsTime()
	{
		LARGE_INTEGER actualTime;
		QueryPerformanceCounter(&actualTime);

		float time = (float)((1000 * (actualTime.QuadPart - m_Data->m_Count.QuadPart)) / m_Data->m_Frequency.QuadPart);

		return time;
	}

	float C_Timer::GetMicrosecondsTime()
	{
		LARGE_INTEGER actualTime;
		QueryPerformanceCounter(&actualTime);

		float time = (float)((1000000 * (actualTime.QuadPart - m_Data->m_Count.QuadPart)) / m_Data->m_Frequency.QuadPart);

		return time;
	}
}
