#pragma once
#if defined _WINDOWS
#	if defined FLEXSIM_BOOST
#		include <boost/asio.hpp>
#	endif
#	include <Windows.h> 
#	include <Shlwapi.h>

#endif
// I get errors with the flexscript lexer. So, here I don't inlude utf8 stuff when including the lexer
#ifndef YY_NO_UNISTD_H
#	include "UTF8.h"
#endif
#include "BasicMacros.h"
#include <queue>
#include <unordered_map>
#include <condition_variable>
#include <mutex>
#include <future>

namespace FlexSim {

#if defined _WINDOWS
	typedef BYTE			byte;
	typedef HMODULE			DllModule;
	typedef HINSTANCE		ExeInstance;
	typedef HMENU			Menu;
	typedef HWND			Window;
	typedef WPARAM			WindowParam1;
	typedef LPARAM			WindowParam2;
	typedef MSG				WindowMessage;
	typedef MSG				ThreadMessage;
	typedef POINT			WindowPoint;
	typedef RECT			WindowRect;
	typedef HDC				DeviceContext;
	typedef HANDLE			Handle;
	typedef DWORD			DWord;
#else
	typedef unsigned char	byte;
	typedef void*			DllModule;
	typedef void*			ExeInstance;
	typedef void*			Menu;
	typedef void*			Window;
	typedef void*			DeviceContext;
	typedef void*			Handle;
	typedef uint64_t		WindowParam1;
	typedef int64_t			WindowParam2;
	typedef
	struct _Flex_WP {
		long x;
		long y;
	}						WindowPoint;
	typedef
	struct _Flex_WR {
		long left;
		long top;
		long right;
		long bottom;
	}						WindowRect;

	struct ThreadMessage {
		Window window;
		int message;
		void* wParam;
		void* lParam;
		int time;
		struct {
			long x; 
			long y;
		} pt;
	};
	typedef ThreadMessage WindowMessage;
	typedef unsigned int	DWord;

	#define WM_QUIT              0x0012
	#define WINAPI __stdcall
#endif

struct MessageQueue {
	MessageQueue() : mutex(), lock(mutex) { lock.unlock(); }
	std::queue<ThreadMessage> queue;
	std::mutex mutex;
	std::unique_lock<std::mutex> lock{ mutex };
	std::condition_variable pushSignal;
	bool get(ThreadMessage& outMsg);
	bool peek(ThreadMessage& outMsg, bool pop);
	void post(int msg, void* wParam, void* lParam);
	int64_t runLoop(bool* whileIsTrue = nullptr);
};

#define FLEXSIM_MESSAGE_USER_CALLBACK 2001
#define FLEXSIM_MESSAGE_USER_NODEFUNCTION 2002
#define FLEXSIM_MESSAGE_USER_ONACTIVATENOTIFY 2003
#define FLEXSIM_MESSAGE_REEVALUATE_LICENSE 2004
#define FLEXSIM_MESSAGE_LVN_COLUMNCLICK 2005
#define FLEXSIM_MESSAGE_CALLBACK_AND_RELEASE 2006

class Platform {
public:
	engine_export static int getProcessID();
	engine_export static int getThreadID();
	~Platform();
private:
	engine_export static void lockMainThreadCallback(void* x);

	std::unordered_map<int, std::unique_ptr<MessageQueue>> messageQueueMap;
	std::mutex messageQueueMapMutex;

	engine_export void postThreadMessage_(int threadID, int msg, void* wParam, void* lParam);


public:
	template <typename WType, typename LType>
	void postThreadMessage(int threadID, int msg, WType wParam, LType lParam)
	{
		postThreadMessage_(threadID, msg, (void*)(uint64_t)wParam, (void*)(uint64_t)lParam);
	}
	engine_export MessageQueue& assertThreadMessageQueue(int threaadID);

public:
	engine_export void lockMainThread();
	engine_export void unlockMainThread();

	bool isInitialized = false;
	void init();
	int mainThreadID;
	std::mutex mainThreadMutex;
	std::mutex altThreadMutex;
	typedef void (*CallbackFuncPtr)(void* data);
	template <class Callback>
	void callMainThreadCallback(Callback callback, bool wait)
	{
		int threadId = getThreadID();
		if (wait) {
			if (threadId == mainThreadID)
				callback();
			else {
				typedef std::pair<Callback, std::promise<void>> DataParam;
				auto data = new DataParam(std::move(callback), std::promise<void>());

				auto localCallback = [](void* data) -> void {
					DataParam* param = (DataParam*)data;
					Callback& callback = param->first;
					callback();
					param->second.set_value();
					delete param;
				};
				postThreadMessage(mainThreadID, FLEXSIM_MESSAGE_USER_CALLBACK,
					(void*)(CallbackFuncPtr)localCallback, (void*)data);
				data->second.get_future().wait();
			}
		}
		else {
			Callback* callbackPtr = new Callback(std::move(callback));
			auto localCallback = [](void* data) -> void {
				Callback* callback = (Callback*)data;
				(*callback)();
				delete callback;
			};
			postThreadMessage(mainThreadID, FLEXSIM_MESSAGE_USER_CALLBACK,
				(void*)(CallbackFuncPtr)localCallback, (void*)callbackPtr);
		}
	}
	engine_export void dispatchFlexSimMessage(ThreadMessage& msg);
	std::string getEnv(const char* envName);
	engine_export int setEnv(const char* envName, const char* value);
	
	// formats a string representing a file path
	std::string& formatFilePath(std::string&);
	std::string& formatWindowsFilePath(std::string& s)
	{
#ifndef _WINDOWS
		formatFilePath(s);
#endif
		return s;
	}
	std::string formatWindowsFilePath(const std::string& s)
	{
		std::string copy(s);
#ifndef _WINDOWS
		formatFilePath(copy);
#endif
		return copy;
	}

	engine_export int executeConsoleWithOutput(const char* cmdLine);

	static void signalHandler(int signal);
	class SegFaultException : public std::exception
	{
		virtual const char* what() const noexcept override 
		{
			return "Segmentation Fault";
		}
	};
	class FloatingPointException : public std::exception
	{
		virtual const char* what() const noexcept override
		{
			return "Floating Point Exception";
		}

	};

	using TimerCallback = void (*)(void* wnd, int, size_t, int);

	engine_export size_t setTimer(size_t timerID, std::chrono::milliseconds ms, TimerCallback callback);
	engine_export void killTimer(size_t timerID);

	/*
	static void s_lambdaCallback(void* wnd, int ms, size_t id, int exta)
	template<class Lambda>
	size_t setTimer(size_t timerID, milliseconds ms, Lambda lambda) {
		auto moved = new Lambda(std::move(lambda));
		setTimer(timerID, ms, )
	}
	*/
	struct Timer {
		std::chrono::milliseconds span;
		std::chrono::time_point<std::chrono::steady_clock> nextExpireTime;
		TimerCallback callback;
	};
	bool isTimerThreadActive = false;
	std::vector<Timer> timers;
	size_t nextExpireTimerID = 0;
	std::condition_variable timerWaitCondition;
	std::mutex timerThreadDataMutex;

};

extern engine_export Platform platform;
}