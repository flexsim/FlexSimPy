// The following license applies to all parts of this file.
/*************************************************
The MIT License

Copyright (c) 2013 FlexSim Software Products Inc.

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

#ifndef FLEXSIMDEFS_H
#define FLEXSIMDEFS_H

#ifdef _WINDOWS
#include <windows.h>
#include "glew.h"
#include "wglew.h"
#else
#define GLEW_NO_GLU
#include "glew.h"
#endif

#include <string>
#include <cmath>
#include <climits>

using std::string;

#define YY_NO_UNISTD_H
#include "Platform.h"

#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL

	#define CONTENT_DLL_COMPILE

	#include "BasicClasses.h"
	#include "BasicMacros.h"

	namespace FlexSim {
		visible int swapnoderanks(TreeNode*, int, int);
		visible int validlink(TreeNode*, const char*);
	}

	#include "TreeNode.h"

	//namespace FlexSim {
	//extern double(*_parval)(int, CallPoint *);
	//}

	#define cellrc cellrowcolumn
	#define mpt(x) _mpt(x)
	#define mpd(x) _mpd(x)
	#define mpr(x) _mpr(x)
	#define mpf(x) _mpf(x)

#else
	namespace FlexSim {
		class TreeNode;
		typedef TreeNode* treenode;
		class ByteBlock;
		class CallPoint;
		class EventDataStruct;
		typedef EventDataStruct eventdatastruct;

		extern double(*_parval)(int, CallPoint *);

		extern void* (*flexsimmalloc)(size_t);
		extern void(*flexsimfree)(void*);
		#define parnode(__a__) _parnode(__a__, callPoint)
		#define parval(__a__) _parval(__a__, callPoint)
		#define parstr(__a__) _parstr(__a__, callPoint)
	}
		
	#include "BasicMacros.h"

#endif

#ifndef FLEXSIM_TARGET_VERSION
	#define FLEXSIM_TARGET_VERSION 9900
#endif

// direct c++ parval
#define stringreturn(str) stringreturn(str, callPoint)
#define msgsendingobject parnode(1)

#define ip ((size_t)edsdata((EventDataStruct *)input))
#define eventdata ((char *)edsdata((EventDataStruct *)input))
#define eventdataint ((size_t)edsdata((EventDataStruct *)input))
#define eventdatanode ((treenode )edsdata((EventDataStruct *)input))
#define eventdatastring ((char *)edsdata((EventDataStruct *)input))
#define eventstring ((char *)edsdata((EventDataStruct *)input))
#define eventcode edscode((EventDataStruct *)input)

#define FLEXSIM_DECLARATION_PHASE 1
#define FLEXSIM_DEFINITION_PHASE 2
#define FLEXSIM_BINDING_PHASE 3

#if defined COMPILING_FLEXSIM_CONTENT || defined COMPILING_MODULE_DLL
	#define DECLARATIONTYPE FLEXSIM_DECLARATION_PHASE
	#include "FlexsimFuncs.h"

	// I need to include simpledatatype after flexsimfuncs, because sdt needs some of
	// the stuff available in flexsimfuncs
	#include "SimpleDataType.h"
	#include "ObjectDataType.h"
	#include "CouplingDataType.h"
	#include "CppLambdaCommands.h"
	#include "FlexSimEvent.h"
	#include "Mesh.h"
	#include "List.h"
	#include "StatisticsCollector.h"
	#include "CalculatedTable.h"
	#include "ChartTemplate.h"
	#include "DatabaseConnection.h"
	#include "ColorPalette.h"
	#include "TextMesh.h"
	#include "Light.h"
	#include "ParameterTable.h"
	#include "Experimenter.h"
	#include "DataTypes.h"

	#if defined COMPILING_MODULE_DLL
		#include "allobjects.h"
	#endif

#else

#ifdef _MSC_VER
#	define visible extern "C" __declspec(dllexport)
#else
#	define visible 
#endif
	namespace FlexSim {
	typedef char* (*customdisplayfunction)(treenode, int);
	}

	#define mpt _mpt
	#define mpd _mpd
	#define mpf _mpf
	#define mpr _mpr
	#define cellrc cellrowcolumn

	#define n10args                         n1  ,        n2  ,        n3  ,        n4  ,        n5  ,        n6  ,        n7  ,        n8  ,        n9  ,       n10  
	#define n30args                         n1  ,        n2  ,        n3  ,        n4  ,        n5  ,        n6  ,        n7  ,        n8  ,        n9  ,       n10  ,\
	                                       n11  ,       n12  ,       n13  ,       n14  ,       n15  ,       n16  ,       n17  ,       n18  ,       n19  ,       n20  ,\
	                                       n21  ,       n22  ,       n23  ,       n24  ,       n25  ,       n26  ,       n27  ,       n28  ,       n29  ,       n30  
	#define n10argsinterface        double  n1  ,double  n2  ,double  n3  ,double  n4  ,double  n5  ,double  n6  ,double  n7  ,double  n8  ,double  n9  ,double n10
	#define n30argsinterface        double  n1  ,double  n2  ,double  n3  ,double  n4  ,double  n5  ,double  n6  ,double  n7  ,double  n8  ,double  n9  ,double n10  ,\
	                                double n11  ,double n12  ,double n13  ,double n14  ,double n15  ,double n16  ,double n17  ,double n18  ,double n19  ,double n20  ,\
	                                double n21  ,double n22  ,double n23  ,double n24  ,double n25  ,double n26  ,double n27  ,double n28  ,double n29  ,double n30  
	#define n10argsdefaultinterface double  n1=0,double  n2=0,double  n3=0,double  n4=0,double  n5=0,double  n6=0,double  n7=0,double  n8=0,double  n9=0,double n10=0
	#define n30argsdefaultinterface double  n1=0,double  n2=0,double  n3=0,double  n4=0,double  n5=0,double  n6=0,double  n7=0,double  n8=0,double  n9=0,double n10=0,\
	                                double n11=0,double n12=0,double n13=0,double n14=0,double n15=0,double n16=0,double n17=0,double n18=0,double n19=0,double n20=0,\
	                                double n21=0,double n22=0,double n23=0,double n24=0,double n25=0,double n26=0,double n27=0,double n28=0,double n29=0,double n30=0

	#define FLEXSIMINTERFACE int code, treenode c, treenode theclass, void * input, void * output, treenode i, CallPoint * callPoint
	#define FLEXSIMINTERFACEPARAMETERS code, c, theclass, input, output, i, callPoint

	// Constants

	// Constants group: GLOBAL
	#define GLOBAL_DELAYINDEFINITE  1000000000
	#define GLOBAL_UNREACHABLE  -1

	// Constants group: EVENT
	#define EVENT_OPENINPUTS  1
	#define EVENT_OPENOUTPUTS  2
	#define EVENT_PROCESSFINISH  3
	#define EVENT_CREATEPART  4
	#define EVENT_DESTROYPRODUCT  5
	#define EVENT_CONVEYEND  6
	#define EVENT_BEGINLOADTIME  7
	#define EVENT_BEGINUNLOADTIME  8
	#define EVENT_ENDLOADTIME  9
	#define EVENT_ENDUNLOADTIME  10
	#define EVENT_ENDDELAYTIME  11
	#define EVENT_BEGINDOWNTIME  12
	#define EVENT_ENDDOWNTIME  13
	#define EVENT_ENDDOWNTIMENORESUME  14
	#define EVENT_ENDWAITTIME  15
	#define EVENT_MEETBATCHQTY  16
	#define EVENT_ENDTRAVELTIME  17
	#define EVENT_ENDSETUP  18
	#define EVENT_SENDMESSAGE  19
	#define EVENT_LISTEN  20
	#define EVENT_COLLISIONCHECK  21
	#define EVENT_STARTLOADTIME  22
	#define EVENT_STARTUNLOADTIME  23
	#define EVENT_USEROPENOUTPUT  24
	#define EVENT_USEROPENINPUT  25

	// Constants group: TASKTYPE
	#define TASKTYPE_LOAD  1
	#define TASKTYPE_FRLOAD  2
	#define TASKTYPE_UNLOAD  3
	#define TASKTYPE_FRUNLOAD  4
	#define TASKTYPE_UTILIZE  5
	#define TASKTYPE_STOPREQUESTBEGIN  6
	#define TASKTYPE_STOPREQUESTFINISH  7
	#define TASKTYPE_TRAVEL  8
	#define TASKTYPE_TRAVELTOLOC  9
	#define TASKTYPE_TRAVELRELATIVE  10
	#define TASKTYPE_BREAK  11
	#define TASKTYPE_DELAY  12
	#define TASKTYPE_SENDMESSAGE  13
	#define TASKTYPE_TE_ALLOCATED  14
	#define TASKTYPE_MOVEOBJECT  15
	#define TASKTYPE_DESTROYOBJECT  16
	#define TASKTYPE_SETNODENUM  17
	#define TASKTYPE_PICKOFFSET  18
	#define TASKTYPE_PLACEOFFSET  19
	#define TASKTYPE_TAG  20
	#define TASKTYPE_CT_ALLOCATE  21
	#define TASKTYPE_CT_DEALLOCATE  22
	#define TASKTYPE_CT_SYNC  23
	#define TASKTYPE_CALLSUBTASKS  24
	#define TASKTYPE_TE_RETURN  25
	#define TASKTYPE_TE_STOP  26
	#define TASKTYPE_MILESTONE  27
	#define TASKTYPE_CT_MULTIALLOCATE  28
	#define TASKTYPE_NODEFUNCTION 29

	// Constants group: TASK
	#define TASK_TYPE  1
	#define TASK_INVOLVED1  2
	#define TASK_INVOLVED2  3
	#define TASK_VAR1  4
	#define TASK_VAR2  5
	#define TASK_VAR3  6
	#define TASK_VAR4  7
	#define TASK_CONTENT  3

	// Constants group: TASKSTATE
	#define TASKSTATE_UNFINISHED  1
	#define TASKSTATE_ACTIVE  2
	#define TASKSTATE_FINISHED  3
	#define TASKSTATE_COORDINATED  4

	// Constants group: TASKSEQUENCE
	#define TASKSEQUENCE_TASKS  1
	#define TASKSEQUENCE_PRIORITY  2
	#define TASKSEQUENCE_PREEMPTING  3
	#define TASKSEQUENCE_TOTALTASKS  4
	#define TASKSEQUENCE_CONTENT  4

	// Constants group: PREEMPT
	#define PREEMPT_NOT  0
	#define PREEMPT_ONLY  1
	#define PREEMPT_AND_ABORT_ACTIVE  2
	#define PREEMPT_AND_ABORT_ALL  3

	// Constants group: STATE
	#define STATE_IDLE  1
	#define STATE_PROCESSING  2
	#define STATE_BUSY  3
	#define STATE_BLOCKED  4
	#define STATE_GENERATING  5
	#define STATE_EMPTY  6
	#define STATE_COLLECTING  7
	#define STATE_RELEASING  8
	#define STATE_WAITING_FOR_OPERATOR  9
	#define STATE_WAITING_FOR_TRANSPORT  10
	#define STATE_BREAKDOWN  11
	#define STATE_SCHEDULED_DOWN  12
	#define STATE_CONVEYING  13
	#define STATE_TRAVEL_EMPTY  14
	#define STATE_TRAVEL_LOADED  15
	#define STATE_OFFSET_TRAVEL_EMPTY  16
	#define STATE_OFFSET_TRAVEL_LOADED  17
	#define STATE_LOADING  18
	#define STATE_UNLOADING  19
	#define STATE_DOWN  20
	#define STATE_SETUP  21
	#define STATE_UTILIZE  22
	#define STATE_FULL  23
	#define STATE_NOT_EMPTY  24
	#define STATE_FILLING  25
	#define STATE_STARVED  26
	#define STATE_MIXING  27
	#define STATE_FLOWING  28
	#define STATE_ALLOCATED_IDLE  29
	#define STATE_OFF_SHIFT  30
	#define STATE_CHANGE_OVER  31
	#define STATE_REPAIR  32
	#define STATE_MAINTENANCE  33
	#define STATE_LUNCH  34
	#define STATE_ON_BREAK  35
	#define STATE_SUSPEND  36
	#define STATE_AVAILABLE  37
	#define STATE_PREPROCESSING  38
	#define STATE_POSTPROCESSING  39
	#define STATE_INSPECTING  40
	#define STATE_OPERATING  41
	#define STATE_STANDBY  42
	#define STATE_PURGING  43
	#define STATE_CLEANING  44
	#define STATE_ACCELERATING  45
	#define STATE_MAXSPEED  46
	#define STATE_DECELERATING  47
	#define STATE_STOPPED  48
	#define STATE_WAITING  49
	#define STATE_ACCUMULATING  50
	#define STATE_END  51

	// Constants group: DATATYPE
	#define DATATYPE_NUMBER  1
	#define DATATYPE_STRING  2
	#define DATATYPE_COUPLING  3
	#define DATATYPE_OBJECT  4
	#define DATATYPE_PARTICLE  5
	#define DATATYPE_BUNDLE  6

	// Constants group: DATA
	#ifndef DATA_FLOAT
		#define DATA_FLOAT  1
		#define DATA_BYTEBLOCK  2
		#define DATA_POINTERCOUPLING  3
		#define DATA_OBJECT  4
		#define DATA_PARTICLE  5
		#define DATA_BUNDLE  6
		#define DATA_SIMPLE  7
	#endif

	// Constants group: ARRIVALMODE
	#define ARRIVALMODE_INTERARRIVALTIME  1
	#define ARRIVALMODE_SCHEDULE  2
	#define ARRIVALMODE_SEQUENCE  3

	// Constants group: FRSTATE
	#define FRSTATE_INQUEUE  1
	#define FRSTATE_READY  2
	#define FRSTATE_MOVEREQUESTED  3

	// Constants group: QUEUENODERANK
	#define QUEUENODERANK_STATE  1
	#define QUEUENODERANK_SENDTO  2
	#define QUEUENODERANK_VAR1  3
	#define QUEUENODERANK_VAR2  4
	#define QUEUENODERANK_VAR3  5
	#define QUEUENODERANK_INVOLVED  6

	// Constants group: SPACING
	#define SPACING_LENGTH  1
	#define SPACING_LENGTHPLUSSETVALUE  2
	#define SPACING_SETVALUE  3

	// Constants group: PORT
	#define PORT_OPENVARIABLE  1
	#define PORT_INSIDECOUPLING  2
	#define PORT_EXTRAVAR1  3
	#define PORT_EXTRAVAR2  4
	#define PORT_EXTRAVAR3  5
	#define PORT_EXTRAVAR4  6
	#define PORT_EXTRAVAR5  7
	#define PORT_EXTRAVAR6  8
	#define PORT_EXTRAVAR7  9
	#define PORT_EXTRAVAR8  10
	#define PORT_EXTRAVAR9  11
	#define PORT_EXTRAVAR10  12
	#define PORT_EXTRAVAR11  13
	#define PORT_EXTRAVAR12  14
	#define PORT_EXTRAVAR13  15
	#define PORT_EXTRAVAR14  16
	#define PORT_EXTRAVAR15  17
	#define PORT_CONNECTEDTO  PORT_EXTRAVAR1
	#define PORT_DISTANCE  PORT_EXTRAVAR2
	#define PORT_SPLINEHERE  PORT_EXTRAVAR3
	#define PORT_FILLEDLENGTH  PORT_EXTRAVAR4
	#define PORT_ACTIVE  PORT_EXTRAVAR5
	#define PORT_INOPEN  PORT_EXTRAVAR6
	#define PORT_LASTEXITTIME  PORT_EXTRAVAR7
	#define PORT_LASTEXITSIZE  PORT_EXTRAVAR8
	#define PORT_LASTENTRYPORT  PORT_EXTRAVAR9
	#define PORT_SPACING  PORT_EXTRAVAR10
	#define PORT_SPLINECOUPLING  PORT_EXTRAVAR11
	#define PORT_SPEED  PORT_EXTRAVAR12
	#define PORT_USERDISTANCE  PORT_EXTRAVAR13
	#define PORT_SPLINEENDROT  PORT_EXTRAVAR14
	#define PORT_BLOCKEDLENGTH  PORT_EXTRAVAR15

	// Constants group: VISUALOBJECT
	#define VISUALOBJECT_PLANE  1
	#define VISUALOBJECT_CUBE  2
	#define VISUALOBJECT_COLUMN  3
	#define VISUALOBJECT_SPHERE  4
	#define VISUALOBJECT_MODEL  5
	#define VISUALOBJECT_TEXT  6
	#define VISUALOBJECT_SLIDE  7

	// Constants group: EDGE
	#define EDGE_NOCONNECTION  1
	#define EDGE_PASSING  2
	#define EDGE_NONPASSING  3

	// Constants group: DEBUG
	#define DEBUG__FLEXSIMOBJECT  1
	#define DEBUG__NAVIGATOR  2
	#define DEBUG__FIXEDRESOURCE  3
	#define DEBUG__TASKEXECUTER  4
	#define DEBUG__NETWORKNAVIGATOR  5
	#define DEBUG__NETWORKNODE  6
	#define DEBUG__PROCESSOR  7
	#define DEBUG__SOURCE  8
	#define DEBUG__QUEUE  9
	#define DEBUG__CONVEYOR  10
	#define DEBUG__COMBINER  11
	#define DEBUG__SEPARATOR  12
	#define DEBUG__RACK  13
	#define DEBUG__DISPATCHER  14
	#define DEBUG__OPERATOR  15
	#define DEBUG__TRANSPORTER  16
	#define DEBUG__CRANE  17
	#define DEBUG__ASRSVEHICLE  18
	#define DEBUG__SINK  19
	#define DEBUG__MODEL  20
	#define DEBUG__NORECYCLE  21

	// Constants group: CONVSECTYPE
	#define CONVSECTYPE_STRAIGHT  1
	#define CONVSECTYPE_CURVED  2

	// Constants group: CONVSEC
	#define CONVSEC_TYPE  1
	#define CONVSEC_LENGTH  2
	#define CONVSEC_RISE  3
	#define CONVSEC_ANGLE  4
	#define CONVSEC_RADIUS  5
	#define CONVSEC_NROFLEGS  6
	#define CONVSEC_SECLENGTH  7
	#define CONVSEC_STARTLENGTH  8
	#define CONVSEC_STARTX  9
	#define CONVSEC_STARTY  10
	#define CONVSEC_STARTZ  11
	#define CONVSEC_STARTANGLE  12

	// Constants group: CLASSTYPE
	#define CLASSTYPE_ODT  1
	#define CLASSTYPE_FLEXSIMOBJECT  2
	#define CLASSTYPE_FIXEDRESOURCE  4
	#define CLASSTYPE_DISPATCHER  8
	#define CLASSTYPE_TASKEXECUTER  16
	#define CLASSTYPE_NAVIGATOR  32
	#define CLASSTYPE_PROCESSOR  64
	#define CLASSTYPE_NETWORKNODE  128
	#define CLASSTYPE_VISUALTOOL  256
	#define CLASSTYPE_CONVEYOR  512
	#define CLASSTYPE_TRAFFICCONTROLLER  1024
	#define CLASSTYPE_MTBFMTTR  2048
	#define CLASSTYPE_MERGESORT  4096
	#define CLASSTYPE_WANTCONNECTLOGIC  8192

	// Constants group: RECORDER_DATA
	#define RECORDER_DATA_TABLE  1
	#define RECORDER_DATA_STANDARD  2
	#define RECORDER_DATA_USERDEFINED  3

	// Constants group: RECORDER_GRAPH
	#define RECORDER_GRAPH_BAR  1
	#define RECORDER_GRAPH_PIE  2
	#define RECORDER_GRAPH_LINE  3
	#define RECORDER_GRAPH_HISTO  4

	// Constants group: RECORDER_OUTPUT
	#define RECORDER_OUTPUT_GRAPH  1
	#define RECORDER_OUTPUT_POINT  2
	#define RECORDER_OUTPUT_TABLE  3

	// Constants group: DBMODE
	#define DBMODE_CLOSED  0
	#define DBMODE_SQL  1
	#define DBMODE_TABLE  2

	// Constants group: ATTCOPY
	#define ATTCOPY_ALL  1
	#define ATTCOPY_SPATIAL  2
	#define ATTCOPY_OFFSETS  4
	#define ATTCOPY_VISUAL  8
	#define ATTCOPY_MEDIA  16
	#define ATTCOPY_LABELS  32
	#define ATTCOPY_VARIABLES  64
	#define ATTCOPY_DESCRIPTIVE  128
	#define ATTCOPY_TABLES  256

	// Constants group: SOCKET
	#define SOCKET_BLOCK  0
	#define SOCKET_NOBLOCK  1

	// Constants group: ADV_FUNC
	#define ADV_FUNC_CLASSTYPE  1
	#define ADV_FUNC_DRAGCONNECTION  2
	#define ADV_FUNC_CLICK  3
	#define ADV_FUNC_KEYEDCLICK  4

	// Constants group: KINEMATIC
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
	#define KINEMATIC_TURN_XY  3
	#define KINEMATIC_TURN_YZ  4
	#define KINEMATIC_TURN_ZX  5

	// Constants group: TIME
	#define TIME_NAME  1
	#define TIME_PLURAL_NAME  2
	#define TIME_ABBREVIATION  3
	#define TIME_MULTIPLE  4

	// Constants group: LENGTH
	#define LENGTH_NAME  11
	#define LENGTH_PLURAL_NAME  12
	#define LENGTH_ABBREVIATION  13
	#define LENGTH_MULTIPLE  14

	// Constants group: FLUID
	#define FLUID_NAME  21
	#define FLUID_PLURAL_NAME  22
	#define FLUID_ABBREVIATION  23
	#define FLUID_MULTIPLE  24
	#define FLUID_TYPE 25

	//Constants group: DATE & TIME
	#define DATE_TIME_NODE 31
	#define START_TIME 32
	#define START_TIME_NODE 33
	#define CURRENT_TIME 34
	#define CURRENT_TIME_NODE 35
	#define STOP_TIME 36
	#define STOP_TIME_NODE 37
	#define TIME_FORMAT 38
	#define DATE_FORMAT 39

	//Constants group: START TIME
	#define START_YEAR 41
	#define START_MONTH 42
	#define START_DAY 43
	#define START_DAYOFWEEK 44
	#define START_HOUR 45
	#define START_MINUTE 46
	#define START_SECOND 47
	#define START_MILLISECOND 48

	//Constants group: CURRENT TIME
	#define CURRENT_YEAR 51
	#define CURRENT_YEAR_OF_TIME 52
	#define CURRENT_MONTH_OF_YEAR 53
	#define CURRENT_DAY 54
	#define CURRENT_DAY_OF_MONTH 55
	#define CURRENT_DAY_OF_WEEK 56
	#define CURRENT_HOUR 57
	#define CURRENT_HOUR_OF_DAY 58
	#define CURRENT_MINUTE 59
	#define CURRENT_MINUTE_OF_HOUR 60
	#define CURRENT_SECOND 61
	#define CURRENT_SECOND_OF_MINUTE 62
	#define CURRENT_MILLISECOND 63
	#define CURRENT_MILLISECOND_OF_SECOND 64

	// Constants group: MTBF_MTTR
	#define MTBF_MTTR_BEGIN_DOWN_TIME  1
	#define MTBF_MTTR_BEGIN_DOWN_TIME_NO_RESUME  2
	#define MTBF_MTTR_FINISH_DOWN_TIME  3
	#define MTBF_MTTR_FINISH_DOWN_TIME_NO_RESUME  4

	#define FLEXSIM_MESSAGE_USER_CALLBACK 2001
	#define FLEXSIM_MESSAGE_USER_NODEFUNCTION 2002

	/* Mesh Class */
	#define MESH_POSITION               0x0
	#define MESH_TEX_COORD1             0x0010000
	#define MESH_TEX_COORD2             0x0020000
	#define MESH_TEX_COORD3             0x0040000
	#define MESH_NORMAL                 0x0080000
	#define MESH_AMBIENT                0x0100000
	#define MESH_DIFFUSE                0x0200000
	#define MESH_DIFFUSE4               0x0400000
	#define MESH_AMBIENT_AND_DIFFUSE    0x0800000
	#define MESH_AMBIENT_AND_DIFFUSE4   0x1000000
	#define MESH_SPECULAR               0x2000000
	#define MESH_SHININESS              0x4000000
	#define MESH_EMISSIVE               0x8000000

	#define MESH_STATIC_DRAW 			0x1
	#define MESH_DYNAMIC_DRAW 			0x2
	#define MESH_INDEXED 				0x4

	#define MESH_PER_VERTEX_ATTRIBS 1
	#define MESH_PER_MESH_ATTRIBS 2
	#define MESH_FLAGS 3
	#define MESH_NR_VERTS 4
	#define MESH_GET_INDEX 5

	#define MESH_COLOR_RED 0
	#define MESH_COLOR_GREEN 1
	#define MESH_COLOR_BLUE 2
	#define MESH_COLOR_ALPHA 3
	#define MESH_POS_X 0
	#define MESH_POS_Y 1
	#define MESH_POS_Z 2
	#define MESH_TEX_S 0
	#define MESH_TEX_T 1
	#define MESH_TEX_R 2
	#define MESH_TEX_Q 3
	#define MESH_SHININESS 0

	#define DRAG_INFO_DX 1
	#define DRAG_INFO_DY 2
	#define DRAG_INFO_DZ 3
	#define DRAG_INFO_MDX 4
	#define DRAG_INFO_MDY 5
	#define DRAG_INFO_BUTTON_STATE 6
	#define DRAG_INFO_SET_DX 7
	#define DRAG_INFO_SET_DY 8
	#define DRAG_INFO_SET_DZ 9
	#define DRAG_INFO_SET_MDX 10
	#define DRAG_INFO_SET_MDY 11
	#define DRAG_INFO_SET_BUTTON_STATE 12
	#define DRAG_INFO_SNAPPED_DX 13
	#define DRAG_INFO_SNAPPED_DY 14
	#define DRAG_INFO_SNAPPED_DZ 15

	#define DETECT_DRAG_XY 0
	#define DETECT_DRAG_XZ 1
	#define DETECT_DRAG_YZ 2
	#define DETECT_DRAG_X 3
	#define DETECT_DRAG_Y 4
	#define DETECT_DRAG_Z 5

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
	#define SM_LOAD 14
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

	#define LISTENER_INFO_CODE 1
	#define LISTENER_INFO_ASSOCIATED 2
	#define LISTENER_INFO_COUPLING 3

	// nodefunction listen event macros
	#define NFL_PRE_LISTEN 0x1
	#define NFL_LISTEN 0x2
	#define NFL_PERSIST 0x4
	#define NFL_PASS_THROUGH_PARAMS 0x8

	#define NFL_STOP_LISTENING -1

	#define STAT_MEAN 1
	#define STAT_CONF_INTERVAL_HALF_WIDTH 2
	#define STAT_MIN 3
	#define STAT_MAX 4
	#define STAT_VARIANCE 5
	#define STAT_STD_DEV 6
	#define STAT_SUM 7

	#define DRAW_FLAG_BILLBOARD_MASK 0x3
	#define DRAW_FLAG_ONE_SIDED 0x4
	#define DRAW_FLAG_TWO_SIDED 0x8
	#define DRAW_FLAG_NO_DEPTH_TEST 0x10
	#define DRAW_FLAG_REFLECTIVE 0x20
	#define DRAW_FLAG_LUMINOUS 0x40
	#define DRAW_FLAG_SCALE_CHILDREN 0x80
	#define DRAW_FLAG_IGNORE_PICKING 0x100
	#define DRAW_FLAG_NO_ON_DRAW 0x200
	#define DRAW_FLAG_NO_ON_PRE_DRAW 0x400
	#define DRAW_FLAG_SKIP_ALL_DRAW 0x800
	
	#define DB_SQL_FLAG_FORWARD_ONLY_CURSOR 0x1

	#define IGNORE_CASE 1

	#define EDIT_MODE_GET_MODE_NUM -1
	#define EDIT_MODE_GET_MODE_DELEGATE -2

	#define PARAM_TYPE_NUMBER 1
	#define PARAM_TYPE_NODE 2
	#define PARAM_TYPE_STRING 3
	
	#define nullvar Variant()

	#if !defined COMPILING_FLEXSIM_CONTENT && !defined COMPILING_MODULE_DLL
	namespace FlexSim {
		extern void* (*flexsimmalloc) (size_t);
		extern void(*flexsimfree) (void*);
	}
	#include "BasicMacros.h"
	#endif

	#define DECLARATIONTYPE FLEXSIM_DECLARATION_PHASE
	#include "FlexsimFuncs.h"

#endif //COMPILING_FLEXSIM_CONTENT, COMPILING_MODULE_DLL

#endif //FLEXSIMDEFS_H
