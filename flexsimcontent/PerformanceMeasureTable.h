#pragma once

#include "ObjectDataType.h"

namespace FlexSim
{
class StatusVariable;
class PerformanceMeasureTable : public ObjectDataType
{
protected:
	static Map nameRowMap;
	static bool mapDirty;
	static void buildMap(bool reset = false);
	static TreeNode* globalContainer(bool assert = false);

public:
	static StatusVariable* find(const char* name);
	engine_export static TreeNode* findPerformanceMeasure(const char* name);
	static PerformanceMeasureTable* findTable(const char* name);
	static Array getTables();

protected:
	static const int NAME_NODE_RANK = 1;
	static const int SV_RANK = 2;
	static const int UNIT_RANK = 3;
	static const int DESC_RANK = 4;
	static const int MAX_COLUMNS = DESC_RANK;

	TreeNode* addPerformanceMeasure();

protected:
	TreeNode* importData;

public:
	TreeNode* performanceMeasures;

	virtual void bindVariables() override;

	virtual void resetPerformanceMeasures();
	engine_export TreeNode* addPerformanceMeasure(const char* defaultName);
	
	Array getNames();

	engine_export void reset();
};

class PerformanceMeasures
{
public:
	static StatusVariable* find(const char* name) {
		return PerformanceMeasureTable::find(name);
	}

	Variant getProperty(const char* name, unsigned nameHash, bool dieHard);
	void setProperty(const char* name, unsigned nameHash, const Variant& value);
	StatusVariable* operator[](const char* name) { return find(name); }

	engine_export Array names(const char* tableName = nullptr);
	engine_export Array _getTableNames();
	__declspec(property(get = _getTableNames)) Array tableNames;
	
	void bindInterface();
};

}