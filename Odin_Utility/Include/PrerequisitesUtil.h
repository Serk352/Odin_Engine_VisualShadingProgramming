#pragma once

//If we are compiling with Visual Studio
#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC
//TODO:  This is not deactivated anywhere, therefore it applies to any file that includes this header.
//     - Right now I don't have an easier way to apply these warnings globally so I'm keeping it this way.

//Secure versions aren't multi platform, so we won't be using them
#define _CRT_SECURE_NO_WARNINGS

//Disable: "<type> needs to have DLL interface to be used by clients'
//Happens on STL member variables which are not public therefore is ok
#pragma warning (disable: 4251)

//Disable: 'X' Function call with parameters that may be unsafe
#pragma warning(disable: 4996) 

//Disable: decorated name length exceeded, name was truncated. Happens with really long type names.
//Even fairly standard use of std::unordered_map with custom parameters, meaning I can't really do 
//much to avoid it. It shouldn't effect execution but might cause problems if you compile library
//with one compiler and use it in another.
#pragma warning(disable: 4503)

//Disable: nonstandard extension used: override specifier 'keyword'. Happens when a keyword was used
//that is not in the C++ standard, for example, one of the override specifiers that also works under /clr.
#pragma warning(disable : 4481)
#endif

#include "OdinPlatformDefines.h"
#include "OEPlatformTypes.h"
#include "OEMacros.h"
#include "OEMemoryAllocator.h"
#include "OESTDHeader.h"
#include "OEString.h"
#include "OEFileManager.h"
#include "MathUtil.h"

