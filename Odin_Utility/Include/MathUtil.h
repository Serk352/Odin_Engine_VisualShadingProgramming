#pragma once

#include "PrerequisitesUtil.h"

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
#	include "PlatformMath.h"
namespace OE_SDK
{
	typedef PlatformMath Math;
}
#else
#	pragma error "Math no se ha definido para esta plataforma (Math.h)"
#endif
