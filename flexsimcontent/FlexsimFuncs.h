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

/******************* - flexsimfuncs.h - Flexsim function definition and binding file - ******************/

// notify any other files that flexsim funcs has been included at least once
#ifndef FLEXSIM_FUNCS
	#define FLEXSIM_FUNCS
#endif

#include <functional>
#include <string>

#undef DECLARE_FLEXSIM_FUNCTION_1
#undef DECLARE_FLEXSIM_FUNCTION_2
#undef DECLARE_FLEXSIM_FUNCTION_3
#undef DECLARE_FLEXSIM_ATTRIBUTE
#undef DECLARE_FLEXSIM_GLOBAL_VARIABLE

#if DECLARATIONTYPE == FLEXSIM_DECLARATION_PHASE

	#define DECLARE_FLEXSIM_FUNCTION_1(name) extern _##name name;
	#define DECLARE_FLEXSIM_FUNCTION_2(name, strname) extern _##name name;
	#define DECLARE_FLEXSIM_FUNCTION_3(name, strname32, strname64) extern _##name name;
	#define DECLARE_FLEXSIM_ATTRIBUTE(name) visible TreeNode* name(TreeNode* object);
	#define DECLARE_FLEXSIM_GLOBAL_VARIABLE(name, type) extern type * _##name##_pointer;

#elif DECLARATIONTYPE == FLEXSIM_DEFINITION_PHASE

	// These are standard function definition. These should not be changed.
	#define DECLARE_FLEXSIM_FUNCTION_1(name) _##name name;
	#define DECLARE_FLEXSIM_FUNCTION_2(name, strname) _##name name;
	#define DECLARE_FLEXSIM_FUNCTION_3(name, strname32, strname64) _##name name;
	#define DECLARE_FLEXSIM_ATTRIBUTE(name) 
	#define DECLARE_FLEXSIM_GLOBAL_VARIABLE(name, type) type * _##name##_pointer;

#elif DECLARATIONTYPE == FLEXSIM_BINDING_PHASE

	// These are standard function binding. These should not be changed.
	#define DECLARE_FLEXSIM_FUNCTION_1(name) \
		name = (_##name)getflexsimexportedfunction((char*)#name);\
		if(!name){ nrUnboundFunctions++; unboundFunctions += #name; unboundFunctions += "\n"; name = (_##name)handleunboundfunction;}
	#define DECLARE_FLEXSIM_ATTRIBUTE(name) 
	#define DECLARE_FLEXSIM_FUNCTION_2(name, strname) \
		name = (_##name)getflexsimexportedfunction((char*)strname);\
		if(!name){ nrUnboundFunctions++; unboundFunctions += #name; unboundFunctions += "\n"; name = (_##name)handleunboundfunction;}
	#ifndef _M_AMD64
		#define DECLARE_FLEXSIM_FUNCTION_3(name, strname32, strname64) \
			name = (_##name)getflexsimexportedfunction((char*)strname32);\
			if(!name){ nrUnboundFunctions++; unboundFunctions += #name; unboundFunctions += "\n"; name = (_##name)handleunboundfunction;}
	#else
		#define DECLARE_FLEXSIM_FUNCTION_3(name, strname32, strname64) \
			name = (_##name)getflexsimexportedfunction((char*)strname64);\
			if(!name){ nrUnboundFunctions++; unboundFunctions += #name; unboundFunctions += "\n"; name = (_##name)handleunboundfunction;}
	#endif

	#define DECLARE_FLEXSIM_GLOBAL_VARIABLE(name, type)\
		int _##name##_globalvariableindex = getglobalvariableindex(#name);\
		if(_##name##_globalvariableindex == 0)\
			{ nrUnboundFunctions++; unboundFunctions += #name; unboundFunctions += "\n"; }\
		else _##name##_pointer = &(getglobalvariableas##type(_##name##_globalvariableindex));

#endif

#ifndef TYPEDEFS
#define TYPEDEFS
namespace FlexSim {
#ifdef _WINDOWS
	// FLEXSIM FUNCTIONS
	typedef int          (*_EXalias)(char* T, char* M, int showsystemconsole);

	#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
	#else
		typedef double       (*_addsphere)(treenode obj, double xval, double yval, double zval, double radius);
		typedef double       (*_backupfile)(char* f);
		typedef treenode     (*_bcgetitemkinematics)(treenode conveyor, treenode item, int kinematictype);
		typedef double       (*_bcgetitemposition)(treenode conveyor, treenode item);
		typedef double       (*_bcsetdirection)(treenode conveyor, int direction);
		typedef double       (*_bcsetitemconveystate)(treenode conveyor, treenode item, double startpos, double startspeed, double targetspeed, double accdec);
		typedef double       (*_changeconveyorspeed)(treenode conveyor, double newspeed);
		typedef treenode     (*_changetask)(treenode tasksequence, int taskrank, unsigned short type, treenode involved1, treenode involved2, double var1, double var2, double var3, double var4);
		typedef double       (*_closenodeedge)(treenode curnode, int edgenum);
		typedef double       (*_codetotemplatetext)(treenode view, treenode destnode);
		typedef double       (*_consoleexecutecpp)(Window in, Window out);
		typedef double       (*_containerentry)(treenode container, treenode item);
		typedef double       (*_containerexit)(treenode container, treenode item);
		typedef double       (*_contextdragconnection)(treenode fromobject, treenode toobject, char keypressed);
		typedef treenode     (*_createcoordinatedtasksequence)(treenode dispatcher);
		typedef treenode     (*_createemptytasksequence)(treenode dispatcher, double priority, int preempt);
		typedef double       (*_dispatchcoordinatedtasksequencealias)(treenode tasksequence, treenode dispatcher);
		typedef double       (*_dispatchtasksequencealias)(treenode tasksequence, treenode dispatcher);
		typedef double       (*_distancetotravel)(treenode traveler, treenode destination);
		typedef double       (*_drawspheres)(treenode object, treenode view);
		typedef int          (*_enablefullhistory)(int enable);
		typedef double       (*_fglinfo)(int op, treenode view);
		typedef void         (*_flexsimfree)(void*);
		typedef void*        (*_flexsimmalloc)(size_t);
		typedef void*        (*_flexsimrealloc)(void*, size_t);
		typedef double       (*_freeoperators)(treenode dispatcher, treenode involved);
		typedef treenode     (*_getallocatedfromkey)(treenode tasksequence, int key);
		typedef treenode     (*_getcoordinatedtasksequence)(treenode dispatcher, int tsrank);
		typedef double       (*_getcurtask)(treenode tasksequence);
		typedef double       (*_getedgedist)(treenode netnode, int edgenum);
		typedef double       (*_getedgespeedlimit)(treenode netnode, int edgenum);
		typedef double       (*_geteventtime)(char* eventname, double mode);
		typedef treenode     (*_getiteminvolved)(treenode item);
		typedef int          (*_getitemsendto)(treenode item);
		typedef int          (*_getitemstate)(treenode item);
		typedef double       (*_getitemvar)(treenode item, int index);
		typedef int          (*_getmodulelicense)(int module, int* version, int* subversion);
		typedef treenode     (*_getnetnode)(treenode object, int index);
		typedef treenode     (*_getnetnodespline)(treenode netnode, int outport);
		typedef double       (*_getnetworkdistance)(int fromnn, int tonn);
		typedef int          (*_getnextnetnode)(int fromnn, int tonn);
		typedef int          (*_getnextnetnodeoutport)(int fromnn, int tonn);
		typedef double       (*_getnroftasks)(treenode tasksequence);
		typedef unsigned int (*_getnummoverecords)();
		typedef unsigned int (*_getnumstaterecords)();
		typedef treenode     (*_getobjvarfastpointer)(treenode thenode, int offset);
		typedef int          (*_getobjvarfastpointeroffset)(treenode thenode, char* varname);
		typedef unsigned int (*_getpreempt)(treenode tasksequence);
		typedef double       (*_getpriority)(treenode tasksequence);
		typedef treenode     (*_gettaskinvolved)(treenode tasksequence, unsigned int rankrequested, unsigned int involvednum);
		typedef treenode     (*_gettasksequence)(treenode dispatcher, double tsrank);
		typedef treenode     (*_gettasksequencequeue)(treenode dispatcher);
		typedef unsigned int (*_gettasktype)(treenode tasksequence, int rankrequested);
		typedef double       (*_gettaskvariable)(treenode tasksequence, unsigned int rankrequested, unsigned int varnum);
		typedef treenode     (*_gettenetnode)(treenode te);
		typedef double       (*_gettotalnroftasks)(treenode tasksequence);
		typedef double       (*_gettreedrawpositionalias)(treenode object, treenode roottree, int* cury, int increment);
		typedef double       (*_holditem)(treenode item);
		typedef int          (*_insertallocatetask)(treenode tasksequence, treenode dispatcher, double priority, double preempt, int noblock);
		typedef int          (*_insertdeallocatetaskalias)(treenode tasksequence, int executerkey, int noblock);
		typedef int          (*_insertmultiallocatetask)(treenode tasksequence, int range);
		typedef int          (*_insertproxytaskalias1)(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1, treenode involved2, double var1, double var2, double var3, double var4);
		typedef int          (*_insertproxytaskalias2)(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1);
		typedef int          (*_insertproxytaskalias3)(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1, int involved2, double var1, double var2, double var3, double var4);
		typedef int          (*_insertproxytaskalias4)(treenode tasksequence, unsigned int executerkey, unsigned int  type);
		typedef int          (*_insertproxytaskalias5)(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1, treenode involved2, double var1, double var2, double var3, double var4);
		typedef int          (*_insertproxytaskalias6)(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1);
		typedef int          (*_insertproxytaskalias7)(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1, int involved2, double var1, double var2, double var3, double var4);
		typedef int          (*_insertsynctask)(treenode tasksequence, int taskkey);
		typedef treenode     (*_inserttaskalias)(treenode tasksequence, unsigned int  type, treenode involved1, treenode involved2, double var1, double var2, double var3, double var4);
		typedef int          (*_isedgeforward)(treenode netnode, int outport);
		typedef double       (*_movetasksequence)(treenode tasksequence, treenode dispatcher);
		typedef treenode     (*_netnodefromrank)(int netnoderank);
		typedef double       (*_opennodeedge)(treenode curnode, int edgenum);
		typedef double       (*_optimizenetwork)();
		typedef double       (*_pickoffsetx)(treenode station, treenode item, treenode otherobject);
		typedef double       (*_pickoffsety)(treenode station, treenode item, treenode otherobject);
		typedef double       (*_pickoffsetz)(treenode station, treenode item, treenode otherobject);
		typedef double       (*_placeoffsetx)(treenode station, treenode item, treenode otherobject);
		typedef double       (*_placeoffsety)(treenode station, treenode item, treenode otherobject);
		typedef double       (*_placeoffsetz)(treenode station, treenode item, treenode otherobject);
		typedef double       (*_profiletasksequence)(treenode ts);
		typedef double       (*_rackdrawfilledcell)(treenode rack, int bay, int level, double x, double y, double z, double sx, double sy, double sz, double red, double green, double blue, int glbeginend);
		typedef double       (*_rackdrawvirtualcontent)(treenode rack, double bayfillperc, double levelfillperc, double itemdepth, double red, double green, double blue, double virtualonly);
		typedef double       (*_rackgetbaycontent)(treenode rack, int bay);
		typedef double       (*_rackgetbayloc)(treenode rack, int bay);
		typedef double       (*_rackgetbayofitem)(treenode rack, treenode item);
		typedef double       (*_rackgetbaysize)(treenode rack, int bay);
		typedef double       (*_rackgetcellcontent)(treenode rack, int bay, int level);
		typedef double       (*_rackgetcellvar)(treenode rack, int bay, int level, int varnum, treenode storedlabel);
		typedef treenode     (*_rackgetcontenttable)(treenode object);
		typedef treenode     (*_rackgetitembybaylevel)(treenode rack, int bay, int level, int itemrank);
		typedef double       (*_rackgetlevelloc)(treenode rack, int bay, int level);
		typedef double       (*_rackgetlevelofitem)(treenode rack, treenode item);
		typedef double       (*_rackgetlevelsize)(treenode rack, int bay, int level);
		typedef double       (*_rackgetnrofbays)(treenode rack);
		typedef double       (*_rackgetnroflevels)(treenode rack, int bay);
		typedef double       (*_rackrecycleitem)(treenode rack, treenode item, int binrank);
		typedef treenode     (*_rackrestoreitem)(treenode rack, int binrank, int bay, int level, int position);
		typedef double       (*_racksetcellcontent)(treenode rack, int bay, int level, int contentval);
		typedef double       (*_racksetcellvar)(treenode rack, int bay, int level, int varnum, double value, treenode storedlabel);
		typedef int          (*_rankfromnetnode)(treenode netnode);
		typedef double       (*_reassignnetnode)(treenode taskexecuter, treenode netnode);
		typedef double       (*_receiveitem_alias1)(treenode station);
		typedef double       (*_receiveitem_alias2)(treenode station, int port);
		typedef double       (*_recycleitem)(treenode item, int binrank);
		typedef double       (*_recyclenode)(treenode node, treenode containerbranch);
		typedef double       (*_redirectnetworktraveler)(treenode traveler, treenode newdest);
		typedef double       (*_releaseitem_alias1)(treenode item);
		typedef double       (*_releaseitem_alias2)(treenode item, int port);
		typedef double       (*_reordertasks)(treenode involved);
		typedef double       (*_requestoperators)(treenode dispatcher, treenode station, treenode involved, int nrofops, double priority, int preempt);
		typedef double       (*_rerankbesttask)(treenode involved);
		typedef double       (*_resumeobjectalias)(treenode involved, int id);
		typedef double       (*_resumetransportsin)(treenode object, int rank);
		typedef double       (*_resumetransportsout)(treenode object, int rank);
		typedef double       (*_savebyname)(treenode tree, char* name);
		typedef double       (*_savestoppedtransportin)(treenode object, treenode transporter);
		typedef double       (*_savestoppedtransportout)(treenode object, treenode transporter);
		typedef double       (*_senddelayedmessage)(treenode toobject, double delaytime, treenode fromobject, double par1, double par2, double par3);
		typedef double       (*_setcollisioncheck)(treenode collisionobj, double val, double interval);
		typedef double       (*_seteventtime)(char* eventname, double timeval, double mode, double newevent);
		typedef double       (*_setiteminvolved)(treenode item, treenode involved);
		typedef double       (*_setitemsendto)(treenode item, int sendto);
		typedef double       (*_setitemvar)(treenode item, int index, double val);
		typedef double       (*_setpreempt)(treenode tasksequence, unsigned int newpreempt);
		typedef double       (*_setpriority)(treenode tasksequence, double newpriority);
		typedef double       (*_setresetposition)(treenode obj);
		typedef double       (*_stopobject)(treenode involved, int state, int id, double priority);
		typedef double       (*_trafficcontrolinfo)(treenode tc, int info, double _a, double _b);
		typedef double       (*_transportincompletealias)(treenode object, treenode item, int portnumber, treenode transporter);
		typedef double       (*_transportoutcompletealias)(treenode object, treenode item, int portnumber, treenode transporter);
		typedef double       (*_updatelocations)(treenode object);
	#endif
#endif
}
#endif

#if DECLARATIONTYPE != FLEXSIM_BINDING_PHASE
namespace FlexSim {
#endif
#ifdef _WINDOWS
/*** FLEXSIM FUNCTIONS ***/
DECLARE_FLEXSIM_FUNCTION_2(EXalias, "EX")

#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
/*** FUNCTIONS ONLY REQUIRED FOR CONTENT DLL ***/
#else
/*** FUNCTIONS ONLY REQUIRED FOR DLL PROJECT***/
	DECLARE_FLEXSIM_FUNCTION_1(addsphere)
	DECLARE_FLEXSIM_FUNCTION_1(backupfile)
	DECLARE_FLEXSIM_FUNCTION_1(bcgetitemkinematics)
	DECLARE_FLEXSIM_FUNCTION_1(bcgetitemposition)
	DECLARE_FLEXSIM_FUNCTION_1(bcsetdirection)
	DECLARE_FLEXSIM_FUNCTION_1(bcsetitemconveystate)
	DECLARE_FLEXSIM_FUNCTION_1(changeconveyorspeed)
	DECLARE_FLEXSIM_FUNCTION_1(changetask)
	DECLARE_FLEXSIM_FUNCTION_1(closenodeedge)
	DECLARE_FLEXSIM_FUNCTION_1(codetotemplatetext)
	DECLARE_FLEXSIM_FUNCTION_1(consoleexecutecpp)
	DECLARE_FLEXSIM_FUNCTION_1(containerentry)
	DECLARE_FLEXSIM_FUNCTION_1(containerexit)
	DECLARE_FLEXSIM_FUNCTION_1(contextdragconnection)
	DECLARE_FLEXSIM_FUNCTION_1(createcoordinatedtasksequence)
	DECLARE_FLEXSIM_FUNCTION_1(createemptytasksequence)
	DECLARE_FLEXSIM_FUNCTION_2(dispatchcoordinatedtasksequencealias, "dispatchcoordinatedtasksequence")
	DECLARE_FLEXSIM_FUNCTION_2(dispatchtasksequencealias, "dispatchtasksequence")
	DECLARE_FLEXSIM_FUNCTION_1(distancetotravel)
	DECLARE_FLEXSIM_FUNCTION_1(drawspheres)
	DECLARE_FLEXSIM_FUNCTION_1(enablefullhistory)
	DECLARE_FLEXSIM_FUNCTION_1(fglinfo)
	DECLARE_FLEXSIM_FUNCTION_1(flexsimfree)
	DECLARE_FLEXSIM_FUNCTION_1(flexsimmalloc)
	DECLARE_FLEXSIM_FUNCTION_1(flexsimrealloc)
	DECLARE_FLEXSIM_FUNCTION_1(freeoperators)
	DECLARE_FLEXSIM_FUNCTION_1(getallocatedfromkey)
	DECLARE_FLEXSIM_FUNCTION_1(getcoordinatedtasksequence)
	DECLARE_FLEXSIM_FUNCTION_1(getcurtask)
	DECLARE_FLEXSIM_FUNCTION_1(getedgedist)
	DECLARE_FLEXSIM_FUNCTION_1(getedgespeedlimit)
	DECLARE_FLEXSIM_FUNCTION_1(geteventtime)
	DECLARE_FLEXSIM_FUNCTION_1(getiteminvolved)
	DECLARE_FLEXSIM_FUNCTION_1(getitemsendto)
	DECLARE_FLEXSIM_FUNCTION_1(getitemstate)
	DECLARE_FLEXSIM_FUNCTION_1(getitemvar)
	DECLARE_FLEXSIM_FUNCTION_1(getmodulelicense)
	DECLARE_FLEXSIM_FUNCTION_1(getnetnode)
	DECLARE_FLEXSIM_FUNCTION_1(getnetnodespline)
	DECLARE_FLEXSIM_FUNCTION_1(getnetworkdistance)
	DECLARE_FLEXSIM_FUNCTION_1(getnextnetnode)
	DECLARE_FLEXSIM_FUNCTION_1(getnextnetnodeoutport)
	DECLARE_FLEXSIM_FUNCTION_1(getnroftasks)
	DECLARE_FLEXSIM_FUNCTION_1(getnummoverecords)
	DECLARE_FLEXSIM_FUNCTION_1(getnumstaterecords)
	DECLARE_FLEXSIM_FUNCTION_1(getobjvarfastpointer)
	DECLARE_FLEXSIM_FUNCTION_1(getobjvarfastpointeroffset)
	DECLARE_FLEXSIM_FUNCTION_1(getpreempt)
	DECLARE_FLEXSIM_FUNCTION_1(getpriority)
	DECLARE_FLEXSIM_FUNCTION_1(gettaskinvolved)
	DECLARE_FLEXSIM_FUNCTION_1(gettasksequence)
	DECLARE_FLEXSIM_FUNCTION_1(gettasksequencequeue)
	DECLARE_FLEXSIM_FUNCTION_1(gettasktype)
	DECLARE_FLEXSIM_FUNCTION_1(gettaskvariable)
	DECLARE_FLEXSIM_FUNCTION_1(gettenetnode)
	DECLARE_FLEXSIM_FUNCTION_1(gettotalnroftasks)
	DECLARE_FLEXSIM_FUNCTION_2(gettreedrawpositionalias, "gettreedrawposition")
	DECLARE_FLEXSIM_FUNCTION_1(holditem)
	DECLARE_FLEXSIM_FUNCTION_1(insertallocatetask)
	DECLARE_FLEXSIM_FUNCTION_2(insertdeallocatetaskalias, "insertdeallocatetask")
	DECLARE_FLEXSIM_FUNCTION_1(insertmultiallocatetask)
	DECLARE_FLEXSIM_FUNCTION_2(insertproxytaskalias1, "insertproxytask")
	DECLARE_FLEXSIM_FUNCTION_3(insertproxytaskalias2, "?insertproxytask@FlexSim@@YAHPAVTreeNode@1@II0@Z", "?insertproxytask@FlexSim@@YAHPEAVTreeNode@1@II0@Z")
	DECLARE_FLEXSIM_FUNCTION_3(insertproxytaskalias3, "?insertproxytask@FlexSim@@YAHPAVTreeNode@1@II0HNNNN@Z", "?insertproxytask@FlexSim@@YAHPEAVTreeNode@1@II0HNNNN@Z")
	DECLARE_FLEXSIM_FUNCTION_3(insertproxytaskalias4, "?insertproxytask@FlexSim@@YAHPAVTreeNode@1@II@Z", "?insertproxytask@FlexSim@@YAHPEAVTreeNode@1@II@Z")
	DECLARE_FLEXSIM_FUNCTION_3(insertproxytaskalias5, "?insertproxytask@FlexSim@@YAHPAVTreeNode@1@IIH0NNNN@Z", "?insertproxytask@FlexSim@@YAHPEAVTreeNode@1@IIH0NNNN@Z")
	DECLARE_FLEXSIM_FUNCTION_3(insertproxytaskalias6, "?insertproxytask@FlexSim@@YAHPAVTreeNode@1@IIH@Z", "?insertproxytask@FlexSim@@YAHPEAVTreeNode@1@IIH@Z")
	DECLARE_FLEXSIM_FUNCTION_3(insertproxytaskalias7, "?insertproxytask@FlexSim@@YAHPAVTreeNode@1@IIHHNNNN@Z", "?insertproxytask@FlexSim@@YAHPEAVTreeNode@1@IIHHNNNN@Z")
	DECLARE_FLEXSIM_FUNCTION_1(insertsynctask)
	DECLARE_FLEXSIM_FUNCTION_2(inserttaskalias, "inserttask")
	DECLARE_FLEXSIM_FUNCTION_1(isedgeforward)
	DECLARE_FLEXSIM_FUNCTION_1(movetasksequence)
	DECLARE_FLEXSIM_FUNCTION_1(netnodefromrank)
	DECLARE_FLEXSIM_FUNCTION_1(opennodeedge)
	DECLARE_FLEXSIM_FUNCTION_1(optimizenetwork)
	DECLARE_FLEXSIM_FUNCTION_1(pickoffsetx)
	DECLARE_FLEXSIM_FUNCTION_1(pickoffsety)
	DECLARE_FLEXSIM_FUNCTION_1(pickoffsetz)
	DECLARE_FLEXSIM_FUNCTION_1(placeoffsetx)
	DECLARE_FLEXSIM_FUNCTION_1(placeoffsety)
	DECLARE_FLEXSIM_FUNCTION_1(placeoffsetz)
	DECLARE_FLEXSIM_FUNCTION_1(profiletasksequence)
	DECLARE_FLEXSIM_FUNCTION_1(rackdrawfilledcell)
	DECLARE_FLEXSIM_FUNCTION_1(rackdrawvirtualcontent)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetbaycontent)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetbayloc)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetbayofitem)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetbaysize)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetcellcontent)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetcellvar)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetcontenttable)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetitembybaylevel)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetlevelloc)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetlevelofitem)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetlevelsize)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetnrofbays)
	DECLARE_FLEXSIM_FUNCTION_1(rackgetnroflevels)
	DECLARE_FLEXSIM_FUNCTION_1(rackrecycleitem)
	DECLARE_FLEXSIM_FUNCTION_1(rackrestoreitem)
	DECLARE_FLEXSIM_FUNCTION_1(racksetcellcontent)
	DECLARE_FLEXSIM_FUNCTION_1(racksetcellvar)
	DECLARE_FLEXSIM_FUNCTION_1(rankfromnetnode)
	DECLARE_FLEXSIM_FUNCTION_1(reassignnetnode)
	DECLARE_FLEXSIM_FUNCTION_2(receiveitem_alias1, "receiveitem")
	DECLARE_FLEXSIM_FUNCTION_3(receiveitem_alias2, "?releaseitem@FlexSim@@YANPAVTreeNode@1@H@Z", "?releaseitem@FlexSim@@YANPEAVTreeNode@1@H@Z")
	DECLARE_FLEXSIM_FUNCTION_1(recycleitem)
	DECLARE_FLEXSIM_FUNCTION_1(recyclenode)
	DECLARE_FLEXSIM_FUNCTION_1(redirectnetworktraveler);
	DECLARE_FLEXSIM_FUNCTION_2(releaseitem_alias1, "releaseitem")
	DECLARE_FLEXSIM_FUNCTION_3(releaseitem_alias2, "?releaseitem@FlexSim@@YANPAVTreeNode@1@H@Z", "?releaseitem@FlexSim@@YANPEAVTreeNode@1@H@Z")
	DECLARE_FLEXSIM_FUNCTION_1(reordertasks)
	DECLARE_FLEXSIM_FUNCTION_1(requestoperators)
	DECLARE_FLEXSIM_FUNCTION_1(rerankbesttask)
	DECLARE_FLEXSIM_FUNCTION_1(resumeobjectalias)
	DECLARE_FLEXSIM_FUNCTION_1(resumetransportsin)
	DECLARE_FLEXSIM_FUNCTION_1(resumetransportsout)
	DECLARE_FLEXSIM_FUNCTION_1(savebyname)
	DECLARE_FLEXSIM_FUNCTION_1(savestoppedtransportin)
	DECLARE_FLEXSIM_FUNCTION_1(savestoppedtransportout)
	DECLARE_FLEXSIM_FUNCTION_1(senddelayedmessage)
	DECLARE_FLEXSIM_FUNCTION_1(setcollisioncheck)
	DECLARE_FLEXSIM_FUNCTION_1(seteventtime)
	DECLARE_FLEXSIM_FUNCTION_1(setiteminvolved)
	DECLARE_FLEXSIM_FUNCTION_1(setitemsendto)
	DECLARE_FLEXSIM_FUNCTION_1(setitemvar)
	DECLARE_FLEXSIM_FUNCTION_1(setpreempt)
	DECLARE_FLEXSIM_FUNCTION_1(setpriority)
	DECLARE_FLEXSIM_FUNCTION_1(setresetposition)
	DECLARE_FLEXSIM_FUNCTION_1(stopobject)
	DECLARE_FLEXSIM_FUNCTION_1(trafficcontrolinfo)
	DECLARE_FLEXSIM_FUNCTION_2(transportincompletealias, "transportincomplete")
	DECLARE_FLEXSIM_FUNCTION_2(transportoutcompletealias, "transportoutcomplete")
	DECLARE_FLEXSIM_FUNCTION_1(updatelocations)
#endif
#endif

/*** FLEXSIM ATTRIBUTES ***/
DECLARE_FLEXSIM_ATTRIBUTE(alignbottommargin)
DECLARE_FLEXSIM_ATTRIBUTE(alignbottomposition)
DECLARE_FLEXSIM_ATTRIBUTE(aligncenterx)
DECLARE_FLEXSIM_ATTRIBUTE(aligncentery)
DECLARE_FLEXSIM_ATTRIBUTE(alignrightmargin)
DECLARE_FLEXSIM_ATTRIBUTE(alignrightposition)
DECLARE_FLEXSIM_ATTRIBUTE(animationinfo)
DECLARE_FLEXSIM_ATTRIBUTE(assertupdate)
DECLARE_FLEXSIM_ATTRIBUTE(behaviour)
DECLARE_FLEXSIM_ATTRIBUTE(beveltype)
DECLARE_FLEXSIM_ATTRIBUTE(bitmap)
DECLARE_FLEXSIM_ATTRIBUTE(cellheight)
DECLARE_FLEXSIM_ATTRIBUTE(cellwidth)
DECLARE_FLEXSIM_ATTRIBUTE(centroid)
DECLARE_FLEXSIM_ATTRIBUTE(classes)
DECLARE_FLEXSIM_ATTRIBUTE(coldlink)
DECLARE_FLEXSIM_ATTRIBUTE(coldlinkname)
DECLARE_FLEXSIM_ATTRIBUTE(coldlinknamex)
DECLARE_FLEXSIM_ATTRIBUTE(coldlinkx)
DECLARE_FLEXSIM_ATTRIBUTE(color)
DECLARE_FLEXSIM_ATTRIBUTE(connections)
DECLARE_FLEXSIM_ATTRIBUTE(connectionscenter)
DECLARE_FLEXSIM_ATTRIBUTE(connectionsin)
DECLARE_FLEXSIM_ATTRIBUTE(connectionsout)
DECLARE_FLEXSIM_ATTRIBUTE(connectorsize)
DECLARE_FLEXSIM_ATTRIBUTE(connectorstyle)
DECLARE_FLEXSIM_ATTRIBUTE(cppfunctions)
DECLARE_FLEXSIM_ATTRIBUTE(cppvariables)
DECLARE_FLEXSIM_ATTRIBUTE(customaction)
DECLARE_FLEXSIM_ATTRIBUTE(deassertupdate)
DECLARE_FLEXSIM_ATTRIBUTE(description)
DECLARE_FLEXSIM_ATTRIBUTE(drawflags)
DECLARE_FLEXSIM_ATTRIBUTE(drawsurrogate)
DECLARE_FLEXSIM_ATTRIBUTE(eventfunctions)
DECLARE_FLEXSIM_ATTRIBUTE(frame)
DECLARE_FLEXSIM_ATTRIBUTE(graphannotate)
DECLARE_FLEXSIM_ATTRIBUTE(graphaxes)
DECLARE_FLEXSIM_ATTRIBUTE(graphbars)
DECLARE_FLEXSIM_ATTRIBUTE(graphgrid)
DECLARE_FLEXSIM_ATTRIBUTE(graphhistodata)
DECLARE_FLEXSIM_ATTRIBUTE(graphlegend)
DECLARE_FLEXSIM_ATTRIBUTE(graphlegendhisto)
DECLARE_FLEXSIM_ATTRIBUTE(graphlines)
DECLARE_FLEXSIM_ATTRIBUTE(graphmaxpoints)
DECLARE_FLEXSIM_ATTRIBUTE(graphpie)
DECLARE_FLEXSIM_ATTRIBUTE(graphpiedata)
DECLARE_FLEXSIM_ATTRIBUTE(graphpoints)
DECLARE_FLEXSIM_ATTRIBUTE(graphstep)
DECLARE_FLEXSIM_ATTRIBUTE(graphtitle)
DECLARE_FLEXSIM_ATTRIBUTE(graphxy)
DECLARE_FLEXSIM_ATTRIBUTE(grayed)
DECLARE_FLEXSIM_ATTRIBUTE(gridfog)
DECLARE_FLEXSIM_ATTRIBUTE(gridlinecolor)
DECLARE_FLEXSIM_ATTRIBUTE(gridlinewidth)
DECLARE_FLEXSIM_ATTRIBUTE(gridx)
DECLARE_FLEXSIM_ATTRIBUTE(gridy)
DECLARE_FLEXSIM_ATTRIBUTE(gridz)
DECLARE_FLEXSIM_ATTRIBUTE(gridplane)
DECLARE_FLEXSIM_ATTRIBUTE(guifocus)
DECLARE_FLEXSIM_ATTRIBUTE(guifocusclass)
DECLARE_FLEXSIM_ATTRIBUTE(hidden)
DECLARE_FLEXSIM_ATTRIBUTE(hotlink)
DECLARE_FLEXSIM_ATTRIBUTE(hotlinkname)
DECLARE_FLEXSIM_ATTRIBUTE(hotlinknamex)
DECLARE_FLEXSIM_ATTRIBUTE(hotlinkx)
DECLARE_FLEXSIM_ATTRIBUTE(imagebase)
DECLARE_FLEXSIM_ATTRIBUTE(imageindexbase)
DECLARE_FLEXSIM_ATTRIBUTE(imageindexobject)
DECLARE_FLEXSIM_ATTRIBUTE(imageobject)
DECLARE_FLEXSIM_ATTRIBUTE(initialtext)
DECLARE_FLEXSIM_ATTRIBUTE(itemcurrent)
DECLARE_FLEXSIM_ATTRIBUTE(items)
DECLARE_FLEXSIM_ATTRIBUTE(itemtype)
DECLARE_FLEXSIM_ATTRIBUTE(labels)
DECLARE_FLEXSIM_ATTRIBUTE(labelscale)
DECLARE_FLEXSIM_ATTRIBUTE(listeners)
DECLARE_FLEXSIM_ATTRIBUTE(menucustom)
DECLARE_FLEXSIM_ATTRIBUTE(menupopup)
DECLARE_FLEXSIM_ATTRIBUTE(menuview)
DECLARE_FLEXSIM_ATTRIBUTE(noformat)
DECLARE_FLEXSIM_ATTRIBUTE(objectfocus)
DECLARE_FLEXSIM_ATTRIBUTE(objectinfo)
DECLARE_FLEXSIM_ATTRIBUTE(offsetrx)
DECLARE_FLEXSIM_ATTRIBUTE(offsetry)
DECLARE_FLEXSIM_ATTRIBUTE(offsetrz)
DECLARE_FLEXSIM_ATTRIBUTE(offsetsx)
DECLARE_FLEXSIM_ATTRIBUTE(offsetsy)
DECLARE_FLEXSIM_ATTRIBUTE(offsetsz)
DECLARE_FLEXSIM_ATTRIBUTE(offsetx)
DECLARE_FLEXSIM_ATTRIBUTE(offsety)
DECLARE_FLEXSIM_ATTRIBUTE(offsetz)
DECLARE_FLEXSIM_ATTRIBUTE(OnClick)
DECLARE_FLEXSIM_ATTRIBUTE(OnClose)
DECLARE_FLEXSIM_ATTRIBUTE(OnCompile)
DECLARE_FLEXSIM_ATTRIBUTE(OnCreate)
DECLARE_FLEXSIM_ATTRIBUTE(OnDestroy)
DECLARE_FLEXSIM_ATTRIBUTE(OnDrag)
DECLARE_FLEXSIM_ATTRIBUTE(OnDraw)
DECLARE_FLEXSIM_ATTRIBUTE(OnDrawPlanar)
DECLARE_FLEXSIM_ATTRIBUTE(OnDrop)
DECLARE_FLEXSIM_ATTRIBUTE(OnDropFile)
DECLARE_FLEXSIM_ATTRIBUTE(OnDropNode)
DECLARE_FLEXSIM_ATTRIBUTE(OnEntering)
DECLARE_FLEXSIM_ATTRIBUTE(OnExiting)
DECLARE_FLEXSIM_ATTRIBUTE(OnInOpen)
DECLARE_FLEXSIM_ATTRIBUTE(OnKeyDown)
DECLARE_FLEXSIM_ATTRIBUTE(OnKeyUp)
DECLARE_FLEXSIM_ATTRIBUTE(OnListen)
DECLARE_FLEXSIM_ATTRIBUTE(OnLoad)
DECLARE_FLEXSIM_ATTRIBUTE(OnMessage)
DECLARE_FLEXSIM_ATTRIBUTE(OnMouseButtonDown)
DECLARE_FLEXSIM_ATTRIBUTE(OnMouseButtonUp)
DECLARE_FLEXSIM_ATTRIBUTE(OnMouseMove)
DECLARE_FLEXSIM_ATTRIBUTE(OnMouseWheel)
DECLARE_FLEXSIM_ATTRIBUTE(OnOpen)
DECLARE_FLEXSIM_ATTRIBUTE(OnOutOpen)
DECLARE_FLEXSIM_ATTRIBUTE(OnPreDraw)
DECLARE_FLEXSIM_ATTRIBUTE(OnPreDrawPlanar)
DECLARE_FLEXSIM_ATTRIBUTE(OnPreListen)
DECLARE_FLEXSIM_ATTRIBUTE(OnPreOpen)
DECLARE_FLEXSIM_ATTRIBUTE(OnPress)
DECLARE_FLEXSIM_ATTRIBUTE(OnReceive)
DECLARE_FLEXSIM_ATTRIBUTE(OnReset)
DECLARE_FLEXSIM_ATTRIBUTE(OnRunEnd)
DECLARE_FLEXSIM_ATTRIBUTE(OnRunStart)
DECLARE_FLEXSIM_ATTRIBUTE(OnSelect)
DECLARE_FLEXSIM_ATTRIBUTE(OnSend)
DECLARE_FLEXSIM_ATTRIBUTE(OnStateChange)
DECLARE_FLEXSIM_ATTRIBUTE(OnStick)
DECLARE_FLEXSIM_ATTRIBUTE(OnTimerEvent)
DECLARE_FLEXSIM_ATTRIBUTE(pagelist)
DECLARE_FLEXSIM_ATTRIBUTE(palettewindow)
DECLARE_FLEXSIM_ATTRIBUTE(pickcopydataonly)
DECLARE_FLEXSIM_ATTRIBUTE(pickitem)
DECLARE_FLEXSIM_ATTRIBUTE(picklist)
DECLARE_FLEXSIM_ATTRIBUTE(picklistnameonly)
DECLARE_FLEXSIM_ATTRIBUTE(pickprimary)
DECLARE_FLEXSIM_ATTRIBUTE(picture)
DECLARE_FLEXSIM_ATTRIBUTE(rangeexp)
DECLARE_FLEXSIM_ATTRIBUTE(rangemax)
DECLARE_FLEXSIM_ATTRIBUTE(rangemin)
DECLARE_FLEXSIM_ATTRIBUTE(resizeinfo)
DECLARE_FLEXSIM_ATTRIBUTE(shape)
DECLARE_FLEXSIM_ATTRIBUTE(shapeindex)
DECLARE_FLEXSIM_ATTRIBUTE(sound)
DECLARE_FLEXSIM_ATTRIBUTE(soundindex)
DECLARE_FLEXSIM_ATTRIBUTE(spatialrx)
DECLARE_FLEXSIM_ATTRIBUTE(spatialry)
DECLARE_FLEXSIM_ATTRIBUTE(spatialrz)
DECLARE_FLEXSIM_ATTRIBUTE(spatialsx)
DECLARE_FLEXSIM_ATTRIBUTE(spatialsy)
DECLARE_FLEXSIM_ATTRIBUTE(spatialsz)
DECLARE_FLEXSIM_ATTRIBUTE(spatialx)
DECLARE_FLEXSIM_ATTRIBUTE(spatialy)
DECLARE_FLEXSIM_ATTRIBUTE(spatialz)
DECLARE_FLEXSIM_ATTRIBUTE(state_current)
DECLARE_FLEXSIM_ATTRIBUTE(state_profile)
DECLARE_FLEXSIM_ATTRIBUTE(state_profiles)
DECLARE_FLEXSIM_ATTRIBUTE(state_since)
DECLARE_FLEXSIM_ATTRIBUTE(stats_content)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentavg)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentgraph)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentgraphmaxpoints)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentmax)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentmin)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentsince)
DECLARE_FLEXSIM_ATTRIBUTE(stats_contentupdates)
DECLARE_FLEXSIM_ATTRIBUTE(stats_creationtime)
DECLARE_FLEXSIM_ATTRIBUTE(stats_input)
DECLARE_FLEXSIM_ATTRIBUTE(stats_lastmovetime)
DECLARE_FLEXSIM_ATTRIBUTE(stats_output)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytime)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimeavg)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimegraph)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimegraphmaxpoints)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimehisto)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimemax)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimemin)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimesince)
DECLARE_FLEXSIM_ATTRIBUTE(stats_staytimeupdates)
DECLARE_FLEXSIM_ATTRIBUTE(stats_throughput)
DECLARE_FLEXSIM_ATTRIBUTE(statusbar)
DECLARE_FLEXSIM_ATTRIBUTE(stored)
DECLARE_FLEXSIM_ATTRIBUTE(superclasses)
DECLARE_FLEXSIM_ATTRIBUTE(tabwindow)
DECLARE_FLEXSIM_ATTRIBUTE(title)
DECLARE_FLEXSIM_ATTRIBUTE(tooltip)
DECLARE_FLEXSIM_ATTRIBUTE(treeiconhide)
DECLARE_FLEXSIM_ATTRIBUTE(treeiconindex)
DECLARE_FLEXSIM_ATTRIBUTE(treeiconsilentobject)
DECLARE_FLEXSIM_ATTRIBUTE(treeicontitle)
DECLARE_FLEXSIM_ATTRIBUTE(uniqueid)
DECLARE_FLEXSIM_ATTRIBUTE(userfunctions)
DECLARE_FLEXSIM_ATTRIBUTE(variables)
DECLARE_FLEXSIM_ATTRIBUTE(viewautoconnect)
DECLARE_FLEXSIM_ATTRIBUTE(viewbackgroundcolor)
DECLARE_FLEXSIM_ATTRIBUTE(viewconnectioncolor)
DECLARE_FLEXSIM_ATTRIBUTE(viewfar)
DECLARE_FLEXSIM_ATTRIBUTE(viewfield)
DECLARE_FLEXSIM_ATTRIBUTE(viewfirstperson)
DECLARE_FLEXSIM_ATTRIBUTE(viewfocus)
DECLARE_FLEXSIM_ATTRIBUTE(viewfog)
DECLARE_FLEXSIM_ATTRIBUTE(viewfull)
DECLARE_FLEXSIM_ATTRIBUTE(viewhideallbases)
DECLARE_FLEXSIM_ATTRIBUTE(viewhideallconnectors)
DECLARE_FLEXSIM_ATTRIBUTE(viewhidealldrawcontent)
DECLARE_FLEXSIM_ATTRIBUTE(viewhidealllabels)
DECLARE_FLEXSIM_ATTRIBUTE(viewhiderouting)
DECLARE_FLEXSIM_ATTRIBUTE(viewignoreobjects)
DECLARE_FLEXSIM_ATTRIBUTE(viewlabelalignment)
DECLARE_FLEXSIM_ATTRIBUTE(viewlights)
DECLARE_FLEXSIM_ATTRIBUTE(viewmagnification)
DECLARE_FLEXSIM_ATTRIBUTE(viewnear)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointradius)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointrx)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointry)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointrz)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointx)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointy)
DECLARE_FLEXSIM_ATTRIBUTE(viewpointz)
DECLARE_FLEXSIM_ATTRIBUTE(viewprojectiontype)
DECLARE_FLEXSIM_ATTRIBUTE(viewshowgrid)
DECLARE_FLEXSIM_ATTRIBUTE(viewshowheads)
DECLARE_FLEXSIM_ATTRIBUTE(viewsnaptogrid)
DECLARE_FLEXSIM_ATTRIBUTE(viewsyncupdate)
DECLARE_FLEXSIM_ATTRIBUTE(viewwindowclean)
DECLARE_FLEXSIM_ATTRIBUTE(viewwindowopen)
DECLARE_FLEXSIM_ATTRIBUTE(viewwindowsource)
DECLARE_FLEXSIM_ATTRIBUTE(viewwindowtype)
DECLARE_FLEXSIM_ATTRIBUTE(windowtitle)
DECLARE_FLEXSIM_ATTRIBUTE(wordwrap)

#if DECLARATIONTYPE != FLEXSIM_BINDING_PHASE
}
#endif

#if DECLARATIONTYPE == FLEXSIM_DECLARATION_PHASE
	#include "declaration.h"
#elif DECLARATIONTYPE == FLEXSIM_DEFINITION_PHASE
#ifdef _WINDOWS
	#include "definition.h"
#endif
#endif

#if !defined COMPILING_FLEXSIM_CONTENT && !defined COMPILING_MODULE_DLL
#ifdef _WINDOWS
	#include "UserFuncs.h"
#endif
#endif
