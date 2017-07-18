#pragma once


/************************************************************************/
/*  IF we are on a Borland compiler  (C++ Builder)                      */
/************************************************************************/

#ifdef  __BORLAND__
#define  __STD_ALGORITHM
#endif

/************************************************************************/
/* C type objects                                                       */
/************************************************************************/



#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

/************************************************************************/
/* For memory management                                                */
/************************************************************************/

#include <memory>

/************************************************************************/
/* STL Containers                                                       */
/************************************************************************/

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>
#include <fstream>

/************************************************************************/
/*                                                                      */
/************************************************************************/

#if(ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_GNUC)
#if ODIN_ENGINE_COMP_VER >= 430
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#elif (ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_PS4)
#include <unordered_map>
#include <unordered_set>
#else
#include <ext/hash_map>
#include <ext/hash_set>

#endif
#else

#if (ODIN_ENGINE_COMPILER == ODIN_ENGINE_COMPILER_MSVC) && ODIN_ENGINE_COMP_VER >= 1600 // VC++ 10.0 or higher
#include <unordered_map>
#include <unordered_set>
#else
#include <hash_set>
#include <hash_map>

#endif
#endif

/************************************************************************/
/* STL algorithms & functions                                           */
/************************************************************************/


#include <algorithm>
#include <functional>
#include <limits>

/************************************************************************/
/* C++ stream stuff                                                     */
/************************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <ostream>

#ifdef __BORLAND__
namespace OE_SDK
{
	using namespace std;
}
#endif

/************************************************************************/
/* C type and Stats                                                     */
/************************************************************************/

extern "C"
{
	#include <sys/types.h>
	#include <sys/stat.h>
}


/************************************************************************/
/* Windows Specific														*/
/************************************************************************/

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_WIN32
//undefined min & max

	#undef min
	#undef max

	#if !defined(NOMINMAX) && defined(_MSC_VER)
		#define  NOMINMAX			//Required to stop windows.h mwessing up std::min
	#endif
	#if defined (__MINGW32__)
		#include <unistd.h>
	#endif
#endif

/************************************************************************/
/* Linux Specifics                                                      */
/************************************************************************/

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_LINUX
	extern "C"
	{
		#include <unistd.h>
		#include <dlfcn.h>
	}
#endif

	/************************************************************************/
	/* Apple Specifics                                                      */
	/************************************************************************/

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_APPLE
	extern "C"
	{
		#include <unistd.h>
		#include <sys/param.h>
		#include <CoreFoundation/CoreFoundation.h>
	}

#endif



	/************************************************************************/
	/* PS4 Specifics                                                        */
	/************************************************************************/

#if ODIN_ENGINE_PLATFORM == ODIN_ENGINE_PLATFORM_PS4
	extern "C"
	{
		#include <unistd.h>
		#include <sys/param.h>
	}

#endif


	namespace OE_SDK
	{
		template <typename T, typename A = StdAlloc<T>>
		using Deque = std::deque<T, A>;


		template <typename T, typename A = StdAlloc<T>>
		using Vector = std::vector<T, A>;


		template <typename T, typename A = StdAlloc<T>>
		using List = std::list<T, A>;


		template <typename T, typename A = StdAlloc<T>>
		using Stack = std::stack<T,  std::deque<T,A>>;


		template <typename T, typename A = StdAlloc<T>>
		using Queue = std::queue < T, std::deque < T, A >>;


		template <typename T, typename P = std::less<T>, typename A = StdAlloc<T>>
		using Set = std::set <T, P, A>;


		template <typename K, typename V, typename P = std::less<K>, typename A = StdAlloc<std::pair<const K, V>>>
		using Map = std::map < K, V, P, A>;

		template <typename K, typename V, typename P = std::less<K>, typename A = StdAlloc<std::pair<const K, V>>>
		using MultiMap = std::multimap< K, V, P, A>;

		template <typename T, typename H = std::hash<T>, typename C = std::equal_to<T>, typename A = StdAlloc<T>>
		using UnorderedSet = std::unordered_set<T, H, C, A>;

		template <typename K, typename V, typename H = std::hash<K>, typename C = std::equal_to<K>, typename A = StdAlloc<std::pair <const K, V>>>
		using UnorderedMap = std::unordered_map<K, V, H, C, A>;

		template <typename K, typename V, typename H = std::hash<K>, typename C = std::equal_to<K>, typename A = StdAlloc<std::pair <const K, V>>>
		using UnorderedMultimap = std::unordered_multimap<K, V, H, C, A>;

		template<typename E, typename T = std::char_traits<E>>
		using FStream = std::basic_fstream<E, T>;

		typedef FStream<char> FileStream;
	//	Vector<char> m_VectorChars;



		template <typename T>
		using SPtr = std::shared_ptr<T>;


		template <typename T, typename Alloc = GenAlloc>
		using UPtr = std::unique_ptr<T, decltype(&OE_delete<T, Alloc>)>;  //Delete

		template<class Type, class AllocCategory, class... Args>
		SPtr<Type> ge_shared_ptr_new(Args&&... args)
		{
			return std::allocate_shared<Type>(StdAlloc<Type, AllocCategory>(), std::forward<Args>(args)...);
		}
		

		template<class Type, class... Args>
		SPtr<Type> ge_shared_ptr_new(Args&&... args)
		{
			return std::allocate_shared<Type>(StdAlloc<Type, GenAlloc>(), std::forward<Args>(args)...);
		}


		template<class Type, class MainAlloc = GenAlloc, class PtrDataAlloc = GenAlloc>
		SPtr<Type> ge_share_ptr(Type* data)
		{
			return std::shared_ptr<Type>(data &OE_delete<Type, MainAlloc>, StdAlloc<Type, PtrDataAlloc>());
		}


		template<class Type, class Alloc = GenAlloc>
		UPtr<Type, Alloc> ge_unique_ptr(Type* data)
		{
			return std::unique_ptr<Type, decltype(&OE_delete<Type, Alloc>)>(data, OE_delete<Type, Alloc>);
		}

		template<class Type, class Alloc, class... Args>
		UPtr<Type> ge_unique_ptr_new(Args &&... args)
		{
			Type* rawPtr = OE_New<Type, Alloc>(std::forward<Args>(args)...);
			return ge_unique_ptr<Type, Alloc>(rawPtr);
		}

		template<class Type, class... Args>
		UPtr<Type> ge_unique_ptr_new(Args &&... args)
		{
			Type* rawPtr = OE_New<Type, GenAlloc> (std::forward<Args>(args)...);
			return ge_unique_ptr<Type, GenAlloc>(rawPtr);
		}

	}
