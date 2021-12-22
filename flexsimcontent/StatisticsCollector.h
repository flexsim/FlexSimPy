#pragma once

#include "DataTypes.h"
#include "ObjectDataType.h"
#include "FlexSimEvent.h"

#ifdef FLEXSIM_ENGINE_COMPILE
#include "Bundle.h"
#endif

#include <functional>
#include <map>

#define DATA_FORMAT_NONE 0
#define DATA_FORMAT_OBJECT 1
#define DATA_FORMAT_TIME 2
#define DATA_FORMAT_PERCENT 3

namespace FlexSim
{

#ifdef FLEXSIM_COMMANDS
visible treenode nodeaddsimpledata(treenode, SimpleDataType*, int);
#endif


#pragma region class SDTMember

template <class SDT>
class SDTMember
{
protected:
	TreeNode* memberNode;

public:
	SDT* operator->() {
		if (memberNode->dataType != DATA_SIMPLE) {
			memberNode->addSimpleData(new SDT, 1);
		}

		return memberNode->objectAs(SDT);
	}

	SDT& operator*() { return *(operator->()); }
	operator SDT*() { return operator->(); }
	operator TreeNode*&() { return memberNode; }
};

template <class CDT>
class CDTMember
{
protected:
	TreeNode* memberNode;

public:
	CDT* operator->() {
		if (memberNode->dataType != DATA_POINTERCOUPLING) {
			memberNode->addCouplingData(new CDT, 1);
		}

		return memberNode->objectAs(CDT);
	}

	CDT& operator*() { return *(operator->()); }
	operator CDT*() { return operator->(); }
	operator TreeNode*&() { return memberNode; }
};

class BundleMember
{
protected:
	TreeNode* memberNode;

public:
	Bundle* operator->() const { return memberNode->objectAs(Bundle); }
	Bundle& operator*() const { return *(operator->()); }
	operator Bundle*() const { return operator->(); }
	operator TreeNode*&() { return memberNode; }
};

#pragma endregion

#pragma region IDService
class IDServiceCore : public SimpleDataType
{
protected:
	typedef std::unordered_map<TreeNode*, std::pair<NodeRef, double>> IDMap;
	IDMap itemMap;
	double itemID = 1;
	IDMap::iterator itemMapEnd = itemMap.end();

public:
	class IDInfo : public CouplingDataType
	{
	public:
		// holder->partner() stores the reference to the object
		// holder's name stores the path
		double hash;
		ByteBlock path;

		virtual void bind() override
		{
			__super::bind();
			bindDouble(hash, true);
			bindByteBlock(path, true);
		}
		virtual const char* getClassFactory() override { return "IDServiceCoreIDInfo"; }
	};
protected:
	NodeListArray<IDInfo>::CouplingSdtSubNodeBindingType idInfoObjects;
	bool mapsBuilt = false;
	std::unordered_map<TreeNode*, IDInfo*> nodeIDMap;
	std::unordered_map<unsigned int, IDInfo*> idPathMap;

	std::unordered_map<TreeNode*, IDInfo*>::iterator nodeIDMapEnd = nodeIDMap.end();
	std::unordered_map<unsigned int, IDInfo*>::iterator idPathMapEnd = idPathMap.end();

	std::string getObjectHashPath(TreeNode* object);
	unsigned int hashPath(const char* path, size_t length);
	void buildIDInfoMaps();

	double getObjectID(TreeNode* object);
	double getItemID(TreeNode* item);

public:
	// The model IDService should not keep dead IDs.
	// The experimenter IDService, on the other hand, should,
	// because a replication might have created an object that
	// doesn't exist in the original.
	double keepDeadIDs = 0;

	void onReset();
	double getID(TreeNode* object);

	int isValueID(double id);
	TreeNode* getObjectFromID(double id);
	const char* getPathFromID(double id, const unsigned int maxDepth);
	int doesNodeHaveID(TreeNode* object);
	void setNodeID(TreeNode* object, double id);

	void mergeWith(IDServiceCore* other);
	Map getIdPathMap();

	void clear();

	virtual void bind() override;
	virtual const char* getClassFactory() override { return "IDServiceCore"; }
};

class IDService : public ObjectDataType
{
protected:
	static ObjRef<IDService> idService;
	static IDService& getIDService();

	ObjRef<IDServiceCore> __idServiceCore;
	TreeNode* __idServiceCoreNode;
	IDServiceCore& __getIDServiceCore();
	__declspec(property(get = __getIDServiceCore)) IDServiceCore& idServiceCore;

	Map temporaryIDs; // not bound

public:
	double saved = 0;
	engine_export void onReset();

	engine_export static double getID(TreeNode* object);

	engine_export static int isValueID(double id);
	engine_export static TreeNode* getObjectFromID(double id);
	engine_export static const char* getPathFromID(double id, int maxDepth);
	engine_export static int doesNodeHaveID(TreeNode* object);
	engine_export static void setNodeID(TreeNode* object, double id);
	
	engine_export static Array getIDsAndPathsInBundle(TreeNode* bundleNode, const Variant& columns, int startEntry, int maxDepth);

	engine_export static void clear();
	engine_export Map getIdPathMap();
	engine_export void setTemporaryIDs(Map ids);

	engine_export virtual void bindVariables() override;
	
	static IDService* create(TreeNode* parent);
};
#pragma endregion (classes IDService, IDServiceCore)

// This interface makes it easier to deal with the fact that both
// the statistics collector and the calculated table specify column
// formats (DATA_FORMAT_*)
class StatisticsCollector;
class CalculatedTable;
class engine_export ColumnFormatter
{
public:
	virtual int getColumnFormat(int colNr) = 0;
	virtual Array getColumnFormats() = 0;
	virtual TreeNode* getBundleNode() = 0;
	virtual int getObjectFormatMaxDepth() { return 0; };
	virtual void prepareToRead() {};
	void transferDataTo(TreeNode* target);

	static bool inheritsColumnFormatter(TreeNode* object);
	static ColumnFormatter* toColumnFormatter(TreeNode* object);
};

class StatisticsCollector : public ObjectDataType, public ColumnFormatter
{
protected:
	// The purpose of the KeySafeVariant is to make a value
	// that is safe to use as a key for an unordered map.
	// A regular variant can be or contain noderef values,
	// which can change at any time to 0. So here I keep a list
	// of the original TreeNode* and noderefs to those values.
	// If the pointer and noderef don't match, then the
	// treenode address has been reused by the treenode allocator.
	struct KeySafeVariant
	{
		Variant original;
		struct AddrRef
		{
			TreeNode* addr;
			NodeRef ref;
		};
		std::vector<AddrRef> addrRefs;
		size_t hash;
		
		KeySafeVariant(const Variant& value);
		bool isValid() const;
		
		static const size_t invalid = -1;
		
		struct Hash
		{
			size_t operator()(const KeySafeVariant& ksv) const {
				return ksv.hash;
			}
		};

		struct Comp
		{
			bool operator()(const KeySafeVariant& ksv1, const KeySafeVariant& ksv2) const;
		};
	};

public:
	class CollectedDataRow : public SimpleDataType
	{
	public:
		TreeNode* labels;
		Variant getProperty(const char* name, unsigned nameHash, bool dieHard);
		void setProperty(const char* name, unsigned nameHash, const Variant& value);

		virtual TreeNode* getLabelNode(const char* labelName, bool assert) override;
		virtual TreeNode* getLabelNode(int labelRank, bool assert) override;

		LabelsArray getLabelsArray();

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorCollectedDataRow"; }
		virtual void bindInterface() override;
	};

protected:
	typedef std::map<std::string, Variant> PropertyMap;
	class CollectedData
	{
	public:
		StatisticsCollector* collector = nullptr;

		// These are set in the event phase
		Group* group = nullptr;
		TreeNode* eventNode = nullptr;
		ObjectDataType* processFlowInstance = nullptr;
		std::string eventName;
		Array linkedColumns;

		bool dataAvailable = false;
		bool rowValueAvailable = false;
		bool rowDataAvailable = false;

		// The row function iterates through all rows, setting the row object and number
		Variant rowValue;
		int rowNum;
		int rowValueIndex;

		CollectedDataRow* row;

		bool colDataAvailable = false;
		// Then the row function iterates through all columns, setting the col number
		Variant colValue;
		int colNum;
		int colValueIndex;

		// Any additional properties are stored here
		PropertyMap properties;

		// This method allows the user to create an enumerated row
		double enumerate() { return enumerate(eventNode, processFlowInstance, group); }
		double enumerate(TreeNode* eventNode, ObjectDataType* instance, Group* group);

		// This is called after every event is handled
		void clear();

		CollectedData() {}
		CollectedData(StatisticsCollector* collector) : collector(collector) {}
	};

	class CollectedDataInterface
	{
	protected:
		CollectedData* data = nullptr;
	public:
		CollectedDataInterface(CollectedData* data) : data(data) {}
		void construct(const CollectedDataInterface& other) { data = other.data; }
		CollectedDataInterface& operator =(const CollectedDataInterface& other) { data = other.data; return *this; }

		Group* __getGroup();
		TreeNode* __getEventNode();
		ObjectDataType* __getProcessFlowInstance();
		std::string __getEventName();
		Array __getLinkedColumns();
		Variant __getRowValue();
		int __getRowNumber();
		int __getRowValueIndex();
		Variant __getColValue();
		int __getColNumber();
		int __getColValueIndex();

		Variant __getCurrentValue();

		CollectedDataRow* __getRow();

		__declspec(property(get = __getGroup)) Group* group;
		__declspec(property(get = __getEventNode)) TreeNode* eventNode;
		__declspec(property(get = __getProcessFlowInstance)) ObjectDataType* processFlowInstance;
		__declspec(property(get = __getEventName)) std::string eventName;
		__declspec(property(get = __getLinkedColumns)) Array linkedColumns;
		__declspec(property(get = __getRowObject)) Variant rowObject;
		__declspec(property(get = __getRowNumber)) int rowNumber;
		__declspec(property(get = __getRowValueIndex)) int rowValueIndex;
		__declspec(property(get = __getColValue)) Variant colValue;
		__declspec(property(get = __getColNumber)) int colNumber;
		__declspec(property(get = __getColValueIndex)) int colValueIndex;
		__declspec(property(get = __getCurrentValue)) Variant currentValue;

		Variant getProperty(const char* name, unsigned nameHash, bool dieHard);
		void setProperty(const char* name, unsigned nameHash, const Variant& value);

		double enumerate();
		double enumerate(TreeNode* eventNode, ObjectDataType* instance, Group* group);

		static void bindInterface();
	};

	CollectedData __collectedData = CollectedData(this);

public:
	struct RowData
	{
		int rowNum;
		ObjRef<CollectedDataRow> row;
	};

	class VariantMapBinder : public SimpleDataType
	{
	public:
		typedef std::unordered_map<KeySafeVariant, RowData, KeySafeVariant::Hash, KeySafeVariant::Comp> KeySafeMap;
		KeySafeMap map;
		KeySafeMap::iterator mapEnd = map.end();
		void clear() { map.clear(); }
		virtual void bind()	override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorVariantMapBinder"; }
	};


protected:
	friend class StatisticsCollectorRowValuesView;
	SDTMember<VariantMapBinder> rowValueMap;

	int addNewRow();
	double willSort = 0;
	
	// This vector keeps a list of all rows that can be reused
	std::vector<int> reusableRows;
	TreeNode* _reusableRowsNode;
	double willReuseUntrackedRows = 0;

public:
	class EventReference;
	class ColumnSet;
	class Column : public SimpleDataType
	{
	public:
		enum ValueApplicationMode {
			ByEvent = 1,
			Always,
		};

		double bundleFieldType = 1;
		double bundleIndexType = 0;
		double valueFormat = DATA_FORMAT_NONE;
		TreeNode* valueNode;
		TreeNode* initialValueNode;
		Variant columnValue;
		double columnValueIndex = 0;
		ObjRef<Column> definition = nullptr;

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorColumn"; }

		StatisticsCollector* __getCollector();
		__declspec(property(get = __getCollector)) StatisticsCollector* collector;

		double valueApplicationMode = (double)ByEvent;
		double updatedByEvent = 0;
		
		Variant getValue() { return valueNode->evaluate(); }
		Variant getInitialValue() { return initialValueNode->evaluate(); }
		int getBundleFieldType() { return (int)bundleFieldType;	};
		int getBundleIndexType() { return (int)bundleIndexType; }

		int getColumnFormat() { return (int)valueFormat; }
		bool isDynamic() { return valueApplicationMode == (double)Always; }

		virtual bool isClassType(const char* className) override {
			return strcmp(className, "StatisticsCollectorColumn") == 0;
		}

		static void eventAdder(TreeNode* x, EventReference* event);
		static void liveEventAdder(TreeNode* x, EventReference* event);
		static EventReference* eventGetter(TreeNode* x);
		NodeListArray<EventReference, eventAdder, eventGetter, 0> events;
		NodeListArray<EventReference, liveEventAdder, eventGetter, 0> liveEvents;

		virtual ColumnSet* toColumnSet() { return nullptr; }

		engine_export Variant isColumnSet(FLEXSIMINTERFACE) { 
			return toColumnSet() != nullptr; 
		}
	};

	class ColumnSet : public Column
	{
	public:
		TreeNode* setValue;

		virtual bool isClassType(const char* className) override {
			return strcmp(className, "StatisticsCollectorColumnSet") == 0;
		}

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorColumnSet"; }
		virtual ColumnSet* toColumnSet() override { return this; }
	};

	class EventParamProperty : public SimpleDataType
	{
	public:
		double enabled;
		ByteBlock paramName;
		double paramNumber;

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorEventParamProperty"; }
	};

	class CollectedDataProperty : public SimpleDataType
	{
	public:
		TreeNode* propertyValue;

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorCollectedDataProperty"; }
	};
	
	// This class represents the interface into OnEventOccurred in the StatisticsCollector
	// The listener classes should all have one of these (usually)
	class EventOccurredInfo : public SimpleDataType
	{
	public:
		NodeRef eventObject;
		ByteBlock eventName;
		ObjRef<Group> group;
		NodeRef instanceObject;
		NodeListArray<EventParamProperty>::ObjPtrType eventProperties;
		NodeRef condition;
		NodeListArray<CollectedDataProperty>::ObjPtrType collectedProperties;
		NodeRef rowValue;
		double stopTrackingRowValue = 0.0;
		NodeListArray<Column>::ObjPtrType columns;
		Variant columnIndices;
		double flags = 0;

		TreeNode* savedProperties;

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorEventOccurredInfo"; }
	};

	class TimerEventReference;
	class TransientEventReference;
	class EnumerateEventReference;
	class EventReference : public SimpleDataType
	{
	public:
		NodeRef object;
		ByteBlock eventName;

		double changeRule = 0;
		TreeNode* changeValue;

		double searchForObjects = 0;
		TreeNode* searchRequirements;

		// The view fills in this list using enumerateEvents
		TreeNode* eventList;
		NodeListArray<EventParamProperty>::SdtSubNodeBindingType eventProperties;
		NodeListArray<CollectedDataProperty>::SdtSubNodeBindingType collectedProperties;

		TreeNode* condition;
		TreeNode* rowValue;
		double stopTrackingRowValue = 0;

		enum ColumnSelectMode { ByLinks = 0, ByCode };

		double columnSelectMode = (double)ByLinks;
		TreeNode* selectColumnsCallback;

		static void columnAdder(TreeNode* x, Column* column);
		static Column* columnGetter(TreeNode* x);
		NodeListArray<Column, columnAdder, columnGetter, 0> columns;
		NodeListArray<Column, columnAdder, columnGetter, 0> liveColumns;

		virtual Variant getRowValue() {
			return rowValue->evaluate();
		}
		
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorEventReference"; }
		virtual bool isClassType(const char* className) override {
			return strcmp(className, "StatisticsCollectorEventReference") == 0;
		}

		virtual const char* getType();
		virtual TimerEventReference* toTimerEventReference() { return nullptr; }
		virtual TransientEventReference* toTransientEventReference() { return nullptr; }
		virtual EnumerateEventReference* toEnumerateEventReference() { return nullptr; }

		static void updateEventListInternal(TreeNode* object, TreeNode* listNode);
		void updateEventList(TreeNode* object);
		void updateTransientEventList(TreeNode* object);
		void selectEvent(const char* eventName);
		void selectTransientEvent(const char* eventName);
		bool isTrackedVariableEvent();
		bool isTransientTrackedVariableEvent();

		Variant getType(FLEXSIMINTERFACE);
		Variant updateEventList(FLEXSIMINTERFACE);
		Variant updateTransientEventList(FLEXSIMINTERFACE);
		Variant selectEvent(FLEXSIMINTERFACE);
		Variant selectTransientEvent(FLEXSIMINTERFACE);
		Variant isTrackedVariableEvent(FLEXSIMINTERFACE);
		Variant isTransientTrackedVariableEvent(FLEXSIMINTERFACE);
	};

	class TransientEventReference : public EventReference
	{
	public:
		// Most of the inherited fields specify the existing event
		// These additional fields specify information about the transient event
		TreeNode* transientObjectsCallback;
		ByteBlock transientEventName;
		TreeNode* transientEventList; // The view fills in this list
		double transientChangeRule = 0;
		TreeNode* transientChangeValue;
		TreeNode* transientCondition;

		NodeListArray<EventParamProperty>::SdtSubNodeBindingType transientEventProperties;

		virtual const char* getType() override;
		virtual TransientEventReference* toTransientEventReference() override { return this; }
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorTransientEventReference"; }
		virtual bool isClassType(const char* className) override {
			return strcmp(className, "StatisticsCollectorTransientEventReference") == 0;
		}
	};

	class EventReferenceListener : public FlexSimEvent
	{
	public:
		SDTMember<EventOccurredInfo> info;

		virtual void execute() override;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorEventReferenceListener"; }

		// for listening to ProcessFlow instances
		Variant getEventTitle(FLEXSIMINTERFACE) override;
		Variant setInstanceObject(FLEXSIMINTERFACE);
	};

	class TransientEventReferenceListener : public FlexSimEvent
	{
	public:
		// This function creates a listener on the transient object
		NodeRef eventObject;
		NodeRef instanceObject;
		double flags;
		ObjRef<TransientEventReference> linkedEventReference;

		virtual void execute() override;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorTransientEventReferenceListener"; }

		// for listening to ProcessFlow instances
		Variant getEventTitle(FLEXSIMINTERFACE) override;
		Variant setInstanceObject(FLEXSIMINTERFACE);
	};

	class TimerEventReference : public EventReference
	{
	public:
		TreeNode* offsetTime;
		double repeatSchedule = 0;
		TreeNode* repeatInterval;

		// The schedule should be a table
		// First column - time to fire
		// Additional columns - data to collect
		TreeNode* schedule;

		double cachedOffsetTime = 0;
		double cachedRepeat = 0;
		double cachedInterval = 0;
		Variant cachedSchedule = 0;
		SDTMember<EventOccurredInfo> info;

		enum ExecuteMode
		{
			Execute = 0x1,
			Repeat = 0x2,
			Schedule = 0x4,
		};

		void cacheResetData();
		void generateTimerEvent(StatisticsCollector* collector, double atTime, int executeMode);
		void generateSchedule(StatisticsCollector* collector, double atTime);

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorTimerEventReference"; }

		virtual const char* getType() override { return "Timer"; }

		virtual TimerEventReference* toTimerEventReference() override { return this; }
	};

	class TimerEventReferenceListener : public FlexSimEvent
	{
	public:
		ObjRef<TimerEventReference> linkedEventReference;
		double executeMode = 0;
		

		virtual void execute() override;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorTimerEventReferenceListener"; }
	};

	class TrackedVariableEventReferenceListener : public ValueChangeListener
	{
	public:
		SDTMember<EventOccurredInfo> info;

		virtual void onChangeRuleMet(const Variant& newValue, const Variant& oldValue) override;

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorTrackedVariableEventReferenceListener"; }

		// for listening to ProcessFlow instances
		Variant getEventTitle(FLEXSIMINTERFACE) override;
		Variant setInstanceObject(FLEXSIMINTERFACE);
	};

	class EnumerateEventReference : public EventReference
	{
	public:
		// This class is not bound. It is only created (and destroyed)
		// during the createEvents() method of the stats collector.
		class EnumerateHelper : public SimpleDataType
		{
		public:
			ObjRef<StatisticsCollector> collector;
			NodeRef objects;
			Variant evaluate(const VariantParams& params) override;
			EnumerateHelper(StatisticsCollector* collector, TreeNode* objects) 
				: collector(collector), objects(objects) {}
		};

		static const double ENUM_ID_MAX;
		TreeNode* objects;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "StatisticsCollectorEnumerateEventReference"; }
		virtual const char* getType() override { return "Enumerate"; }

		virtual EnumerateEventReference* toEnumerateEventReference() override {
			return this;
		}

		Variant addObject(FLEXSIMINTERFACE);
	};

	class QuerySource : public SqlDataSource
	{
	protected:
#ifdef FLEXSIM_ENGINE_COMPILE
		struct IterInfo
		{
			double changeCount = 0;
			bool isPopulated = false;
			int compareType = -1;
			Variant value = Variant();
			BundleIndex::Range range;
			BundleIndex::Iterator iter;
		};
#else
		struct IterInfo {};
#endif
	public:

		std::map<int, IterInfo> colIDIterInfoMap;
		
		virtual int getColID(int tableId, const char* colName, int& colFlags) override;
		virtual const char* enumerateColNames(int tableId, int colNum) override;
		virtual Variant getValue(int tableId, int row, int colId) override;
		// I don't need to set the value; collector tables are read-only for queries
		// I don't need to worry about table ID either

		virtual bool initIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) override;
		virtual bool advanceIndexedCursor(int tableID, int colID, const Variant& value, int compareType, SqlCursor& cursor) override;

		virtual int getRowCount(int tableID) override;
		NodeRef collectorLink;
		StatisticsCollector* __getCollector();
		__declspec(property(get = __getCollector)) StatisticsCollector* collector;
		QuerySource(StatisticsCollector* collector);
	};

	class DataSource : public Table::TableDataSource
	{
	protected:
		NodeRef collectorLink;
		StatisticsCollector* __getCollector() const;
		__declspec(property(get = __getCollector)) StatisticsCollector* curCollector;
		void throwError(std::string message) { throw message + " (for " + curCollector->holder->name + ")"; }
	public:
		DataSource(StatisticsCollector* curCollector);
		bool isValid() { return (bool)curCollector; }

		virtual int getConstraints() const override { return READ_ONLY | BUNDLE_TYPES_ONLY; }
		engine_export virtual int __numRows() const override;
		engine_export virtual int __numCols() const override;

		virtual std::string __name() const override;

		virtual void addCol(int, int) override { throwError("Error: cannot add columns"); }
		virtual void addRow(int, int) override { throwError("Error: cannot add rows"); }
		virtual TreeNode* cell(const Variant&, const Variant&) override { throwError("Error: cannot get cell"); throw; }
		virtual void clear(int) override { throwError("Error: cannot clear table"); }
		virtual void deleteCol(int) override { throwError("Error: cannot delete column"); }
		virtual void deleteRow(int) override { throwError("Error: cannot delete row"); }
		// executeCell is okay
		virtual std::string getColHeader(int colNum) override;
		// getRowHeader is okay
		virtual void moveCol(int, int) override { throwError("Error: cannnot move column"); }
		virtual void moveRow(int, int) override { throwError("Error: cannnot move row"); }
		virtual void setColHeader(int, const char*) override { throwError("Error: cannnot set column header"); }
		virtual void setRowHeader(int, const char*) override { throwError("Error: cannnot set row header"); }
		virtual void setSize(int, int, int, int) override { throwError("Error: cannnot set size"); }
		virtual void sort(const Variant&, const Variant&) override { throwError("Error: cannnot sort"); }
		virtual void swapCols(int, int) override { throwError("Error: swap columns"); }
		virtual void swapRows(int, int) override { throwError("Error: swap rows"); }

		engine_export virtual Variant getValue(int row, int col) override;
		virtual void setValue(int row, int col, const Variant& val) override { throwError("Error: cannnot set value"); }
	};

	std::shared_ptr<Table::TableDataSource> getTableDataSource();
protected:
	std::shared_ptr<Table::TableDataSource> dataSource;

protected:
	NodeListArray<CollectedDataProperty>::SdtSubNodeBindingType sharedProperties;
	static bool checkNodeForSDTType(TreeNode* obj, const char* classType);

public:
	double enabled = 1;
	enum WarmupMode { ClearRows = 0x0, DoNothing = 0x1, ResetValues = 0x2, RemoveUntrackedRows = 0x4 };
	double ignoreWarmup = 0;
	double inErrorState = 0;
	double changeCount;
	double saved = 0;
	double storeDataOnDrive = 0;
	double reuseUntrackedRows = 0;
	double keepLabelsForFinishedRows = 0;

	TreeNode* sharedCondition;
	
	TreeNode* rowSortInfo;
	
	NodeRef instanceObject;
	double objectFormatMaxDepth = 0;

	double lastUpdateTime = 0;
	double updateSinceReset = 0;
	NodeRef lastUpdateEvent;

	NodeListArray<EventReference>::SdtSubNodeBindingType eventReferences;
	NodeListArray<Column>::SdtSubNodeBindingType columns;
	NodeListArray<Column>::SdtSubNodeBindingType liveColumns;
	NodeListArray<Column>::ObjPtrType dynamicColumns;
	NodeListArray<Column>::ObjPtrType staticColumns;

	
	NodeListArray<FlexSimEvent>::CouplingSdtPtrType liveListeners;

	BundleMember data;
	TreeNode* rowScores;
	NodeListArray<CollectedDataRow>::SdtSubNodeBindingType rowDatas;

	TreeNode* enumeratedRows;
	
protected:
	bool enumerationMapDirty = true;
	void buildEnumerationMap();
	std::unordered_map<double, TreeNode*> enumerationMap;
	double getEnumerationID(TreeNode* eventNode, ObjectDataType* instance, Group* group);
	double enumerate(TreeNode* eventNode, ObjectDataType* instance, Group* group);
	void checkApplyEnumerationData();
public:

	engine_export TreeNode* addEventReference();
	engine_export TreeNode* addTimerEventReference();
	engine_export TreeNode* addTransientEventReference();
	engine_export TreeNode* addEnumerateEventReference();
	engine_export const char* getEventReferenceType(TreeNode* eventReference);
	engine_export TreeNode* assertEventReferenceParam(TreeNode* eventReference, int paramNum);
	engine_export TreeNode* addPropertyToEventReference(TreeNode* eventReference);
	engine_export TreeNode* addSharedProperty();
	engine_export TreeNode* addRowSortInfo();
	engine_export void updateEventList(TreeNode* object, TreeNode* list);

	LabelsArray getLabelsArray();

protected:
	void addColumnInternal(Column* newColumn, std::string prefix);
public:
	engine_export TreeNode* addColumn();
	engine_export TreeNode* addColumnSet();

private:
	bool hasColumnSets();
	TreeNode* getColumnCache(bool assert);
public:
	int getNumColumns();
	Variant getColName(int colNum);
	Column* getColumn(int colNum);
	
	engine_export void linkColumnAndEvent(TreeNode* column, TreeNode* eventRef);
	engine_export void unlinkColumnAndEvent(TreeNode* column, TreeNode* eventRef);
	engine_export void unlinkAllEvents(TreeNode* column);
	engine_export void unlinkAllColumns(TreeNode* eventRef);

	engine_export Array getEventsForColumn(TreeNode* column);

	void onEventOccurred(EventOccurredInfo& info, CallPoint* listenerCP);
	void onPreTransientEvent(TransientEventReference* eventReference, TreeNode* eventObject, TreeNode* instanceObject, double flags, CallPoint* listenerCP);
	void updateAllRows(std::vector<Column*>& columnsToUpdate, const char* eventName, bool doEvent);

	engine_export void update();

	engine_export Array getUniquePropertyNames();

	engine_export CollectedDataInterface __getCollectedData() { return CollectedDataInterface(&__collectedData); }
	__declspec(property (get = __getCollectedData)) CollectedDataInterface collectedData;

	engine_export TreeNode* __getData() { return data; }

	engine_export TreeNode* __getInstanceObject() { return instanceObject; }
	engine_export void __setInstanceObject(TreeNode* obj) { instanceObject = obj; }

	engine_export int getRowForValue(const Variant& value);
	engine_export Variant getValue(int row, int col, int skipUpdate = 0);
	engine_export Array getAllRowValues();

	engine_export operator Table();
	engine_export operator TreeNode*() { return holder; }

	// These methods allow access to some column metadata
	engine_export int getColumnFormat(int columnNr) override;
	engine_export Array getColumnFormats() override;
	engine_export TreeNode* getBundleNode() override;
	engine_export int getObjectFormatMaxDepth() override;
	engine_export void prepareToRead() override;

	engine_export Array getColumnInfo();

	engine_export static StatisticsCollector* createGlobal();
	engine_export static StatisticsCollector* getGlobal(const Variant& id);

	engine_export void onReset();
	engine_export void onPostReset();
	engine_export void applySettings();
	void onConfigure();
	void clearCollector();
	void setResetValues();
	void createLiveComponents();
	void createColumns();
	void createListeners();
	void setInfoColumns(EventOccurredInfo* info, EventReference* linkedEvent, TreeNode* eventObject, const char* eventName);
	void setInfo(EventOccurredInfo* info, EventReference* linkedEvent, TreeNode* eventObject, const char* eventName, TreeNode* instanceObject, int flags);
	void setTransientInfo(EventOccurredInfo* info, TransientEventReference* linkedEvent, TreeNode* eventObject, const char* eventName, int flags);
	void listenToEventNode(EventReference* ref, TreeNode* eventNode, TreeNode* eventObject, const char* eventName, TreeNode* instanceObject, int flags);
	void listenToTransientEventNode(TransientEventReference *ref, TreeNode* eventNode, TreeNode* eventObject, const char* eventName, int flags, const PropertyMap& cachedProperties);
	void createEvents();
	engine_export void onRunWarm();
	// double onStartSimulation() override;

	// Events
protected:
	TreeNode* onRowAdded = nullptr;
	TreeNode* onRowUpdated = nullptr;
	TreeNode* onRowFinished = nullptr;

	TreeNode* onRowAdding = nullptr;
	TreeNode* onRowUpdating = nullptr;

	Array columnsUpdated;
	Array previousValues;
public:

	// getEventInfo
	engine_export virtual TreeNode* getEventInfoObject(const char* eventTitle) override;

	// Bind
	engine_export virtual void bindEvents() override;
	engine_export virtual void bindVariables() override;
	engine_export virtual void bindInterface() override;

	// ID Service functions
	engine_export static double getID(TreeNode* object) { return IDService::getID(object); }

	engine_export static int isValueID(double id) { return IDService::isValueID(id); }
	engine_export static TreeNode* getObjectFromID(double id) { return IDService::getObjectFromID(id); }
	engine_export static const char* getPathFromID(double id, int maxDepth = 0) { 
		return IDService::getPathFromID(id, maxDepth);
	}
	engine_export static int doesNodeHaveID(TreeNode* object) { return IDService::doesNodeHaveID(object); }
	engine_export static void setNodeID(TreeNode* object, double id) { IDService::setNodeID(object, id); }

	engine_export static void clearIDs() { IDService::clear(); }

	engine_export Variant getDBExportColumnExpression(const char* colName, int dbDataType);

	engine_export bool isSuitableForLiveUpdates();

	Variant getProperty(const char* name, unsigned nameHash, int dieHard);
	void setProperty(const char* name, unsigned nameHash, const Variant& value);

	virtual StatisticsCollector* toStatisticsCollector() { return this; }
};

}