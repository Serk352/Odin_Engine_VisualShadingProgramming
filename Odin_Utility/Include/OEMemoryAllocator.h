#pragma once

#undef min
#undef max

/************************************************************************/
/* Includes                                                             */
/************************************************************************/

#include <memory>
#include <atomic>
#include <limits>
#include <utility>

namespace OE_SDK
{

	class MemoryAllocatorBase;


	class MemoryCounter
	{
	public:
		static ODIN_ENGINE_UTILITY_EXPORT uint64 GetNumAllocs()
		{
			return m_Allocs;

		}

		static ODIN_ENGINE_UTILITY_EXPORT uint64 GetNumFrees()
		{
			return m_Frees;
		}

	private:
		friend class MemoryAllocatorBase;

		//Thread local data can't be exported, so some magic to make it accessible form memory


		static ODIN_ENGINE_UTILITY_EXPORT void IncrementAllocCount() { m_Allocs++; }
		static ODIN_ENGINE_UTILITY_EXPORT void IncrementFreecCount() { m_Frees++; }


		static ODIN_ENGINE_THREADLOCAL uint64 m_Allocs;
		static ODIN_ENGINE_THREADLOCAL uint64 m_Frees;
	};


	class MemoryAllocatorBase
	{
	protected:

		static void IncrementAllocCout() { MemoryCounter::IncrementAllocCount(); }
		static void IncrementFreeCout() { MemoryCounter::IncrementFreecCount(); }
	};


	template<class T>
	class MemoryAllocator : public MemoryAllocatorBase
	{
	public:
		static inline void* Allocate(SIZE_T bytes)
		{
#if ODIN_ENGINE_PROFILING_ENABLED
			IncrementAllocCout();
#endif
			return malloc(bytes);
		}

		static inline void* AllocateArray(SIZE_T bytes, uint32 count)
		{
#if ODIN_ENGINE_PROFILING_ENABLED
			IncrementAllocCout();
#endif
			return malloc(bytes * count);
		}

		static inline void Free(void* ptr)
		{
#if ODIN_ENGINE_PROFILING_ENABLED
			IncrementFreeCount();
#endif
			::free(ptr);
		}

		static inline void FreeArray(void* ptr, uint32 count)
		{
			ODIN_ENGINE_UNREFERENCED_PARAMETER(count);
#if ODIN_ENGINE_PROFILING_ENABLED

			IncrementFreeCout();
#endif
			::free(ptr);
		}
	};


	class GenAlloc
	{};


	template <class Alloc>
	inline void* OE_Alloc(SIZE_T count)
	{
		return MemoryAllocator<Alloc>::Allocate(count);
	}


	template<class T, class Alloc>
	inline T* OE_Alloc()
	{
		return (T*)MemoryAllocator<Alloc>::Allocate(sizeof(T));
	}


	template <class T, class Alloc>
	inline T* OE_newN(uint32 count)
	{
		T* ptr = (T*)MemoryAllocator<Alloc>::AllocateArray(sizeof(T), count);

		for (uint32 i = 0; i < count; i++)
		{
			new((void)*&ptr[i]) T;
		}

		return ptr;
	}



	template<class Type, class Alloc, class... Args>
	Type* OE_new(Args&&... args)
	{
		return new(OE_Alloc<Alloc>(sizeof(type))) Type(std::forward<Args>(args)...);
	}


	template<class Alloc>
	inline void OE_free(void* ptr)
	{
		MemoryAllocator<Alloc>::Free(ptr);
	}


	template <class T, class Alloc = GenAlloc>
	inline void OE_delete(T* ptr)
	{
		(ptr)->~T();
		MemoryAllocator<Alloc>::Free(ptr);
	}


	template<class T, class Alloc = GenAlloc>
	inline void OE_deleteN(T* ptr, uint32 count)
	{
		for (uint32 i = 0; i < count; i++)
		{
			ptr[i].~T();
		}
		MemoryAllocator<Alloc>::FreeArray(ptr, count);
	}


	inline void* OE_Alloc(SIZE_T count)
	{
		return MemoryAllocator<GenAlloc>::Allocate(count);
	}



	template<class T>
	inline T* OE_Alloc()
	{
		return (T*)MemoryAllocator<GenAlloc>::Allocate(sizeof(T));
	}


	template<class T>
	inline T* OE_newN(uint32 count)
	{
		T* ptr = (T*)MemoryAllocator<GenAlloc>::AllocateArray(sizeof(T), count);

		for (uint32 i = 0; i < count; i++)
		{
			new((void*)&ptr[i]) T;
		}

		return ptr;
	}


	template<class Type, class... Args>
	Type* OE_new(Args&&... args)
	{
		return new(OE_Alloc<GenAlloc>(sizeof(Type))) Type(std::forward<Args>(args)...);
	}



	inline void OE_free(void* ptr)
	{
		MemoryAllocator<GenAlloc>::Free(ptr);
		//MemoryAllocator<GenAlloc>::Free(ptr);
	}


}


#define ODIN_ENGINE_PVT_DELETE(T, ptr) \
				(ptr)->~T();		   \
				MemoryAllocator<GenAlloc>::Free(ptr);

#define ODIN_ENGINE_PVT_DELETE_A(T, ptr, Alloc) \
				(ptr)->~T();					\
				MemoryAllocator<Alloc>::Free(ptr);





namespace OE_SDK
{
	template<class T, class Alloc = GenAlloc>
	class StdAlloc
	{
	public:

		typedef T value_type;
		StdAlloc() _NOEXCEPT {}
		template<class T, class Alloc> /*bool*/ StdAlloc(const StdAlloc<T, Alloc>&) _NOEXCEPT {}
		template<class T, class Alloc> bool operator==(const StdAlloc<T, Alloc>&) const _NOEXCEPT { return true; }
		template<class T, class Alloc> bool operator!=(const StdAlloc<T, Alloc>&) const _NOEXCEPT { return false; }
	
	

		T* allocate(const size_t num) const
		{
			if (num == 0)
			{
				return nullptr;
			}

			if (num > static_cast<size_t>(-1) / sizeof(T))
			{
				throw std::bad_array_new_length();
			}

			void* const pv = OE_Alloc<Alloc>((uint32)(num * sizeof(T)));
			if (!pv)
			{
				throw std::bad_alloc();
			}
			//no se usa un new normal porque ese tambien llama a los constructores, el nuestro solo genera el espacio, es más rápido
			return static_cast<T*>(pv);
		}

		void deallocate(T* p, size_t) const _NOEXCEPT
		{
			OE_free<Alloc>((void*)p);
		}

	};

}

//#include "OdinEngineMemStack"
//#include ""