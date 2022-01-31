#include "PyPlatform.h"
#include <filesystem>
#include <span>

namespace FlexSim {

PyPlatform pyPlatform;

DllModule PyPlatform::getModuleHandle(const char* _dllName)
{
	std::string dllName = _dllName;
#ifdef _WINDOWS
	if (dllName.substr(dllName.length() - 4, 4).compare(".dll") != 0)
		dllName.append(".dll");
	return GetModuleHandle(dllName.c_str());
#else 
	if (dllName.substr(dllPath.length() - 3, 3).compare(".so") != 0)
		dllName.append(".so");
	DllModule mod = dlopen(dllName.c_str(), RTLD_NOLOAD);
	return mod;
#endif
}

void PyPlatform::setDllDirectory(const char* dirPath)
{
#ifdef _WINDOWS
	SetDllDirectory(dirPath);
#else 
#endif

}

DllModule PyPlatform::loadLibrary(const char* dllName)
{
	std::string dllPath = dllName;
#ifdef _WINDOWS
	if (dllPath.substr(dllPath.length() - 4, 4).compare(".dll") != 0)
		dllPath.append(".dll");
	return LoadLibrary(dllPath.c_str());
#else 
	if (dllPath.substr(dllPath.length() - 3, 3).compare(".so") != 0)
		dllPath.append(".so");
	DllModule mod = dlopen(dllPath.c_str(), RTLD_LAZY);
	//if (!mod) {
	//	char* err = dlerror();
	//	pt(err);
	//}
	return mod;
#endif
}

void* PyPlatform::getProcAddress(Handle hModule, const char* funcName)
{
#ifdef _WINDOWS
	return (void*)GetProcAddress((HMODULE)hModule, funcName);
#else 
	return dlsym(hModule, funcName);
#endif
}

bool PyPlatform::isDirectory(const char* dir)
{
	try {
		return std::filesystem::is_directory(std::filesystem::path(dir));
	}
	catch (...) {
		return false;
	}
}

std::string PyPlatform::findFlexSimDir()
{
	const char* searchPaths[] = {
		"C:\\Program Files\\FlexSim 2024\\",
		"C:\\Program Files\\FlexSim 2023 Update 2\\",
		"C:\\Program Files\\FlexSim 2023 Update 1\\",
		"C:\\Program Files\\FlexSim 2023\\",
		"C:\\Program Files\\FlexSim 2022 Update 2\\",
		"C:\\Program Files\\FlexSim 2022 Update 1\\",
	};

	auto paths = std::span{ searchPaths };
	for (auto path : paths) {
		if (isDirectory(path))
			return path;
	}
	return "C:\\Program Files\\FlexSim 2022 Update 1\\";
}


}