#pragma once
#include "BasicMacros.h"
#include "BasicClasses.h"
#ifdef FLEXSIM_ENGINE_COMPILE
#include "FlexSimVersion.h"
#endif

#define SUI_ALL             (0xFFFFFFFF)
#define SUI_SUPPRESS_ALL    (0xFFFFFFFF)
#define SUI_SUPPRESS_ALL_UI (0xFFFFFFFF)
#define SUI_NONE            (0x00000000)
#define SUI_NO_LOAD_MEDIA   (0x00000001)
#define SUI_NO_VIEW         (0x00000002)
#define SUI_NO_MSG          (0x00000004)
#define SUI_NO_MODAL        (0x00000004)
#define SUI_NO_HTML_VIEW    (0x00000008)

class FlexSimApplication
{
public:
	static const int INIT_FLAG_RUN_MESSAGE_LOOP = 0x1;
	static const int INIT_FLAG_DEFAULT = INIT_FLAG_RUN_MESSAGE_LOOP;

	engine_export static FlexSimApplication& getInstance();
	engine_export static Platform& getPlatform();
	engine_export int initialize(const char* cmdLine, int nCmdShow, int flags);
	engine_export int initialize(const wchar_t* cmdLine, int nCmdShow, int flags);
	engine_export int cleanup();

public:
	bool doChildExperiment = false;
	bool doEarlyExit = false;
	bool doCmdLineCompile = false;
	int suppressUIFlags = 0;
	static FlexSimApplication instance;

#ifdef P_AP_M
	Encryption::FileHash flexSimDLLHash;
#endif

private:
	void loadSystemStrings();
	void loadCustomAppOwner();
	void loadAppTitle();
	void loadCursors();
	bool cleanedUp = false;
	bool initialized = false;
};

