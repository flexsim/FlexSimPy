#pragma once
#if defined _WINDOWS
#include <Windows.h>
#endif
#include <string>

namespace FlexSim {

#if defined _WINDOWS
	typedef HMODULE			DllModule;
	typedef HANDLE			Handle;
#else
	typedef void* DllModule;
	typedef void* Handle;
#endif
class PyPlatform {
public:
	static DllModule getModuleHandle(const char* dllName);
	static void setDllDirectory(const char* dirPath);
	static DllModule loadLibrary(const char* dllName);


	void* getProcAddress(Handle hModule, const char* funcName);
};

extern PyPlatform pyPlatform;
}