#pragma once
// COPYRIGHT 2006   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

#include "TreeNode.h"

#include "ByteBlock.h"
#include "SimpleDataType.h"
#include "CouplingDataType.h"

#define ODT ObjectDataType

#ifdef FLEXSIM_ENGINE_COMPILE
	#include "GLM.h"

	#define STATE_PROFILE_CURRENT 1
	#define STATE_PROFILE_SINCE 2
	#define STATE_PROFILE_LIST 3
#endif

#define CLASS_NAME_SEPARATOR ':'

class portcache;

namespace FlexSim {

class ObjectDataType;


class SplineCache
{
public:
	SplineCache() : nrEntries(0), entries(0), length(0.0), checkSum(0) {}
	~SplineCache();
	struct Entry
	{
		#ifdef FLEXSIM_ENGINE_COMPILE
			glm::dvec3 pos;
		#else
			double pos[3];
		#endif
		double distAlong;
		double percAlong;
	};
	
	#ifdef FLEXSIM_ENGINE_COMPILE
		void getRot(size_t entryIndex, glm::dvec3& rot);
	#endif
	void clear();
	void addEntries(size_t nrCachePoints);
	unsigned int calcCheckSum(treenode spline);
	void buildCache(treenode holder);

	Entry * entries;
	size_t nrEntries;
	double length;
	unsigned int checkSum;
	static double splineTension;
};

/***** The following class is only defined because I want to explicitly fire code when I start***/
class fireconstructor{
public:
	int dummyval;
	fireconstructor();
};


class _LOD
{
public:
  _LOD();
  int * LODtable;
  int LODtablesize;
  
  int LODresettable();
  int LODgetmember(int index);

  int LODaddtotable(int index);
  int LODgettablesize();

  double range_pers;
  double range_pers_type;
  double range_ortho;


};

class _REEL
{
public:
  _REEL();
  int * REELtable;
  int REELtablesize;
  
  int REELresettable();
  int REELgetmember(int index);

  int REELaddtotable(int index);
  int REELgettablesize();

  double range_pers;
  double range_pers_type;
  double range_ortho;
};

#ifdef FLEXSIM_ENGINE_COMPILE
	class TreeWinAttTable
	{
	public:
	  TreeWinAttTable(){};


	#define H_LOC_ODT_VARIABLE_TABLE(v,ODTMEMBERPREFIX)  \
	  TreeNode * NTable##ODTMEMBERPREFIX##v = nullptr; 
  
	  //              ATT ADDPOINT 7
  
	#define DECLARE_ATTRIBUTE(ATTRIBUTE_DEFAULT,ATTRIBUTE_NAME, ...) H_LOC_ODT_VARIABLE_TABLE(ATTRIBUTE_NAME,b_)
	#include "AttributesTreeWin.h"
	#undef DECLARE_ATTRIBUTE
	};
#else
	class TreeWinAttTable;
#endif



class ObjectDataType : public SimpleDataType
{
private:


	int reset();

public:
  
	void* operator new (size_t size)
	{
		void* p = flexsimmalloc(size);
		if(!p) throw 0;
		return p;
	}

	void operator delete (void* p){flexsimfree(p);}

	engine_export void initialize();
	ObjectDataType(){initialize();}
	engine_export void cleanup();
	virtual ~ObjectDataType(){cleanup();}
	int resetbasetable();

	// The following method was added by Anthony Johnson 2-16-2006
	virtual unsigned int getClassType() override {return 0;}
	virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype) override {return 0;}

	TreeNodeListHead objecttree;

	ScenePositionCache* sceneCache;
  
	portcache * theportcache;

	// these are for fast lookup of spline distances
	SplineCache* splineCache;
	void addSplineCache(size_t np, size_t res);
	void clearSplineCache(bool isDestructor = false);
	void buildSplineCache(size_t res);

	TreeNode * classcache;
	TreeNode * superclasscache;
	char * copycache;
	TreeWin * treewindow;
  
	unsigned int boundnodecheckmask;
	unsigned int boundnodeabsentmask;

	ByteBlock cpptypestring;
	int cpptypecode;
 
	int shapeautoload(TreeNode * parentobject);
	int imageautoload(TreeNode * parentobject);
	int soundautoload(TreeNode * parentobject);
  
	engine_export int bindstructure(TreeNode *, unsigned int flags);
  
	int bind(TreeNode *, TreeNode **, char *);
   
	int datatostring(char *, int n);
  
	Menu custommenu;
	static const int MENU_MERGE = 1;
	static const int MENU_OVERRIDE = 2;
	Menu popupmenu(TreeWin* t, int* objMenuMode, TreeNode* theMenu = 0);
	int createmenufromtree(TreeNode *menutree);
	int createmenufromtree_(TreeNode *menutree, Menu nextmenu, Menu supermenu);
   
	int bind_media_shape();
	int bind_media_image();
	int bind_media_sound();
  

	TreeNode* thefunctionbindings[SM_MAX_MESSAGES];

	struct hashvalue {int counterindex; int offset;};
	static std::unordered_map<std::string, hashvalue> hashattributes;
	static std::unordered_map<std::string, hashvalue> hashbasetable;
	static void bindhashattributes();
	int resetfunctionbindings();

	engine_export virtual void bind() override;
	virtual void bindVariables(){return;}
	PortDrawCache* findPortDrawCache(TreeNode* couplingNode);
   
	int indexbindings;

	TreeWinAttTable * thebasetable;
	TreeWinAttTable* createbasetable();


	#define H_LOC_ODT_VARIABLE(v,ODTMEMBERPREFIX)  \
	TreeNode * N##ODTMEMBERPREFIX##v; 
  
	//              ATT ADDPOINT 7
  
	TreeNode* firstattribute;
	#define DECLARE_ATTRIBUTE(ATTRIBUTE_DEFAULT,ATTRIBUTE_NAME, ...) H_LOC_ODT_VARIABLE(ATTRIBUTE_NAME,b_)
	#include "Attributes.h"
	#undef DECLARE_ATTRIBUTE
	TreeNode* lastattribute;

	void copyattributebindingsfrom(ObjectDataType* odt);

	static TreeNode* findclassbyname(TreeNode* object, const char* fullclassname);
	static ObjectDataType* createodtderivativefromclassatt(TreeNode* classatt);

	static const int ODT_BIND_STATE_VARIABLE = 0x1;
	ObjectDataType* checkCreateODTDerivative(TreeNode* classesAtt, bool force = false);
	engine_export TreeNode* bindVariableNode(char* name, bool isStateVariable);
	engine_export void bindVariableByName(const char* name, double& val, int flags = 0);
	engine_export void bindVariableByName(const char* name, TreeNode*& val, int flags = 0);
	engine_export void bindVariableByName(const char* name, ByteBlock& val, int flags = 0);
	engine_export void bindVariableByName(const char* name, NodeRef& val, int flags = 0);
public:

	#define bindVariable(x) bindVariableByName(#x, x)
	#define bindStateVariable(x) bindVariableByName(#x, x, ODT_BIND_STATE_VARIABLE)

	engine_export virtual TreeNode* getObjectTree() override;
	engine_export virtual TreeNode* getLabelNode(const char* labelName, bool assert) override;
	engine_export virtual TreeNode* getLabelNode(int labelRank, bool assert) override;

	engine_export virtual void bindEvents() override;
	engine_export virtual TreeNode* getEventInfoObject(const char* eventTitle) override;

	engine_export virtual void bindInterface() override;
	engine_export void bindStatsObject(const char* version = nullptr);

public:
	engine_export Vec3 __getCentroid();
	engine_export Vec3 getLocation(double xFactor, double yFactor, double zFactor);
	engine_export Vec3 getLocation(const Vec3& factors);
	engine_export ObjectDataType& setLocation(double x, double y, double z);
	engine_export ObjectDataType& setLocation(double x, double y, double z, double xFactor, double yFactor, double zFactor);
	engine_export ObjectDataType& setLocation(const Vec3& location, const Vec3& factors)
	{
		return setLocation(location.x, location.y, location.z, factors.x, factors.y, factors.z);
	}
	engine_export ObjectDataType& setRotation(double x, double y, double z);
	engine_export ObjectDataType& setRotation(const Vec3& rotation);
	engine_export ObjectDataType& setSize(double x, double y, double z);

	engine_export static bool getBBinLu;
	engine_export virtual BoundingBox3 getAxisAlignedBoundingBox(TreeNode* projectOnto = nullptr);
	engine_export BoundingBox3 getAxisAlignedBoundingBoxLu(TreeNode* projectOnto)
	{
		getBBinLu = true;
		auto result = getAxisAlignedBoundingBox(projectOnto);
		getBBinLu = false;
		return result;
	}

	engine_export Vec3& __getLocation();
	engine_export Vec3& __getRotation();
	engine_export Vec3& __getSize();

	__declspec(property(get = __getLocation)) Vec3& location;
	__declspec(property(get = __getRotation)) Vec3& rotation;
	__declspec(property(get = __getSize)) Vec3& size;

	class ResetPositionProperty
	{
	public:
		operator bool();
		ObjectDataType* object = nullptr;
		TreeNode* resetPositionNode = nullptr;
		Vec3 location();
		Vec3 rotation();
		Vec3 size();
		TreeNode* container();
		void clear();
		void set();
		static void bindInterface();
	};
	ResetPositionProperty resetPosition();

	engine_export void setState(int state, int profile);

	engine_export Variant getVariable(const char* variableName);
	engine_export void setVariable(const char* variableName, const Variant&  value);

	engine_export Color& __getColor();
	// making color into a property creates name collisions with the color() attribute command
	// so for now I'm leaving this out.
	//__declspec(property(get = __getColor)) Color& color;

	engine_export int stopCount();

	engine_export void setLabelProperty(const char* name, unsigned nameHash, const Variant& val);
	engine_export Variant getLabelProperty(const char* name, unsigned nameHash, bool dieHard);

	engine_export TreeNode* findAttribute(const char* path);

	private:
	typedef TreeNode* (ObjectDataType::*GetBoundEventAttribute)();
	static GetBoundEventAttribute eventAttributeGetters[SM_MAX_MESSAGES];
	TreeNode * getBoundEventAttribute_SM_RESET(){ return Nb_OnReset; }
	TreeNode * getBoundEventAttribute_SM_MESSAGE() { return Nb_OnMessage;}
	TreeNode * getBoundEventAttribute_SM_EVENT() { return Nb_OnTimerEvent;}
	TreeNode * getBoundEventAttribute_SM_DRAW() { return Nb_OnDraw;}
	TreeNode * getBoundEventAttribute_SM_PREDRAW() { return Nb_OnPreDraw;}
	TreeNode * getBoundEventAttribute_SM_INOPEN() { return Nb_OnInOpen;}
	TreeNode * getBoundEventAttribute_SM_OUTOPEN() { return Nb_OnOutOpen;}
	TreeNode * getBoundEventAttribute_SM_ACCEPT() { return Nb_OnReceive;}
	TreeNode * getBoundEventAttribute_SM_GIVE() { return Nb_OnSend;}
	TreeNode * getBoundEventAttribute_SM_ENTER() { return Nb_OnEntering;}
	TreeNode * getBoundEventAttribute_SM_EXIT() { return Nb_OnExiting;}

	TreeNode * getBoundEventAttribute_SM_COMPILE() { return Nb_OnCompile;}
	TreeNode * getBoundEventAttribute_SM_CREATE() { return Nb_OnCreate;}
	TreeNode * getBoundEventAttribute_SM_DESTROY() { return Nb_OnDestroy;}
	TreeNode * getBoundEventAttribute_SM_UNDO() { return Nb_OnUndo;}
	TreeNode * getBoundEventAttribute_SM_CLICK() { return Nb_OnClick;}
	TreeNode * getBoundEventAttribute_SM_RUNSTART() { return Nb_OnRunStart;}
	TreeNode * getBoundEventAttribute_SM_RUNWARM() { return Nb_OnRunWarm;}
	TreeNode * getBoundEventAttribute_SM_RUNEND() { return Nb_OnRunEnd;}
	TreeNode * getBoundEventAttribute_SM_LISTEN() { return Nb_OnListen;}
	TreeNode * getBoundEventAttribute_SM_DRAWPLANAR() { return Nb_OnDrawPlanar;}
	TreeNode * getBoundEventAttribute_SM_PREDRAWPLANAR() { return Nb_OnPreDrawPlanar;}
	TreeNode * getBoundEventAttribute_SM_PRELISTEN() { return Nb_OnPreListen;}

	TreeNode * getBoundEventAttribute_SM_STATECHANGE() { return Nb_OnStateChange;}

	TreeNode * getBoundEventAttribute_SM_DRAG() { return Nb_OnDrag;}
public:
	TreeNode* getBoundEventAttributeByMessageCode(int messageCode);

	static ObjectDataType* createEngineODTDerivative(const char* classname);
	typedef ObjectDataType* (*CreateODTDerivative)(const char* classname);
	static CreateODTDerivative createContentODTDerivative;
	static ObjectDataType* createODTDerivative_NoDLLConnection(const char* classname);

	// These lists are bound in CompilerDataTypes.cpp, so I can bind them as registered classes, not content registered classes

	static bool shouldCachePorts;

	engine_export TreeNode* assertAttribute(const char *name, int datatype);
	engine_export ObjectDataType* __getClassObject();
	__declspec(property(get = __getClassObject)) ObjectDataType* classObject;


	typedef NodeListArray<ObjectDataType>::OutObjectTypeOneBased OutObjectArray;
	typedef NodeListArray<ObjectDataType>::InObjectTypeOneBased InObjectArray;
	typedef NodeListArray<ObjectDataType>::CenterObjectTypeOneBased CenterObjectArray;
	typedef NodeListArray<ObjectDataType>::ObjSubNodeTypeOneBased ObjectItemArray;

	void resetStats();

	class engine_export Animation
	{
		friend Variant getanimationvar(TreeNode*, int, const char*);
	protected:
		TreeNode* animation;
		TreeNode* object;
		TreeNode* variables;

		static TreeNode* animationVariable;

	public:
		Animation(TreeNode* animationNode = nullptr);
		void construct(const Animation& other);
		Animation& operator=(const Animation& other);

		void resume(int resumeAtType = 0, double resumeAtVal = 0);
		void start(int speedType = 0, double speedValue = 0, int repeatType = 0, double repeatValue = 0);
		void stop();
		void update(double updateTime = -1);

		Variant getVariable(const char* variableName, unsigned nameHash, bool dieHard);
		void setVariable(const char* variableName, unsigned nameHash, const Variant& value);

		static void bindInterface();
	};

	class engine_export AnimationsArray
	{
	protected:
		TreeNode* object = nullptr;
		TreeNode* animations = nullptr;

	public:
		AnimationsArray(TreeNode* object = nullptr);
		void construct(const AnimationsArray& other);
		AnimationsArray& operator=(const AnimationsArray& other);

		Animation operator [](const char* animation);
		Animation operator [](int animation);
		Animation operator [](const Variant& animation);
		// Animation _assert(const char* animationName);
		int __getLength();
		__declspec(property (get = __getLength)) int length;

		operator bool();

		static void bindInterface();
	};

	engine_export AnimationsArray __getAnimations() { return AnimationsArray(holder); }
	__declspec(property(get = __getAnimations)) AnimationsArray animations;

	engine_export virtual void stop(int stopState, int id = 0, double priority = 0.0, int stateProfile = 0);
	engine_export virtual void resume(int id = 0, int stateProfile = 0);

	engine_export const float* __getModelToWorldMatrix();
	__declspec(property(get = __getModelToWorldMatrix)) const float* modelToWorldMatrix;

	virtual ObjectDataType* toObject() override { return this; }

	engine_export Variant message(double delayTime = 0, treenode fromObj = nullptr, const Variant& p1 = Variant(), const Variant& p2 = Variant(), const Variant& p3 = Variant());

	class ResetValues : public SimpleDataType
	{
	private:
		std::unordered_map<TreeNode*, Variant> variableMap;
		std::unordered_map<std::string, Variant> propertyMap;

	public:
		virtual void bind() override; 
		virtual const char* getClassFactory() override { return "ObjectResetValues"; }
		void addVariable(TreeNode* varNode);
		void addProperty(const char* propName);
		void restoreValues();
	};

	engine_export Variant function(const char* funcName, CallPoint* cp, ObjectDataType* classObject);
	engine_export virtual Variant function(const char* funcName, CallPoint* cp) override { return function(funcName, cp, this); }


	engine_export virtual bool isClassType(const char* className) override;
	Array enumerateProperties();
private:
	Variant findProperty(FLEXSIMINTERFACE);
	bool checkPropertyValidClasses(TreeNode* foundProp);
	Variant enumerateProperties(FLEXSIMINTERFACE) { return enumerateProperties(); }
public:

	engine_export ObjectDataType* findProperty(const char* propName);
	engine_export Variant getProperty(ObjectDataType* prop, const char* propName);
	engine_export Variant getProperty(const char* propName);
	engine_export int setProperty(ObjectDataType* prop, const char* propName, const Variant& val);
	engine_export int setProperty(const char* propName, const Variant& val);
	static bool keepTemplateBinding;
	static const int UPDATE_TEMPLATE_OVERRIDES = 0x1;
	static const int UPDATE_TEMPLATE_INSTANCES = 0x2;
	engine_export void applyProperties(const Variant& prop, const Variant* newValue = nullptr, const Variant* oldValue = nullptr, int flags = UPDATE_TEMPLATE_OVERRIDES | UPDATE_TEMPLATE_INSTANCES);
	engine_export void applyProperties(const char* propName = "") { applyProperties(propName && propName[0] ? Variant(propName) : Variant()); }
	engine_export Variant applyProperties(FLEXSIMINTERFACE);


	static const int DRAW_SIZER_X = 0x1;
	static const int DRAW_SIZER_Y = 0x2;
	static const int DRAW_SIZER_Z = 0x4;
	static const int DRAW_SIZER_X_NEG = 0x8;
	static const int DRAW_SIZER_Y_NEG = 0x10;
	static const int DRAW_SIZER_Z_NEG = 0x20;
	static const int DRAW_YELLOW_BOX = 0x40;
	static const int DRAW_GREEN_BOX = 0x80;
	static const int DRAW_RED_BOX = 0x100;
	static const int DRAW_HOVER_BOX = 0x200;

	static const int DRAW_ROTATOR_X = 0x400;
	static const int DRAW_ROTATOR_Y = 0x800;
	static const int DRAW_ROTATOR_Z = 0x1000;
	static const int DRAW_ROTATOR_ALL = 0x1c00;

	static const int DRAW_CONNECTOR_TRIANGLE = 0x2000;
	static const int DRAW_CONNECTOR_SQUARE = 0x4000;
	static const int DRAW_CONNECTOR_CIRCLE = 0x8000;
	static const int DRAW_CONNECTOR_DIAMOND = 0x10000;
	static const int DRAW_CONNECTOR_DEFAULT = (DRAW_CONNECTOR_TRIANGLE | DRAW_CONNECTOR_SQUARE);
	static const int DRAW_CONNECTOR_ALL = 0x1e000;

	static const int DRAW_ALL_AXIS_SIZER = 0x20000;
	static const int DRAW_MOVE_X = 0x80000;
	static const int DRAW_MOVE_Y = 0x100000;
	static const int DRAW_MOVE_Z = 0x200000;
	static const int DRAW_MOVE_AXIS_ALL = 0x380000;
	static const int DRAW_MOVE_XY = 0x400000;

	static const int DRAW_ORB = 0x800000;

	static const int DRAW_SIZER_ALL = (0x3f | DRAW_ALL_AXIS_SIZER);
	static const int DRAW_DEFAULTS = (DRAW_ORB | DRAW_SIZER_ALL | DRAW_ALL_AXIS_SIZER | DRAW_MOVE_X | DRAW_MOVE_Y | DRAW_MOVE_Z
		| DRAW_ROTATOR_Z | DRAW_CONNECTOR_DEFAULT);
	static const int DRAW_MANIP_HANDLES = (DRAW_ORB | DRAW_SIZER_ALL | DRAW_MOVE_AXIS_ALL | DRAW_CONNECTOR_ALL | DRAW_ROTATOR_ALL);

	engine_export static void setManipulationHandleDraw(int flags);
};


// declare the list of allocator functions: one per attribute
int bindattributestree(ObjectDataType *, TreeNode * client);

#define ODT_SETMEMBERFUNC_H(v,ODTMEMBERPREFIX) \
int odtsetmemberfunction##ODTMEMBERPREFIX##v(FlexSim::ObjectDataType * D,  FlexSim::TreeNode * P);
#define DECLARE_ATTRIBUTE(ATTRIBUTE_DEFAULT,ATTRIBUTE_NAME, ...) ODT_SETMEMBERFUNC_H(ATTRIBUTE_NAME,b_)
#include "Attributes.h"
#undef DECLARE_ATTRIBUTE

}

// COPYRIGHT 2006   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

