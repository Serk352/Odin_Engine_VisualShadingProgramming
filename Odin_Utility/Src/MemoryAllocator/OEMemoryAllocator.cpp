#include "PrerequisitesUtil.h"


namespace OE_SDK
{
	ODIN_ENGINE_THREADLOCAL uint64 MemoryCounter::m_Allocs = 0;
	ODIN_ENGINE_THREADLOCAL uint64 MemoryCounter::m_Frees = 0;
}