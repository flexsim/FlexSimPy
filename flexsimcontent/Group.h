#pragma once
#include "ObjectDataType.h"

#include <set>

#if defined FLEXSIM_ENGINE_COMPILE
#include "Locator.h"
#endif

namespace FlexSim
{

class Group : public ObjectDataType
{
public:	
	Group() {}
	static Group* global(const char* name);

	virtual bool isClassType(const char* className) override { return strcmp(className, "Group") == 0 || __super::isClassType(className); }

	engine_export int isMember(treenode object, int recursive = 0);
	engine_export void addMember(treenode object);
	engine_export void removeMember(treenode object);
	engine_export int length();
	engine_export int indexOf(treenode object);
	engine_export Array toFlatArray();

	ObjectDataType* operator [] (int index);

	//Not FlexScript accessible
	int findFlatRank(treenode object);
	Array toFlatGroupArray();

private:
	bool visited;
	
	virtual void bindVariables() override;
	engine_export virtual void bindInterface() override;

	static TreeNode* getGroupAtt(ObjectDataType* other) { return other->assertAttribute("Groups", 0); }
	NodeListArray<ObjectDataType, NodeListArray<ObjectDataType>::CustomCouplingAdder<getGroupAtt>>::ObjCouplingType members;
	
	int isMemberRecursive(treenode object);

	void buildMemberArray(Array& arr, std::set<treenode>& set);
	void buildGroupArray(Array& arr);
	void markGroupsUnvisited();

	operator treenode() { return holder; };
	operator Variant() { return holder; };
};

}