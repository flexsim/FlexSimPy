#pragma once

#include "BasicClasses.h"
#include "ObjectDataType.h"
#include "CouplingDataType.h"
#include "ByteBlock.h"
#include "FlexSimEvent.h"
#include "Group.h"

#include <unordered_map>

#if defined FLEXSIM_ENGINE_COMPILE
#include "Locator.h"
#endif

namespace FlexSim
{
class List : public ObjectDataType
{
	friend SimpleDataType* engine_createsdtderivative(char* classname, TreeNode* holder);
public:
	int repaintMatchId = 0;
	// flags for pulling
	static const int ALLOCATE_ALL_OR_NOTHING = 0x1;
	static const int PARSE_QUERY = 0x2;
	static const int PULL_ENTRY_NODES = 0x4;
	static const int DO_NOT_REMOVE = 0x8;
	static const int DO_NOT_BACK_ORDER = 0x10;
	static const int PULL_BACK_ORDERS = 0x20;
	static const int DO_NOT_FULFILL = 0x40;
	static const int RETURN_BACK_ORDER_IF_NOT_FULFILL = 0x80;

	static const int COL_ID_VALUE = INT_MAX - 1;
	static const int COL_ID_PULLER = INT_MAX - 2;
	static const int COL_ID_REQUESTED = INT_MAX - 3;
	static const int COL_ID_REQUIRED = INT_MAX - 4;
	List() : defaultDataSource(0), backOrderQueueStrategyDataSource(0), defaultBackOrderDataSource(0) {}

	class Entry : public CouplingDataType
	{
		friend class List;
		friend class ListViewDataSource;
	public:
		Entry(size_t numFields, const Variant& value);
		Entry() {}
		bool getEntryNodes = false;
	private:
		virtual const char* getClassFactory() override { return "ListEntry"; }
		virtual void bind() override;
		std::vector<Variant> staticFields;
		double pushTime;
		Variant value;
		bool hasListeners = false;
		const Variant* puller = nullptr;
		TreeNode* onPull = nullptr;
		bool isIneligibleForPull = false;
		virtual void bindEvents() override;

		Variant __getValue() { return value; }
		void remove() { List::remove(holder); };
		engine_export virtual void bindInterface() override;
	};

	class LabelField;
	class GroupField;
	class Field : public SimpleDataType
	{
		friend class List;
		friend class FlexSim::ListViewDataSource;
	public:
		engine_export virtual void bind() override;
		engine_export virtual void bindStatistics() override;
		engine_export void bindEvents() override { bindStatisticsAsEvents(); }
		engine_export virtual void reset(List* list);
		double isDynamic;
		double staticIndex;
		bool shouldTrackTotal(List* list) { return !isDynamic && list->trackStaticFieldTotals; }
		TreeNode* total = nullptr;
		TreeNode* totalInput = nullptr;
		TreeNode* totalOutput = nullptr;
		virtual Variant evaluateOnAdd(Entry* entry, const VariantParams& params) { return Variant(); }
		virtual Variant evaluateOnQuery(Entry* entry, const Variant& requester) { return Variant(); }
		virtual bool needsPuller() { return false; }
		virtual LabelField* toLabelField() { return nullptr; }
		virtual GroupField* toGroupField() { return nullptr; }

		engine_export virtual TreeNode* getEventInfoObject(const char* eventTitle) override;
	};

	class LabelField : public Field
	{
		virtual const char* getClassFactory() override { return "ListLabelField"; }
		virtual Variant evaluateOnAdd(Entry* entry, const VariantParams& params) override;
		virtual Variant evaluateOnQuery(Entry* entry, const Variant& requester) override;
		virtual LabelField* toLabelField() override { return this; }
	};
	class ExpressionField : public Field
	{
		treenode expression;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "ListExpressionField"; }
		virtual Variant evaluateOnAdd(Entry* entry, const VariantParams& params) override;
		virtual Variant evaluateOnQuery(Entry* entry, const Variant& requester) override;
		virtual bool needsPuller() override;
	};
	class PushArgumentField : public Field
	{
		double paramNum;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "ListPushArgumentField"; }
		virtual Variant evaluateOnAdd(Entry* entry, const VariantParams& params) override;
	};
	class GroupField : public Field
	{
	public:
		GroupField(TreeNode* groupNode) { group = groupNode; isDynamic = 0; staticIndex = 0; }
		GroupField() {}
		NodeRef group;
		virtual void bind() override;
		virtual void reset(List* list) override;
		virtual const char* getClassFactory() override { return "ListGroupField"; }
		virtual Variant evaluateOnAdd(Entry* entry, const VariantParams& params) override;
		virtual Variant evaluateOnQuery(Entry* entry, const Variant& requester) override;
		virtual GroupField* toGroupField() override { return this; }
	};

	struct OverflowTrackableValue
	{
		TreeNode* labelNode = nullptr;
		Variant* varRef = nullptr;
		Field* fieldRef = nullptr;
	};

	class Partition;
	class ListSqlDataSource : public SqlDataSource
	{
	public:
		ListSqlDataSource() {}
		ListSqlDataSource(List* list) : list(list) {}
		virtual const char* getClassFactory() override { return "ListSqlDataSource"; }
		virtual void bind() override;
		virtual int getColID(int tableID, const char* colName, int& flags) override;
		void reset();
		void onModelReset();
		virtual const char* enumerateColNames(int tableID, int colNum) override;
		virtual Variant getValue(int tableID, int row, int colID) override;
		virtual bool setValue(int tableID, int row, int colID, const Variant& toValue) override;
		virtual int getTableID(const char* tableName) override;
		virtual int getRowCount(int tableID) override;
		virtual OverflowTrackableValue getOverflowTrackableValue(int row, int colID);

		virtual bool hasCustomWhereFilter() override { return matchValues != nullptr || list->shouldTrackIneligibleEntries; }
		bool evaluateCustomWhereFilter(SqlQueryInterface* q, int row);
		virtual bool evaluateCustomWhereFilter(SqlQueryInterface* q) override;
		virtual const char* getFlexScriptType(int tableID, int colID) override;

		TreeNode* curPuller = nullptr;
		List* list;
		Partition* partition;
		TreeNode* sqlParse = 0;
		const Array* matchValues = nullptr;
		bool queryUsesSelectQty = false;
		std::vector<std::string> labelNames;
		void assertSQLParse();
		void setQuery(SqlQuery* q);
		static const int VALUE_TABLE = 0;
		static const int PULLER_TABLE = 1;
		static const int BACK_ORDER_TABLE = 2;
	};
	class ListBackOrderSqlDataSource : public ListSqlDataSource
	{
	public:
		ListBackOrderSqlDataSource() : ListSqlDataSource() {}
		ListBackOrderSqlDataSource(List* list) : ListSqlDataSource(list) {}
		virtual const char* getClassFactory() override { return "ListBackOrderSqlDataSource"; }
		virtual void bind() override;
		virtual int getTableID(const char* tableName) override;
		virtual int getColID(int tableID, const char* colName, int& flags) override;
		virtual Variant getValue(int tableID, int row, int colID) override;
		virtual int getRowCount(int tableID) override;
		virtual bool evaluateCustomWhereFilter(SqlQueryInterface* q) override;
		/// <summary>The current 0-based entry row to compare back orders against.</summary>
		int curEntryRow = 0;
	};

	struct EntryRange {
		EntryRange() {}
		EntryRange(int begin, int end) : begin(begin), end(end) {}
		int begin;
		int end;
	};

	class BackOrder : public ListSqlDataSource
	{
	public:
		BackOrder() {}
		BackOrder(List* list, double numRequested, double numRequired, double numFulfilled,
			const Variant& puller, Partition* partition, int flags, const Array* matchValues, ListSqlDataSource* originalDelegate)
			: ListSqlDataSource(list), numRequested(numRequested), numRequired(numRequired), numFulfilled(numFulfilled),
			puller(puller), flags(flags), originalDelegate(originalDelegate)
		{
			orderTime = time();
			incrementalAllocation = !(flags & List::ALLOCATE_ALL_OR_NOTHING);
			this->partition = partition;
			if (matchValues)
				this->matchValues.reset(new Array(*matchValues));
		}
		virtual const char* getClassFactory() override { return "ListBackOrder"; }
		virtual void bind() override;
		double numFulfilled;
		double numRequired;
		double numRequested;
		double lastFulfillQty = 0.0;
		double orderTime;
		Variant puller;
		TreeNode* labels;
		std::unique_ptr<Array> matchValues;
		int flags;
		bool incrementalAllocation;
		EntryRange range;
		ListSqlDataSource* originalDelegate;
		enum class Fulfillment {
			None,
			Partial,
			Full
		};
		Fulfillment checkFulfill(EntryRange& range);
		virtual int getRowCount(int tableID) override;
		virtual Variant getValue(int tableID, int row, int colID) override;
		virtual bool evaluateCustomWhereFilter(SqlQueryInterface* q) override;
		virtual OverflowTrackableValue getOverflowTrackableValue(int row, int colID) override;


		TreeNode* onFulfill = nullptr;
		virtual void bindEvents() override;
		Variant value;

		Variant __getPuller() { return puller; }
		std::string __getQuery();
		double __getNumRequested() { return numRequested; }
		double __getNumRequired() { return numRequired; }
		int __getFlags() { return flags; }
		void remove() { List::remove(holder); };
		engine_export virtual void bindInterface() override;

		operator treenode () { return holder; }

		virtual TreeNode* getLabelNode(const char* labelName, bool assert) override;
		virtual TreeNode* getLabelNode(int labelRank, bool assert) override;
		Variant getLabelProperty(const char* name, unsigned nameHash, bool dieHard);
		void setLabelProperty(const char* name, unsigned nameHash, const Variant& value);
		LabelsArray getLabels() { return LabelsArray(holder); }
		virtual int getCapabilities() override { return CAPABILITY_LABELS; }
	};

	/// <summary>	A push result that is still being composed (as opposed to a push 
	/// 			result that is the final result of a push). </summary>
	/// <remarks>	Anthony.johnson, 2/27/2017. </remarks>
	struct ComposingPushResult
	{
		ComposingPushResult() {}
		ComposingPushResult(const Variant& val) { addToResult(returnVal); }
		ComposingPushResult(ComposingPushResult&& other) : returnVal(std::move(other.returnVal)), returnArray(std::move(other.returnArray)) {  }
		Variant returnVal;
		std::unique_ptr<std::vector<Variant>> returnArray;
		int numResults = 0;
		Variant getResult();
		void addToResult(const Variant& puller);
	};

	typedef NodeListArray<Entry>::CouplingSdtSubNodeType EntryList;

	NodeListArray<Field>::SdtSubNodeBindingType fields;
	double numTrackingFields;
	double trackStaticFieldTotals;
	NodeListArray<Entry>::CouplingSdtSubNodeType removedEntries;
	TreeNode* contentsOnReset;

	ByteBlock listType;	
	bool shouldTrackIneligibleEntries = false;
	std::vector<Entry*> ineligibleEntries;
protected:
	std::vector<int> staticFields;
	std::vector<int> dynamicFields;
	void cacheFieldIndices();
	void cacheBackOrderIndices();
	Variant push(const VariantParams& params);
	static Variant curPuller;

	class VariantKeyEqual
	{
	public:
		bool operator() (const Variant& a, const Variant& b) const;
	};


public:
	static List* global(const char* name);
	// Events
	TreeNode* onPush = nullptr;
	TreeNode* onPull = nullptr;
	TreeNode* onValuePulled = nullptr;

	class BackOrderFulfillEvent : public FlexSimEvent
	{
	public:
		BackOrderFulfillEvent() {}
		BackOrderFulfillEvent(Partition* partition, Entry* entry, const Variant& pushedVal);
		virtual const char* getClassFactory() override { return "ListBackOrderFulfillEvent"; }
		virtual void execute() override;
		virtual void bind() override;
		Variant pushedVal;
	};
	class PullResult : public Variant
	{
	public:
		PullResult() : backOrder(nullptr), amountPulled(0.0) {}
		BackOrder* backOrder;
		double amountPulled;
		void destruct() { this->~PullResult(); }
		void construct() { ::new(this) PullResult(); }
		void copyConstruct(const PullResult& other) { ::new (this) PullResult(other); }
		static void bindInterface();
		BackOrder* __getBackOrder() { return backOrder; }
	};

	class Partition : public SimpleDataType
	{
	public:
		Partition() {}
		Partition(Variant partitionID, List* list) : id(partitionID), list(list) {}
		engine_export void cleanup();
		~Partition() { cleanup(); }

		std::unordered_map<Variant, Entry*, Variant::Hash, VariantKeyEqual> entryMap;
		std::unordered_map<Variant, BackOrder*, Variant::Hash, VariantKeyEqual> backOrderMap;

		typedef NodeListArray<BackOrder>::SdtSubNodeBindingType BackOrders;
		BackOrders backOrders;
		typedef NodeListArray<Entry>::CouplingSdtSubNodeBindingType Entries;
		Entries entries;
		
		typedef NodeListArray<BackOrder, nullptr, nullptr, 0, ThrowingAssertionMethod>::SdtSubNodeBindingTypeOneBased ListBackOrders;
		typedef NodeListArray<Entry, nullptr, nullptr, 0, ThrowingAssertionMethod>::CouplingSdtSubNodeBindingTypeOneBased ListEntries;

		Variant id;
		List* list;

		std::vector<BackOrder*> backOrderCallbacks;
		NodeListArray<BackOrder>::SdtSubNodeType backOrdersToRemove;
		NodeListArray<Entry>::SdtSubNodeType entriesToRemove;
		/// <summary>	The overflow entry. This is only valid if there is a select clause in the 
		/// 			pull query. If there is an entry it is pulled but not removed (there is leftover
		/// 			then this pointer will be set so it can call its onPull. </summary>
		Entry* overflowEntry = nullptr;

		engine_export virtual void bind() override;
		virtual const char* getClassFactory() override { return "ListPartition"; }


		PullResult pull(const Array* a, SqlQuery* q, double requestNum, double requireNum, const Variant& puller, int flags);

		/// <summary>Pulls the back orders.</summary>
		///
		/// <remarks>Anthony Johnson, 4/2/2018.</remarks>
		///
		/// <param name="q">		 [in,out] If non-null, a SqlQuery to process.</param>
		/// <param name="requestNum">The request number.</param>
		/// <param name="value">	 The entry value to evaluate back orders against. This value can be one of several things, 
		/// 						 and each type implies different functionality
		/// 						 If the value is a treenode, then it will check the the treenode is one of the entries. If so,
		/// 						 the back orders will be evaluated against that entry. If it is a number, then it is the number 
		/// 						 of entries to evaluate back orders against. These are assumed to be the last n entries in the list.
		/// 						 </param>
		/// <param name="flags">	 The flags.</param>
		/// <param name="range">	 [in,out] (Optional) If non-null, the range.</param>
		///
		/// <returns>A Variant.</returns>
		Variant pullBackOrders(SqlQuery* q, double requestNum, const Variant& value, int flags, EntryRange* range = nullptr);
		Variant calculateSelectClauseValue(int queryMatchIndex, int selectClauseRank, SqlQuery* q, List::OverflowTrackableValue* tracker);
		/// <summary>	Gets the result from the last pull query. </summary>
		/// <remarks>	Returns either a scalar value or an array, depending on what the query is. Also,
		/// 			this will remove the entries that are fulfilled. </remarks>
		/// <param name="numMatches">		  	Number of matching entries in the last pull query. </param>
		/// <param name="q">				  	[in] The SqlQuery* to process. </param>
		/// <param name="puller">			  	The puller. </param>
		/// <param name="shouldRemoveEntries">	true if should remove entries. </param>
		/// <param name="range">			  	[in, out] The entry range that is currently active. </param>
		/// <param name="getEntryNodes">	  	true if you want to return the entry nodes instead of just
		/// 									the values of the entries. </param>
		/// <param name="fulfillQty">		  	[out] The fulfill qty. This is calculated within getResult(), and returned. </param>
		/// <param name="maxFulfillQty">	  	The maximum fulfill qty. Mostly needed for pull queries with a select 
		/// 									statement. Here the request num is a potentially continuous value, and
		/// 									the fulfill qty is incremented as it traverses the result, until it
		/// 									reaches the maximum fulfill qty.</param>
		/// <param name="innerRange">		  	[in,out] (Optional) If non-null, (Optional) the inner range.
		/// 									range. </param>
		/// <returns>	The result. </returns>
		Variant getResult(int numMatches, SqlQuery* q, const Variant& puller, bool shouldRemoveEntries,
			EntryRange& range, bool getEntryNodes, double& fulfillQty, double maxFulfillQty, EntryRange* innerRange = nullptr, bool isFirstFulfillment = true);

		Variant push(const VariantParams& params);
		Variant processPushedEntries(EntryRange& range, const Variant& involvedVal);
		ComposingPushResult matchEntriesToBackOrders(EntryRange& range);
		engine_export virtual Variant getEntryValue(int entryIndex, int fieldId);

		Entry* addEntry(Entry* entry, const VariantParams& params);
		void removeEntry(Entry* entry, bool getEntryNodes, bool fireOnPull);
		BackOrder* addBackOrder(BackOrder* backOrder, SqlQuery* q);
		void removeBackOrder(BackOrder* backOrder, bool fireOnFulfill);

		bool isEmpty() { return entries.size() == 0 && backOrders.size() == 0; };

		engine_export virtual void bindEvents() override;
		std::pair<int, int> getListLevels() { return { entries.size(), backOrders.size() }; }
		double getCurListLevel() { return entries.size(); }
		double getCurBackOrderLevel() { return backOrders.size(); }

		engine_export virtual void bindStatistics() override;
		TreeNode* content = nullptr;
		TreeNode* input = nullptr;
		TreeNode* output = nullptr;
		TreeNode* staytime = nullptr;

		TreeNode* backOrderContent = nullptr;
		TreeNode* backOrderInput = nullptr;
		TreeNode* backOrderOutput = nullptr;
		TreeNode* backOrderStaytime = nullptr;

		engine_export virtual TreeNode* getEventInfoObject(const char* eventTitle) override;

		ObjRef<FlexSimEvent> backOrderFulfillEvent;

		void assignSelectLabelsToPuller(TreeNode* puller, SqlQuery* q, int queryMatchIndex, bool reset, double curQty = 1.0);
	};

	NodeListArray<Partition>::SdtSubNodeBindingType partitions;
	NodeListArray<Partition>::SdtSubNodeBindingType deadPartitions;
	std::unordered_map<Variant, Partition*, Variant::Hash, VariantKeyEqual> partitionMap;
	
	double uniqueValues;
	double uniquePullers;
	double sortBackOrdersFirst;
	
	Partition* assertPartition(const Variant& partitionID);
	void removePartition(Partition& partition);
	void endPartitionOperation(Partition& partition, std::pair<int, int>& previousLevels);

	ListSqlDataSource* defaultDataSource;
	NodeListArray<ListSqlDataSource>::SdtSubNodeBindingType parsedQueries;
	NodeListArray<ListBackOrderSqlDataSource>::SdtSubNodeBindingType parsedBackOrderQueries;
	std::unordered_map<const char*, ListSqlDataSource*, CharStrHash, CharStrEquals> backOrderQueryCache;
	
	/// <summary>	boolean whether the list should cache queries. </summary>
	double cacheQueries;
	std::unordered_map<const char*, ListSqlDataSource*, CharStrHash, CharStrEquals> queryCache;

	ByteBlock backOrderQueueStrategy;
	ListBackOrderSqlDataSource* defaultBackOrderDataSource;
	ListBackOrderSqlDataSource* backOrderQueueStrategyDataSource;
	TreeNode* backOrderQueueStrategyDataSourceNode;

	void buildQueryCache();
	void buildPartitionMap();

public:
	static bool isVariantNonNull(const Variant& partitionID);

	/// <summary>	Gets the result from a pull query and, if needed, removes the pulled entries. </summary>
	/// <remarks>	This is called by a pull operation if valid results are pulled, and from the 
	/// 			back order fulfillment mechanism. </remarks>
	/// <param name="numMatches">				Number of matches previously returned from an sql query. </param>
	/// <param name="q">						The SqlQuery to retrieve the result from. </param>
	/// <param name="puller">					The puller. </param>
	/// <param name="removeEntries">			true if result entries should be removed. </param>
	/// <param name="range">					[in,out] The range of entries that were queried. </param>
	/// <param name="partitionID">				Partition ID. </param>
	/// <param name="getEntryNodes">			If true, the result will get the entry nodes instead of their associated values. </param>
	/// <param name="innerRange">				[in,out] An optional inner range. This is used 
	/// 										for all-or-nothing back order fulfillment. When this type of back order tries to be 
	/// 										fulfilled, it will set the normal range to the full range of entries because it needs
	/// 										to query the full list again. However, it also needs to track how the "incremental
	/// 										range" was changed so that the incremental range integrity will be preserved when 
	/// 										fulfilling multiple back orders. So it passes the incremental range as an "innerRange",
	/// 										the getResult() will properly update innerRange if entries from within that innerRange
	/// 										are removed.</param>
	/// <returns>	The result. </returns>
	Variant getResult(int numMatches, SqlQuery* q, const Variant& puller, bool removeEntries, EntryRange& range, const Variant& partitionID, bool getEntryNodes, EntryRange* innerRange = nullptr);


	// statistics
	TreeNode* content = nullptr;
	TreeNode* input = nullptr;
	TreeNode* output = nullptr;
	TreeNode* staytime = nullptr;

	TreeNode* backOrderContent = nullptr;
	TreeNode* backOrderInput = nullptr;
	TreeNode* backOrderOutput = nullptr;
	TreeNode* backOrderStaytime = nullptr;
	
	TreeNode* getBackOrderList(const Variant& partitionID);
	TreeNode* getEntryList(const Variant& partitionID);
	int getTotalBackOrders();
	engine_export virtual void bindVariables() override;
	engine_export virtual void bindEvents() override;
	engine_export virtual void bindStatistics() override;
	engine_export TreeNode* getPartitionNode(const Variant& partitionID);
	engine_export TreeNode* partitionResolver(const Variant& partitionID);
	engine_export int getPartitionPossibilities(TreeNode* dest, const Variant& p1, const Variant& p2);
	engine_export TreeNode* fieldResolver(const Variant& fieldID);
	engine_export int getFieldPossibilities(TreeNode* dest, const Variant& p1, const Variant& p2);
	engine_export virtual void onReset();
	engine_export virtual void onPostReset();
	void removeBadInitialContents();
	void initializeFields();
	void addInitialContents();
	void pushInitialContentsObject(TreeNode* obj);
	void addGroupFields(Group* group);
	void addGroupMembers(Group* group);
	engine_export virtual int getFieldId(const char* fieldName);
	engine_export virtual const char* enumerateColNames(int colNum);
	engine_export Variant push(const Variant& involved);
	engine_export Variant push(const Variant& involved, const Variant& partitionID);
	engine_export Variant push(const Variant& involved, const Variant& partitionID, const Variant& p1);
	engine_export Variant push(const Variant& involved, const Variant& partitionID, const Variant& p1, const Variant& p2);
	engine_export Variant push(const Variant& involved, const Variant& partitionID, const Variant& p1, const Variant& p2, const Variant& p3);
	engine_export Variant push(const Variant& involved, const Variant& partitionID, const Variant& p1, const Variant& p2, const Variant& p3, const Variant& p4, const Variant& p5 = Variant(), const Variant& p6 = Variant(),
		const Variant& p7 = Variant(), const Variant& p8 = Variant());
	/// <summary>	Gets the entry for the given value. </summary>
	/// <remarks>	If the list is set to Unique Values Only, then values pushed to the list may not
	///				result in new entries to the list. This method uses the list's internal map to quickly
	///				find the entry that's associated with the given value.
	///				If Unique Values Only is set to false this method will return null.</remarks>
	/// <returns>	Entry node. </returns>
	engine_export Entry* getEntryFromValue(const Variant& value, const Variant& partitionID = 0);

private:
	int lastPushMarker;
	ListSqlDataSource* processQuery(const char* sqlQuery, int flags, TreeNode* parsedContainer, bool isBackOrderQuery);
	PullResult pull(const Array* a, SqlQuery* q, double requestNum, double requireNum, const Variant& puller, const Variant& partitionID, int flags);
	inline Variant legacyPull(SqlQuery* q, double requestNum, double requireNum, const Variant& puller, const Variant& partitionID, int flags)
	{
		return pull(nullptr, q, requestNum, requireNum, puller, partitionID, flags);
	}
	inline Variant pullBackOrders(SqlQuery* q, double requestNum, const Variant& value, const Variant& partitionID, int flags);
	Variant pullBackOrders(const char* sqlQuery, double requestNum, const Variant& value, const Variant& partitionID, int flags);
	Variant pullBackOrders(TreeNode* cachedQuery, double requestNum, const Variant& value, const Variant& partitionID, int flags);
public:
	/// <summary>	Gets the last push marker. </summary>
	/// <remarks>	This returns the index relating to the list content BEFORE the last push was performed. This is 
	/// 			similar to getting the content of the relevant partition before pushing, and then comparing it 
	/// 			to the content after the push (to see if all pushed values were fulfilled or not), 
	/// 			except that if there are back orders that are pulling all-or-nothing, the push may fulfill other 
	/// 			entries without completely fulfilling the
	/// 			value(s) that were pushed, in which case recording the content before is invalid because entries 
	/// 			ranked before the pushed entries were removed as part of the push. getLastPushMarker() resolves this
	/// 			because it gives you an accurate dividing point between the existing entries and the newly pushed 
	/// 			entries (it is updated properly if entries before the dividing point are fulfilled as part of the push).  
	/// 			Thus, if after a push, getLastPushMarker() is less than the content of the partition, that means there
	/// 			are pushed entries that have not been completely fulfilled.</remarks>
	/// <returns>	The last push marker. </returns>
	engine_export int getLastPushMarker() { return lastPushMarker; }
	engine_export PullResult pull(const char* sqlQuery, double requestNum, double requireNum, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);
	engine_export PullResult pull(TreeNode* what, double requestNum, double requireNum, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);
	engine_export PullResult pull(const Array& a, const char*, double requestNum, double requireNum, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);
	Variant legacyPull(const char* sqlQuery, double requestNum, double requireNum, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0)
	{
		return pull(sqlQuery, requestNum, requireNum, puller, partitionID, flags);
	}
	Variant legacyPull(TreeNode* cachedQuery, double requestNum, double requireNum, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0)
	{
		return pull(cachedQuery, requestNum, requireNum, puller, partitionID, flags);
	}
	/// <summary>	Gets the back order for the given puller. </summary>
	/// <remarks>	If the list is set to Unique Pullers Only, then back orders may have multiple
	///				pullers associated with them. This method uses the list's internal map to quickly
	///				find the back order that's associated with the given puller.
	///				If Unique Pullers Only is set to false this method will return null.</remarks>
	/// <returns>	Back order node. </returns>
	engine_export TreeNode* backOrderForPuller(const Variant& puller, const Variant& partitionID);
	engine_export void listenToEntry(treenode entry, treenode callback, const Variant& p1);


private:
	class DestroyPartitionEvent : public FlexSimEvent
	{
	public:
		DestroyPartitionEvent() : FlexSimEvent() {}
		DestroyPartitionEvent(Partition* partition);

		virtual const char* getClassFactory() override { return "DestroyPartitionEvent"; }
		virtual void execute() override;
	};

public:
	class BackOrderListener;
	class BackOrderListenerEvent : public FlexSimEvent
	{
	public:
		BackOrderListenerEvent() : FlexSimEvent() {}
		BackOrderListenerEvent(List* list, double eventCode): 
			list(list), listenerType(BackOrderListener::GLOBAL), isEventQueueEvent(false),
			FlexSimEvent(nullptr, 0.0, nullptr, (int)eventCode, nullptr) {}
		BackOrderListenerEvent(List* list, Entry* entry, double eventCode, bool isEventQueueEvent) : 
			list(list), listenerType(BackOrderListener::VALUE_BASED), isEventQueueEvent(isEventQueueEvent),
			FlexSimEvent(isEventQueueEvent ? list->holder : nullptr, isEventQueueEvent ? ::FlexSim::time() : 0.0, entry->holder, (int)eventCode, nullptr) {}
		BackOrderListenerEvent(List* list, BackOrder* backOrder, double eventCode, bool isEventQueueEvent): 
			list(list), listenerType(BackOrderListener::PULLER_BASED), isEventQueueEvent(isEventQueueEvent),
			FlexSimEvent(isEventQueueEvent ? list->holder : nullptr, isEventQueueEvent ? ::FlexSim::time() : 0.0, backOrder->holder, (int)eventCode, nullptr) {}
		BackOrderListenerEvent(List* list, double time, BackOrderListener* timeIntervalListener): 
			list(list),	listenerType(BackOrderListener::TIME_INTERVAL), timeIntervalListener(timeIntervalListener), 
			FlexSimEvent(list->holder, time, nullptr, 0, nullptr), isEventQueueEvent(false) {}

		virtual const char* getClassFactory() override { return "ListBackOrderListenerEvent"; }
		virtual void execute() override;
		virtual void bind() override;
		int listenerType;
		List* list;
		BackOrderListener* timeIntervalListener = nullptr;
		bool executingNow = false;
		bool isEventQueueEvent;
	};
	class BackOrderListener : public SimpleDataType
	{
	public:
		BackOrderListener() {}
		BackOrderListener(int theListenerType) { listenerType = theListenerType; }
		virtual const char* getClassFactory() override { return "ListBackOrderListener"; }
		List* list;
		treenode focusExpression;
		treenode eventExpression;
		NodeRef focus;
		static const int PULLER_BASED = 1;
		static const int VALUE_BASED = 2;
		static const int GLOBAL = 3;
		static const int TIME_INTERVAL = 4;
		double listenerType;
		ObjRef<BackOrderListenerEvent> timeIntervalEvent;
		virtual void bind() override;
		void createNextTimeIntervalEvent();
	};
	ListBackOrderSqlDataSource* defaultBackOrderListener;
	NodeListArray<BackOrderListener>::SdtSubNodeType backOrderListeners;
	NodeListArray<BackOrderListener>::ObjPtrType valueBackOrderListeners;
	NodeListArray<BackOrderListener>::ObjPtrType pullerBackOrderListeners;
	NodeListArray<BackOrderListener>::ObjPtrType globalBackOrderListeners;
	NodeListArray<BackOrderListener>::ObjPtrType timeIntervalBackOrderListeners;
	treenode globalListenerPointers;

	double keepEmptyPartitions = 0;
	double allowMultiplePushes = 0;
	double reevaluateAllValues = 0;
	double autoAddGroupFields = 0;
	double leaveEntriesOnList = 0;

	void addValueListeners(Entry* entry);
	void addPullerListeners(BackOrder* backOrder);
	void addGlobalListeners();
	void addTimeIntervalListeners();

	void removeGlobalListeners();
	void removeTimeIntervalListeners();

	void reevaluateBackOrder(BackOrder* backOrder);
	engine_export void reevaluateBackOrders(Entry* entry);
	void reevaluateBackOrders();

	static bool hasSelectStatement(SqlQuery* q);
	engine_export virtual TreeNode* getEventInfoObject(const char* eventTitle) override;

	/// <summary>	Manually removes the given node, whether it is an entry or a back order. </summary>
	/// <remarks>	Anthony.johnson, 9/28/2015. </remarks>
	/// <param name="node">	[in,out] If non-null, the node to remove. </param>
	engine_export static void remove(TreeNode* node);

	engine_export virtual void bindInterface() override;

	ByteBlock valueAlias;
	ByteBlock valueType;
	ByteBlock pullerAlias;
	ByteBlock pullerType;

	double assignSelectValsToPuller;
	double isFirstSelectValQuantifier;

private:
	Partition::ListEntries __getListEntries(const Variant& partitionID);
	Partition::ListBackOrders __getListBackOrders(const Variant& partitionID);
};

#ifdef FLEXSIM_ENGINE_COMPILE

engine_export treenode globallist(const char* listName);
engine_export treenode globallist(int listRank);
engine_export treenode globallist(const Variant& list);

engine_export Variant listpush(const char* listName, const Variant& involved);
engine_export Variant listpush(treenode list, const Variant& involved);
engine_export Variant listpush(const char* listName, const Variant& involved, const Variant& partitionID, const Variant& p1, const Variant& p2,
                                            const Variant& p3, const Variant& p4, const Variant& p5, const Variant& p6,
                                            const Variant& p7, const Variant& p8);
engine_export Variant listpush(treenode list, const Variant& involved);
engine_export Variant listpush(treenode list, const Variant& involved, const Variant& partitionID, const Variant& p1, const Variant& p2,
                                            const Variant& p3, const Variant& p4, const Variant& p5, const Variant& p6,
                                            const Variant& p7, const Variant& p8);
engine_export treenode listbackorders(TreeNode* listNode, const Variant& partitionID);
engine_export treenode listentries(TreeNode* listNode, const Variant& partitionID);
engine_export Variant listpull(TreeNode* listNode, TreeNode* cachedQuery, double requestNum = 1, double requireNum = 1, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);
engine_export Variant listpull(TreeNode* listNode, const char* query, double requestNum = 1, double requireNum = 1, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);
engine_export Variant listpull(const char* listName, TreeNode* cachedQuery, double requestNum = 1, double requireNum = 1, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);
engine_export Variant listpull(const char* listName, const char* query, double requestNum = 1, double requireNum = 1, const Variant& puller = Variant(), const Variant& partitionID = Variant(), int flags = 0);

engine_export void listremove(TreeNode* entryOrBackOrderNode);


#endif

}
