#pragma once
// COPYRIGHT 2015   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

#include "BasicMacros.h"
#include "BasicClasses.h"
#include "DataTypes.h"
#include <unordered_map>

#if defined FLEXSIM_ENGINE_COMPILE || defined COMPILING_MODULE_DLL || defined COMPILING_FLEXSIM_CONTENT
#define FULL_TREENODE_DEF
#include "ByteBlock.h"
#endif

#ifdef FLEXSIM_ENGINE_COMPILE
	#include <stack>
	#include <map>
	#include <list>
	#define IN_TREENODE_H
	#include "TreeNodeMacros.h"
	visible int validlink(FlexSim::TreeNode *, const char *);
	#define VALIDLINKFAST(x) (x != nullptr && x!=SAFENODE && testpointer(x,sizeof(TreeNode), nullptr) && x->checkParity())

	#include "Platform.h"
	#include "PageAllocator.h"
#endif

namespace FlexSim {

class engine_export SubnodesArray
{
protected:
	TreeNode* holder = nullptr;
public:
	SubnodesArray(TreeNode* holder = nullptr) : holder(holder) {}
	SubnodesArray(const SubnodesArray& other) : holder(other.holder) {}
	void construct(const SubnodesArray& other) { ::new(this)SubnodesArray(other); }
	SubnodesArray& operator =(const SubnodesArray& other) { holder = other.holder; return *this; }

	int __getLength();
	__declspec(property(get = __getLength)) int length;
	TreeNode* _assert(const char* name);
	TreeNode* _assert(const char* name, const Variant& val) { return _assert(name, val, false); }
	TreeNode* _assert(const char* name, const Variant& val, bool persist);
	void clear();
	TreeNode* operator[](int r);
	TreeNode* operator[](const char* name);
	TreeNode* operator[](const Variant& index);
	TreeNode* add();
	Array toArray();
};

class engine_export LabelsArray
{
private:
	static bool dieHard;
protected:
	TreeNode* holder = nullptr;
public:
	LabelsArray(TreeNode* holder = nullptr) : holder(holder) {}
	LabelsArray(const LabelsArray& other) : holder(other.holder) {}
	void construct(const LabelsArray& other) { ::new(this)LabelsArray(other); }
	LabelsArray& operator =(const LabelsArray& other) { holder = other.holder; return *this; }

	TreeNode* _assert(const char* name);
	TreeNode* _assert(const char* name, const Variant& val);

	TreeNode* operator[](const char* name);
};

class TreeNodeExtraData
{
	friend class TreeNode;
	friend class TreeNodeListHead;
protected:
	~TreeNodeExtraData();
	void* operator new (size_t size);
	void operator delete (void* p);


	CustomDisplayFunction __customDisplayFunction = nullptr;
protected:
	NodeRef * __refsToMe = nullptr;
	TreeNode * __ownerObjectCache = nullptr;

	void removeAllRefs();
};


class TreeNode
{
public:
	// Public interface
	// value
	engine_export Variant __getValue();
	engine_export TreeNode* __setValue(const Variant&);
	Variant __getValueSafe();
	TreeNode* __setValueSafe(const Variant&);
#ifdef FLEXSIM_ENGINE_COMPILE
	__declspec(property(get = __getValueSafe, put = __setValueSafe)) Variant value;
#else
	__declspec(property(get = __getValue, put = __setValue)) Variant value;
#endif

	// name
	engine_export FlexSimPrivateTypes::String __getName();
	engine_export void __setName(const FlexSimPrivateTypes::String&);
	__declspec(property(get = __getName, put = __setName)) FlexSimPrivateTypes::String name;

	// dataType
	engine_export int __getDataType();
	engine_export void __setDataType(int);
	__declspec(property(get = __getDataType, put = __setDataType)) int dataType;

	// rank
	engine_export int __getRank();
	engine_export void __setRank(int);
	__declspec(property(get = __getRank, put = __setRank)) int rank;

	// first
	engine_export TreeNode* __getFirst();
	engine_export void __setFirst(TreeNode*);
	__declspec(property(get = __getFirst, put = __setFirst)) TreeNode* first;

	// last
	engine_export TreeNode* __getLast();
	engine_export void __setLast(TreeNode*);
	__declspec(property(get = __getLast, put = __setLast)) TreeNode* last;

	// up
	engine_export TreeNode* __getUp();
	engine_export void __setUp(TreeNode*);
	__declspec(property(get = __getUp, put = __setUp)) TreeNode* up;

	// prev
	engine_export TreeNode* __getPrev();
	__declspec(property(get = __getPrev)) TreeNode* prev;

	// next
	engine_export TreeNode* __getNext();
	__declspec(property(get = __getNext)) TreeNode* next;

	SubnodesArray __getSubnodes() { return SubnodesArray(this); }
	__declspec(property(get = __getSubnodes)) SubnodesArray subnodes;

	LabelsArray __getLabels() { return LabelsArray(this); }
	__declspec(property(get = __getLabels)) LabelsArray labels;

	engine_export TreeNode* __getOwnerObject();
	__declspec(property(get = __getOwnerObject)) TreeNode* ownerObject;
	engine_export TreeNode* findOwnerObject();
	// evaluate
	engine_export Variant evaluate(const VariantParams& params);
	engine_export Variant evaluate();
	engine_export Variant evaluate(const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant& );
	engine_export Variant evaluate(const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&, const Variant&);


	/// <summary>	Destroys the node. </summary>
	/// <remarks>	If undos are enabled, this will add an undo record. </remarks>
	/// <param name="to">	[in,out] If non-null, to. </param>
	engine_export void destroy();

	/// <summary>	Joins this node with another node using a two-way coupling. </summary>
	/// <remarks>	If undos are enabled, this will add an undo record. </remarks>
	/// <param name="to">	[in,out] If non-null, to. </param>
	engine_export TreeNode* joinTo(TreeNode* to);

	/// <summary>	Points this node to another node using a one-way coupling. </summary>
	/// <remarks>	If undos are enabled, this will add an undo record. </remarks>
	/// <param name="to">	[in,out] If non-null, to. </param>
	engine_export TreeNode* pointTo(TreeNode* to);

	/// <summary>	Breaks off this node's pointer coupling data. </summary>
	/// <remarks>	If it is currently a two-way coupling, both sides of the coupling will be set to point to null.
	/// 			If undos are enabled, this will add an undo record. </remarks>
	/// <param name="to">	[in,out] If non-null, to. </param>
	engine_export TreeNode* breakItOff();

	/// <summary>	Sets the name of the node. </summary>
	/// <remarks>	If undos are enabled, this will add an undo record. </remarks>
	/// <param name="name">	The name. </param>
	engine_export TreeNode* setName(const char* name);
	engine_export const char * getName();

	/// <summary>	Adds data to the node. </summary>
	/// <remarks>	If undos are enabled, this will add an undo record. </remarks>
	/// <param name="type">	The data type. </param>
	/// <returns>	This node, allowing you to chain commands. </returns>
	engine_export TreeNode* addData(int type);

	engine_export TreeNode* find(const char* path);

	engine_export TreeNode* addSimpleData(SimpleDataType* simple, bool bind);
	engine_export TreeNode* addCouplingData(CouplingDataType* cdt, bool bind);

	// object data
	template <class T>
	T* object() const { return (T*)data; }
private:
	engine_export void* __getData();
#ifndef FULL_TREENODE_DEF
	// for normal dll accessors, you should get data with a getter method
	__declspec(property(get = __getData)) void* data;
#else
protected:
	TreeNode ** array;                            // (4 or 8 bytes)
	TreeNodeExtraData* extraData = nullptr;       // (4 or 8 bytes)

	//DATA MEMBERS ARE MANUALLY ALIGNED (NO PADDING)
engine_private:
	unsigned short parity;                        // (2 bytes)
	unsigned short datatype;                      // (2 bytes)
protected:
	unsigned long long flags;                     // (8 bytes)
	ByteBlock m_name;                             // (36 or 40 bytes)
public:
content_private:
	TreeNodeListHead * owner;                             // (4 or 8 bytes)
	TreeNodeListHead * branch;                            // (4 or 8 bytes) 

engine_private:
	union{                                        // (4 or 8 bytes) 
		void * data;
		double* dataasdouble;
		ObjectDataType* dataasobject;
		ByteBlock* dataasbyteblock;
		CouplingDataType* dataascoupling;
		Bundle* dataasbundle;
		SimpleDataType* dataassimple;
	};

public:
	TreeNode() { initialize(); }
	~TreeNode() { cleanup(); }
	engine_export void initialize();
	engine_export int cleanup();
	engine_export double * safedatafloat();
	engine_export ByteBlock * safedatabyteblock();
	engine_export TreeNode * safedatapartner();

	#ifdef COMPILING_FLEXSIM_CONTENT
		// do not use this method. It is for backwards compatibility
		void __addUnknownData(void* theData) { datatype = 0; data = theData; }
	#endif

	public:
		class IteratorElement
		{
		public:
			TreeNode* listHead;
			TreeNode* element;
			int curRank;
			IteratorElement(TreeNode* node, int curRank)
				: listHead((TreeNode*)node->owner == node ? node : (TreeNode*)node->branch),
				curRank(curRank), element(listHead ? listHead->array[curRank] : 0)
			{}
			IteratorElement() : listHead(0), curRank(0), element(0) {}
			IteratorElement(IteratorElement& other) : listHead(other.listHead), curRank(other.curRank), element(other.element) {}
			TreeNode* operator ->() const { return element; }
			TreeNode* operator * () { return element; }
			TreeNode* operator * () const { return element; }
			operator TreeNode*() const { return element; }
			IteratorElement& swap(IteratorElement& other)
			{
				IteratorElement temp = other;
				other = *this;
				*this = temp;
				return *this;
			}
			IteratorElement& operator = (IteratorElement& other)
			{
				if (listHead == other.listHead && curRank) {
					element = other.element;
					listHead->array[curRank] = element;
					element->array = listHead->array + curRank;
				} else {
					listHead = other.listHead;
					curRank = other.curRank;
					element = other.element;
				}
				return *this;
			}
		};

#if defined _DEBUG && FLEXSIM_ENGINE_COMPILE
	// This is a debugging help, so when some execption gets thrown in FlexScript,
	// you can type "TreeNode::s_nodeCallStack" in your watch window, and see the
	// stack of flexscript nodes that have been called. If someday Visual Studio
	// knows how to show the callstack properly from within executing flexscript,
	// we should remove this.
	static std::vector<TreeNode*> s_nodeCallStack;
#endif

#endif // end full treenode def

	engine_export void getPath(char* buffer, TreeNode* relativeTo, int byName);
	std::string getPath(TreeNode* relativeTo = 0, int byName = 1)
	{
		char buffer[4096];
		getPath(buffer, relativeTo, byName);
		return buffer;
	}

	typedef std::basic_string<char32_t> SortablePath;
	static const char32_t SP_VIEW = INT32_MAX;
	static const char32_t SP_MAIN = INT32_MAX - 1;
	static const char32_t SP_SUB_TREE = INT32_MAX - 2;
	static const char32_t SP_OBJ_TREE = INT32_MAX - 3;
	/// <summary>Returns a human-unreadable string describing the rank-based path of the object</summary>
	  /// <remarks></remarks>
	  /// <param name="relativeTo">[in] The desired root node of the path.</param>
	/// <returns></returns>
	SortablePath getSortablePath(TreeNode* relativeTo = 0);
protected:

#ifdef FLEXSIM_ENGINE_COMPILE

#define NULLTERMINATEvoid(note) if (!checkParity() || this==&(failSafeLink)) { diesafely(#note); return; }
#define NULLTERMINATEx(note) if (!checkParity() || this==&(failSafeLink)) return diesafely(#note);
#define NULLTERMINATE(note) if (!checkParity() || this==&(failSafeLink)) {diesafely(#note); return 0;}
#define HEADTERMINATE(note) if (!(flags&FLAG_HASOWNER)) {mpt("LIST HEAD ERROR(");mpt(#note);mpt(")\n"); return 0;}


	friend class TreeNodeListHead;
public:
	static TreeNodeListHead failSafeLink;
	static TreeNodeListHead mainTree;
	static TreeNodeListHead viewTree;
	static TreeNode globalDefQueryNode;
	static double failSafeDouble;
	static ByteBlock failSafeByteBlock;
	static std::stack<int> xmlPointerizationOffsets;
	static std::map<TreeNode*, tinyxml2::XMLElement*, mapcmp> fileMapList;
	static bool licenseHasXMLSaveLoadFeature;

	void* operator new (size_t size);
	void operator delete (void* p);

	static char treeFileLoadVersion;
	static char xmlFileLoadVersion;
	static TreeNode* xmlSaveTopNode;
	static const unsigned long long EXP_MASK = 0x7ff0000000000000;
	static const unsigned long long FRAC_MASK = 0x000fffffffffffff;

	void setDataFloat(double* val);
	void setDataStr(const char* val);
	void setDataVariant(const Variant& val);
	void delData();
	TreeNode* insertInto();
	void destroyBranch();

	static char* globalEncryptionKey;

	// data
public:
	engine_export TreeNode* _parent();
	__declspec(property(get = _parent)) TreeNode* parent;
	CustomDisplayFunction __getCustomDisplayFunction() { return extraData ? extraData->__customDisplayFunction : nullptr; }
	void __setCustomDisplayFunction(CustomDisplayFunction func);
	__declspec(property(get = __getCustomDisplayFunction, put = __setCustomDisplayFunction)) CustomDisplayFunction customDisplayFunction;

	TreeNode* getObjectTree();

	// checking
	inline bool checkParity()
	{
		return parity == (unsigned short)(size_t)this;
	}//true if valid
	TreeWin* treewindow();
	// creation


	TreeNode* insertInto_bareBones();
	// undoable method pointers for insertInto_bareBones
	TreeNode* insertInto_undoable();
	typedef TreeNode* (TreeNode::* InsertIntoCallback)();
	static InsertIntoCallback insertIntoCallback;

	TreeNode* insertInto_bareBones(TreeNode*);

	TreeNodeListHead* insertbranch();
	TreeNodeListHead* assertBranch() { return insertbranch(); }
	int destroyBranch_bareBones();
	// undoable method pointers for destroyBranch_bareBones
	int destroyBranch_undoable();
	typedef int (TreeNode::* DestroyBranchCallback)();
	static DestroyBranchCallback destroyBranchCallback;

	int getlabelsize();
	int setlabelsize(int size);

	int setName_bareBones(const char* newname);
	// undoable method pointers for deleting data
	int setName_undoable(const char*);
	typedef int (TreeNode::* SetNameCallback)(const char*);
	static SetNameCallback setNameCallback;

	int setName_bareBones(const char* buffer, size_t size);

	// undoable method pointers for setting number data
	void setDataFloat_bareBones(double*);
	void setDataFloat_undoable(double*);
	typedef void (TreeNode::* SetDataFloatCallback)(double*);
	static SetDataFloatCallback setDataFloatCallback;

	// undoable method pointers for setting number data
	void setDataVariant_bareBones(const Variant&);
	void setDataVariant_undoable(const Variant&);
	typedef void (TreeNode::* SetDataVariantCallback)(const Variant&);
	static SetDataVariantCallback setDataVariantCallback;

	// undoable method pointers for setting string data
	void setDataStr_bareBones(char*);
	void setDataStr_undoable(char*);
	typedef void (TreeNode::* SetDataStrCallback)(char*);
	static SetDataStrCallback setDataStrCallback;

	void swapData(TreeNode* other, bool swapSubTreeAlso = false);
	void swapSubTree(TreeNode* other);

	void initializeLike(TreeNode* other);

	// access

	inline TreeNode* faststep(size_t i) { return i == 0 ? this : array[i]; }

	TreeNode* step(size_t);
	TreeNode* findByName(const char* name, TreeNode* after = nullptr);
	TreeNode* findByName(const char* name, int nth)
	{
		TreeNode* cur = nullptr;
		for (int i = 0; i < nth; i++) {
			cur = findByName(name, cur);
			if (!cur)
				return nullptr;
		}
		return cur;
	}
	TreeNode* findByNameRecursive(const char* searchname);

	size_t size();
	int fastsize();
	TreeNode* lastitem();


	TreeNode* safefind(const char*);
	TreeNode* F(const char* name) { return safefind(name); }
	TreeNode* safefindrecursive(const char*);
	TreeNode* safestep(size_t);
	TreeNode* S(size_t rank) { return safestep(rank); }
	TreeNode* safenext();
	TreeNodeListHead* safebranch();
	TreeNodeListHead* B() { return safebranch(); }
	NodeRef& safeDataNodeRef();
	NodeRef& SDNR() { return safeDataNodeRef(); }

	TreeNode* diesafely(const char*);
	TreeNode* BS(size_t x) { return ((TreeNode*)safebranch())->safestep(x); }
	TreeNode* BF(const char* x) { return ((TreeNode*)safebranch())->safefind(x); }


	//friend TreeNode * operator/(TreeNode *, char*);
	//friend TreeNode * operator/(TreeNode *, unsigned int);

	size_t position();

protected:
	size_t fastposition() { return array - ((TreeNode*)owner)->array; }
public:

	TreeNode* _up();
	TreeNode* _next();
	TreeNode* _prev();

	int getthepathname(char* buffer);


	// flags

	int toggleexpanded();
	int togglefunction();
	int toggleglobalfunction();
	int toggleflexscript();
	int toggledll();
	int togglehideconnectors();

	/// <summary>	Query if the node has the defined bit flag set. If multiple 
	/// 			bits are defined with a bitwise | operator, it will return true
	/// 			if any one of the bits are high.</summary>
	/// <remarks>	Anthony.johnson, 6/25/2015. </remarks>
	/// <param name="bit">	The bit. </param>
	/// <returns>	true if flag, false if not. </returns>
	bool hasFlag(unsigned long long bit) const { return (flags & bit) != 0; }
	void assertFlag(unsigned long long bit) { flags |= bit; }
	void clearFlag(unsigned long long bit) { flags &= ~bit; }
	int setFlag(unsigned long long bit, bool on) { if (on) assertFlag(bit); else clearFlag(bit); return hasFlag(bit); }
	int toggleFlag(unsigned long long bit) { if (hasFlag(bit)) clearFlag(bit); else assertFlag(bit); return hasFlag(bit); }
	void setFlags(unsigned long long to) { flags = to; }
	unsigned long long getFlags() const { return flags; }
	int ascodecpp();
	int ascodefpp();
	int ascodeglobalcpp();

	// load-save

	static bool didLastLoadHaveCppCode;
	static TreeSaveFlags curSaveFlags;
	template <class BufferAllocator>
	/// <summary>	Saves a tree. </summary>
	/// <remarks>	Allocates the necessary storage buffer and returns that buffer. The caller
	/// 			must take ownership of the returned buffer. </remarks>
	/// <param name="bufferAllocator">	The buffer allocator. Can be a lambda that allocates the storage.</param>
	/// <param name="saveType">		  	Type of the save. </param>
	/// <param name="saveSizeOut">	  	[out] (Optional) If non-null, the resulting save size
	/// 								out. </param>
	/// <returns>	Returns the buffer. </returns>
	char* saveTree(BufferAllocator bufferAllocator, int saveType, size_t* saveSizeOut = 0, TreeSaveFlags flags = None)
	{
		curSaveType = saveType;
		curSaveFlags = flags;
		std::vector<NodeRef> sdtNodeList;
		saveTreePrepare(sdtNodeList);

		size_t bufferSize = estimateSaveSize();
		char* buffer = bufferAllocator(bufferSize);
		size_t saveSize = 0;
		if (buffer)
			saveSize = saveTree(buffer, saveType);

		saveTreeCleanup(sdtNodeList);

		if (saveSizeOut)
			*saveSizeOut = saveSize;

		curSaveType = SAVE_TYPE_MODEL;
		curSaveFlags = None;
		return buffer;
	}

	/// <summary>	Saves a tree. </summary>
	/// <remarks>	Allocates the necessary storage buffer and returns that buffer. The caller
	/// 			takes ownership of the returned buffer. </remarks>
	/// <param name="saveType">   	Type of the save. </param>
	/// <param name="saveSizeOut">	[out] (Optional) If non-null, the resulting save size. </param>
	/// <returns>	null if it fails, else. </returns>
	char* saveTree(int saveType, size_t* saveSizeOut = 0, TreeSaveFlags flags = None)
	{
		return saveTree([](size_t bufferSize) -> char* {return new char[bufferSize]; }, saveType, saveSizeOut, flags);
	}
protected:
	void saveTreePrepare(std::vector<NodeRef>& sdtNodeList);
	void saveTreeCleanup(std::vector<NodeRef>& sdtNodeList);
	size_t saveTree(char* destination, int filetype);

	/* There are two main file versions right now
	version 2 (really 0-2) are used for Flexsim 1-4
	version 3 has been introduced for Flexsim 5.1

	This will include compression and encryption capabilities,
	as well as hopefully embedded media capabilities.
	*/
	bool save(std::ostream& stream);
	bool loadstream_v2(std::istream& stream);
	bool loadStream_v3v4v5(std::istream& stream);
	int save(char*& destination);
	int load_v3v4v5(const char*& source);
	int load_v2(const char*& source);
	typedef int (TreeNode::* LoadCallback)(const char*& source);
	static LoadCallback load;
	typedef bool (TreeNode::* LoadStreamCallback)(std::istream& stream);
	static LoadStreamCallback loadstream;
	int loaddata(const char*& source);
	bool savedata(std::ostream& stream);
	bool loaddata(std::istream& stream);
	int savedata(char*& source);
	/// <summary>	Estimates the save size. </summary>
	/// <remarks>	This will estimate the save size for the tree. It is just that,
	/// 			an estimate. It may not be exact. When it is not exact, it will always
	/// 			over-estimate the size needed so that if you use the return value to 
	/// 			allocate a buffer, the buffer will always be large enough for the save. </remarks>
	/// <param name="savesize">	[out] The save size. </param>
	/// <returns>	. </returns>
	size_t estimateSaveSize();
	void estimateSaveSizeRecursive(size_t& savesize);
	void estimateDataSaveSize(size_t& savesize);
	void estimateListSaveSize(size_t& savesize);
public:
	void addRef(NodeRef* ref);
	bool checkValidRefs() const; // only for debugging purposes
	void removeAllRefs();
	/// <summary>	Nullify all NodeRef references to this node, for undo purposes. </summary>
	/// <remarks>	Anthony.johnson, 3/18/2015. </remarks>
	void nullifyRefs(bool onlyOneWay);
	void restoreRefs();

	bool saveTreeToStream(std::ostream& stream, int filetype);
	bool loadTree(std::istream& stream, int copycache = 0, bool savedInSameProcess = false);
	static std::vector<TreeNode*> saveFailedNodes;
	bool saveTreeToFile(const char* filepath, int filetype = 0, int uncompressed = 0);
	int saveTreeToBinaryFile(const char* filepath, int filetype, int uncompressed = 0);
	bool loadTree(const char* source, int copycache = 0, bool savedInSameProcess = false);

	/// <summary>	Loads a tree from a file. </summary>
	/// <remarks>	Anthony.johnson, 4/26/2017. </remarks>
	/// <param name="filepath">	The filepath. </param>
	/// <returns>	true if it succeeds, false if it fails. </returns>
	bool loadTreeFromFile(const char* filepath);

	void checkAddToSDTNodeList(int bindMode, std::vector<NodeRef>* list = nullptr);
	void bindSDTs(int bindMode, std::vector<NodeRef>& list, bool detachReattach = false);
	static void bindSDTList(int bindMode, bool detachReattach = false);
	static std::vector<TreeNode*> lastLoadPreservedCouplings;
protected:
	void save_populatePointerList();
	void save_resolveCounters();
	static void save_preserveOrphaned(std::vector<NodeRef>& sdtNodeList);
	static void save_removeOrphaned();
	static void save_restorePointedTos();
	static void save_restoreOrphaned();
	static int save_pointedToCounter;

	enum OrphanType {
		Orphaned,
		Preserved
	};
	struct OrphanedCoupling
	{
		TreeNode* couplingNode;
		TreeNodeListHead* originalOwner;
		size_t rank;
		OrphanType orphanType;
	};
public:
	struct CouplingSavePointedToRecord
	{
		unsigned long long serialization = 0;
		TreeNode* to;
		bool hasTwoWayCoupling;
	};
	TreeNodeExtraData* assertExtraData()
	{
		if (!extraData)
			extraData = new TreeNodeExtraData;
		return extraData;
	}
protected:
	static std::vector<OrphanedCoupling> orphanedCouplings;
	static TreeNodeListHead orphanedCouplingOwner;

	static std::vector<NodeRef*> save_pointers;
	typedef std::unordered_map<TreeNode*, CouplingSavePointedToRecord> PointedToMap;
	// the following nodes are for saveing a tree
	static PointedToMap save_pointedTos;

	union PointerizationRecord {
		unsigned long long serialization;
		char* xmlPath;
	};
	static std::unordered_map<NodeRef*, PointerizationRecord> pointerizationMap;
	static std::unordered_map<TreeNode*, TreeNodeListHead*> preservedCouplingMap;
	static std::vector<NodeRef> pointerizationPointedTos;

public:
	static void save_addToPointerList(const NodeRef& ref, TreeNode* from = nullptr);
	static unsigned long long save_getSerialization(const NodeRef& ref);
	static void load_addPointerization(NodeRef& ref, unsigned long long serialization, TreeNode* from = nullptr);
	static void load_addPointerization(NodeRef& ref, std::string& path);
	static int curSaveType;
protected:
	/// <summary>	when pasting/duplicating, if the copy/save was done in the same process, this is
	/// 			a flag to signal that preserved couplings can indeed be preserved. </summary>
	static bool loadBufferSavedInSameProcess;

	static tinyxml2::XMLDocument filemapdoc;

	static int xmlpointerizationcounter;
	void pointerize();
	void pointerizeXML();

public:
	size_t countTotalPopulation();
	// data
	TreeNode* addData_bareBones(int type);
	// undoable method pointers for adding data
	TreeNode* addData_undoable(int type);
	typedef TreeNode* (TreeNode::* AddDataCallback)(int);
	static AddDataCallback addDataCallback;
	TreeNode* addSimpleData_bareBones(SimpleDataType* simple, int bind, int userSDT);
	TreeNode* addSimpleData_undoable(SimpleDataType* simple, int bind, int userSDT);
	TreeNode* addCouplingData_bareBones(CouplingDataType* cdt, int bind, int userSDT);
	TreeNode* addCouplingData_undoable(CouplingDataType* simple, int bind, int userSDT);
	void detachSimpleData();

	int delData_bareBones();
	// undoable method pointers for deleting data
	int delData_undoable();
	typedef int (TreeNode::* DelDataCallback)();
	static DelDataCallback delDataCallback;

	void reownData();

	void disownDouble(double* toDouble);
	void reownDouble();

	void disownCoupling(NodeRef& to);
	void reownCoupling();

	void disownByteBlock(ByteBlock* toData);
	void reownByteBlock();

	void reownSubTreeDataOnDelData();

	int datatostring(char* datastring, size_t maxsize, int precision = -1);
	int stringtodata(char* datastring, int precision = -1);
	int stringtodata(char* datastring, int precision, double rangeMin, double rangeMax);
	int isinobject();

	// data-pointer

	int pointTo_bareBones(TreeNode*);
	// undoable method pointers for joinTo_bareBones
	int pointTo_undoable(TreeNode*);
	typedef int (TreeNode::* PointToCallback)(TreeNode*);
	static PointToCallback pointToCallback;

	int joinTo_bareBones(TreeNode*);
	// undoable method pointers for joinTo_bareBones
	int joinTo_undoable(TreeNode*);
	typedef int (TreeNode::* JoinToCallback)(TreeNode*);
	static JoinToCallback joinToCallback;


	int joinback(TreeNode*);
	int breakfrom(TreeNode* source);

	int breakItOff_bareBones();
	// undoable method pointers for breakItOff_bareBones
	int breakItOff_undoable();
	typedef int (TreeNode::* BreakItOffCallback)();
	static BreakItOffCallback breakItOffCallback;


	// MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
	// beyond here could be part of other objects in a future version
	// MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM


	// class-instance
#define LISTEN_TIME_MASK_PRE_LISTEN 0x1
#define LISTEN_TIME_MASK_LISTEN 0x2
	void notifylisteners(TreeNode* listeners, int listencode, int originalcode, EventDataStruct* data, CallPoint* callpoint, TreeNode* associated, bool requireFlag = false);

	Variant receiveUIMessage(int code, EventDataStruct* data, CallPoint* callpoint, TreeNode* associated, TreeWin* window);
	Variant receivemessage(int code, EventDataStruct* data, CallPoint* callpoint, TreeNode* associated);
	TreeNode* getclassfunctionnode(int code);
	//double executemyownfunction(TreeNode * theclass, TreeNode * theinstance, int code, void * data, char * name, int group, CallPoint * callpoint, TreeNode * associated);
	TreeNode* ihavethefunctionmyself(int code);
	TreeNode* findtheclass(int code, TreeNode**);
	TreeNode* rememberfunctionnode(int code, TreeNode*);
	bool assertDLLBinding(CppCode*& cppCode);
	Variant callMemberFunction(TreeNode* c, TreeNode* i, const VariantParams& params);
	Variant callMemberFunction(FLEXSIMINTERFACE);
	void reportDllConnectionFailure(TreeNode* codeNode);

	// gui

	static int deadlinks;
	static int updatehotlinkscode;
	static bool repaintAfterUpdatingLinks;
	static const int UPDATE_SKIP_NODE = 0x100;
private:
	typedef int (*UpdateHotLinksPredicate)(TreeNode* x);
	int updatehotlinks_private(int apply, int hotlinktype, UpdateHotLinksPredicate traversalPredicate);
public:
	template<class PredType>
	int updatehotlinks(int apply, int hotlinktype, PredType pred) {
		static PredType* predPtr = nullptr;
		auto saved = predPtr;
		predPtr = &pred;
		auto localPred = [](TreeNode* x) {
			return (*predPtr)(x);
		};
		int result = updatehotlinks_private(apply, hotlinktype, (UpdateHotLinksPredicate)localPred);
		predPtr = saved;
		return result;
	}
	int updatehotlinks(int apply, int hotlinktype) { return updatehotlinks_private(apply, hotlinktype, [](TreeNode* x) { return 0; }); }
	int updatehotlinks_refresh(int hotlinktype);
	int updatehotlinks_apply(int hotlinktype);
	TreeNode* locatehotlink(int& type, int byExpr);
	int isnamehotlink(int hotlinktype);
	int resetbuttonstate(int e);

	// view

	int spawnwindow(Window, int, TreeNode*);
	int killwindow();

	int storeallviews();
	int restoreallviews();
	int restoreallviewsA();
	int restoreallviewsB();

	int repaintall();


	// misc recursive

	int shapeautoload(int e);
	int imageautoload(int e);
	int soundautoload(int e);
	int shapeautoloadrecursive(int e);
	int imageautoloadrecursive(int e);
	int soundautoloadrecursive(int e);

	int expandall(int);
	int expandallobjects(int);

	int notifyall(int messagecode);

	// objecttype: 0=viewobject, 1=modelobject
	int objectbindall(int flags);
	int objectbindall_(int flags);

	int select(int state, int options, TreeNode* recordedchanges = NULL);

	//int buildallflexscript();

	bool checkBuildFlexScript();
	void buildAllFlexScript(bool asynchronous = true);
	bool checkCleanFlexScript();
	void cleanAllFlexScript();

	int searchall(char* pattern, double value, int type, unsigned int* n, int doreplace, char* replace, double replacen, double all);

	int statstoselection(int, int);

	static bool isXMLSaveMergeFriendly;
	static bool assertMergeFriendlyPath;
	static void convertToXML(const char* src, std::ostream& doc);
	bool saveTreeToXmlDoc(std::ostream& doc, const char* filepath);
	static void xmlnewline(std::ostream& doc, int indent);
	static void xmlsavedouble(std::ostream& doc, double val);
	int savexml(std::ostream& doc, int depth = 0);
	int savedataxml(std::ostream& doc, int depth = 0);

	class XMLAttList {
	public:
		std::list<std::pair<std::string, std::string>> atts;
		const std::string& getAttribute(const char* name) const;
		bool hasAttribute(const char* name) const;
	};

	static const int XMLOpenTag = 0x1;
	static const int XMLCloseTag = 0x2;
	static const int XMLEndOfFile = 0x0;

	static int parseToNextTag(std::istream& doc, std::string& tagName, XMLAttList* attList = nullptr);
	static std::string parseXMLText(std::istream& doc);
	static double xmlLoadDouble(std::istream& doc);
	int loadTreeXML(std::istream& doc, const char* filepath, int ignorelicense = 0);
	int loadXML(std::istream& doc, const std::string& tagName, const XMLAttList& attritbutes);
	int loadXMLList(std::istream& doc, std::string& tagName, TreeNode::XMLAttList& attributes, bool loadSelf = true);
	int loadDataXML(std::istream& doc);


	static int getSaveFileType(const char* buffera);
	static bool isSaveFileTypeXml(int savetype);

	bool isEqual(TreeNode*, int*);
	void swapODT(ObjectDataType* newodt);

	static int listenermessagecode;
	static TreeNode* listenerassociated;
	static TreeNode* listenercoupling;
	struct ListenerReturnOverride
	{
		TreeNode* listenedNode;
		Variant returnVal;
	};
	static std::vector<ListenerReturnOverride> overriddenListenerReturns;
	void checkOverrideEvaluatedReturnVal(Variant& returnVal);

	static const int STOP_TRAVERSE_OBJ_TREE = 0x1;
	static const int STOP_TRAVERSE_SUB_TREE = 0x2;
	static const int STOP_TRAVERSE = STOP_TRAVERSE_OBJ_TREE | STOP_TRAVERSE_SUB_TREE;
	static const int ABORT_TRAVERSE = 0x4;

	static const int TRAVERSE_BRANCH_BEFORE_OBJECT = 0x1;

	TreeNode* getNextForObjectTreeUnderNode(TreeNode* topNode)
	{
		if (!isValidNode())
			return nullptr;
		if (first->isValidNode())
			return first;
		if (next->isValidNode())
			return next;
		else {
			TreeNode* curNode = this;
			while (curNode != topNode && curNode->up != topNode && !curNode->up->next->isValidNode())
				curNode = curNode->up;
			if (curNode != topNode && curNode->up != topNode && curNode->up->next->isValidNode())
				return curNode->up->next;
			else return nullptr;
		}
		return nullptr;
	}


	/// <summary>	Traverse this node's subtree, calling the callback for al tree. </summary>
	/// <remarks>	Anthony.johnson, 8/11/2016. </remarks>
	/// <param name="func">			  	The callback function. This function should return 0 to continue
	/// 								the traversal, or one of STOP_TRAVERSE_OBJ_TREE, STOP_TRAVERSE_SUB_TREE,
	/// 								STOP_TRAVERSE, or ABORT_TRAVERSE </param>
	/// <param name="includeObjects"> 	(Optional) True if you want to include object attribute trees. </param>
	/// <param name="includeRootNode">	(Optional) True if you want to include the root node. </param>
	/// <param name="includeBranches">	(Optional) True if you want to include branch nodes. </param>
	template <class Func>
	int traverseTree(Func func, bool includeObjects = true, bool includeRootNode = true, bool includeBranches = false, int flags = 0)
	{
		using ODTHelper = FlexSimPrivateTypes::ODTHelper;
		using TreeHelper = FlexSimPrivateTypes::TreeHelper;
		int stopType = 0;
		if (includeRootNode)
			stopType = func(this);

		if (stopType == ABORT_TRAVERSE)
			return ABORT_TRAVERSE;

		if (includeObjects && datatype == DATA_OBJECT && !(stopType & STOP_TRAVERSE_OBJ_TREE) && !(flags & TRAVERSE_BRANCH_BEFORE_OBJECT)) {
			if (ODTHelper::objTree(dataasobject).traverseTree(func, includeObjects, includeBranches, includeBranches) == ABORT_TRAVERSE)
				return ABORT_TRAVERSE;
		}

		if ((TreeNode*)owner == this && TreeHelper::listSize(owner) > 0) {
			TreeNode* curNode = step(1), * nextNode = 0;
			while (curNode) {
				nextNode = curNode->_next();
				if (curNode->traverseTree(func, includeObjects, true, includeBranches, flags) == ABORT_TRAVERSE)
					return ABORT_TRAVERSE;
				curNode = nextNode;
			}
		}

		if (branch && !(stopType & STOP_TRAVERSE_SUB_TREE)) {
			if (((TreeNode*)branch)->traverseTree(func, includeObjects, includeBranches, includeBranches, flags) == ABORT_TRAVERSE)
				return ABORT_TRAVERSE;
		}

		// if the flag says traverse branch before object, then now I should traverse the object
		if (includeObjects && (flags & TRAVERSE_BRANCH_BEFORE_OBJECT) && datatype == DATA_OBJECT && !(stopType & STOP_TRAVERSE_OBJ_TREE)) {
			if (ODTHelper::objTree(dataasobject).traverseTree(func, includeObjects, includeBranches, includeBranches, flags) == ABORT_TRAVERSE)
				return ABORT_TRAVERSE;
		}
		return 0;
	}



	bool contains(TreeNode* descendant);

	void removeDllBoundNode();
	void safelyKillExecutingFlexScript();

	/// <summary>	Query if this object is a valid node. </summary>
	/// <remarks>	validlink() now forwards directly to this method. Note that you can safely call x->isValidNode() with 
	/// 			x being null, and it will safely return false. </remarks>
	/// <returns>	true if valid node, false if not. </returns>
	bool isValidNode();

	char* getMeaningfulPathName();

	TreeNode* assertSubnode(const char* name, int dataType, bool undoable = true);

	/// <summary>	Transfer this node into the new parent. </summary>
	/// <remarks>	Anthony.johnson, 12/14/2016. </remarks>
	/// <param name="newParent">	[in,out] If non-null, the new parent. </param>
	void transferInto(TreeNode* newParent);
	void showCriticalErrorMessage(const char* title, const char* message);
	static bool s_skipPathFlexScriptWildcards;
	TreeNode* getNodeFromPath(const char* path);
	template <class Callback>
	TreeNode* findAncestorIf(Callback callback)
	{
		TreeNode* parent = this->parent;
		while (parent) {
			if (callback(parent))
				return parent;
			parent = parent->parent;
		}
		return nullptr;
	}
	bool isAncestor(TreeNode* child) { return child->findAncestorIf([&](TreeNode* x) {return x == this; }) != nullptr; }

	Variant getLabelProperty(const char* name, unsigned nameHash, bool dieHard);
	void setLabelProperty(const char* name, unsigned nameHash, const Variant& value);

protected:
	template <class LabelDefiner>
	TreeNode* labelGeneric(LabelDefiner labelName, bool assert) 
	{
		using SDTHelper = FlexSimPrivateTypes::SDTHelper;
		if (!isValidNode())
			throw "Attempting to access a label on an object that does not exist.";

		switch (datatype) {
		case DATA_SIMPLE: case DATA_POINTERCOUPLING: case DATA_OBJECT: {
			treenode theLabel = SDTHelper::getLabelNode(dataassimple, labelName, assert);
			if (theLabel)
				return theLabel;
			else return nullptr;
		}
		default: return nullptr;
		}
		return nullptr;
	}
	inline void checkValidityOnPropertyAccess(const char* propertyName);
public:
	TreeNode* label(const char* name, bool assert);
	TreeNode* label(int rank, bool assert);
	std::string __getNameStr();
	void __setNameStr(const std::string& to);
	bool is(const char* className);
	void refreshContentStats();

public:
	static bool bindLocally;

	void clearSubnodes();

	static TreeNode* g_passwordNode;
	static double getPasswordFromUser(TreeNode* destnode);


	TreeNode* __getOwnerView();
	__declspec(property(get = __getOwnerView)) TreeNode* ownerView;

	TreeNode* SF(const char* name) { return safefind(name); }
	double* SDF() { return safedatafloat(); }
	ByteBlock* SDB() { return safedatabyteblock(); }
	TreeNode* SDP() { return safedatapartner(); }

	static void loadDefaultMain();
	static void loadDefaultViews();
	static void loadPrefsTree(bool loadyesno);
	static void savePrefsTree();

	unsigned short getHtmlPathSignature();
	std::string getHtmlID();
	static TreeNode* getNodeFromHtmlID(const char* htmlID);

#endif
};
#pragma pack()

class TreeNodeListHead : public TreeNode
{
	friend class TreeNode;
	friend class FlexSimPrivateTypes;
protected:
	unsigned int __listSize = 0;
	static const int LOCAL_ARRAY_SIZE = 16;
	TreeNode* __localArray[LOCAL_ARRAY_SIZE];
	int __arrayCapacity = LOCAL_ARRAY_SIZE;
	TreeNode** __arrayBase = __localArray;
public:
	int __getArrayCapacity() { return __arrayCapacity; }
	__declspec(property(get = __getArrayCapacity)) int arrayCapacity;
	std::unordered_map<std::string, TreeNode*> * listHash = nullptr;
	TreeNode * __parent = nullptr;

	TreeNodeListHead() {
		owner = this;
		array = __arrayBase;
		array[0] = this;
	}
	engine_export ~TreeNodeListHead();
	void* operator new (size_t size);
	void operator delete (void* p);

	// ------------------------
	// extra
	// ------------------------

	static TreeNode*const LIST_HASH_UNCACHED_VALUE;

	std::unordered_map<std::string, TreeNode*> * & assertListHash();
	std::unordered_map<std::string, TreeNode*> * & refreshListHash();
	// ------------------------
	// extra
	// ------------------------

	void assertListCapacity(int size);


	void clear();
	void remove(TreeNode*);
	void destroy(TreeNode*);
	void swap(size_t index1, size_t index2);
	void insertBlock(int qty);
	TreeNode* add(); // insert_bareBones new treenode at end
	TreeNode* add(TreeNode* newNode); // insert_bareBones at end


	TreeNode* insert(TreeNode* insertAfter);
	TreeNode* insert_bareBones(TreeNode* insertAfter);
	// undoable method pointers for insert_bareBones
	TreeNode* insert_undoable(TreeNode* insertAfter);
	typedef TreeNode* (TreeNodeListHead::*InsertCallback)(TreeNode*);
	static InsertCallback insertCallback;

	TreeNode* insert_bareBones(TreeNode* insertAfter, TreeNode* nodeToInsert);

	bool saveList(std::ostream& stream);
	bool loadList(std::istream& stream);
	int saveList(char*& destination);
	int loadList(const char*& source);
};

}

#ifdef FLEXSIM_ENGINE_COMPILE
	#undef IN_TREENODE_H
#endif

// COPYRIGHT 2015   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

