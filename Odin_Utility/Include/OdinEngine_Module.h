#pragma once
#include "PrerequisitesUtil.h"



//en utilitys el archivo se llama  geModule  el ge es por el nombre del motor

// template<class T>
// class Module
// {
// public:
// 
// 
// 	static T& Instance()
// 	{
// 		if (IsShutDown())
// 		{
// 
// 			OE_EXCEPT(InternalErrorException, "Trying to acces a module but it hasn´t been started up yet");
// 		}
// 		if (IsDestroyed())
// 		{
// 			OE_EXCEPT(InternalErrorException, "Trying to access a destroyed module.")
// 		}
// 
// 		return *_Instance();
// 	}
// 
// 	//////////////////////////////////////////////////////////////////////////
// 	template<class... Args>
// 	static void StartUp(Args&&... args)
// 
// 
// 		static T& Instance()
// 	{
// 		if (IsShutDown())
// 		{
// 
// 			OE_EXCEPT(InternalErrorException, "Trying to acces a module but it hasn´t been started up yet");
// 		}
// 
// 		_Instance() = ge_new<T>(std::forward<Args>(args)...);
// 		IsShutDown() = false;
// 
// 		((Module*)_Instance())->OnStartUp();
// 	}
// 
// 	template<class SubType, class... Args>
// 	static void StartUp(Args&&... args)
// 	{
// 		static_assert(std::is_base_of<T, SubType>::value, "Provided type is not derived form type the MOdule is initialized with.");
// 
// 		if (!IsShutDown())
// 		{
// 			GE_EXCEPT(InternalErrorException, "Trying to start an already started module");
// 		}
// 
// 		_Instance() = ge_new<SubType>(std::forward<Args>(args)...);
// 		IsShutDown() = false;
// 
// 		((Module*)_Instance())->OnStartUp();
// 	}
// 
// 	static void ShutDown()
// 	{
// 		if (IsShutDown() || IsDestroyed())
// 		{
// 			GE_EXCEPT(InternalErrorException, "Trying to shut down an already shut down module.");
// 		}
// 		((Module*)_Instance())->OnShutDown();
// 
// 		ge_Delete(_Instance());
// 		IsShutDown() = true;
// 	}
// 
// 
// 	static bool IsStarted()
// 	{
// 		return !IsShutDown() && !IsDestroyed();
// 	}
// 
// protected:
// 
// 	Module()
// 	{
// 
// 	}
// 
// 	virtual ~Module()
// 	{
// 		_Instance() = nullptr;
// 		IsDestroyed() = true; 
// 	}
// 
// 	Module(const Module&)
// 	{
// 
// 	}
// 
// 	Module& operator=(const Module&)
// 	{
// 		return *this;
// 	}
// 
// 	virtual void OnStartUp()
// 	{
// 
// 	}
// 
// 	virtual void OnShutDown()
// 	{
// 
// 	}
// 
// 	static T*& _Instance()
// 	{
// 		static T* = nullptr;
// 		return inst;
// 	}
// 
// 
// 	static bool& IsDestroyed()
// 	{
// 		static bool inst = false;
// 		return inst;
// 	}
// 
// 	static bool& IsShutDown()
// 	{
// 		static bool inst = true;
// 		return inst;
// 	}
// 
// };

/*Un modulo tiene lo mismo del singleton sin los problemas del singleton*/

/*
class CGraphicsAPI: public Module<CGraphics>
{
public:	
	CGraphicsAPI(int, int, char)
	CGraphicsAPI() {};
	~CGraphicsAPI() {};

	virtual void OnStartUp() override
	{

	}

	virtual void OnShutDown() override
	{

	}
};

CGraphicsAPI::StartUp();
*/