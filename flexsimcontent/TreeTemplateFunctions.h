#pragma once

#include <math.h>

#include "TreeNode.h"
#include "SimpleDataType.h"
#include "CouplingDataType.h"
#include "ObjectDataType.h"

namespace FlexSim
{

template<class ObjType>
inline ObjRef<ObjType>::operator ObjType*() const
{
	TreeNode* x = NodeRef::get();
	if (x)
		return x->objectAs(ObjType);
	else return 0;
}

template<class ObjType>
void ObjRef<ObjType>::bind(TreeNode* x) {
	switch (SimpleDataType::getBindMode()) {
	case 1: operator = (((TreeNode*)x->value)->objectAs(ObjType)); break;
	case 2: x->value = NodeRef::get(); break;
	case 4: {
		TreeNode* bindNode = NodeRef::get();
		std::string displayStr;
		if (validlink(bindNode, ""))
			displayStr = bindNode->getPath(0, 1);
		else
			displayStr = "<no path>";
		SimpleDataType::appendToDisplayStr(displayStr);
		break;
	}
	}
}

template<class Type, VariantType TypeId>
template <class OtherArrayType>
typename std::enable_if<std::is_same<OtherArrayType, FlexSimArray<Type, TypeId>>::value && std::is_same<Type, Variant>::value, FlexSimArray<Type, TypeId>>::type
	FlexSimArray<Type, TypeId>::s_clone(const OtherArrayType& original)
{
	ArrayType copy(original.size());
	if (copy.size() > 0) {
		for (size_t i = 0; i <= copy.size(); i++) {
			const Variant& val = original[i];
			if (val.type == VariantType::Array)
				copy[i] = ((ArrayType)original[i]).clone();
			else copy[i] = val;
		}
	}
	return copy;
}

template<class Type, VariantType TypeId>
template<class X>
std::string FlexSimArray<Type, TypeId>::join(typename std::enable_if<std::is_same<Type, Variant>::value && std::is_same<X, const char*>::value, X>::type separator)
{
	std::string joined;
	for (int i = 1; i <= size(); i++) {
		Variant& val = operator [] (i);
		switch (val.type) {
		case VariantType::String:
			joined.append(val.c_str());
			break;
		case VariantType::Number: {
			double fVal = val;
			double intPart;
			char buffer[200];
			if (modf(fVal, &intPart) == 0)
				sprintf(buffer, "%d", (int)fVal);
			else sprintf(buffer, "%f", fVal);
			joined.append(buffer);
			break;
		}
		case VariantType::TreeNode: {
			joined.append(((TreeNode*)val)->getPath());
			break;
		}
		case VariantType::Array: {
			joined.append("[");
			joined.append(((FlexSimArray<Variant, VariantType::Array>)val).join<const char*>(separator));
			joined.append("]");
			break;
		}
		default: {
			break;
		}
		}
		if (separator && i < size())
			joined.append(separator);
	}
	return joined;
}

template<class Type, VariantType TypeId>
void FlexSimArray<Type, TypeId>::bind(TreeNode* x) {
	Variant var = *this;
	var.bind(x);
	*this = var.operator Array();
}

template<class PropertyType>
void TypedPropertyBinding<PropertyType, typename std::enable_if_t<
	std::is_compound_v<PropertyType>
	&& !std::is_pointer_v<PropertyType>
	&& !std::is_reference_v<PropertyType>
	&& std::is_base_of_v<SimpleDataType, PropertyType>>>::set(void* owner, const Variant& val) const
{
	typedef void*(UnknownClass::*TypedSetter)(PropertyType*);
	TypedSetter typedSetter = force_cast<TypedSetter>(setter);
	treenode valAsNode = val;
	(((UnknownClass*)owner)->*typedSetter)(valAsNode ? valAsNode->object<PropertyType>() : nullptr);
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::ObjSubNodeAdder(treenode x, T* obj) {
	ObjectDataType* objPtr = (ObjectDataType*)obj;
	objPtr->holder->up = x->up; x->destroy();
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::ObjPtrAdder(treenode x, T* obj)
{
	ObjectDataType* objPtr = (ObjectDataType*)obj;
	AssertionMethod()(objPtr->holder != 0, "Adding object that is not bound to the tree");
	x->pointTo(objPtr->holder);
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::ObjCouplingAdder(treenode x, T* obj)
{
	ObjectDataType* objPtr = (ObjectDataType*)obj;
	AssertionMethod()(objPtr->holder != 0, "Adding object that is not bound to the tree");
	x->joinTo(objPtr->assertAttribute("stored", 0)->subnodes.add()->addData(DATA_POINTERCOUPLING));
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::InPortAdder(treenode x, T* obj)
{
	ObjectDataType* objPtr = (ObjectDataType*)obj;
	AssertionMethod()(obj == nullptr || objPtr->holder != 0, "Adding object that is not bound to the tree");
	PortAdder(x, obj, obj ? objPtr->Nb_connectionsin : nullptr);
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::OutPortAdder(treenode x, T* obj)
{
	ObjectDataType* objPtr = (ObjectDataType*)obj;
	AssertionMethod()(obj == nullptr || objPtr->holder != 0, "Adding object that is not bound to the tree");
	PortAdder(x, obj, obj ? objPtr->Nb_connectionsout : nullptr);
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::CenterPortAdder(treenode x, T* obj)
{
	ObjectDataType* objPtr = (ObjectDataType*)obj;
	AssertionMethod()(obj == nullptr || objPtr->holder != 0, "Adding object that is not bound to the tree");
	PortAdder(x, obj, obj ? objPtr->Nb_connectionscenter : nullptr);
}

#ifdef FLEXSIM_ENGINE_COMPILE

template <class Func>
int TreeNode::traverseTree(Func func, bool includeObjects, bool includeRootNode, bool includeBranches, int flags)
{
	int stopType = 0;
	if (includeRootNode)
		stopType = func(this);

	if (stopType == ABORT_TRAVERSE)
		return ABORT_TRAVERSE;

	if (includeObjects && datatype == DATA_OBJECT && !(stopType & STOP_TRAVERSE_OBJ_TREE) && !(flags & TRAVERSE_BRANCH_BEFORE_OBJECT)) {
		if (dataasobject->objecttree.traverseTree(func, includeObjects, includeBranches, includeBranches) == ABORT_TRAVERSE)
			return ABORT_TRAVERSE;
	}

	if (owner == this && owner->__listSize > 0) {
		TreeNode* curNode = step(1), *nextNode = 0;
		while (curNode) {
			nextNode = curNode->_next();
			if (curNode->traverseTree(func, includeObjects, true, includeBranches, flags) == ABORT_TRAVERSE)
				return ABORT_TRAVERSE;
			curNode = nextNode;
		}
	}

	if (branch && !(stopType & STOP_TRAVERSE_SUB_TREE)) {
		if (branch->traverseTree(func, includeObjects, includeBranches, includeBranches, flags) == ABORT_TRAVERSE)
			return ABORT_TRAVERSE;
	}

	// if the flag says traverse branch before object, then now I should traverse the object
	if (includeObjects && (flags & TRAVERSE_BRANCH_BEFORE_OBJECT) && datatype == DATA_OBJECT && !(stopType & STOP_TRAVERSE_OBJ_TREE)) {
		if (dataasobject->objecttree.traverseTree(func, includeObjects, includeBranches, includeBranches, flags) == ABORT_TRAVERSE)
			return ABORT_TRAVERSE;
	}
	return 0;
}

template <class LabelDefiner>
TreeNode* TreeNode::labelGeneric(LabelDefiner labelName, bool assert)
{
	if (!isValidNode())
		throw "Attempting to access a label on an object that does not exist.";

	switch (datatype) {
		case DATA_SIMPLE: case DATA_POINTERCOUPLING: case DATA_OBJECT: {
			treenode theLabel = dataassimple->getLabelNode(labelName, assert);
			if (theLabel)
				return theLabel;
			else return nullptr;
		}
		default: return nullptr;
	}
	return nullptr;
}

template<class T, void(*Adder)(treenode x, T* obj), T* (*Getter)(treenode x), int rankOffset, class AssertionMethod>
void NodeListArray<T, Adder, Getter, rankOffset, AssertionMethod>::StoredAttCouplingAdder(treenode x, TreeNode* obj)
{
	x->joinTo(obj->dataasobject->assertAttribute("stored", 0)->subnodes.add()->addData(DATA_POINTERCOUPLING));
}

#endif

}