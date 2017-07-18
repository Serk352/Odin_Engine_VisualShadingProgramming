#pragma once


#include "OdinPlatformDefines.h"

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_PS4
	#include <scebase.h>
#endif


namespace OE_SDK
{
	/************************************************************************/
	/* Basic Unsigned Types													*/
	/************************************************************************/
	typedef unsigned char  uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;

#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC
	typedef unsigned __int64  uint64;
#else
	typedef unsigned long uint64;
#endif

	/************************************************************************/
	/* Basic Signed Types													*/
	/************************************************************************/
	typedef signed char  int8;
	typedef signed short int16;
	typedef signed int   int32;
#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC
	typedef signed __int64  int64;
#else
	typedef signed long  int64;
#endif


	/************************************************************************/
	/* 128 bits variable                                                    */
	/************************************************************************/

	/************************************************************************/
	/* pack(4) struct
		{
		char var; 8bits = byte 
		char var2;
		int var3;
		}
		
		por default se hace un pack de (4) bytes. Esto en memoria son dos bytes vacíos y dos bytes en uso
		[0x0000FFFF]


		struct
		{
		int var;
		char var2;
		char var3;			8 bytes
		short unused;
		}	



		*/
	/************************************************************************/

	MS_ALIGN(16) class QWord
	{
	public:
		uint64 m_lower;
		int64 m_upper;


		/************************************************************************/
		/*
		*@Brief The cast operator for casting/truncating to 64 bits.
		*@returns The lower 64 bits of the value
		*/
		/************************************************************************/

		operator int64 () const
		{
			return m_lower;
		}


		/************************************************************************/
		/*
		*@brief   The default constructor for the QWord class
		*/
		/************************************************************************/
		QWord() : m_lower(0), m_upper(0)
		{

		}

		QWord(bool from) : m_lower(from), m_upper(0)
		{

		}

		QWord(uint8 from) : m_lower(from), m_upper(0)
		{

		}


		QWord(int8 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(uint16 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int16 from) : m_lower(from), m_upper(0)
		{

		}



		QWord(uint32 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int32 from) : m_lower(from), m_upper(0)
		{

		}



		QWord(uint64 from) : m_lower(from), m_upper(0)
		{

		}

		QWord(int64 from) : m_lower(from), m_upper(0)
		{

		}



		QWord(float from) : m_lower((uint64)from), m_upper(0)
		{

		}

		QWord(double from) : m_lower((uint64)from), m_upper(0)
		{

		}

	} GCC_ALIGN(16);

	typedef QWord int128;
	typedef QWord uint128;


	/************************************************************************/
	/* Character Types                                                                     */
	/************************************************************************/

#if ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC || ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_PS4
	typedef wchar_t  WCHAR;
#else
	typedef unsigned short  WCHAR;
#endif
	typedef char	ANSICHAR;   //ANSI character type
	typedef WCHAR	UNICHAR;	//UNICODE character type 

	/************************************************************************/
	/* Null data type                                                       */
	/************************************************************************/

	typedef int32    TYPE_OF_NULL;


	/************************************************************************/
	/*	SIZE_T  is an architecture dependant data type						*/
	/************************************************************************/

#if ODIN_ENGINE_ARCH_TYPE == ODIN_ENGINE_ 
	typedef unsigned __int64  SIZE_T;
#else
	typedef unsigned long     SIZE_T;
#endif
}
