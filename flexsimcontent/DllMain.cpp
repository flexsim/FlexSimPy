// The following license applies to all parts of this file.
/*************************************************
The MIT License

Copyright (c) <2008> <flexsim-dll-project contributors>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*************************************************/

/************************************************
This cpp file handles the main DLL entry point as well as connecting to
Flexsim functionality. For the most part you do not need to worry about
this file at all unless you need functionality to be executed when
the DLL is loaded. Other than that, just leave this part alone.
*************************************************/

#include "FlexsimDefs.h"

#ifdef _WINDOWS
// Main DLL entry point just calls bindflexsimfunctions().
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	using namespace FlexSim;
	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
		return bindflexsimfunctions();
	else return 1;
}
#endif

// Here I do DECLARATIONTYPE FLEXSIM_DEFINITION_PHASE, which allocates memory space for the flexsim function pointers
// then include flexsimfuncs.h
#undef DECLARATIONTYPE
#define DECLARATIONTYPE FLEXSIM_DEFINITION_PHASE 
#include "FlexsimFuncs.h"

namespace FlexSim {
#ifdef _WINDOWS
int bindflexsimfunctions()
{
	flexSimModule = GetModuleHandle("flexsim.dll");
	_getflexsimexportedfunction getflexsimexportedfunction = (_getflexsimexportedfunction)GetProcAddress(flexSimModule, "getexportedfunction");

	if (!getflexsimexportedfunction)
		getflexsimexportedfunction = (_getflexsimexportedfunction)&defaultgetflexsimexportedfunction;

	int nrUnboundFunctions = 0;
	unboundFunctions = "Flexsim could not load a dll module correctly \nbecause some flexsim functions could not be bound\n\nUnsuccessful Bindings:\n";

	// Make DECLARATIONTYPE FLEXSIM_BINDING_PHASE and include flexsimfuncs.h, which sets the function pointers to GetProcAddress(...)

#undef DECLARATIONTYPE
#define DECLARATIONTYPE FLEXSIM_BINDING_PHASE
#include "FlexsimFuncs.h"

#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
	if (nrUnboundFunctions > 0)
	{
		MessageBox(NULL, (char*)unboundFunctions.c_str(), "", MB_OK | MB_TOPMOST);
	}

	int versionerror = 0;
	if (llgetallocsize() != sizeof(TreeNode))
		versionerror = 1;
	if (odtgetallocsize() != sizeof(ObjectDataType))
		versionerror = 1;
#if defined COMPILING_FLEXSIM_CONTENT
	if (versionerror)
		MessageBox(NULL, "Flexsim's content dll was built against the wrong version of the Flexsim engine.\r\nThe dll was loaded unsuccessfully.", "Versioning Error", MB_OK | MB_TOPMOST);
#else
	if (versionerror)
		MessageBox(NULL, "A module dll was built against the wrong version of the Flexsim content.\r\nThe dll was loaded unsuccessfully.", "Versioning Error", MB_OK | MB_TOPMOST);
#endif

	return nrUnboundFunctions == 0 && !versionerror;
#else
	return true;
#endif
}
#endif
}
