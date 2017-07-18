#pragma once

/************************************************************************/
/* Includes																*/
/************************************************************************/
#include "PrerequisitesUtil.h"

namespace OE_SDK
{
	class ODIN_ENGINE_UTILITY_EXPORT C_Timer
	{
	public:
		void Reset();
		float GetMillisecondsTime();
		float GetMicrosecondsTime();

	public:
		C_Timer();
		~C_Timer();

	public:
		struct DataTimer;
		DataTimer* m_Data;
	};
}
