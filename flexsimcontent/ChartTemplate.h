#pragma once

#include "ObjectDataType.h"

namespace FlexSim
{

class CalculatedTable;

/*
The ChartTemplate class is a class that is designed to:
		"use FlexSim for the user to make charts"

It manages several internal objects that could include
	-a process flow
	-a statistics collector
	-a groups (or two)
	-a calculated table
	-a GenericChart object

With these internal objects, it should be able to produce a WebStatGraph,
a chart that the user wanted.

The UI can then be reduced to a few simple options, so that an experience
like the one pre 17.2 can be had: pick a chart from the library, pick
some objects, and ta-da! You have a chart.

This class is defined in the engine so that run-time users can create
these objects.
*/

class ChartTemplate : public ObjectDataType
{
protected:
	TreeNode* primaryGroup;
	TreeNode* secondaryGroup;

	TreeNode* processFlow;
	TreeNode* coreCollector;
	TreeNode* statisticsCollector;
	TreeNode* calculatedTable;
	TreeNode* genericChart;

	TreeNode* statisticsCollectorStored;
	TreeNode* calculatedTableStored;

	NodeListArray<>::SubNodeType processedReplacements;
	double firstPrepareComplete = 0;

	TreeNode* chartLinks;

	NodeRef genericChartRef;

public:
	// type determines which UI to show
	TreeNode* type;

	// these values determine which template objects to use
	ByteBlock flowPath;
	ByteBlock coreCollectorPath;
	ByteBlock collectorPath;
	ByteBlock calculatedTablePath;
	ByteBlock genericChartPath;

	// The replacements list is a kind of table. The name of each
	// node is the name of a replacement.
	// o references
	// L o Type "SKU"
	// | L o text "MAIN:/path/to/code" (segements of code replaced with parent value)
	// | L o name "MAIN:/path/to/name/of/node/to/rename" (name replaced with parent value)
	// | L o value "MAIN:/path/to/value/to/replace" (value replaced with parent value)
	// L o PrimaryGroup refToGroupUserWants
	// | L o value "MAIN:/path/to/group/reference"
	// L o RefValue "MAIN:/path/to/some/template/node" (this value is replaced with the correct node)
	//
	// During prepare(), this structure is translated and saved in processedReplacements:
	//
	// o processedReferences
	// | o Type "SKU"
	// | L o text ptrToCode (segements of code replaced with parent value)
	// | |  L o [no name] ptrToOriginalCode
	// | L o name ptrToTargetNode (name replaced with parent value)
	// | L o value ptrToTargetNode (value replaced with parent value)
	// L o PrimaryGroup refToGroupUserWants
	// | L o value ptrToTargetNode
	// L o RefValue ptrToValue
	//
	// This way, instances can correctly update values they need
	NodeListArray<>::SubNodeType replacements;

	// The preservedNodes list is a list of nodes to keep from the user's side
	// During pack and unpack, these nodes will be saved and loaded. This
	// way, some user settings can be preserved.
	NodeListArray<>::SubNodeType preservedNodes;

	// some chart templates (like the ones for people module) don't need internal groups
	double skipGroups;

private:
	TreeNode* getPreserveTarget(TreeNode* preserveInfo);
	void savePreservedNodes();
	void loadPreservedNodes();

	// Anywhere I call doReplacements(), I need to call configure eventually
	// On save/load, I configure after the preserved nodes are loaded.
	bool needsConfigure = false;
	void configure();

public:
	engine_export void pack();
	engine_export void clearEvents();
	engine_export void clearObjects();

	void verifyType();
	engine_export void prepare();
	engine_export void apply();
	engine_export void doReplacements(bool installing = false);
	void replaceEvents();
	engine_export void unpack();

	engine_export void install();

	engine_export void onCreate();
	engine_export void onSave();
	engine_export void onPostSave();
	engine_export void onLoad();

	engine_export void onRunWarm();

	engine_export virtual void bindVariables() override;


	static TreeNode* global(const char* name);
	StatisticsCollector* getStatisticsCollector();
	CalculatedTable* getCalculatedTable();
	engine_export TreeNode* getPrimaryTable();
	engine_export TreeNode* getChart();
};

}