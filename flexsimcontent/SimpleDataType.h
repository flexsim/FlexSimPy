#pragma once
#include "BasicClasses.h"
#include "BasicMacros.h"
#include "DataTypes.h"
#include "TreeNode.h"
#include "ByteBlock.h"

// Need to undef min and max for Clang
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <unordered_map>
#pragma pop_macro("min")
#pragma pop_macro("max")

namespace FlexSim {

#define SDT_BIND_NONE 0
#define SDT_BIND_ON_LOAD 1
#define SDT_BIND_ON_SAVE 2
#define SDT_BIND_ON_CREATE 3
#define SDT_BIND_ON_DISPLAY 4
#define SDT_BIND_SET_VALUE 5
#define SDT_BIND_GET_VALUE 6
#define SDT_BIND_ENUM_SUBNODES 7

class SimpleDataType
{
	friend class TreeNode;
	friend class CouplingDataType;
	friend class ObjectDataType;
	friend class TableView;
private:

	static int bindMode;
	static char* displayStr;
	static size_t displayStrMaxSize;
	static char* displayStrCopyPoint;
	static bool displayVerbose;
	static int detachAfterBind;
	static Array boundSubnodes;
	static void attachSDTDerivative(TreeNode* x);
	static void bindSDTNode(TreeNode* x);
	static void detachSDTDerivative(TreeNode* x);
	static SimpleDataType* createSDTDerivativeFromName(const char* name, TreeNode* holder);
	engine_export static TreeNode* s_getBindTree(TreeNode* x);
	engine_export static TreeNode* s_assertBindTree(TreeNode* x);
	static Variant curValue;
	static const char * curValueName;
	engine_export TreeNode* assertBindTree();
	static std::vector<NodeRef> nodeList;

protected:

public:
	virtual CouplingDataType* toCoupling() { return nullptr; }
	virtual TrackedVariable* toTrackedVariable() { return nullptr; }
	virtual CodeSDT* toCodeSDT() { return nullptr; }
	engine_export static void appendToDisplayStr(const char* text);
	static void appendToDisplayStr(double val) { 
		char buffer[100]; 
		double absVal = val >= 0 ? val : -val;
		if (absVal == 0.0 || (absVal > 0.000001 && absVal < 1000000000.0))
			sprintf(buffer, "%f", val); 
		else sprintf(buffer, "%e", val);
		appendToDisplayStr(buffer);
	}
	static void appendToDisplayStr(int val) { char buffer[100]; sprintf(buffer, "%d", val); appendToDisplayStr(buffer); }
	static void appendToDisplayStr(const std::string& str) { appendToDisplayStr(str.c_str()); }
	engine_export static bool isDisplayVerbose();
	engine_export static void bindNodeList(int doBindMode, bool detachReattach, int startIndex = 0, std::vector<NodeRef>* list = nullptr);
	static void clearAttsFromNodeList(std::vector<NodeRef>* list = nullptr);
	TreeNode* holder;
	SimpleDataType() : holder(0) {}
	virtual ~SimpleDataType(){}
	virtual const char* getClassFactory(){return 0;}
	engine_export virtual void bind();
	engine_export void bind(int bindMode);
	static const int DISPLAY_TREE = 0;
	static const int DISPLAY_VERBOSE_TREE = 0x1;
	static const int DISPLAY_TABLE_CELL = 0x2;
	static const int DISPLAY_LIST = 0x4;
	static const int DISPLAY_DEBUGGER = 0x8;
	static const int DISPLAY_SPECIAL = 0x100;
	engine_export virtual char* toString(int displayFlags);
	engine_export virtual int stringToData(const char *datastring, int precision) { return 0; };
	engine_export virtual int getCapabilities() { return 0; }
	static const int CAPABILITY_LABELS = 0x1;
	engine_export virtual void setLabel(const char* name, const Variant& val);
	virtual void initializeLike(SimpleDataType* other) {}
	virtual bool pasteFrom(TreeNode* other) { return false; }
engine_private:
	virtual TreeNode* getObjectTree() { return 0; }
	virtual TreeNode* getLabelNode(const char* labelName, bool assert) { return 0; }
	virtual TreeNode* getLabelNode(int labelRank, bool assert) { return 0; }
public:
	virtual Variant evaluate(const VariantParams& params) { return holder; }
	char* defaultToString(int verbose);
	void* operator new (size_t size)
	{
		void* p = flexsimmalloc(size);
		if(!p) throw 0;
		return p;
	}
	void operator delete (void* p)
	{
		flexsimfree(p);
	}

	engine_export static int getBindMode();
	static void setBindMode(int toMode);
	engine_export static Variant& getCurValue();
	engine_export static const char * getCurValueName();
	engine_export Variant getValue(const char* name);
	engine_export void setValue(const char* name, Variant value);
	Array enumerateBoundSubnodes();
private:
	engine_export static TreeNode* bindByName(const char* name, int asSubNode, int dataType, int * added, TreeNode* bindParent, SimpleDataType* sdt);
public:
	engine_export TreeNode* bindByName(const char* name, int asSubNode, int dataType, int * added = 0);

	engine_export void bindDoubleByName(const char* name, double& val, int asSubNode);
#define bindDouble(name, asSubNode) bindDoubleByName(#name, name, asSubNode)
	engine_export void bindNodeRefByName(const char* name, NodeRef& val, int asSubNode);
#define bindNodeRef(name, asSubNode) bindNodeRefByName(#name, name, asSubNode)
template<class ObjType>
	void bindObjRefByName(const char* name, ObjRef<ObjType>& val, int asSubNode)
	{
		bindNodeRefByName(name, val, asSubNode);
	}
#define bindObjRef(name, asSubNode) bindObjRefByName(#name, name, asSubNode)

	/// <summary>	Binds a double with "unknown" type. Use this method if the name you want to bind by is
	/// 			different than the name of the member itself. Otherwise just use
	/// 			bindUnknownDouble()</summary>
	/// <param name="name">	The name of the member. </param>
	/// <param name="val"> 	[in,out] The value. </param>
	engine_export void bindUnknownDoubleByName(const char* name, double& val);

	/// <summary>	Binds a double with "unknown" type. Similar to bindDouble() or
	///				bindNumber(), except this method will check if tonode(value)
	///				is a valid node reference, and if so, it will save a coupling pointer
	///				to the node instead of using number data, so the reference will
	/// 			properly be saved/loaded. 
	/// 			
	/// 			Note that this is mostly available for backwards compatibility. 
	/// 			Going forward you should store such members as Variants and use bindVariant().
	/// 			Note: bindUnknownDouble is a macro that expands the parameter to a name/value
	/// 			pair for calling bindUnknownDoubleByName. </summary>
	/// <param name="name">	The name of the member to bind. </param>
	#define bindUnknownDouble(name) bindUnknownDoubleByName(#name, name)

private:

	template<class T>
	static void __bindNumberByName(const char* name, T& val, TreeNode* bindToNode)
	{
		using TreeHelper = FlexSimPrivateTypes::TreeHelper;
		int bindMode = getBindMode();

		switch (bindMode) {
		case SDT_BIND_ON_DISPLAY: {
			char tempStr[1000];
			if (((double)(int)val) != ((double)val)) {
				double absVal = std::fabs((double)val);
				if (absVal < 1000000000000.0 && absVal > 0.00001)
					sprintf(tempStr, "%s: %f%s", name, (double)val, isDisplayVerbose() ? "\r\n" : ", ");
				else sprintf(tempStr, "%s: %e%s", name, (double)val, isDisplayVerbose() ? "\r\n" : ", ");
			}
			else sprintf(tempStr, "%s: %d%s", name, (int)val, isDisplayVerbose() ? "\r\n" : ", ");
			appendToDisplayStr(tempStr);
			break;
		}
		// else continue into load/save
		case SDT_BIND_ON_SAVE:
		case SDT_BIND_ON_LOAD:
			if (bindMode == SDT_BIND_ON_SAVE)
				TreeHelper::SDF(bindToNode)[0] = (double)val;
			else val = (T)TreeHelper::SDF(bindToNode)[0];
			break;
		}
	}
public:
	template<class T>
	void bindNumberByName(const char* name, T& val)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
		case SDT_BIND_ON_DISPLAY: __bindNumberByName(name, val, nullptr); break;
		case SDT_BIND_ON_SAVE:
		case SDT_BIND_ON_LOAD: __bindNumberByName(name, val, bindByName(name, 0, DATA_FLOAT, 0)); break;

		case SDT_BIND_SET_VALUE:
			if (strcmp(name, getCurValueName()) == 0) {
				val = (T)(double)getCurValue();
			}
			break;
		case SDT_BIND_GET_VALUE:
			if (strcmp(name, getCurValueName()) == 0) {
				getCurValue() = (double)val;
			}
			break;
		}
	}
	template<class T>
	static void bindNumberByName(const char* name, T& val, TreeNode* bindParent)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
		case SDT_BIND_ON_DISPLAY: __bindNumberByName(name, val, nullptr); break;
		case SDT_BIND_ON_SAVE:
		case SDT_BIND_ON_LOAD: __bindNumberByName(name, val, bindByName(name, 0, DATA_FLOAT, 0, bindParent, nullptr)); break;
		}
	}
#define bindNumber(name, ...) bindNumberByName(#name, name, ##__VA_ARGS__)


	template<class T>
	void bindEnumByName(const char* name, T& val)
	{
		int bindMode = getBindMode();
		int valAsInt = static_cast<int>(val);
		bindNumberByName(name, valAsInt);
		if (bindMode == SDT_BIND_ON_LOAD || bindMode == SDT_BIND_SET_VALUE)
			val = static_cast<T>(valAsInt);
	}
	#define bindEnum(name) bindEnumByName(#name, name)

	template<class Str>
	void bindStringByName(const char* name, Str& val)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
		case SDT_BIND_ON_DISPLAY: {
			char tempStr[1000];
			snprintf(tempStr, 1000, "%s: %s%s", name, val.c_str(), isDisplayVerbose() ? "\r\n" : ", ");
			tempStr[999] = 0;
			appendToDisplayStr(tempStr);
			break;
		}
		// else continue into load/save
		case SDT_BIND_ON_SAVE:
		case SDT_BIND_ON_LOAD: {
			TreeNode* theNode = bindByName(name, 0, DATA_BYTEBLOCK, 0);
			if(bindMode == SDT_BIND_ON_SAVE)
				Variant::set(theNode, (char*)val.c_str());
			else val = FlexSimPrivateTypes::TreeHelper::SDB(theNode)->getBuffer();
			break;
		}

		case SDT_BIND_SET_VALUE:
			if (strcmp(name, getCurValueName()) == 0) {
				val = getCurValue().c_str();
			}
			break;
		case SDT_BIND_GET_VALUE:
			if (strcmp(name, getCurValueName()) == 0) {
				getCurValue() = val.c_str();
			}
			break;
		}

	}
	#define bindString(name) bindStringByName(#name, name)

	engine_export void bindByteBlockByName(const char* name, ByteBlock& val, int asSubNode);
	#define bindByteBlock(name, asSubNode) bindByteBlockByName(#name, name, asSubNode)

	template<class Type, class SizeType>
	void bindLocalArrayByName(const char* name, Type* val, SizeType numElements)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
			// else continue into load/save
			case SDT_BIND_ON_SAVE:
			case SDT_BIND_ON_LOAD: {
				TreeNode* theNode = bindByName(name, 0, DATA_BYTEBLOCK, 0);
				if(bindMode == SDT_BIND_ON_SAVE) {
					theNode->safedatabyteblock()->setSize((int)numElements * sizeof(Type));
					memcpy(theNode->safedatabyteblock()->getBuffer(), val, numElements * sizeof(Type));
				}
				else memcpy(val, theNode->safedatabyteblock()->getBuffer(), numElements * sizeof(Type));
				break;
			}
			case SDT_BIND_ON_DISPLAY:
				appendToDisplayStr(name);
				appendToDisplayStr(": ");
				for (int i = 0; i < numElements; i++) {
					StlValueBinder<Type>::Displayer(val + i);
					appendToDisplayStr(" ");
				}
				if (isDisplayVerbose())
					appendToDisplayStr("\r\n");
				break;
		}
	}
	#define bindLocalArray(name, nrBytes) bindLocalArrayByName(#name, name, nrBytes)

	engine_export void bindLocalBufferByName(const char* name, void* val, int nrBytes);
	#define bindLocalBuffer(name, nrBytes) bindLocalBufferByName(#name, name, nrBytes)

	template<class Type, class SizeType>
	void bindHeapArrayByName(const char* name, Type*& val, SizeType& numElements)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
		// else continue into load/save
		case SDT_BIND_ON_SAVE:
		case SDT_BIND_ON_LOAD: {
			TreeNode* theNode = bindByName(name, 0, DATA_BYTEBLOCK, 0);
			if(bindMode == SDT_BIND_ON_SAVE) {
				theNode->safedatabyteblock()->setSize(numElements * sizeof(Type));
				memcpy(theNode->safedatabyteblock()->getBuffer(), val, numElements * sizeof(Type));
			}
			else {
				numElements = theNode->safedatabyteblock()->getSize() / sizeof(Type);
				val = new Type[numElements];
				memcpy(val, theNode->safedatabyteblock()->getBuffer(), numElements * sizeof(Type));
			}
			break;
		}
		}
	}
	#define bindHeapArray(name, numElements) bindHeapArrayByName(#name, name, numElements)

	private:
		engine_export void displayFlexSimArray(Array& val);

	public:
	// bind method for treenodearray and string array
	engine_export void bindFlexSimArrayByName(const char* name, Array& val);

	#define bindFlexSimArray(name) bindFlexSimArrayByName(#name, name)

	engine_export void bindFlexSimMapByName(const char* name, Map& val);
	#define bindFlexSimMap(name) bindFlexSimMapByName(#name, name)

	engine_export void bindNodePtrByName(const char* name, TreeNode*& val);
	engine_export void bindSubNodeByName(const char* name, TreeNode*& val, int dataType = 1);
private:
	engine_export static void __bindObjPtrByName(const char* name, SimpleDataType*& val, TreeNode* bindToNode);
public:
	engine_export void bindObjPtrByName(const char* name, SimpleDataType*& val);
	engine_export static void bindObjPtrByName(const char* name, SimpleDataType*& val, TreeNode* bindParent);
	engine_export void bindVariantByName(const char* name, Variant& var);

#define bindSubNode(name, dataType) bindSubNodeByName(#name, name, dataType)
#define bindNodePtr(name) bindNodePtrByName(#name, name)
#define bindObjPtr(name, ...) bindObjPtrByName(#name, (SimpleDataType*&)name, ##__VA_ARGS__)
#define bindVariant(name) bindVariantByName(#name, name)

	engine_export void bindSimpleDataMemberByName(const char* name, SimpleDataType& member);

	template <class T>
	typename std::enable_if<std::is_base_of<SimpleDataType, T>::value, void>::type bindSdtMemberByName(const char* name, T& member)
	{
		bindSimpleDataMemberByName(name, member);
	}

#define bindSdtMember(name) bindSdtMemberByName(#name, name)

	engine_export TreeNode* getBindTree();

	// now for some stl stuff
	
	// original Saver() definitions
	template <typename Type, class Enable = void> class StlValueBinder;
	
	template <typename Type>
	class StlValueBinder<Type, typename std::enable_if<!std::is_pointer<Type>::value && !std::is_integral<Type>::value && !std::is_floating_point<Type>::value, void>::type> {
	public:
		static treenode Saver(treenode x, Type* toVal)
		{
			toVal->bind(x);
			return x;
		}
		static Type Loader(treenode x)
		{
			Type myVal;
			myVal.bind(x);
			return myVal;
		}
		static void Displayer(Type* x)
		{
			x->bind(nullptr);
		}
	};

	#define FORMAT_AND_DISPLAY(format, x) \
			char str[200];\
			sprintf(str, format, x);\
			appendToDisplayStr(str);


	template <class T>
	class StlValueBinder<T*, typename std::enable_if<!std::is_base_of<SimpleDataType, T>::value, void>::type> {
	public:
		static treenode Saver(treenode x, T** toVal)
		{
			(*toVal)->bind(x); return x;
		}
		static T* Loader(treenode x)
		{
			T* newT = new T;
			newT->bind(x);
			return newT;
		}
		static void Displayer(T** x)
		{
			(*x)->bind(0);
		}
	};
	template <class Type> 
	class StlValueBinder<Type, typename std::enable_if_t<std::is_floating_point_v<Type>>> {
	public:
		static treenode Saver(treenode x, Type* toVal)
			{x->addData(DATA_FLOAT)->safedatafloat()[0] = (double)*toVal; return x;}
		static Type Loader(treenode x)
			{return (Type)x->safedatafloat()[0];}
		static void Displayer(Type* val)
			{FORMAT_AND_DISPLAY("%lf", (double)*val);}
	};
	template <class Type> 
	class StlValueBinder<Type, typename std::enable_if_t<std::is_integral_v<Type>>> {
	public:
		static treenode Saver(treenode x, Type* toVal)
			{x->addData(DATA_FLOAT)->safedatafloat()[0] = (double)*toVal; return x;}
		static Type Loader(treenode x)
		{return (Type)x->safedatafloat()[0];}
		static void Displayer(Type* val)
			{FORMAT_AND_DISPLAY("%d", (int)*val);}
	};


	template <class T> 
	class StlValueBinder<T*, typename std::enable_if_t<std::is_base_of_v<SimpleDataType, T>>> {
	public:
		static treenode Saver(treenode x, T** toVal)
		{ x->addData(DATA_POINTERCOUPLING)->pointTo(*toVal ? (*toVal)->holder : 0); return x; }
		static T* Loader(treenode x)
		{
			treenode dereference = x->safedatapartner(); 
			if (dereference)
				return dereference->object<T>();
			return 0;
		}
		static void Displayer(T** x);
	};


	template <class SetType>
	static void StlSetInserter(SetType& theSet, typename SetType::value_type theVal)
	{
		theSet.insert(std::move(theVal));
	}

	template <class SetType>
	static void StlVectorInserter(SetType& theSet, typename SetType::value_type theVal)
	{
		theSet.push_back(std::move(theVal));
	}


	template <class SetType, class Binder, void (*Inserter) (SetType& theSet, typename SetType::value_type theVal)>
	void bindStlContainerByName(const char* prefix, SetType& theSet)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
		case SDT_BIND_ON_SAVE: {
			typename SetType::iterator temp = theSet.begin();
			if (temp == theSet.end())
				return;
			treenode container = bindByName(prefix, 0, DATA_FLOAT);
			container->subnodes.clear();
			for (; temp != theSet.end(); temp++)
				Binder::Saver(container->subnodes.add(), (typename SetType::value_type*)&(*(temp)));
			break;
		}
		case SDT_BIND_ON_LOAD: {
			treenode container = bindByName(prefix, 0, DATA_FLOAT);
			theSet.clear();
			for (int i = 1; i <= container->subnodes.length; i++)
				Inserter(theSet, Binder::Loader(container->subnodes[i]));
			break;
		}
		case SDT_BIND_ON_DISPLAY: {
			appendToDisplayStr(prefix);
			appendToDisplayStr(": ");
			for (typename SetType::iterator temp = theSet.begin(); temp != theSet.end(); temp++) {
				if(temp != theSet.begin())
					appendToDisplayStr(", ");
				Binder::Displayer((typename SetType::value_type*)&(*(temp)));
			}
			appendToDisplayStr("\r\n");
			break;
		}
		case SDT_BIND_ENUM_SUBNODES: {
			bindByName(prefix, 0, DATA_FLOAT);
			break;
		}
		default:break;

		}
	}

	template <class MapType, class KeyBinder, class ValBinder>
	void bindStlMapByName(const char* prefix, MapType& theMap)
	{
		int bindMode = getBindMode();

		switch (bindMode) {
		case SDT_BIND_ON_SAVE: {
			typename MapType::iterator temp = theMap.begin();
			if (temp == theMap.end())
				return;
			treenode container = bindByName(prefix, 0, DATA_FLOAT);
			container->subnodes.clear();
			for (; temp != theMap.end(); temp++) {
				ValBinder::Saver(
					KeyBinder::Saver(container->subnodes.add(), (typename MapType::key_type*)&(temp->first))->subnodes.add(),
						(&(temp->second)));
			}
			break;
		}
		case SDT_BIND_ON_LOAD: {
			treenode container = bindByName(prefix, 0, DATA_FLOAT);
			theMap.clear();
			for (int i = 1; i <= container->subnodes.length; i++) {
				treenode x = container->subnodes[i];
				theMap[KeyBinder::Loader(x)] = ValBinder::Loader(x->last);
			}
			break;
		}
		case SDT_BIND_ON_DISPLAY: {
			appendToDisplayStr(prefix);
			appendToDisplayStr(": ");
			for (typename MapType::iterator temp = theMap.begin(); temp != theMap.end(); temp++) {
				if(temp != theMap.begin())
					appendToDisplayStr(", ");
				KeyBinder::Displayer((typename MapType::key_type*)&(temp->first));
				appendToDisplayStr(" => ");
				ValBinder::Displayer(&(temp->second));
			}
			appendToDisplayStr("\r\n");
			break;
		}
		case SDT_BIND_ENUM_SUBNODES: {
			bindByName(prefix, 0, DATA_FLOAT);
			break;
		}
		default:break;

		}
	}


	template <class MapType>
	void bindStlMapByName(const char* prefix, MapType& theMap)
	{
		bindStlMapByName<MapType, StlValueBinder<typename MapType::key_type>, StlValueBinder<typename MapType::mapped_type>>
			(prefix, theMap);
	}
	#define bindStlMap(x) bindStlMapByName(#x, x)


	// utilities for stl container element bind methods
	template <class SDTType>
	static void bindObjPtrToNodeByName(char* name, SDTType* & ptr, treenode x)
	{
		__bindObjPtrByName(name, (SimpleDataType*&)ptr, x);
	}
	#define bindObjPtrToNode(name, x) bindObjPtrToNodeByName(#name, name, x)

	template <typename NumberType>
	static void bindNumberToNodeByName(char* name, NumberType & val, treenode x)
	{
		__bindNumberByName(name, val, x);
	}
	#define bindNumberToNode(name, x) bindNumberToNodeByName(#name, name, x)

	template <class SetType>
	void bindStlContainerByName(const char* prefix, SetType& theSet)
	{
		bindStlContainerByName<SetType, StlValueBinder<typename SetType::value_type>, StlVectorInserter<SetType>>(prefix, theSet);
	}
	#define bindStlContainer(x) bindStlContainerByName(#x, x)

	template <class SetType>
	void bindStlSetByName(const char* prefix, SetType& theMap)
	{
		bindStlContainerByName<SetType, StlValueBinder<typename SetType::value_type>, StlSetInserter<SetType>>
			(prefix, theMap);
	}
	#define bindStlSet(x) bindStlSetByName(#x, x)

	template <typename SubClass>
	static void bindCallbackByName(char* name, Variant (SubClass::*callback)(FLEXSIMINTERFACE))
	{
		if (getBindMode() == SDT_BIND_GET_VALUE && strcmp(getCurValueName(), name) == 0)
			getCurValue() = (double)(size_t)force_cast<void*>(callback);
	}
	#define bindCallback(name, classType) bindCallbackByName((char*)#name, &classType::name)

	
	/** @name Event Binding
	*	Methods associated with enumerating and subscribing to events
	*/
	//@{
	public:
	virtual void bindEvents() {}
	virtual TreeNode* getEventInfoObject(const char* eventTitle) { return nullptr; }

	static const int EVENT_INFO_PARAMS = 0x1;
	static const int EVENT_INFO_DEFAULT_CODE = 0x2;
	static const int EVENT_INFO_CATEGORY = 0x3;
	static const int EVENT_INFO_LOCALIZED_TITLE = 0x4;
	static const int EVENT_INFO_REQUIREMENTS = 0x5;
	static const int EVENT_INFO_NODE = 0x6;
	engine_export virtual Variant getEventTitle(TreeNode* eventNode);
	engine_export virtual Variant getEventTitle(FLEXSIMINTERFACE); 
	engine_export virtual Variant getEventInfo(const char* eventTitle, int info);
	engine_export virtual Variant getEventInfo(FLEXSIMINTERFACE);

	static const int BIND_EVENT_ENUMERATE = 1;
	static const int BIND_EVENT_ASSERT = 2;
	static const int BIND_EVENT_ON_LOAD = 3;
	static const int BIND_EVENT_FILL_BINDING_ENTRY = 4;
	static const int BIND_EVENT_GET_INFO_OBJECT = 5;
	static const int BIND_EVENT_GET_TITLE = 6;

	// flags and op codes for flagging extended functionality as well as retrieving data associated with
	// that functionality
	static const int EVENT_TYPE_MASK = 0x7;
	static const int EVENT_TYPE_DEFAULT = 0x1;
	static const int EVENT_TYPE_VALUE_GETTER = 0x2;
	static const int EVENT_TYPE_VALUE_NOTIFIER = 0x4;
	static const int EVENT_TYPE_TRIGGER = 0x8;

	/// <summary>	A flag to not allow the event binding to a node based on the byte offset from the sdt memory pointer.</summary>
	static const int EVENT_DO_NOT_BIND_BYTE_OFFSET = 0x100;
	static const int EVENT_ATTRIBUTE = 0x200;
	static const int EVENT_NO_DEFAULT_CODE = 0x400;
	static const int EVENT_RELAYED = 0x800;
	static const int EVENT_STAT = 0x1000;

	static const int EVENT_REQUIREMENTS = 0x30000; // the mask around all requirments flags
	static const int EVENT_REQUIREMENTS_BIT_SHIFT = 16; // shift the requirements masked value 16 bits to get the number of requirements
	static const int EVENT_1_REQUIREMENT = 0x10000;
	static const int EVENT_2_REQUIREMENTS = 0x20000;
	static const int EVENT_3_REQUIREMENTS = 0x30000;
	static int getNumRequirementsFromFlags(int flags) 
	{ 
		return (flags & SimpleDataType::EVENT_REQUIREMENTS) >> SimpleDataType::EVENT_REQUIREMENTS_BIT_SHIFT; 
	}

	engine_export static int getBindEventMode();

	typedef TreeNode*(SimpleDataType::*EventNodeResolver) ();
	typedef TreeNode*(SimpleDataType::*EventNodeResolver1) (const Variant& p1);
	typedef TreeNode*(SimpleDataType::*EventNodeResolver2) (const Variant& p1, const Variant& p2);
	typedef TreeNode*(SimpleDataType::*EventNodeResolver3) (const Variant& p1, const Variant& p2, const Variant& p3);

	typedef double(SimpleDataType::*CurValueResolver) ();
	typedef double(SimpleDataType::*CurValueResolver1) (const Variant& p1);
	typedef double(SimpleDataType::*CurValueResolver2) (const Variant& p1, const Variant& p2);
	typedef double(SimpleDataType::*CurValueResolver3) (const Variant& p1, const Variant& p2, const Variant& p3);

	class EventBindingEntry
	{
	public:
		EventBindingEntry() : flags(0), resolver(nullptr), node(nullptr)
		{}
		EventBindingEntry(SimpleDataType* sdt, const char* nodeName, TreeNode*& node, const char* eventTitle, const char* unmangledEventTitle, long long flags,
			EventNodeResolver resolver, CurValueResolver valueResolver) :
			sdt(sdt),
			nodeName(nodeName ? nodeName : ""),
			node(&node),
			eventTitle(eventTitle ? eventTitle : ""),
			unmangledEventTitle(unmangledEventTitle ? unmangledEventTitle : ""),
			flags(flags | s_bindEventFlags),
			resolver(resolver),
			valueResolver(valueResolver)
		{
			if (!(flags & EVENT_DO_NOT_BIND_BYTE_OFFSET))
				nodeByteOffset = (char*)(void*)(&node) - (char*)(void*)sdt;
			if (this->flags & EVENT_REQUIREMENTS)
				this->node = nullptr;
			if (s_sharedRelayedEventBindingSDT.get())
				sharedSDT = s_sharedRelayedEventBindingSDT;
		}
		/// <summary>	Future use: when a TE binds events, he's going to forward bindEvents to his navigator, which makes it
		/// 			so nodeByteOffset can't be used (the events aren't members of the TE class, but on something like AGVData). </summary>
		static int s_bindEventFlags;
		static std::shared_ptr<SimpleDataType> s_sharedRelayedEventBindingSDT;
		SimpleDataType* sdt;
		std::string nodeName;
		std::string unmangledEventTitle;
		std::string eventTitle;
		long long flags;
		int nodeByteOffset = 0;
		TreeNode** node;
		EventNodeResolver resolver;
		CurValueResolver valueResolver;
		int numForwardsContained = 0;
		std::shared_ptr<SimpleDataType> sharedSDT;
	};

	private:
	engine_export void bindEventByNameEx(const char* nodeName, TreeNode*& node, const char* eventTitle, int flags = 0, EventNodeResolver resolver = nullptr, CurValueResolver valueResolver = nullptr);
	engine_export static void bindRelayedClassEventsEx(const char* prefix, int flags, EventNodeResolver resolver, SimpleDataType* sdt, bool shouldShareSDT);
	public:
	template <class ResolverCallbackType = nullptr_t, class ValueResolverCallbackType = nullptr_t>
	void bindEventByName(const char* nodeName, TreeNode*& node, const char* eventTitle, int flags = 0, 
		ResolverCallbackType resolver = nullptr, ValueResolverCallbackType valueResolver = nullptr)
	{
		bindEventByNameEx(nodeName, node, eventTitle, flags, force_cast<EventNodeResolver>(resolver), force_cast<CurValueResolver>(valueResolver));
	}
	#define bindEvent(name, ...) bindEventByName("on" #name, on##name, "On" #name, ##__VA_ARGS__)

	template <class ResolverCallbackType = nullptr_t, class ValueResolverCallbackType = nullptr_t>
	void bindEventWithRequirement(const char* eventTitle, int flags, ResolverCallbackType resolver, ValueResolverCallbackType valueResolver)
	{
		TreeNode* x;
		bindEventByNameEx("", x, eventTitle, flags, force_cast<EventNodeResolver>(resolver), force_cast<CurValueResolver>(valueResolver));
	}


	template <class RelayToClass, class ResolverCallbackType = nullptr_t>
	static void bindRelayedClassEvents(const char* prefix, int flags, ResolverCallbackType resolver, RelayToClass* existing = nullptr)
	{
		switch (getBindEventMode()) {
			case BIND_EVENT_ENUMERATE: 
			case BIND_EVENT_FILL_BINDING_ENTRY:
			case BIND_EVENT_GET_INFO_OBJECT:
			case BIND_EVENT_GET_TITLE:
			{
				if (existing) {
					bindRelayedClassEventsEx(prefix, flags, force_cast<EventNodeResolver>(resolver), existing, false);
				} else {
					RelayToClass* relayToClass = new RelayToClass;
					bindRelayedClassEventsEx(prefix, flags, force_cast<EventNodeResolver>(resolver), relayToClass, true);
				}
				break;
			}
		}
	}

	engine_export void bindStatisticsAsEvents();

	void bindEventsOnLoad();

	engine_export void enumerateEvents(TreeNode* destNode, bool asEventBinding);
	engine_export void enumerateEvents(EventBinding* dest);
	engine_export Variant enumerateEvents(FLEXSIMINTERFACE);

	engine_export TreeNode* assertEvent(const char* eventTitle);
	static bool s_assertEventCode;
	engine_export TreeNode* assertEvent(EventBinding* enumeration);
	engine_export TreeNode* assertEvent(const char* eventTitle, const Variant& p1, const Variant& p2 = Variant(), const Variant& p3 = Variant(), int* outFlags = nullptr);
	engine_export TreeNode* assertEventWithCode(const char* eventTitle, const Variant& p1 = Variant(), const Variant& p2 = Variant(), const Variant& p3 = Variant(), int* outFlags = nullptr);
	engine_export TreeNode* assertEvent(EventBinding* enumeration, const Variant& p1, const Variant& p2 = Variant(), const Variant& p3 = Variant());
	engine_export Variant assertEvent(FLEXSIMINTERFACE);
	engine_export Variant assertEventWithCode(FLEXSIMINTERFACE);
	engine_export TreeNode* assertEventNode(const char* eventTitle, TreeNode*& node);

	engine_export TreeNode* getEvent(const char* eventTitle);
	engine_export Variant getEvent(FLEXSIMINTERFACE);
	
	engine_export double getEventCurValue(EventBinding* binding);
	engine_export double getEventCurValue(EventBinding* binding, const Variant& p1, const Variant& p2 = Variant(), const Variant& p3 = Variant());
	engine_export double getEventCurValue(const char* eventTitle);
	engine_export double getEventCurValue(const char* eventTitle, const Variant& p1, const Variant& p2 = Variant(), const Variant& p3 = Variant());


#define FIRE_SDT_EVENT(node, ...) if (node) { node->evaluate(__VA_ARGS__); }
#define FIRE_SDT_EVENT_VALUE_GETTER(node, ...) (node ? node->evaluate(__VA_ARGS__) : Variant())
#define FIRE_SDT_EVENT_VALUE_CHANGE(node, newValue, oldValue) {if (node) { node->evaluate(newValue, oldValue); }}
#define FIRE_SDT_EVENT_VALUE_CHANGE_KINETIC(node, newValue, oldValue) {if (node) { node->evaluate(newValue, oldValue); }}

	private:
	/// <summary>	Makes sure that the enumeration is properly filled. </summary>
	/// <remarks>	Anthony.johnson, 8/14/2015. </remarks>
	/// <param name="enumeration">	[in,out] The enumeration. </param>
	bool assertValidEventBindingData(EventBinding* enumeration);
	TreeNode* assertRelayedEvent(EventBindingEntry& entry, const Variant& p1, const Variant& p2, const Variant& p3);
	TreeNode* assertEvent(EventBindingEntry& entry);
	TreeNode* assertEvent(EventBindingEntry& entry, const Variant& p1, const Variant& p2, const Variant& p3);
	double getEventCurValue(EventBindingEntry& entry);
	double getEventCurValue(EventBindingEntry& entry, const Variant& p1, const Variant& p2, const Variant& p3);
	static int s_bindEventMode;
	static EventBinding* s_eventBinding;
	static const char* s_bindEventTitle;
	static TreeNode* s_boundEventNode;
	static EventBindingEntry* s_eventBindingEntry;
	static std::string s_forwardingPrefix;
	static const char* s_originalTitle;
	static EventNodeResolver s_relayedEventResolver;
	TreeNode* getEventNode(const char* nodeName, const char* eventTitle, int flags, bool assert);
	//@}

	/** @name Statistic Binding
	*	Methods associated with enumerating and subscribing to statistics
	*/
	//@{
	public:
	virtual void bindStatistics() {}

	static const int BIND_STAT_ENUMERATE = 1;
	static const int BIND_STAT_ASSERT = 2;
	static const int BIND_STAT_ON_LOAD = 3;
	static const int BIND_STAT_FILL_BINDING_ENTRY = 4;
	static const int BIND_STAT_ON_RUNWARM = 5;
	static const int BIND_STAT_ON_BIND_EVENTS = 6;
	static const int BIND_STAT_ENUMERATE_REQUIREMENT_POSSIBILITIES = 7;
	static const int BIND_STAT_ENUMERATE_REQUIREMENT_NAMES = 8;
	static const int BIND_STAT_ENUMERATE_INTERFACE = 9;

	// flags and op codes for flagging extended functionality as well as retrieving data associated with
	// that functionality
	static const int STAT_TYPE_MASK = 0x7;
	static const int STAT_TYPE_LEVEL = 0x1; // the default, level stats change by delta
	static const int STAT_TYPE_CUMULATIVE = 0x2; // input, output can only be incremented; max, min, and avg are pointless
	static const int STAT_TYPE_TIME_SERIES = 0x3; // staytime is a stream of unrelated values; current value is less important
	static const int STAT_TYPE_CATEGORICAL = 0x4; // discrete is a set of discrete values that don't relate mathematically, i.e. state
	static const int STAT_TYPE_KINETIC_LEVEL = 0x5; // a "moving" level, i.e. you set it to a level and a rate, and the rate causes it to change.
	static const int STAT_TYPE_POINTER = 0x6; // like categorical, but stores noderefs instead of strings
	static const int STAT_TYPE_CATEGORICAL_COMBO = 0x7; // multiplies multiple categorical tvs together

	static const int STAT_USE_HISTORY = 0x10;
	static const int STAT_USE_PROFILE = 0x20;
	static const int STAT_IGNORE_WARMUP = 0x40;

	static const int STAT_RELAYED = 0x100;
	static const int STAT_NOT_EVENT = 0x400;

	static const int STAT_REQUIREMENTS = 0x30000; // the mask around all requirments flags
	static const int STAT_REQUIREMENTS_BIT_SHIFT = 16; // shift the requirements masked value 16 bits to get the number of requirements
	static const int STAT_1_REQUIREMENT = 0x10000;
	static const int STAT_2_REQUIREMENTS = 0x20000;
	static const int STAT_3_REQUIREMENTS = 0x30000;
	static int getNumStatRequirementsFromFlags(int flags)
	{
		return (flags & SimpleDataType::STAT_REQUIREMENTS) >> SimpleDataType::STAT_REQUIREMENTS_BIT_SHIFT;
	}

	// These constants deal with the meaningful derivative values
	static const int STAT_DERIVE_CUR = 0x1;
	static const int STAT_DERIVE_MIN = 0x2;
	static const int STAT_DERIVE_MAX = 0x4;
	static const int STAT_DERIVE_AVG = 0x8;

	engine_export static int getStatDerivativesFromFlags(int flags);

	engine_export static int getBindStatisticMode();

	typedef TreeNode*(SimpleDataType::*StatNodeResolver1) (const Variant& p1);
	typedef TreeNode*(SimpleDataType::*StatNodeResolver2) (const Variant& p1, const Variant& p2);
	typedef TreeNode*(SimpleDataType::*StatNodeResolver3) (const Variant& p1, const Variant& p2, const Variant& p3);
	
	static const int STAT_ENUM_REQS_INVALID = 0;
	static const int STAT_ENUM_REQS_STATIC = 1;
	static const int STAT_ENUM_REQS_DYNAMIC = 2;
	static const int STAT_ENUM_REQS_IGNORED = 3;
	typedef int(SimpleDataType::*StatRequirementEnumerator) (TreeNode* dest, const Variant& p1, const Variant& p2);
	

	class StatisticBindingEntry
	{
	public:
		static int s_bindStatFlags;
		ByteBlock statName;
		ByteBlock nodeName;
		int flags;
		int nodeByteOffset = 0;
		TreeNode** node;
		StatNodeResolver1 resolver;
		int numForwardsContained = 0;

		StatisticBindingEntry() : flags(0), resolver(nullptr), node(nullptr)
		{}
		StatisticBindingEntry(SimpleDataType* sdt, const char* _nodeName, TreeNode*& _node, const char* _statName, int _flags, StatNodeResolver1 _resolver)
			: node(&_node)
			, flags(_flags | s_bindStatFlags)
			, resolver(_resolver)
		{
			if (_nodeName)
				nodeName.write(_nodeName);

			if (_statName)
				statName.write(_statName);

			if (flags & STAT_REQUIREMENTS)
				node = nullptr;
			nodeByteOffset = (char*)(void*)(&_node) - (char*)(void*)sdt;
		}
	};

	private:
	engine_export void bindStatisticByNameEx(const char* nodeName, TreeNode*& node, const char* statName, int flags = 0, StatNodeResolver1 resolver = nullptr, StatRequirementEnumerator enumerator = nullptr);
	engine_export void bindRelayedClassStatisticsEx(const char* prefix, int flags, StatNodeResolver1 resolver, StatRequirementEnumerator enumerator, SimpleDataType* sdt);
	public:
	template <class ResolverCallbackType = nullptr_t, class EnumeratorCallbackType = nullptr_t>
	void bindStatisticByName(const char* nodeName, TreeNode*& node, const char* statName, int flags = 0, ResolverCallbackType resolver = nullptr, EnumeratorCallbackType enumerator = nullptr)
	{
		bindStatisticByNameEx(nodeName, node, statName, flags, force_cast<StatNodeResolver1>(resolver), force_cast<StatRequirementEnumerator>(enumerator));
	}
	#define bindStatistic(name, ...) \
		bindStatisticByName(#name, name, #name, __VA_ARGS__);

	template <class ResolverCallbackType = nullptr_t>
	void bindStatisticWithRequirement(const char* statTitle, int flags, ResolverCallbackType resolver)
	{
		TreeNode* x;
		bindStatisticByNameEx("", x, statTitle, flags, force_cast<StatNodeResolver1>(resolver));
	}


	template <class RelayToClass, class ResolverCallbackType = nullptr_t, class EnumeratorCallbackType = nullptr_t>
	void bindRelayedClassStatistics(const char* prefix, int flags, ResolverCallbackType resolver, EnumeratorCallbackType enumerator = nullptr)
	{
		switch (getBindStatisticMode()) {
		case BIND_STAT_ENUMERATE:
		case BIND_STAT_ENUMERATE_INTERFACE:
		case BIND_STAT_FILL_BINDING_ENTRY:
		case BIND_STAT_ENUMERATE_REQUIREMENT_POSSIBILITIES: 
		case BIND_STAT_ENUMERATE_REQUIREMENT_NAMES: {
			RelayToClass relayToClass;
			bindRelayedClassStatisticsEx(prefix, flags, force_cast<StatNodeResolver1>(resolver), force_cast<StatRequirementEnumerator>(enumerator), &relayToClass);
			break;
		}
		}
	}

	void bindStatisticsOnLoad();

	engine_export void enumerateStatistics(TreeNode* destNode, bool asStatisticBinding);
	engine_export void enumerateStatistics(StatisticBinding* dest);
	engine_export Variant enumerateStatistics(FLEXSIMINTERFACE);

	engine_export void enumerateInterfaceStatistics(StatisticBinding* dest);

	engine_export TreeNode* assertStatistic(const char* statTitle);
	engine_export TreeNode* assertStatistic(StatisticBinding* enumeration);
	engine_export TreeNode* assertStatistic(const char* statTitle, const Variant& p1, const Variant& p2 = Variant(), const Variant& p3 = Variant(), int* outFlags = nullptr);
	engine_export TreeNode* assertStatistic(StatisticBinding* enumeration, const Variant& p1, const Variant& p2 = Variant(), const Variant& p3 = Variant());
	engine_export Variant assertStatistic(FLEXSIMINTERFACE);
	engine_export TreeNode* assertStatisticNode(const char* statTitle, TreeNode*& node);

	engine_export int enumerateRequirementPossibilities(const char* statTitle, TreeNode* destNode, const Variant& p1 = Variant(), const Variant& p2 = Variant());
	engine_export Variant enumerateRequirementPossibilities(FLEXSIMINTERFACE);

	engine_export Variant enumerateRequirementNames(const char* statTitle);
	engine_export Variant enumerateRequirementNames(FLEXSIMINTERFACE);
	engine_export void ListStatRequirementNames(const char* name1, const char* name2 = 0, const char* name3 = 0);

#define UPDATE_SDT_STAT(node, newValue) if (node) { node->objectAs(TrackedVariable)->set(newValue); }
#define UPDATE_SDT_STAT_DELTA(node, delta) if (node) {\
	TrackedVariable* tv = node->objectAs(TrackedVariable);\
	tv->set(tv->getCurrent() + delta); }
#define UPDATE_SDT_STAT_CUMULATIVE(node) UPDATE_SDT_STAT_DELTA(node, 1)
#define UPDATE_SDT_STAT_KINETIC(node, newValue, newRate) if (node) {node->objectAs(TrackedVariable)->set(newValue, newRate);}
#define RESET_SDT_STAT(node, ...) if (node) {node->objectAs(TrackedVariable)->reset(__VA_ARGS__);}
#define SET_SDT_STAT_KINETIC_BOUNDS(node, lower, upper) if (node) {node->objectAs(TrackedVariable)->setBounds(lower, upper);}

	/// <summary>	Sets the SDT's primary value. </summary>
	/// <remarks>	 This is used to allow a user to use
	/// 			setlabel() or some other mechanism to set the value on a node. Child 
	/// 			classes should override this if they want setlabel() to set a value on 
	/// 			the node without removing/adding new data.</remarks>
	/// <param name="val">	The value. </param>
	/// <returns>	true if it succeeds, false if it cannot set its primary value to the given value. </returns>
	virtual bool setPrimaryValue(const Variant& val) { return false; }
	virtual Variant getPrimaryValue() { 
		VariantParams params;
		return evaluate(params);
	}

	private:
	/// <summary>	Makes sure that the enumeration is properly filled. </summary>
	/// <remarks>	Anthony.johnson, 8/14/2015. </remarks>
	/// <param name="enumeration">	[in,out] The enumeration. </param>
	bool assertStatisticBinding(StatisticBinding* enumeration);
	TreeNode* assertStatistic(StatisticBindingEntry& entry);
	TreeNode* assertStatistic(StatisticBindingEntry& entry, const Variant& p1, const Variant& p2, const Variant& p3);
	static int s_bindStatisticMode;
	static StatisticBinding* s_statBinding;
	static const char* s_assertStatisticName;
	static TreeNode* s_assertedStatistic;
	static StatisticBindingEntry* s_statBindingEntry;
	static std::string s_forwardingStatPrefix;
	static std::string s_statAsEventPrefix;
	static StatNodeResolver1 s_relayedStatResolver;
	static StatRequirementEnumerator s_requirementEnumerator;
	static SimpleDataType* s_enumerateObject;
	static const char* s_enumerateReqsName;
	static TreeNode* s_enumerateReqsNode;
	static Variant s_requirement1;
	static Variant s_requirement2;
	static int s_enumerateReqsResult;
	static Variant s_enumerateReqNamesResult;
	TreeNode* getStatisticNode(const char* nodeName, int flags, bool assert);

	//@}

	/** @name Interface Binding
	*	Methods associated with enumerating what methods and operators are available to flexscript
	*/
	//@{
	public:
	static const int BIND_METHOD_STATIC = 0x2;
	virtual bool isClassType(const char* className) { const char* classFactory = getClassFactory(); return classFactory && strcmp(classFactory, className) == 0; }
	virtual void bindInterface() {}
#if !defined FLEXSIM_ENGINE_COMPILE || defined FLEXSIM_FLEXSCRIPT_CPP
	private:
	engine_export static void bindMethodByName(const char* name, void* callback, const char* signature, int flags = 0);
	public:
	template<class Callback>
	static void bindMethodByName(const char* name, typename std::enable_if<std::is_member_function_pointer<Callback>::value || std::is_pointer<Callback>::value, Callback>::type callback, const char* signature, int flags = 0)
	{
		bindMethodByName(name, force_cast<void*>(callback), signature, flags);
	}

#define bindMethod(method, className, signature, ...) SimpleDataType::bindMethodByName<decltype(&className::method)>(#method, &className::method, signature, ##__VA_ARGS__)

	private:
	engine_export static void bindPropertyByName(const char* name, PropertyBinding* newProperty);
	engine_export static void bindOperatorByName(const char* opName, void* operatorPtr, const char* signature);
	public:
	template<class Callback>
	static void bindOperatorByName(const char* opName, typename std::enable_if<std::is_member_function_pointer<Callback>::value || std::is_pointer<Callback>::value, Callback>::type callback, const char* signature)
	{
		bindOperatorByName(opName, force_cast<void*>(callback), signature);
	}
#define bindOperator(method, className, signature) bindOperatorByName<decltype(&className::operator method)>(#method, &className::operator method, signature)

	private:
	
	public:
	template <class Type>
	static void bindTypedPropertyByName(const char* name, const char* typeName, void* getter, void* setter, const char* version = nullptr) 
	{
		if (version)
			bindPropertyByName(name, new TypedPropertyBinding<Type>(typeName, getter, setter, version));
		else
			bindPropertyByName(name, new TypedPropertyBinding<Type>(typeName, getter, setter));
	}
	template <class Type>
	static void bindStaticTypedPropertyByName(const char* name, const char* typeName, void* getter, void* setter, const char* version = nullptr)
	{
		if (version)
			bindPropertyByName(name, new StaticTypedPropertyBinding<Type>(typeName, getter));
		else
			bindPropertyByName(name, new StaticTypedPropertyBinding<Type>(typeName, getter));
	}
	template<int value>
	static void bindStaticConstIntPropertyByName(const char* name)
	{
		struct MyGetterClass {
			static int getter() { return value; }
		};
		bindStaticTypedPropertyByName<int>(name, "int", (void*)&MyGetterClass::getter, nullptr);
	}

private:
	engine_export static void bindConstructorVoidPtr(void* constructorCallback, const char* signature);
	engine_export static void bindDestructorVoidPtr(void* destructorCallback);
public:
	template <class Type> 
	static void bindConstructor(Type constructorCallback, const char* signature)
	{
		bindConstructorVoidPtr(force_cast<void*>(constructorCallback), signature);
	}
	template <class Type>
	static void bindConstructor(void (Type::*constructorCallback) (), const char* signature)
	{
		bindConstructorVoidPtr(force_cast<void*>(constructorCallback), signature);
	}
	template <class Type>
	static void bindDestructor(void(Type::*destructorCallback)())
	{
		bindDestructorVoidPtr(force_cast<void*>(destructorCallback));
	}

#define bindTypedProperty(member, type, getter, setter, ...) SimpleDataType::bindTypedPropertyByName<type>(#member, #type, force_cast<void*>(getter), force_cast<void*>(setter), ##__VA_ARGS__)
#define bindStaticConstIntProperty(name, value) bindStaticConstIntPropertyByName<value>(#name)

	static void bindPropertyByName(const char* name, void* getter, void* setter)
	{
		bindPropertyByName(name, new PropertyBinding(getter, setter));
	}
#define bindProperty(member, getter, setter) SimpleDataType::bindPropertyByName(#member, force_cast<void*>(getter), force_cast<void*>(setter))

	static engine_export void bindParentClass(const char* className);

	private:
	engine_export static void bindDynamicPropertyPrivate(PropertyBinding* dynamicPropertyBinding);
	public:
	template<class Getter, class Setter>
	static void bindDynamicPropertyByType(
		typename std::enable_if<std::is_member_function_pointer<Getter>::value, Getter>::type propertyGetter,
		typename std::enable_if<std::is_member_function_pointer<Setter>::value, Setter>::type propertySetter
		) {
		bindDynamicPropertyPrivate(new PropertyBinding(propertyGetter, propertySetter));
	}
#define bindDynamicProperty(getter, setter) SimpleDataType::bindDynamicPropertyByType<decltype(getter), decltype(setter)>(getter, setter);

	private:
	engine_export static void bindNodeListArrayClassPrivate(void** data);

	public:
	template <class NLA>
	static void bindNodeListArrayClassByName(const char* interfaceName, const char* elementName, bool readOnly = false)
	{
		class NLAHelper : public NLA
		{
		public:
			void construct(NLA& other) { ::new(this)NLA(other); }
		};

		auto bracketOp = (typename NLA::ElementType*(NLA::*)(int) const)&NLA::operator[];
		auto copyConstructor = (void(NLA::*)(NLA& other))&NLAHelper::construct;
		auto copyAssigner = (NLA&(NLA::*)(const NLA& other))&NLA::operator=;
		auto addedBinder = (void(*)())&NLA::bindInterface;
		auto boolCaster = (bool(NLA::*)())&NLA::operator bool;

		void* data[] = {
			(void*)interfaceName,
			(void*)elementName,
			force_cast<void*>(&NLA::size),
			force_cast<void*>(bracketOp),
			force_cast<void*>(&NLA::toArray),
			force_cast<void*>(copyConstructor),
			force_cast<void*>(copyAssigner),
			force_cast<void*>(addedBinder),
			readOnly ? nullptr : force_cast<void*>(&NLA::push),
			readOnly ? nullptr : force_cast<void*>(&NLA::pop),
			readOnly ? nullptr : force_cast<void*>(&NLA::shift),
			readOnly ? nullptr : force_cast<void*>(&NLA::unshift),
			force_cast<void*>(boolCaster),
		};
		bindNodeListArrayClassPrivate(data);
	}
#define bindNodeListArrayAsClass(Class, Element) SimpleDataType::bindNodeListArrayClassByName<Class>(#Class, #Element)
#define bindNodeListArrayAsReadOnlyClass(Class, Element) SimpleDataType::bindNodeListArrayClassByName<Class>(#Class, #Element, true)

	private:
		engine_export static void bindCastOperatorPrivate(const char* castClass, void* funcPtr);
	public:
		template <class Type, class ToType>
		static void bindCastOperatorByName(const char* castClass, ToType(Type::*funcPtr)())
		{
			bindCastOperatorPrivate(castClass, force_cast<void*>(funcPtr));
		}
		template <class Type, class ToType>
		static void bindCastOperatorByName(const char* castClass, ToType(Type::*funcPtr) () const)
		{
			bindCastOperatorPrivate(castClass, force_cast<void*>(funcPtr));
		}
#define bindCastOperator(to, caster) SimpleDataType::bindCastOperatorByName(#to, caster)

	private:
		engine_export static void bindBracketOperatorPrivate(const char* returnType, void* operatorPtr, bool intElseString, bool ptrElseClass);
	public:
		template <typename ReturnType, typename Type>
		static void bindBracketOperatorByName(const char* returnTypeName, ReturnType(Type::* operatorPtr)(int)) {
			if (std::is_pointer<ReturnType>::value)
				bindBracketOperatorPrivate(returnTypeName, force_cast<void*>(operatorPtr), true, true);
			else
				bindBracketOperatorPrivate(returnTypeName, force_cast<void*>(operatorPtr), true, false);
		}
		template <typename ReturnType, typename Type>
		static void bindBracketOperatorByName(const char* returnTypeName, ReturnType(Type::* operatorPtr)(const char*)) {
			if (std::is_pointer<ReturnType>::value)
				bindBracketOperatorPrivate(returnTypeName, force_cast<void*>(operatorPtr), false, true);
			else
				bindBracketOperatorPrivate(returnTypeName, force_cast<void*>(operatorPtr), false, false);
		}
		template <typename ReturnType, typename Type>
		static void bindBracketOperatorByName(const char* returnTypeName, ReturnType(Type::* operatorPtr)(const Variant&)) {
			if (std::is_pointer<ReturnType>::value)
				bindBracketOperatorPrivate(returnTypeName, force_cast<void*>(operatorPtr), false, true);
			else
				bindBracketOperatorPrivate(returnTypeName, force_cast<void*>(operatorPtr), false, false);
		}
#define bindBracketOperator(ReturnType, Class, Arg) \
	SimpleDataType::bindBracketOperatorByName(#ReturnType, (ReturnType(Class::*)(Arg))&Class::operator [])

	private:
		engine_export static void bindCopyConstructorPrivate(void* copyConstructor);
		engine_export static void bindCopyAssignerPrivate(void* copyAssigner);

	public:
		template <class Type> // for const copy constructor
		static void bindCopyConstructor(void(Type::*construct)(const Type&)) { bindCopyConstructorPrivate(force_cast<void*>(construct)); }
		template <class Type> // for non-const copy constructor
		static void bindCopyConstructor(void(Type::*construct)(Type&)) { bindCopyConstructorPrivate(force_cast<void*>(construct)); }

		template <class Type> // for const copy assigner
		static void bindCopyAssigner(Type&(Type::*assigner)(const Type&)) { bindCopyAssignerPrivate(force_cast<void*>(assigner)); }
		template <class Type> // for non-const copy assigner
		static void bindCopyAssigner(Type&(Type::*assigner)(Type&)) { bindCopyAssignerPrivate(force_cast<void*>(assigner)); }

	private:
		engine_export static void bindClassByNamePrivate(const char* className, void* method, size_t size, char bindClassFlags);
	public:
		const static char BIND_CLASS_USER_ACCESSIBLE = 0x1;
		const static char BIND_CLASS_CAN_SET_PROPS_RVALUE = 0x2;

		template <class ClassType>
		static void bindClassByName(const char* className, char bindClassFlags = 0) {
			bindClassByNamePrivate(className, force_cast<void*>(&ClassType::bindInterface), sizeof(ClassType), bindClassFlags);
		}
#define bindClass(ClassType, ...) SimpleDataType::bindClassByName<ClassType>(#ClassType, ##__VA_ARGS__)

	public:
		engine_export static void bindDocumentationXMLPath(const char* path);
		engine_export static void bindToVariantFunc(Variant(*)(void*));
#endif
	public:

		static SimpleDataType* createEngineSDTDerivative(const char* classname, TreeNode* holder);

		typedef SimpleDataType* (*CreateSDTDerivative)(const char* classname, TreeNode* holder);
		static CreateSDTDerivative createContentSDTDerivative;
		static SimpleDataType* createSDTDerivative_NoDLLConnection(const char* classname, TreeNode* holder);
		virtual ObjectDataType* toObject() { return nullptr; }
	//@}

	/** @name 3D/Tree User Interaction
	*	Methods associated with the user manipulating the object in 3D/Tree
	*/
	//@{
		virtual double onDrag(TreeNode* view) { return 0; }
		virtual double onClick(TreeNode* view, int clickCode) { return 0; }
		virtual double onCreate(bool isCopy) { return 0; }
		virtual double onDestroy(TreeNode* view) { return 0; }
		virtual unsigned int getClassType() { return 0; }
		virtual double dragConnection(treenode toobject, char characterpressed, unsigned int classtype) { return 0; }
		virtual double onUndo(bool isUndo, treenode undoRecord) { return 0; }
	//@}


	engine_export virtual Variant function(const char* funcName, CallPoint* cp);
	engine_export Variant function(const char* funcName, n10varsdefaultinterface);
};

template <>
class SimpleDataType::StlValueBinder<char*> {
public:
	static treenode Saver(treenode x, char** toVal)
		{Variant::set(x, *toVal); return x;}
	static char* Loader(treenode x)
		{return x->safedatabyteblock()->getBuffer();}
	static void Displayer(char** x)
		{appendToDisplayStr(*x);}
};

template <>
class SimpleDataType::StlValueBinder<std::string> {
public:
	static treenode Saver(treenode x, std::string* toVal)
		{Variant::set(x, *toVal); return x;}
	static std::string Loader(treenode x)
		{return x->safedatabyteblock()->getBuffer();}
	static void Displayer(std::string* x)
		{appendToDisplayStr(x->c_str());}
};

template <>
class SimpleDataType::StlValueBinder<treenode> {
public:
	static treenode Saver(treenode x, treenode* toVal)
		{x->addData(DATA_POINTERCOUPLING)->pointTo(*toVal); return x;}
	static treenode Loader(treenode x)
		{return x->safedatapartner();}
	static void Displayer(treenode* x)
	{
		std::string str;
		if (*x)
			str = (*x)->getPath();
		else if(*x == 0)
			str = "NULL";
		else str = "[Invalid Ptr]";
		appendToDisplayStr(str.c_str());
	}
};

template <>
class SimpleDataType::StlValueBinder<NodeRef> {
public:
	static treenode Saver(treenode x, NodeRef* toVal)
	{ x->addData(DATA_POINTERCOUPLING)->pointTo(*toVal); return x; }
	static NodeRef Loader(treenode x)
	{ return x->safedatapartner(); }
	static void Displayer(NodeRef* x)
	{
		std::string str;
		if (*x)
			str = (*x)->getPath();
		else if (!(*x))
			str = "NULL";
		else str = "[Invalid Ptr]";
		appendToDisplayStr(str.c_str());
	}
};

template <class T>
void SimpleDataType::StlValueBinder<T*, typename std::enable_if_t<std::is_base_of_v<SimpleDataType, T>>>::Displayer(T** x)
{
	if (x && (*x))
		StlValueBinder<treenode>::Displayer(&((*x)->holder));
	else appendToDisplayStr("NULL");
}

/// <summary>	Event binding. Stores enumerated events and saves binding information for later use.  </summary>
/// <remarks>	Allows a "client" object to get an enumeration of an object's available events once, 
/// 			and then bind to a specific event without having to call bindEvents()
/// 			each time. This can be especially helpful at simulation run time if you don't want
/// 			to have to call bindEvents() over and over again each time you want to get the node
/// 			associated with an event. This method is much faster using a method that repeatedly 
/// 			calls bindEvents().
/// 			Here's how you work with it.
/// 			
/// 			// at model building time, or on reset
/// 			sdt->enumerateEvents(destNode, true); // this will populate the EventBinding with all the needed data
/// 			EventBinding* binding = destNode->objectAs(EventBinding);
/// 			binding->select("OnEntry"); // this selects the given event
/// 			
/// 			... later, during simulation run
/// 			treenode eventNode = sdt->assertEvent(binding); // will get the node associated with the event, without calling bindEvents().
/// 			
/// 			... also, you can switch to another sdt of the same class. Note that it MUST be of the same 
/// 			class, or else all hell will break loose.
/// 			treenode newEventNode = newSDT->assertEvent(binding);
/// 			</remarks>
class EventBinding : public SimpleDataType
{
public:
	virtual const char* getClassFactory() override { return "EventBinding"; }
	engine_export virtual void bind() override;
	ObjRef<SimpleDataType> object;
	int selected = -1;
	bool isSelectionValid() { return selected >= 0 && selected < events.size(); }
	void* virtualTable = nullptr;
	ByteBlock selectedEventTitle;
	/// <summary>	Selects the given event. This can be used in conjunction with SimpleDataType::assertEvent(EventBinding*, ...). 
	/// 			Instead of </summary>
	/// <remarks>	Anthony.johnson, 8/15/2015. </remarks>
	/// <param name="eventTitle">	The event title. </param>
	engine_export void select(const char* eventTitle);
	/// <summary>	Selects the given sdt, rebinding its event entries based on that sdt. </summary>
	/// <remarks>	This will rebind event node pointers. If there is a currently selected event, then
	/// 			for speed reasons it will only rebind that event's node. </remarks>
	/// <param name="sdt">	[in,out] If non-null, the sdt. </param>
	engine_export void select(SimpleDataType* sdt);
	FlexSimPrivateTypes::Vector<SimpleDataType::EventBindingEntry> events;
	const EventBindingEntry& getSelectedEntry() { return events[selected]; }
};

class StatisticBinding : public SimpleDataType
{
private:
	std::vector<SimpleDataType::StatisticBindingEntry> statistics;

public:
	virtual const char* getClassFactory() override { return "StatisticBinding"; }
	engine_export virtual void bind() override;
	ObjRef<SimpleDataType> object;
	int selected = -1;
	bool isSelectionValid() { return selected >= 0 && selected < statistics.size(); }
	void* virtualTable = nullptr;
	ByteBlock selectedStatisticTitle;
	/// <summary>	Selects the given statsitic. This can be used in conjunction with SimpleDataType::assertStatistic(StatisticBinding*, ...). 
	/// 			Instead of </summary>
	/// <remarks>	Anthony.johnson, 8/15/2015. </remarks>
	/// <param name="statName">	The statistic name. </param>
	engine_export void select(const char* statName);
	/// <summary>	Selects the given sdt, rebinding its stat entries based on that sdt. </summary>
	/// <remarks>	This will rebind stat node pointers. If there is a currently selected stat, then
	/// 			for speed reasons it will only rebind that stat's node. </remarks>
	/// <param name="sdt">	[in,out] If non-null, the sdt. </param>
	engine_export void select(SimpleDataType* sdt);
	
	void addStatistic(StatisticBindingEntry& newEntry);
	engine_export StatisticBindingEntry& getSelectedEntry();
	void clearStatistics();

	engine_export StatisticBindingEntry* begin();
	engine_export StatisticBindingEntry* end();
};

#if !defined FLEXSIM_ENGINE_COMPILE || defined FLEXSIM_FLEXQL
class SqlQueryInterface : public SimpleDataType
{
public:
	virtual void setLimit(int limit) = 0;
	virtual SqlCursor getCurrentCursorByTableID(int tableID) = 0;
	virtual SqlCursor getMatchCursorByTableID(int tableID, int matchRow) = 0;
	virtual SqlCursor getMatchCursor(const char* tableName, int matchRow) = 0;
	virtual SqlCursor getMatchCursor(int tableNum, int matchRow) = 0;
	virtual int getResultLength() = 0;
	virtual int getResultNumCols() = 0;
	virtual Variant getResult(int row, int col) = 0;
	virtual Variant getResult(int row, const char* col) = 0;

	virtual int run(SqlDataSource* d, bool doSort = true) = 0;
	virtual int run(bool doSort = true) = 0;

	virtual bool hasSelect() = 0;
	virtual bool hasFrom() = 0;
	virtual bool hasWhere() = 0;
	virtual bool hasOn() = 0;
	virtual bool hasOrderBy() = 0;
	virtual bool hasGroupBy() = 0;
	virtual bool hasHaving() = 0;

	virtual Array getResultArray() = 0;

	virtual SqlDataSource* getDataSource() = 0;

	virtual Variant evaluateTableValuedFunctionParams(void* tableRef) { return Variant(); }
};

/// <summary>	Defines an interface for interaction with FlexSim's SQL parser/evaluator. </summary>
/// <remarks>	Sub-class implementations act as delegates to the parser,
/// 			providing, first, mappings of table and column names to table and
/// 			column id's, and second, an interface for retrieving values out of
/// 			those tables.</remarks>
class SqlDataSource : public SimpleDataType
{

/// <summary>	A macro that defines if a column as not found. Returned by the SqlDataSource::getColID() if it cannot find that column.</summary>
#define SQL_COL_NOT_FOUND INT_MAX
/// <summary>	"Not found" table is one that it tried to resolve but couldn't. </summary>
#define SQL_TABLE_NOT_FOUND (INT_MAX - 2)

#define SQL_FLEXSCRIPT_EXCEPTION (INT_MAX - 3)
/// <summary>	A macro that defines if a column is actually a namespace. Returned by the SqlDataSource::getColID()
///             This is INT_MAX - 2001 because everything above that is considered an error, but a namespace should 
///             not be considered an error.</summary>
#define SQL_COL_NAMESPACE (INT_MAX - 2001)

#define SQL_COL_END ((const char*) 0x2)
#define SQL_NULL Variant()

public:

	static const int COL_INDEXED = 0x1; // tells the execution engine that the data source has an quick lookup index for values.
	static const int COL_INDEX_ORDERED = 0x2; // tells the execution engine that the data source has an ordered quick lookup index, so the user can get fast lookups both with an ==, as well as with a <, >, <=, and >=.
	static const int COL_DYNAMIC = 0x4; // signal to the sql execution engine that it should perhaps be cached because it may change on each execution
	static const int COL_CONSTANT = 0x8; // signal to the sql execution engine that this column value is constant across all rows of the table (for indexing)
	static const int COL_DO_NOT_INDEX = 0x10; // signal to the sql execution engine that this column should not be automatically indexed. Specifically used by lists, because indexing lists wastes CPU time.
	static const int COL_NAMESPACE = 0x20; // signal to the sql execution engine that this column is a namespace. If getColID() returns SQL_COL_NAMESPACE, then the column is a namespace and is not itself 
											// a field. If getColID() returns a valid column id, and the COL_NAMESPACE flag is set, then the column name is a valid field, but it is also a namespace. For 
											// example, in the Objects() table, Location is itself a valid field, but it is also a namespace for Location.X, Location.Y, Location.Z
	/// <summary>	Returns the column identifier of the column with the defined name in the defined
	/// 			table. </summary>
	/// <remarks>	Anthony, 8/27/2014. </remarks>
	/// <param name="tableId"> 	Identifier for the table. </param>
	/// <param name="colName"> 	Name of the column. </param>
	/// <param name="colFlags">	[out] The col flags. </param>
	/// <returns>	The column identifier. </returns>
	virtual int getColID(int tableId, const char* colName, int& colFlags) { return SQL_COL_NOT_FOUND; }

	/// <summary>	Enumerate column names of a table. </summary>
	/// <remarks>	Anthony, 8/27/2014. </remarks>
	/// <param name="tableId">	 This is used if the parser needs a full enumeration of the columns of a table,
	/// 			specifically for a SELECT * clause. The sql parser will start with colNum = 0, and then
	/// 			iteratively call this method, incrementing colNum each time, until the method returns 
	/// 			SQL_COL_END. Each call should return the name of a column.</param>
	/// <param name="colNum"> 	The 0-based column number. </param>
	/// <returns>	Returns the name of a column, or SQL_COL_END. </returns>
	virtual const char* enumerateColNames(int tableID, int colNum){return SQL_COL_END;}

	/// <summary>	Retrieves a value out of a table. </summary>
	/// <remarks>	Anthony, 8/27/2014. </remarks>
	/// <param name="tableId">	Identifier for the table. </param>
	/// <param name="row">	  	The zero-based row. </param>
	/// <param name="colId">  	Identifier for the col. </param>
	/// <returns>	The value. </returns>
	virtual Variant getValue(int tableID, int row, int colID) {return SQL_NULL;}

	virtual Variant getValue(int tableID, const SqlCursor& cursor, int colID) { return getValue(tableID, (int)cursor.id, colID); }

	/// <summary>	Sets a value. </summary>
	/// <remarks>	Anthony.johnson, 2/25/2016. </remarks>
	/// <param name="tableId">	Identifier for the table. </param>
	/// <param name="row">	  	The row. </param>
	/// <param name="colId">  	Identifier for the col. </param>
	/// <param name="toVal">  	to value. </param>
	/// <returns>	true if it succeeds, false if it fails. </returns>
	virtual bool setValue(int tableId, int row, int colId, const Variant& toVal) { return false; }
	virtual bool setValue(int tableID, const SqlCursor& cursor, int colID, const Variant& toVal) { return setValue(tableID, (int)cursor.id, colID, toVal); }

	/// <summary>	Gets a table's identifier. </summary>
	/// <remarks>	Anthony, 8/27/2014. </remarks>
	/// <param name="tableName">	Name of the table. </param>
	/// <returns>	The table identifier. </returns>
	virtual int getTableID(const char* tableName) {return 0;}

	/// <summary>	Gets a table's identifier. </summary>
	/// <remarks>	Anthony, 8/27/2014. </remarks>
	/// <param name="tableName">	Name of the table. </param>
	/// <returns>	The table identifier. </returns>
	virtual int getTableID(const char* tableName, SqlQueryInterface* query, bool isTableValuedFunction, void* tableRef) { return getTableID(tableName); }

	/// <summary>	Returns the number of rows in a table. </summary>
	/// <remarks>	Anthony, 8/27/2014. </remarks>
	/// <param name="tableId">	Identifier for the table. </param>
	/// <returns>	The number of rows in the table. </returns>
	virtual int getRowCount(int tableID) {return 0;}

	engine_export virtual SqlCursorAdvancer* initAdvancer(int tableID, SqlCursorAdvancer* defaultAdvancer, bool& manageMemory)
	{
		defaultAdvancer->tableSize = getRowCount(tableID);
		return defaultAdvancer;
	}

	static const int COMP_EQ = 0;
	static const int COMP_GT = 1;
	static const int COMP_LT = 2;
	static const int COMP_GE = 3;
	static const int COMP_LE = 4;
	virtual int getNextIndexedRow(int tableID, int colID, const Variant& value, int lastRow = -1) { return -1; }

	virtual bool initIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) { cursor.id = getNextIndexedRow(tableID, colID, value, -1); return cursor.id >= 0; }
	virtual bool advanceIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) { cursor.id = getNextIndexedRow(tableID, colID, value, (int)cursor.id); return cursor.id >= 0; }


	virtual const char* getClassFactory() override { return "SqlDataSource"; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Query if this object has custom where filter. </summary>
	///
	/// <remarks>	This is used by the list, so a pull query can include a list of 
	/// 			objects that it's looking for, in addition to (or in place of) the WHERE clause. </remarks>
	///
	/// <returns>	True if custom where filter, false if not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool hasCustomWhereFilter() { return false; }
	virtual bool evaluateCustomWhereFilter(SqlQueryInterface* q) { return true; }
	virtual const char* getFlexScriptType(int tableID, int colID) { return nullptr; }
	virtual void onStartBuildQuery() {}
	virtual void onStartRunQuery(SqlQueryInterface* q) {}
	virtual void insertInto(int tableID, const Variant& columnIDs, const Variant& values) { throw "INSERT INTO not supported for this type of table"; }
	virtual void deleteRows(int tableID, const SqlCursor* cursors, int numCursors) { throw "DELETE not supported for this type of table"; }
};
#endif

/// <summary>	Defines the TrackedVariable class. </summary>
/// <remarks>	Tracked variables accept a sequence of values (one at a time)
///				and provide methods to get the current, min, max, and avg. </remarks>
class TrackedVariable : public SimpleDataType
{
private:
	static const int HISTORY_FIELD_TIME = 0;
	static const int HISTORY_FIELD_VALUE = 1;
	void assertHistory();
	void resetHistory();
	void deassertHistory();
	void deassertProfile();
	double curValue;
	double _rate = 0.0;
public:

	engine_export TrackedVariable(); //Use init() method instead. Do not use this.
	engine_export ~TrackedVariable() {}
	engine_export static TrackedVariable* init(TreeNode* theNode, int type, double startVal = 0, int flags = 0);
	static const char* className;
	virtual TrackedVariable* toTrackedVariable() override { return this; }
	engine_export virtual const char* getClassFactory() override { return "TrackedVariable"; }
	virtual bool isClassType(const char* className) override { return strcmp(className, "TrackedVariable") == 0 || __super::isClassType(className); }
	engine_export virtual void bind() override;
	engine_export virtual void bindInterface() override;
	engine_export virtual char* toString(int verbose) override; 

	static TrackedVariable* global(const char* name);

	treenode history = nullptr;
	int type = SimpleDataType::STAT_TYPE_LEVEL;
	double startValue;
	double cumulative;
	double cumulativeTime;
	double minValue;
	double maxValue;
	double numEntries;
	double lastSetTime;
	treenode profile = nullptr;
	treenode onChange = nullptr;
	treenode dependencies = nullptr;
	double flags = 0;
	double lowerBound = -DBL_MAX;
	double upperBound = DBL_MAX;

	bool useCachedTime = false;
	double cachedTime = 0.0;

	engine_export void reset(double value = FLT_MAX, int type = -1);
	engine_export void set(double value);
	// TODO: implement proper acc/dec for kinetic levels
	//engine_export void set(double value, double toRate, double toAcc);
	engine_export void set(double value, double toRate);
	engine_export void set(const Variant& value);

	engine_export void setAtTime(double value, double curTime);
	engine_export void setAtTime(double value, double toRate, double curTime);
	engine_export void setAtTime(const Variant& value, double curTime);

	engine_export void setBounds(double lower, double upper) { lowerBound = lower; upperBound = upper; }
	engine_export void setUpperBound(double upper);
	engine_export void setLowerBound(double lower);

	engine_export double getUpperBound();
	engine_export double getLowerBound();

	engine_export Table getProfile();
	engine_export Table getHistory();

	engine_export int getType() { return type; }

	engine_export operator TreeNode*();
	engine_export operator Variant();
private:
	void updateKineticCumulative(double endUndboundedValue, double timeAtCurrent);
	void __setRate(double toRate);
	static bool blockOnChange;
public:

	engine_export virtual void bindEvents() override;
	engine_export virtual void bindStatistics() override;

	engine_export double getAvg();
	engine_export double getMin();
	engine_export double getMax();
	engine_export double getCurrent();

	/// <summary>	Gets the arrival time for a given value, or -1 if never. </summary>
	/// <remarks>	This is only applicable for kinetic level variables </remarks>
	/// <param name="atValue">	The target value. </param>
	/// <returns>	The time that the variable will arrive at the target value, or -1 if never. </returns>
	engine_export double getArrivalTime(double atValue);
	engine_export double getCurrentRate() { return _rate; }
	__declspec(property(get = getCurrentRate, put = __setRate)) double rate;

	engine_export double getLastResetTime() { return lastResetTime; }
	engine_export double getAge();
	__declspec(property(get = getAge)) double age;

private:
	double getCurrentIgnoringBounds();
public:
	engine_export double getCount();
	engine_export double getTotalTimeAt(const Variant& state);
	engine_export int getNumCategories();
	Variant getTotalTimeAt(FLEXSIMINTERFACE);
	static const int PROFILE_FIELD_NAME = 0;
	static const int PROFILE_FIELD_TIME = 1;
	static const int PROFILE_FIELD_ACTIVE = 2;
	engine_export void assertProfile(int toStateRank, TreeNode* guide, bool persist);
	engine_export bool hasProfile(int toStateRank);

	engine_export virtual bool setPrimaryValue(const Variant& val) override;
	virtual Variant getPrimaryValue() override { return getCurrent(); }
	virtual Variant evaluate(const VariantParams& params) override { return getCurrent(); }
	engine_export Variant getCategoricalName();
	std::string getCategoryName(int catNum) const;
	engine_export Variant getCategoryValue(int catNum = -1);

	engine_export static TrackedVariable* create();
	engine_export void addSubscriber(bool needsHistory, bool needsProfile, bool persist);
	Variant addSubscriber(FLEXSIMINTERFACE);

	virtual void initializeLike(SimpleDataType* other) override;

private:
	void onComboStateChange();
	static bool inComboStateChange;
	friend class ComboStateChangeEvent;
public:
	engine_export void clearListeners();
	engine_export void listenTo(TrackedVariable* other);

	static bool resetStatsCalled;
private:
	void countDownSubscribers();
	int needsHistoryCountDown = 0;
	int needsProfileCountDown = 0;
	double lastResetTime;
};

#if !defined FLEXSIM_ENGINE_COMPILE || defined FLEXSIM_SDT_CLASSES
class StatVariable : public SimpleDataType
{
protected:
	int type;
	Variant value;
	TreeNode* onChange = nullptr;

public:
	virtual const char* getClassFactory() override { return "StatVariable"; }
	virtual bool isClassType(const char* className) override { return strcmp(className, "StatVariable") == 0 || __super::isClassType(className); }

	virtual void bind() override;
	virtual void bindEvents() override;
	virtual bool setPrimaryValue(const Variant& val) override;
	virtual Variant getPrimaryValue() override;
	virtual Variant evaluate(const VariantParams& params) override;
	virtual TreeNode* getEventInfoObject(const char* eventTitle) override;
	virtual char* toString(int displayFlags) override;

	engine_export static StatVariable* init(TreeNode* holder, int type);
};

#endif

/// <summary>	Defines the Table Header class. </summary>
/// <remarks>	Preserves column header names when all of a table's rows are removed.</remarks>
class TableHeader : public SimpleDataType
{
public:
	Array headers;
	Array dataTypes;
	virtual const char* getClassFactory() override { return "TableHeader"; }
	TableHeader() {}
	virtual void bind() override;
	static TableHeader* create() { return new TableHeader; }

	void saveHeaders(TreeNode* table);
	void restoreHeaders(TreeNode* table);
	void resizeHeaders(TreeNode* table, int xSize, double dataType, int index = 0);
	
	int numCols() {	return (int)headers.size(); }

	virtual char* toString(int displayFlags) override;

};

}
