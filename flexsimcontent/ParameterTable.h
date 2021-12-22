#pragma once

#include "ObjectDataType.h"

namespace FlexSim
{
class ConstrainedVariable;
class ParameterTable : public ObjectDataType
{
protected:
	static Map nameRowMap;
	static bool mapDirty;
	static void buildMap(bool reset = false);
	static TreeNode* globalContainer(bool assert = false);

public:
	static ConstrainedVariable* find(const char* name);
	engine_export static TreeNode* findParameter(const char* name);
	static ParameterTable* findTable(const char* name);
	static Array getTables();

protected:
	static const int NAME_NODE_RANK = 1;
	static const int CV_RANK = 2;
	static const int UNIT_RANK = 3;
	static const int DESC_RANK = 4;
	static const int MAX_COLUMNS = DESC_RANK;

	TreeNode* addParameter();

protected:
	TreeNode* importData;

public:
	TreeNode* params;

	virtual void bindVariables() override;

	virtual void resetParameters();
	engine_export TreeNode* addParameter(const char* defaultName);
	engine_export void applyImportData();

	Array getNames();

	static void resetAll();
	static Map getParameterValues();
};

class Parameters
{
public:
	static ConstrainedVariable* find(const char* name) {
		return ParameterTable::find(name);
	}

	engine_export TreeNode* findNode(const char* name);

	Variant getProperty(const char* name, unsigned nameHash, bool dieHard);
	void setProperty(const char* name, unsigned nameHash, const Variant& value);
	ConstrainedVariable* operator[](const char* name) { return find(name); }

	engine_export Array names(const char* tableName = nullptr);
	engine_export Array _getTableNames();
	__declspec(property(get = _getTableNames)) Array tableNames;
	
	void bindInterface();
};

}