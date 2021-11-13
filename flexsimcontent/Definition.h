
namespace FlexSim {

string unboundFunctions;

void handleunboundfunction()
{
	// if the EX() command was bound correctly then call EX
	if(EXalias != reinterpret_cast<_EXalias>(&handleunboundfunction))
		EXalias((char*)unboundFunctions.c_str(), (char*)"Throwing...", 1);
	else 
	{
	// otherwise do a windows message box
		static int messageshownalready = 0;
		if(!messageshownalready)
		{
			// so that you don't get a million error messages.
			messageshownalready = 1;
			MessageBox(0, unboundFunctions.c_str(), "Error Calling Unbound DLL Function", MB_OK);
		}
	}
	throw 0;
}

HMODULE flexSimModule;
typedef void* (*_getflexsimexportedfunction)(char* functionname);
void* defaultgetflexsimexportedfunction(char* functionname)
{
	void* thefunction = GetProcAddress(flexSimModule, functionname);
	return thefunction;
}

}