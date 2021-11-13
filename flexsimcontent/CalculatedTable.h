#pragma once

#include "StatisticsCollector.h"

namespace FlexSim {

class CalculatedTable : public ObjectDataType, public ColumnFormatter
{
protected:
	bool shouldUpdate() const;

public:
	class Timer : public FlexSimEvent
	{
	public:
		virtual void execute() override;
		virtual const char* getClassFactory() override { return "CalculatedTableTimer"; }
	};

	class QuerySource : public SqlDataSource
	{
	public:
		virtual int getColID(int tableId, const char* colName, int& colFlags) override;
		virtual const char* enumerateColNames(int tableId, int colNum) override;
		virtual Variant getValue(int tableId, int row, int colId) override;
		// I don't need to set the value; collector tables are read-only for queries
		// I don't need to worry about table ID either
		virtual int getRowCount(int tableID) override;
		ObjRef<CalculatedTable> table;
		QuerySource(CalculatedTable* table) : table(table) {}
	};

	class DataSource : public Table::TableDataSource
	{
	protected:
		ObjRef<CalculatedTable> table;
		void throwError(std::string message) { throw message + " (for " + table->holder->name + ")"; }
	public:
		DataSource(CalculatedTable* table) : table(table) {}
		bool isValid() { return (bool)table; }

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

	std::shared_ptr<Table::TableDataSource> dataSource;
	std::shared_ptr<Table::TableDataSource> getTableDataSource();

	// The event listener, if doing a live query from a Statistics Collector
	class TableChangeListener : public FlexSimEvent
	{
	public:
		enum Type { None = 0, SCRowAdded, SCRowUpdated, Invalid };
		double type;
		ByteBlock tableName;

		TableChangeListener() {}
		TableChangeListener(Type type, const char* tableName);

		virtual void execute() override;

		virtual void bind() override;
		virtual const char* getClassFactory() override { return "CalculatedTableTableChangeListener"; }
		virtual bool isClassType(const char* className) override { return strcmp(className, getClassFactory()) == 0; }
	};

	// Inputs
	ByteBlock query;
	enum UpdateMode { Manual = 0, ByInterval = 1, Always = 2, LazyInterval = 3 };
	double updateMode = 0;
	double updateInterval = 0;
	double enabled = 1;
	double updateCount = 0;
	double displayTimeAsText = 0;
	double objectFormatMaxDepth = 0;

	TreeNode* formatList;

	// Internal state
	TreeNode* queryNode;

	// I only add listeners if:
	//   * the query only involves statistics collectors
	//   * the update mode is always
	//   * the "update" is called
	NodeListArray<TableChangeListener>::CouplingSdtPtrType liveListeners;
	double liveUpdateFailed = 0;

	// This gets set for unrecoverable errors (sql build or query errors)
	double buildFailed = 0;
	ByteBlock cachedQuery;

	// and here's the last update time
	double lastUpdateTime = -1;
	double updateSinceReset = 0;
	NodeRef lastUpdateEvent;

	// and here's where the result gets dumped
	BundleMember data;

	engine_export static CalculatedTable* getGlobal(const Variant& queryTable);

	// OnReset - build the sql query, and run it for the first time
	engine_export void onReset();
	engine_export void onRunWarm();
	
	bool isQueryBuildable();

	// update runs the query, and dumps the table
	engine_export void update(int force = 0);
	void updateFormatList();

	engine_export int getColumnFormat(int columnNr) override;
	engine_export Array getColumnFormats() override;
	engine_export TreeNode* getBundleNode() override;
	engine_export int getObjectFormatMaxDepth() override;
	engine_export void prepareToRead() override;

	engine_export int dependsOnExperimentData();

	engine_export virtual void bindVariables() override;

	void onSourceRowAdded(const char* tableName);
	void onSourceValueChanged(const char* tableName, int row, const char* colName, const Variant& oldValue);

	virtual CalculatedTable* toCalculatedTable() { return this; }

	// QueryBuilder methods

	protected:
	// This method is meant to traverse a treenode structure that defines
	// and arbitrary SQL expression
	enum ExprMode {
		Value,
		Score,
		Alias,
	};

	static bool isAggregation(std::string& value);
	static bool isWindowFunction(std::string& value);

#define BUILD_QUERY_EXPR_INTERFACE std::ostream& ss, TreeNode* root, ExprMode mode
	bool buildQueryExpression(BUILD_QUERY_EXPR_INTERFACE);
	std::string getNameFromColumnValue(TreeNode* root);
	bool _buildColumnValue(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildLiteral(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildBinaryOperator(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildExpression(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildAggregation(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildFunction(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildCase(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildSql(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildWindowFunction(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildUnboundedPreceding(BUILD_QUERY_EXPR_INTERFACE);
	bool _buildCurrentRow(BUILD_QUERY_EXPR_INTERFACE);

	bool isExprList(TreeNode* curNode);
	bool hasCustomSQL();

	// no bind, for internal use during buildQueryExpression
	bool hasWindow = false; 
	bool hasAggregation = false;

	void forEach(TreeNode* listNode, TreeNode* processedListNode, const std::function<void(TreeNode*)>& callback, bool generate);
	void forEachMetric(const std::function<void(TreeNode*)>& callback, bool generate = false);
	void forEachSubset(const std::function<void(TreeNode*)>& callback, bool generate = false);
	void forEachPartition(const std::function<void(TreeNode*)>& callback, bool generate = false);

	struct ColRefData
	{
		TreeNode* tableRef;
		std::string columnName;
		std::vector<ColRefData> equivalentColumns;

		bool operator==(const ColRefData& other) const {
			return tableRef == other.tableRef && columnName == other.columnName;
		}
	};
	std::pair<ColRefData, bool> extractColRefData(TreeNode* columnValue, bool readEquivalentData = false);
	std::map<TreeNode*, ColRefData> colRefData;
	std::vector<TreeNode*> getFromTables();
	bool useColRefData = false;
	void populateColRefData(const std::set<TreeNode*>& colRefSet);
	void getColRefs(std::set<TreeNode*>& colRefSet, TreeNode* expression);
	
	// This method is meant to build an entire query from the expressions
	// stored by the Calculated Table

	public:
	engine_export void buildQueryStatement();
	engine_export Array getAvailableColumns(int mode, TreeNode* tableRef);
	engine_export Array getDependentExpressions(TreeNode* exprNode);
	engine_export Array getAvailableMetrics(TreeNode* expression, bool includePartitions);
	engine_export Array getResultColumns();
	engine_export TreeNode* getTableRefForTable(TreeNode* table);

	engine_export int getSubsetCount();
	engine_export int getPartitionCount();

	TreeNode* tables;
	TreeNode* metrics;
	TreeNode* subsets;
	TreeNode* partitions;
	
	double sortResults = 0;

	ByteBlock subsetColumnName;
	ByteBlock metricNameColumnName;
	ByteBlock metricValueColumnName;

	double useQueryBuilder = 0;
	double queryBuilderDirty = 0;

	TreeNode* processedMetrics;
	TreeNode* processedSubsets;
	TreeNode* processedPartitions;

	class ExpressionGenerator : public SimpleDataType
	{
	public:
		virtual int generate() = 0;
		virtual TreeNode* getExpression(int rank) = 0;
		virtual bool isClassType(const char* className) override { 
			return strcmp(className, "ExpressionGenerator") == 0 ? true : __super::isClassType(className); 
		}
	};
};

}