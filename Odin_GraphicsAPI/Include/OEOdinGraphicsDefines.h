/************************************************************************/
/**
* @File OdinPlatformDefines.h
* @Author: Ramiro Flores
* @Date:	13/09/2016
* @This file while include Platform's definition
* @Este archivo incluirá la definición de las plataformas
*/
/************************************************************************/

#pragma once

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32

#	if defined( ODIN_ENGINE_GRAPHICS_API_STATIC_LIB)
#		define ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT
#	elif defined(ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORTS)
#			define ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT __declspec( dllexport)
#	else	
#		if defined (__MINGW32__)	
#			define ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT
#		else
#			define ODIN_ENGINE_GRAPHICS_API_UTILITY_EXPORT __declspec( dllimport )
#		endif
#	endif
#endif
