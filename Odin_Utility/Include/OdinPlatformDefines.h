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


//Defines


#define ODIN_ENGINE_PLATFORM_WIN32	1					//Windows PLatform
#define ODIN_ENGINE_PLATFORM_LINUX	2					//Linux Platform
#define ODIN_ENGINE_PLATFORM_APPLE	3					//Apple Platform
#define ODIN_ENGINE_PLATFORM_PS4	4					//PlayStation 4 Platform

#define ODIN_ENGINE_COMPILER_MSVC	1					//Visual Studio Compiler
#define ODIN_ENGINE_COMPILER_GNUC	2					//GCC Compiler
#define ODIN_ENGINE_COMPILER_INTEL	3					//Intel Compiler
#define ODIN_ENGINE_COMPILER_CLANG	4					//Clang Compiler

#define ODIN_ENGINE_ARCHITECTURE_x86_32			1					//Intel x86 32 bits
#define ODIN_ENGINE_ARCHITECTURE_x86_64			2					//Intel x86 64 bits


#define ODIN_ENGINE_ENDIAN_LITTLE	1					//Little Endian
#define ODIN_ENGINE_ENDIAN_BIG		2					//Big Endian

#define ODIN_ENGINE_Endian_ge_endian_little

#define ODIN_ENGINE_editor_build   1


/************************************************************************/
/* Compiler type and version											*/
/* Tipo y version de compilador											*/
/************************************************************************/


#if defined (_MSC_VER)														//Visual Studio
	#define ODIN_ENGINE_COMPILER ODIN_ENGINE_COMPILER_MSVC						
	#define ODIN_ENGINE_COMP_VER _MSC_VER							
	#define ODIN_ENGINE_THREADLOCAL  __declspec(thread)				
#elif defined(__GNUC__)
	#define ODIN_ENGINE_COMPILER GE_COMPILER_GNUC
	#define ODIN_ENGINE_COMP_VER	(((__GNUC__)*100) + (__GNUC_MINOR_*10) + __GNUC_PATCHLEVEL__)
	#define ODIN_ENGINE_THREADLOCAL  __thread
#elif defined(__INTEL_COMPILER )
	#define ODIN_ENGINE_COMPILER ODIN_ENGINE_COMPILER_INTEL
	#define ODIN_ENGINE_COMP_VER	__INTEL_COMPILER
#elif defined(__clang__)
#define ODIN_ENGINE_COMPILER GE_COMPILER_CLANG
#define ODIN_ENGINE_COMP_VER	__clang_major__
#define ODIN_ENGINE_THREADLOCAL  __thread
#else
	#pragma error "no know compiler."

#endif

/************************************************************************/
/*See if we can use _forceinline or if we need to use __inline instead  */
/************************************************************************/

#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC
	#if ODIN_ENGINE_COMP_VER >= 1200
		#define FORCEINLINE __forceinline
		#ifndef RESTRICT
			#define RESTRICT __restrict
		#endif
	#endif

#elif defined (__WINGW32__)
	#if !defined(FORCEINLINE)
		#define FORCEINLINE __forceinline
		#ifndef RESTRICT
			#define RESTRICT __restrict
		#endif
	#endif

#else
	#define FORCEINLINE __inline
	#ifndef RESTRICT
		#define RESTRICT __restrict
	#endif	
#endif



/************************************************************************/
/* Finds the current platform											*/
/************************************************************************/
#if defined(__WIN32__) || defined(_WIN32)
#	define ODIN_ENGINE_PLATFORM ODIN_ENGINE_PLATFORM_WIN32	
#elif defined (__APPLE_CC__ )
	#define ODIN_ENGINE_PLATFORM ODIN_ENGINE_PLATFORM_APPLE
#elif defined
#	define ODIN_ENGINE_PLATFORM ODIN_ENGINE_PLATFORM_PS4
#else
#	define  ODIN_ENGINE_PLATFORM ODIN_ENGINE_PLATFORM_LINUX
#endif


/************************************************************************/
/* Find the architecture type											*/
/************************************************************************/

#if defined(__x86_64__) || defined (_M_X64)
	#define ODIN_ENGINE_ARCH_TYPE ODIN_ENGINE_ARCHITECTURE_X86_64
#else
	#define ODIN_ENGINE_ARCH_TYPE ODIN_ENGINE_ARCHITECTURE_x86_32
#endif

/************************************************************************/
/* Memory Aligment macros												*/
/************************************************************************/


#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC
	#define MS_ALIGN(n) __declspec(align(n))
	#ifndef GCC_PACK
		#define GCC_PACK(n)
	#endif
	#ifndef GCC_ALIGN
		#define GCC_ALIGN(n)
	#endif

#elif (ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_GNUC && ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_PS4 )
	#define MS_ALIGN(n)
	#define GCC_ALIGN(n)	
	#define GCC_ALIGN(n)  __attribute__( (__aligned__(n)) )
#else
	#define MS_ALIGN(n)
	#define GCC_ALIGN(n)  __attribute__( (packed, aligned(n)) )
	#define GCC_ALIGN(n)  __attribute__( (aligned(n)) )
#endif


/**********************************************************************************************/
/* For throw override (deprecated on c++11 but Visual Studio does not have handle noexcept    */
/**********************************************************************************************/
#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC
	#define _NOEXCEPT noexcept
#elif ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_INTEL
	#define _NOEXCEPT noexcept
#elif ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_GNUC
	#define _NOEXCEPT noexcept
#else
	#define _NOEXCEPT
#endif



/************************************************************************/
/* Windows specific sttings												*/
/************************************************************************/

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32

	#if defined( ODIN_ENGINE_UTILITY_STATIC_LIB)
		#define ODIN_ENGINE_UTILITY_EXPORT
	#else
		#if defined(ODIN_ENGINE_UTILITY_EXPORTS)
			#define ODIN_ENGINE_UTILITY_EXPORT __declspec( dllexport)
		#else	
			#if defined (__MINGW32__)	
				#define ODIN_ENGINE_UTILITY_EXPORT
			#else
				#define ODIN_ENGINE_UTILITY_EXPORT __declspec( dllimport )
			#endif
		#endif
	#endif

//si el linker agrego la libreria pero dce que no esta incluido es que no se esta utilizando como importación.

	//Win32 compilers use _DEBUG for specifying debug builds  
	#if defined (_DEBUG) || defined(DEBUG)
		#define ODIN_ENGINE_DEBUG_MODE 1
	#else
		#define ODIN_ENGINE_DEBUG_MODE 0
	#endif

	#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_INTEL
		#define ODIN_ENGINE_THREADLOCAL __declspec(thread)
	#endif	
#endif // ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32

/********************/



#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_LINUX || ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_APPLE
//

	#if defined (ODIN_ENGINE_GCC_VISIBILITY)
		#Define ODIN_ENGINE_UTILITY_EXPORT  __attribute__ ((visibility("default")))
	#else
		#define ODIN_ENGINE_UTILITY_EXPORT
	#endif

	#define stricmp strcasecmp

//if we are on a Debug build

#if defined (_DEBUG) || defined (DEBUG)
		#define ODIN_ENGINE_DEBUG_MODE 1
	#else
		#define ODIN_ENGINE_DEBUG_MODE 0
	#endif

	#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_INTEL
		#define ODIN_ENGINE_THREADLOCAL __thread
	#endif
#endif

/************************************************************************/
/* PS4                                                                     */
/************************************************************************/

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_PS4

	#if defined (ODIN_ENGINE_STATIC_LIB)
		#define ODIN_ENGINE_UTILITY_EXPORT
	#else
		#if defined (ODIN_ENGINE_UTILITY_EXPORTS)
			#define ODIN_ENGINE_UTILITY_EXPORT __declspec( dllexport )
		#else
#if defined (__MINGW32__)
#define ODIN_ENGINE_UTILITY_EXPORT
#else#define ODIN_ENGINE_UTILITY_EXPORT	__declspec( dllimport)
#endif
#endif
#endif



#if defined (_DEBUG) || defined (DEBUG)
#define ODIN_ENGINE_DEBUG_MODE 1
#else
#define ODIN_ENGINE_DEBUG_MODE 0
#endif
#endif



/************************************************************************/
/* DEFINITION of debug macros                                           */
/************************************************************************/


#if ODIN_ENGINE_DEBUG_MODE
#define ODIN_ENGINE_DEBUG_ONLY (x) x
#define ODIN_ENGINE_ASSERT(x) assert(x)

#else
#define ODIN_ENGINE_DEBUG_ONLY (x)
#define ODIN_ENGINE_ASSERT (x)
#endif