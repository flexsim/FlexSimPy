#pragma once
#include <stddef.h>

#ifndef _MSC_VER
	#define MAX_PATH          260
#else
	#define PATH_MAX          4096
#endif

#ifndef engine_export
	#ifdef _MSC_VER 
		#ifdef FLEXSIM_ENGINE_COMPILE
			#define engine_export __declspec(dllexport)
		#else
			#define engine_export __declspec(dllimport)
		#endif
	#else
		#define engine_export 
	#endif
	#ifdef FLEXSIM_ENGINE_COMPILE
		#define engine_private public
	#else
		#define engine_private protected
	#endif
#endif

#ifdef FLEXSIM_ENGINE_COMPILE
#	ifndef EX_DEFINED
#		define EX_DEFINED
		extern "C" engine_export int EX(const char *T, const char * M, int showsystemconsole = 0);
#	endif
#endif

#ifdef _DEBUG
#	include <stdio.h>
#	define XS try{
#	define XE } catch(...){ \
			char error[1024]; \
			sprintf(error, "Exception in file %s, function %s at line %d, forwarding throw", __FILE__, __FUNCSIG__, __LINE__); \
			EX("", error, 1); \
			throw ; \
		}
#	define XXS try{
#	define XXE(m) }catch(...){ EX(m,"", 1); throw;}
#else
#	define XS 
#	define XE 
#	define XXS
#	define XXE(m) 
#endif

// Flexsim interface parameters
#define FLEXSIMINTERFACE int code, TreeNode * c, TreeNode * thisClass, \
void * input, void * output, TreeNode *i, CallPoint * callPoint
#define FLEXSIMINTERFACEPARAMETERS code, c, thisClass, input, output, i, callPoint


#define CHECKNEW(p,m)\
{\
  if (!p) \
  {\
   char buffer[1024];\
   /*mpt(m);*/\
  }\
}

#define optionalthrow throw
//#define optionalthrow mpt("warning: throw - code may have been terminated."); mpr(); 

#define guardstart(name) try{

#define guardend(name) }catch(...){  mpt("exception: "); mpt(#name);mpr();  optionalthrow;}

#define GUARD(x,y)  try{x;}catch(...){ mpt(y); mpt("\n"); optionalthrow;}

#define n10argsdefaultinterface double n1=0,double n2=0,double n3=0,double n4=0,double n5=0,double n6=0,double n7=0,double n8=0,double n9=0,double n10=0

#define n10argsinterface double n1,double n2,double n3,double n4,double n5,double n6,double n7,double n8,double n9,double n10

#define n10argstovarsconvert Variant::interpretLegacyDouble(n1), \
	Variant::interpretLegacyDouble(n2), \
	Variant::interpretLegacyDouble(n3), \
	Variant::interpretLegacyDouble(n4), \
	Variant::interpretLegacyDouble(n5), \
	Variant::interpretLegacyDouble(n6), \
	Variant::interpretLegacyDouble(n7), \
	Variant::interpretLegacyDouble(n8), \
	Variant::interpretLegacyDouble(n9), \
	Variant::interpretLegacyDouble(n10) \

#define n10args n1,n2,n3,n4,n5,n6,n7,n8,n9,n10

#define n10varsdefaultinterface const Variant& n1 = Variant(), const Variant& n2 = Variant(), const Variant& n3 = Variant(), const Variant& n4 = Variant(), const Variant& n5 = Variant(), const Variant& n6 = Variant(), const Variant& n7 = Variant(), const Variant& n8 = Variant(), const Variant& n9 = Variant(), const Variant& n10 = Variant()
#define n10varsinterface const Variant& n1, const Variant& n2, const Variant& n3, const Variant& n4, const Variant& n5, const Variant& n6, const Variant& n7, const Variant& n8, const Variant& n9, const Variant& n10

#define n10vars n1, n2, n3, n4, n5, n6, n7, n8, n9, n10
#define n10varslegacy n1.forceLegacyDouble(), n2.forceLegacyDouble(), n3.forceLegacyDouble(), n4.forceLegacyDouble(), n5.forceLegacyDouble(), n6.forceLegacyDouble(), n7.forceLegacyDouble(), n8.forceLegacyDouble(), n9.forceLegacyDouble(), n10.forceLegacyDouble()

#define n30varsdefaultinterface const Variant& n1 = Variant(), const Variant& n2 = Variant(), const Variant& n3 = Variant(), const Variant& n4 = Variant(), const Variant& n5 = Variant(), const Variant& n6 = Variant(), const Variant& n7 = Variant(), const Variant& n8 = Variant(), const Variant& n9 = Variant(), const Variant& n10 = Variant(), \
	const Variant& n11 = Variant(), const Variant& n12 = Variant(), const Variant& n13 = Variant(), const Variant& n14 = Variant(), const Variant& n15 = Variant(), const Variant& n16 = Variant(), const Variant& n17 = Variant(), const Variant& n18 = Variant(), const Variant& n19 = Variant(), const Variant& n20 = Variant(), \
	const Variant& n21 = Variant(), const Variant& n22 = Variant(), const Variant& n23 = Variant(), const Variant& n24 = Variant(), const Variant& n25 = Variant(), const Variant& n26 = Variant(), const Variant& n27 = Variant(), const Variant& n28 = Variant(), const Variant& n29 = Variant(), const Variant& n30 = Variant()

#define n30varsinterface const Variant& n1, const Variant& n2, const Variant& n3, const Variant& n4, const Variant& n5, const Variant& n6, const Variant& n7, const Variant& n8, const Variant& n9, const Variant& n10, \
	const Variant& n11, const Variant& n12, const Variant& n13, const Variant& n14, const Variant& n15, const Variant& n16, const Variant& n17, const Variant& n18, const Variant& n19, const Variant& n20, \
	const Variant& n21, const Variant& n22, const Variant& n23, const Variant& n24, const Variant& n25, const Variant& n26, const Variant& n27, const Variant& n28, const Variant& n29, const Variant& n30

#define n30vars n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30
#define n30varslegacy n1.forceLegacyDouble(), n2.forceLegacyDouble(), n3.forceLegacyDouble(), n4.forceLegacyDouble(), n5.forceLegacyDouble(), n6.forceLegacyDouble(), n7.forceLegacyDouble(), n8.forceLegacyDouble(), n9.forceLegacyDouble(), n10.forceLegacyDouble() \
	n11.forceLegacyDouble(), n12.forceLegacyDouble(), n13.forceLegacyDouble(), n14.forceLegacyDouble(), n15.forceLegacyDouble(), n16.forceLegacyDouble(), n17.forceLegacyDouble(), n18.forceLegacyDouble(), n19.forceLegacyDouble(), n20.forceLegacyDouble(), \
	n21.forceLegacyDouble(), n22.forceLegacyDouble(), n23.forceLegacyDouble(), n24.forceLegacyDouble(), n25.forceLegacyDouble(), n26.forceLegacyDouble(), n27.forceLegacyDouble(), n28.forceLegacyDouble(), n29.forceLegacyDouble(), n30.forceLegacyDouble()

#define n30argsinterface double n1,double n2,double n3,double n4,double n5,double n6,double n7,double n8,double n9,double n10,\
  double n11,double n12,double n13,double n14,double n15,double n16,double n17,double n18,double n19,double n20,\
double n21,double n22,double n23,double n24,double n25,double n26,double n27,double n28,double n29,double n30

#define n30argsdefaultinterface double n1=0,double n2=0,double n3=0,double n4=0,double n5=0,double n6=0,double n7=0,double n8=0,double n9=0,double n10=0,\
  double n11=0,double n12=0,double n13=0,double n14=0,double n15=0,double n16=0,double n17=0,double n18=0,double n19=0,double n20=0,\
double n21=0,double n22=0,double n23=0,double n24=0,double n25=0,double n26=0,double n27=0,double n28=0,double n29=0,double n30=0

#define n30args n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,\
  n11,n12,n13,n14,n15,n16,n17,n18,n19,n20,\
n21,n22,n23,n24,n25,n26,n27,n28,n29,n30

#ifdef _MSC_VER
#	define visible extern "C" __declspec(dllexport)
#	define windowsvisible extern "C" __declspec(dllexport)
#else
#	define visible extern "C"
#	define windowsvisible 
#endif

#define RETURN_TYPE_UNRESOLVED 0
#define RETURN_TYPE_NUMBER 1
#define RETURN_TYPE_STRING 2
#define RETURN_TYPE_VARIANT 3

#define TYPE_CHECK_NUMBER_BIT 0x1
#define TYPE_CHECK_STRING_BIT 0x2
#define TYPE_CHECK_NODE_BIT 0x4
#define TYPE_CHECK_ALL_BITS 0x7

#define CALLBACKPARAMS HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam

#define SAFENODE &TreeNode::failSafeLink

# define parametersinterface CallPoint * callpoint
# define parameters callpoint

#ifndef FLEXSIM_ENGINE_COMPILE
# define o(type,instance) (*(instance->object<type>()))
#endif
#define objectAs(T) template object<T>()

#define CppStart 
#define CppEnd 
#define ObjectFunctionStart try { int functionlocaliterator=0; double count=0;
#define ObjectFunctionEnd(functionname) return 0; } catch(...) {\
		reportobjectfunctionexception((char*)functionname, c, i, thisClass);mpr();\
		logevent((char*)"EXCEPTION", c, i);\
		throw;\
	} 
#define ObjectMethodStart try {
#define ObjectMethodEnd(objectname) } catch(...) {reportobjectfunctionexception((char*)objectname, this->holder, NULL, NULL); throw;} 
#define ObjectMethodEndStatic(objectname) } catch(...) {reportobjectfunctionexception((char*)objectname, NULL, NULL, NULL); throw;} 
#define GlobalFunctionStart try {
#define GlobalFunctionEnd(functionname) } catch(...) {reportobjectfunctionexception((char*)functionname, NULL, NULL, NULL); throw;} 

#define forobjecttreeunder(__top__)\
	for(treenode a = first(__top__); objectexists(a); a = nextforobjecttreeunder(a, __top__))
#define forobjectlayerunder(__top__)\
	for (treenode a = first(__top__); objectexists(a); a = next(a))
#define forobjectsbefore(__node__)\
	for (treenode a = prev(__node__); objectexists(a) && getrank(a) >= 1; a = prev(a))
#define forobjectsbehind(__node__)\
	for (treenode a = next(__node__); objectexists(a); a = next(a))
#define forobjectselectionset(node)\
for(treenode a = NULL, nextforobjectselectionset(&a, node); objectexists(a); nextforobjectselectionset(&a, node))

#define BINDFLAG_PORTCACHE			0x00000001
#define UNBINDFLAG_PORTCACHE		0x00000002
#define BINDFLAG_IGNOREMEDIA		0x00000004
#define BINDFLAG_IGNORECLASSES		0x00000008
#define BINDFLAG_IGNORERESET		0x00000010
#define BINDFLAG_DESTROYONRESET		0x00000020
#define BINDFLAG_BINDVARIABLES		0x00000040

// model unit macros
#define TIME_RANK 1
#define LENGTH_RANK 2
#define FLUID_RANK 3
#define DATE_TIME_RANK 4
#define TIME_FORMAT_RANK 5
#define DATE_FORMAT_RANK 6

#define START_RANK 1
#define CURRENT_RANK 2
#define STOP_RANK 3
#define WARMUP_RANK 4

#define NAME_RANK 1
#define ABBREVIATION_RANK 2
#define MULTIPLE_RANK 3
#define NAME_PLURAL_RANK 4
#define TYPE_RANK 5

#define SM_RESET 1
#define SM_MESSAGE 2
#define SM_EVENT 3
#define SM_DRAW 4

#define SM_INOPEN 5
#define SM_OUTOPEN 6
#define SM_ACCEPT 7
#define SM_GIVE 8
#define SM_ENTER 9
#define SM_EXIT 10

#define SM_COMPILE 11
#define SM_CREATE 12
#define SM_DESTROY 13
#define SM_UNDO 14
#define SM_CLICK 15
#define SM_RUNSTART 16
#define SM_RUNWARM 17
#define SM_RUNEND 18
#define SM_PRELISTEN 19
#define SM_LISTEN 20
#define SM_PREDRAW 21
#define SM_DRAWPLANAR 22
#define SM_PREDRAWPLANAR 23

#define SM_STATECHANGE 24
#define SM_DRAG 25

#define SM_MAX_MESSAGES 27 // If you add more messages, make sure you change this to the max message plus 1

#define DATA_FLOAT 1
#define DATA_BYTEBLOCK 2
#define DATA_POINTERCOUPLING 3
#define DATA_OBJECT 4
//#define DATA_PARTICLE 5
#define DATA_BUNDLE 6
#define DATA_SIMPLE 7

#define LISTENER_INFO_CODE 1
#define LISTENER_INFO_ASSOCIATED 2
#define LISTENER_INFO_COUPLING 3
#define LISTENER_INFO_OVERRIDE_RETURN_VALUE 4

// Constants
#define KINEMATIC_X  0
#define KINEMATIC_Y  1
#define KINEMATIC_Z  2
#define KINEMATIC_RX  3
#define KINEMATIC_RY  4
#define KINEMATIC_RZ  5
#define KINEMATIC_VX  6
#define KINEMATIC_VY  7
#define KINEMATIC_VZ  8
#define KINEMATIC_VRX  9
#define KINEMATIC_VRY  10
#define KINEMATIC_VRZ  11
#define KINEMATIC_NR  12
#define KINEMATIC_STARTTIME  13
#define KINEMATIC_ENDTIME  14
#define KINEMATIC_ARRIVALTIME  15
#define KINEMATIC_STARTSPEED  16
#define KINEMATIC_ENDSPEED  17
#define KINEMATIC_ACC1  18
#define KINEMATIC_ACC2  19
#define KINEMATIC_PEAKSPEED  20
#define KINEMATIC_ACC1TIME  21
#define KINEMATIC_PEAKTIME  22
#define KINEMATIC_ACC2TIME  23
#define KINEMATIC_TOTALDIST  24
#define KINEMATIC_CUMULATIVEDIST  25
#define KINEMATIC_TOTALX  26
#define KINEMATIC_TOTALY  27
#define KINEMATIC_TOTALZ  28
#define KINEMATIC_TOTALRDIST  29
#define KINEMATIC_CUMULATIVERDIST  30
#define KINEMATIC_TOTALRX  31
#define KINEMATIC_TOTALRY  32
#define KINEMATIC_TOTALRZ  33
#define KINEMATIC_VELOCITY  34
#define KINEMATIC_RVELOCITY  35
#define KINEMATIC_ENDDIST  36
#define KINEMATIC_ENDRDIST  37
#define KINEMATIC_TYPE  38

#define KINEMATIC_TRAVEL  1
#define KINEMATIC_ROTATE  2
#define KINEMATIC_TURNXY  3
#define KINEMATIC_TURNYZ  4
#define KINEMATIC_TURNZX  5



inline void * doubletoptr(double x)
{
//	return ((void**)&x)[0];
	return (void*)(size_t)x;
}
inline double ptrtodouble(void* x)
{
//	return ((double*)&x)[0];
	return (double)(size_t)x;
}


#if defined FLEXSIM_ENGINE_COMPILE || defined COMPILING_FLEXSIM_CONTENT
	#define content_private public
#else
	#define content_private protected
#endif

#if defined FLEXSIM_ENGINE_COMPILE || defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
	#define module_private public
#else
	#define module_private protected
#endif

template <class Dest, class Src>
Dest force_cast(Src src)
{
	union
	{
		Dest d;
		Src s;
	} convertor;
	if constexpr (sizeof(Dest) != sizeof(Src))
		memset(&convertor, 0, sizeof(Dest));
	convertor.s = src;
	return convertor.d;
}
