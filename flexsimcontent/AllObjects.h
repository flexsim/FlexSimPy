
// cpp objects


#ifndef allobjects_h


#define allobjects_h


#ifdef COMPILING_FLEXSIM_CONTENT
#	include "all.h"
#endif
#ifdef _MSC_VER
#	ifdef COMPILING_FLEXSIM_CONTENT
#		define FS_CONTENT_DLL_FUNC __declspec(dllexport)
#		define fs_content_export __declspec(dllexport)
#	else
#		define FS_CONTENT_DLL_FUNC __declspec(dllimport)
#		define fs_content_export __declspec(dllimport)
#	endif
#else
#	define FS_CONTENT_DLL_FUNC 
#	define fs_content_export 
#endif
#define node_b_behaviour Nb_behaviour
#define node_b_cppfunctions Nb_cppfunctions
#define node_b_cppvariables Nb_cppvariables
#define node_b_eventfunctions Nb_eventfunctions
#define node_b_userfunctions Nb_userfunctions
#define node_b_classes Nb_classes
#define node_b_superclasses Nb_superclasses
#define node_b_connections Nb_connections
#define node_b_connectionsin Nb_connectionsin
#define b_connectionsin Nb_connectionsin->safedatafloat()[0]
#define node_b_connectionsout Nb_connectionsout
#define b_connectionsout Nb_connectionsout->safedatafloat()[0]
#define node_b_connectionscenter Nb_connectionscenter
#define b_connectionscenter Nb_connectionscenter->safedatafloat()[0]
#define node_b_itemtype Nb_itemtype
#define b_itemtype Nb_itemtype->safedatafloat()[0]
#define node_b_labels Nb_labels
#define node_b_variables Nb_variables
#define node_b_listeners Nb_listeners
#define node_b_OnReset Nb_OnReset
#define node_b_OnMessage Nb_OnMessage
#define node_b_OnTimerEvent Nb_OnTimerEvent
#define node_b_OnDraw Nb_OnDraw
#define node_b_OnPreDraw Nb_OnPreDraw
#define node_b_OnDrawPlanar Nb_OnDrawPlanar
#define node_b_OnPreDrawPlanar Nb_OnPreDrawPlanar
#define node_b_OnInOpen Nb_OnInOpen
#define node_b_OnOutOpen Nb_OnOutOpen
#define node_b_OnReceive Nb_OnReceive
#define node_b_OnSend Nb_OnSend
#define node_b_OnEntering Nb_OnEntering
#define node_b_OnExiting Nb_OnExiting
#define node_b_OnCompile Nb_OnCompile
#define node_b_OnCreate Nb_OnCreate
#define node_b_OnDestroy Nb_OnDestroy
#define node_b_OnUndo Nb_OnUndo
#define node_b_OnClick Nb_OnClick
#define node_b_OnRunStart Nb_OnRunStart
#define node_b_OnRunWarm Nb_OnRunWarm
#define node_b_OnRunEnd Nb_OnRunEnd
#define node_b_OnListen Nb_OnListen
#define node_b_OnPreListen Nb_OnPreListen
#define node_b_OnStateChange Nb_OnStateChange
#define node_b_OnDrag Nb_OnDrag
#define node_b_stats Nb_stats
#define node_b_state_current Nb_state_current
#define node_b_state_since Nb_state_since
#define node_b_state_profile Nb_state_profile
#define node_b_state_profiles Nb_state_profiles
#define node_b_stats_content Nb_stats_content
#define node_b_stats_staytime Nb_stats_staytime
#define node_b_stats_contentmin Nb_stats_contentmin
#define b_stats_contentmin Nb_stats_contentmin->safedatafloat()[0]
#define node_b_stats_contentmax Nb_stats_contentmax
#define b_stats_contentmax Nb_stats_contentmax->safedatafloat()[0]
#define node_b_stats_contentavg Nb_stats_contentavg
#define b_stats_contentavg Nb_stats_contentavg->safedatafloat()[0]
#define node_b_stats_contentupdates Nb_stats_contentupdates
#define b_stats_contentupdates Nb_stats_contentupdates->safedatafloat()[0]
#define node_b_stats_contentsince Nb_stats_contentsince
#define b_stats_contentsince Nb_stats_contentsince->safedatafloat()[0]
#define node_b_stats_contentgraph Nb_stats_contentgraph
#define node_b_stats_contentgraphmaxpoints Nb_stats_contentgraphmaxpoints
#define b_stats_contentgraphmaxpoints Nb_stats_contentgraphmaxpoints->safedatafloat()[0]
#define node_b_stats_staytimemin Nb_stats_staytimemin
#define node_b_stats_staytimemax Nb_stats_staytimemax
#define node_b_stats_staytimeavg Nb_stats_staytimeavg
#define node_b_stats_staytimeupdates Nb_stats_staytimeupdates
#define node_b_stats_staytimesince Nb_stats_staytimesince
#define node_b_stats_staytimegraph Nb_stats_staytimegraph
#define node_b_stats_staytimegraphmaxpoints Nb_stats_staytimegraphmaxpoints
#define node_b_stats_staytimehisto Nb_stats_staytimehisto
#define node_b_stats_throughput Nb_stats_throughput
#define node_b_stats_lastmovetime Nb_stats_lastmovetime
#define b_stats_lastmovetime Nb_stats_lastmovetime->safedatafloat()[0]
#define node_b_stats_creationtime Nb_stats_creationtime
#define b_stats_creationtime Nb_stats_creationtime->safedatafloat()[0]
#define node_b_stats_input Nb_stats_input
#define node_b_stats_output Nb_stats_output
#define node_b_stream Nb_stream
#define b_stream Nb_stream->safedatafloat()[0]
#define node_b_spatialx Nb_spatialx
#define b_spatialx Nb_spatialx->safedatafloat()[0]
#define node_b_spatialy Nb_spatialy
#define b_spatialy Nb_spatialy->safedatafloat()[0]
#define node_b_spatialz Nb_spatialz
#define b_spatialz Nb_spatialz->safedatafloat()[0]
#define node_b_spatialsx Nb_spatialsx
#define b_spatialsx Nb_spatialsx->safedatafloat()[0]
#define node_b_spatialsy Nb_spatialsy
#define b_spatialsy Nb_spatialsy->safedatafloat()[0]
#define node_b_spatialsz Nb_spatialsz
#define b_spatialsz Nb_spatialsz->safedatafloat()[0]
#define node_b_spatialrx Nb_spatialrx
#define b_spatialrx Nb_spatialrx->safedatafloat()[0]
#define node_b_spatialry Nb_spatialry
#define b_spatialry Nb_spatialry->safedatafloat()[0]
#define node_b_spatialrz Nb_spatialrz
#define b_spatialrz Nb_spatialrz->safedatafloat()[0]
#define node_b_offsetx Nb_offsetx
#define b_offsetx Nb_offsetx->safedatafloat()[0]
#define node_b_offsety Nb_offsety
#define b_offsety Nb_offsety->safedatafloat()[0]
#define node_b_offsetz Nb_offsetz
#define b_offsetz Nb_offsetz->safedatafloat()[0]
#define node_b_offsetrx Nb_offsetrx
#define b_offsetrx Nb_offsetrx->safedatafloat()[0]
#define node_b_offsetry Nb_offsetry
#define b_offsetry Nb_offsetry->safedatafloat()[0]
#define node_b_offsetrz Nb_offsetrz
#define b_offsetrz Nb_offsetrz->safedatafloat()[0]
#define node_b_offsetsx Nb_offsetsx
#define b_offsetsx Nb_offsetsx->safedatafloat()[0]
#define node_b_offsetsy Nb_offsetsy
#define b_offsetsy Nb_offsetsy->safedatafloat()[0]
#define node_b_offsetsz Nb_offsetsz
#define b_offsetsz Nb_offsetsz->safedatafloat()[0]
#define node_b_color Nb_color
#define node_b_centroid Nb_centroid
#define b_centroid Nb_centroid->safedatafloat()[0]
#define node_b_drawflags Nb_drawflags
#define b_drawflags Nb_drawflags->safedatafloat()[0]
#define node_b_imageobject Nb_imageobject
#define node_b_imageindexobject Nb_imageindexobject
#define b_imageindexobject Nb_imageindexobject->safedatafloat()[0]
#define node_b_imagebase Nb_imagebase
#define node_b_imageindexbase Nb_imageindexbase
#define b_imageindexbase Nb_imageindexbase->safedatafloat()[0]
#define node_b_shape Nb_shape
#define node_b_shapeindex Nb_shapeindex
#define b_shapeindex Nb_shapeindex->safedatafloat()[0]
#define node_b_drawsurrogate Nb_drawsurrogate
#define node_b_sound Nb_sound
#define node_b_soundindex Nb_soundindex
#define b_soundindex Nb_soundindex->safedatafloat()[0]
#define node_b_guifocus Nb_guifocus
#define node_b_guifocusclass Nb_guifocusclass
#define node_b_stored Nb_stored
#define node_b_objectinfo Nb_objectinfo
#define node_b_frame Nb_frame
#define b_frame Nb_frame->safedatafloat()[0]
#define node_b_uniqueid Nb_uniqueid
#define b_uniqueid Nb_uniqueid->safedatafloat()[0]
#define node_b_animationinfo Nb_animationinfo
#define node_b_resizeinfo Nb_resizeinfo
#define node_b_shapedata Nb_shapedata
#define node_b_resetvalues Nb_resetvalues
#define node_b_templateobject Nb_templateobject
#define node_b_templateoverrides Nb_templateoverrides
#define node_b_templateinstances Nb_templateinstances


// Constants



// Constants


#define iterate(__start__, __end__, __inc__) for (double count = __start__; __inc__ > 0 ? count < __end__ + .001 * __inc__ : count > __end__ + 0.001 * __inc__; count += __inc__)
#define inheritcode() _inheritcode(callPoint)
#define local(index) __local__(index, callPoint)
#define localarray(qty, datatype) __localarray__(qty, datatype, callPoint)

#ifdef THIS_SHOULD_NEVER_BE_DEFINED_BECAUSE_IT_SHOULD_ONLY_BE_SEEN_BY_FLEXSCRIPT
	#define forobjecttreeunder(__top__) for (treenode a = first(__top__); objectexists(a); a = nextforobjecttreeunder(a, __top__))
	#define forobjectlayerunder(__top__) for (treenode a = first(__top__); objectexists(a); a = next(a))
	#define forobjectsbefore(__node__) for (treenode a = prev(__node__); objectexists(a) && getrank(a) >= 1; a = prev(a))
	#define forobjectsbehind(__node__) for (treenode a = next(__node__); objectexists(a); a = next(a))
	#define eq(__a__, __b__) (__a__ == __b__)
	#define ne(__a__, __b__) (__a__ != __b__)
	#define msgsendingobject() _parnode(1, callPoint)
#endif

#define partype(__a__) _partype(__a__,callPoint)
#define msgparam(__a__) _param(__a__ + 1, callPoint)
#define param(__a__) _param(__a__, callPoint)
#define parval(__a__) _parval(__a__, callPoint)
#define parnode(__a__) _parnode(__a__, callPoint)
#define parstr(__a__) _parstr(__a__, callPoint)
#define parqty() _parqty(callPoint)
#define setcurrent(__a__) __setcurrent__(__a__, callPoint)
#define setitem(__a__) __setitem__(__a__, callPoint)
#define setport(__a__) __setport__(__a__, callPoint)

// Constants group: GLOBAL
#define GLOBAL_DELAYINDEFINITE  1000000000
#define GLOBAL_UNREACHABLE  340282346600000000000000000000000000000.0
#define UNIXSECSB4OADATETIME 9435312000.0
#define INT_MAX 2147483647
#define FLOAT_MAX 3.402823466e38
#define DOUBLE_MAX 1.7976931348623158e308

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
#define EVENT_RECORDER_LISTEN  20
#define EVENT_COLLISIONCHECK  21
#define EVENT_STARTLOADTIME  22
#define EVENT_STARTUNLOADTIME  23
#define EVENT_USEROPENOUTPUT  24
#define EVENT_USEROPENINPUT  25
#define EVENT_TICK  26
#define EVENT_TRAVELERBLOCKED  27
#define EVENT_STARTSIMULATION  28
#define EVENT_ENDCHANGEOVER  29
#define EVENT_BEGINRUN  30
#define EVENT_NEXTTIME  31
#define EVENT_RELEASEPALLET  32
#define EVENT_CONV_AT_BLOCKED_LENGTH  33
#define EVENT_PE_GREEN  34
#define EVENT_PE_YELLOW  35
#define EVENT_PE_RED  36
#define EVENT_MSHOLD  37
#define EVENT_MSLOOPITEM  38
#define EVENT_DP_COVER_FRONT  39
#define EVENT_DP_CLEAR_BACK  40
#define EVENT_DP_CLEAR_BACK_SPACE  41
#define EVENT_REPEAT  42
#define EVENT_FIREEVENT  43
#define EVENT_ENDFORKTRAVELTIME  44

//Excel flags
#define EXCEL_DATA_AUTOMATIC 0x01
#define EXCEL_DATA_STRING 0x02
#define EXCEL_DATA_NUMBER 0x04
#define EXCEL_DATE_AS_NUM 0x08
#define EXCEL_USE_COLUMNHEADERS 0x20
#define EXCEL_USE_ROWHEADERS 0x40

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
#define TASKTYPE_SENDMESSAGE  13 //deprecated
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
#define TASKTYPE_NODEFUNCTION  29
#define TASKTYPE_STARTANIMATION  30
#define TASKTYPE_STOPANIMATION  31
#define TASKTYPE_FREEOPERATORS  32
#define TASKTYPE_WAITFORTASK  33
#define TASKTYPE_MESSAGE 34

// Constants group: TASKSTATE
#define TASKSTATE_UNFINISHED  1
#define TASKSTATE_ACTIVE  2
#define TASKSTATE_FINISHED  3
#define TASKSTATE_COORDINATED  4

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
#define DATATYPE_SIMPLE  7

// Constants group: VARTYPE
#define VAR_TYPE_NULL 0
#define VAR_TYPE_NUMBER 1
#define VAR_TYPE_NODE 2
#define VAR_TYPE_STRING 3
#define VAR_TYPE_ARRAY 4
#define VAR_TYPE_POINTER 5
#define VAR_TYPE_MAP 6

// Constants group: SM
#define SM_RESET  1
#define SM_MESSAGE  2
#define SM_EVENT  3
#define SM_DRAW  4
#define SM_INOPEN  5
#define SM_OUTOPEN  6
#define SM_ACCEPT  7
#define SM_GIVE  8
#define SM_ENTER  9
#define SM_EXIT   10
#define SM_COMPILE   11
#define SM_CREATE   12
#define SM_DESTROY   13
#define SM_LOAD   14
#define SM_CLICK   15
#define SM_RUNSTART   16
#define SM_RUNWARM   17
#define SM_RUNEND   18
#define SM_PRELISTEN   19
#define SM_LISTEN   20
#define SM_PREDRAW   21
#define SM_DRAWPLANAR   22
#define SM_PREDRAWPLANAR   23
#define SM_STATECHANGE   24
#define SM_DRAG   25

// Constants group: ARRIVALMODE
#define ARRIVALMODE_INTERARRIVALTIME  1
#define ARRIVALMODE_SCHEDULE  2
#define ARRIVALMODE_SEQUENCE  3

// Constants group: FRSTATE
#define FRSTATE_INQUEUE  1
#define FRSTATE_READY  2
#define FRSTATE_MOVEREQUESTED  3

// Constants group: SPACING
#define SPACING_LENGTH  1
#define SPACING_LENGTHPLUSSETVALUE  2
#define SPACING_SETVALUE  3
#define SPACING_LENGTHTIMESSETVALUE  4

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

// Constants group: VISUALOBJECT
#define VISUALOBJECT_PLANE  1
#define VISUALOBJECT_CUBE  2
#define VISUALOBJECT_COLUMN  3
#define VISUALOBJECT_SPHERE  4
#define VISUALOBJECT_MODEL  5
#define VISUALOBJECT_TEXT  6
#define VISUALOBJECT_SLIDE  7
#define VISUALOBJECT_FLOOR  8

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
#define CLASSTYPE_TASKEXECUTER  0x10
#define CLASSTYPE_NAVIGATOR  0x20
#define CLASSTYPE_PROCESSOR  0x40
#define CLASSTYPE_NETWORKNODE  0x80
#define CLASSTYPE_VISUALTOOL  0x100
#define CLASSTYPE_CONVEYOR  0x200
#define CLASSTYPE_TRAFFICCONTROLLER  0x400
#define CLASSTYPE_MTBFMTTR  0x800
#define CLASSTYPE_MERGESORT  0x1000
#define CLASSTYPE_WANTCONNECTLOGIC  0x2000
#define CLASSTYPE_FLUIDOBJECT  0x4000
#define CLASSTYPE_FLUIDOBJECT2  0x8000
#define CLASSTYPE_LINECONTROLLER  0x10000
#define CLASSTYPE_SYSTEMCONTROLLER  0x20000
#define CLASSTYPE_FLEXSIMEVENTHANDLER 0x40000
#define CLASSTYPE_OWNERDRAWN		0x80000000

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
#define ADV_FUNC_ONPREEMPT  5

// kinematic flags
#define KINEMATIC_MANAGE_ROTATIONS 0x1
#define KINEMATIC_DO_NOT_PRUNE 0x2
#define KINEMATIC_NO_UPDATE 0x4
#define KINEMATIC_RELATIVE_LOCS 0x8
#define KINEMATIC_RESET_BUFFER 0x10
#define KINEMATIC_MANAGE_ROT_OVERRIDE 0x20
#define KINEMATIC_NO_INCLINE_ROTATION 0x40

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
#define KINEMATIC_STARTANGLE  39
#define KINEMATIC_TURNANGLE  40
#define KINEMATIC_TURNRADIUS  41
#define KINEMATIC_PRUNE  42

#define KINEMATIC_TRAVEL  1
#define KINEMATIC_ROTATE  2
#define KINEMATIC_TURN_XY  3
#define KINEMATIC_TURN_YZ  4
#define KINEMATIC_TURN_ZX  5

// Constants group: MTBF_MTTR
#define MTBF_MTTR_BEGIN_DOWN_TIME  1
#define MTBF_MTTR_BEGIN_DOWN_TIME_NO_RESUME  2
#define MTBF_MTTR_FINISH_DOWN_TIME  3
#define MTBF_MTTR_FINISH_DOWN_TIME_NO_RESUME  4

// constrained variable types
#define CV_TYPE_CONTINUOUS 1
#define CV_TYPE_INTEGER 2
#define CV_TYPE_DISCRETE 3
#define CV_TYPE_BINARY 4
#define CV_TYPE_OPTION 5
#define CV_TYPE_SEQUENCE 6
#define CV_TYPE_EXPRESSION 7
#define CV_TYPE_PASSTHROUGH 8

#define ITEMVAR_PROCESSBEGINTIME 1
#define ITEMVAR_PROCESSTIME 2
#define ITEMVAR_SETUPTIME 3

#ifdef DOUBLE_CLICK
	#undef DOUBLE_CLICK
#endif
#define DOUBLE_CLICK 1
#define LEFT_PRESS 2
#define LEFT_RELEASE 3
#define RIGHT_PRESS 4
#define RIGHT_RELEASE 5

#define SCI_START 2000
#define SCI_OPTIONAL_START 3000
#define SCI_LEXER_START 4000
#define SCI_ADDTEXT 2001
#define SCI_ADDSTYLEDTEXT 2002
#define SCI_INSERTTEXT 2003
#define SCI_CLEARALL 2004
#define SCI_CLEARDOCUMENTSTYLE 2005
#define SCI_GETLENGTH 2006
#define SCI_GETCHARAT 2007
#define SCI_GETCURRENTPOS 2008
#define SCI_GETANCHOR 2009
#define SCI_GETSTYLEAT 2010
#define SCI_REDO 2011
#define SCI_SETUNDOCOLLECTION 2012
#define SCI_SELECTALL 2013
#define SCI_SETSAVEPOINT 2014
#define SCI_GETSTYLEDTEXT 2015
#define SCI_CANREDO 2016
#define SCI_MARKERLINEFROMHANDLE 2017
#define SCI_MARKERDELETEHANDLE 2018
#define SCI_GETUNDOCOLLECTION 2019
#define SCWS_INVISIBLE 0
#define SCWS_VISIBLEALWAYS 1
#define SCWS_VISIBLEAFTERINDENT 2
#define SCI_GETVIEWWS 2020
#define SCI_SETVIEWWS 2021
#define SCI_POSITIONFROMPOINT 2022
#define SCI_POSITIONFROMPOINTCLOSE 2023
#define SCI_GOTOLINE 2024
#define SCI_GOTOPOS 2025
#define SCI_SETANCHOR 2026
#define SCI_GETCURLINE 2027
#define SCI_GETENDSTYLED 2028
#define SC_EOL_CRLF 0
#define SC_EOL_CR 1
#define SC_EOL_LF 2
#define SCI_CONVERTEOLS 2029
#define SCI_GETEOLMODE 2030
#define SCI_SETEOLMODE 2031
#define SCI_STARTSTYLING 2032
#define SCI_SETSTYLING 2033
#define SCI_GETBUFFEREDDRAW 2034
#define SCI_SETBUFFEREDDRAW 2035
#define SCI_SETTABWIDTH 2036

#define SCI_MARKERDEFINE 2040
#define SCI_MARKERSETFORE 2041
#define SCI_MARKERSETBACK 2042
#define SCI_MARKERADD 2043
#define SCI_MARKERDELETE 2044
#define SCI_MARKERDELETEALL 2045
#define SCI_MARKERGET 2046
#define SCI_MARKERNEXT 2047
#define SCI_MARKERPREVIOUS 2048
#define SCI_MARKERDEFINEPIXMAP 2049
#define SCI_MARKERADDSET 2466
#define SCI_MARKERSETALPHA 2476

#define FS_MARKER_MARKLINE 0
#define FS_MARKER_BREAK_POINT 1
#define FS_MARKER_DISABLED_BREAK_POINT 2
#define FS_MARKER_CODE_POINT 3

#define SC_MARK_ROUNDRECT 1
#define SC_MARK_ARROW 2
#define SC_MARK_SMALLRECT 3
#define SC_MARK_SHORTARROW 4
#define SC_MARK_EMPTY 5
#define SC_MARK_ARROWDOWN 6
#define SC_MARK_MINUS 7
#define SC_MARK_PLUS 8
#define SC_MARK_VLINE 9
#define SC_MARK_LCORNER 10
#define SC_MARK_TCORNER 11
#define SC_MARK_BOXPLUS 12
#define SC_MARK_BOXPLUSCONNECTED 13
#define SC_MARK_BOXMINUS 14
#define SC_MARK_BOXMINUSCONNECTED 15
#define SC_MARK_LCORNERCURVE 16
#define SC_MARK_TCORNERCURVE 17
#define SC_MARK_CIRCLEPLUS 18
#define SC_MARK_CIRCLEPLUSCONNECTED 19
#define SC_MARK_CIRCLEMINUS 20
#define SC_MARK_CIRCLEMINUSCONNECTED 21
#define SC_MARK_BACKGROUND 22
#define SC_MARK_DOTDOTDOT 23
#define SC_MARK_ARROWS 24
#define SC_MARK_PIXMAP 25
#define SC_MARK_FULLRECT 26
#define SC_MARK_LEFTRECT 27
#define SC_MARK_AVAILABLE 28
#define SC_MARK_UNDERLINE 29

#define SC_MARGIN_SYMBOL 0
#define SC_MARGIN_NUMBER 1
#define SC_MARGIN_BACK 2
#define SC_MARGIN_FORE 3
#define SC_MARGIN_TEXT 4
#define SC_MARGIN_RTEXT 5

#define SCI_SETMARGINTYPEN 2240
#define SCI_GETMARGINTYPEN 2241
#define SCI_SETMARGINWIDTHN 2242
#define SCI_GETMARGINWIDTHN 2243
#define SCI_SETMARGINMASKN 2244
#define SCI_GETMARGINMASKN 2245
#define SCI_SETMARGINSENSITIVEN 2246
#define SCI_GETMARGINSENSITIVEN 2247

#define SCI_GETTABWIDTH 2121
#define SCI_SETINDENT 2122
#define SCI_GETINDENT 2123
#define SCI_SETUSETABS 2124
#define SCI_GETUSETABS 2125
#define SCI_SETLINEINDENTATION 2126
#define SCI_GETLINEINDENTATION 2127
#define SCI_GETLINEINDENTPOSITION 2128
#define SCI_GETCOLUMN 2129
#define SCI_SETHSCROLLBAR 2130
#define SCI_GETHSCROLLBAR 2131
#define SCI_SETINDENTATIONGUIDES 2132
#define SCI_GETINDENTATIONGUIDES 2133
#define SCI_SETHIGHLIGHTGUIDE 2134
#define SCI_GETHIGHLIGHTGUIDE 2135
#define SCI_GETLINEENDPOSITION 2136
#define SCI_GETCODEPAGE 2137
#define SCI_GETCARETFORE 2138
#define SCI_GETUSEPALETTE 2139
#define SCI_GETREADONLY 2140
#define SCI_SETCURRENTPOS 2141
#define SCI_SETSELECTIONSTART 2142
#define SCI_GETSELECTIONSTART 2143
#define SCI_SETSELECTIONEND 2144
#define SCI_GETSELECTIONEND 2145
#define SCI_SETPRINTMAGNIFICATION 2146
#define SCI_GETPRINTMAGNIFICATION 2147
#define SC_PRINT_NORMAL 0
#define SC_PRINT_INVERTLIGHT 1
#define SC_PRINT_BLACKONWHITE 2
#define SC_PRINT_COLOURONWHITE 3
#define SC_PRINT_COLOURONWHITEDEFAULTBG 4
#define SCI_SETPRINTCOLOURMODE 2148
#define SCI_GETPRINTCOLOURMODE 2149
#define SCFIND_WHOLEWORD 2
#define SCFIND_MATCHCASE 4
#define SCFIND_WORDSTART 0x00100000
#define SCFIND_REGEXP 0x00200000
#define SCFIND_POSIX 0x00400000
#define SCI_FINDTEXT 2150
#define SCI_FORMATRANGE 2151
#define SCI_GETFIRSTVISIBLELINE 2152
#define SCI_GETLINE 2153
#define SCI_GETLINECOUNT 2154
#define SCI_SETMARGINLEFT 2155
#define SCI_GETMARGINLEFT 2156
#define SCI_SETMARGINRIGHT 2157
#define SCI_GETMARGINRIGHT 2158
#define SCI_GETMODIFY 2159
#define SCI_SETSEL 2160
#define SCI_GETSELTEXT 2161
#define SCI_GETTEXTRANGE 2162
#define SCI_HIDESELECTION 2163
#define SCI_POINTXFROMPOSITION 2164
#define SCI_POINTYFROMPOSITION 2165
#define SCI_LINEFROMPOSITION 2166
#define SCI_POSITIONFROMLINE 2167
#define SCI_LINESCROLL 2168
#define SCI_SCROLLCARET 2169
#define SCI_REPLACESEL 2170
#define SCI_SETREADONLY 2171
#define SCI_NULL 2172
#define SCI_CANPASTE 2173
#define SCI_CANUNDO 2174
#define SCI_EMPTYUNDOBUFFER 2175
#define SCI_UNDO 2176
#define SCI_CUT 2177
#define SCI_COPY 2178
#define SCI_PASTE 2179
#define SCI_CLEAR 2180
#define SCI_SETTEXT 2181
#define SCI_GETTEXT 2182
#define SCI_GETTEXTLENGTH 2183
#define SCI_GETDIRECTFUNCTION 2184
#define SCI_GETDIRECTPOINTER 2185

#define SCI_SETTARGETSTART 2190
#define SCI_GETTARGETSTART 2191
#define SCI_SETTARGETEND 2192
#define SCI_GETTARGETEND 2193
#define SCI_REPLACETARGET 2194
#define SCI_REPLACETARGETRE 2195
#define SCI_SEARCHINTARGET 2197
#define SCI_SETSEARCHFLAGS 2198
#define SCI_GETSEARCHFLAGS 2199

#define SCI_WORDSTARTPOSITION 2266
#define SCI_WORDENDPOSITION 2267

#define SCI_TARGETFROMSELECTION 2287

#define SCI_SEARCHANCHOR 2366
#define SCI_SEARCHNEXT 2367
#define SCI_SEARCHPREV 2368


/* BeginMode */
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_QUAD_STRIP                     0x0008
#define GL_POLYGON                        0x0009

/* enabling/disabling*/
#define GL_FOG                            0x0B60
#define GL_LIGHTING                       0x0B50
#define GL_TEXTURE_2D                     0x0DE1
#define GL_DEPTH_TEST                     0x0B71
#define GL_TEXTURE_GEN_S                  0x0C60
#define GL_TEXTURE_GEN_T                  0x0C61
#define GL_TEXTURE_GEN_R                  0x0C62
#define GL_TEXTURE_GEN_Q                  0x0C63


/* AttribMask */
#define GL_LIGHTING_BIT                   0x00000040
#define GL_ENABLE_BIT                     0x00002000
#define GL_ALL_ATTRIB_BITS                0x000fffff

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

// Texture Channels
#define TEX_UNIT_SHADOWS 1
#define TEX_UNIT_HEIGHT 2
#define TEX_UNIT_NORMAL 3

// this should be the same as -FLT_MAX
#define DISPATCHER_ABORT_QUEUE_STRATEGY -340282346600000000000000000000000000000.0

#define NETWORK_INFO_ORIGIN_NET_NODE_RANK 1
#define NETWORK_INFO_DEST_NET_NODE_RANK 2
#define NETWORK_INFO_DISTANCE 3
#define NETWORK_INFO_CUR_DIST_ALONG_EDGE 4
#define NETWORK_INFO_CUR_TRAVEL_DEST_RANK 5
#define NETWORK_INFO_CUR_TRAVEL_ORIGIN_RANK 6

#define LICENSE_TYPE_NONE 0
#define LICENSE_TYPE_STANDARD 1
#define LICENSE_TYPE_RUNTIME 2
#define LICENSE_TYPE_EDUCATIONAL 3
#define LICENSE_TYPE_CUSTOM 4

#define CLF_ADMIN				0x00000010
#define CLF_DRAG_DROP_CONNECT	0x00000800
#define CLF_CREATE_OBJECTS		0x00000400
#define CLF_NO_MODEL_LIMIT		0x00000200
#define CLF_STOCHASTICS			0x00000100
#define CLF_ENTIRE_TREE			0x00008000
#define CLF_MODEL_TREE			0x00004000
#define CLF_CONSOLE_SCRIPT		0x00002000
#define CLF_COMPILE				0x00001000
#define CLF_COMMERCIAL_USE		0x00080000
#define CLF_EXPERTFIT			0x00040000
#define CLF_OPTQUEST			0x00020000
#define CLF_XMLSAVELOAD			0x00010000
#define CLF_OPTQUEST_STUDENT	0x00000008

#define UNDO_AGGREGATED 1
#define UNDO_MOVE_SIZE_ROTATE 2
#define UNDO_MOVE_SIZE_ROTATE_GROUP 3
#define UNDO_SELECTION_CHANGE 4
#define UNDO_CREATE_OBJECT 5 // creates an object/node
#define UNDO_DELETE_OBJECT 6 // deletes an object/node
#define UNDO_CHANGE_DATA 7 // includes set(), sets(), nodeadddata, etc.
#define UNDO_CHANGE_RANK 8
#define UNDO_CHANGE_NAME 9
#define UNDO_MOVE_OBJECT 10
#define UNDO_DELETE_COUPLING 11
#define UNDO_BREAK_COUPLING 12
#define UNDO_AGGREGATED_FIRST_RECORD 13 // a no-op record that serves as a simple placeholder for the "current record" pointer when doing and aggregated undo
#define UNDO_DESTROY_BRANCH 14
#define UNDO_CHANGE_FLAGS 15
#define UNDO_REPLACE_OBJECT 16
#define UNDO_CUSTOM 17
#define UNDO_CALLBACK 18
#define UNDO_CHANGE_NUMBER_DATA 19 // used only as a sub-record of a move/size/rotate
#define UNDO_UPDATE_LINKS_ON_UNDO 20
#define UNDO_UPDATE_LINKS_ON_REDO 21
#define UNDO_RECORD_SUBCLASS 22
#define UNDO_CUSTOM_UNDO 23
#define UNDO_CUSTOM_REDO 24

#define UNDO_UPDATE_ADD_SELECTION 1
#define UNDO_UPDATE_ADD_UNSELECTION 2

#define USC_RESET_VIEW_SELECTIONS 1
#define USC_SELECT_SUB_TREE 2
#define USC_UNSELECT_SUB_TREE 3

#define PICK_OPERATOR_SETUP 1
#define PICK_OPERATOR_PROCESS 2
#define PICK_OPERATOR_SETUP_RELEASE 3
#define PICK_OPERATOR_PROCESS_RELEASE 4

#define REMEMBER_WINDOW_SIZES !objectexists(node("VIEW:/environment/dev"))

#define TC_ON_ENTRY_REQUEST_DEFAULT 0
#define TC_ON_ENTRY_REQUEST_ALLOW 1
#define TC_ON_ENTRY_REQUEST_QUEUE 2

#define TCI_NR_ACTIVE_TRAVELERS 1
#define TCI_ACTIVE_TRAVELER 2
#define TCI_ACTIVE_TRAVELER_COUPLING 3
#define TCI_ACTIVE_TRAVELER_RANK_FROM_TRAVELER 4
#define TCI_NR_MEMBERS 5
#define TCI_MEMBER 6
#define TCI_MEMBER_COUPLING 7
#define TCI_MEMBER_RANK_FROM_NETWORK_NODE 8
#define TCI_NR_ENTRY_REQUESTS 9
#define TCI_ENTRY_REQUEST_TRAVELER 10
#define TCI_ENTRY_REQUEST_NETWORK_NODE 11
#define TCI_ENTRY_REQUEST_NODE 12
#define TCI_ALLOW_ENTRY 13
#define TCI_SET_ENTRY_REQUEST_RANK 14

#define LA_PROCESS_ASR_FROM_BUFFER 1
#define LA_PROCESS_ASR_FROM_FILE 2
#define LA_PROCESS_ACTIVATION_RESPONSE_FROM_BUFFER 3
#define LA_PROCESS_ACTIVATION_RESPONSE_FROM_FILE 4
#define LA_SUBMIT_ACTIVATION_REQUEST 5
#define LA_WRITE_ACTIVATION_REQUEST_TO_FILE 6
#define LA_SET_ACTIVATION_SERVER_PARAMS 7
#define LA_SET_PROXY_DETAILS 8
#define LA_DISPLAY_TRUSTED_STORAGE_CONTENTS 9
#define LA_RETURN_FULFILLMENT_RECORD 10
#define LA_REPAIR_FULFILLMENT_RECORD 11
#define LA_SET_ENTITLEMENT_ID 12
#define LA_SET_FULFILLMENT_ID 13
#define LA_GET_TRUSTED_STORAGE_CONTENTS_INFO 14
#define LA_WRITE_REPAIR_REQUEST_TO_FILE 15
#define LA_PROCESS_REPAIR_RESPONSE_FROM_FILE 16
#define LA_DELETE_FULFILLMENT_RECORD 17
#define LA_SET_EXPIRATIONDATE 18
#define LA_LF_BORROW_CHECKOUT 19
#define LA_GET_LF_BORROWED_CONTENTS_INFO 20
#define LA_PROCESS_RETURN_RESPONSE_FROM_FILE 21
#define LA_LF_BORROW_RETURN 22
#define LA_HAS_TRUSTED_STORAGE_CONTENTS 23
#define LA_SEND_UPGRADE_REQUEST 24
#define LA_REEVALUATE_LICENSE 25

#define ANIM_INFO_BODIES 1
#define ANIM_INFO_ANIMATIONS 2
#define ANIM_INFO_VARIABLES 3
#define ANIM_INFO_BONES 4

#define ANIM_VAR_SURROGATE 1
#define ANIM_VAR_KEYFRAME_VAL 2
#define ANIM_VAR_COMPONENT_VAL 3
#define ANIM_VAR_KEYFRAME_GAP 4
#define ANIM_VAR_COMPONENT 5

#define ANIMATION_CONTENT 12
#define ANIMATION_KEYFRAMES 1
#define ANIMATION_REPEAT_TYPE 2
#define ANIMATION_REPEAT_VALUE 3
#define ANIMATION_TIME_TYPE 4
#define ANIMATION_START_STATE 5
#define ANIMATION_START_TIME 6
#define ANIMATION_TIME_SCALE 7
#define ANIMATION_CUR_REPEAT_TYPE 8
#define ANIMATION_CUR_REPEAT_VALUE 9
#define ANIMATION_LAST_UPDATE_TIME 10
#define ANIMATION_TRIGGERS 11
#define ANIMATION_CLIPS 12

#define REPEAT_TYPE_DEFAULT 0
#define REPEAT_TYPE_NONE 1
#define REPEAT_TYPE_IMMEDIATE 2
#define REPEAT_TYPE_NR_ITERATIONS 3
#define REPEAT_TYPE_USE_TIME 4
#define REPEAT_TYPE_TIME_AFTER_END 5
#define REPEAT_TYPE_LAST_FRAME 6

#define KEYFRAME_CONTENT 2
#define KEYFRAME_BODIES 1
#define KEYFRAME_TRIGGER 2

#define KEYFRAME_BODY_X 1
#define KEYFRAME_BODY_Y 2
#define KEYFRAME_BODY_Z 3
#define KEYFRAME_BODY_SX 4
#define KEYFRAME_BODY_SY 5
#define KEYFRAME_BODY_SZ 6
#define KEYFRAME_BODY_RX 7
#define KEYFRAME_BODY_RY 8
#define KEYFRAME_BODY_RZ 9
#define KEYFRAME_BODY_RED 10
#define KEYFRAME_BODY_GREEN 11
#define KEYFRAME_BODY_BLUE 12
#define KEYFRAME_BODY_SHAPE_FRAME 13

#define START_STATE_BODY_SCALE_X 10
#define START_STATE_BODY_SCALE_Y 11
#define START_STATE_BODY_SCALE_Z 12
#define START_STATE_BODY_SCALE_SX 13
#define START_STATE_BODY_SCALE_SY 14
#define START_STATE_BODY_SCALE_SZ 15

#define SPEED_TYPE_DEFAULT 0
#define SPEED_TYPE_DURATION 1
#define SPEED_TYPE_MULTIPLIER 2

#define RESIZE_INFO_BASE_SIZE 1
#define RESIZE_INFO_BODIES 2

#define RESIZE_BODY_X 1
#define RESIZE_BODY_Y 2
#define RESIZE_BODY_Z 3
#define RESIZE_BODY_RX 4
#define RESIZE_BODY_RY 5
#define RESIZE_BODY_RZ 6
#define RESIZE_BODY_SX 7
#define RESIZE_BODY_SY 8
#define RESIZE_BODY_SZ 9
#define RESIZE_BODY_X_MAP 10
#define RESIZE_BODY_Y_MAP 11
#define RESIZE_BODY_Z_MAP 12

#define DEBUG_STOP 0
#define DEBUG_STEP 1
#define DEBUG_CONTINUE 2
#define DEBUG_IS_STOPPED 3
#define DEBUG_GET_LINE_NR 4
#define DEBUG_DUMP_VARIABLES 5
#define DEBUG_STOP_SIMULATION 6
#define DEBUG_REFRESH_BREAK_POINTS 7
#define DEBUG_ADD_BREAK_POINT 8
#define DEBUG_DELETE_BREAK_POINT 9
#define DEBUG_GET_WATCH_VARIABLE 10
#define DEBUG_ENABLE_CODE_PROFILING 11
#define DEBUG_PRINT_CODE_PROFILING_INFO 12
#define DEBUG_RESET_CODE_PROFILING 13
#define DEBUG_DUMP_CALL_STACK 14
#define DEBUG_STEP_INTO 15
#define DEBUG_DUMP_PROFILE_DATA 17
#define DEBUG_PROFILE_PUSH 18
#define DEBUG_PROFILE_POP 19
#define DEBUG_DUMP_MEMORY_DATA 20

#define ELI_GET_OBJECTPATH 1
#define ELI_GET_INVOLVEDPATH 2
#define ELI_GET_OTHERPATH 3
#define ELI_EVENTTYPE_NAME 4
#define ELI_LOGGEDEVENTTYPE_NAME 5


#define PICK_SIZER -1

#define PICK_CONNECTOR -2
#define PICK_CONNECTOR_TRIANGLE -3
#define PICK_CONNECTOR_SQUARE -4
#define PICK_CONNECTOR_CIRCLE -5
#define PICK_CONNECTOR_DIAMOND -6


#define PICK_ADDINPUTCONNECTOR -10
#define PICK_REMOVEINPUTCONNECTOR -11
#define PICK_ADDOUTPUTCONNECTOR -12
#define PICK_REMOVEOUTPUTCONNECTOR -13
#define PICK_ADDCENTRECONNECTOR -14
#define PICK_REMOVECENTRECONNECTOR -15
#define PICK_ITEMDATA -16
#define PICK_ITEMLABEL -17
#define PICK_EXPANDER -18
#define PICK_TEXTAREA -19
#define PICK_SIZERVERTICAL -20
#define PICK_TREEICONTOP -21
#define PICK_TREEICONBOTTOM -22
#define PICK_SIZERX -30
#define PICK_SIZERY -31
#define PICK_SIZERZ -32
#define PICK_SIZERXNEG -33
#define PICK_SIZERYNEG -34
#define PICK_SIZERZNEG -35

#define OBJECT_PART_SIZER_X 1
#define OBJECT_PART_SIZER_Y 2
#define OBJECT_PART_SIZER_Z 3
#define OBJECT_PART_SIZER_X_NEG 4
#define OBJECT_PART_SIZER_Y_NEG 5
#define OBJECT_PART_SIZER_Z_NEG 6
#define OBJECT_PART_YELLOW_HIGHLIGHT 7
#define OBJECT_PART_HOVER_HIGHLIGHT 8
#define OBJECT_PART_GREEN_HIGHLIGHT 9
#define OBJECT_PART_RED_HIGHLIGHT 10
#define OBJECT_PART_CONNECTOR_TRIANGLE 11
#define OBJECT_PART_CONNECTOR_SQUARE 12
#define OBJECT_PART_CONNECTOR_CIRCLE 13
#define OBJECT_PART_CONNECTOR_DIAMOND 14

#define PICK_OBJECT 1
#define PICK_TYPE 2
#define PICK_SECONDARY_OBJECT 3

#define PICK_PRESSED 0
#define PICK_HOVERED -1
#define PICK_RELEASED -2
#define PICK_MOVED -3

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

#define PICK_ASRS_RAIL_X 1
#define PICK_ASRS_RAIL_X_NEG 2

#define PICK_CRANE_LEG_X 10
#define PICK_CRANE_LEG_Y 11
#define PICK_CRANE_BEAM_Y 12
#define PICK_CRANE_BEAM_Z 13
#define PICK_CRANE_BRIDGE_X 14
#define PICK_CRANE_BRIDGE_Z 15
#define PICK_CRANE_FRAME_X 16
#define PICK_CRANE_FRAME_Y 17
#define PICK_CRANE_FRAME_Z 18

#define PICK_ELEVATOR_FRAME_Z 20

#define DETECT_DRAG_XY 0
#define DETECT_DRAG_XZ 1
#define DETECT_DRAG_YZ 2
#define DETECT_DRAG_X 3
#define DETECT_DRAG_Y 4
#define DETECT_DRAG_Z 5

#define DASHBOARD_WINDOW_MODE_MOVING 1
#define DASHBOARD_WINDOW_MODE_RESIZING_X 2
#define DASHBOARD_WINDOW_MODE_RESIZING_SX 3
#define DASHBOARD_WINDOW_MODE_RESIZING_Y 4
#define DASHBOARD_WINDOW_MODE_RESIZING_SY 5
#define DASHBOARD_WINDOW_MODE_RESIZING_XY 6
#define DASHBOARD_WINDOW_MODE_RESIZING_SXY 7
#define DASHBOARD_WINDOW_MODE_RESIZING_SXSY 8
#define DASHBOARD_WINDOW_MODE_RESIZING_XSY 9

#define CHART_TYPE_HORIZONTAL_BAR 1
#define CHART_TYPE_VERTICAL_BAR 2
#define CHART_TYPE_PIE 3
#define CHART_TYPE_LINE 4
#define CHART_TYPE_DATA_TABLE 5
#define CHART_TYPE_TIME_PLOT 6
#define CHART_TYPE_TIME_SERIES_HISTOGRAM 7
#define CHART_TYPE_FINANCIAL 8
#define CHART_TYPE_GANTT 9

#define CURSOR_DEFAULT 1
#define CURSOR_SIZE_XY 8
#define CURSOR_SIZE_YX 9
#define CURSOR_SIZE_X 10
#define CURSOR_SIZE_Y 11
#define CURSOR_MOVE 12

#define STAT_SUCCESS 0
#define STAT_ERR_UNABLE -1
#define STAT_ERR_AGGREGATE -2

#define STAT_DRAW_INVLD_DATA 1
#define STAT_DRAW_FILTERED 2
#define STAT_DRAW_MAXTIME 3
#define STAT_DRAW_SKIP 4

#define AGGREGATION_TYPE_NONE 0
#define AGGREGATION_TYPE_ONE 1
#define AGGREGATION_TYPE_MANY 2
#define AGGREGATION_TYPE_NAMED_LIST 3

#define STAT_CONTENT 0
#define STAT_CONTENT_AVG 1
#define STAT_CONTENT_MIN 2
#define STAT_CONTENT_MAX 3
#define STAT_INPUT 4
#define STAT_OUTPUT 5
#define STAT_STAYTIME_AVG 6
#define STAT_STAYTIME_MIN 7
#define STAT_STAYTIME_MAX 8
#define STAT_STATE_TOTAL 9
#define STAT_STATE_PERCENT 10
#define STAT_STATE_AVG 11
#define STAT_COMBINED 12
#define STAT_INPUT_AVG 13
#define STAT_OUTPUT_AVG 14
#define STAT_STAYTIME 15

#define APPLY_LINKS_ON_OPEN 1
#define APPLY_LINKS_ON_CHANGE_OBJECT 2

#define EXP_VAR_TYPE 1
#define EXP_VAR_NAME 2
#define EXP_VAR_SAVE_DATA 3

#define EXP_VAR_ON_REMOVE 1
#define EXP_VAR_SET_SCENARIO 2

#define EXP_VAR_CONTENT 3

#define BUNDLE_FLAG_UNPAGED 0x1
#define BUNDLE_FLAG_KEYED 0x2
#define BUNDLE_FLAG_SORTED 0x4

#define BUNDLE_FLAG_IR_OPT 0x10

#define BUNDLE_FIELD_TYPE_DOUBLE 1
#define BUNDLE_FIELD_TYPE_INT 2
#define BUNDLE_FIELD_TYPE_STR 3
#define BUNDLE_FIELD_TYPE_FLOAT 4
#define BUNDLE_FIELD_TYPE_VARCHAR 5
#define BUNDLE_FIELD_TYPE_NODEREF 6
#define BUNDLE_FIELD_TYPE_BINARY 7
#define BUNDLE_FIELD_TYPE_MASK 0x00FF

#define BUNDLE_FIELD_INDEX_MAP 0x0100
#define BUNDLE_FIELD_INDEX_HASH 0x0200
#define BUNDLE_FIELD_INDEX_MASK 0x7F00

#define BUNDLE_FIELD_NULLABLE 0x8000

#define BUNDLE_FIELD_NAME_SIZE 64

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

#define CWSM_END 0
#define CWSM_DOUBLE 1
#define CWSM_NODE 2
#define CWSM_STRING 3
#define CWSM_BUNDLE_DATA 4
#define CWSM_BUNDLE_HEADER 5
#define CWSM_BUNDLE_RANGE 6
#define CWSM_BUNDLE 7
#define CWSM_BINARY_BYTEBLOCK 8
#define CWSM_JSON 9

#define STATE_PROFILE_CURRENT 1
#define STATE_PROFILE_SINCE 2
#define STATE_PROFILE_LIST 3

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

#define START_TIME_STR 71
#define CURRENT_TIME_STR 72
#define STOP_TIME_STR 73
#define WARMUP_TIME_STR 74

#define WARMUP_TIME 81
#define WARMUP_TIME_NODE 82

// Constants group: FLUID CONVEYOR
#define FLUID_CONVEYOR_DIRECTION_FORWARD  1
#define FLUID_CONVEYOR_DIRECTION_REVERSE  2

#define FLUID_CONVEYOR_LAYOUT_AUX_CONVEYOR_ALPHA  1
#define FLUID_CONVEYOR_LAYOUT_AUX_ENDPOINTS  2
#define FLUID_CONVEYOR_LAYOUT_AUX_NORMALS  3
#define FLUID_CONVEYOR_LAYOUT_AUX_DIRECTION_INDICATORS  4

#define FLUID_CONVEYOR_LAYOUT_AUX_DIRECTION_INDICATORS_VERTICES  1
#define FLUID_CONVEYOR_LAYOUT_AUX_DIRECTION_INDICATORS_COLORS  2

#define FLUID_CONVEYOR_INFO_LEAD_X_POSITION_1_BASED  1
#define FLUID_CONVEYOR_INFO_MID_X_POSITION_1_BASED  2
#define FLUID_CONVEYOR_INFO_LEAD_RIGHT_Y_POSITION_1_BASED  3
#define FLUID_CONVEYOR_INFO_MID_RIGHT_Y_POSITION_1_BASED  4
#define FLUID_CONVEYOR_INFO_LEAD_LEFT_Y_POSITION_1_BASED  5
#define FLUID_CONVEYOR_INFO_MID_LEFT_Y_POSITION_1_BASED  6
#define FLUID_CONVEYOR_INFO_SLICE_SIZE_Y_1_BASED  7
#define FLUID_CONVEYOR_INFO_COUNT  7

#define FLUID_CONVEYOR_PREVIOUS_LAYOUT_NUMBER_OF_SLICES  1
#define FLUID_CONVEYOR_PREVIOUS_LAYOUT_LENGTH  2
#define FLUID_CONVEYOR_PREVIOUS_LAYOUT_INPUT_WIDTH  3
#define FLUID_CONVEYOR_PREVIOUS_LAYOUT_OUTPUT_WIDTH  4
#define FLUID_CONVEYOR_PREVIOUS_LAYOUT_CENTERLINE_OFFSET  5

#define FLUID_CONVEYOR_INPUTS_OBJECT  1
#define FLUID_CONVEYOR_INPUTS_START_RANGE  2
#define FLUID_CONVEYOR_INPUTS_END_RANGE  3
#define FLUID_CONVEYOR_INPUTS_START_SLICE_INDEX  4
#define FLUID_CONVEYOR_INPUTS_END_SLICE_INDEX  5
#define FLUID_CONVEYOR_INPUTS_INPORT_NUMBER  6
#define FLUID_CONVEYOR_INPUTS_COUNT  6

#define FLUID_CONVEYOR_OUTPUTS_OBJECT  1
#define FLUID_CONVEYOR_OUTPUTS_POSITION  2
#define FLUID_CONVEYOR_OUTPUTS_FORWARD_PERCENTAGE  3
#define FLUID_CONVEYOR_OUTPUTS_REVERSE_PERCENTAGE  4
#define FLUID_CONVEYOR_OUTPUTS_STOPPED_RATE  5
#define FLUID_CONVEYOR_OUTPUTS_OUTPORT_NUMBER  6
#define FLUID_CONVEYOR_OUTPUTS_AUX_ROW  7
#define FLUID_CONVEYOR_OUTPUTS_COUNT 7

#define FLUID_CONVEYOR_OUTPUTS_AUX_OUTPORT_NUMBER  1
#define FLUID_CONVEYOR_OUTPUTS_AUX_POSITION  2
#define FLUID_CONVEYOR_OUTPUTS_AUX_FORWARD_PERCENTAGE  3
#define FLUID_CONVEYOR_OUTPUTS_AUX_REVERSE_PERCENTAGE  4
#define FLUID_CONVEYOR_OUTPUTS_AUX_STOPPED_RATE  5
#define FLUID_CONVEYOR_OUTPUTS_AUX_STOPPED_PER_TICK  6
#define FLUID_CONVEYOR_OUTPUTS_AUX_MATERIAL_LEAVING  7
#define FLUID_CONVEYOR_OUTPUTS_AUX_OUTPUT_PERCENTAGE  8
#define FLUID_CONVEYOR_OUTPUTS_AUX_OUTSLICE_INDEX  9
#define FLUID_CONVEYOR_OUTPUTS_AUX_REPOSED_MATERIAL 10
#define FLUID_CONVEYOR_OUTPUTS_AUX_COUNT  10

#define FLUID_CONVEYOR_SENSORS_START_RANGE  1
#define FLUID_CONVEYOR_SENSORS_END_RANGE  2
#define FLUID_CONVEYOR_SENSORS_TYPE  3
#define FLUID_CONVEYOR_SENSORS_LOW_VALUE  4
#define FLUID_CONVEYOR_SENSORS_MID_VALUE  5
#define FLUID_CONVEYOR_SENSORS_HIGH_VALUE  6
#define FLUID_CONVEYOR_SENSORS_PREVIOUS_VALUE  7
#define FLUID_CONVEYOR_SENSORS_STATE  8
#define FLUID_CONVEYOR_SENSORS_START_SLICE_INDEX  9
#define FLUID_CONVEYOR_SENSORS_END_SLICE_INDEX  10
#define FLUID_CONVEYOR_SENSORS_COUNT 10

#define FLUID_CONVEYOR_SENSOR_TYPE_VOLUME  1
#define FLUID_CONVEYOR_SENSOR_TYPE_PEAK_HEIGHT  2


// Constants group: PFM
#define PFM_EXPERIMENT_DATA 1
#define PFM_EVALUATOR 2
#define PFM_STATISTIC 2
#define PFM_UNIT_NAME 3

#define BYPASS_NONE 0
#define BYPASS_ALL 0xffffffff
#define BYPASS_PULL_REQUIREMENT  0x1
#define BYPASS_SEND_TO 0x2
#define BYPASS_OUTPUT_CLOSED 0x4
#define BYPASS_OUTPUT_PORT_CLOSED 0x8
#define BYPASS_INPUT_CLOSED 0x10
#define BYPASS_UPSTREAM_STOPPED 0x20
#define BYPASS_STOPPED 0x40

#define PULL_REEVALUATE_ON_READY -2
#define PORT_STATE_REEVALUATE 2

#define OFFSET_NONE 0
#define OFFSET_BY_TE_LOGIC 1
#define OFFSET_NONE_AND_BLOCK 2
#define OFFSET_BY_NAV_LOGIC 3

// reasons for adding a module dependency to a model
#define DEPENDANT_BECAUSE_OBJECT_CREATED 1 // added when a user drops an object into the model
#define DEPENDANT_BECAUSE_NEW_MODEL 2 // added because the user checked a box or something on a new model
#define DEPENDANT_BECAUSE_SUB_DEPENDENCY 3 // added because another module dependency was added for a module that is dependent on this module
#define DEPENDANT_BECAUSE_USER_INPUT 4 // added because the user explicitly pushed some button or chose a menu option (maybe through the model settings window)
#define DEPENDANT_BECAUSE_OTHER 0 // added for some other reason

#define DOCK_PANE_MAIN 1
#define DOCK_PANE_LEFT 2
#define DOCK_PANE_RIGHT 4
#define DOCK_PANE_TOP 8
#define DOCK_PANE_BOTTOM 16
#define DOCK_TOOL_LEFT 32
#define DOCK_TOOL_RIGHT 64
#define DOCK_TOOL_TOP 128
#define DOCK_TOOL_BOTTOM 256

#define DOCK_TYPE_DOCUMENT 101
#define DOCK_TYPE_TOOL 102

#define VIEW_TYPE_TREE 0
#define VIEW_TYPE_PLANAR 1
#define VIEW_TYPE_3D 2
#define VIEW_TYPE_GUI 4
#define VIEW_TYPE_TABLE 5
#define VIEW_TYPE_GRAPH 6
#define VIEW_TYPE_SCRIPT 8
#define VIEW_TYPE_BUTTON 100
#define VIEW_TYPE_EDIT 101
#define VIEW_TYPE_PANEL 102
#define VIEW_TYPE_STATIC 103
#define VIEW_TYPE_CHECKBOX 105
#define VIEW_TYPE_RADIOBUTTON 106
#define VIEW_TYPE_COMBOBOX 109
#define VIEW_TYPE_LISTBOX 114
#define VIEW_TYPE_TAB_CONTROL 115
#define VIEW_TYPE_TOOLBAR 116
#define VIEW_TYPE_TAB_CONTROL_BOTTOM 118
#define VIEW_TYPE_TRACKER 122
#define VIEW_TYPE_HTML 124

#define CONSOLE_OUTPUT 1
#define CONSOLE_SYSTEM 2
#define CONSOLE_COMPILER 3
#define CONSOLE_TRACE 4

// nodefunction listen event macros
#define NFL_PRE_LISTEN 0x1
#define NFL_LISTEN 0x2
#define NFL_PERSIST 0x4
#define NFL_PASS_THROUGH_PARAMS 0x8
#define NFL_LISTEN_ONCE 0x10

#define NFL_STOP_LISTENING -1

#define EVENT_PRE_LISTEN 0x1
#define EVENT_LISTEN 0x2
#define EVENT_PERSIST 0x4
#define EVENT_PASS_THROUGH_PARAMS 0x8
#define EVENT_LISTEN_ONCE 0x10

#define EVENT_STOP_LISTENING -1

#define RESUME_AT_SAME_POS 0
#define RESUME_AT_NEXT_KEYFRAME 1
#define RESUME_AT_TIME 2

#define FLEXSIM_MESSAGE_USER_CALLBACK 2001
#define FLEXSIM_MESSAGE_USER_NODEFUNCTION 2002

#define OVERRIDE_DRAW_SIZER_X      0x10
#define OVERRIDE_DRAW_SIZER_Y      0x20
#define OVERRIDE_DRAW_SIZER_Z      0x40
#define OVERRIDE_DRAW_SIZER_X_NEG  0x80
#define OVERRIDE_DRAW_SIZER_Y_NEG  0x100
#define OVERRIDE_DRAW_SIZER_Z_NEG  0x200
#define OVERRIDE_DRAW_SIZER_ALL    0x3f0
#define OVERRIDE_DRAW_YELLOW_BOX   0x400
#define OVERRIDE_DRAW_GREEN_BOX    0x800
#define OVERRIDE_DRAW_REDBOX       0x1000
#define OVERRIDE_DRAW_HOVERBOX     0x2000
#define OVERRIDE_DRAW_ALL          0x0ffffff0

#define OVERRIDE_SET_MOUSE_DOWN_PICK 0x10000000
#define OVERRIDE_SET_MOUSE_UP_PICK 0x20000000
#define OVERRIDE_SET_MOUSE_MOVE_PICK 0x30000000
#define OVERRIDE_SET_MOUSE_HOVER_PICK 0x40000000

#define STAT_MEAN 1
#define STAT_AVERAGE 1
#define STAT_CURRENT 2
#define STAT_CONF_INTERVAL_HALF_WIDTH 2
#define STAT_MIN 3
#define STAT_MAX 4
#define STAT_TIME_AT_VALUE 5
#define STAT_VARIANCE 5
#define STAT_NUM_CATEGORIES 6
#define STAT_STD_DEV 6
#define STAT_SUM 7
#define STAT_COUNT 8
// this should be the same as FLT_MAX
#define STAT_UNDEFINED 340282346600000000000000000000000000000.0

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
#define DRAW_FLAG_CENTER_PORT_NAMES 0x1000
#define DRAW_FLAG_INOUT_PORT_NAMES 0x2000

// drawimage
#define NO_SCALE 0
#define SCALE_DOWN 1
#define SCALE_UP_DOWN 2
#define SCALE_INDEPENDENT 3

#define DB_SQL_FLAG_FORWARD_ONLY_CURSOR 0x1

#define IGNORE_CASE 1

#define EDIT_MODE_GET_MODE_NUM -1
#define EDIT_MODE_GET_MODE_DELEGATE -2
#define EDIT_MODE_GET_DEPTH -3
#define EDIT_MODE_DEPTH_PUSH -4
#define EDIT_MODE_DEPTH_POP -5

#define PARAM_TYPE_NUMBER 1
#define PARAM_TYPE_NODE 2
#define PARAM_TYPE_STRING 3

#define FGL_INFO_SHADERTYPE 1
#define FGL_INFO_SHADOWTYPE 2
#define FGL_INFO_MODELVIEW_MATRIX 3
#define FGL_INFO_PROJECTION_MATRIX 4
#define FGL_INFO_OVERRIDES 5
#define FGL_INFO_MESH_RENDER_MODE 6

// shader pass macros
#define SHADERTYPE_DEFAULT 0
#define SHADERTYPE_RENDER_SHADOWS 1
#define SHADERTYPE_BLUR 2
#define SHADERTYPE_SUM_AREA_TABLE 3
#define SHADERTYPE_RENDER_ODA 4

#define SHADOWTYPE_NONE 0
#define SHADOWTYPE_HARD 1
#define SHADOWTYPE_VSM 2
#define SHADOWTYPE_PCSS 3
#define SHADOWTYPE_PCSS_SAVSM 4

#define SHAPEINFO_GET_ANIMATION_COUNT 1
#define SHAPEINFO_GET_ANIMATION_NAME 2
#define SHAPEINFO_GET_ANIMATION_DURATION 3
#define SHAPEINFO_SET_ANIMATION 4
#define SHAPEINFO_UPDATE_ANIMATION 5
#define SHAPEINFO_FIND_ANIMATION_CLIP_LIST 6
#define SHAPEINFO_GET_BONE_MATRIX_INDEX 7
#define SHAPEINFO_EXPORT_MESHES 8
#define SHAPEINFO_ADD_ANIMATIONS_FROM_FILE 9
#define SHAPEINFO_GET_ANIMATION_FILE_NAME 10
#define SHAPEINFO_GET_MESH_COUNT 11
#define SHAPEINFO_GET_MESH_NAME 12
#define SHAPEINFO_STORE_BONES_IN_TREE 13
#define SHAPEINFO_DRAW_BONES_IN_TREE 14

#define LIST_PULL_ALL_OR_NOTHING 0x1
#define LIST_PARSE_QUERY 0x2
#define LIST_PULL_ENTRY_NODES 0x4
#define LIST_DO_NOT_REMOVE 0x8
#define LIST_DO_NOT_BACK_ORDER 0x10
#define LIST_PULL_BACK_ORDERS 0x20
#define LIST_DO_NOT_FULFILL 0x40
#define LIST_RETURN_BACK_ORDER_IF_NOT_FULFILL 0x80

// Config
#define VREC_DEBUG_NOOUTPUT 0

// Paths
#define VREC_PATH_FFMPEG concat(pdir(), "ffmpeg\\ffmpeg.exe")
#define VREC_PATH_TOOLS concat(pdir(), "ffmpeg\\")
#define VREC_PATH_TOOL_RUNFFMPEG concat(VREC_PATH_TOOLS, "run_ffmpeg.bat")
#define VREC_PATH_TOOL_CLEANUP concat(VREC_PATH_TOOLS, "cleanup.bat")

// Messages
#define VREC_MSG_JOBS_RUN 1
#define VREC_MSG_JOB_START 2
#define VREC_MSG_JOB_STOP 3
#define VREC_MSG_SEQ_START 4
#define VREC_MSG_SEQ_STOP 5
#define VREC_MSG_FRAME 6

// Size modes
#define VREC_SIZEMODE_CUSTOM 0
#define VREC_SIZEMODE_INHERIT 1
#define VREC_SIZEMODE_VIEW 2

// Record modes
#define VREC_RECMODE_ALL 1
#define VREC_RECMODE_ONE 2

// Metrics
#define VREC_METRIC_OUT_TIME 1
#define VREC_METRIC_OUT_FRAMES 2
#define VREC_METRIC_SEQ_TIME 3
#define VREC_METRIC_SEQ_FRAMES 4
#define VREC_METRIC_SEQ_INTERVAL 5
#define VREC_METRIC_LAY_WIDTH 6
#define VREC_METRIC_LAY_HEIGHT 7
#define VREC_METRIC_LAY_VFLIP 8

// Layer types
#define VREC_LAYER_COLOR 1
#define VREC_LAYER_VIEW 2

// Animation
//// Coordinates
#define VREC_COORD_X 1
#define VREC_COORD_Y 2
//// Margin types
#define VREC_MARGIN_PIXELS 1
#define VREC_MARGIN_PERCENT 2
//// Alignment types
#define VREC_ALIGN_MIN 1
#define VREC_ALIGN_MID 2
#define VREC_ALIGN_MAX 3
//// Interpolation types
#define VREC_INTERPOLATE_LINEAR 1
#define VREC_INTERPOLATE_COSINE 2

// Event Listener
#define EVENT_PARAM_1 "%$1$%"
#define EVENT_PARAM_2 "%$2$%"
#define EVENT_PARAM_3 "%$3$%"
#define EVENT_PARAM_4 "%$4$%"
#define EVENT_PARAM_5 "%$5$%"
#define EVENT_PARAM_6 "%$6$%"
#define EVENT_PARAM_7 "%$7$%"
#define EVENT_PARAM_8 "%$8$%"
#define EVENT_PARAM_9 "%$9$%"
#define EVENT_PARAM_10 "%$A$%"

// Event Listener Aliases
#define LIST_ON_FULFILL_VALUE "%$1$%"
#define LIST_ON_FULFILL_NUM_FULFILLED "%$2$%"
#define LIST_ON_FULFILL_TOTAL_FULFILLED "%$3$%"
#define LIST_ON_FULFILL_NUM_REQUESTED "%$4$%"
#define LIST_ON_FULFILL_NUM_REQUIRED "%$5$%"
#define LIST_ON_PULL_VALUE "%$1$%"
#define LIST_ON_PULL_PULLER "%$2$%"

#define EVENT_INFO_TABLE_COL_NAME 1
#define EVENT_INFO_TABLE_COL_REF 2
#define EVENT_INFO_TABLE_COL_FLAGS 3
#define EVENT_INFO_TABLE_COL_PARAMS 4
#define EVENT_INFO_TABLE_COL_REQUIREMENTS 5

#define EVENT_INFO_PARAMS 0x1
#define EVENT_INFO_DEFAULT_CODE 0x2
#define EVENT_INFO_CATEGORY 0x3
#define EVENT_INFO_LOCALIZED_TITLE 0x4
#define EVENT_INFO_REQUIREMENTS 0x5

#define BIND_EVENT_ENUMERATE 1
#define BIND_EVENT_ASSERT 2
#define BIND_EVENT_ON_LOAD 3
#define BIND_EVENT_FILL_BINDING_ENTRY 4

#define EVENT_TYPE_MASK 0x7
#define EVENT_TYPE_DEFAULT 0x1
#define EVENT_TYPE_VALUE_GETTER 0x2
#define EVENT_TYPE_VALUE_NOTIFIER 0x4
#define EVENT_TYPE_TRIGGER 0x8

// A flag to not allow the event binding to a node based on the byte offset from the sdt memory pointer.&lt;/summary&gt;
#define EVENT_DO_NOT_BIND_BYTE_OFFSET 0x100
#define EVENT_ATTRIBUTE 0x200
#define EVENT_NO_DEFAULT_CODE 0x400
#define EVENT_RELAYED 0x800

// the mask around all requirments flags
#define EVENT_REQUIREMENTS 0x30000
// shift the requirements masked value 16 bits to get the number of requirements
#define EVENT_REQUIREMENTS_BIT_SHIFT 16
#define EVENT_1_REQUIREMENT 0x10000
#define EVENT_2_REQUIREMENTS 0x20000
#define EVENT_3_REQUIREMENTS 0x30000

#define STAT_INFO_REQUIREMENTS 0x1
#define STAT_INFO_LOCALIZED_TITLE 0x2

#define BIND_STAT_ENUMERATE 1
#define BIND_STAT_ASSERT 2
#define BIND_STAT_ON_LOAD 3
#define BIND_STAT_FILL_BINDING_ENTRY 4
#define BIND_STAT_ON_RUNWARM 5

#define STAT_TYPE_MASK 0x7
#define STAT_TYPE_LEVEL 0x1 
#define STAT_TYPE_CUMULATIVE 0x2
#define STAT_TYPE_TIME_SERIES 0x3
#define STAT_TYPE_CATEGORICAL 0x4
#define STAT_TYPE_KINETIC_LEVEL 0x5
#define STAT_TYPE_POINTER 0x6
#define STAT_TYPE_CATEGORICAL_COMBO 0x7

#define STAT_RELAYED 0x100
#define STAT_TIME_WEIGHTED 0x200

#define STAT_REQUIREMENTS 0x30000
#define STAT_REQUIREMENTS_BIT_SHIFT 16
#define STAT_1_REQUIREMENT 0x10000
#define STAT_2_REQUIREMENTS 0x20000
#define STAT_3_REQUIREMENTS 0x30000

#define STAT_DERIVE_CUR 0x1
#define STAT_DERIVE_MIN 0x2
#define STAT_DERIVE_MAX 0x4
#define STAT_DERIVE_AVG 0x8

#define STAT_ENUM_REQS_INVALID 0
#define STAT_ENUM_REQS_STATIC 1
#define STAT_ENUM_REQS_DYNAMIC 2

#define STAT_USE_HISTORY 0x10
#define STAT_USE_PROFILE 0x20
#define STAT_IGNORE_WARMUP 0x40

#define XL_DATETIME 1
#define FS_DATETIME 2
#define MODEL_TIME 3
#define DATE_STR 4
#define TIME_STR 5
#define DATETIME_STR 6
#define WINDOWS_DATETIME_STR 7
#define MODEL_UNITS 8

#define RUN_SPEED_LOW_PRECISION 1
#define RUN_SPEED_HIGH_PRECISION 2

#define STICK_JOY_STATUS 0
#define STICK_JOY_XPOS 1
#define STICK_JOY_YPOS 2
#define STICK_JOY_ZPOS 3
#define STICK_JOY_BUTTONS 4
#define STICK_JOY_SET_CAPTURE 5
#define STICK_JOY_RELEASE_CAPTURE 6
#define STICK_JOY_RPOS 7
#define STICK_JOY_UPOS 8
#define STICK_JOY_VPOS 9
#define STICK_JOY_POV 10
#define STICK_JOY_CURRENT_BUTTON 11
#define STICK_JOY_FLAGS 12
#define STICK_XBOX_STATUS 20
#define STICK_XBOX_BUTTONS 21
#define STICK_XBOX_LEFT_THUMB_X 22
#define STICK_XBOX_LEFT_THUMB_Y 23
#define STICK_XBOX_RIGHT_THUMB_X 24
#define STICK_XBOX_RIGHT_THUMB_Y 25
#define STICK_XBOX_LEFT_TRIGGER 26
#define STICK_XBOX_RIGHT_TRIGGER 27
#define STICK_VR_STATUS 50
#define STICK_VR_THUMB_X 51
#define STICK_VR_THUMB_Y 52
#define STICK_VR_INDEX_TRIGGER 53
#define STICK_VR_GRIP_TRIGGER 54
#define STICK_VR_BUTTON_1 55
#define STICK_VR_BUTTON_2 56
#define STICK_VR_BUTTON_3 57
#define STICK_VR_BUTTON_4 58
#define STICK_VR_TOUCH_BUTTON_1 59
#define STICK_VR_TOUCH_BUTTON_2 60
#define STICK_VR_TOUCH_BUTTON_3 61
#define STICK_VR_TOUCH_BUTTON_4 62
#define STICK_VR_TOUCH_THUMB_REST 63
#define STICK_VR_TOUCH_INDEX_TRIGGER 64
#define STICK_VR_TOUCH_POINTING 65
#define STICK_VR_TOUCH_THUMB_UP 66
#define STICK_VR_HAND_POSITION 67
#define STICK_VR_HAND_ROTATION 68
#define STICK_VR_HAND_WORLD_POSITION 69
#define STICK_VR_HAND_WORLD_ROTATION 70
#define STICK_VR_HAND_OFFSET_POSITION 71
#define STICK_VR_TARGET_FLOOR_POSITION 72
#define STICK_VR_SET_VIBRATION 73
#define STICK_VR_SUBMIT_VIBRATION 74

#define TASKBAR_NORMAL 2
#define TASKBAR_ERROR 4
#define TASKBAR_PAUSED 8
#define TASKBAR_INDETERMINATE 1

#define WS_VISIBLE 0x10000000

#define REFRESH_VIEW_PRESERVE_FLAGGED 0x1
#define REFRESH_VIEW_REFRESH_ONLY 0x2
#define REFRESH_VIEW_DELAY_VISIBLE 0x4


namespace FlexSim {

}


// Include Header
#include <float.h>

// The following #defines can be changed to customize the connection controls.
// The following keys are already in use and should NOT be used here : A, Q, S, W, O, T, N, P, X
//#include ".\include\eventstruct.h"

#define INOUT_KEY1 'J'
#define INOUT_KEY2 'U'
#define CENTER_KEY1 'K'
#define CENTER_KEY2 'I'

#define DEFAULTZERO = 0
#define DEFAULTNULL = 0x0
#define DEFAULTONE = 1
#define DEFAULTPARAM(val) = val

namespace FlexSim {

class FlexSimEventHandler;

class FlexSimObject;

class StorageObject;

class Rack;

class GravityFlowRack;

class DriveInRack;

class PushBackRack;

class FloorStorage;

class Dispatcher;

class TaskExecuter;

class FixedResource;

class Navigator;

class NetworkNode;

class NetworkNavigator;

class FlowItem;

class SplineEndPoint;

class DatabaseConnector;

class Task;

class TaskSequence;


///////////////////////////////////////////////////////
// Travel Requests
///////////////////////////////////////////////////////
class TravelRequest : public SimpleDataType
{
  public:
	virtual const char* getClassFactory() {return "TravelRequest";}
	virtual void bind();
	treenode traveler;
	treenode staticTravelMemberNode; // the rank of the coupling node in the Navigator's travelers variable.
	double beginTime; // the begin time of the travel request.
	double totalDist;// the total distance to travel.
	double endSpeed;
};

class NavigatorRequest : public TravelRequest
{
public:
	virtual const char* getClassFactory() {return "NavigatorRequest";}
	virtual void bind();
	double rotationTime; // the time it will take to rotate around
	int initRY;
	int initRZ;
	int rotateY;
	int rotateZ;
};

class NetworkRequest : public TravelRequest
{
public:
	virtual const char* getClassFactory() {return "NetworkRequest";}
	virtual void bind();
	treenode destination; // the requested destination
	int destCol; // the column of the destination node.
	int originCol; // the column of the original origin node.
	int initRZ; // start z rotation
	unsigned short outPort; // the current output port of the network node
	#define NETREQSTATE_TRAVEL 1
	#define NETREQSTATE_WAIT 2
	unsigned char state;
	double nodeBeginTime; // the time that the traveller entered into the current node.
	treenode curNetNode; // the current network node that is managing the object
	unsigned short curTControlRank; // the rank of the traffic control that I'm attempting to enter
	int flipped;
	float lastUpdatedDistAlongEdge;
	float distTraveled;
	float edgeAccDist;
	float edgeDecDist;
	float edgeEndSpeed;
	double nextNodeArrivalTime;
	float edgeMaxV;
	treenode kinematics;
};

class NetworkNodeMember : public CouplingDataType
{
public:
	virtual const char* getClassFactory() {return "NetworkNodeMember";}
	virtual void bind();
	struct ConnectionInfo
	{
		int tableRow;
		float distance;
		int outPort;
	};
	std::vector<ConnectionInfo> connections;
	std::vector<float> distanceTable;
	std::vector<unsigned char> nextOutPortTable;
	NetworkNode* getNetNode();
};

class TrafficControlRequest
{
	public:
	treenode travelreqnode;
	NetworkNode* tonetnode;
	unsigned short nextport;
	unsigned short fromrank;
	unsigned short torank;

	static char* displaydata(treenode thenode, int verbose);
};

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

typedef NodeListArray<Task, nullptr, nullptr, 0, ThrowingAssertionMethod>::SdtSubNodeType TaskArray;
typedef NodeListArray<TaskSequence, nullptr, nullptr, 0, ThrowingAssertionMethod>::SdtSubNodeType TaskSequenceArray;

class TaskSequence : public SimpleDataType{
	public:
	TaskSequence() : labelsNode(0) {}
	~TaskSequence() {if (labelsNode) delete labelsNode;}
	float priority; 
	unsigned char preempt; 
	unsigned char coordinated; // if the task is coordinated
	unsigned int curtask; // this number is the rank of the task that is currently being worked on.
	treenode owner; // this is only used in coordinated tasks.  It is there so that the proxy task executers have a reference back to the dispatcher that has the task sequence
	unsigned int milestone; // this is the rank of the current milestone
	unsigned int nrofallocations; // this is the current number of objects allocated or whose allocation has been requested
	int waitForFinishState = 0;
	virtual const char* getClassFactory() override {return "TaskSequence";}
	FS_CONTENT_DLL_FUNC virtual void bind() override;
	FS_CONTENT_DLL_FUNC virtual void bindInterface() override;
	FS_CONTENT_DLL_FUNC virtual char* toString(int verbose) override;
	FS_CONTENT_DLL_FUNC virtual int getCapabilities() override { return 1; } //Labels
	FS_CONTENT_DLL_FUNC virtual treenode getObjectTree() override;
	FS_CONTENT_DLL_FUNC virtual TreeNode* getLabelNode(const char* labelName, bool assert) override;
	FS_CONTENT_DLL_FUNC virtual TreeNode* getLabelNode(int labelRank, bool assert) override;
	
	FS_CONTENT_DLL_FUNC Variant getLabelProperty(const char* name, unsigned nameHash, bool dieHard);
	FS_CONTENT_DLL_FUNC void setLabelProperty(const char* name, unsigned nameHash, const Variant& value);

	FS_CONTENT_DLL_FUNC static TaskSequence* create(treenode obj, double priority = 0.0, int preempt = 0, int waitForFinishState = 0);
	FS_CONTENT_DLL_FUNC Task* addTask(int type, treenode involved1 = nullptr, treenode involved2 = nullptr, const Variant& var1 = Variant(), 
		const Variant& var2 = Variant(), const Variant& var3 = Variant(), const Variant& var4 = Variant());
		
	FS_CONTENT_DLL_FUNC void finish();
	
	treenode labelsNode;
	void reset();
	
	private:
	int __getPreempt() { return preempt; }
	void __setPreempt(int toVal) { preempt = (char)toVal; }
	double __getPriority() { return priority; }
	void __setPriority(double toVal) { priority = toVal; }
	int __getRank() { return holder->rank; }
	void __setRank(int toRank) { holder->rank = toRank; }
	
	public:
	FS_CONTENT_DLL_FUNC void __dispatch(treenode dispatcher);
	Task* __getCurrentTask() { return holder->subnodes[curtask]->objectAs(Task); }
	
	__declspec(property(get=__getCurrentTask)) Task* currentTask;
	
	TaskArray __getTasks() { return TaskArray(holder); }
	__declspec(property(get=__getTasks)) TaskArray tasks;
	
	void dispatch() { __dispatch(nullptr);}
	FS_CONTENT_DLL_FUNC void move(Dispatcher* toDisp);
	
	operator treenode() { return holder; }
	operator Variant() { return holder; }
};


class Task : public SimpleDataType{
	public:
	unsigned short type;
	// The state variable will usually go from UNFINISHED, to ACTIVE, to FINISHED.  However, if it is coordinated, it will go to COORDINATED instead of ACTIVE,
	// so that the proxy executer knows that it's a coordinated, and should be finished by the Dispatcher that is coordinating the tasks.
	unsigned short state;
	// The following are the most used variables of the task.
	treenode involved1;
	treenode involved2;
	Variant var1;
	Variant var2;
	Variant var3;
	Variant var4;

	// syncnextkey is only used in coordinated tasks.  The dispatcher, when coordinating tasks, may immediately run through several proxy tasks for the same 
	// executer.  However, it will not tell a proxy executer to begin a task until all of the previous tasks for that executer have been finished.  If it gets to a 
	// proxy task, and the executer is busy on a previous proxy task, it will set the syncenextkey variable of the previous proxy task to the rank of this task.  
	// Then it will trigger the next task once the executer is finished.
	unsigned int syncnextkey;
	// The executerkey is specified by the user.  This is a reference to the rank of an allocate task, and specifies the executer that will execute a proxy task.
	unsigned int executerkey;
	virtual const char* getClassFactory() override {return "Task";}
	virtual void bind() override;
	virtual void bindInterface() override;
	virtual char* toString(int verbose) override;
	
	private:
	int __getType() { return type; }
	void __setType(int toVal) { type = toVal; }
	treenode __getInvolved1() { return involved1; }
	void __setInvolved1(treenode toVal) { involved1 = toVal; }
	treenode __getInvolved2() { return involved2; }
	void __setInvolved2(treenode toVal) { involved2 = toVal; }
	Variant __getVar1() { return var1; }
	void __setVar1(const Variant& toVal) { var1 = toVal; }
	Variant __getVar2() { return var2; }
	void __setVar2(const Variant& toVal) { var2 = toVal; }
	Variant __getVar3() { return var3; }
	void __setVar3(const Variant& toVal) { var3 = toVal; }
	Variant __getVar4() { return var4; }
	void __setVar4(const Variant& toVal) { var4 = toVal; }
	int __getState() { return state; }
	int __getRank() { return holder->rank; }
	void __setRank(int toVal) { holder->rank = toVal; }
};


// deprecated
class SendMessageEvent : public FlexSimEvent {
	public:
	double par1;
	double par2;
	double par3;
	SendMessageEvent() : FlexSimEvent(), par1(0), par2(0), par3(0)
		{}
	SendMessageEvent(treenode toobject, double time, treenode fromobject, double par1, double par2, double par3) 
			: FlexSimEvent(toobject, time, fromobject, EVENT_SENDMESSAGE, NULL),
			par1(par1), par2(par2), par3(par3)
		{}
	virtual void execute();
	virtual const char* getClassFactory() {return "SendMessageEvent";}
	virtual void bind();
	virtual void getDescription(char* toStr, size_t maxSize);
	virtual void getEventDataDescription(char* toStr, size_t maxSize);
};

class SimulationStartEvent : public FlexSimEvent {
public:
	SimulationStartEvent() : FlexSimEvent() {}
	SimulationStartEvent(FlexSimEventHandler* firstObject);
	virtual void execute();
	virtual const char* getClassFactory() {return "SimulationStartEvent";}
	virtual void bind();
	FS_CONTENT_DLL_FUNC static void addObject(FlexSimEventHandler* object);
	FS_CONTENT_DLL_FUNC static void clearPostResetObjects();
	FS_CONTENT_DLL_FUNC static void addPostResetObject(ObjectDataType* object);
	FS_CONTENT_DLL_FUNC static void executePostReset();
private:
	std::vector<ObjRef<FlexSimEventHandler>> objects;
	static std::vector<ObjRef<ObjectDataType>> postResetObjects;
	static ObjRef<SimulationStartEvent> simulationStartEvent;
};

class MTBFCheckEvent : public FlexSimEvent {
public:
	MTBFCheckEvent() : FlexSimEvent() {}
	MTBFCheckEvent(TreeNode* mtbfNode, TreeNode* coupling) : FlexSimEvent(), mtbfNode(mtbfNode), coupling(coupling) {}
	virtual void execute() override;
	virtual const char* getClassFactory() override {return "MTBFCheckEvent";}
private:
	TreeNode* mtbfNode;
	TreeNode* coupling;
};

class FRItemInfo : public SimpleDataType
{
friend class FixedResource;
friend class TaskExecuter;
public:
	FRItemInfo() : state(0), sendto(0), involved(0), transportOutCompleteObject(0), transportInCompleteObject(0) {}
	virtual const char* getClassFactory() {return "FRItemInfo";}
	virtual void bind();
	void reset();
private:
	FixedResource* curFR;
	int state;
	int sendto;
	double vars[3];
	treenode involved;
public:
	treenode transportOutCompleteObject;
	treenode transportInCompleteObject;
};

class PullIterator
{
public:
	virtual TreeNode* getNext() = 0;
	static PullIterator* s_customPullIterator;
};

class FifoPullIterator : public PullIterator
{
protected:
	int numReleased;
	int numChecked;
	int curRank;
	int totalContent;
	int outPort;
	TreeNode* frNodeBranch;
public:
	static FifoPullIterator fifoPullIterator;
	virtual TreeNode* getNext() override;
	void init(FixedResource*, int outPort);
};

class LifoPullIterator : public FifoPullIterator
{
public:
	static LifoPullIterator lifoPullIterator;
	virtual TreeNode* getNext() override;
	void init(FixedResource*, int outPort);
};

struct conviteminfostruct : public SimpleDataType {
	virtual const char* getClassFactory() {return "conviteminfostruct";}
	virtual void bind();
	double entrytime;
	double distbehindkinematic; 
	double totalspacebefore; 
	double spacing; 
	double prodlength; 
	int frontedgepe; 
	int backedgepe;
	// used for basic conveyors
	double position;
	int frontedgedp;
	int backedgedp; 
	int backspacedp; 
};

struct bciteminfostruct{
};

extern char * tasktypenames[];

extern treenode* nexttreeunderstack;
extern int nexttreeunderstacktop;
extern int nexttreeunderstacksize;

struct delayedmessagedata
{
	int nrofparams;
	double params[7];
};

#define INTO_GLOBAL_SCOPE return 0;}catch(...){return 0;}}
#define OUT_OF_GLOBAL_SCOPE(NAME) double dummy##NAME##Function(){try{

FS_CONTENT_DLL_FUNC extern int globalnouserreset;
extern treenode _defaultNetworkNavigator;

extern double messageeventfilter_p1;
extern double messageeventfilter_p2;
extern double messageeventfilter_p3;

#define NR_CONTENT_EVENT_TYPES 95
extern int g_logeventtypes[];
extern int * g_logeventtypesenabled[]; 
extern int * g_eventloggingenabled;

extern int g_tasksequencecounter;
// these are array indexes used to reference eventtype indexes in the LOGEVENT() macro
#define LE_interarrivaltime 0
#define LE_sendtoport 1
#define LE_transportdispatcher 2
#define LE_resettrigger 3
#define LE_messagetrigger 4
#define LE_creationtrigger 5
#define LE_entrytrigger 6
#define LE_exittrigger 7
#define LE_receivefromport 8
#define LE_pullrequirement 9
#define LE_endcollectingtrigger 10
#define LE_setuptime 11
#define LE_cycletime 12
#define LE_processdispatcher 13
#define LE_setupfinishtrigger 14
#define LE_processfinishtrigger 15
#define LE_splitquantity 16
#define LE_photoeyecovertrigger 17
#define LE_photoeyeuncovertrigger 18
#define LE_conveyendtrigger 19
#define LE_sendrequirement 20
#define LE_itemspeed 21
#define LE_placeinbay 22
#define LE_placeinlevel 23
#define LE_minimumstaytime 24
#define LE_enddwelltimetrigger 25
#define LE_inflowrate 26
#define LE_outflowrate 27
#define LE_risethroughhighmarktrigger 28
#define LE_fallthroughhighmarktrigger 29
#define LE_risethroughmiddlemarktrigger 30
#define LE_fallthroughmiddlemarktrigger 31
#define LE_risethroughlowmarktrigger 32
#define LE_fallthroughlowmarktrigger 33
#define LE_passto 34
#define LE_queuestrategy 35
#define LE_onresourceavailable 36
#define LE_loadtime 37
#define LE_unloadtime 38
#define LE_breakto 39
#define LE_loadtrigger 40
#define LE_unloadtrigger 41
#define LE_collisiontrigger 42
#define LE_entrytrigger_nn 43
#define LE_arrivaltrigger 44
#define LE_requesttrigger 45
#define LE_onbeginoffset 46
#define LE_onfinishoffset 47
#define LE_pickoffset 48
#define LE_placeoffset 49
#define LE_stop 50
#define LE_resume 51
#define LE_advancedfunctions 52
#define LE_transportinnotify 53
#define LE_transportincomplete 54
#define LE_transportoutnotify 55
#define LE_transportoutcomplete 56
#define LE_oncover_dp 57
#define LE_onclear_dp 58
#define LE_lowmarktrigger 59
#define LE_midmarktrigger 60
#define LE_highmarktrigger 61
#define LE_adjustinputrates 62
#define LE_adjustoutputrates 63
#define LE_emptytrigger 64
#define LE_fulltrigger 65
#define LE_beforedelaytrigger 66
#define LE_afterdelaytrigger 67
#define LE_begintask_travel 68
#define LE_begintask_load 69
#define LE_begintask_frload 70
#define LE_begintask_unload 71
#define LE_begintask_frunload 72
#define LE_begintask_utilize 73
#define LE_begintask_delay 74
#define LE_begintask_break 75
#define LE_begintask_callsubtasks 76
#define LE_begintask_stoprequestbegin 77
#define LE_begintask_stoprequestfinish 78
#define LE_begintask_sendmessage 79
#define LE_begintask_traveltoloc 80
#define LE_begintask_travelrelative 81
#define LE_begintask_pickoffset 82
#define LE_begintask_placeoffset 83
#define LE_begintask_moveobject 84
#define LE_begintask_destroyobject 85
#define LE_begintask_setnodenum 86
#define LE_begintask_milestone 87
#define LE_begintask_nodefunction 88
#define LE_tasksequence_receivets 89
#define LE_tasksequence_begints 90
#define LE_tasksequence_finishts 91
#define LE_begintask_startanimation 92
#define LE_begintask_stopanimation 93
#define LE_begintask_freeoperators 94


class NetworkTravelMember : public CouplingDataType
{
	public:
	FS_CONTENT_DLL_FUNC virtual const char* getClassFactory() {return "NetworkTravelMember";}
	FS_CONTENT_DLL_FUNC void bind();
	ObjRef<NetworkNode> resetNode;
	treenode currentNodeRefNode;
	NodeRef currentNodeRef;
	NodeRef reqNode;
	int blockingState;
};


class DatabaseImporter: public CouplingDataType
{
public:
	virtual void bind() override;
	double shouldImportOnReset = 0.0;
	ByteBlock query;
	virtual const char* getClassFactory() override { return "DatabaseImporter"; }
	void doImport(Database::Connection* connection);
	void onReset(Database::Connection* connection) 
	{ 
		if (shouldImportOnReset) 
			doImport(connection);
	}
};


class DatabaseExporter : public CouplingDataType
{
public:
	virtual const char* getClassFactory() override { return "DatabaseExporter"; }
	virtual void bind() override;
	void doExport(Database::Connection* connection, DatabaseConnector* connector);
	Variant getTableNode(FLEXSIMINTERFACE);
	treenode getTableNode();
	Variant getDefaultSourceColumnName(FLEXSIMINTERFACE);
	string getDefaultSourceColumnName(const char* colName, int colNum);
	treenode getTableOwner();

	ByteBlock tableName;
	treenode columnMap;
	treenode columnInfo;
	double append;
	double batchSize;
};

class ModelDateTime : public SimpleDataType
{
public:
	void update() { applicationcommand("convertunixtime", holder); };
	void setModelTime(double t);
	void setDateTime(double t);	
	
	Variant setModelTime(FLEXSIMINTERFACE) 	{ setModelTime(param(1)); return 0; };
	Variant setDateTime(FLEXSIMINTERFACE) 	{ setDateTime(param(1)); return 0; };
	
	virtual const char* getClassFactory() override { return "ModelDateTime"; }	
	virtual void bind() override;	
	
	double dateTime;
	double modelTime;
	double enabled;
	ByteBlock dateString;
	int year;
	int month;
	int day;
	int dayOfWeek;
	int hour;
	int minute;
	int second;
	int millisecond;	
};

void searchhelpmanual(string searchStr, treenode destNode);

}


;


namespace FlexSim {


// Global Functions
Variant pounddefines();

visible double addsphere(treenode obj, double xval, double yval, double zval, double radius);

visible treenode  bcgetitemkinematics(treenode conveyor, treenode item, int kintype);

visible double  bcgetitemposition(treenode conveyor, treenode item);

visible double  bcsetdirection(treenode conveyor, int direction);

visible double bcsetitemconveystate(treenode conveyor, treenode item, double startpoint, double startspeed, double destspeed, double accdec);

visible int calloperator(treenode dispatcher, treenode origin, treenode involved, double priority, int preempt);

visible double changeconveyorspeed(treenode conveyor, double newspeed);

visible treenode changetask(treenode tasksequence, int taskrank, unsigned short type, treenode involved1 DEFAULTNULL, treenode involved2 DEFAULTNULL, double var1 DEFAULTZERO, double var2 DEFAULTZERO, double var3 DEFAULTZERO, double var4 DEFAULTZERO);

Variant checkforcollisions(treenode obj);

unsigned int classtype(treenode involved);

Variant closenodeedge(treenode curnode, char* edgename);

visible double closenodeedge(treenode curnode, int edgenum);

Variant containerdragconnection(treenode fromobject, treenode toobject, char characterpressed);

visible double containerentry(treenode container, treenode item);

visible double containerexit(treenode container, treenode item);

visible double contextdragconnection(treenode fromobject, treenode toobject, char keypressed);

Variant contextdragconnection(treenode fromobject, treenode toobject, string keypressed);

visible treenode createcoordinatedtasksequence(treenode dispatcher);

visible treenode createdelaytask(treenode dispatcher,double delaytime,double state,double priority,int preempt);

visible treenode createemptytasksequence(treenode dispatcher, double priority, int preempt);

visible treenode createglobaltasksequence(string name, treenode dispatcher, treenode d1, treenode d2, treenode d3, treenode d4, treenode d5);

visible treenode createloadtask(treenode dispatcher,treenode destination,treenode flowitem,double priority,int preempt);

visible treenode createsendmessagetask(treenode dispatcher,treenode receiver, double priority,int preempt,double param1,double param2,double param3);

visible treenode createstandardtask(treenode dispatcher,treenode origin,treenode destination,treenode flowitem,double priority,int preempt);

visible treenode createtravelloadtask(treenode dispatcher,treenode destination,treenode flowitem,double priority,int preempt);

visible treenode createtraveltask(treenode dispatcher,treenode destination,double priority,int preempt);

visible treenode createtraveltolocandwaittask(treenode dispatcher,double relativeloc,double xloc,double yloc,double zloc,double endspeed,double state,double priority,int preempt);

visible treenode createtraveltoloctask(treenode dispatcher,int relativeloc,double xloc,double yloc,double zloc,double endspeed,double priority,int preempt);

visible treenode createtravelunloadtask(treenode dispatcher,treenode destination,treenode flowitem,double priority,int preempt);

visible treenode createunloadtask(treenode dispatcher,treenode destination,treenode flowitem,double priority,int preempt);

treenode createwaittask(treenode dispatcher,double state,double priority,int preempt);

visible double defaultdragconnection(treenode fromobject, treenode toobject, char characterpressed);

visible treenode derefcoupling(treenode coupling);

int destroymessageeventfilter(treenode object, double simtime, int code, void* data, treenode involved);

Variant destroymessageevents(treenode object, double simtime, treenode fromobj, double p1 DEFAULTPARAM(FLT_MAX), double p2 DEFAULTPARAM(FLT_MAX), double p3 DEFAULTPARAM(FLT_MAX));

visible double dispatchcoordinatedtasksequence(treenode tasksequence, treenode dispatcher DEFAULTNULL);

visible double dispatchtasksequence(treenode tasksequence, treenode dispatcher DEFAULTNULL);

visible double distancetotravel(treenode traveler, treenode destination);

visible double drawspheres(treenode object, treenode view);

Variant draw_spheres(treenode whose, treenode window, double color[4]);

visible int emptyfluidobject(treenode curobj);

visible int enablecode(treenode target, int mode DEFAULTZERO);

visible double endwaittask(treenode dispatcher);

treenode* enumerateteam(treenode team, int * returnnrofoperators, int recursivecall DEFAULTZERO);

visible int evaluatepullcriteria(treenode fr, treenode item, int port, int bypassflags);

fs_content_export Variant fglinfo(int op, treenode view);

treenode findnextclassvariable(treenode*curclass, treenode curvariable);

visible double freeoperators(treenode dispatcher, treenode involved);

Variant fsRotatexy(double matrix[4][4], double rz);

Variant fsScalexy(double matrix[4][4], double sx, double sy);

Variant fsTranslatexy(double matrix[4][4], double x, double y);

visible treenode getallocatedfromkey(treenode tasksequence, int key);

visible treenode getcoordinatedtasksequence(treenode dispatcher, int tsrank);

visible double getcurtask(treenode tasksequence);

visible treenode getdashboardcontrol(char* id, treenode startnode);

visible double getedgedist(treenode netnode, int edgenum);

visible double getedgespeedlimit(treenode netnode, int edgenum);

visible double geteventtime(char *eventname, double mode);

Variant geteventtime(string eventname, double mode);

visible treenode getiteminvolved(treenode item);

visible int getitemsendto(treenode item);

visible int getitemstate(treenode item);

visible double getitemvar(treenode item, int index);

visible treenode getnetnode(treenode object, int index);

visible treenode getnetnodespline(treenode netnode, int outport);

visible double getnetworkdistance(int fromCol, int toCol);

visible treenode getnextparametersobject(treenode curobj, string focus, int useclass, int forward);

visible int getnextnetnodeoutport(int fromnn, int tonn);

visible int getnextnetnode(int fromnn, int tonn);

treenode getnextpullitem();

visible double getnroftasks(treenode tasksequence);

visible unsigned int getpreempt(treenode tasksequence);

visible double getpriority(treenode tasksequence);

visible double getreportnum(treenode tableobj, int column, int rowsback);

visible treenode gettaskinvolved(treenode tasksequence, unsigned int rankrequested, unsigned int involvednum);

visible treenode gettasksequence(treenode dispatcher, double tsrank);

visible treenode gettasksequencequeue(treenode dispatcher);

visible double gettaskstate(treenode tasksequence, unsigned int rankrequested);

visible unsigned int gettasktype(treenode tasksequence, int rankrequested);

visible double gettaskvariable(treenode tasksequence, unsigned int rankrequested, unsigned int varnum);

visible treenode gettenavigator(treenode te);

visible treenode gettenetnode(treenode te);

visible double gettenetworkinfo(treenode te, treenode destobj, int info);

visible double gettotalnroftasks(treenode tasksequence);

visible double gettrackedvariable(char* name);

fs_content_export double gettrackedvariable(char* name, int valtype);

fs_content_export double gettrackedvariable(treenode trackedvar);

fs_content_export double gettrackedvariable(treenode trackedvar, int valtype);

visible treenode getutilizedobject(treenode team, treenode item, treenode station, int operatornr);

visible treenode getvirtualexit(treenode netnode, int index);

Variant groupaddmember(treenode child, treenode parent, char* groupname);

Variant groupdelete(treenode child, char* groupname);

treenode groupmember(treenode child, char* groupname, unsigned int membernum);

Variant groupnrofmembers(treenode child, char* groupname);

treenode groupparent(treenode child, char *groupname);

Variant groupremovemember(treenode child, char* groupname);

visible double holditem(treenode item);

visible int inititem(treenode item);

int initpull(treenode object, int outPort);

visible int insertallocatetask(treenode tasksequence, treenode dispatcher, double priority, double preempt, int noblock DEFAULTZERO);

visible int insertdeallocatetask(treenode tasksequence, int executerkey, int noblock DEFAULTZERO);

visible int insertmultiallocatetask(treenode tasksequence, int range);

visible int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1, treenode involved2,double var1 DEFAULTZERO, double var2  DEFAULTZERO, double var3 DEFAULTZERO, double var4 DEFAULTZERO);

fs_content_export int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1, int involved2,double var1 DEFAULTZERO, double var2 DEFAULTZERO, double var3 DEFAULTZERO, double var4 DEFAULTZERO);

fs_content_export int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1, treenode involved2,double var1 DEFAULTZERO, double var2 DEFAULTZERO, double var3 DEFAULTZERO, double var4 DEFAULTZERO);

fs_content_export int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1, int involved2,double var1 DEFAULTZERO, double var2 DEFAULTZERO, double var3 DEFAULTZERO, double var4 DEFAULTZERO);

fs_content_export int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, int involved1);

fs_content_export int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type, treenode involved1);

fs_content_export int insertproxytask(treenode tasksequence, unsigned int executerkey, unsigned int  type);

visible int insertsynctask(treenode tasksequence, int taskkey);

visible treenode inserttask(treenode tasksequence,  unsigned int  type, treenode involved1 DEFAULTNULL, treenode involved2 DEFAULTNULL , double var1 DEFAULTZERO , double var2 DEFAULTZERO , double var3 DEFAULTZERO , double var4 DEFAULTZERO);

visible int isedgeforward(treenode netnode, int outport);

Variant loadnodestate(treenode loadnode, treenode* nodes DEFAULTNULL);

Variant loadstatelayer(treenode layer);

visible treenode loaduserlibrary(string filename, treenode libraryview DEFAULTNULL, int reloadmedia DEFAULTZERO, int changeitemcurrent DEFAULTZERO, int autoinstall DEFAULTZERO);

double memberadd(treenode child, string parentname, int type);

double memberremove(treenode child, string parentname, int type);

double memberremoveall(string parentname, int type);

Variant modelupdatelayer(treenode layer, char* newversion, char *oldversion);

visible double movetasksequence(treenode tasksequence, treenode dispatcher);

visible treenode netnodefromrank(int netnoderank);

Variant opennodeedge(treenode curnode, char* edgename);

visible double opennodeedge(treenode curnode, int edgenum);

visible double optimizenetwork();

visible double pickoffsetx(treenode station, treenode item, treenode otherobject);

visible double pickoffsety(treenode station, treenode item, treenode otherobject);

visible double pickoffsetz(treenode station, treenode item, treenode otherobject);

visible double placeoffsetx(treenode station, treenode item, treenode otherobject);

visible double placeoffsety(treenode station, treenode item, treenode otherobject);

visible double placeoffsetz(treenode station, treenode item, treenode otherobject);

visible double profiletasksequence(treenode ts);

visible int pullitem(treenode fr, treenode item, int port, int bypassflags DEFAULTZERO);

visible void pushitem(treenode item, treenode toFR, int outPort, int inPort);

visible double rackdrawfilledcell(treenode rack, int bay, int level, double x, double y, double z, double sx, double sy, double sz, double red, double green, double blue, int glbeginend DEFAULTONE);

visible double rackdrawvirtualcontent(treenode rack,double bayfillperc, double levelfillperc, double itemdepth, double red, double green, double blue, double virtualonly DEFAULTONE);

visible double rackgetbaycontent(treenode rack, int bay);

visible double rackgetbayofitem(treenode rack, treenode item);

visible double rackgetbayloc(treenode rack,int bay);

visible double rackgetbaysize(treenode rack,int bay);

visible double rackgetcellcontent(treenode rack, int bay, int level);

visible double rackgetcellvar(treenode rack, int bay, int level, int varnum, treenode storedlabel DEFAULTNULL);

visible double rackgetitemcellrank(treenode rack, treenode item);

visible treenode rackgetitembybaylevel(treenode rack, int bay, int level, int itemrank DEFAULTONE);

visible double rackgetlevelofitem(treenode rack, treenode item);

visible double rackgetlevelloc(treenode rack,int bay, int level);

visible double rackgetlevelsize(treenode rack,int bay, int level);

visible double rackgetnrofbays(treenode rack);

visible double rackgetnroflevels(treenode rack, int bay DEFAULTONE);

visible double rackrecycleitem(treenode rack, treenode item, int binrank);

visible treenode rackrestoreitem(treenode rack, int binrank, int bay, int level, int position);

visible double racksetcellcontent(treenode rack, int bay, int level, int contentval);

visible double racksetcellvar(treenode rack, int bay, int level, int varnum, double value, treenode storedlabel DEFAULTNULL);

visible int rankfromnetnode(treenode netnode);

visible double reassignnetnode(treenode taskexecuter, treenode netnode);

visible double receiveitem(treenode station);

fs_content_export double receiveitem(treenode station, int port);

treenode recycledtasksequences();

treenode recycledtasks();

treenode recycledtravelrequests();

treenode recyclednetworkrequests();

visible double recycleitem(treenode item, int binrank);

visible double recyclenode(treenode node, treenode containerbranch);

visible double redirectnetworktraveler(treenode traveler, treenode newdest);

visible double releaseitem(treenode item);

fs_content_export double releaseitem(treenode item, int port);

Variant releaseoperators(treenode dispatcher, treenode involved);

visible double reordertasks(treenode involved);

visible double requestdecision(treenode object);

visible double requestoperators(treenode dispatcher, treenode station, treenode involved, int nrofops, double priority, int preempt);

visible double rerankbesttask(treenode involved);

treenode restorenode(treenode containerbranch, treenode destcontainer);

fs_content_export double resumeobject(treenode involved, int id, int stateprofile);

fs_content_export double resumeobject(treenode involved);

visible double resumeobject(treenode involved, int id);

visible double resumetransportsin(treenode object, int rank DEFAULTZERO);

visible double resumetransportsout(treenode object, int rank DEFAULTZERO);

Variant savenodestate(treenode savenode, int size DEFAULTZERO, int nrofpointers DEFAULTONE, treenode* nodes DEFAULTNULL);

Variant savestatelayer(treenode layer);

visible double savestoppedtransportin(treenode object, treenode transporter);

visible double savestoppedtransportout(treenode object, treenode transporter);

visible double senddelayedmessage(treenode toobject, double delaytime, treenode fromobject, double par1, double par2 DEFAULTZERO, double par3 DEFAULTZERO);

Variant senddelayedmessage(treenode toobject, double delaytime, treenode fromobject);

visible double setcollisioncheck(treenode collisionobj, double val,double interval DEFAULTZERO);

visible double seteventtime(char *eventname, double timeval, double mode, double newevent);

Variant seteventtime(string eventname, double timeval, double mode, double newevent);

visible double setiteminvolved(treenode item, treenode involved);

visible double setitemsendto(treenode item, int sendto);

visible double setitemvar(treenode item, int index, double val);

visible double setpreempt(treenode tasksequence, unsigned int newpreempt);

visible double setpriority(treenode tasksequence, double newpriority);

visible double setresetposition(treenode obj);

fs_content_export double settrackedvariable(const Variant&  name, double value, double rate DEFAULTZERO);

visible double settrackedvariable(const char* name, double value);

fs_content_export double settrackedvariable(const char* name, double value, double rate);

fs_content_export double settrackedvariable(treenode trackedvar, double value);

fs_content_export double settrackedvariable(treenode trackedvar, double value, double rate);

fs_content_export double stopobject(treenode involved, int state, int id, double priority, int stateprofile);

fs_content_export double stopobject(treenode involved, int state);

visible double stopobject(treenode involved, int state, int id, double priority);

Variant syncmember(treenode child, char * groupname);

Variant syncmemberauto(treenode child, char * groupname);

Variant syncquantity(treenode child, char* groupname);

visible double trackdefaultsoncreate(treenode item);

visible double trackdefaultsondestroy(treenode item);

visible double trafficcontrolinfo(treenode tc, int info, double _a, double _b);

visible double transportincomplete(treenode object, treenode item, int portnumber DEFAULTZERO, treenode transporter DEFAULTNULL);

visible double transportoutcomplete(treenode object, treenode item, int portnumber DEFAULTZERO, treenode transporter DEFAULTNULL);

visible double updatelocations(treenode object);

visible void updatestates();

visible void updatetoolsmenu();

Variant updateconveyorsectioninfo(treenode conveyor);


// FlexSimEventHandler
class FlexSimEventHandler : public ObjectDataType
{
public:


// c++ member functions

fs_content_export virtual double onReceive(treenode item, int port);

fs_content_export virtual double onSend(treenode item, int port);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export virtual double onDestroy(treenode view);

fs_content_export virtual double onDraw(treenode view);

fs_content_export virtual double onDrawPlanar(treenode view);

fs_content_export virtual double onPreDraw(treenode view);

fs_content_export virtual double onOutOpen(int port);

fs_content_export virtual double onInOpen(int port);

fs_content_export virtual double onClick(treenode view, int code);

fs_content_export virtual Variant onMessage(treenode fromobject, const Variant& par1, const Variant& par2, const Variant& par3);

fs_content_export virtual double onReset();

fs_content_export virtual double onStartSimulation();

fs_content_export virtual double onDrag(treenode view);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onUndo(bool isUndo, treenode undoRecord);

fs_content_export virtual void stop(int stopstate, int id, double priority DEFAULTZERO, int stateprofile DEFAULTZERO);

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume(int id, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export virtual void onDragConnection(ObjectDataType* fromObj, ObjectDataType* toObj, char charPressed);

fs_content_export virtual double getPickOffset(treenode involvedobj, treenode toobject, double* returnarray);

fs_content_export virtual double getPlaceOffset(treenode involvedobj, treenode fromobject,  double* returnarray);

fs_content_export virtual double updateLocations();

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual double rotateAroundAxis(double angle, double x, double y);

fs_content_export virtual double flipAroundAxis(const Vec2& point1, const Vec2& point2);

fs_content_export virtual double copyVariables(treenode fromObj);

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export virtual double onTransportOutNotify(treenode item, int port);

fs_content_export virtual double onTransportOutComplete(treenode item, int portnumber, treenode transporter DEFAULTNULL);

fs_content_export virtual double onTransportInComplete(treenode item, int portnumber, treenode transporter DEFAULTNULL);

fs_content_export treenode getEventInfoObject(const char* eventName);

fs_content_export static treenode s_getEventInfoObject(treenode holder, const char* eventTitle);

fs_content_export double resetLabels();

fs_content_export virtual void bindEvents();

fs_content_export virtual void bindStatistics();

fs_content_export void bindStandardStatistics(bool force);

fs_content_export treenode stateProfileResolver(const Variant& p1);

fs_content_export int enumerateLabels(treenode destNode, const Variant& p1, const Variant& p2);

fs_content_export treenode resolveLabel(const Variant& p1);

fs_content_export virtual double usePlaceOffsetForTravel(TaskExecuter* te);


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FlexSimObject
class FlexSimObject : public FlexSimEventHandler
{
public:


// c++ member functions

fs_content_export  FlexSimObject();

fs_content_export virtual double onDestroy(treenode view);

fs_content_export virtual double onDraw(treenode view);

fs_content_export virtual double onPreDraw(treenode view);

fs_content_export virtual double onKeyedClick(treenode view, int code, char key);

fs_content_export virtual Variant onMessage(treenode fromobject, const Variant& par1, const Variant& par2, const Variant& par3);

fs_content_export virtual double onReset();

fs_content_export virtual void stop(int stopstate, int id, double priority DEFAULTZERO, int stateprofile DEFAULTZERO);

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void onInitialStop();

fs_content_export virtual void resume(int id, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export virtual void onFinalResume();

fs_content_export double resetVariables();

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export double drawStopped(double red, double blue, double green);

fs_content_export virtual double getPickOffset(treenode involvedobj, treenode toobject, double* returnarray);

fs_content_export virtual double getPlaceOffset(treenode involvedobj, treenode fromobject,  double* returnarray);

fs_content_export virtual double updateLocations();

fs_content_export double execDelayedMessage(treenode involved, void * datastring);

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual double saveState();

fs_content_export virtual double loadState();

fs_content_export virtual double updateVersion(char* newversion, char* oldversion);

fs_content_export virtual int checkCollisions();

fs_content_export static double catchError(string stra, string strb);

fs_content_export double moveToResetPosition();

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export static char* displayMessageData(int code, char* edata);

fs_content_export virtual void bindEvents();

fs_content_export void bindGeneralEvents();

fs_content_export void bindPickPlaceOffsetEvents(int pick, int place);

fs_content_export void bindStopResumeEvents();

TreeNode* node_v_timetables;
#define v_timetables node_v_timetables->safedatafloat()[0]
TreeNode* node_v_networknodes;
#define v_networknodes node_v_networknodes->safedatafloat()[0]
TreeNode* node_v_timeoflaststop;
#define v_timeoflaststop node_v_timeoflaststop->safedatafloat()[0]
TreeNode* node_v_nrofstops;
#define v_nrofstops node_v_nrofstops->safedatafloat()[0]
TreeNode* node_v_statebeforestop;
#define v_statebeforestop node_v_statebeforestop->safedatafloat()[0]
TreeNode* node_v_collisionspheres;
#define v_collisionspheres node_v_collisionspheres->safedatafloat()[0]
TreeNode* node_v_collisionobjects;
#define v_collisionobjects node_v_collisionobjects->safedatafloat()[0]
TreeNode* node_v_savedstate;
#define v_savedstate node_v_savedstate->safedatafloat()[0]
TreeNode* node_v_resetposition;
#define v_resetposition node_v_resetposition->safedatafloat()[0]
TreeNode* node_v_doanimations;
#define v_doanimations node_v_doanimations->safedatafloat()[0]

// c++ attributes
double* protectLocs;

treenode pickOffset = nullptr;

treenode placeOffset = nullptr;

treenode onStop = nullptr;

treenode onResume = nullptr;

treenode onDrawTrigger = nullptr;

treenode onPreDrawTrigger = nullptr;

treenode onResetTrigger = nullptr;

treenode onMessageTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FixedResource
class FixedResource : public FlexSimObject
{
public:


//ClassIncludeHeaderStart
fs_content_export virtual int getPullFromPort();
fs_content_export virtual bool getPullRequirement(treenode item, int port);
fs_content_export virtual treenode getTransportDispatcher(treenode flowItem, int port, treenode toObject);
fs_content_export virtual bool isPulling();
//ClassIncludeHeaderEnd

// c++ member functions

fs_content_export double onOutOpen(int port);

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onSend(treenode item, int port);

fs_content_export double onReset();

fs_content_export virtual double releaseItem(treenode item);

fs_content_export virtual double releaseItem(treenode item, int port);

fs_content_export inline int releaseItemToPort(treenode item, int porttoopen);

fs_content_export virtual double outOpenEvent(FixedResource* otherobject, int search, int port, int otherport);

fs_content_export virtual double receiveItem();

fs_content_export virtual double receiveItem(int port);

fs_content_export inline int receiveItemFromPort(int porttoopen);

fs_content_export virtual double inOpenEvent(FixedResource* otherobject, int search, double port );

fs_content_export virtual double pushItem(treenode item, FixedResource* otherobject, int port, int otherport);

fs_content_export virtual double pullItem(treenode item, int port, int bypassflags);

fs_content_export virtual double evaluatePullCriteria(treenode item, int port, int bypassflags);

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export virtual double onTransportOutNotify(treenode item, int port);

fs_content_export virtual double onTransportOutComplete(treenode item, int portnumber, treenode transporter DEFAULTNULL);

fs_content_export virtual double onTransportInComplete(treenode item, int portnumber, treenode transporter DEFAULTNULL);

fs_content_export virtual void onTransportInFailed(treenode item, int portnumber);

fs_content_export double resetVariables();

fs_content_export static inline FRItemInfo* getItemInfo(treenode flowitem);

fs_content_export int initItem(treenode flowitem);

fs_content_export static int setItemVar(treenode flowitem, int varnum, double val);

fs_content_export static double getItemVar(treenode flowitem, int varnum);

fs_content_export static int setItemInvolved(treenode flowitem, treenode involved);

fs_content_export static treenode getItemInvolved(treenode flowitem);

fs_content_export static FixedResource* getItemCurFR(treenode flowitem);

fs_content_export double holdItem(treenode flowitem);

fs_content_export static inline double getItemState(treenode flowitem);

fs_content_export static double setItemState(treenode flowitem, int state);

fs_content_export static int getItemSendTo(treenode flowitem);

fs_content_export static int setItemSendTo(treenode flowitem, int sendto);

fs_content_export double cleanItemData(treenode item);

fs_content_export double closeInvolvedPorts(treenode item);

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export treenode createMoveTaskSequence(treenode dispatcher, treenode involved, treenode origin, treenode destination, double outportnumber, double inportnumber);

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export double saveState();

fs_content_export double loadState();

fs_content_export double resumeTransportsOut(int trank DEFAULTZERO);

fs_content_export double resumeTransportsIn(int trank DEFAULTZERO);

fs_content_export double saveStoppedTransportOut(treenode transporter);

fs_content_export double saveStoppedTransportIn(treenode transporter);

fs_content_export virtual PullIterator& initPull(int outPort);

fs_content_export double checkReceiveItem(int maxContent);

fs_content_export virtual void bindEvents();

fs_content_export void bindEntryExitEvents(int entry, int exit);

fs_content_export void bindOutputEvents();

fs_content_export void bindInputEvents();

TreeNode* node_v_nrreleased;
#define v_nrreleased node_v_nrreleased->safedatafloat()[0]
TreeNode* node_v_pull;
#define v_pull node_v_pull->safedatafloat()[0]
TreeNode* node_v_sendtoport;
TreeNode* node_v_receivefromport;
TreeNode* node_v_pullrequirement;
TreeNode* node_v_usetransport;
#define v_usetransport node_v_usetransport->safedatafloat()[0]
TreeNode* node_v_transportpriority;
#define v_transportpriority node_v_transportpriority->safedatafloat()[0]
TreeNode* node_v_preempttransport;
#define v_preempttransport node_v_preempttransport->safedatafloat()[0]
TreeNode* node_v_transportdispatcher;
TreeNode* node_v_nroftransportsout;
#define v_nroftransportsout node_v_nroftransportsout->safedatafloat()[0]
TreeNode* node_v_nroftransportsin;
#define v_nroftransportsin node_v_nroftransportsin->safedatafloat()[0]
TreeNode* node_v_outwaitinfo;
#define v_outwaitinfo node_v_outwaitinfo->safedatafloat()[0]
TreeNode* node_v_sendtocontinuous;
#define v_sendtocontinuous node_v_sendtocontinuous->safedatafloat()[0]
TreeNode* node_v_pullcontinuous;
#define v_pullcontinuous node_v_pullcontinuous->safedatafloat()[0]
TreeNode* node_v_lifo;
#define v_lifo node_v_lifo->safedatafloat()[0]

// c++ attributes
double inPort;

treenode lastReleased;

treenode curTransporter = nullptr;

int pullItemCalled;

bool blockRecursiveReceive = false;

treenode onEntryTrigger = nullptr;

treenode onExitTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Navigator
class Navigator : public FlexSimObject
{
public:


// c++ member functions

fs_content_export double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export double onReset();

fs_content_export virtual void onMemberDestroyed(TaskExecuter* te);

fs_content_export virtual double navigateToObject(treenode traveler, treenode destination, double endSpeed);

fs_content_export virtual double navigateToLoc(treenode traveler, double* destLoc, double endSpeed);

fs_content_export double resetVariables();

fs_content_export treenode createTravelMemberNode(TaskExecuter* involvedtaskexecuter, FlexSimObject* destination, double totaldistance, double extravars);

fs_content_export virtual double abortTravel(treenode traveler, treenode newts);

fs_content_export virtual double updateLocations();

fs_content_export virtual double updateLocations(TaskExecuter* te);

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual double queryDistance(TaskExecuter* taskexecuter, FlexSimObject* destination);

fs_content_export double saveState();

fs_content_export double loadState();

fs_content_export static float saveTravelRequestState(treenode reqnode);

fs_content_export static float loadTravelRequestState(treenode reqnode);

fs_content_export virtual treenode addMember(TaskExecuter* te);

fs_content_export virtual treenode addCopiedMember(TaskExecuter* te, TaskExecuter* original);

fs_content_export virtual void bindEvents();

fs_content_export virtual void bindTEEvents(TaskExecuter* te);

fs_content_export virtual void bindTEStatistics(TaskExecuter* te);

fs_content_export virtual double getTotalTravelDistance(TaskExecuter* te);

TreeNode* node_v_travelmembers;
#define v_travelmembers node_v_travelmembers->safedatafloat()[0]
TreeNode* node_v_activetravelmembers;
#define v_activetravelmembers node_v_activetravelmembers->safedatafloat()[0]
TreeNode* node_v_lastupdatetime;
#define v_lastupdatetime node_v_lastupdatetime->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// GlobalTable
class GlobalTable : public ObjectDataType
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual void bindEvents();

TreeNode* node_v_data;
TreeNode* node_v_resettrigger;
TreeNode* node_v_width;
#define v_width node_v_width->safedatafloat()[0]
TreeNode* node_v_height;
#define v_height node_v_height->safedatafloat()[0]
TreeNode* node_v_cellwidth;
#define v_cellwidth node_v_cellwidth->safedatafloat()[0]
TreeNode* node_v_cellheight;
#define v_cellheight node_v_cellheight->safedatafloat()[0]
TreeNode* node_v_bundleIndexFields;
#define v_bundleIndexFields node_v_bundleIndexFields->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// PerformanceMeasureTable
class PerformanceMeasureTable : public FlexSimEventHandler
{
public:


//ClassIncludeHeaderStart
treenode performanceMeasures;

virtual void bindVariables() override;
//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// UserEvent
class UserEvent : public ObjectDataType
{
public:


// c++ member functions

fs_content_export double updateVersion(char* newversion, char* oldversion);

fs_content_export virtual void bindEvents();

TreeNode* node_v_time;
#define v_time node_v_time->safedatafloat()[0]
TreeNode* node_v_repeat;
#define v_repeat node_v_repeat->safedatafloat()[0]
TreeNode* node_v_event;
TreeNode* node_v_reset;
#define v_reset node_v_reset->safedatafloat()[0]
TreeNode* node_v_firsttime;
#define v_firsttime node_v_firsttime->safedatafloat()[0]
TreeNode* node_v_enabled;
#define v_enabled node_v_enabled->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// MTBFMTTR
class MTBFMTTR : public ObjectDataType
{
public:


// c++ member functions

fs_content_export double updateVersion(char* newversion, char* oldversion);

fs_content_export virtual double onReset();

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual void bindEvents();

fs_content_export virtual treenode getEventInfoObject(const char* eventName);

fs_content_export virtual double CheckBringDown(treenode coupling, treenode profile, int toState, int fromState);

TreeNode* node_v_members;
#define v_members node_v_members->safedatafloat()[0]
TreeNode* node_v_mtbf;
TreeNode* node_v_mttr;
TreeNode* node_v_state;
#define v_state node_v_state->safedatafloat()[0]
TreeNode* node_v_firstmtbf;
TreeNode* node_v_applyindividuals;
#define v_applyindividuals node_v_applyindividuals->safedatafloat()[0]
TreeNode* node_v_downtrigger;
TreeNode* node_v_uptrigger;
TreeNode* node_v_downfunction;
TreeNode* node_v_upfunction;
TreeNode* node_v_mtbfstates;
#define v_mtbfstates node_v_mtbfstates->safedatafloat()[0]
TreeNode* node_v_enabled;
#define v_enabled node_v_enabled->safedatafloat()[0]
TreeNode* node_v_downBehavior;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// TimeTable
class TimeTable : public ObjectDataType
{
public:


// c++ member functions

fs_content_export virtual void bindEvents();

fs_content_export virtual treenode getEventInfoObject(const char* eventName);

TreeNode* node_v_table;
#define v_table node_v_table->safedatafloat()[0]
TreeNode* node_v_members;
#define v_members node_v_members->safedatafloat()[0]
TreeNode* node_v_repeattime;
#define v_repeattime node_v_repeattime->safedatafloat()[0]
TreeNode* node_v_rows;
#define v_rows node_v_rows->safedatafloat()[0]
TreeNode* node_v_modelstarttime;
#define v_modelstarttime node_v_modelstarttime->safedatafloat()[0]
TreeNode* node_v_repeattype;
#define v_repeattype node_v_repeattype->safedatafloat()[0]
TreeNode* node_v_calendarstarttime;
TreeNode* node_v_snapto;
#define v_snapto node_v_snapto->safedatafloat()[0]
TreeNode* node_v_downtrigger;
TreeNode* node_v_uptrigger;
TreeNode* node_v_downfunction;
TreeNode* node_v_upfunction;
TreeNode* node_v_enabled;
#define v_enabled node_v_enabled->safedatafloat()[0]
TreeNode* node_v_pickColor;
#define v_pickColor node_v_pickColor->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// DownBehavior
class DownBehavior : public ObjectDataType
{
public:


// c++ member functions

fs_content_export virtual void bindEvents();

fs_content_export virtual treenode getEventInfoObject(const char* eventName);

TreeNode* node_v_downtrigger;
TreeNode* node_v_uptrigger;
TreeNode* node_v_downfunction;
TreeNode* node_v_upfunction;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// PropertyTable
class PropertyTable : public ObjectDataType
{
public:


//ClassIncludeHeaderStart
virtual void bindVariables() override;
virtual void bind() override;
void onReset();
std::string resolveQueryFromTree(TreeNode* tree, const char* updateFromTable = nullptr);
Variant resolveQueryFromTree(FLEXSIMINTERFACE) { return resolveQueryFromTree(param(1), param(2).c_str()); }
TreeNode* resolveTreeFromQuery(const char* query);
void updateTable();
Variant updateTable(FLEXSIMINTERFACE) { updateTable(); return Variant();}
static string getExprDescription(treenode expr);
Variant getExprDescription(FLEXSIMINTERFACE) { return getExprDescription((treenode)param(1)); }
Variant getProperty(const char* expr);
Variant getProperty(FLEXSIMINTERFACE) { return getProperty(param(1).c_str()); }


TreeNode* queryTree;
double manualQuery = 0;
ByteBlock queryStr;
TreeNode* query;
TreeNode* dataSource;
TreeNode* table;

TreeNode* copyToTable;
double copyOnReset;
TreeNode* updateFromTable;
ByteBlock updateQuery;
double updateOnReset;

void runCopyTo(const char* toTableName = nullptr);
Variant runCopyTo(FLEXSIMINTERFACE) { runCopyTo(param(1).c_str()); return Variant();}

TreeNode* resolveUpdateFromTable();
std::string generateUpdateQuery(const char* fromTableName = nullptr, bool save = true);
Variant generateUpdateQuery(FLEXSIMINTERFACE) { return generateUpdateQuery(param(1).c_str(), (bool)(int)param(2)).c_str(); }
void runUpdateQuery(const char* query = nullptr);
Variant runUpdateQuery(FLEXSIMINTERFACE) { runUpdateQuery(param(1).c_str()); return Variant(); }

class DataSource : public Table::TableDataSource 
{
	public:
	PropertyTable* propTable;
	DataSource(PropertyTable* propTable) : propTable(propTable) { this->root = propTable->table; }

	virtual void addCol(int col, int datatype) override { throw "Table.addCol() called on property table is not allowed"; }
	virtual void addRow(int row, int datatype) override { throw "Table.addRow() called on property table is not allowed"; }
	virtual void clear(int recursive = 0) override { throw "Table.clear() called on property table is not allowed"; }
	virtual void deleteCol(int col) override { throw "Table.deleteCol() called on property table is not allowed"; }
	virtual void deleteRow(int row) override { throw "Table.deleteRow() called on property table is not allowed"; }
	virtual void moveCol(int fromCol, int toCol) override { throw "Table.moveCol() called on property table is not allowed"; }
	virtual void moveRow(int fromRow, int toRow) override { throw "Table.moveRow() called on property table is not allowed"; }
	virtual void setColHeader(int colNum, const char* name) override { throw "Table.setColHeader() called on property table is not allowed"; }
	virtual void setRowHeader(int rowNum, const char* name) override { throw "Table.setRowHeader() called on property table is not allowed"; }
	virtual void setSize(int rows, int cols, int datatype, int overwrite) override { throw "Table.setSize() called on property table is not allowed"; }
	virtual void sort(const Variant& cols, const Variant& ascDesc) override { throw "Table.sort() called on property table is not allowed"; }
	virtual void swapCols(int col, int col2) override { throw "Table.swapCols() called on property table is not allowed"; }
	virtual void swapRows(int row, int row2) override { throw "Table.swapRows() called on property table is not allowed"; }

	virtual Variant getValue(int row, int col) override;
	virtual void setValue(int row, int col, const Variant& val) override;
};

DataSource* getTableDataSource();
Variant getTableDataSource(FLEXSIMINTERFACE) { return Variant((void*)getTableDataSource()); }

//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// NetworkNavigator
class NetworkNavigator : public Navigator
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export virtual double navigateToObject(treenode traveler, treenode destination, double endspeed);

fs_content_export virtual double navigateToLoc(treenode traveler, double* destLoc, double endSpeed);

fs_content_export double finishTravel(treenode reqnode, int blocking DEFAULTZERO);

fs_content_export double resetVariables();

fs_content_export double generateDistanceTable();

fs_content_export virtual treenode addMember(TaskExecuter* te);

fs_content_export virtual NetworkTravelMember* addMember(TaskExecuter* taskexecuter, NetworkNode* networknode);

fs_content_export virtual treenode addCopiedMember(TaskExecuter* te, TaskExecuter* original);

fs_content_export int getNextOutPort(NetworkRequest* netreq);

fs_content_export int getNextOutPort(NetworkNode* from, NetworkNode* to);

fs_content_export double getNextOutPort(int fromRow, int toCol);

fs_content_export double getDistRemaining(NetworkNode * netnode, int destcol);

fs_content_export double toggleAllShowModes(double newmode, int selectedonly);

fs_content_export virtual double abortTravel(treenode taskexecuternode, treenode newts);

fs_content_export virtual double updateLocations();

fs_content_export double reassignNetNode(treenode membernode, NetworkNode* tonetnode, int onreset DEFAULTZERO);

fs_content_export double queryDistance(TaskExecuter* te, FlexSimObject* destobj);

fs_content_export double queryDistanceEx(TaskExecuter* te, FlexSimObject* destobj, NetworkNode* originnetnode, NetworkNode** bestorigin DEFAULTNULL, NetworkNode** bestdestnode DEFAULTNULL, int * bestoriginrow DEFAULTNULL, int * bestdestcol DEFAULTNULL, double* bestdist DEFAULTNULL);

fs_content_export double queryDistance(NetworkNode* from, NetworkNode* to);

fs_content_export double queryDistance(int fromCol, int toCol);

fs_content_export double getTravelerInfo(TaskExecuter* te, FlexSimObject * destobj, int info);

fs_content_export virtual double updateVersion(char* newversion, char* oldversion);

fs_content_export double redirectTraveler(treenode traveler, treenode newdest);

fs_content_export virtual double saveState();

fs_content_export virtual double loadState();

fs_content_export static float saveNetworkRequestState(treenode reqnode);

fs_content_export static float loadNetworkRequestState(treenode reqnode);

fs_content_export double validateTravelMemberStructure(treenode curtmemnode);

fs_content_export static treenode getTENetNode(treenode membernode);

fs_content_export static NetworkNavigator* getInstance();

fs_content_export virtual void onMemberDestroyed(TaskExecuter* te);

fs_content_export virtual double getTotalTravelDistance(TaskExecuter* te);

TreeNode* node_v_nodemembers;
#define v_nodemembers node_v_nodemembers->safedatafloat()[0]
TreeNode* node_v_nrtofirstnode;
#define v_nrtofirstnode node_v_nrtofirstnode->safedatafloat()[0]
TreeNode* node_v_modified;
#define v_modified node_v_modified->safedatafloat()[0]
TreeNode* node_v_nodesize;
#define v_nodesize node_v_nodesize->safedatafloat()[0]
TreeNode* node_v_arrowsize;
#define v_arrowsize node_v_arrowsize->safedatafloat()[0]
TreeNode* node_v_connecting;
#define v_connecting node_v_connecting->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// VideoRecorder
class VideoRecorder : public ObjectDataType
{
public:


// c++ member functions

fs_content_export double getMetric(int metric, string sout, treenode seq, string slay);

fs_content_export double getMetric(int metric, string sout, string sseq, string slay);

fs_content_export double getMetric(int metric, string sout);

fs_content_export double getMetric(int metric);

fs_content_export treenode resolveSequence(treenode seqSubNode);

TreeNode* node_v_outputs;
#define v_outputs node_v_outputs->safedatafloat()[0]
TreeNode* node_v_sequences;
#define v_sequences node_v_sequences->safedatafloat()[0]
TreeNode* node_v_jobscallback;
TreeNode* node_v_preview;
#define v_preview node_v_preview->safedatafloat()[0]
TreeNode* node_v_active;
#define v_active node_v_active->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// PreLoad
class PreLoad : public ObjectDataType
{
public:


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// ExcelAuto
class ExcelAuto : public ObjectDataType
{
public:


// c++ member functions

fs_content_export double doImport();

fs_content_export double doExport();

fs_content_export double reimport();

fs_content_export double importTables(int onreset);

fs_content_export double updateProgress(string status, double value);

fs_content_export double updateProgressExport(string status, double value);

fs_content_export double excelFileChanged(treenode file);

fs_content_export double getAndOpenWorkBook();

fs_content_export double openWorkBook();

fs_content_export double getRowHeaders(int startrow, int rows, int col);

fs_content_export double getColHeaders(int startcol, int cols, int row);

fs_content_export int getBundleColHeaders(int startcol, int cols, int row);

fs_content_export double importData(int startrow, int startcol, int rows, int cols, int curtable, double percentdone, double percentmain);

fs_content_export double importBundleData(int startrow, int startcol, int rows, int cols, int curtable, double percentdone, double percentmain);

fs_content_export double exportData(int startrow, int startcol, int headers, int curtable, double percentdone, double percentmain);

fs_content_export int isNumber(string str);

TreeNode* node_v_needtocompile;
#define v_needtocompile node_v_needtocompile->safedatafloat()[0]
TreeNode* node_v_excellocation;
TreeNode* node_v_curworkbook;
TreeNode* node_v_importexcelfiles;
#define v_importexcelfiles node_v_importexcelfiles->safedatafloat()[0]
TreeNode* node_v_importtable;
#define v_importtable node_v_importtable->safedatafloat()[0]
TreeNode* node_v_exporttable;
#define v_exporttable node_v_exporttable->safedatafloat()[0]
TreeNode* node_v_sheet;
TreeNode* node_v_tname;
TreeNode* node_v_headerval;
#define v_headerval node_v_headerval->safedatafloat()[0]
TreeNode* node_v_datadistinctval;
#define v_datadistinctval node_v_datadistinctval->safedatafloat()[0]
TreeNode* node_v_usepostimportcode;
#define v_usepostimportcode node_v_usepostimportcode->safedatafloat()[0]
TreeNode* node_v_OnImport;
TreeNode* node_v_CustomImport;
TreeNode* node_v_CustomExport;
TreeNode* node_v_desccustomimport;
TreeNode* node_v_desccustomexport;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Recorder
class Recorder : public FlexSimObject
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export double onDraw(treenode view);

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double resetVariables();

fs_content_export treenode findNode(treenode startnode, char *name);

fs_content_export double generateOutput();

fs_content_export double drawHisto(treenode view);

fs_content_export double drawBar(treenode view);

fs_content_export double drawXYGraph(treenode view);

fs_content_export double drawPieGraph(treenode view);

fs_content_export double drawUserGraph(treenode view);

fs_content_export double drawBarChart(treenode view, void * graphdata,int nrofinstances,double xmin, double xmax, double ymin, double ymax, char * charttitle);

fs_content_export double drawLineGraph(treenode view, void * graphdata,int nrofinstances,double xmin, double xmax, double ymin, double ymax, char * charttitle);

fs_content_export double drawPieChart(treenode view, void * graphdata,int nrofinstances,double xmin, double xmax, double ymin, double ymax, char * charttitle);

fs_content_export virtual double copyVariables(treenode otherobject);

TreeNode* node_v_timedriven;
#define v_timedriven node_v_timedriven->safedatafloat()[0]
TreeNode* node_v_timebetweenchecks;
#define v_timebetweenchecks node_v_timebetweenchecks->safedatafloat()[0]
TreeNode* node_v_outputtype;
#define v_outputtype node_v_outputtype->safedatafloat()[0]
TreeNode* node_v_datatype;
#define v_datatype node_v_datatype->safedatafloat()[0]
TreeNode* node_v_standardtype;
#define v_standardtype node_v_standardtype->safedatafloat()[0]
TreeNode* node_v_graphtype;
#define v_graphtype node_v_graphtype->safedatafloat()[0]
TreeNode* node_v_weighttype;
#define v_weighttype node_v_weighttype->safedatafloat()[0]
TreeNode* node_v_objectrank;
#define v_objectrank node_v_objectrank->safedatafloat()[0]
TreeNode* node_v_drawbackground;
#define v_drawbackground node_v_drawbackground->safedatafloat()[0]
TreeNode* node_v_histomin;
#define v_histomin node_v_histomin->safedatafloat()[0]
TreeNode* node_v_histomax;
#define v_histomax node_v_histomax->safedatafloat()[0]
TreeNode* node_v_histobuckets;
#define v_histobuckets node_v_histobuckets->safedatafloat()[0]
TreeNode* node_v_numpoints;
#define v_numpoints node_v_numpoints->safedatafloat()[0]
TreeNode* node_v_autodomain;
#define v_autodomain node_v_autodomain->safedatafloat()[0]
TreeNode* node_v_autorange;
#define v_autorange node_v_autorange->safedatafloat()[0]
TreeNode* node_v_xmin;
#define v_xmin node_v_xmin->safedatafloat()[0]
TreeNode* node_v_xmax;
#define v_xmax node_v_xmax->safedatafloat()[0]
TreeNode* node_v_ymin;
#define v_ymin node_v_ymin->safedatafloat()[0]
TreeNode* node_v_ymax;
#define v_ymax node_v_ymax->safedatafloat()[0]
TreeNode* node_v_tablexval;
TreeNode* node_v_tableyval;
TreeNode* node_v_linecolor;
#define v_linecolor node_v_linecolor->safedatafloat()[0]
TreeNode* node_v_graphtitle;
TreeNode* node_v_draw3dgraph;
#define v_draw3dgraph node_v_draw3dgraph->safedatafloat()[0]
TreeNode* node_v_datapointer;
#define v_datapointer node_v_datapointer->safedatafloat()[0]
TreeNode* node_v_numwatches;
#define v_numwatches node_v_numwatches->safedatafloat()[0]
TreeNode* node_v_graphdata;
#define v_graphdata node_v_graphdata->safedatafloat()[0]
TreeNode* node_v_watchtable;
#define v_watchtable node_v_watchtable->safedatafloat()[0]
TreeNode* node_v_bucketnames;
#define v_bucketnames node_v_bucketnames->safedatafloat()[0]
TreeNode* node_v_tablerowtemplate;
#define v_tablerowtemplate node_v_tablerowtemplate->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// VisualTool
class VisualTool : public FlexSimObject
{
public:


// c++ member functions

fs_content_export  VisualTool();

fs_content_export double onDraw(treenode view);

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onDestroy(treenode view);

fs_content_export double onPreDraw(treenode view);

fs_content_export double onReset();

fs_content_export double buildMesh();

fs_content_export double drawSnapMesh(treenode view);

fs_content_export double drawPlane(treenode view);

fs_content_export double drawCube();

fs_content_export double drawColumn();

fs_content_export double drawSphere();

fs_content_export double drawString(treenode view);

fs_content_export double drawFloor(treenode view);

fs_content_export double arrangeObject(double posx, double posy, double posz, double rotx, double roty, double rotz, double size);

fs_content_export double addText(treenode newtextobj);

fs_content_export double removeText(treenode textobj);

fs_content_export double containerEntry(treenode item);

fs_content_export double containerExit(treenode item);

fs_content_export double regenStayTimeHisto();

fs_content_export double resetVariables();

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export unsigned int getClassType();

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export double doConnectIndirection(treenode otherobject, char characterpressed, int tome);

fs_content_export virtual void bindEvents();

TreeNode* node_v_shapetypes;
#define v_shapetypes node_v_shapetypes->safedatafloat()[0]
TreeNode* node_v_divisions;
#define v_divisions node_v_divisions->safedatafloat()[0]
TreeNode* node_v_repeatx;
#define v_repeatx node_v_repeatx->safedatafloat()[0]
TreeNode* node_v_repeaty;
#define v_repeaty node_v_repeaty->safedatafloat()[0]
TreeNode* node_v_nroftexts;
#define v_nroftexts node_v_nroftexts->safedatafloat()[0]
TreeNode* node_v_settextloc;
#define v_settextloc node_v_settextloc->safedatafloat()[0]
TreeNode* node_v_containercontent;
#define v_containercontent node_v_containercontent->safedatafloat()[0]
TreeNode* node_v_objectref;
TreeNode* node_v_textcode;
TreeNode* node_v_textnode;
TreeNode* node_v_textsize;
#define v_textsize node_v_textsize->safedatafloat()[0]
TreeNode* node_v_viewmagnification;
#define v_viewmagnification node_v_viewmagnification->safedatafloat()[0]
TreeNode* node_v_viewdistance;
#define v_viewdistance node_v_viewdistance->safedatafloat()[0]
TreeNode* node_v_textthickness;
#define v_textthickness node_v_textthickness->safedatafloat()[0]
TreeNode* node_v_billboardtype;
#define v_billboardtype node_v_billboardtype->safedatafloat()[0]
TreeNode* node_v_showcontents;
#define v_showcontents node_v_showcontents->safedatafloat()[0]
TreeNode* node_v_connectinputs;
TreeNode* node_v_connectoutputs;
TreeNode* node_v_snapPoints;
#define v_snapPoints node_v_snapPoints->safedatafloat()[0]
TreeNode* node_v_snapDrawMode;
#define v_snapDrawMode node_v_snapDrawMode->safedatafloat()[0]
TreeNode* node_v_snapDrawSize;
#define v_snapDrawSize node_v_snapDrawSize->safedatafloat()[0]
TreeNode* node_v_polygonOffsetFactor;
#define v_polygonOffsetFactor node_v_polygonOffsetFactor->safedatafloat()[0]
TreeNode* node_v_polygonOffsetUnits;
#define v_polygonOffsetUnits node_v_polygonOffsetUnits->safedatafloat()[0]

// c++ attributes
Mesh shapeMesh;

int meshShapeType;

double repX;

double repY;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// DatabaseConnector
class DatabaseConnector : public ObjectDataType
{
public:


// c++ member functions

fs_content_export void onReset();

fs_content_export bool testConnection();

fs_content_export void updateInformationSchema();

fs_content_export void importAll();

fs_content_export void importSingle(treenode importer);

fs_content_export void exportAll();

fs_content_export void exportSingle(treenode exporter);

fs_content_export void getColumnInfo(const char* tableName, treenode destNode);

TreeNode* node_v_connection;
TreeNode* node_v_importers;
#define v_importers node_v_importers->safedatafloat()[0]
TreeNode* node_v_exporters;
#define v_exporters node_v_exporters->safedatafloat()[0]
TreeNode* node_v_tableInfo;
#define v_tableInfo node_v_tableInfo->safedatafloat()[0]
TreeNode* node_v_columnInfo;
#define v_columnInfo node_v_columnInfo->safedatafloat()[0]
TreeNode* node_v_tableList;
#define v_tableList node_v_tableList->safedatafloat()[0]
TreeNode* node_v_preparedStatements;
#define v_preparedStatements node_v_preparedStatements->safedatafloat()[0]
TreeNode* node_v_isInformationSchemaDirty;
#define v_isInformationSchemaDirty node_v_isInformationSchemaDirty->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// ReinforcementLearning
class ReinforcementLearning : public ObjectDataType
{
public:


//ClassIncludeHeaderStart
virtual void bindVariables() override;
virtual void bind() override;
virtual void bindEvents() override;
void onReset();
void onPostReset();

TreeNode* OnObservation;
TreeNode* RewardFunction;
TreeNode* OnRequestAction;

TreeNode* actionParams;
TreeNode* observationParams;

ByteBlock customActionSpace;
ByteBlock customObservationSpace;
TreeNode* customAction;
TreeNode* customObservation;

TreeNode* events;

bool training = false;
int socket = 0;
int connected = 0;

static const int SPACE_TYPE_CUSTOM = 0;
static const int SPACE_TYPE_BOX = 1;
static const int SPACE_TYPE_DISCRETE = 2;
static const int SPACE_TYPE_MULTI_DISCRETE = 3;
static const int SPACE_TYPE_MULTI_BINARY = 4;

void onModelOpen();
Variant onModelOpen(FLEXSIMINTERFACE) { onModelOpen(); return Variant();}
int connectToSocket(string address, int port);
Variant connectToSocket(FLEXSIMINTERFACE) { return connectToSocket(param(1), param(2)); }
int takeAction(string action);
Variant takeAction(FLEXSIMINTERFACE) { return takeAction(param(1)); }
void requestDecision(int isReset = 0);
Variant requestDecision(FLEXSIMINTERFACE) { requestDecision(); return Variant();}

int waitForMessage();
int sendActionSpace();
int sendObservationSpace();
string getSpaceDefinitionFromParams(TreeNode* params);
int getNumOptionsInDiscreteParam(TreeNode* constrainedVariable);
int resetEnvironment(int seed);

class DecisionEvent : public FlexSimEvent
{
public:
	DecisionEvent()
	{
		this->time = 0x1; // LISTEN_TIME_MASK_PRE_LISTEN
	}
	
	virtual const char* getClassFactory() { return "ReinforcementLearningDecisionEvent"; }
	void execute() override;
};
//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// StatisticObject
class StatisticObject : public FlexSimEventHandler
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual Variant onMessage(treenode from, const Variant& p1, const Variant& p2, const Variant& p3);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export virtual treenode addMember(treenode newObj);

fs_content_export int checkDestroy();

fs_content_export treenode getStateProfile(treenode object, int profileNum);

fs_content_export double getStateTime(treenode profile, int state, int curState);

fs_content_export int getStateUsed(treenode profile, int state);

fs_content_export string getStateName(treenode profile, int stateNum);

fs_content_export int getNumStates(treenode profile);

fs_content_export double generateGuid();

fs_content_export void bindVariables();

fs_content_export static StatisticObject* getStatisticByGuid(const char* guid);

TreeNode* node_v_guid;

// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// StateChart
class StateChart : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export int initalizeObjects();

fs_content_export int getMaxGroupNameWidth();

fs_content_export int getMaxObjectNameWidth();

fs_content_export int initializeObjectMember(treenode membernode);

fs_content_export treenode getNextMemberNode(treenode membernode);

fs_content_export int updateAllCurStates();

fs_content_export int updateCurState(treenode membernode, int entrynr);

fs_content_export int updateCurStateString(treenode membernode, int entrynr);

fs_content_export int updateStates();

fs_content_export int updateAllStates(treenode membernode, int entrynr, int onreset);

fs_content_export int saveBaseStates(treenode membernode, int entrynr);

fs_content_export int filterAllByTime(treenode view);

fs_content_export int filterByTime(treenode membernode);

fs_content_export int unfilterAll(treenode graph);

fs_content_export double getTotalTime();

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export treenode refreshUtilizedStates();

fs_content_export treenode onChangeObjectSet();

fs_content_export int countNrInGroup(treenode objnode);

fs_content_export treenode getMember(int nr);

fs_content_export treenode getMember(treenode memberNode);

fs_content_export virtual treenode addMember(treenode newObj);

fs_content_export treenode addGroup(int groupRank);

TreeNode* node_v_objects;
#define v_objects node_v_objects->safedatafloat()[0]
TreeNode* node_v_colors;
#define v_colors node_v_colors->safedatafloat()[0]
TreeNode* node_v_charttype;
#define v_charttype node_v_charttype->safedatafloat()[0]
TreeNode* node_v_customnames;
#define v_customnames node_v_customnames->safedatafloat()[0]
TreeNode* node_v_statestrings;
#define v_statestrings node_v_statestrings->safedatafloat()[0]
TreeNode* node_v_usecollecttime;
#define v_usecollecttime node_v_usecollecttime->safedatafloat()[0]
TreeNode* node_v_mincollecttime;
#define v_mincollecttime node_v_mincollecttime->safedatafloat()[0]
TreeNode* node_v_maxcollecttime;
#define v_maxcollecttime node_v_maxcollecttime->safedatafloat()[0]
TreeNode* node_v_collecthistory;
#define v_collecthistory node_v_collecthistory->safedatafloat()[0]
TreeNode* node_v_filtermintime;
#define v_filtermintime node_v_filtermintime->safedatafloat()[0]
TreeNode* node_v_filtermaxtime;
#define v_filtermaxtime node_v_filtermaxtime->safedatafloat()[0]
TreeNode* node_v_filterednow;
#define v_filterednow node_v_filterednow->safedatafloat()[0]
TreeNode* node_v_showtotals;
#define v_showtotals node_v_showtotals->safedatafloat()[0]
TreeNode* node_v_showlegend;
#define v_showlegend node_v_showlegend->safedatafloat()[0]
TreeNode* node_v_stacked;
#define v_stacked node_v_stacked->safedatafloat()[0]
TreeNode* node_v_doutilization;
#define v_doutilization node_v_doutilization->safedatafloat()[0]
TreeNode* node_v_fontsize;
#define v_fontsize node_v_fontsize->safedatafloat()[0]
TreeNode* node_v_barsize;
#define v_barsize node_v_barsize->safedatafloat()[0]
TreeNode* node_v_precision;
#define v_precision node_v_precision->safedatafloat()[0]
TreeNode* node_v_utilizedstates;
#define v_utilizedstates node_v_utilizedstates->safedatafloat()[0]
TreeNode* node_v_data;
TreeNode* node_v_basedata;
TreeNode* node_v_colordata;
TreeNode* node_v_validdata;
#define v_validdata node_v_validdata->safedatafloat()[0]
TreeNode* node_v_useprofilenr;
#define v_useprofilenr node_v_useprofilenr->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// StatChart
class StatChart : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export int initializeObjects();

fs_content_export int getMaxGroupNameWidth();

fs_content_export int getMaxObjectNameWidth();

fs_content_export int initializeObjectMember(treenode membernode, treenode bundlenode, int listen DEFAULTZERO);

fs_content_export int initializeAggregateMember(treenode groupnode);

fs_content_export treenode getNextMemberNode(treenode membernode);

fs_content_export int updateAllStats();

fs_content_export int updateMemberStats(treenode membernode, int entrynr);

fs_content_export double updateTimeStats();

fs_content_export double calculateAvgContent(treenode obj, treenode statnode, int savingbase DEFAULTZERO);

fs_content_export double calculateAvgStayTime(treenode obj, treenode statnode);

fs_content_export int saveBaseStats(treenode membernode, int entrynr);

fs_content_export int filterAllByTime(treenode view);

fs_content_export int filterByTime(treenode membernode, int entrynr);

fs_content_export int unfilterAll(treenode graph);

fs_content_export double getTotalTime();

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export treenode onChangeObjectSet();

fs_content_export int countNrInGroup(treenode objnode);

fs_content_export treenode getMember(int nr);

fs_content_export treenode getMember(treenode memberNode);

fs_content_export virtual treenode addMember(treenode newObj);

fs_content_export treenode addGroup(int groupRank);

TreeNode* node_v_objects;
#define v_objects node_v_objects->safedatafloat()[0]
TreeNode* node_v_colors;
#define v_colors node_v_colors->safedatafloat()[0]
TreeNode* node_v_charttype;
#define v_charttype node_v_charttype->safedatafloat()[0]
TreeNode* node_v_usecollecttime;
#define v_usecollecttime node_v_usecollecttime->safedatafloat()[0]
TreeNode* node_v_mincollecttime;
#define v_mincollecttime node_v_mincollecttime->safedatafloat()[0]
TreeNode* node_v_maxcollecttime;
#define v_maxcollecttime node_v_maxcollecttime->safedatafloat()[0]
TreeNode* node_v_collecthistory;
#define v_collecthistory node_v_collecthistory->safedatafloat()[0]
TreeNode* node_v_filtermintime;
#define v_filtermintime node_v_filtermintime->safedatafloat()[0]
TreeNode* node_v_filtermaxtime;
#define v_filtermaxtime node_v_filtermaxtime->safedatafloat()[0]
TreeNode* node_v_filterednow;
#define v_filterednow node_v_filterednow->safedatafloat()[0]
TreeNode* node_v_timeinterval;
#define v_timeinterval node_v_timeinterval->safedatafloat()[0]
TreeNode* node_v_showlegend;
#define v_showlegend node_v_showlegend->safedatafloat()[0]
TreeNode* node_v_fontsize;
#define v_fontsize node_v_fontsize->safedatafloat()[0]
TreeNode* node_v_barsize;
#define v_barsize node_v_barsize->safedatafloat()[0]
TreeNode* node_v_precision;
#define v_precision node_v_precision->safedatafloat()[0]
TreeNode* node_v_stacked;
#define v_stacked node_v_stacked->safedatafloat()[0]
TreeNode* node_v_statistics;
#define v_statistics node_v_statistics->safedatafloat()[0]
TreeNode* node_v_data;
TreeNode* node_v_basedata;
TreeNode* node_v_timedata;
TreeNode* node_v_colordata;
TreeNode* node_v_validdata;
#define v_validdata node_v_validdata->safedatafloat()[0]
TreeNode* node_v_useprofilenr;
#define v_useprofilenr node_v_useprofilenr->safedatafloat()[0]
TreeNode* node_v_generallisten;
#define v_generallisten node_v_generallisten->safedatafloat()[0]
TreeNode* node_v_aggregatelisten;
#define v_aggregatelisten node_v_aggregatelisten->safedatafloat()[0]
TreeNode* node_v_systemwarmuptime;
#define v_systemwarmuptime node_v_systemwarmuptime->safedatafloat()[0]
TreeNode* node_v_timemultiple;
#define v_timemultiple node_v_timemultiple->safedatafloat()[0]
TreeNode* node_v_datamultiple;
#define v_datamultiple node_v_datamultiple->safedatafloat()[0]
TreeNode* node_v_datavaluetype;
TreeNode* node_v_xaxistitle;
TreeNode* node_v_yaxistitle;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// CustomChart
class CustomChart : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export int getMaxObjectNameWidth();

fs_content_export int initializeAggregateMember(treenode groupnode);

fs_content_export treenode getNextMemberNode(treenode membernode);

fs_content_export int updateAllStats();

fs_content_export double updateTimeStats();

fs_content_export double getTotalTime();

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export treenode onChangeAssociationSet();

fs_content_export treenode getMember(int nr);

fs_content_export treenode getMember(treenode memberNode);

fs_content_export virtual treenode addMember(treenode newNode);

TreeNode* node_v_associations;
#define v_associations node_v_associations->safedatafloat()[0]
TreeNode* node_v_colors;
#define v_colors node_v_colors->safedatafloat()[0]
TreeNode* node_v_charttype;
#define v_charttype node_v_charttype->safedatafloat()[0]
TreeNode* node_v_numcategories;
TreeNode* node_v_categorytitle;
TreeNode* node_v_numseries;
TreeNode* node_v_seriestitle;
TreeNode* node_v_datapointvalue;
TreeNode* node_v_usecollecttime;
#define v_usecollecttime node_v_usecollecttime->safedatafloat()[0]
TreeNode* node_v_mincollecttime;
#define v_mincollecttime node_v_mincollecttime->safedatafloat()[0]
TreeNode* node_v_maxcollecttime;
#define v_maxcollecttime node_v_maxcollecttime->safedatafloat()[0]
TreeNode* node_v_collecthistory;
#define v_collecthistory node_v_collecthistory->safedatafloat()[0]
TreeNode* node_v_timeinterval;
#define v_timeinterval node_v_timeinterval->safedatafloat()[0]
TreeNode* node_v_showlegend;
#define v_showlegend node_v_showlegend->safedatafloat()[0]
TreeNode* node_v_fontsize;
#define v_fontsize node_v_fontsize->safedatafloat()[0]
TreeNode* node_v_barsize;
#define v_barsize node_v_barsize->safedatafloat()[0]
TreeNode* node_v_precision;
#define v_precision node_v_precision->safedatafloat()[0]
TreeNode* node_v_stacked;
#define v_stacked node_v_stacked->safedatafloat()[0]
TreeNode* node_v_reloadbundle;
#define v_reloadbundle node_v_reloadbundle->safedatafloat()[0]
TreeNode* node_v_data;
TreeNode* node_v_timedata;
TreeNode* node_v_colordata;
TreeNode* node_v_validdata;
#define v_validdata node_v_validdata->safedatafloat()[0]
TreeNode* node_v_systemwarmuptime;
#define v_systemwarmuptime node_v_systemwarmuptime->safedatafloat()[0]
TreeNode* node_v_timescale;
#define v_timescale node_v_timescale->safedatafloat()[0]
TreeNode* node_v_xaxistitle;
TreeNode* node_v_yaxistitle;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// GanttChart
class GanttChart : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export int getLastEntryNum(int series);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export int initalizeObjects();

fs_content_export int getMaxObjectNameWidth();

fs_content_export int initializeObjectMember(treenode membernode);

fs_content_export treenode getNextMemberNode(treenode membernode);

fs_content_export double updateCurrentStates();

fs_content_export double getTotalTime();

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export treenode refreshStates();

fs_content_export virtual treenode onChangeObjectSet();

fs_content_export treenode getMember(int nr);

fs_content_export treenode getMember(treenode memberNode);

fs_content_export virtual treenode addMember(treenode newObj);

fs_content_export treenode addGroup(int groupRank);

TreeNode* node_v_objects;
#define v_objects node_v_objects->safedatafloat()[0]
TreeNode* node_v_colors;
#define v_colors node_v_colors->safedatafloat()[0]
TreeNode* node_v_charttype;
#define v_charttype node_v_charttype->safedatafloat()[0]
TreeNode* node_v_tracerequirementtrigger;
TreeNode* node_v_itemnametrigger;
TreeNode* node_v_usecollecttime;
#define v_usecollecttime node_v_usecollecttime->safedatafloat()[0]
TreeNode* node_v_mincollecttime;
#define v_mincollecttime node_v_mincollecttime->safedatafloat()[0]
TreeNode* node_v_maxcollecttime;
#define v_maxcollecttime node_v_maxcollecttime->safedatafloat()[0]
TreeNode* node_v_showlegend;
#define v_showlegend node_v_showlegend->safedatafloat()[0]
TreeNode* node_v_fontsize;
#define v_fontsize node_v_fontsize->safedatafloat()[0]
TreeNode* node_v_barsize;
#define v_barsize node_v_barsize->safedatafloat()[0]
TreeNode* node_v_itemtrace;
#define v_itemtrace node_v_itemtrace->safedatafloat()[0]
TreeNode* node_v_timescale;
#define v_timescale node_v_timescale->safedatafloat()[0]
TreeNode* node_v_xaxistitle;
TreeNode* node_v_reloadbundles;
#define v_reloadbundles node_v_reloadbundles->safedatafloat()[0]
TreeNode* node_v_newtime;
#define v_newtime node_v_newtime->safedatafloat()[0]
TreeNode* node_v_includedstates;
#define v_includedstates node_v_includedstates->safedatafloat()[0]
TreeNode* node_v_series;
TreeNode* node_v_entrylegend;
TreeNode* node_v_data;
TreeNode* node_v_colordata;
TreeNode* node_v_validdata;
#define v_validdata node_v_validdata->safedatafloat()[0]
TreeNode* node_v_useprofilenr;
#define v_useprofilenr node_v_useprofilenr->safedatafloat()[0]
TreeNode* node_v_wrap;
#define v_wrap node_v_wrap->safedatafloat()[0]
TreeNode* node_v_wraptime;
#define v_wraptime node_v_wraptime->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// CustomGanttChart
class CustomGanttChart : public GanttChart
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double onRunWarm();

fs_content_export virtual double drawGraph(treenode view);

fs_content_export double updateOrderedStats();

fs_content_export double updateUnorderedStats();

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export treenode onChangeAssociationSet();

fs_content_export treenode getMember(treenode memberNode);

fs_content_export virtual treenode addMember(treenode newNode);

TreeNode* node_v_associations;
#define v_associations node_v_associations->safedatafloat()[0]
TreeNode* node_v_lockmodeltime;
#define v_lockmodeltime node_v_lockmodeltime->safedatafloat()[0]
TreeNode* node_v_chartendtime;
#define v_chartendtime node_v_chartendtime->safedatafloat()[0]
TreeNode* node_v_ordered;
#define v_ordered node_v_ordered->safedatafloat()[0]
TreeNode* node_v_numseries;
TreeNode* node_v_seriestitle;
TreeNode* node_v_seriesspan;
TreeNode* node_v_numentries;
TreeNode* node_v_starttime;
TreeNode* node_v_endtime;
TreeNode* node_v_legend;
TreeNode* node_v_legendtitle;
TreeNode* node_v_legendshow;
TreeNode* node_v_clickcallback;
TreeNode* node_v_spanbarsize;
#define v_spanbarsize node_v_spanbarsize->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// TrackedVariableChart
class TrackedVariableChart : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export double initializeData(treenode view);

fs_content_export double updateData(treenode view);

fs_content_export virtual treenode addMember(treenode newNode);

fs_content_export treenode addMember(treenode object, const Variant& stat);

TreeNode* node_v_trackedvariables;
#define v_trackedvariables node_v_trackedvariables->safedatafloat()[0]
TreeNode* node_v_colors;
#define v_colors node_v_colors->safedatafloat()[0]
TreeNode* node_v_charttype;
#define v_charttype node_v_charttype->safedatafloat()[0]
TreeNode* node_v_showlegend;
#define v_showlegend node_v_showlegend->safedatafloat()[0]
TreeNode* node_v_nrbuckets;
#define v_nrbuckets node_v_nrbuckets->safedatafloat()[0]
TreeNode* node_v_normalize;
#define v_normalize node_v_normalize->safedatafloat()[0]
TreeNode* node_v_colordata;
TreeNode* node_v_timemultiple;
#define v_timemultiple node_v_timemultiple->safedatafloat()[0]
TreeNode* node_v_datamultiple;
#define v_datamultiple node_v_datamultiple->safedatafloat()[0]
TreeNode* node_v_datavaluetype;
TreeNode* node_v_xaxistitle;
TreeNode* node_v_yaxistitle;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// HtmlStatistic
class HtmlStatistic : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export double parseUserHtml();

fs_content_export double dumpHtml(treenode toNode, int replace);

fs_content_export  HtmlStatistic();

fs_content_export  ~HtmlStatistic();

TreeNode* node_v_userhtml;
TreeNode* node_v_userheader;
TreeNode* node_v_hasdynamicflexscript;
#define v_hasdynamicflexscript node_v_hasdynamicflexscript->safedatafloat()[0]
TreeNode* node_v_flexscriptprocessor;
TreeNode* node_v_elementid;

// c++ attributes
Window console;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FinancialAnalysis
class FinancialAnalysis : public StatisticObject
{
public:


// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export int initalizeObjects();

fs_content_export treenode getNextMemberNode(treenode membernode);

fs_content_export int getMaxObjectNameWidth();

fs_content_export int initializeObjectMember(treenode membernode);

fs_content_export int updateAllStats();

fs_content_export double updateMemberStats(treenode membernode, double totalTime, int entrynr);

fs_content_export double updateTotals();

fs_content_export double getTotalTime();

fs_content_export int isGroup(treenode membernode);

fs_content_export double setProperties(treenode view);

fs_content_export int applyProperties(treenode graph);

fs_content_export treenode onChangeObjectSet();

fs_content_export treenode getMember(int nr);

fs_content_export treenode getMember(treenode memberNode);

fs_content_export virtual treenode addMember(treenode newObj);

fs_content_export treenode addGroup(int groupRank);

TreeNode* node_v_objects;
#define v_objects node_v_objects->safedatafloat()[0]
TreeNode* node_v_charttype;
#define v_charttype node_v_charttype->safedatafloat()[0]
TreeNode* node_v_currency;
TreeNode* node_v_precision;
#define v_precision node_v_precision->safedatafloat()[0]
TreeNode* node_v_fontsize;
#define v_fontsize node_v_fontsize->safedatafloat()[0]
TreeNode* node_v_usecollecttime;
#define v_usecollecttime node_v_usecollecttime->safedatafloat()[0]
TreeNode* node_v_mincollecttime;
#define v_mincollecttime node_v_mincollecttime->safedatafloat()[0]
TreeNode* node_v_maxcollecttime;
#define v_maxcollecttime node_v_maxcollecttime->safedatafloat()[0]
TreeNode* node_v_data;
TreeNode* node_v_displaydata;
TreeNode* node_v_validdata;
#define v_validdata node_v_validdata->safedatafloat()[0]
TreeNode* node_v_reset;
#define v_reset node_v_reset->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// GenericChart
class GenericChart : public StatisticObject
{
public:


//ClassIncludeHeaderStart
class EnumSortDelegate;
class SimpleSortDelegate;
class SortDelegate : public SimpleDataType
{
protected:
	treenode canSortNode;

public:
	virtual bool canSort(const Variant& value, const char* colName, int format);
	virtual bool compare(const Variant& value1, const Variant& value2, int format);
	
	virtual void bind() override;

	virtual EnumSortDelegate* toEnumSortDelegate() { return nullptr; }
	virtual SimpleSortDelegate* toSimpleSortDelegate() { return nullptr; }

	Variant getSortType(FLEXSIMINTERFACE);
	Variant reset(FLEXSIMINTERFACE);
	Variant canSort(FLEXSIMINTERFACE);
	Variant compare(FLEXSIMINTERFACE);
};

class EnumSortDelegate : public SortDelegate
{
protected:
	typedef std::unordered_map<Variant, int, Variant::Hash, Variant::KeyEqual> ValueMap;
	ValueMap valueMap;
	bool mapDirty = true;
	void buildMap();
	
public:
	treenode valueNode;
	double dynamic = 0.0;
	void reset();
	virtual bool canSort(const Variant& value, const char* colName, int format) override;
	virtual bool compare(const Variant& value1, const Variant& value2, int format) override;
	virtual void bind() override;
	virtual const char* getClassFactory() override { return "GenericChartEnumSortDelegate"; }

	virtual EnumSortDelegate* toEnumSortDelegate() override { return this; }
};

class SimpleSortDelegate : public SortDelegate
{
public:
	double descending = 0.0;
	virtual bool compare(const Variant& value1, const Variant& value2, int format) override;
	virtual void bind() override;
	virtual const char* getClassFactory() override { return "GenericChartSimpleSortDelegate"; }

	virtual SimpleSortDelegate* toSimpleSortDelegate() override { return this; }
};

static SimpleDataType* createSDTDerivative(const char* className);

double sortCategories = 0.0;
NodeListArray<SortDelegate>::SdtSubNodeBindingType sortDelegates;
treenode addEnumSortDelegate() { return sortDelegates.add(new EnumSortDelegate)->holder; }
treenode addSimpleSortDelegate() { return sortDelegates.add(new SimpleSortDelegate)->holder; }

treenode addSortDelegate(const char* type) {
	if (strcmp(type, "Enum") == 0) {
		return addEnumSortDelegate();
	} else if (strcmp(type, "Simple") == 0) {
		return addSimpleSortDelegate();
	}
	return nullptr;
}

class RowProcessor
{
public:
	GenericChart& chart;
	RowProcessor(GenericChart& chart) : chart(chart) {};
	virtual void prepare() {}
	virtual void processRow(TreeNode* bundle, int entry) = 0;
	virtual void postProcess() {}
};

class CategoryRowProcessor : public RowProcessor
{
protected:
	Array colNames;

public:
	Array colIndices;
	Array colFormats;
	Array sortColFlags;
	std::vector<Array> categories;
	std::unordered_map<Variant, std::vector<int>, Variant::Hash, Variant::KeyEqual> categoryMap;
	CategoryRowProcessor(GenericChart& chart) : RowProcessor(chart) {}
	virtual void prepare() override;
	virtual void processRow(TreeNode* bundle, int entry) override;
	virtual void postProcess() override;
};

class IntFormatProcessor : public RowProcessor
{
protected:
	int intColumnCount;

public:
	Array colIndices;
	Array colFormats;
	IntFormatProcessor(GenericChart& chart) : RowProcessor(chart) {}
	virtual void prepare() override;
	virtual void processRow(TreeNode* bundle, int entry) override;
};

CategoryRowProcessor colorCategoryProcessor = CategoryRowProcessor(*this);
CategoryRowProcessor axisCategoryProcessor = CategoryRowProcessor(*this);
IntFormatProcessor intFormatProcessor = IntFormatProcessor(*this);

void processBundle(TreeNode* tableRef, TreeNode* bundleNode, TreeNode* repData = nullptr);

bool initIntFormatProcessor(TreeNode* bundleNode, Array colFormats);
bool initColorCategoryProcessor(int numCols, Array colFormats);
bool initAxisCategoryProcessor(int numCols, Array colFormats);

bool usedIntFormatProcessor = false;
bool usedColorCategoryProcessor = false;
bool usedAxisCategoryProcessor = false;
bool shouldSetAxisCategories = false;

void sortCategoryList(std::vector<Array>& categories, Array colNames, Array colFormats, Array sortColFlags);

bool encodeNumberValues = false;

bool hasAxisCategories();

fs_content_export void bindVariables() override;
//ClassIncludeHeaderEnd

// c++ member functions

fs_content_export virtual double onReset();

fs_content_export virtual Variant onMessage(treenode from, const Variant& p1, const Variant& p2, const Variant& p3);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onRunWarm();

fs_content_export virtual double onPreDraw(treenode  view);

fs_content_export virtual double onListen(treenode listenedto, treenode listenercoupling, int listenercode, int ecode, treenode involved, char* edata);

fs_content_export virtual double hasAbility(int ability);

fs_content_export virtual double drawGraph(treenode view);

fs_content_export virtual double getAggregationType();

fs_content_export virtual double enumerateAggregationList(treenode from);

fs_content_export virtual double aggregateData(treenode destNode, treenode statNode);

fs_content_export virtual double getData(treenode destNode);

fs_content_export virtual double getOfflineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOnlineHtml(treenode destNode, int chartNum);

fs_content_export virtual double getOfflineDependencies(treenode destNode);

fs_content_export virtual double getOfflineInitializer(treenode destNode);

fs_content_export virtual double getOfflineData(treenode from, treenode repDataNode);

fs_content_export virtual double createCSV(char* filePath);

fs_content_export virtual treenode addMember(treenode newObj);

fs_content_export std::string setProperties(treenode view, treenode repData DEFAULTZERO);

fs_content_export std::string getBasicPropertiesAsJSON();

fs_content_export std::string getAxisPropertiesAsJSON(treenode settings);

fs_content_export std::string getFormatPropertiesAsJSON(treenode tableRef, treenode repData DEFAULTZERO);

fs_content_export std::string getColorPropertiesAsJSON(treenode tableRef, treenode repData DEFAULTZERO);

fs_content_export Array getColorValues(std::vector<int>& objColumns, treenode tableRef, treenode repData DEFAULTZERO);

fs_content_export std::vector<int> getObjDisplayColumns(Array columnFormats);

fs_content_export Array getColumnFormats(treenode tableRef, treenode repData DEFAULTZERO);

fs_content_export int getObjectFormatMaxDepth(treenode tableRef, treenode repData DEFAULTZERO);

fs_content_export std::set<unsigned __int64> getIDsInBundle(treenode bundle, const std::vector<int>& fields);

fs_content_export std::string getColumnListAsJSON(const char* name, treenode colListNode);

fs_content_export std::string getValueListAsJSON(const char* name, treenode valueListNode);

fs_content_export Array getColumnListAsArray(treenode colListNode, int base DEFAULTZERO);

fs_content_export std::string getNameValueJSON(const char* name, const Variant& value);

fs_content_export std::string getValueJSON(const Variant& value);

fs_content_export std::string getNameNodeValueJSON(const char* name, treenode valueNode, bool neg1IsNull DEFAULTZERO);

fs_content_export treenode getBundleNode(treenode tableRef);

fs_content_export treenode getBundleFormatter(treenode tableRef);

fs_content_export Variant getNewIDsInSeries(treenode bundleNode, treenode series);

fs_content_export void getDataForTable(treenode tableRef, treenode destNode);

fs_content_export treenode getSettingsNode();

fs_content_export treenode getTableRef(treenode settings);

fs_content_export treenode getKeyColumns(treenode settings);

fs_content_export treenode getAxisKeyColumns(treenode settings);

fs_content_export treenode getColorKeyColumns(treenode settings);

fs_content_export Variant getDataColumnsArray(treenode settings, int base DEFAULTZERO);

fs_content_export void setAxisCategories(treenode tableRef, treenode repData DEFAULTZERO);

fs_content_export void onColorAssignment(const Variant& value, const Variant& color, int usedExistingColor);

fs_content_export void onXCategoryFound(std::string category);

fs_content_export void onColorCategoryFound(std::string category);

fs_content_export virtual double onDestroy(treenode view);

fs_content_export std::string getTimeFormatAsJSON();

fs_content_export std::string getNumberFormatAsJSON();

fs_content_export std::string getColumnReplacementText(int rank);

fs_content_export std::string getValueReplacementText(int rank);

fs_content_export std::map<int, treenode> getReplicationBundles(int scenario);

fs_content_export Array getReplicationFormats();

fs_content_export GenericChart* getExperimentVersion();

fs_content_export Array getTextForAxisKeyValue(Array keyValue, treenode repData DEFAULTZERO);

TreeNode* node_v_data;
TreeNode* node_v_initialized;
#define v_initialized node_v_initialized->safedatafloat()[0]
TreeNode* node_v_chartType;
#define v_chartType node_v_chartType->safedatafloat()[0]
TreeNode* node_v_genericChartType;
#define v_genericChartType node_v_genericChartType->safedatafloat()[0]
TreeNode* node_v_fontSize;
#define v_fontSize node_v_fontSize->safedatafloat()[0]
TreeNode* node_v_titleFontSize;
#define v_titleFontSize node_v_titleFontSize->safedatafloat()[0]
TreeNode* node_v_axisTitleFontSize;
#define v_axisTitleFontSize node_v_axisTitleFontSize->safedatafloat()[0]
TreeNode* node_v_precision;
#define v_precision node_v_precision->safedatafloat()[0]
TreeNode* node_v_showLegend;
#define v_showLegend node_v_showLegend->safedatafloat()[0]
TreeNode* node_v_useCustomTitle;
#define v_useCustomTitle node_v_useCustomTitle->safedatafloat()[0]
TreeNode* node_v_customTitle;
TreeNode* node_v_manager;
TreeNode* node_v_palette;
TreeNode* node_v_localPalette;
TreeNode* node_v_namedColumns;
#define v_namedColumns node_v_namedColumns->safedatafloat()[0]
TreeNode* node_v_axisCategories;
#define v_axisCategories node_v_axisCategories->safedatafloat()[0]
TreeNode* node_v_colorCategories;
#define v_colorCategories node_v_colorCategories->safedatafloat()[0]
TreeNode* node_v_allowAxisChase;
#define v_allowAxisChase node_v_allowAxisChase->safedatafloat()[0]
TreeNode* node_v_useAxisOrderInTable;
#define v_useAxisOrderInTable node_v_useAxisOrderInTable->safedatafloat()[0]
TreeNode* node_v_timeplotSettings;
#define v_timeplotSettings node_v_timeplotSettings->safedatafloat()[0]
TreeNode* node_v_histogramSettings;
#define v_histogramSettings node_v_histogramSettings->safedatafloat()[0]
TreeNode* node_v_ganttSettings;
#define v_ganttSettings node_v_ganttSettings->safedatafloat()[0]
TreeNode* node_v_pieSettings;
#define v_pieSettings node_v_pieSettings->safedatafloat()[0]
TreeNode* node_v_barSettings;
#define v_barSettings node_v_barSettings->safedatafloat()[0]
TreeNode* node_v_tableSettings;
#define v_tableSettings node_v_tableSettings->safedatafloat()[0]
TreeNode* node_v_boxPlotSettings;
#define v_boxPlotSettings node_v_boxPlotSettings->safedatafloat()[0]
TreeNode* node_v_sankeySettings;
#define v_sankeySettings node_v_sankeySettings->safedatafloat()[0]

// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// ScenarioChart
class ScenarioChart : public GenericChart, public ColumnFormatter
{
public:


// c++ member functions

fs_content_export int getColumnFormat(int colNr);

fs_content_export Array getColumnFormats();

fs_content_export treenode getBundleNode();

fs_content_export void setData();

fs_content_export void setSettings();

fs_content_export void setDefaultDataAndSettings();

fs_content_export void bindVariables();

fs_content_export virtual double getAggregationType();

TreeNode* node_v_needsUpdate;
#define v_needsUpdate node_v_needsUpdate->safedatafloat()[0]
TreeNode* node_v_timeplotInterpolationMode;
#define v_timeplotInterpolationMode node_v_timeplotInterpolationMode->safedatafloat()[0]
TreeNode* node_v_timeplotSampleRate;
#define v_timeplotSampleRate node_v_timeplotSampleRate->safedatafloat()[0]
TreeNode* node_v_timeplotShowRange;
#define v_timeplotShowRange node_v_timeplotShowRange->safedatafloat()[0]
TreeNode* node_v_timeplotShowConfidence;
#define v_timeplotShowConfidence node_v_timeplotShowConfidence->safedatafloat()[0]
TreeNode* node_v_timeplotConfidence;
#define v_timeplotConfidence node_v_timeplotConfidence->safedatafloat()[0]
TreeNode* node_v_tableAggregateColumns;
#define v_tableAggregateColumns node_v_tableAggregateColumns->safedatafloat()[0]
TreeNode* node_v_tableShowMean;
#define v_tableShowMean node_v_tableShowMean->safedatafloat()[0]
TreeNode* node_v_tableShowMin;
#define v_tableShowMin node_v_tableShowMin->safedatafloat()[0]
TreeNode* node_v_tableShowMax;
#define v_tableShowMax node_v_tableShowMax->safedatafloat()[0]
TreeNode* node_v_pieAggregateTitle;
#define v_pieAggregateTitle node_v_pieAggregateTitle->safedatafloat()[0]
TreeNode* node_v_pieAggregateCenter;
#define v_pieAggregateCenter node_v_pieAggregateCenter->safedatafloat()[0]
TreeNode* node_v_barAggregateTitle;
#define v_barAggregateTitle node_v_barAggregateTitle->safedatafloat()[0]
TreeNode* node_v_barAggregateValue;
#define v_barAggregateValue node_v_barAggregateValue->safedatafloat()[0]
TreeNode* node_v_localPalette;
TreeNode* node_v_allowAxisChase;
#define v_allowAxisChase node_v_allowAxisChase->safedatafloat()[0]

// c++ attributes
ObjRef<GenericChart> sourceChart;

treenode scenarios;

BundleMember data;

treenode formatList;

treenode infoForSettings;

treenode chartDump;

ObjRef<GenericChart::EnumSortDelegate> scenarioDelegate;


// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// Source
class Source : public FixedResource
{
public:


// c++ member functions

fs_content_export double onSend(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double generateItem(double curitemtype, const string& itemname, double rownumber);

fs_content_export virtual double onPreDraw(treenode view);

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export virtual void bindEvents();

TreeNode* node_v_arrivalmode;
#define v_arrivalmode node_v_arrivalmode->safedatafloat()[0]
TreeNode* node_v_interarrivaltime;
TreeNode* node_v_timezerocreate;
#define v_timezerocreate node_v_timezerocreate->safedatafloat()[0]
TreeNode* node_v_itemclass;
#define v_itemclass node_v_itemclass->safedatafloat()[0]
TreeNode* node_v_schedule;
#define v_schedule node_v_schedule->safedatafloat()[0]
TreeNode* node_v_repeat;
#define v_repeat node_v_repeat->safedatafloat()[0]
TreeNode* node_v_sequence;
#define v_sequence node_v_sequence->safedatafloat()[0]
TreeNode* node_v_sequencecurrow;
#define v_sequencecurrow node_v_sequencecurrow->safedatafloat()[0]
TreeNode* node_v_flowitembin;
#define v_flowitembin node_v_flowitembin->safedatafloat()[0]

// c++ attributes
treenode flowitemtocreate;

treenode onCreationTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Queue
class Queue : public FixedResource
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export double onSend(treenode item, int port);

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export virtual void onTransportInFailed(treenode item, int port);

fs_content_export double resetVariables();

fs_content_export virtual double getPlaceOffset(treenode involvedobj, treenode fromobject,  double* returnarray);

fs_content_export virtual double getPickOffset(treenode involvedobj, treenode toobject, double* returnarray);

fs_content_export virtual double updateLocations();

fs_content_export virtual double setLocations(int uptorank);

fs_content_export void calculateNextLocation(treenode item);

fs_content_export virtual double checkReceiveItem();

fs_content_export virtual void bindEvents();

fs_content_export void cacheLocationUpdateData();

TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_usebatching;
#define v_usebatching node_v_usebatching->safedatafloat()[0]
TreeNode* node_v_batchsize;
#define v_batchsize node_v_batchsize->safedatafloat()[0]
TreeNode* node_v_maxwaittime;
#define v_maxwaittime node_v_maxwaittime->safedatafloat()[0]
TreeNode* node_v_flush;
#define v_flush node_v_flush->safedatafloat()[0]
TreeNode* node_v_currentbatchsize;
#define v_currentbatchsize node_v_currentbatchsize->safedatafloat()[0]
TreeNode* node_v_placemode;
#define v_placemode node_v_placemode->safedatafloat()[0]
TreeNode* node_v_stackinitz;
#define v_stackinitz node_v_stackinitz->safedatafloat()[0]

// c++ attributes
int lastpredrawoutput;

int lastpredrawinput;

treenode onEndCollectingTrigger = nullptr;

double currentxloc;

double currentyloc;

double currentzloc;

double currentmaxsy;

double currentmaxsz;

double xfringeleft;

double xfringeright;

double yfringebottom;

double yfringetop;

double xinc;

double yinc;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Processor
class Processor : public FixedResource
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export virtual double onDraw(treenode view);

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export double resetVariables();

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export virtual double callProcessOperators( treenode item, int trigger);

fs_content_export virtual double releaseProcessOperators( treenode item);

fs_content_export virtual double processorEvents(double code, treenode involved, char * datastr);

fs_content_export virtual double updateLocations();

fs_content_export virtual double onPreDraw(treenode view);

fs_content_export virtual unsigned int getClassType();

fs_content_export double checkSetupOpCall( treenode item, double cursetuptime);

fs_content_export double checkProcessOpCall(treenode item, double curcycletime);

fs_content_export double checkSetupOpFree(treenode item);

fs_content_export double checkProcessOpFree(treenode item);

fs_content_export virtual double startSetupTime(treenode item, int port);

fs_content_export virtual void onTransportInFailed(treenode item, int port);

fs_content_export virtual void bindEvents();

TreeNode* node_v_cycletime;
#define v_cycletime node_v_cycletime->safedatafloat()[0]
TreeNode* node_v_setuptime;
#define v_setuptime node_v_setuptime->safedatafloat()[0]
TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_useprocessoperators;
#define v_useprocessoperators node_v_useprocessoperators->safedatafloat()[0]
TreeNode* node_v_usesetupoperators;
#define v_usesetupoperators node_v_usesetupoperators->safedatafloat()[0]
TreeNode* node_v_nrofprocessoperators;
#define v_nrofprocessoperators node_v_nrofprocessoperators->safedatafloat()[0]
TreeNode* node_v_processoperatorpriority;
#define v_processoperatorpriority node_v_processoperatorpriority->safedatafloat()[0]
TreeNode* node_v_preemptprocessoperators;
#define v_preemptprocessoperators node_v_preemptprocessoperators->safedatafloat()[0]
TreeNode* node_v_processdispatcher;
TreeNode* node_v_convey;
#define v_convey node_v_convey->safedatafloat()[0]
TreeNode* node_v_usesameop;
#define v_usesameop node_v_usesameop->safedatafloat()[0]
TreeNode* node_v_nrofsetupoperators;
#define v_nrofsetupoperators node_v_nrofsetupoperators->safedatafloat()[0]

// c++ attributes
treenode onSetupFinishTrigger = nullptr;

treenode onProcessFinishTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Sink
class Sink : public FixedResource
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onReceive(treenode item, int port);

fs_content_export double resetVariables();

fs_content_export virtual double onTransportInNotify(treenode item, int portnumber);

fs_content_export virtual double updateLocations();

fs_content_export virtual void bindEvents();

TreeNode* node_v_recycle;
#define v_recycle node_v_recycle->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Combiner
class Combiner : public Processor
{
public:


// c++ member functions

fs_content_export  Combiner();

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onClick(treenode view, int code);

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export double resetVariables();

fs_content_export virtual double generateCompList();

fs_content_export double receiveItem();

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export virtual double onTransportInComplete(treenode item, int port, treenode transporter DEFAULTNULL);

fs_content_export virtual void onTransportInFailed(treenode item, int port);

fs_content_export virtual double getPlaceOffset(treenode involvedobj, treenode fromobject,  double* returnarray);

fs_content_export virtual double updateVersion(char* newversion, char* oldversion);

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export virtual double checkReceiveItem();

TreeNode* node_v_collectingcontainer;
#define v_collectingcontainer node_v_collectingcontainer->safedatafloat()[0]
TreeNode* node_v_componentlist;
#define v_componentlist node_v_componentlist->safedatafloat()[0]
TreeNode* node_v_currentcomponentsum;
#define v_currentcomponentsum node_v_currentcomponentsum->safedatafloat()[0]
TreeNode* node_v_targetcomponentsum;
#define v_targetcomponentsum node_v_targetcomponentsum->safedatafloat()[0]
TreeNode* node_v_pack;
#define v_pack node_v_pack->safedatafloat()[0]
TreeNode* node_v_recycle;
#define v_recycle node_v_recycle->safedatafloat()[0]

// c++ attributes
bool internalMove = false;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Separator
class Separator : public Processor
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double resetVariables();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export virtual void bindEvents();

TreeNode* node_v_unpack;
#define v_unpack node_v_unpack->safedatafloat()[0]
TreeNode* node_v_splitquantity;
TreeNode* node_v_overriddensendtoport;
TreeNode* node_v_recycle;
#define v_recycle node_v_recycle->safedatafloat()[0]

// c++ attributes
bool movingItemsNow = false;;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// MultiProcessor
class MultiProcessor : public FixedResource
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export virtual double onPreDraw(treenode view);

fs_content_export double resetVariables();

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export virtual void bindEvents();

fs_content_export double assertProfile();

TreeNode* node_v_optable;
#define v_optable node_v_optable->safedatafloat()[0]
TreeNode* node_v_nrofprocesses;
#define v_nrofprocesses node_v_nrofprocesses->safedatafloat()[0]
TreeNode* node_v_curdispatcher;
#define v_curdispatcher node_v_curdispatcher->safedatafloat()[0]
TreeNode* node_v_convey;
#define v_convey node_v_convey->safedatafloat()[0]
TreeNode* node_v_nonestate;
#define v_nonestate node_v_nonestate->safedatafloat()[0]

// c++ attributes
treenode onProcessFinishTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Conveyor
class Conveyor : public FixedResource
{
public:


// c++ member functions

fs_content_export  Conveyor();

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export double onDraw(treenode view);

fs_content_export double onDrawPlanar(treenode view);

fs_content_export double onPreDraw(treenode view);

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export double setAllLocations();

fs_content_export double setOneLocation(treenode item, double tempmaxloc, double curzoffset);

fs_content_export double resetVariables();

fs_content_export double updateSectionInfo();

fs_content_export virtual double getPickOffset(treenode involvedobj, treenode toobject, double* returnarray);

fs_content_export virtual double getPlaceOffset(treenode involvedobj, treenode fromobject,  double* returnarray);

fs_content_export virtual double updateLocations();

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export virtual double photoEyeEntryLogic(treenode item);

fs_content_export virtual double checkCreatePEYellow(treenode item, double itempos, int onexit DEFAULTZERO);

fs_content_export virtual double checkCreatePEGreen(treenode item, double itembackedgepos, int pe, int onexit DEFAULTZERO);

fs_content_export virtual double photoEyeExitLogic(treenode item);

fs_content_export double alignNextLoc();

fs_content_export virtual unsigned int getClassType();

fs_content_export double getProdLength(treenode item);

fs_content_export virtual double changeSpeed(double newspeed);

fs_content_export virtual double blockedLengthNotify(double length);

fs_content_export virtual double blockedLengthNotifyUpstream(double length);

fs_content_export virtual double resetConveyorKinematics();

fs_content_export virtual double flipAroundAxis(const Vec2& point1, const Vec2& point2);

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export double initItem(treenode item);

fs_content_export double buildBaseMesh(treenode cursection);

fs_content_export double buildConveyorMesh(treenode cursection, double &curtexperc);

fs_content_export virtual void bindEvents();

TreeNode* node_v_speed;
#define v_speed node_v_speed->safedatafloat()[0]
TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_accumulating;
#define v_accumulating node_v_accumulating->safedatafloat()[0]
TreeNode* node_v_lastexittime;
#define v_lastexittime node_v_lastexittime->safedatafloat()[0]
TreeNode* node_v_lastentrytime;
#define v_lastentrytime node_v_lastentrytime->safedatafloat()[0]
TreeNode* node_v_lastexitsize;
#define v_lastexitsize node_v_lastexitsize->safedatafloat()[0]
TreeNode* node_v_conveytimesle;
#define v_conveytimesle node_v_conveytimesle->safedatafloat()[0]
TreeNode* node_v_conveyorlength;
#define v_conveyorlength node_v_conveyorlength->safedatafloat()[0]
TreeNode* node_v_needinputevent;
#define v_needinputevent node_v_needinputevent->safedatafloat()[0]
TreeNode* node_v_filledlength;
#define v_filledlength node_v_filledlength->safedatafloat()[0]
TreeNode* node_v_spacingmode;
#define v_spacingmode node_v_spacingmode->safedatafloat()[0]
TreeNode* node_v_spacing;
#define v_spacing node_v_spacing->safedatafloat()[0]
TreeNode* node_v_zoffset;
#define v_zoffset node_v_zoffset->safedatafloat()[0]
TreeNode* node_v_siderelative;
#define v_siderelative node_v_siderelative->safedatafloat()[0]
TreeNode* node_v_sideheight;
#define v_sideheight node_v_sideheight->safedatafloat()[0]
TreeNode* node_v_nroflegs;
#define v_nroflegs node_v_nroflegs->safedatafloat()[0]
TreeNode* node_v_legsrelative;
#define v_legsrelative node_v_legsrelative->safedatafloat()[0]
TreeNode* node_v_legheight;
#define v_legheight node_v_legheight->safedatafloat()[0]
TreeNode* node_v_texturedist;
#define v_texturedist node_v_texturedist->safedatafloat()[0]
TreeNode* node_v_prodzoffset;
#define v_prodzoffset node_v_prodzoffset->safedatafloat()[0]
TreeNode* node_v_sections;
#define v_sections node_v_sections->safedatafloat()[0]
TreeNode* node_v_lastentrysize;
#define v_lastentrysize node_v_lastentrysize->safedatafloat()[0]
TreeNode* node_v_photoeyes;
#define v_photoeyes node_v_photoeyes->safedatafloat()[0]
TreeNode* node_v_orientationmode;
#define v_orientationmode node_v_orientationmode->safedatafloat()[0]
TreeNode* node_v_zorient;
#define v_zorient node_v_zorient->safedatafloat()[0]
TreeNode* node_v_yorient;
#define v_yorient node_v_yorient->safedatafloat()[0]
TreeNode* node_v_userlength;
#define v_userlength node_v_userlength->safedatafloat()[0]
TreeNode* node_v_scaleitemsize;
#define v_scaleitemsize node_v_scaleitemsize->safedatafloat()[0]
TreeNode* node_v_sectiontotallength;
#define v_sectiontotallength node_v_sectiontotallength->safedatafloat()[0]
TreeNode* node_v_blockedlength;
#define v_blockedlength node_v_blockedlength->safedatafloat()[0]
TreeNode* node_v_notifyofblockedlength;
#define v_notifyofblockedlength node_v_notifyofblockedlength->safedatafloat()[0]
TreeNode* node_v_zerospeedtime;
#define v_zerospeedtime node_v_zerospeedtime->safedatafloat()[0]
TreeNode* node_v_lastpositivespeed;
#define v_lastpositivespeed node_v_lastpositivespeed->safedatafloat()[0]
TreeNode* node_v_convkinematic;
TreeNode* node_v_totalexitedspace;
#define v_totalexitedspace node_v_totalexitedspace->safedatafloat()[0]
TreeNode* node_v_curtexper;
#define v_curtexper node_v_curtexper->safedatafloat()[0]
TreeNode* node_v_drawcont;
#define v_drawcont node_v_drawcont->safedatafloat()[0]
TreeNode* node_v_drawstop;
#define v_drawstop node_v_drawstop->safedatafloat()[0]
TreeNode* node_v_textureincrement;
#define v_textureincrement node_v_textureincrement->safedatafloat()[0]
TreeNode* node_v_movewhilepaused;
#define v_movewhilepaused node_v_movewhilepaused->safedatafloat()[0]
TreeNode* node_v_lastdrawtime;
#define v_lastdrawtime node_v_lastdrawtime->safedatafloat()[0]
TreeNode* node_v_texremainder;
#define v_texremainder node_v_texremainder->safedatafloat()[0]
TreeNode* node_v_sideoffset;
#define v_sideoffset node_v_sideoffset->safedatafloat()[0]
TreeNode* node_v_animateskirt;
#define v_animateskirt node_v_animateskirt->safedatafloat()[0]

// c++ attributes
treenode cursection;

double cursecstartx;

double cursecstarty;

double cursecstartz;

double cursecstartangle;

double cursectype;

double cursecstartlength;

double curseclength;

double cursecrise;

double cursecangle;

double cursecradius;

double accummaxloc;

double drawangle;

Mesh legMesh;

Mesh photoeyeMesh;

Mesh conveyorMesh;

bool baseMeshBuilt;

double builtY;

double builtZ;

bool builtRelative;

treenode onConveyEndTrigger = nullptr;

treenode onCoverTrigger = nullptr;

treenode onUncoverTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// MergeSort
class MergeSort : public Conveyor
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export double onClick(treenode view, int code);

fs_content_export double onDraw(treenode view);

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double resetVariables();

fs_content_export double updatePortTables();

fs_content_export double updateLocations();

fs_content_export double setAllLocations(double updatetime);

fs_content_export double releaseItem(treenode item, int port);

fs_content_export double receiveItem(int port);

fs_content_export virtual double inOpenEvent(FixedResource* otherobject, int search, double port );

fs_content_export double drawInPort(int port);

fs_content_export double drawOutPort(int port);

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export virtual double onTransportInNotify(treenode item, int port);

fs_content_export double buildPortMesh();

TreeNode* node_v_inputtable;
#define v_inputtable node_v_inputtable->safedatafloat()[0]
TreeNode* node_v_outputtable;
#define v_outputtable node_v_outputtable->safedatafloat()[0]
TreeNode* node_v_sortedtable;
#define v_sortedtable node_v_sortedtable->safedatafloat()[0]
TreeNode* node_v_sendrequirement;
TreeNode* node_v_blocktime;
#define v_blocktime node_v_blocktime->safedatafloat()[0]
TreeNode* node_v_madeattempt;
#define v_madeattempt node_v_madeattempt->safedatafloat()[0]

// c++ attributes
Mesh inputMesh;

Mesh outputMesh;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// BasicConveyor
class BasicConveyor : public Conveyor
{
public:


// c++ member functions

fs_content_export inline treenode getMainItemKinematics(treenode item);

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export double onDraw(treenode view);

fs_content_export double resetVariables();

fs_content_export double updateLocations();

fs_content_export double setAllLocations();

fs_content_export double initItem(treenode item);

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export double setItemConveyState(treenode item, double startpoint, double startspeed, double targetspeed, double accdec);

fs_content_export double setConveyStatesByRange(double frompos, double topos, double startspeed, double targetspeed, double accdec);

fs_content_export double getDPsFromPosition(double position, double prodlength, double space, int* frontdp, int* backdp, int* backspacedp);

fs_content_export double onSpaceCleared(treenode item);

fs_content_export double createDPClearEvent(treenode item, int backedgetype);

fs_content_export double getItemPosition(treenode item);

fs_content_export double setDirection(int direction);

fs_content_export double updateAllPositions(int forceupdate DEFAULTZERO);

fs_content_export double resetKinematicsBehind(treenode item);

fs_content_export double getFilledLength();

fs_content_export virtual double getPickOffset(treenode involvedobj, treenode toobject, double* returnarray);

fs_content_export treenode getItemKinematics(treenode item, int kintype);

fs_content_export static char* showDPCacheInfo(treenode dpcache, int verbose);

fs_content_export static double getItemInfo(treenode item, int val);

fs_content_export double destroyItemEvent(treenode item, int event);

fs_content_export double cleanItemEvent(treenode item, int event);

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export double buildDecisionMesh();

fs_content_export virtual void bindEvents();

TreeNode* node_v_decisionpointtable;
#define v_decisionpointtable node_v_decisionpointtable->safedatafloat()[0]
TreeNode* node_v_dptablecache;
TreeNode* node_v_recycledkinematics;
#define v_recycledkinematics node_v_recycledkinematics->safedatafloat()[0]
TreeNode* node_v_recyclednodes;
#define v_recyclednodes node_v_recyclednodes->safedatafloat()[0]
TreeNode* node_v_direction;
#define v_direction node_v_direction->safedatafloat()[0]
TreeNode* node_v_lastupdatetime;
#define v_lastupdatetime node_v_lastupdatetime->safedatafloat()[0]
TreeNode* node_v_cleardpevents;
#define v_cleardpevents node_v_cleardpevents->safedatafloat()[0]
TreeNode* node_v_inactivecouplings;
#define v_inactivecouplings node_v_inactivecouplings->safedatafloat()[0]

// c++ attributes
struct dptableentry{int row; double position; bool spaceneeded; int coverstate;};;

treenode exitingitem;;

Mesh decisionPointMesh;

treenode stopResume = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// BasicFR
class BasicFR : public FixedResource
{
public:


// c++ member functions

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume(int id, int stateprofile DEFAULTZERO);

fs_content_export double onTransportInNotify(treenode item, int port);

fs_content_export double onTransportOutNotify(treenode item, int port);

fs_content_export double onTransportOutComplete(treenode item, int port, treenode transporter DEFAULTNULL);

fs_content_export double onTransportInComplete(treenode item, int port, treenode transporter DEFAULTNULL);

fs_content_export double getPickOffset(treenode item, treenode toobject, double* returnarray);

fs_content_export double getPlaceOffset(treenode item, treenode fromobject,  double* returnarray);

fs_content_export virtual unsigned int getClassType();

fs_content_export double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export double onClick(treenode view, int code);

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export double onStateChange(int toState, treenode stateProfile);

fs_content_export virtual void bindEvents();

TreeNode* node_v_poffsetx;
#define v_poffsetx node_v_poffsetx->safedatafloat()[0]
TreeNode* node_v_poffsety;
#define v_poffsety node_v_poffsety->safedatafloat()[0]
TreeNode* node_v_poffsetz;
#define v_poffsetz node_v_poffsetz->safedatafloat()[0]

// c++ attributes
treenode onStateChangeTrigger = nullptr;

treenode onTransportInNotifyCompleteTrigger = nullptr;

treenode onTransportOutNotifyCompleteTrigger = nullptr;

treenode onStopResumeTrigger = nullptr;

treenode onPickPlaceOffsetTrigger = nullptr;

treenode onAdvancedFunctionsTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Dispatcher
class Dispatcher : public FlexSimObject
{
public:


// c++ member functions

fs_content_export double onOutOpen(int port);

fs_content_export double onReset();

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export virtual double receiveTaskSequence(treenode newtasksequence);

fs_content_export virtual double finishUtilize(treenode involveditem);

fs_content_export double resetVariables();

fs_content_export double rankInOrder(treenode tasksequence);

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export void resume(int id, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

fs_content_export double reorder();

fs_content_export double rerankbest();

fs_content_export virtual treenode findBestTS();

fs_content_export virtual unsigned int getClassType();

fs_content_export double updateVersion(char* newversion, char* oldversion);

fs_content_export double executeTasks(treenode tasksequence);

fs_content_export double executeProxyTask(treenode curtask, Task* taskdata, Task* allocatetaskdata);

fs_content_export double finishProxyTask(treenode task, treenode executer);

fs_content_export double makeMultipleAllocations(treenode tasksequence, treenode alreadyallocatedtask);

fs_content_export double onAllocationNotify(treenode executer, treenode task);

fs_content_export inline double finishDeallocation(Task* taskdata, Task* allocatetaskdata, TaskSequence* tsdata);

fs_content_export static int recycleTaskSequence(treenode tasksequence);

fs_content_export double onDraw(treenode view);

fs_content_export virtual double onResourceAvailable(int port);

fs_content_export TaskSequenceArray __getTaskSequences();

fs_content_export virtual void bindEvents();

fs_content_export virtual void bindInterface();

TreeNode* node_v_tasksequencequeue;
#define v_tasksequencequeue node_v_tasksequencequeue->safedatafloat()[0]
TreeNode* node_v_coordinatedtasks;
#define v_coordinatedtasks node_v_coordinatedtasks->safedatafloat()[0]
TreeNode* node_v_passimmediately;
#define v_passimmediately node_v_passimmediately->safedatafloat()[0]
TreeNode* node_v_passto;
TreeNode* node_v_queuestrategy;

// c++ attributes
treenode onReceiveTSTrigger = nullptr;

treenode onResourceAvailableTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// TaskExecuter
class TaskExecuter : public Dispatcher
{
public:


//ClassIncludeHeaderStart
Vec3 offsetloc;
treenode activetask;
IndexedMesh spheresMesh;
double lastPickPlaceOffsetResult;
bool isPostLoadUnloadOffset = false;
bool isNotFirstOffset = false;

treenode onEntryTrigger = nullptr;
treenode onExitTrigger = nullptr;
treenode onLoadTrigger = nullptr;
treenode onUnloadTrigger = nullptr;
treenode onPreemptTrigger = nullptr;
treenode onStartTaskTrigger = nullptr;
treenode onFinishTaskTrigger = nullptr;

FS_CONTENT_DLL_FUNC virtual void bindInterface() override;
FS_CONTENT_DLL_FUNC virtual void bindVariables() override;
FS_CONTENT_DLL_FUNC virtual void bind() override;

FS_CONTENT_DLL_FUNC double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO) override;

FS_CONTENT_DLL_FUNC double onReset() override;

FS_CONTENT_DLL_FUNC  TaskExecuter();

FS_CONTENT_DLL_FUNC double onTimerEvent(treenode involved, int code, char *datastr) override;

FS_CONTENT_DLL_FUNC double onDraw(treenode view) override;

FS_CONTENT_DLL_FUNC double onReceive(treenode item, int port) override;

FS_CONTENT_DLL_FUNC double onSend(treenode item, int port) override;

FS_CONTENT_DLL_FUNC virtual double onDestinationArrival(double finalspeed);

FS_CONTENT_DLL_FUNC virtual double receiveTaskSequence(treenode newts) override;

FS_CONTENT_DLL_FUNC double cleanupAbortedTS(treenode ts);

FS_CONTENT_DLL_FUNC virtual double beginTask(treenode task);

FS_CONTENT_DLL_FUNC virtual double beginLoadUnloadTask(treenode task, int isLoad, int eventCode, char* eventName, int logId);

FS_CONTENT_DLL_FUNC virtual void finishLoadUnloadTask(treenode task, bool isLoad, treenode involvedItem, treenode involvedStation);

FS_CONTENT_DLL_FUNC virtual double finishTask(treenode task);

FS_CONTENT_DLL_FUNC double resetVariables();

FS_CONTENT_DLL_FUNC virtual double getEntryLoc(treenode involved,  double* returnarray);

FS_CONTENT_DLL_FUNC double offsetByNavigator(double endSpeed);

FS_CONTENT_DLL_FUNC virtual double beginOffset(double endspeed, treenode item);

FS_CONTENT_DLL_FUNC virtual double beginOffsetDefault(double endspeed, treenode item);

FS_CONTENT_DLL_FUNC virtual double updateOffset();

FS_CONTENT_DLL_FUNC virtual double finishOffset();

FS_CONTENT_DLL_FUNC treenode  findDefaultNavigator();

FS_CONTENT_DLL_FUNC virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO) override;

FS_CONTENT_DLL_FUNC void resume(int id, int stateprofile DEFAULTZERO) override;

FS_CONTENT_DLL_FUNC virtual void resume() override;

FS_CONTENT_DLL_FUNC virtual double preemptActive(treenode task, treenode activets, int preempttype, treenode newts);

FS_CONTENT_DLL_FUNC static treenode findNextDurativeTask(treenode tasksequencenode, int alloctaskrank DEFAULTZERO);

FS_CONTENT_DLL_FUNC virtual double onPreempt();

FS_CONTENT_DLL_FUNC virtual double updateLocations() override;

FS_CONTENT_DLL_FUNC virtual unsigned int getClassType() override;

FS_CONTENT_DLL_FUNC virtual double reassignNetNode(NetworkNode* netnode);

FS_CONTENT_DLL_FUNC virtual double getPlaceOffset(treenode involvedobj, treenode fromobject,  double* returnarray) override;

FS_CONTENT_DLL_FUNC virtual double getPickOffset(treenode item, treenode toobject, double* returnarray) override;

FS_CONTENT_DLL_FUNC double saveState() override;

FS_CONTENT_DLL_FUNC double loadState() override;

FS_CONTENT_DLL_FUNC double queryDistance(FlexSimObject* destination);

FS_CONTENT_DLL_FUNC double resumeLoad(treenode fromstation);

FS_CONTENT_DLL_FUNC double resumeUnload(treenode tostation);

FS_CONTENT_DLL_FUNC double setCollisionCheck(int val, double interval);

FS_CONTENT_DLL_FUNC double drawSpheres(treenode view, double * drawcolor);

FS_CONTENT_DLL_FUNC double catchTaskError(treenode task);

FS_CONTENT_DLL_FUNC virtual int checkCollisions() override;

FS_CONTENT_DLL_FUNC double setObjectInfo();

FS_CONTENT_DLL_FUNC virtual void onBeginTask(treenode task);

FS_CONTENT_DLL_FUNC virtual void onEndTask(treenode task);

FS_CONTENT_DLL_FUNC virtual void onOffsetFinishNotify();

FS_CONTENT_DLL_FUNC virtual double onResourceAvailable(int port) override;

FS_CONTENT_DLL_FUNC virtual double onStartSimulation() override;

FS_CONTENT_DLL_FUNC virtual double onDestroy(treenode view) override;

FS_CONTENT_DLL_FUNC virtual void bindEvents() override;

FS_CONTENT_DLL_FUNC virtual void bindStatistics() override;

FS_CONTENT_DLL_FUNC virtual bool canRotateOnIncline();

FS_CONTENT_DLL_FUNC TaskSequence* __getActiveTaskSequence();

FS_CONTENT_DLL_FUNC Task* __getActiveTask();

FS_CONTENT_DLL_FUNC void updateTotalTravelDist(double value);

FS_CONTENT_DLL_FUNC virtual double getTotalTravelDistance();

Variant getTotalTravelDistance(FLEXSIMINTERFACE) { return getTotalTravelDistance(); }

//ClassIncludeHeaderEnd

// c++ member functions

TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_loadtime;
#define v_loadtime node_v_loadtime->safedatafloat()[0]
TreeNode* node_v_unloadtime;
#define v_unloadtime node_v_unloadtime->safedatafloat()[0]
TreeNode* node_v_maxspeed;
#define v_maxspeed node_v_maxspeed->safedatafloat()[0]
TreeNode* node_v_acceleration;
#define v_acceleration node_v_acceleration->safedatafloat()[0]
TreeNode* node_v_deceleration;
#define v_deceleration node_v_deceleration->safedatafloat()[0]
TreeNode* node_v_navigator;
#define v_navigator node_v_navigator->safedatafloat()[0]
TreeNode* node_v_breakto;
TreeNode* node_v_modifyrotation;
#define v_modifyrotation node_v_modifyrotation->safedatafloat()[0]
TreeNode* node_v_useoffsets;
#define v_useoffsets node_v_useoffsets->safedatafloat()[0]
TreeNode* node_v_offsettingnow;
#define v_offsettingnow node_v_offsettingnow->safedatafloat()[0]
TreeNode* node_v_offsetbegintime;
#define v_offsetbegintime node_v_offsetbegintime->safedatafloat()[0]
TreeNode* node_v_offsettotaltime;
#define v_offsettotaltime node_v_offsettotaltime->safedatafloat()[0]
TreeNode* node_v_loadedspeed;
#define v_loadedspeed node_v_loadedspeed->safedatafloat()[0]
TreeNode* node_v_emptyspeed;
#define v_emptyspeed node_v_emptyspeed->safedatafloat()[0]
TreeNode* node_v_curloadunloadtime;
#define v_curloadunloadtime node_v_curloadunloadtime->safedatafloat()[0]
TreeNode* node_v_lastupdatedspeed;
#define v_lastupdatedspeed node_v_lastupdatedspeed->safedatafloat()[0]
TreeNode* node_v_travelvstart;
#define v_travelvstart node_v_travelvstart->safedatafloat()[0]
TreeNode* node_v_travelvend;
#define v_travelvend node_v_travelvend->safedatafloat()[0]
TreeNode* node_v_lastspeedupdatetime;
#define v_lastspeedupdatetime node_v_lastspeedupdatetime->safedatafloat()[0]
TreeNode* node_v_collisiontrigger;
TreeNode* node_v_collcheckinterval;
#define v_collcheckinterval node_v_collcheckinterval->safedatafloat()[0]
TreeNode* node_v_drawcollspheres;
#define v_drawcollspheres node_v_drawcollspheres->safedatafloat()[0]
TreeNode* node_v_incollision;
#define v_incollision node_v_incollision->safedatafloat()[0]
TreeNode* node_v_collcheckstate;
#define v_collcheckstate node_v_collcheckstate->safedatafloat()[0]
TreeNode* node_v_totaltraveldist;
TreeNode* node_v_kinematics;
TreeNode* node_v_flipthreshold;
#define v_flipthreshold node_v_flipthreshold->safedatafloat()[0]
TreeNode* node_v_availableonstart;
#define v_availableonstart node_v_availableonstart->safedatafloat()[0]
TreeNode* node_v_activetasksequence;
#define v_activetasksequence node_v_activetasksequence->safedatafloat()[0]
TreeNode* node_v_resetposition;
#define v_resetposition node_v_resetposition->safedatafloat()[0]

// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// Operator
class Operator : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onReset();

fs_content_export double beginOffset(double endspeed, treenode item);

fs_content_export double finishOffset();

fs_content_export double resetVariables();

fs_content_export virtual void onBeginTask(treenode task);

fs_content_export virtual void onEndTask(treenode task);

fs_content_export virtual double getEntryLoc(treenode involved,  double* returnarray);

fs_content_export virtual bool canRotateOnIncline();

fs_content_export virtual double onPreDraw(treenode view);

fs_content_export void bindVariables();

TreeNode* node_v_activeRoles;
#define v_activeRoles node_v_activeRoles->safedatafloat()[0]
TreeNode* node_v_currentLocation;
TreeNode* node_v_idleAnimation;
TreeNode* node_v_walkAnimation;
TreeNode* node_v_walkLoadedAnimation;

// c++ attributes
bool doUpdateAnimation = true;


// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// Transporter
class Transporter : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onPreDraw(treenode view);

fs_content_export double onReset();

fs_content_export double getForkHeight();

fs_content_export double beginOffset(double endspeed,treenode item);

fs_content_export double finishOffset();

fs_content_export double resetVariables();

fs_content_export virtual double beginTask(treenode task);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export virtual void onBeginTask(treenode task);

fs_content_export virtual double updateOffset();

fs_content_export virtual double getEntryLoc(treenode involved,  double* returnarray);

TreeNode* node_v_forkspeed;
#define v_forkspeed node_v_forkspeed->safedatafloat()[0]
TreeNode* node_v_forkinitialheight;
#define v_forkinitialheight node_v_forkinitialheight->safedatafloat()[0]
TreeNode* node_v_forkdestheight;
#define v_forkdestheight node_v_forkdestheight->safedatafloat()[0]
TreeNode* node_v_forkbegintime;
#define v_forkbegintime node_v_forkbegintime->safedatafloat()[0]
TreeNode* node_v_forktravel;
#define v_forktravel node_v_forktravel->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Elevator
class Elevator : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onClick(treenode view, int code);

fs_content_export virtual double beginOffset(double endspeed, treenode item);

fs_content_export virtual double updateOffset();

fs_content_export virtual double getEntryLoc(treenode involvedobj,  double* returnarray);

fs_content_export virtual double updateLocations();

fs_content_export double scaleComponents();

fs_content_export double onDraw(treenode view);

fs_content_export virtual double onDrag(treenode view);

fs_content_export virtual bool canRotateOnIncline();

TreeNode* node_v_shellzloc;
#define v_shellzloc node_v_shellzloc->safedatafloat()[0]
TreeNode* node_v_xconvey;
#define v_xconvey node_v_xconvey->safedatafloat()[0]

// c++ attributes
double lastzloc;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Robot
class Robot : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onSend(treenode item, int port);

fs_content_export double beginOffset(double endspeed, treenode item);

fs_content_export double updateOffset();

fs_content_export double resetVariables();

fs_content_export double updateVersion(char* newversion, char* oldversion);

fs_content_export double moveArm(treenode item, int pathnum, int endrow) ;

fs_content_export double onPreDraw(treenode view);

fs_content_export double onDraw(treenode view);

fs_content_export double drawSkeleton(treenode view, double* d, double* a, double xtrans);

fs_content_export double autoCalculateTable(double* d, double * a, double * xtrans);

fs_content_export double applyJointsToItem(int orientationType);

fs_content_export double applyItemToJoints(int orientationType);

fs_content_export double calcApproachOffsetDist(treenode item, int orientationType);

fs_content_export Vec3 calcApproachOffsetRot(int orientationType);

fs_content_export Vec3 calcItemRot(int orientationType);

fs_content_export double calcClampWidth(treenode item, int orientationType);

fs_content_export virtual bool canRotateOnIncline();

TreeNode* node_v_motionmethod;
#define v_motionmethod node_v_motionmethod->safedatafloat()[0]
TreeNode* node_v_extensionspeed;
#define v_extensionspeed node_v_extensionspeed->safedatafloat()[0]
TreeNode* node_v_rotationspeed;
#define v_rotationspeed node_v_rotationspeed->safedatafloat()[0]
TreeNode* node_v_yrotspeed;
#define v_yrotspeed node_v_yrotspeed->safedatafloat()[0]
TreeNode* node_v_robotkinematics;
#define v_robotkinematics node_v_robotkinematics->safedatafloat()[0]
TreeNode* node_v_clamporientation;
#define v_clamporientation node_v_clamporientation->safedatafloat()[0]
TreeNode* node_v_clampwidth;
#define v_clampwidth node_v_clampwidth->safedatafloat()[0]
TreeNode* node_v_lastpathnum;
#define v_lastpathnum node_v_lastpathnum->safedatafloat()[0]
TreeNode* node_v_nextpathselected;
#define v_nextpathselected node_v_nextpathselected->safedatafloat()[0]
TreeNode* node_v_pathtables;
#define v_pathtables node_v_pathtables->safedatafloat()[0]
TreeNode* node_v_movetime;
TreeNode* node_v_speedtable;
#define v_speedtable node_v_speedtable->safedatafloat()[0]

// c++ attributes

static const int CLAMP_Z_BY_X = 1;
static const int CLAMP_Z_BY_Y = 2;
static const int CLAMP_Z_NEG_BY_X = 3;
static const int CLAMP_Z_NEG_BY_Y = 4;
static const int CLAMP_Y_BY_Z = 5;
static const int CLAMP_Y_BY_X = 6;
static const int CLAMP_Y_NEG_BY_Z = 7;
static const int CLAMP_Y_NEG_BY_X = 8;
static const int CLAMP_X_BY_Y = 9;
static const int CLAMP_X_BY_Z = 10;
static const int CLAMP_X_NEG_BY_Y = 11;
static const int CLAMP_X_NEG_BY_Z = 12;



static const int MOTION_METHOD_SIMPLE = 1;
static const int MOTION_METHOD_MOVE_TIME = 2;
static const int MOTION_METHOD_SPEEDS = 3;
static const int MOTION_METHOD_PATHS = 4;



static const int PATH_CYCLETIME = 1;
static const int PATH_TABLE = 2;
static const int PATH_CLOSE_CLAMP_TIME = 3;
static const int PATH_OPEN_CLAMP_TIME = 4;
static const int PATH_NEXT_PATH = 5;
static const int PATH_CLAMP_ORIENTATION = 6;



// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// Crane
class Crane : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onReset();

fs_content_export double onDraw(treenode view);

fs_content_export virtual double getEntryLoc(treenode involvedobj,  double* returnarray);

fs_content_export virtual double beginOffset(double endspeed, treenode item);

fs_content_export virtual double updateOffset();

fs_content_export double finishOffset();

fs_content_export virtual double updateLocations();

fs_content_export double resetVariables();

fs_content_export virtual double updateVersion(char* newversion, char* oldversion);

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export virtual double rotateAroundAxis(double angle, double x, double y);

fs_content_export virtual double flipAroundAxis(const Vec2& point1, const Vec2& point2);

fs_content_export virtual double onDrag(treenode view);

fs_content_export virtual double onClick(treenode view, int code);

fs_content_export double scaleComponents(int picktype, double newsize);

fs_content_export virtual bool canRotateOnIncline();

fs_content_export virtual double getTotalTravelDistance();

TreeNode* node_v_shellxloc;
#define v_shellxloc node_v_shellxloc->safedatafloat()[0]
TreeNode* node_v_shellyloc;
#define v_shellyloc node_v_shellyloc->safedatafloat()[0]
TreeNode* node_v_shellzloc;
#define v_shellzloc node_v_shellzloc->safedatafloat()[0]
TreeNode* node_v_moving;
#define v_moving node_v_moving->safedatafloat()[0]
TreeNode* node_v_liftheight;
#define v_liftheight node_v_liftheight->safedatafloat()[0]
TreeNode* node_v_travelsequence;
TreeNode* node_v_cranespeeds;
#define v_cranespeeds node_v_cranespeeds->safedatafloat()[0]
TreeNode* node_v_cranekinematics;
TreeNode* node_v_liftradius;
#define v_liftradius node_v_liftradius->safedatafloat()[0]

// c++ attributes
double lastxloc;

double lastyloc;

double lastzloc;

double justcreated;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// ASRSvehicle
class ASRSvehicle : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double onDraw(treenode view);

fs_content_export double onReset();

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double getForkHeight();

fs_content_export double beginOffset(double endspeed, treenode item);

fs_content_export double finishOffset();

fs_content_export double updateOffset();

fs_content_export double resetVariables();

fs_content_export double getEntryLoc(treenode involvedobj,  double* returnarray);

fs_content_export virtual double onDrag(treenode view);

fs_content_export virtual double onClick(treenode view, int code);

fs_content_export double scaleComponents();

fs_content_export virtual bool canRotateOnIncline();

fs_content_export virtual double getTotalTravelDistance();

TreeNode* node_v_forkspeed;
#define v_forkspeed node_v_forkspeed->safedatafloat()[0]
TreeNode* node_v_forkinitialheight;
#define v_forkinitialheight node_v_forkinitialheight->safedatafloat()[0]
TreeNode* node_v_forkkinematics;
TreeNode* node_v_yconvey;
#define v_yconvey node_v_yconvey->safedatafloat()[0]
TreeNode* node_v_forkresetheight;
#define v_forkresetheight node_v_forkresetheight->safedatafloat()[0]
TreeNode* node_v_railx;
#define v_railx node_v_railx->safedatafloat()[0]
TreeNode* node_v_raily;
#define v_raily node_v_raily->safedatafloat()[0]
TreeNode* node_v_railz;
#define v_railz node_v_railz->safedatafloat()[0]
TreeNode* node_v_extensionspeed;
#define v_extensionspeed node_v_extensionspeed->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// BasicTE
class BasicTE : public TaskExecuter
{
public:


// c++ member functions

fs_content_export double beginOffset(double endspeed, treenode item);

fs_content_export double updateOffset();

fs_content_export double finishOffset();

fs_content_export double getPickOffset(treenode item, treenode toobject, double* returnarray);

fs_content_export double getPlaceOffset(treenode item, treenode fromobject,  double* returnarray);

fs_content_export void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume(int id, int stateprofile DEFAULTZERO);

fs_content_export virtual unsigned int getClassType();

fs_content_export double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export double onClick(treenode view, int code);

fs_content_export virtual double onPreempt();

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export double onStateChange(int toState, treenode stateProfile);

fs_content_export virtual void bindEvents();

TreeNode* node_v_poffsetx;
#define v_poffsetx node_v_poffsetx->safedatafloat()[0]
TreeNode* node_v_poffsety;
#define v_poffsety node_v_poffsety->safedatafloat()[0]
TreeNode* node_v_poffsetz;
#define v_poffsetz node_v_poffsetz->safedatafloat()[0]

// c++ attributes
treenode statechange = nullptr;

treenode onbeginoffset = nullptr;

treenode onupdateoffset = nullptr;

treenode onfinishoffset = nullptr;

treenode pickplaceoffset = nullptr;

treenode stopresume = nullptr;

treenode advancedfunctions = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// NetworkNode
class NetworkNode : public FlexSimObject
{
public:


//ClassIncludeHeaderStart
static Mesh pointMesh;
static Mesh selectionMesh;
static Mesh utilityMesh;
static bool staticMeshesBuilt;
bool isMeshDirty;
int meshEdgePointSplit;
int meshEnd;
Mesh mesh;
Mesh arrowMesh;
double meshCheckSum;
treenode onArrivalTrigger = nullptr;
treenode onEntryTrigger = nullptr;
static const int PICK_NET_NODE_EDGE = 1;
static const int PICK_NET_NODE_SPLINE_POINT = 2;


class Edge: public CouplingDataType
{
public:
	Edge() : isInputOpen(false), distance(0.0), filledLength(0.0), lastExitTime(0.0), lastExitSize(0.0), 
					lastEntryPort(0), spacing(0.0), isSplineOwner(false), maxSpeed(0.0), userDistance(0.0), splineEndRot(0.0), blockedLength(0.0),
					activeTravelersNode(0), entryRequestsNode(0), spline(0), arrowMeshIndex(0)
		{}
	NetworkNode* netNode;
	double isOpen;
	treenode insideCoupling;

	// connectionType: one of: EDGE_NOCONNECTION EDGE_PASSING EDGE_NONPASSING
	double connectionType;
	bool isInputOpen;
	double distance;
	double filledLength;
	treenode activeTravelersNode;
	NodeListArray<NetworkRequest>::SdtSubNodeType activeTravelers;
	treenode entryRequestsNode;
	NodeListArray<>::NodePtrType entryRequests;
	double lastExitTime;
	double lastExitSize;
	int lastEntryPort;
	double spacing;
	bool isSplineOwner;
	treenode spline;
	double maxSpeed;
	double userDistance;
	double splineEndRot;
	double blockedLength;
	int arrowMeshIndex;
	int splinePointIndex;
	static const int arrowNrVerts = 12;
	
	fs_content_export Edge* getEdgePartner();
	fs_content_export NetworkNode* getNetNodePartner();
	fs_content_export TreeNode* getSplineHead() {return first(isSplineOwner ? spline : getEdgePartner()->spline);}
	fs_content_export TreeNode* getNearSplinePoint() {return isSplineOwner ? first(spline) : last(getEdgePartner()->spline);}
	fs_content_export TreeNode* getFarSplinePoint() {return isSplineOwner ? last(spline) : first(getEdgePartner()->spline);}
	fs_content_export virtual const char* getClassFactory() {return "NetNodeEdge";}
	fs_content_export virtual void bind();
	fs_content_export void init(char connectionType, bool isSplineOwner);
	fs_content_export virtual void reset(treenode returnTravelersTo);
	// buildMesh: adds the edge's vertices to the mesh. Here I pass a void* instead of a vector<Vec3f> because I don't want allobjects.h to 
	// include <vector> (modules must include allobjects.h, so I don't want to force <vector> upon them)
	fs_content_export void buildMeshEdges(Mesh& mesh, bool includeSplineLines);
	fs_content_export void buildMeshPoints(Mesh& mesh);
	fs_content_export void buildMeshQuads(Mesh& mesh);
};

NodeListArray<Edge>::CouplingSdtSubNodeType edges;

//ClassIncludeHeaderEnd

// c++ member functions

fs_content_export  NetworkNode();

fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onDraw(treenode view);

fs_content_export double onDrag(treenode view);

fs_content_export double onPreDraw(treenode view);

fs_content_export double onDrawPlanar(treenode view);

fs_content_export double onReset();

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export treenode onMenuPopup(treenode view, treenode theMenu);

fs_content_export double setViewMode(int viewMode);

fs_content_export double onClick(treenode view, int code);

fs_content_export double onDestroy(treenode view);

fs_content_export virtual double onReceiveTraveler(treenode reqnode, int port, int beginning, int lastport);

fs_content_export virtual double onSendTraveler(treenode reqnode, int nextport);

fs_content_export virtual double releaseTraveler(treenode reqnode);

fs_content_export virtual double receiveTraveler(int port);

fs_content_export virtual double receiveInputRequest(treenode reqnode, int port, int lastport);

fs_content_export static int pushTraveler(treenode reqnode, NetworkNode* tonetnode, int nextport);

fs_content_export virtual double isTrafficControlMember(treenode tcontroller);

fs_content_export static int resumePushTraveler(treenode reqnode, NetworkNode* tonetnode, int nextport);

fs_content_export virtual double onTravelInNotify(treenode reqnode, int port);

fs_content_export virtual double getSplinePos(int port, double perc, double * returnloc);

fs_content_export virtual double getPlaceOffset(treenode traveler, treenode reqnode,  int port, double* returnarray);

fs_content_export virtual double updateData();

fs_content_export virtual double getBurden(int outport);

fs_content_export virtual double getEdgeSpeedLimit(int outport);

fs_content_export virtual double dragConnection(treenode toObj, char characterpressed, unsigned int classtype);

fs_content_export virtual NetworkNode::Edge* addEdge(NetworkNode* otherNode, int toType, int backType, bool curved);

fs_content_export virtual NetworkNode::Edge* createNewEdge();

fs_content_export double resetVariables();

fs_content_export double toggleShowMode(int newmode);

fs_content_export virtual double abortTravel(treenode reqnode);

fs_content_export virtual double deleteInRequest(treenode reqnode, int searchallports DEFAULTZERO);

fs_content_export virtual double updateLocations();

fs_content_export double invalidateSpline(int port);

fs_content_export NetworkNavigator* checkNetwork(int changename DEFAULTZERO);

fs_content_export virtual char* getNavigatorName();

fs_content_export unsigned int getClassType();

fs_content_export double userCloseEdge(int portnum);

fs_content_export double userOpenEdge(int portnum);

fs_content_export virtual double updateVersion(char* newversion, char* oldversion);

fs_content_export double saveState();

fs_content_export double loadState();

fs_content_export virtual double validateData(int notifyuser DEFAULTONE);

fs_content_export virtual double rotateAroundAxis(double angle, double x, double y);

fs_content_export virtual double flipAroundAxis(const Vec2& point1, const Vec2& point2);

fs_content_export double buildStaticMeshes();

fs_content_export double buildMesh();

fs_content_export virtual void bindVariables();

fs_content_export virtual void setEdgeType(treenode edge, int type);

fs_content_export virtual void setEdgeGeomType(treenode edgeNode, bool straight);

fs_content_export double addSplineAtts(treenode obj);

fs_content_export virtual void bindEvents();

TreeNode* node_v_network;
#define v_network node_v_network->safedatafloat()[0]
TreeNode* node_v_travellers;
#define v_travellers node_v_travellers->safedatafloat()[0]
TreeNode* node_v_activetravellers;
#define v_activetravellers node_v_activetravellers->safedatafloat()[0]
TreeNode* node_v_stations;
#define v_stations node_v_stations->safedatafloat()[0]
TreeNode* node_v_showmode;
#define v_showmode node_v_showmode->safedatafloat()[0]
TreeNode* node_v_maxinactive;
#define v_maxinactive node_v_maxinactive->safedatafloat()[0]
TreeNode* node_v_lastxloc;
#define v_lastxloc node_v_lastxloc->safedatafloat()[0]
TreeNode* node_v_lastyloc;
#define v_lastyloc node_v_lastyloc->safedatafloat()[0]
TreeNode* node_v_lastzloc;
#define v_lastzloc node_v_lastzloc->safedatafloat()[0]
TreeNode* node_v_showme;
#define v_showme node_v_showme->safedatafloat()[0]
TreeNode* node_v_lastupdatetime;
#define v_lastupdatetime node_v_lastupdatetime->safedatafloat()[0]
TreeNode* node_v_clicked;
#define v_clicked node_v_clicked->safedatafloat()[0]
TreeNode* node_v_sideoffset;
#define v_sideoffset node_v_sideoffset->safedatafloat()[0]
TreeNode* node_v_disttosideoffset;
#define v_disttosideoffset node_v_disttosideoffset->safedatafloat()[0]
TreeNode* node_v_trafficcontrollers;
#define v_trafficcontrollers node_v_trafficcontrollers->safedatafloat()[0]
TreeNode* node_v_virtualexits;
#define v_virtualexits node_v_virtualexits->safedatafloat()[0]
TreeNode* node_v_notifyofblockedlength;
#define v_notifyofblockedlength node_v_notifyofblockedlength->safedatafloat()[0]

// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// TrafficControl
class TrafficControl : public FlexSimObject
{
public:


// c++ member functions

fs_content_export double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double requestEntry(treenode reqnode, NetworkNode* tonetnode, int nextport, int fromrank, int torank);

fs_content_export virtual double leaveArea(treenode reqnode, treenode networknode);

fs_content_export virtual double searchModeTable(int fromrank, int torank);

fs_content_export virtual double findDifferentTableMatch(int fromrank, int torank);

fs_content_export virtual double allowNewRequests();

fs_content_export virtual double checkRowForConnection(int row, int fromrank, int torank);

fs_content_export double modeError(int fromrank, int torank);

fs_content_export unsigned int getClassType();

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export virtual double forceReceive(treenode reqnode, treenode netnode);

fs_content_export virtual double abortRequest(treenode reqnode);

fs_content_export double onDraw(treenode view);

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export double saveState();

fs_content_export double loadState();

fs_content_export static float saveTCRequestState(treenode reqnode);

fs_content_export static float loadTCRequestState(treenode reqnode);

fs_content_export virtual double getSpeedMultiple();

fs_content_export virtual double copyVariables(treenode otherobject);

fs_content_export virtual double info(int info, double _a, double _b);

fs_content_export virtual void bindEvents();

TreeNode* node_v_requests;
#define v_requests node_v_requests->safedatafloat()[0]
TreeNode* node_v_numberactive;
#define v_numberactive node_v_numberactive->safedatafloat()[0]
TreeNode* node_v_maxactive;
#define v_maxactive node_v_maxactive->safedatafloat()[0]
TreeNode* node_v_controlmode;
#define v_controlmode node_v_controlmode->safedatafloat()[0]
TreeNode* node_v_netnodemembers;
#define v_netnodemembers node_v_netnodemembers->safedatafloat()[0]
TreeNode* node_v_modetable;
#define v_modetable node_v_modetable->safedatafloat()[0]
TreeNode* node_v_curtablemode;
#define v_curtablemode node_v_curtablemode->safedatafloat()[0]
TreeNode* node_v_searchbestmode;
#define v_searchbestmode node_v_searchbestmode->safedatafloat()[0]
TreeNode* node_v_speedtable;
#define v_speedtable node_v_speedtable->safedatafloat()[0]

// c++ attributes
struct travelrequest{treenode requester;short opnum; short fromnode; short destnode; treenode traveldata;};

int matchingcolumn;

treenode onEntryTrigger = nullptr;

treenode onExitTrigger = nullptr;

treenode onRequestTrigger = nullptr;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// StorageSystem
class StorageSystem : public FlexSimEventHandler
{
public:


//ClassIncludeHeaderStart
	  
fs_content_export StorageSystem() : slots(this) {}
fs_content_export ~StorageSystem();
fs_content_export static StorageSystem* getInstance() { return StorageSystem::instance; }
static StorageSystem* instance;

class AddressMapping;

/// <summary>	Represents a integer-ized slot address.</summary>
/// <remarks>	  Addresses can be either "mapped" or "raw". Address provides 
/// 			  conversions between "raw" and "mapped".</remarks>
class fs_content_export Address {
public:
	Address() : storageObject(nullptr), isMapped(false) {}
	Address(StorageObject* storageObject, int bay, int level, int slot, bool isMapped)
		: storageObject(storageObject), bay(bay), level(level), slot(slot), isMapped(isMapped)
	{}
	StorageObject* storageObject;
	int bay;
	int level;
	int slot;
	bool isMapped;
	Address getRaw(const AddressMapping& mapping) const;
	Address getMapped(const AddressMapping& mapping) const;
	Address getRaw() const;
	Address getMapped() const;
	std::string toString() const;
	Variant getZoneID() const;
	Variant getAisleID() const;
	Variant getBayID() const;
	Variant getLevelID() const;
	Variant getSlotID() const;
	bool operator < (const Address& other);
};

class AddressScheme : public SimpleDataType {
public:
	virtual const char* getClassFactory() override { return "StorageSystemAddressScheme"; }
	fs_content_export virtual void bind() override;

	class Element : public SimpleDataType {
	public:
		virtual const char* getClassFactory() override { return "StorageSystemAddressSchemeElement"; }
		fs_content_export virtual void bind() override;
		static const int TEXT = 0;
		static const int ZONE_ID = 1;
		static const int AISLE_ID = 2;
		static const int BAY_ID = 3;
		static const int LEVEL_ID = 4;
		static const int SLOT_ID = 5;
		double scope = 0;

		static const int NUMBER = 1;
		static const int LETTER = 2;
		static const int ARBITRARY = 3;
		double format = 0;

		double isFixedLength = 1;
		double fixedLength = 1;
		ByteBlock text;
		ByteBlock fillerText;
		string getExampleText();
		StorageSystem* __getSystem() { return holder->ownerObject->objectAs(StorageSystem); }
		__declspec(property(get = __getSystem)) StorageSystem* system;
		AddressScheme* __getScheme() { return holder->up->up->objectAs(AddressScheme); }
		__declspec(property(get = __getScheme)) AddressScheme* scheme;

		fs_content_export bool isValidChar(char c);

		const char* parseBegin;
		const char* parseEnd;

		/// <summary>	Parses the given text. </summary>
		/// <param name="text">	The text to parse. In/out parameter. It will be progressed 
		/// 					to the start of the next token at the end of the parse if 
		/// 					successful.</param>
		/// <returns>	True if it succeeds, false if it fails. </returns>
		fs_content_export bool parse(const char*& text);

		/// <summary>	Resolves the last parsed text to a number. </summary>
		/// <remarks>	This should be called after a successful call to parse(), if 
		/// 			the scope is a bay, level, or slot. </remarks>
		/// <returns>	The resolved number value. </returns>
		fs_content_export int resolveNumber();

		void formatAddress(std::string& outStr, const Address& addr);
		std::string getScopeStr();
	};

	NodeListArray<Element>::SdtSubNodeBindingType elements;
	StorageSystem* __getSystem() { return holder->ownerObject->objectAs(StorageSystem); }
	__declspec(property(get = __getSystem)) StorageSystem* system;

	StorageObject* findMemberObject();
	fs_content_export Variant getExampleText();
	Variant getExampleText(FLEXSIMINTERFACE) { return getExampleText(); }

	fs_content_export bool isMatch(const char* text);
	fs_content_export Variant isSequenceValid();
	Variant isSequenceValid(FLEXSIMINTERFACE) { return isSequenceValid(); }
	fs_content_export std::pair<bool, Address> parseAddress(const char* address);
	fs_content_export void formatAddress(std::string& outStr, const Address& addr);
	fs_content_export Variant getID(int scope, int numVal, const Address& addr, bool forceString = false);
	fs_content_export Variant getID(int scope, int numVal, bool forceString = false);
	fs_content_export Variant getBayID(FLEXSIMINTERFACE) { return getID(Element::BAY_ID, (int)param(1), (int)param(2)); }
	fs_content_export Variant getLevelID(FLEXSIMINTERFACE) { return getID(Element::LEVEL_ID, (int)param(1), (int)param(2)); }
	fs_content_export Variant getSlotID(FLEXSIMINTERFACE) { return getID(Element::SLOT_ID, (int)param(1), (int)param(2)); }

	fs_content_export int getNum(int scope, const char* id);
	fs_content_export int getBayNum(const char* id) { return getNum(Element::BAY_ID, id); }
	fs_content_export int getLevelNum(const char* id) { return getNum(Element::LEVEL_ID, id); }
	fs_content_export int getSlotNum(const char* id) { return getNum(Element::SLOT_ID, id); }
	fs_content_export Variant getBayNum(FLEXSIMINTERFACE) { return getNum(Element::BAY_ID, param(1).c_str()); }
	fs_content_export Variant getLevelNum(FLEXSIMINTERFACE) { return getNum(Element::LEVEL_ID, param(1).c_str()); }
	fs_content_export Variant getSlotNum(FLEXSIMINTERFACE) { return getNum(Element::SLOT_ID, param(1).c_str()); }

	string assertValidText(int scope, const char* original);
	fs_content_export Variant assertValidText(FLEXSIMINTERFACE) { return assertValidText(param(1), param(2).c_str()); }

	fs_content_export void onReset();
	fs_content_export Element* addElement(int scope);
	fs_content_export Variant addElement(FLEXSIMINTERFACE) { return addElement(param(1))->holder; }

	fs_content_export Element* getElementByScope(int scope);

	struct Hash
	{
		size_t operator()(const std::pair<string, string>& val) const {
			return std::hash<string>()(val.first) ^ std::hash<string>()(val.first);
		}
	};
	std::unordered_multimap<std::pair<string, string>, StorageObject*, Hash> objectIndex;
};

/// <summary>	Defines the data needed to apply a mapping from "raw" bay/level/slot 
/// 			coordinates to "mapped" coordinates.</summary>
///
/// <remarks>	 Each storage object owns an address mapping, and the various values 
/// 			 are defined by the user.</remarks>
class AddressMapping {
public:
	StorageObject & storageObject;
	AddressMapping(StorageObject& storageObject) : storageObject(storageObject) {}
	double startBay;
	double bayStride;
	double startLevel;
	double levelStride;
	double startSlot;
	double slotStride;
	fs_content_export void bindVariables();
};

class AbstractSlot : public SimpleDataType {
public:
	static const int STOP_AT_LEVEL_END = 1;
	static const int STOP_AT_BAY_END = 2;
	static const int STOP_AT_OBJECT_END = 3;
	static const int STOP_AT_SYSTEM_END = 4;
	struct Iterator {
		Iterator(AbstractSlot* slot, int stopPoint = STOP_AT_SYSTEM_END) : slot(slot), stopPoint(stopPoint) {}
		bool operator == (const Iterator& other) const { return other.slot == slot; }
		bool operator != (const Iterator& other) const { return other.slot != slot; }
		Iterator& operator++();
		Iterator operator++(int) { Iterator copy = *this; operator++(); return copy; }
		AbstractSlot* slot;
		AbstractSlot* operator *() { return slot; }
		int stopPoint;
	};
};

struct Slots {
	StorageSystem* system;
	Slots(StorageSystem* system) : system(system) {}
	AbstractSlot::Iterator begin();
	AbstractSlot::Iterator end() { return AbstractSlot::Iterator(nullptr); }
};
Slots slots;

class AbstractSlotItem : public CouplingDataType{};
class VirtualizedItem;

static const int INDEX_UNORDERED = 1;
static const int INDEX_ORDERED = 2;

class SlotLabelSettings : public SimpleDataType {
public:
	virtual const char* getClassFactory() override { return "StorageSystemSlotLabelSettings"; }
	fs_content_export virtual void bind() override;

	/// <summary>	Reference to the label's color palette. </summary>
	ObjRef<ColorPalette> colorPalette;
	double indexType = 0.0;
	double trackedVariableType = 0.0;
	TreeNode* defaultValue;

	struct SlotLess {
		bool operator ()(const AbstractSlot* left, const AbstractSlot* right) const;
	};
	typedef std::set<AbstractSlot*, SlotLess> SlotSet;
	typedef std::unordered_map<Variant, SlotSet, Variant::Hash> SlotIndex;
	SlotIndex slotIndex;
	typedef std::pair<SlotSet::iterator, SlotSet::iterator> SlotSetRange;
	fs_content_export void onSlotLabelValueChange(AbstractSlot* slot, TreeNode* label, const Variant& newValue);


	StorageSystem* __getSystem() { return holder->ownerObject->objectAs(StorageSystem); }
	__declspec(property(get = __getSystem)) StorageSystem* system;

	fs_content_export void onReset();

	fs_content_export Color getColor(const Variant& value);
};

class VirtualizedItem : public CouplingDataType {
public:
	class StorageObjectItemMeshData;

	virtual const char* getClassFactory() override { return "StorageSystemVirtualizedItem"; }
	fs_content_export virtual void bind() override;
	int shapeIndex;
	int textureIndex;
	double lastMoveTime;
	double creationTime;
	double statsCollectorID = 0;
	Vec3 location; // the location of the item in storage object coordinate
	Vec3 size; // used only when recycling
	Vec3 rotation; // used only when recycling
	Vec3 __getSize() { return size; }
	Vec3 __getRotation() { return rotation; }
	fs_content_export Vec3 __getCenter();
	fs_content_export void __setCenter(const Vec3& toLoc);
	__declspec(property(get = __getCenter, put = __setCenter)) Vec3 center;
	Vec4f color;

	fs_content_export void virtualize(ObjectDataType* item, StorageSystem* system, StorageObject* owner);
	fs_content_export ObjectDataType* unvirtualize(treenode toNode, StorageSystem* system, StorageObject* owner);
	fs_content_export void setMeshDataDirty(StorageObject* obj);
	VirtualizedItem* next = nullptr;
	VirtualizedItem* prev = nullptr;
	StorageObjectItemMeshData* meshDataOwner = nullptr;
	VirtualizedItem* meshDataNext = nullptr;
	VirtualizedItem* meshDataPrev = nullptr;

	std::vector<Variant> labels;
	TreeNode* substructure = nullptr;
	TreeNode* copiedLabels = nullptr;

	int assignmentCount = 0;

	bool isParentVirtualized = false;
	bool isDrawSurrogateElement = false;

	class StorageData;

	class StorageObjectItemMeshData : public CouplingDataType {
	public:
		fs_content_export StorageObjectItemMeshData();
		virtual const char* getClassFactory() override { return "StorageSystemVirtualizedItemStorageObjectItemMeshData"; }
		fs_content_export virtual void bind() override;
		bool isDirty;
		StorageObject* __getStorageObject() const { return holder->ownerObject->objectAs(StorageObject); }
		__declspec(property(get = __getStorageObject)) StorageObject* object;
		StorageData* __getStorageData() const { return partner()->up->up->objectAs(StorageData); }
		__declspec(property(get = __getStorageData)) StorageData* data;

		int transformVertAttrib;
		int colorVertAttrib;
		InstancedMesh mesh;
		VirtualizedItem* firstItem = nullptr;
		fs_content_export void draw(int dataMeshIndex, int glDrawMode);
		fs_content_export void rebuildMesh();
	};

	class StorageData : public SimpleDataType {
	public:
		struct Key {
			int shapeIndex;
			int textureIndex;
			bool operator == (const Key& other) const { return shapeIndex == other.shapeIndex && textureIndex == other.textureIndex; }
			Key() { }
			Key(ObjectDataType* item);
			Key(int shapeIndex, int textureIndex) : shapeIndex(shapeIndex), textureIndex(textureIndex) {}
		};

		struct Hash {
			size_t operator() (const Key& key) const { return key.shapeIndex ^ key.textureIndex; }
		};
		virtual const char* getClassFactory() override { return "StorageSystemVirtualizedItemStorageData"; }
		fs_content_export virtual void bind() override;
		Key key;
		TreeNode* itemCopy;
		bool isMeshDataDumped = false;
		NodeListArray<>::SubNodeType shapeMeshes;
		int __getNumMeshes() { return shapeMeshes.length; }
		__declspec(property(get = __getNumMeshes)) int numMeshes;
		NodeListArray<StorageObjectItemMeshData>::ObjPtrType dependentObjectMeshData;
		fs_content_export void dumpMeshData();
		fs_content_export int prepareDraw(int meshIndex);
		fs_content_export void finishDraw(int meshIndex);
		IndexedMesh* getMesh(int meshIndex) { return shapeMeshes[meshIndex]->subnodes["mesh"]->objectAs(IndexedMesh); }

		static int u_perInstanceColorEnabledID;
		static bool u_perInstanceColorEnabledCurValue;
		bool didDisableTextures = false;
	};
};

class ItemLabelSettings : public SimpleDataType {
public:
	virtual const char* getClassFactory() override { return "StorageSystemItemLabelSettings"; }
	fs_content_export virtual void bind() override;

	double indexType = 0.0;

	struct ItemLess {
		bool operator ()(const VirtualizedItem* left, const VirtualizedItem* right) const
		{
			return left->assignmentCount < right->assignmentCount;
		}
	};
	typedef std::set<VirtualizedItem*, ItemLess> ItemSet;
	typedef std::unordered_map<Variant, ItemSet, Variant::Hash> ItemIndex;
	typedef std::pair<ItemSet::iterator, ItemSet::iterator> ItemSetRange;
	ItemIndex itemIndex;


	StorageSystem* __getSystem() { return holder->ownerObject->objectAs(StorageSystem); }
	__declspec(property(get = __getSystem)) StorageSystem* system;

	fs_content_export void onReset();
	fs_content_export void removeFromIndex(const Variant& value, VirtualizedItem* item);
	void addToIndex(const Variant& value, VirtualizedItem* item)
	{ 
		if (item) 
			itemIndex[value].insert(item); 
	}
};

struct BoundingBox {
	Vec3f min;
	Vec3f max;
	bool contains(const Vec3f& point) const { 
		return point.x >= min.x - 0.00001
			&& point.y >= min.y - 0.00001
			&& point.z >= min.z - 0.00001
			&& point.x <= max.x + 0.00001
			&& point.y <= max.y + 0.00001
			&& point.z <= max.z + 0.00001;
	}
	bool contains(const Vec3f& point, int axis) const {
		return point[axis] >= min[axis] - 0.00001
			&& point[axis] <= max[axis] + 0.00001;
	}
};

class Visualization : public SimpleDataType {
public:
	virtual const char* getClassFactory() override { return "StorageSystemVisualization"; }
	fs_content_export virtual void bind() override;
	fs_content_export void onReset();
	fs_content_export void rebuildLabelDependencies();
	fs_content_export void rebuildMeshMasterSlaveDependencies();
	fs_content_export Variant rebuildLabelDependencies(FLEXSIMINTERFACE) { rebuildLabelDependencies(); return Variant(); }
	fs_content_export void onSlotLabelValueChange(AbstractSlot* slot, TreeNode* label, const Variant& newValue);

	StorageSystem* __getSystem() { return ownerobject(holder)->objectAs(StorageSystem); }
	__declspec(property(get = __getSystem)) StorageSystem* system;

	class TextElement;
	class ImageElement;
	class WireframeBoxElement;
	class VisualizationReferenceElement;
	class Element;

	struct Rect {
		Vec3f bottomLeft;
		Vec3f xAxis;
		Vec3f yAxis;
	};

	class ElementMeshEntry {
	public:
		StorageObject* owner;
		Element* element;
		ElementMeshEntry(StorageObject* owner, Element* element) : owner(owner), element(element) {}
		ElementMeshEntry() : owner(nullptr), element(nullptr) {}
		virtual ~ElementMeshEntry() {}
		void rebuildMesh();
		virtual void addToMesh(TreeNode* slotNode, Element* element, const Rect& face);
		void init();
		virtual void initVirtual() = 0;
		virtual void clear() = 0;
		void setDirty();
		virtual void setDirtyVirtual() = 0;
		virtual void draw() = 0;
		static ElementMeshEntry* makeEntry(StorageObject* owner, Element* element);
		virtual Mesh* getMesh() = 0;
	};


	class WireframeBoxElementMeshEntry : public ElementMeshEntry {
	public:
		WireframeBoxElementMeshEntry(StorageObject* owner, Element* element) : ElementMeshEntry(owner, element), mesh([this](Mesh& mesh) { rebuildMesh(); }) {}

		IndexedMesh::AutoRebuildingMesh mesh;
		virtual void initVirtual() override { mesh.mesh.init(0, MESH_POSITION | MESH_AMBIENT_AND_DIFFUSE4); }
		virtual void clear() override { mesh.mesh.clear(); }
		virtual void setDirtyVirtual() override { mesh.setDirty(); }
		virtual void draw() override;
		virtual Mesh* getMesh() override { return &mesh.mesh; }
	};

	class ImageElementMeshEntry : public WireframeBoxElementMeshEntry {
	public:
		ImageElementMeshEntry(StorageObject* owner, Element* element) : WireframeBoxElementMeshEntry(owner, element) {}

		int builtAtlasSize = 0;

		virtual void addToMesh(TreeNode* slotNode, Element* element, const Rect& face) override;
		virtual void initVirtual() override 
		{ 
			mesh.mesh.init(0, MESH_POSITION | MESH_AMBIENT_AND_DIFFUSE4 | MESH_NORMAL | MESH_TEX_COORD2);
		}
		virtual void draw() override;
	};

	class TextElementMeshEntry : public ElementMeshEntry {
	public:
		TextElementMeshEntry(StorageObject* owner, Element* element) 
			: ElementMeshEntry(owner, element), 
			textMesh([this](TextMesh& mesh) { rebuildMesh(); })
		{}
		TextMesh::AutoRebuildingMesh textMesh;
		virtual void initVirtual() override {
			textMesh.mesh.init(MESH_NORMAL | MESH_AMBIENT_AND_DIFFUSE4);
		}
		virtual void clear() override {textMesh.mesh.clear();}
		virtual void setDirtyVirtual() override {textMesh.setDirty();}
		virtual void draw() override;
		virtual Mesh* getMesh() override { return &textMesh.mesh; }
	};

	class Element : public SimpleDataType {
	public:
		~Element();
		virtual const char* getClassFactory() override { return "StorageSystemVisualizationElement"; }
		virtual void bind() override;
		virtual void onReset() {}

		static const int SCOPE_SLOT = 1;
		static const int SCOPE_CELL = 2;
		static const int SCOPE_LEVEL = 3;
		static const int SCOPE_BAY = 4;
		static const int SCOPE_OBJECT = 5;
		double scope;
		static const int FACE_FRONT = 1;
		static const int FACE_BACK = 2;
		static const int FACE_BOTTOM = 3;
		static const int FACE_TOP = 4;
		static const int FACE_LEFT = 5;
		static const int FACE_RIGHT = 6;
		double face;

		double x;
		double y;
		double z;
		double sx; 
		double sy;

		Vec3 anchorMin;
		Vec3 anchorMax;
		Vec2 pivot;

		ObjRef<SlotLabelSettings> label;
		static const int COLOR_BY_OBJECT = 0;
		static const int COLOR_BY_LABEL = 1;
		TreeNode* color;

		TreeNode* slotFilter;

		static const int REPEAT_TYPE_STRETCH = 0;
		static const int REPEAT_TYPE_TILE = 1;
		double shapeRepeatType = 0;
		double shapeRepeatAxis = 1;
		double shapeRepeatScaleToFit = 1;
		double shapeRepeat = 1;

		Visualization* __getVisualization() { return holder->up->up->objectAs(Visualization); }
		__declspec(property(get = __getVisualization)) Visualization* visualization;

		virtual bool addToMesh(Mesh* mesh, TreeNode* slotNode, const Rect& face) { return true; }

		double drawText = 0;
		void setAllObjectsDirty();
		Variant setAllObjectsDirty(FLEXSIMINTERFACE) { setAllObjectsDirty(); return Variant(); }
	
		virtual TextElement* toText() { return nullptr; }
		virtual ImageElement* toImage() { return nullptr; }
		virtual WireframeBoxElement* toWireBox() { return nullptr; }
		virtual VisualizationReferenceElement* toVisualizationReference() { return nullptr; }

		void calculateInnerFace(Vec3f& bbBottomLeft, Vec3f& xAxis, Vec3f& yAxis);
		void addToBoundingBoxOutline(Mesh* mesh, Vec3f& bbBottomLeft, Vec3f& bbXAxis, Vec3f& bbYAxis, bool doInnerBox);
		bool isValidForSlot(TreeNode* slotNode);

		Rect getFaceFromBoundingBox(StorageObject* obj, const BoundingBox& originalBB, bool includeZ, int shapeRepeatCount);
		void offsetFace(Vec3f& faceOrigin, const BoundingBox& bb, int shapeRepeatCount);
		Variant calculateLabelValue(TreeNode* slotNode);
		Vec4f calculateColor(const Variant& labelValue, TreeNode* slotNode);

		virtual bool canBeMeshSlave(Element* toMaster) { return false; }
		virtual bool canBeMeshMaster() { return false; }
		ObjRef<Element> meshMaster;
		bool __getIsMeshSlave() { return meshMaster.get() != nullptr; }
		__declspec(property(get = __getIsMeshSlave)) bool isMeshSlave;
		double isMeshMaster = 0.0;

		int getNumShapeRepeats(const BoundingBox& bb, StorageObject* obj);
		void saveUnitScalingData(treenode toNode);
	};

	class ImageElement : public Element {
	public:
		virtual const char* getClassFactory() override { return "StorageSystemVisualizationImageElement"; }
		virtual void bind() override;
		virtual void onReset() override;
		std::unique_ptr<TextureAtlas> atlas;
		static const int IMG_TYPE_STATIC = 1;
		static const int IMG_TYPE_DYNAMIC = 2;
		double imageType;
		TreeNode* dynamicImage;
		ByteBlock staticImage;
		int staticImageIndexRank = 0;
		string cachedStaticImage;
		Vec2 bottomLeft;
		Vec2 bottomRight;
		Vec2 topLeft;
		Vec2 topRight;
		Vec2 repeatType;
		Vec2 repeat;
		Vec2 repeatOffset;
		std::string getImage(TreeNode* slotNode);
		virtual bool addToMesh(Mesh* mesh, TreeNode* slotNode, const Rect& face) override;
		virtual ImageElement* toImage() override { return this; }
		virtual bool canBeMeshSlave(Element* toMaster) override;
		virtual bool canBeMeshMaster() override;
	};


	class TextElement : public Element {
	public:
		virtual const char* getClassFactory() override { return "StorageSystemVisualizationTextElement"; }
		virtual void bind() override;
		double textScale = 1.0; // ratio of text line height to height of text box
		TreeNode* drawText;
		double vertAlign = TextMesh::Top;
		double horAlign = TextMesh::Left;
		double wrap = 1;
		double scaleToFit = 1;
		virtual TextElement* toText() override { return this; }
		virtual bool addToMesh(Mesh* mesh, TreeNode* slotNode, const Rect& face) override;
		virtual bool canBeMeshSlave(Element* toMaster) override { return toMaster->toText() != nullptr; }
		virtual bool canBeMeshMaster() override { return true; }
	};

	class WireframeBoxElement : public Element {
	public:
		virtual const char* getClassFactory() override { return "StorageSystemVisualizationWireframeBoxElement"; }
		virtual void bind() override;
		double lineWidth;
		virtual WireframeBoxElement* toWireBox() override { return this; }
		virtual bool addToMesh(Mesh* mesh, TreeNode* slotNode, const Rect& face) override;
		virtual bool canBeMeshSlave(Element* toMaster) override { return toMaster->toWireBox() != nullptr && toMaster->toWireBox()->lineWidth == lineWidth; }
		virtual bool canBeMeshMaster() override { return true; }
	};

	class VisualizationReferenceElement : public Element {
	public:
		virtual const char* getClassFactory() override { return "StorageSystemVisualizationReferenceElement"; }
		virtual void bind() override { __super::bind(); bindObjRef(visualization, 1); }
		ObjRef<Visualization> visualization;
		double lineWidth;
		virtual VisualizationReferenceElement* toVisualizationReference() override { return this; }
	};

	NodeListArray<Element>::SdtSubNodeBindingType elements;

	TreeNode* labelDependencies;

	Element* addElement(const char* type);
	Variant addElement(FLEXSIMINTERFACE);
	void saveUnitScalingData(treenode elementsSubstructureNode);
	Variant saveUnitScalingData(FLEXSIMINTERFACE) { saveUnitScalingData(param(1)); return Variant(); }
};

NodeListArray<Visualization>::SdtSubNodeBindingType visualizations;
Variant addVisualization(FLEXSIMINTERFACE) { return visualizations.add(new Visualization)->holder; }


fs_content_export static SimpleDataType* createSDTDerivative(const char* className);
fs_content_export static void addObject(TreeNode* myCouplingNode, StorageObject* obj);

 
NodeListArray<StorageObject, addObject>::ObjCouplingType objects;
typedef NodeListArray<StorageObject, addObject, nullptr, OneBased::rankOffset>::ObjCouplingType StorageObjectArray;
StorageObjectArray storageObjects;
fs_content_export StorageObjectArray& __getStorageObjects() { return storageObjects; }
NodeListArray<SlotLabelSettings>::SdtSubNodeBindingType slotLabels;

NodeListArray<ItemLabelSettings>::SdtSubNodeBindingType itemLabels;
NodeListArray<ItemLabelSettings>::ObjPtrType indexedItemLabels;
ObjRef<VirtualizedItem> firstItem;
ObjRef<VirtualizedItem> lastItem;


NodeListArray<AddressScheme>::SdtSubNodeBindingType addressSchemes;
Variant addAddressScheme(FLEXSIMINTERFACE) { return addressSchemes.add(new AddressScheme)->holder; }


fs_content_export virtual void bind() override;
fs_content_export virtual void bindVariables() override;
fs_content_export virtual void bindInterface() override;
fs_content_export virtual void bindEvents() override;
fs_content_export virtual double onReset() override;
fs_content_export virtual void onCreate();

fs_content_export void addAllModelStorageObjects();
fs_content_export void validateUniqueAddresses();

Variant addSlotLabel(FLEXSIMINTERFACE);
Variant addItemLabel(FLEXSIMINTERFACE);

ObjRef<SlotLabelSettings> drawPickableSlots;

TreeNode* onSlotEntry;
TreeNode* onSlotExit;
TreeNode* onSlotAssign;

std::unordered_map<std::string, int> labelRankMap;
fs_content_export void refreshLabelRankMap();
fs_content_export int getLabelRank(const char* labelName);

class QueryFlags {
public:
	static const int Limit1 = 0x1;
	
	static const int ExcludeStorableSlots = 0x10;
	static const int UnstorableSlots = 0x20;
	static const int AllSlots = 0x20;
	
	static const int ExcludeStoredItems = 0x200;
	static const int InboundItems = 0x400;
	static const int OutboundItems = 0x800;
	static const int AllItems = 0xc00;
	
	static void bindInterface();
};


class SlotQueryDataSource : public SqlDataSource
{
public:
	StorageSystem * __getSystem() { return ownerobject(holder)->objectAs(StorageSystem); }
	__declspec(property(get = __getSystem))
	StorageSystem* system;
	SlotQueryDataSource() : advancer(*this) {}
	virtual const char* getClassFactory() override { return "StorageSystemSlotQueryDataSource"; }
	virtual void bind() override;
	SlotLabelSettings::SlotSet::iterator lastIndexedIter;
	SlotLabelSettings::SlotSet* lastSet;
	static const int UNTRACKED_LABEL_COL_ID_OFFSET = 0x1000;
	std::vector<string> untrackedLabels;
	int flags;
	VariantParams* params;
	fs_content_export void reset(int flags, VariantParams& params);

	fs_content_export virtual int getTableID(const char* tableName) override;

	static const int SLOT_COL_ID = 0;
	fs_content_export int getColID(int tableId, const char* colName, int& colFlags, bool includeSlotLogic);
	virtual int getColID(int tableId, const char* colName, int& colFlags) override
	{ 
		return getColID(tableId, colName, colFlags, true);
	}


	fs_content_export virtual Variant getValue(int tableID, const SqlCursor& cursor, int colID) override;
	fs_content_export virtual bool setValue(int tableId, const SqlCursor& cursor, int colID, const Variant& toVal) override;

	class CursorAdvancer : public SqlCursorAdvancer {
	public:
		SlotQueryDataSource & owner;
		CursorAdvancer(SlotQueryDataSource& owner) : owner(owner) {}
		virtual bool init(SqlCursor& cursor) override;
		virtual bool advance(SqlCursor& cursor) override;
	};
	CursorAdvancer advancer;

	fs_content_export virtual SqlCursorAdvancer* initAdvancer(int tableID, SqlCursorAdvancer* defaultAdvancer, bool& manageMemory) override { manageMemory = false; return &advancer; }

	fs_content_export virtual bool initIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) override;
	fs_content_export virtual bool advanceIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) override;

	fs_content_export virtual bool hasCustomWhereFilter() override { return (flags & QueryFlags::AllSlots) != QueryFlags::AllSlots && !(flags & QueryFlags::ExcludeStorableSlots); }
	fs_content_export virtual bool evaluateCustomWhereFilter(SqlQueryInterface* q) override;
	fs_content_export virtual const char* getFlexScriptType(int tableID, int colID) override;
};
std::unordered_map<string, ObjRef<SqlQueryInterface>> slotQueryIndex;
TreeNode* slotQueries;
fs_content_export Variant querySlots(const char* query, int flags, VariantParams& params);
fs_content_export Variant querySlots(const char* query, int flags = 0);
fs_content_export Variant querySlots(const char* query, int flags, const Variant& p1);
fs_content_export Variant querySlots(const char* query, int flags, const Variant& p1, const Variant& p2);
fs_content_export Variant querySlots(const char* query, int flags, const Variant& p1, const Variant& p2, const Variant& p3);
fs_content_export Variant querySlots(const char* query, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4);
fs_content_export Variant querySlots(const char* query, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4, const Variant& p5);


fs_content_export AbstractSlot* findSlot(const Variant& queries, int flags, VariantParams& params);
fs_content_export AbstractSlot* findSlot(const Variant& queries = Variant(), int flags = 0);
fs_content_export AbstractSlot* findSlot(const Variant& queries, int flags, const Variant& p1);
fs_content_export AbstractSlot* findSlot(const Variant& queries, int flags, const Variant& p1, const Variant& p2ract);
fs_content_export AbstractSlot* findSlot(const Variant& queries, int flags, const Variant& p1, const Variant& p2, const Variant& p3);
fs_content_export AbstractSlot* findSlot(const Variant& queries, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4);
fs_content_export AbstractSlot* findSlot(const Variant& queries, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4, const Variant& p5);


fs_content_export AbstractSlot* getSlot(const char* address);

class ItemQueryDataSource : public SlotQueryDataSource
{
public:
	virtual const char* getClassFactory() override { return "StorageSystemItemQueryDataSource"; }
	ItemQueryDataSource() : advancer(*this) {}

	static const int SLOT_COL_ID = 0;
	static const int ITEM_COL_ID = UNTRACKED_LABEL_COL_ID_OFFSET + 0x1000;
	fs_content_export virtual int getColID(int tableId, const char* colName, int& colFlags) override;

	fs_content_export virtual Variant getValue(int tableID, const SqlCursor& cursor, int colID) override;

	//virtual bool setValue(int tableId, int row, int colId, const Variant& toVal) override;
	class CursorAdvancer : public SqlCursorAdvancer {
	public:
		ItemQueryDataSource& owner;
		CursorAdvancer(ItemQueryDataSource& owner) : owner(owner) {}
		virtual bool init(SqlCursor& cursor) override;
		virtual bool advance(SqlCursor& cursor) override;
	};
	CursorAdvancer advancer;
	virtual SqlCursorAdvancer* initAdvancer(int tableID, SqlCursorAdvancer* defaultAdvancer, bool& manageMemory) override { manageMemory = false; return &advancer; }

	fs_content_export virtual bool initIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) override;
	fs_content_export virtual bool advanceIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) override;
	virtual const char* getFlexScriptType(int tableID, int colID) override 
	{ 
		if (colID == SLOT_COL_ID) return "Storage.Slot"; 
		else if (colID == ITEM_COL_ID) return "Storage.Slot.Item";
		else return nullptr; }
	virtual bool hasCustomWhereFilter() override { return (flags & QueryFlags::AllItems) != QueryFlags::AllItems && !(flags & QueryFlags::ExcludeStoredItems); }
	fs_content_export virtual bool evaluateCustomWhereFilter(SqlQueryInterface* q) override;
};
std::unordered_map<string, ObjRef<SqlQueryInterface>> itemQueryIndex;
TreeNode* itemQueries;

fs_content_export Variant queryItems(const char* query, int flags, VariantParams& params);
fs_content_export Variant queryItems(const char* query, int flags = 0);
fs_content_export Variant queryItems(const char* query, int flags, const Variant& p1);
fs_content_export Variant queryItems(const char* query, int flags, const Variant& p1, const Variant& p2);
fs_content_export Variant queryItems(const char* query, int flags, const Variant& p1, const Variant& p2, const Variant& p3);
fs_content_export Variant queryItems(const char* query, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4);
fs_content_export Variant queryItems(const char* query, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4, const Variant& p5);

fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags, VariantParams& params);
fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags = 0);
fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags, const Variant& p1);
fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags, const Variant& p1, const Variant& p2);
fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags, const Variant& p1, const Variant& p2, const Variant& p3);
fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4);
fs_content_export VirtualizedItem* findItem(const Variant& queries, int flags, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4, const Variant& p5);

double autoRestack = 0;
double virtualizeItems;
NodeListArray<VirtualizedItem::StorageData>::SdtSubNodeBindingType virtualizedItems;
std::unordered_map<VirtualizedItem::StorageData::Key, VirtualizedItem::StorageData*, VirtualizedItem::StorageData::Hash> virtualizedItemMap;
fs_content_export void refreshVirtualizedItemMap();

double itemAssignmentCount;

Variant setDrawElementBoundingBox(FLEXSIMINTERFACE);

fs_content_export void onItemSlotAssigned(AbstractSlot* slot, VirtualizedItem* data);
fs_content_export void onItemSlotExited(AbstractSlot* slot, VirtualizedItem* data);
fs_content_export void addToInventory(ObjectDataType* item, VirtualizedItem* data);
fs_content_export void removeFromInventory(ObjectDataType* item, VirtualizedItem* data);
fs_content_export void onItemSlotUnassigned(ObjectDataType* item, VirtualizedItem* data);
fs_content_export void onItemCurrentSlotUpdating(VirtualizedItem* oldCurrentSlotItem);

class StorageNamespace {
public:
	static void bindInterface();
	static StorageSystem* __getSystem();
};

StorageObject* drawFiringStorageObject = nullptr;
bool shouldFireDraw = false;
fs_content_export void draw(treenode view);

//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// StorageObject
class StorageObject : public FixedResource
{
public:


//ClassIncludeHeaderStart
	fs_content_export StorageObject();
	fs_content_export ~StorageObject();
	typedef StorageSystem::Visualization Visualization;

	class Bay;
	class Level;
	class Item;
	class Slot : public StorageSystem::AbstractSlot {
	public:
		virtual const char* getClassFactory() override { return "StorageSlot"; }
		fs_content_export virtual void bind() override;
		fs_content_export virtual void bindInterface() override;
		fs_content_export virtual void bindEvents() override;
		virtual int getCapabilities() override { return CAPABILITY_LABELS; }

		class Item : public StorageSystem::VirtualizedItem {
		public:
			virtual const char* getClassFactory() override { return "StorageSlotItem"; }
			fs_content_export virtual void bind() override;
			fs_content_export virtual void bindInterface() override;
			fs_content_export StorageObject::Item* __getStorageItem();
			__declspec(property(get = __getStorageItem)) StorageObject::Item* rawStorageItem;
			fs_content_export StorageObject::Item* __assertStorageItem();
			__declspec(property(get = __assertStorageItem)) StorageObject::Item* storageItem;
			fs_content_export ObjectDataType* __assertItem();
			__declspec(property(get = __assertItem)) ObjectDataType* item; 
			// the "storage size" meaning the total size the item takes up relative to the rack
			Vec3 storageSize;
			// the assigned ("resting"), untilted stack location of the item in slot coordinates
			Vec3 stackingLocation;
			Vec3 slotStackingMarkerAtEntry;
			Vec3 __getStackingCenter() {
				return Vec3(
					stackingLocation.x + 0.5 * storageSize.x,
					stackingLocation.y - 0.5 * storageSize.y,
					stackingLocation.z + 0.5 * storageSize.z);
			}
			void __setStackingCenter(const Vec3& center) {
				stackingLocation = Vec3(center.x - 0.5 * storageSize.x,
					center.y + 0.5 * storageSize.y,
					center.z - 0.5 * storageSize.z);
			}
			// the assigned ("resting"), untilted stack center of the item in slot coordinates
			__declspec(property(get = __getStackingCenter, put = __setStackingCenter)) Vec3 stackingCenter; 
			Slot* __getSlot() { return holder->up->up->objectAs(Slot); }
			__declspec(property(get = __getSlot)) Slot* slot;
			fs_content_export int __getPickRank();
			__declspec(property(get = __getPickRank)) int pickRank;
			fs_content_export int __getSlotRank() { return holder->rank; }
			__declspec(property(get = __getSlotRank)) int slotRank;

			fs_content_export int __getIsVirtual() { return rawStorageItem == nullptr; }
			__declspec(property(get = __getIsVirtual)) int isVirtual;
			fs_content_export Variant __getLabelProperty(const char* name, unsigned nameHash, bool dieHard);
			fs_content_export void __setLabelProperty(const char* name, unsigned nameHash, const Variant& value);
			Vec3 __getLocation() { return location; }

			fs_content_export Vec3 getLocation(const Vec3& sizeRatio);
			Vec3 getLocation(double xRatio, double yRatio, double zRatio) { return getLocation(Vec3(xRatio, yRatio, zRatio)); }

			fs_content_export void virtualize();
			fs_content_export ObjectDataType* unvirtualize();

		};
		double loc = 0.0;
		double size = 1.0;
		Vec3 lowerPadding = Vec3(0.0, 0.0, 0.0);
		Vec3 upperPadding = Vec3(0.0, 0.0, 0.0);
		Vec3 stackingMarker;
		Vec3 stackingMaxSizeMarker;
		double isStorable = 1.0;
		int __getIsStorable() { return (int)isStorable; }
		double __getCenter() { return loc + 0.5 * size; }
		__declspec(property(get = __getCenter)) double center;
		fs_content_export Vec3 getSize(bool xyIsReposedPlane);
		fs_content_export Vec3 getLocation(const Vec3& sizeRatio, bool xyIsReposedPlane);
		Vec3 getLocation(const Vec3& sizeRatio) { return getLocation(sizeRatio, true); }
		Vec3 getLocation(double xRatio, double yRatio, double zRatio) { return getLocation(Vec3(xRatio, yRatio, zRatio), true); }
		Vec3 __getLocation() { return getLocation(Vec3(0.0, 0.0, 0.0), true); }
		fs_content_export Vec3 __getSize();

		treenode itemsNode;
		fs_content_export static StorageObject::Item* __getStorageItem(treenode subnode);
		/// <summary>	The items assigned to this slot. This includes 
		/// 			both items that are in the object and items that 
		/// 			have been assigned to the slot but have not yet 
		/// 			been placed in the object. Note that items already 
		/// 			in the object should always be first in the array, 
		/// 			i.e. the assigned-only items are at the end of the 
		/// 			array.</summary>
		NodeListArray<StorageObject::Item, nullptr, &Slot::__getStorageItem, OneBased::rankOffset> storageItems;

		typedef NodeListArray<typename Slot::Item, nullptr, nullptr, OneBased::rankOffset>::CouplingSdtSubNodeType SlotItemArray;
		SlotItemArray slotItems;
		SlotItemArray& __getSlotItems() { return slotItems; }
		
		fs_content_export Level* __getLevel();
		__declspec(property(get = __getLevel)) Level* level;
		fs_content_export Bay* __getBay();
		__declspec(property(get = __getBay)) Bay* bay;
		fs_content_export StorageObject* __getObject();
		__declspec(property(get = __getObject)) StorageObject* storageObject;
		TreeNode* labels = nullptr;
		TreeNode* resetLabels = nullptr;
		fs_content_export virtual TreeNode* getLabelNode(const char* labelName, bool assert, TreeNode*& labels);
		virtual TreeNode* getLabelNode(const char* labelName, bool assert) override { return getLabelNode(labelName, assert, labels); }
		fs_content_export virtual void setLabel(const char* labelName, const Variant& toVal) override;

		fs_content_export int __getNumStoredItems();
		__declspec(property(get = __getNumStoredItems)) int numStoredItems;

		fs_content_export void onReset();
		fs_content_export void resetStackingMarkers();
		fs_content_export void resetLabelValues();
		fs_content_export void restack(int fromSlotRank = 0);

		static const int PAINT_INDIVIDUAL_SLOT = 1;
		static const int PAINT_ALL_SLOTS_IN_SAME_CELL = 2;
		static const int PAINT_ALL_SLOTS_IN_SAME_LEVEL = 3;
		static const int PAINT_ALL_SLOTS_IN_SAME_BAY = 4;
		static const int PAINT_ALL_SLOTS_IN_SAME_RACK = 5;

		fs_content_export void paintLabel(const string& labelName, const Variant& value, int paintMode);
		fs_content_export Variant paintLabel(FLEXSIMINTERFACE);

		fs_content_export void synchronizeLabelRanks(StorageSystem* system, TreeNode*& labelsNode);
		void synchronizeLabelRanks(StorageSystem* system)
		{
			synchronizeLabelRanks(system, labels);
			synchronizeLabelRanks(system, resetLabels);
		}

		fs_content_export StorageSystem::Address getAddress(bool mapped = true);
		fs_content_export void onAssigned(StorageObject::Item* data);
		fs_content_export void onReceive(StorageObject::Item* data);
		fs_content_export void onSend(StorageObject::Item* data);
		fs_content_export bool hasSpace(treenode item);
		fs_content_export void resolveItemPlacement(Slot::Item* slotItem, StorageObject::Item* storageItem, Vec3& marker, Vec3& maxSizeMarker);
		fs_content_export void setItemStackingLocation(Slot::Item* slotItem, StorageObject::Item* storageItem);

		TreeNode* onEntry = nullptr;
		TreeNode* onExit = nullptr;
		TreeNode* onAssign = nullptr;

		int systemAllSlotsIndex = 0;

		fs_content_export Variant __getLabelProperty(const char* name, unsigned nameHash, bool dieHard);
		void __setLabelProperty(const char* name, unsigned nameHash, const Variant& value) { setLabel(name, value); }
	
		fs_content_export Variant __getSlotID();
		__declspec(property(get = __getSlotID)) Variant slotID;
		fs_content_export Variant __getLevelID();
		__declspec(property(get = __getLevelID)) Variant levelID;
		fs_content_export Variant __getBayID();
		__declspec(property(get = __getBayID)) Variant bayID;
		fs_content_export Variant __getAisleID();
		__declspec(property(get = __getAisleID)) Variant aisleID;
		fs_content_export Variant __getZoneID();
		__declspec(property(get = __getZoneID)) Variant zoneID;
		fs_content_export Variant __getAddress();
		__declspec(property(get = __getAddress)) Variant address; 

		fs_content_export StorageSystem::BoundingBox getBoundingBoxFromScope(int scope);

		double lastItemExitTime;
		double lastItemExitYSize;
		ObjRef<ObjectDataType> pushBackItem;
		fs_content_export bool updateFlowingItems(bool asPushBackRack);
	};

	struct SlotLabelMatchCache {
		bool isDirty = true;
		bool areEqual = false;
		bool isFirstSet = false;
		string labelName;
		Variant value;
		void init(const char* name) {
			labelName = name;
			value = Variant();
			areEqual = true;
			isFirstSet = false;
			isDirty = false;
		}
		void init(const char* name, const Variant& val) {
			init(name);
			value = val;
			isFirstSet = true;
		}
		bool check(Slot* slot) {
			Variant val;
			TreeNode* labelNode = slot->getLabelNode(labelName.c_str(), false);
			if (labelNode)
				val = labelNode->value;
			if (!isFirstSet) {
				isFirstSet = true;
				value = val;
			}
			else {
				areEqual = areEqual && value == val;
			}
			return areEqual;
		}
		template <class Func>
		bool check(const char* name, Func func) {
			if (!isDirty && labelName == name)
				return areEqual;
			init(name);
			func();
			return areEqual;
		}
		template <class Func>
		bool check(const char* name, const Variant& val, Func func) {
			if (!isDirty && labelName == name && value == val)
				return areEqual;
			init(name);
			func();
			return areEqual;
		}
	};

	class Level : public SimpleDataType {
	public:
		virtual const char* getClassFactory() override { return "StorageLevel"; }
		fs_content_export virtual void bind() override;
		fs_content_export virtual void bindInterface() override;
		double loc = 0.0;
		double size = 1.0;
		double isStorable = 1.0;
		typedef NodeListArray<Slot>::SdtSubNodeBindingTypeOneBased SlotsArray;
		SlotsArray slots;
		SlotsArray& __getSlots() { return slots; }

		Bay* __getBay() { return holder->up->up->objectAs(Bay); }
		__declspec(property(get = __getBay)) Bay* bay;

		fs_content_export void onReset();
		fs_content_export void cacheIsStorable();

		template<typename Func, typename CompareType, typename Comp = typename std::equal_to<CompareType>>
		CompareType visitSlots(Func func, CompareType stopVal, CompareType finishVal, Comp comp = Comp()) 
		{
			for (Slot* slot : slots) {
				CompareType val = func(slot);
				if (comp(val, stopVal))
					return val;
			}
			return finishVal;
		}
		template<typename Func>
		void visitSlots(Func func)
		{
			for (Slot* slot : slots) {
				func(slot);
			}
		}
		SlotLabelMatchCache slotLabelMatchCache;
		bool areSlotLabelsEqual(const char* labelName) {
			return slotLabelMatchCache.check(labelName, [this]() {
				return visitSlots([this](Slot* slot) { 
					return slotLabelMatchCache.check(slot);
				}, false, true);
			});
		}
		bool areSlotLabelsEqual(const char* labelName, const Variant& value)
		{
			return slotLabelMatchCache.check(labelName, value, [this]() {
				visitSlots([this](Slot* slot) { 
					return slotLabelMatchCache.check(slot);
				}, false, true);
			});
		}
		void setSlotLabels(const char* labelName, const Variant& value)
		{
			visitSlots([&](Slot* slot) {slot->setLabel(labelName, value); });
		}
	};

	class Bay : public SimpleDataType {
	public:
		virtual const char* getClassFactory() override { return "StorageBay"; }
		fs_content_export virtual void bind() override;
		fs_content_export virtual void bindInterface() override;
		double loc = 0.0;
		double size = 1.0;
		int numItems = 0;
		double isStorable = 1.0;
		typedef NodeListArray<Level>::SdtSubNodeBindingTypeOneBased LevelsArray;
		LevelsArray levels;
		LevelsArray& __getLevels() { return levels; }

		fs_content_export void onReset();
		fs_content_export void cacheIsStorable();


		template<class Func, class CompareType, class Comp = std::equal_to<CompareType>>
		CompareType visitSlots(Func func, CompareType stopVal, CompareType finishVal, Comp comp = Comp())
		{
			for (Level* level : levels) {
				CompareType val = level->visitSlots(func, stopVal, finishVal, comp);
				if (comp(val, stopVal))
					return val;
			}
			return finishVal;
		}
		template<typename Func>
		void visitSlots(Func func)
		{
			for (Level* level : levels) {
				level->visitSlots(func);
			}
		}

		SlotLabelMatchCache slotLabelMatchCache;
		bool areSlotLabelsEqual(const char* labelName) {
			return slotLabelMatchCache.check(labelName, [this]() {
				visitSlots([this](Slot* slot) { 
					return slotLabelMatchCache.check(slot);
				}, false, true);
			});
		}
		bool areSlotLabelsEqual(const char* labelName, const Variant& value)
		{
			return slotLabelMatchCache.check(labelName, value, [this]() {
				visitSlots([this](Slot* slot) { 
					return slotLabelMatchCache.check(slot);
				}, false, true);
			});
		}
		void setSlotLabels(const char* labelName, const Variant& value)
		{
			visitSlots([&](Slot* slot) {slot->setLabel(labelName, value); });
		}
	};

	class Item : public SimpleDataType {
	private:
		treenode currentSlotNode;
		treenode assignedSlotNode;
	public:
		static const char* classFactory;
		virtual const char* getClassFactory() override { return classFactory; }
		fs_content_export virtual void bind() override;
		fs_content_export virtual void bindInterface() override;
		ObjectDataType* __getItem() { return holder->ownerObject->objectAs(ObjectDataType); }
		__declspec(property(get = __getItem)) ObjectDataType* item;

		double accumOffset = 0;
		fs_content_export Slot* __getCurrentSlot();
		fs_content_export void __setCurrentSlot(Slot* slot);
		__declspec(property(get=__getCurrentSlot, put = __setCurrentSlot)) Slot* currentSlot;
		fs_content_export Slot* __getAssignedSlot();
		fs_content_export void __setAssignedSlot(Slot* slot);
		__declspec(property(get = __getAssignedSlot, put = __setAssignedSlot)) Slot* assignedSlot;
		fs_content_export void restoreAtRank(Slot* slot, int atRank);
		fs_content_export Slot::Item* __getCurrentSlotItem();
		__declspec(property(get = __getCurrentSlotItem)) Slot::Item* currentSlotItem;
		fs_content_export Slot::Item* __getAssignedSlotItem();
		__declspec(property(get = __getAssignedSlotItem)) Slot::Item* assignedSlotItem;

		class State {
		public:
			static const int Unassigned = 1;
			static const int Inbound = 2;
			static const int Stored = 3;
			static const int Outbound = 4;
			static int __getUnassigned() { return Unassigned; }
			static int __getInbound() { return Inbound; }
			static int __getStored() { return Stored; }
			static int __getOutbound() { return Outbound; }
			static void bindInterface();
		};
		int __getState() {
			if (!currentSlot) {
				if (!assignedSlot)
					return State::Unassigned;
				else return State::Inbound;
			}
			else {
				if (assignedSlot == currentSlot)
					return State::Stored;
				else return State::Outbound;
			}
		}
		__declspec(property(get = __getState)) int state;
	};
	fs_content_export static StorageObject::Item* getItem(treenode item);
	fs_content_export static StorageObject::Item* assertItem(treenode item);


	fs_content_export virtual void bind() override;
	fs_content_export virtual void bindInterface() override;
	fs_content_export virtual void bindEvents() override;
	fs_content_export virtual void bindVariables() override;
	
	fs_content_export static SimpleDataType* createSDTDerivative(const char* className);

	virtual Rack* toRack() { return nullptr; }
	virtual FloorStorage* toFloorStorage() { return nullptr; }
	virtual GravityFlowRack* toGravityFlowRack() { return nullptr; }
	virtual DriveInRack* toDriveInRack() { return nullptr; }
	virtual PushBackRack* toPushBackRack() { return nullptr; }

	typedef NodeListArray<Bay>::SdtSubNodeBindingTypeOneBased BaysArray;
	BaysArray bays;
	fs_content_export BaysArray& __getBays() { return bays; }
	TreeNode* systemNode;
	fs_content_export StorageSystem* __getSystem();
	__declspec(property(get = __getSystem)) StorageSystem* system;

	/// <summary>	The structural mesh. Draws the column supports, and the orange front-facing
	/// 			panels </summary>
	IndexedMesh structuralMesh;
	/// <summary>	The slot mesh. Draws either the rack platforms, or a 
	/// 			box outline of each slot.</summary>
	Mesh slotMesh;
	/// <summary>	The box mesh. Draws the box surrounding the entire rack.</summary>
	Mesh boxMesh;
	/// <summary>	The brace mesh. Draws the diagonal column braces.</summary>
	Mesh braceMesh;
	/// <summary>	The pickable slot mesh. Draws a colored rectangle for each slot. 
	/// 			Used in slot label painter mode.</summary>
	Mesh pickableSlotMesh;
	ByteBlock pickableSlotMeshLabelName;
	static std::string drawPickableSlotsLabelName;
	Variant setDrawPickableSlots(FLEXSIMINTERFACE) { drawPickableSlotsLabelName = param(1).c_str(); return Variant(); }
	

	fs_content_export void buildReadyToGoMesh(Mesh& mesh);
	Mesh::AutoRebuildingMesh readyToGoMesh;

	bool rebuildMeshes = true;
	bool areLocationsDirty = true;
	treenode onEndDwellTimeTrigger = nullptr;
	double unrequitedDrag = 0;
	bool isBayUndoTrackingAdded = false;

	static const int PICK_BAY_SIZER = 101;
	static const int PICK_LEVEL_SIZER = 102;

	StorageSystem::AddressMapping addressMapping;
	ObjRef<StorageSystem::AddressScheme> addressScheme;

	fs_content_export Bay* getBay(int bay);
	fs_content_export Bay* getBay(treenode item);
	fs_content_export Level* getLevel(int bay, int level);
	fs_content_export Level* getLevel(treenode item);
	fs_content_export Slot* getSlot(int bay, int level, int position);
	fs_content_export Slot* getSlot(const Variant& bayID, const Variant& levelID, const Variant& slotID);
	fs_content_export Slot* getSlot(treenode item);

	fs_content_export void visitBays(std::function<void(Bay*)>, const Variant& bayFilter = Variant());
	fs_content_export void visitLevels(std::function<void(Level*)>, const Variant& levelFilter = Variant());
	fs_content_export void visitSlots(std::function<void(Slot*)>, const Variant& slotFilter = Variant());

	template<class Func, class CompareType, class Comp = std::equal_to<CompareType>>
	CompareType visitSlots(Func func, CompareType stopVal, CompareType finishVal, Comp comp = Comp())
	{
		for (Bay* bay : bays) {
			CompareType val = bay->visitSlots(func, stopVal, finishVal, comp);
			if (comp(val, stopVal))
				return val;
		}
		return finishVal;
	}
	template<typename Func>
	void visitSlots(Func func)
	{
		for (Bay* bay : bays) {
			bay->visitSlots(func);
		}
	}

	fs_content_export void setNumBays(int numBays, bool skipLocRefresh = false);
	Variant setNumBays(FLEXSIMINTERFACE) { setNumBays(param(1), (int)param(2)); return Variant(); }

	fs_content_export void setBaySize(double width, const Variant& bayFilter = Variant(), bool skipLocRefresh = false);
	Variant setBaySize(FLEXSIMINTERFACE) { setBaySize(param(1), param(2), (int)param(3)); return Variant(); }

	fs_content_export void setNumLevels(int numLevels, const Variant& bayFilter, bool skipLocRefresh = false);
	Variant setNumLevels(FLEXSIMINTERFACE) { setNumLevels(param(1), param(2), (int)param(3)); return Variant(); }

	fs_content_export void setLevelSize(double height, const Variant& levelFilter = Variant(), bool skipLocRefresh = false);
	Variant setLevelSize(FLEXSIMINTERFACE) { setLevelSize(param(1), param(2), (int)param(3)); return Variant(); }

	fs_content_export void setNumSlots(int numSlots, const Variant& slotFilter, bool skipLocRefresh = false);
	Variant setNumSlots(FLEXSIMINTERFACE) { setNumSlots(param(1), param(2), (int)param(3)); return Variant(); }

	fs_content_export void setSlotSize(double size, const Variant& slotFilter = Variant(), bool skipLocRefresh = false);
	Variant setSlotSize(FLEXSIMINTERFACE) { setSlotSize(param(1), param(2), (int)param(3)); return Variant(); }

	fs_content_export void setSlotStorable(bool isStorable, const Variant& slotFilter = Variant());
	Variant setSlotStorable(FLEXSIMINTERFACE) { setSlotStorable((int)param(1), param(2)); return Variant(); }

	fs_content_export void setSlotPadding(bool isUpperPadding, int vecIndex, double padding, const Variant& slotFilter = Variant());
	Variant setSlotPadding(FLEXSIMINTERFACE) { setSlotPadding((bool)(int)param(1), (int)param(2), (double)param(3), param(4)); return Variant(); }

	int batchDimensionUpdate = 0;
	Variant beginBatchDimensionUpdate(FLEXSIMINTERFACE) { batchDimensionUpdate++; return Variant(); }
	Variant endBatchDimensionUpdate(FLEXSIMINTERFACE);

	Variant getBaySize(FLEXSIMINTERFACE) { return getBaySize(param(1)); }
	Variant getLevelSize(FLEXSIMINTERFACE) { return getLevelSize(param(1), param(2)); }
	Variant getBayLoc(FLEXSIMINTERFACE) { return getBayLoc(param(1)); }
	Variant getLevelLoc(FLEXSIMINTERFACE) { return getLevelLoc(param(1), param(2)); }

	string getBayAlias(Bay* bay);
	Variant getBayAlias(FLEXSIMINTERFACE) { return getBayAlias(((TreeNode*)param(1))->objectAs(Bay)); }
	string getLevelAlias(Level* level);
	Variant getLevelAlias(FLEXSIMINTERFACE) { return getLevelAlias(((TreeNode*)param(1))->objectAs(Level)); }
	string getSlotAlias(Slot* slot);
	Variant getSlotAlias(FLEXSIMINTERFACE) { return getSlotAlias(((TreeNode*)param(1))->objectAs(Slot)); }

	Variant refreshBayLevelSlotLocations(FLEXSIMINTERFACE) { refreshBayLevelSlotLocations(); return Variant(); }
	Variant updateProgressions(FLEXSIMINTERFACE) { updateProgressions(); return Variant(); }

	fs_content_export virtual double onDrag(treenode view) override;
	fs_content_export double onClick(treenode view, int code) override;
	fs_content_export double onUndo(bool isUndo, treenode undoRecord) override { rebuildMeshes = true; return 0; }

	fs_content_export double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO) override;

	fs_content_export double onReset() override;

	fs_content_export double onReceive(treenode item, int port) override;


	fs_content_export void onItemSlotAssigned(Slot* slot, Slot::Item* data);

	fs_content_export double onTimerEvent(treenode involved, int code, char *datastr) override;

	fs_content_export double onSend(treenode item, int port) override;

	static const int DRAW_RACK = 1;
	static const int DRAW_SLOTS = 2;
	static const int DRAW_BOX = 3;
	static const int DRAW_LINES = 4;
	static const int DRAW_VISUALIZATION = 5;

	fs_content_export double onDraw(treenode view) override;

	fs_content_export virtual double getPickOffset(treenode item, treenode toobject, double* returnarray) override;

	fs_content_export virtual double getPlaceOffset(treenode item, treenode fromobject, double* returnarray) override;

	fs_content_export Slot* assignSlot(Item* data, bool throwOnFail);
	fs_content_export Slot* assignSlot(treenode item);

	fs_content_export virtual double onTransportOutNotify(treenode item, int port) override;

	fs_content_export virtual double onTransportOutComplete(treenode item, int port, treenode transporter = nullptr) override;

	fs_content_export virtual double onTransportInNotify(treenode item, int portnumber) override;

	fs_content_export virtual void onTransportInFailed(treenode item, int port) override;

	fs_content_export virtual double onPreDraw(treenode view) override;

	fs_content_export double getBayOfItem(treenode item);

	fs_content_export double getBayLoc(int bay);

	fs_content_export double getBaySize(int bay);

	fs_content_export double getItemSlotRank(treenode item);

	fs_content_export double getLevelOfItem(treenode item);

	fs_content_export double getLevelLoc(int bay, int level);

	fs_content_export double getLevelSize(int bay, int level);

	fs_content_export treenode getItem(int bay, int level, int position, int rankinslot);

	fs_content_export double getBayContent(int bay);

	fs_content_export double getSlotContent(int bay, int level, int position);

	fs_content_export double getNrOfBays();

	fs_content_export double getNrOfLevels(int bay DEFAULTONE);

	fs_content_export virtual double drawFilledSlot(int bay, int level, int position, double x, double y, double z, double sx, double sy, double sz, int red, int green, int blue, int glbeginend DEFAULTONE);
	fs_content_export double recycleItem(treenode item, int binrank);

	fs_content_export treenode  restoreItem(int binrank, int bay, int level, int position, int itemRank);

	fs_content_export double setSlotContent(int bay, int level, int position, int contentval);

	fs_content_export virtual double drawVirtualContent(double bayfillperc, double levelfillperc, double itemdepth, double red, double green, double blue, int onlyvirtual DEFAULTONE);

	fs_content_export double saveState() override;

	fs_content_export double loadState() override;

	fs_content_export virtual double copyVariables(treenode otherobject) override;

	fs_content_export double checkRebuildMeshes();

	fs_content_export double buildFlatSlotMesh();

	fs_content_export double buildBoxMesh();

	fs_content_export double buildLineMesh();

	fs_content_export void buildPickableSlotMesh();

	fs_content_export void refreshBayLevelSlotLocations();

	fs_content_export void setBasicDimensions(int numBays, double bayWidth, int numLevels, double levelHeight, int numPositions);

	fs_content_export virtual void onDragConnection(ObjectDataType* fromObj, ObjectDataType* toObj, char charPressed) override;

	double meshHash = 0;
	fs_content_export double calculateMeshHash();

	TreeNode* placeinbay;
	TreeNode* placeinlevel;

	TreeNode* slotAssignment;
	TreeNode* minimumstaytime;
	TreeNode* entrytrigger;
	double enableFRLogic;
	double maxcontent;
	double rackdrawmode;
	double markreadytogo;
	ByteBlock zoneID;
	ByteBlock aisleID;

	static const int STACKING_AXIS_NONE = 0;
	static const int STACKING_AXIS_X = 1;
	static const int STACKING_AXIS_NEG_X = 2;
	static const int STACKING_AXIS_Y = 3;
	static const int STACKING_AXIS_NEG_Y = 4;
	static const int STACKING_AXIS_Z = 5;
	static const int STACKING_AXIS_NEG_Z = 6;
	double stackingAxis1;
	double stackingAxis2;
	double stackingAxis3;

	TreeNode* onSlotEntry = nullptr;
	TreeNode* onSlotExit = nullptr;
	TreeNode* onSlotAssign = nullptr;

	struct StackingInfo {
		Vec3 progressionFromMarker;
		int axes[4];
		int vectorIndex[4];
		void cache(StorageObject* obj);
	} stackingInfo;

	void onSlotLabelValueChange(Slot* slot, TreeNode* label, const Variant& newValue);

	enum Progression : int {Positive = 1, Negative = -1, None = 0};
	fs_content_export Progression getBayProgressionFromGeometry();
	fs_content_export Progression getLevelProgressionFromGeometry();
	fs_content_export Progression getSlotProgressionFromGeometry();
	void updateProgressions();
	double bayProgression;
	double levelProgression;
	double slotProgression;

	typedef StorageSystem::Visualization::ElementMeshEntry ElementMeshEntry;
	static ObjRef<StorageSystem::Visualization::Element> drawElementBoundingBox;
	static bool drawSlotMeshBoundingBoxOutlines;
	static Mesh slotBoundingBoxMesh;
	static bool isSlotBoundingBoxMeshInitialized;
	Variant setDrawElementBoundingBox(FLEXSIMINTERFACE);

	ObjRef<StorageSystem::Visualization> visualization;
	fs_content_export StorageSystem::Visualization* getEffectiveVisualization();
	struct ElementLess {
		bool operator()(const Visualization::Element* left, const Visualization::Element* right) const
		{
			if (!left)
				return right != nullptr;
			if (!right)
				return false;
			unsigned short leftVisRank = (unsigned short)left->holder->up->up->rank;
			unsigned short leftElementRank = (unsigned short)left->holder->rank;
			unsigned int leftVal = (leftVisRank << 16) | leftElementRank;
			unsigned short rightVisRank = (unsigned short)right->holder->up->up->rank;
			unsigned short rightElementRank = (unsigned short)right->holder->rank;
			unsigned int rightVal = (rightVisRank << 16) | rightElementRank;
			return leftVal < rightVal;
		}
	};
	using ElementMeshMap = std::map<Visualization::Element*, std::unique_ptr<Visualization::ElementMeshEntry>, ElementLess>;
	std::unique_ptr<ElementMeshMap> slotMeshes;
	fs_content_export void initializeSlotMeshes();
	fs_content_export void rebuildSlotMesh(StorageSystem::Visualization::ElementMeshEntry& entry, Visualization::Element* element);

	SlotLabelMatchCache slotLabelMatchCache;
	bool areSlotLabelsEqual(const char* labelName) {
		return slotLabelMatchCache.check(labelName, [this]() {
			visitSlots([this](Slot* slot) { 
				return slotLabelMatchCache.check(slot);
			}, false, true);
		});
	}
	bool areSlotLabelsEqual(const char* labelName, const Variant& value)
	{
		return slotLabelMatchCache.check(labelName, value, [this]() {
			visitSlots([this](Slot* slot) { 
				return slotLabelMatchCache.check(slot);
			}, false, true);
		});
	}
	void setSlotLabels(const char* labelName, const Variant& value)
	{
		visitSlots([&](Slot* slot) {slot->setLabel(labelName, value); });
	}

	static const int FIFO = 1;
	static const int LIFO = 2;
	virtual int getPickingOrder() { return stackingAxis2 == 0 ? FIFO : LIFO; }
	virtual void setInitialDimensions() {
		setBasicDimensions(8, 2.5 / getmodelunit(LENGTH_MULTIPLE), 6, 1.4 / getmodelunit(LENGTH_MULTIPLE), 2);
	}

	fs_content_export virtual void onSlotReceive(Slot* slot, StorageObject::Item* item);
	fs_content_export virtual void onSlotSend(Slot* slot, StorageObject::Item* item);
	fs_content_export virtual void setItemStackingLocation(Slot* slot, Slot::Item* slotItem, StorageObject::Item* data) { slot->setItemStackingLocation(slotItem, data); }

	virtual const char* getDefaultVisualizationName() { return "Rack"; }

	NodeListArray<StorageSystem::VirtualizedItem::StorageObjectItemMeshData>::CouplingSdtSubNodeBindingType virtualizedItemMeshData;
	
	using VirtualizedItemMeshMap = std::unordered_map<
		StorageSystem::VirtualizedItem::StorageData::Key,
		StorageSystem::VirtualizedItem::StorageObjectItemMeshData*,
		StorageSystem::VirtualizedItem::StorageData::Hash
	>;
	std::unique_ptr<VirtualizedItemMeshMap> virtualizedItemMeshDataMap;
	fs_content_export void refreshVirtualizedItemMeshDataMap();

//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// Rack
class Rack : public StorageObject
{
public:


//ClassIncludeHeaderStart

fs_content_export virtual void bindVariables() override;
fs_content_export virtual Rack* toRack() override { return this; }
fs_content_export virtual double onReset() override;
fs_content_export double buildFullMeshes();
fs_content_export void setTiltAngle(StorageObject::Item* item);

//ClassIncludeHeaderEnd

// c++ member functions

TreeNode* node_v_pickplaceyoffset;
#define v_pickplaceyoffset node_v_pickplaceyoffset->safedatafloat()[0]
TreeNode* node_v_tiltvalue;
#define v_tiltvalue node_v_tiltvalue->safedatafloat()[0]
TreeNode* node_v_tiltangle;
#define v_tiltangle node_v_tiltangle->safedatafloat()[0]
TreeNode* node_v_hidefloor;
#define v_hidefloor node_v_hidefloor->safedatafloat()[0]
TreeNode* node_v_extendcolumn;
#define v_extendcolumn node_v_extendcolumn->safedatafloat()[0]

// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// GravityFlowRack
class GravityFlowRack : public Rack
{
public:


//ClassIncludeHeaderStart
	fs_content_export GravityFlowRack();
	double flowSpeed;

	// hasPreDrawFiredSinceReset is a variable for optimization of my flowingSlots set
	bool hasPreDrawFiredSinceReset = false;
	double lastFlowUpdateTime = -1;
	std::unique_ptr<std::set<Slot*>> flowingSlots;
	fs_content_export virtual void bindVariables() override;
	fs_content_export virtual double onReset() override;
	fs_content_export virtual double onTimerEvent(treenode involved, int code, char *datastr) override;
	fs_content_export virtual GravityFlowRack* toGravityFlowRack() override { return this; }
	fs_content_export virtual void setInitialDimensions() override {
		setBasicDimensions(5, 2.5 / getmodelunit(LENGTH_MULTIPLE), 6, 0.4 / getmodelunit(LENGTH_MULTIPLE), 4);
	}
	FS_CONTENT_DLL_FUNC virtual double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO) override;

	FS_CONTENT_DLL_FUNC virtual double getPlaceOffset(treenode involvedobj, treenode fromobject, double* returnarray) override;

	FS_CONTENT_DLL_FUNC virtual double getPickOffset(treenode item, treenode toobject, double* returnarray) override;
	fs_content_export virtual void onSlotReceive(Slot* slot, StorageObject::Item* item) override;
	fs_content_export virtual void onSlotSend(Slot* slot, StorageObject::Item* item) override;
	fs_content_export virtual double updateLocations() override;
	fs_content_export virtual const char* getDefaultVisualizationName() override { return "Gravity Flow Rack"; }

//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// PushBackRack
class PushBackRack : public GravityFlowRack
{
public:


//ClassIncludeHeaderStart

virtual PushBackRack* toPushBackRack() override { return this; }
fs_content_export double getPickPlaceOffset(treenode involved, treenode fromObj, double* returnArray, bool isPickOffset);
virtual double getPlaceOffset(treenode involved, treenode fromObj, double* returnArray) override
{
	return getPickPlaceOffset(involved, fromObj, returnArray, false);
}
virtual double getPickOffset(treenode involved, treenode toObj, double* returnArray) override
{
	return getPickPlaceOffset(involved, toObj, returnArray, true);
}
fs_content_export virtual void setItemStackingLocation(Slot* slot, Slot::Item* slotItem, StorageObject::Item* data) override;

fs_content_export virtual void setInitialDimensions() override;
fs_content_export virtual const char* getDefaultVisualizationName() override { return "Push Back Rack"; }

fs_content_export virtual void onSlotReceive(Slot* slot, StorageObject::Item* item) override;

//ClassIncludeHeaderEnd

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// DriveInRack
class DriveInRack : public Rack
{
public:


//ClassIncludeHeaderStart

fs_content_export virtual void bind() override;
fs_content_export bool isDriveThrough() { return stackingAxis1 == STACKING_AXIS_Y; }
fs_content_export virtual int getPickingOrder() override { return isDriveThrough() ? FIFO : LIFO; }
fs_content_export virtual void bindVariables() override;
fs_content_export virtual double onTimerEvent(treenode involved, int code, char *datastr) override;
fs_content_export virtual DriveInRack* toDriveInRack() override { return this; }
fs_content_export double getPickPlaceOffset(treenode involved, treenode fromObj, double* returnArray, bool isPickOffset);
fs_content_export virtual double getPlaceOffset(treenode involved, treenode fromObj, double* returnArray) override
{ 
	return getPickPlaceOffset(involved, fromObj, returnArray, false); 
}
fs_content_export virtual double getPickOffset(treenode involved, treenode toObj, double* returnArray) override
{
	return getPickPlaceOffset(involved, toObj, returnArray, true);
}

fs_content_export virtual void onSlotReceive(Slot* slot, StorageObject::Item* item) override;
fs_content_export virtual void onSlotSend(Slot* slot, StorageObject::Item* item) override;

fs_content_export virtual void setInitialDimensions() override
{
	setBasicDimensions(10, 1.5 / getmodelunit(LENGTH_MULTIPLE), 4, 1.5 / getmodelunit(LENGTH_MULTIPLE), 1);
}
fs_content_export virtual const char* getDefaultVisualizationName() override { return "Drive In Rack"; }
fs_content_export void customizeAStarGrid(TreeNode* navigator, double nodeWidth);
Variant customizeAStarGrid(FLEXSIMINTERFACE) { customizeAStarGrid(param(1), param(2)); return 1; }


//ClassIncludeHeaderEnd

// System

fs_content_export static int getAllocSize();
};

// FloorStorage
class FloorStorage : public StorageObject
{
public:


//ClassIncludeHeaderStart

	fs_content_export virtual FloorStorage* toFloorStorage() override { return this; }
	FS_CONTENT_DLL_FUNC virtual double onCreate(double dropx, double dropy, double dropz, int iscopy DEFAULTZERO) override;

	fs_content_export virtual int getPickingOrder() override { return LIFO; }

	fs_content_export virtual const char* getDefaultVisualizationName() override { return "Floor Storage"; }

	fs_content_export virtual void setInitialDimensions() override
	{
		setBasicDimensions(10, 1.0 / getmodelunit(LENGTH_MULTIPLE), 10, 1.0 / getmodelunit(LENGTH_MULTIPLE), 1);
	}
//ClassIncludeHeaderEnd

// c++ member functions


// System

fs_content_export void bindVariablesDefault();

fs_content_export static int getAllocSize();
};

// FluidTicker
class FluidTicker : public FlexSimObject
{
public:


// c++ member functions

fs_content_export double defines();

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export double sortObjectList();

fs_content_export double quickSort(treenode table, int low, int high);

fs_content_export double assignValue(treenode obj);

fs_content_export treenode getLink(treenode obj);

fs_content_export double doTick();

fs_content_export double prepareForTick();

fs_content_export double moveFluid();

fs_content_export double completeTick();

fs_content_export double getTransferAmount(treenode upstreamobj, treenode downstreamobj, int outportnum);

fs_content_export static treenode findDefaultTicker();

TreeNode* node_v_ticktime;
#define v_ticktime node_v_ticktime->safedatafloat()[0]
TreeNode* node_v_objectlist;
#define v_objectlist node_v_objectlist->safedatafloat()[0]
TreeNode* node_v_maxcomponents;
#define v_maxcomponents node_v_maxcomponents->safedatafloat()[0]
TreeNode* node_v_lasttick;
#define v_lasttick node_v_lasttick->safedatafloat()[0]
TreeNode* node_v_resettrigger;
TreeNode* node_v_messagetrigger;
TreeNode* node_v_ondrawtrigger;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidObject
class FluidObject : public FlexSimObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double onDraw(treenode view);

fs_content_export virtual double updateLocations();

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export double connectToTicker();

fs_content_export double connectToTicker(treenode ticker);

fs_content_export double copyProductId(treenode upstreamobj,double amount);

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double prepareMoveFluid();

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

fs_content_export virtual double moveMaterialIn(double amount, int port);

fs_content_export virtual double moveMaterialOut(double amount, int port);

fs_content_export virtual double emptyObject();

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_curcontent;
#define v_curcontent node_v_curcontent->safedatafloat()[0]
TreeNode* node_v_productid;
#define v_productid node_v_productid->safedatafloat()[0]
TreeNode* node_v_maxobjectinrate;
#define v_maxobjectinrate node_v_maxobjectinrate->safedatafloat()[0]
TreeNode* node_v_maxportinrate;
#define v_maxportinrate node_v_maxportinrate->safedatafloat()[0]
TreeNode* node_v_portinratescalefactors;
#define v_portinratescalefactors node_v_portinratescalefactors->safedatafloat()[0]
TreeNode* node_v_maxobjectoutrate;
#define v_maxobjectoutrate node_v_maxobjectoutrate->safedatafloat()[0]
TreeNode* node_v_maxportoutrate;
#define v_maxportoutrate node_v_maxportoutrate->safedatafloat()[0]
TreeNode* node_v_portoutratescalefactors;
#define v_portoutratescalefactors node_v_portoutratescalefactors->safedatafloat()[0]
TreeNode* node_v_lastinputamount;
#define v_lastinputamount node_v_lastinputamount->safedatafloat()[0]
TreeNode* node_v_lastoutputamount;
#define v_lastoutputamount node_v_lastoutputamount->safedatafloat()[0]
TreeNode* node_v_barlocx;
#define v_barlocx node_v_barlocx->safedatafloat()[0]
TreeNode* node_v_barlocy;
#define v_barlocy node_v_barlocy->safedatafloat()[0]
TreeNode* node_v_barlocz;
#define v_barlocz node_v_barlocz->safedatafloat()[0]
TreeNode* node_v_barrotx;
#define v_barrotx node_v_barrotx->safedatafloat()[0]
TreeNode* node_v_barroty;
#define v_barroty node_v_barroty->safedatafloat()[0]
TreeNode* node_v_barrotz;
#define v_barrotz node_v_barrotz->safedatafloat()[0]
TreeNode* node_v_barsizex;
#define v_barsizex node_v_barsizex->safedatafloat()[0]
TreeNode* node_v_barsizey;
#define v_barsizey node_v_barsizey->safedatafloat()[0]
TreeNode* node_v_barsizez;
#define v_barsizez node_v_barsizez->safedatafloat()[0]
TreeNode* node_v_barcylinder;
#define v_barcylinder node_v_barcylinder->safedatafloat()[0]
TreeNode* node_v_drawbar;
#define v_drawbar node_v_drawbar->safedatafloat()[0]
TreeNode* node_v_objectstats;
#define v_objectstats node_v_objectstats->safedatafloat()[0]
TreeNode* node_v_resettrigger;
TreeNode* node_v_messagetrigger;
TreeNode* node_v_ondrawtrigger;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidTank
class FluidTank : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_lowmark;
#define v_lowmark node_v_lowmark->safedatafloat()[0]
TreeNode* node_v_midmark;
#define v_midmark node_v_midmark->safedatafloat()[0]
TreeNode* node_v_highmark;
#define v_highmark node_v_highmark->safedatafloat()[0]
TreeNode* node_v_lowmarktrigger;
TreeNode* node_v_midmarktrigger;
TreeNode* node_v_highmarktrigger;
TreeNode* node_v_adjustinputrates;
TreeNode* node_v_adjustoutputrates;
TreeNode* node_v_emptytrigger;
TreeNode* node_v_fulltrigger;
TreeNode* node_v_initialcontent;
#define v_initialcontent node_v_initialcontent->safedatafloat()[0]
TreeNode* node_v_initialproductid;
#define v_initialproductid node_v_initialproductid->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidGenerator
class FluidGenerator : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_refillmode;
#define v_refillmode node_v_refillmode->safedatafloat()[0]
TreeNode* node_v_refilldelay;
#define v_refilldelay node_v_refilldelay->safedatafloat()[0]
TreeNode* node_v_refillrate;
#define v_refillrate node_v_refillrate->safedatafloat()[0]
TreeNode* node_v_emptytrigger;
TreeNode* node_v_fulltrigger;
TreeNode* node_v_initialcontent;
#define v_initialcontent node_v_initialcontent->safedatafloat()[0]
TreeNode* node_v_initialproductid;
#define v_initialproductid node_v_initialproductid->safedatafloat()[0]
TreeNode* node_v_adjustoutputrates;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidTerminator
class FluidTerminator : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double materialMovedIn(double amount, int port);

fs_content_export virtual double updateLocations();

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_adjustinputrates;
TreeNode* node_v_totalinput;
#define v_totalinput node_v_totalinput->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidMixer
class FluidMixer : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onTimerEvent(treenode involved, int code, char *strdata);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double onDraw(treenode view);

fs_content_export virtual double updateLocations();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double moveMaterialIn(double amount, int port);

fs_content_export virtual double emptyObject();

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_curstep;
#define v_curstep node_v_curstep->safedatafloat()[0]
TreeNode* node_v_targetproductid;
#define v_targetproductid node_v_targetproductid->safedatafloat()[0]
TreeNode* node_v_steptable;
#define v_steptable node_v_steptable->safedatafloat()[0]
TreeNode* node_v_recipetable;
#define v_recipetable node_v_recipetable->safedatafloat()[0]
TreeNode* node_v_currentsteptable;
#define v_currentsteptable node_v_currentsteptable->safedatafloat()[0]
TreeNode* node_v_portcolortable;
#define v_portcolortable node_v_portcolortable->safedatafloat()[0]
TreeNode* node_v_adjustoutputrates;
TreeNode* node_v_emptytrigger;
TreeNode* node_v_beforedelaytrigger;
TreeNode* node_v_afterdelaytrigger;
TreeNode* node_v_indelay;
#define v_indelay node_v_indelay->safedatafloat()[0]
TreeNode* node_v_collecting;
#define v_collecting node_v_collecting->safedatafloat()[0]
TreeNode* node_v_usermaxoutrate;
#define v_usermaxoutrate node_v_usermaxoutrate->safedatafloat()[0]
TreeNode* node_v_batchstarttime;
#define v_batchstarttime node_v_batchstarttime->safedatafloat()[0]
TreeNode* node_v_totalbatchtime;
#define v_totalbatchtime node_v_totalbatchtime->safedatafloat()[0]
TreeNode* node_v_numbatches;
#define v_numbatches node_v_numbatches->safedatafloat()[0]
TreeNode* node_v_avgbatchtime;
#define v_avgbatchtime node_v_avgbatchtime->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidBlender
class FluidBlender : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double updateLocations();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_maxtotalinrate;
#define v_maxtotalinrate node_v_maxtotalinrate->safedatafloat()[0]
TreeNode* node_v_targetproductid;
#define v_targetproductid node_v_targetproductid->safedatafloat()[0]
TreeNode* node_v_recipetable;
#define v_recipetable node_v_recipetable->safedatafloat()[0]
TreeNode* node_v_adjustoutputrates;
TreeNode* node_v_curoutrate;
#define v_curoutrate node_v_curoutrate->safedatafloat()[0]
TreeNode* node_v_avgoutrate;
#define v_avgoutrate node_v_avgoutrate->safedatafloat()[0]
TreeNode* node_v_numupdates;
#define v_numupdates node_v_numupdates->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidSplitter
class FluidSplitter : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double updateLocations();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_maxtotaloutrate;
#define v_maxtotaloutrate node_v_maxtotaloutrate->safedatafloat()[0]
TreeNode* node_v_recipetable;
#define v_recipetable node_v_recipetable->safedatafloat()[0]
TreeNode* node_v_adjustinputrates;
TreeNode* node_v_curinrate;
#define v_curinrate node_v_curinrate->safedatafloat()[0]
TreeNode* node_v_avginrate;
#define v_avginrate node_v_avginrate->safedatafloat()[0]
TreeNode* node_v_numupdates;
#define v_numupdates node_v_numupdates->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidPipe
class FluidPipe : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double updateLocations();

fs_content_export virtual double onDraw(treenode view);

fs_content_export double drawPipe(double color1, double color2, double color3);

fs_content_export double drawConveyor(treenode view, double color1, double color2, double color3);

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double emptyObject();

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_maxflowrate;
#define v_maxflowrate node_v_maxflowrate->safedatafloat()[0]
TreeNode* node_v_tablerate;
#define v_tablerate node_v_tablerate->safedatafloat()[0]
TreeNode* node_v_transfertime;
#define v_transfertime node_v_transfertime->safedatafloat()[0]
TreeNode* node_v_flowmode;
#define v_flowmode node_v_flowmode->safedatafloat()[0]
TreeNode* node_v_accumulated;
#define v_accumulated node_v_accumulated->safedatafloat()[0]
TreeNode* node_v_futureoutputrates;
#define v_futureoutputrates node_v_futureoutputrates->safedatafloat()[0]
TreeNode* node_v_adjustinputrates;
TreeNode* node_v_adjustoutputrates;
TreeNode* node_v_emptytrigger;
TreeNode* node_v_fulltrigger;
TreeNode* node_v_pipesections;
#define v_pipesections node_v_pipesections->safedatafloat()[0]
TreeNode* node_v_curoutrate;
#define v_curoutrate node_v_curoutrate->safedatafloat()[0]
TreeNode* node_v_avgoutrate;
#define v_avgoutrate node_v_avgoutrate->safedatafloat()[0]
TreeNode* node_v_numupdates;
#define v_numupdates node_v_numupdates->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidProcessor
class FluidProcessor : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double updateLocations();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double emptyObject();

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_maxflowrate;
#define v_maxflowrate node_v_maxflowrate->safedatafloat()[0]
TreeNode* node_v_tablerate;
#define v_tablerate node_v_tablerate->safedatafloat()[0]
TreeNode* node_v_transfertime;
#define v_transfertime node_v_transfertime->safedatafloat()[0]
TreeNode* node_v_loss;
#define v_loss node_v_loss->safedatafloat()[0]
TreeNode* node_v_accumulated;
#define v_accumulated node_v_accumulated->safedatafloat()[0]
TreeNode* node_v_futureoutputrates;
#define v_futureoutputrates node_v_futureoutputrates->safedatafloat()[0]
TreeNode* node_v_receiveportnumber;
TreeNode* node_v_destinationportnumber;
TreeNode* node_v_emptytrigger;
TreeNode* node_v_fulltrigger;
TreeNode* node_v_curoutrate;
#define v_curoutrate node_v_curoutrate->safedatafloat()[0]
TreeNode* node_v_avgoutrate;
#define v_avgoutrate node_v_avgoutrate->safedatafloat()[0]
TreeNode* node_v_numupdates;
#define v_numupdates node_v_numupdates->safedatafloat()[0]

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidObject2
class FluidObject2 : public FixedResource
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export double onOutOpen(int port);

fs_content_export virtual double onReset();

fs_content_export double resetVariables();

fs_content_export virtual double onDraw(treenode view);

fs_content_export virtual double updateLocations();

fs_content_export virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype);

fs_content_export double copyProductId(treenode upstreamobj,double amount);

fs_content_export double connectToTicker();

fs_content_export double connectToTicker(treenode ticker);

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double emptyObject();

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

fs_content_export virtual double moveMaterialIn(double amount, int port);

fs_content_export virtual double moveMaterialOut(double amount, int port);

fs_content_export virtual unsigned int getClassType();

fs_content_export virtual void stopAndSetState(int stopstate, int stateprofile DEFAULTZERO);

fs_content_export virtual void resume();

TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_curcontent;
#define v_curcontent node_v_curcontent->safedatafloat()[0]
TreeNode* node_v_productid;
#define v_productid node_v_productid->safedatafloat()[0]
TreeNode* node_v_maxobjectinrate;
#define v_maxobjectinrate node_v_maxobjectinrate->safedatafloat()[0]
TreeNode* node_v_maxportinrate;
#define v_maxportinrate node_v_maxportinrate->safedatafloat()[0]
TreeNode* node_v_portinratescalefactors;
#define v_portinratescalefactors node_v_portinratescalefactors->safedatafloat()[0]
TreeNode* node_v_maxobjectoutrate;
#define v_maxobjectoutrate node_v_maxobjectoutrate->safedatafloat()[0]
TreeNode* node_v_maxportoutrate;
#define v_maxportoutrate node_v_maxportoutrate->safedatafloat()[0]
TreeNode* node_v_portoutratescalefactors;
#define v_portoutratescalefactors node_v_portoutratescalefactors->safedatafloat()[0]
TreeNode* node_v_lastinputamount;
#define v_lastinputamount node_v_lastinputamount->safedatafloat()[0]
TreeNode* node_v_lastoutputamount;
#define v_lastoutputamount node_v_lastoutputamount->safedatafloat()[0]
TreeNode* node_v_barlocx;
#define v_barlocx node_v_barlocx->safedatafloat()[0]
TreeNode* node_v_barlocy;
#define v_barlocy node_v_barlocy->safedatafloat()[0]
TreeNode* node_v_barlocz;
#define v_barlocz node_v_barlocz->safedatafloat()[0]
TreeNode* node_v_barrotx;
#define v_barrotx node_v_barrotx->safedatafloat()[0]
TreeNode* node_v_barroty;
#define v_barroty node_v_barroty->safedatafloat()[0]
TreeNode* node_v_barrotz;
#define v_barrotz node_v_barrotz->safedatafloat()[0]
TreeNode* node_v_barsizex;
#define v_barsizex node_v_barsizex->safedatafloat()[0]
TreeNode* node_v_barsizey;
#define v_barsizey node_v_barsizey->safedatafloat()[0]
TreeNode* node_v_barsizez;
#define v_barsizez node_v_barsizez->safedatafloat()[0]
TreeNode* node_v_barcylinder;
#define v_barcylinder node_v_barcylinder->safedatafloat()[0]
TreeNode* node_v_drawbar;
#define v_drawbar node_v_drawbar->safedatafloat()[0]
TreeNode* node_v_objectstats;
#define v_objectstats node_v_objectstats->safedatafloat()[0]
TreeNode* node_v_resettrigger;
TreeNode* node_v_messagetrigger;
TreeNode* node_v_ondrawtrigger;
TreeNode* node_v_entrytrigger;
TreeNode* node_v_exittrigger;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// ItemToFluid
class ItemToFluid : public FluidObject2
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export double onReset();

fs_content_export double onReceive(treenode item, int port);

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double resetVariables();

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_fluidunitsperdiscrete;
#define v_fluidunitsperdiscrete node_v_fluidunitsperdiscrete->safedatafloat()[0]
TreeNode* node_v_chunksize;
#define v_chunksize node_v_chunksize->safedatafloat()[0]
TreeNode* node_v_recycle;
#define v_recycle node_v_recycle->safedatafloat()[0]
TreeNode* node_v_initialproductid;
#define v_initialproductid node_v_initialproductid->safedatafloat()[0]
TreeNode* node_v_adjustoutputrates;
TreeNode* node_v_emptytrigger;
TreeNode* node_v_fulltrigger;

// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidToItem
class FluidToItem : public FluidObject2
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export double onReset();

fs_content_export double onTimerEvent(treenode involved, int code, char *datastr);

fs_content_export double onSend(treenode item, int port);

fs_content_export double resetVariables();

fs_content_export double generateItem(double curitemtype, string itemname);

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double completeTick(double ticktime);

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

TreeNode* node_v_flowitemclass;
#define v_flowitemclass node_v_flowitemclass->safedatafloat()[0]
TreeNode* node_v_flowitemname;
TreeNode* node_v_flowitemtype;
#define v_flowitemtype node_v_flowitemtype->safedatafloat()[0]
TreeNode* node_v_fluidunitsperdiscrete;
#define v_fluidunitsperdiscrete node_v_fluidunitsperdiscrete->safedatafloat()[0]
TreeNode* node_v_chunksize;
#define v_chunksize node_v_chunksize->safedatafloat()[0]
TreeNode* node_v_creationtrigger;
TreeNode* node_v_flowitembin;
#define v_flowitembin node_v_flowitembin->safedatafloat()[0]
TreeNode* node_v_adjustinputrates;

// c++ attributes
treenode flowitemtocreate;

int itemsmade;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

// FluidConveyor
class FluidConveyor : public FluidObject
{
public:


// c++ member functions

fs_content_export virtual double onCreate(double xloc, double yloc, double zloc, int iscopy DEFAULTZERO);

fs_content_export virtual double onReset();

fs_content_export double onKeyedClick(treenode view, int code, char key);

fs_content_export double resetVariables();

fs_content_export double updateConveyorInfo(double slicewidth, double leftend_y, double rightend_y);

fs_content_export virtual double updateLocations();

fs_content_export virtual double onDraw(treenode view);

fs_content_export double sensorCheck();

fs_content_export double rotateSlices();

fs_content_export double materialRepose(double reposerate, int onlyfalling);

fs_content_export virtual double prepareForTick(double ticktime);

fs_content_export virtual double prepareMoveFluid();

fs_content_export virtual double completeTick(double ticktime);

fs_content_export int updateInputs();

fs_content_export int updateOutputs();

fs_content_export int updateSensors();

fs_content_export virtual double emptyObject();

fs_content_export virtual double updateStats(double ticktime);

fs_content_export double statsFunction(double ticktime);

fs_content_export virtual double moveMaterialIn(double amount, int port);

fs_content_export virtual double moveMaterialOut(double amount, int port);

TreeNode* node_v_numberofslices;
#define v_numberofslices node_v_numberofslices->safedatafloat()[0]
TreeNode* node_v_slicewidth;
#define v_slicewidth node_v_slicewidth->safedatafloat()[0]
TreeNode* node_v_outputwidth;
#define v_outputwidth node_v_outputwidth->safedatafloat()[0]
TreeNode* node_v_centerlineoffset;
#define v_centerlineoffset node_v_centerlineoffset->safedatafloat()[0]
TreeNode* node_v_sidewallheight;
#define v_sidewallheight node_v_sidewallheight->safedatafloat()[0]
TreeNode* node_v_legheight;
#define v_legheight node_v_legheight->safedatafloat()[0]
TreeNode* node_v_layout_aux;
#define v_layout_aux node_v_layout_aux->safedatafloat()[0]
TreeNode* node_v_previouslayout;
#define v_previouslayout node_v_previouslayout->safedatafloat()[0]
TreeNode* node_v_materialcolor;
#define v_materialcolor node_v_materialcolor->safedatafloat()[0]
TreeNode* node_v_direction_default;
#define v_direction_default node_v_direction_default->safedatafloat()[0]
TreeNode* node_v_direction_current;
#define v_direction_current node_v_direction_current->safedatafloat()[0]
TreeNode* node_v_direction_target;
#define v_direction_target node_v_direction_target->safedatafloat()[0]
TreeNode* node_v_speed_default;
#define v_speed_default node_v_speed_default->safedatafloat()[0]
TreeNode* node_v_speed_current;
#define v_speed_current node_v_speed_current->safedatafloat()[0]
TreeNode* node_v_speed_target;
#define v_speed_target node_v_speed_target->safedatafloat()[0]
TreeNode* node_v_acceleration_default;
#define v_acceleration_default node_v_acceleration_default->safedatafloat()[0]
TreeNode* node_v_acceleration_current;
#define v_acceleration_current node_v_acceleration_current->safedatafloat()[0]
TreeNode* node_v_angleofrepose;
#define v_angleofrepose node_v_angleofrepose->safedatafloat()[0]
TreeNode* node_v_reposerate;
#define v_reposerate node_v_reposerate->safedatafloat()[0]
TreeNode* node_v_reposeend;
#define v_reposeend node_v_reposeend->safedatafloat()[0]
TreeNode* node_v_maxsliceheightdifference;
#define v_maxsliceheightdifference node_v_maxsliceheightdifference->safedatafloat()[0]
TreeNode* node_v_endslicefraction;
#define v_endslicefraction node_v_endslicefraction->safedatafloat()[0]
TreeNode* node_v_fallingslices;
#define v_fallingslices node_v_fallingslices->safedatafloat()[0]
TreeNode* node_v_slicesrotated;
#define v_slicesrotated node_v_slicesrotated->safedatafloat()[0]
TreeNode* node_v_allowspillage;
#define v_allowspillage node_v_allowspillage->safedatafloat()[0]
TreeNode* node_v_spillage;
#define v_spillage node_v_spillage->safedatafloat()[0]
TreeNode* node_v_lastspillageamount;
#define v_lastspillageamount node_v_lastspillageamount->safedatafloat()[0]
TreeNode* node_v_inputs;
#define v_inputs node_v_inputs->safedatafloat()[0]
TreeNode* node_v_outputs;
#define v_outputs node_v_outputs->safedatafloat()[0]
TreeNode* node_v_outputs_aux;
#define v_outputs_aux node_v_outputs_aux->safedatafloat()[0]
TreeNode* node_v_sensors;
#define v_sensors node_v_sensors->safedatafloat()[0]
TreeNode* node_v_conveyorcontent;
#define v_conveyorcontent node_v_conveyorcontent->safedatafloat()[0]
TreeNode* node_v_conveyorinfo;
#define v_conveyorinfo node_v_conveyorinfo->safedatafloat()[0]
TreeNode* node_v_lowmarktrigger;
TreeNode* node_v_midmarktrigger;
TreeNode* node_v_highmarktrigger;
TreeNode* node_v_emptytrigger;
TreeNode* node_v_fulltrigger;
TreeNode* node_v_initialcontent;
#define v_initialcontent node_v_initialcontent->safedatafloat()[0]
TreeNode* node_v_initialproductid;
#define v_initialproductid node_v_initialproductid->safedatafloat()[0]
TreeNode* node_v_maxcontent;
#define v_maxcontent node_v_maxcontent->safedatafloat()[0]
TreeNode* node_v_scalefactor;
#define v_scalefactor node_v_scalefactor->safedatafloat()[0]

// c++ attributes
IndexedMesh contentMesh;


// System

fs_content_export virtual void bindVariables();

fs_content_export static int getAllocSize();
};

}

#endif

