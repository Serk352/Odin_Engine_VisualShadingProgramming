/************************************************************************/
/**
* @File OdinPlatformDefines.h
* @Author: Ramiro Flores
* @Date:	25/05/2017
* @This file while include Platform's definition
* @Este archivo incluir� la definici�n de las plataformas
*/
/************************************************************************/

#pragma once

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32

#	if defined( ODIN_ENGINE_VSP_STATIC_LIB)
#		define ODIN_ENGINE_VSP_API_UTILITY_EXPORT
#	elif defined(ODIN_ENGINE_VSP_API_UTILITY_EXPORTS)
#			define ODIN_ENGINE_VSP_API_UTILITY_EXPORT __declspec( dllexport)
#	else	
#		if defined (__MINGW32__)	
#			define ODIN_ENGINE_VSP_API_UTILITY_EXPORT
#		else
#			define ODIN_ENGINE_VSP_API_UTILITY_EXPORT __declspec( dllimport )
#		endif
#	endif
#endif
	