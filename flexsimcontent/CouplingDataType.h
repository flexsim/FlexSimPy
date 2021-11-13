#pragma once

// COPYRIGHT 2006   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

#include "BasicClasses.h"
#include "SimpleDataType.h"
#include <algorithm>

namespace FlexSim {

class CouplingDataType : public SimpleDataType
{
private:
	NodeRef* thePartner;
	NodeRef localPartner;
public:
  
	CouplingDataType() : localPartner(0), thePartner(&localPartner)
	{}
	CouplingDataType(TreeNode* x) : localPartner(x), thePartner(&localPartner)
	{}
	~CouplingDataType(){}
	NodeRef& partner() { return *thePartner; }
	const NodeRef& partner() const { return *thePartner; }
	engine_export virtual char* toString(int verbose) override; 
	virtual Variant evaluate(const VariantParams& params) override { return partner().get(); }
	virtual Variant getPrimaryValue() override { return partner().get(); }
	engine_export virtual int stringToData(const char *datastring, int precision) override;
	virtual CouplingDataType* toCoupling() override { return this; }

	#ifdef FLEXSIM_ENGINE_COMPILE
		void disown(NodeRef& newPartner);
		void reown();
		size_t getSaveSize();
		bool save(std::ostream& stream);
		bool load(std::istream& stream);
		int save(char*& destination);
		int load(const char*& source);

		int saveXML(std::ostream& doc);
		int loadXML(std::istream& doc);
	#endif
};


/// <summary> The NodeListArray class is 
/// meant to allow you, in c++, to treat a list of nodes with coupling data just
/// like a regular 0-based c++ array. So, instead of every time you have to do 
/// something like NetworkNode* nn = &o(NetworkNode, ownerobject(tonode(get(rank(node_v_myNetNodes, i)))));
/// you can just add the correct NodeListArray to your class, and do myNetNodes[i],
/// and bam, it handles all the rest.</summary>
/// 
/// <remarks> There are different ways that a list of coupling nodes may be set up, so
/// there are also several different types I've defined to represent these different
/// types of node list arrays. For example, you may have a list of just one-way 
/// pointers directly to the objects themselves. Or you may have a list of coupling nodes
/// where the other side of the coupling is created in the "stored" attribute
/// of the associated object, and so on. 
/// 
/// So, below are the basic defined ones that you can use out of the box. See the documentation of 
/// each one for more information
/// NodeListArray<YourClass>::ObjPtrType
/// NodeListArray<YourClass>::CouplingSdtPtrType
/// NodeListArray<YourClass>::ObjStoredAttCouplingType
/// NodeListArray<YourClass, YourAdder>::ObjCouplingType
/// NodeListArray<YourClass>::SdtSubNodeType
/// NodeListArray<YourClass>::SdtSubNodeBindingType
/// NodeListArray<YourClass>::CouplingSdtSubNodeType
/// NodeListArray<YourClass>::CouplingSdtSubNodeBindingType
/// NodeListArray<>::NodePtrType
/// NodeListArray<>::StoredAttCouplingType
/// NodeListArray<>::SubNodeCouplingType
/// NodeListArray<YourClass>::SdtSubNodeCouplingType
/// 
/// 
/// Also, usually you are going to initialize a NodeListArray in your bind()
/// or bindVariables() method, depending on if you're an odt or an sdt. </remarks>

class ThrowingAssertionMethod
{
public:
	void operator ()(bool value, const char* error) { if (!value) throw error; }
};
class DebugAssertionMethod
{
public:
	void operator ()(bool value, const char* error)
	{
#if defined _DEBUG
#	if defined _WINDOWS
		(void) ((!!(value)) || \
			(1 != _CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__, NULL, "%s", error)) || \
			(_CrtDbgBreak(), 0));
#	else
		#warning "NodeListArray DebugAssertionMethod Not Implemented"
#	endif
#endif
	}
};

static const int ZeroBasedRankOffset = 1;
static const int OneBasedRankOffset = 0;
template<class T = TreeNode, void(*Adder)(treenode x, T* obj) = nullptr, T* (*Getter)(treenode x) = nullptr, int rankOffset = 1, class AssertionMethod = DebugAssertionMethod>
class NodeListArray
{
	TreeNode* parent;
public:
	typedef T ElementType;

	NodeListArray() : parent(0) {}
	NodeListArray(treenode parent) : parent(parent) {}
	template <class OtherType>
	NodeListArray(treenode parent, const OtherType& copyFrom) : parent(parent)
	{
		*this = copyFrom;
	}
	template <class OtherType>
	NodeListArray(OtherType& copyFrom) : parent(copyFrom) {}
	void init(treenode parent) { this->parent = parent; }

	operator TreeNode*&() { return parent; }

	operator bool() { return parent ? true : false; }
	
	template <class OtherType>
	NodeListArray& operator = (const OtherType& copyFrom)
	{
		AssertionMethod()(parent != 0, "Not allowed to call assignment operator on null NodeListArray");
		clear();
		for (int i = 1; i <= copyFrom.size(); i++)
			add(copyFrom[i - OtherType::rankOffset]);
		return *this;
	}

	int size() const { return parent ? parent->subnodes.length : 0; }
	int __getLength() { return size(); }
	__declspec(property(get = __getLength)) int length;

	T* operator[](int index) const
	{
		AssertionMethod()(index >= 1 - rankOffset && index <= size() - rankOffset, "Array index out of bounds");
		treenode subNode = parent ? parent->subnodes[index + rankOffset] : nullptr;
		return Getter(subNode);
	}
	T* operator[](const char* name) const
	{
		treenode x = parent ? parent->subnodes[name] : nullptr;
		if (x)
			return operator[](x->rank - rankOffset);
		return NULL;
	}
	T* add(T* obj)
	{
		AssertionMethod()(obj != 0, "Adding null object not allowed");
		treenode tmp = parent->subnodes.add();
		tmp->value = (TreeNode*) nullptr;
		Adder(tmp, obj);
		return obj;
	}

	T* add(T* obj, int atIndex)
	{
		AssertionMethod()(obj != 0, "Adding null object not allowed");
		AssertionMethod()(atIndex < size() - rankOffset, "Adding object at index out of bounds");
		treenode tmp;
		tmp = parent->subnodes.add();
		if (atIndex > 0)
			tmp->rank = atIndex + 1;
		else tmp->rank = 1;
		tmp->value = (TreeNode*) nullptr;
		Adder(tmp, obj);
		return obj;
	}

	void remove(int index)
	{
		AssertionMethod()(index >= 1 - rankOffset && index <= size() - rankOffset, "Removing from index out of bounds");
		parent->subnodes[index + rankOffset]->destroy();
	}
	void clear() { parent->subnodes.clear(); }
	void swap(int index1, int index2)
	{
		int rank1 = index1 + rankOffset;
		int rank2 = index2 + rankOffset;
#		if defined FLEXSIM_ENGINE_COMPILE
		TreeNode* branch = parent->branch;
		if (!branch)
			return;
		if (branch->size() < std::max(rank1, rank2) || rank1 <= 0 || rank2 <= 0)
			return;
		return parent->branch->swap(rank1, rank2);
#		else
		swapnoderanks(parent, rank1, rank2);
#		endif
	}
	void setRank(int fromIndex, int toIndex) { parent->subnodes[fromIndex + rankOffset]->rank = toIndex + rankOffset; }
	int find(T* x) const
	{
		int tmpSize = size();
		for (int i = 1; i <= tmpSize; i++)
			if (operator[](i - rankOffset) == x)
				return i - rankOffset;
		return -1;
	}
private:
	template<class _T, class Enable = void>
	struct ToNode
	{
		static TreeNode* get() { return nullptr; }
	};
	template<class _T>
	struct ToNode<_T, typename std::enable_if<!std::is_same<_T, TreeNode>::value>::type>
	{
		static TreeNode* get(_T* x) { return x->holder; }
	};
	template<class _T>
	struct ToNode<_T, typename std::enable_if<std::is_same<_T, TreeNode>::value>::type>
	{
		static TreeNode* get(_T* x) { return x; }
	};
public:

	Array toArray()
	{
		Array values;
		int tmpSize = size();
		values.resize(tmpSize);
		for (int i = 1; i <= tmpSize; i++)
			values[i] = ToNode<T>::get(Getter(parent->subnodes[i]));

		return values;
	}

	void push(T* obj) { add(obj); }
	void pop() { if (!size()) throw "pop() called on empty container";  parent->last->destroy(); }

	void unshift(T* obj) { add(obj); parent->last->rank = 1; }
	void shift() { if (!size()) throw "shift() called on empty container"; parent->first->destroy(); }

	static void bindInterface() {}

	static TreeNode* NodePtrGetter(treenode x) { return x->object<CouplingDataType>()->partner(); }
	static void NodePtrAdder(treenode x, TreeNode* obj) { x->object<CouplingDataType>()->partner() = obj; }

	static TreeNode* StoredAttCouplingGetter(treenode x)
	{
		treenode partner = x->object<CouplingDataType>() ? x->object<CouplingDataType>()->partner().get() : 0;
		if (partner)
			return partner->ownerObject;
		return 0;
	}
	static void StoredAttCouplingAdder(treenode x, TreeNode* obj)
	{
		using ODTHelper = FlexSimPrivateTypes::ODTHelper;
		x->joinTo(ODTHelper::assertAttribute(obj->object<ObjectDataType>(), "stored", 0)->subnodes.add()->addData(DATA_POINTERCOUPLING));
	}

	static TreeNode* SubNodeCouplingGetter(treenode x)
	{
		treenode partner = x->dataType == DATA_POINTERCOUPLING ? x->object<CouplingDataType>()->partner().get() : 0;
		if (partner)
			return partner->up;
		return 0;
	}
	static void SubNodeCouplingAdder(treenode x, TreeNode* obj) { x->joinTo(obj->subnodes.add()->addData(DATA_POINTERCOUPLING)); }
	static T* SdtSubNodeCouplingGetter(treenode x)
	{
		treenode partner = x->dataType == DATA_POINTERCOUPLING ? x->object<CouplingDataType>()->partner().get() : 0;
		if (partner)
			return partner->up->object<T>();
		return 0;
	}
	static void SdtSubNodeCouplingAdder(treenode x, T* obj)
	{
		SimpleDataType* objPtr = (SimpleDataType*)obj;
		AssertionMethod()(objPtr->holder != 0, "Adding object that is not bound to the tree");
		x->joinTo(objPtr->holder->subnodes.add()->addData(DATA_POINTERCOUPLING));
	}

	static T* SdtSubSubNodeCouplingGetter(treenode x)
	{
		treenode partner = x->dataType == DATA_POINTERCOUPLING ? x->object<CouplingDataType>()->partner().get() : 0;
		if (partner)
			return partner->up->up->object<T>();
		return 0;
	}

	template <TreeNode* (*ContainerGetter)(T* obj)>
	static void CustomCouplingAdder(treenode x, T* obj)
	{
		AssertionMethod()(obj->holder != 0, "Adding object that is not bound to the tree");
		x->joinTo(ContainerGetter(obj)->subnodes.add()->addData(DATA_POINTERCOUPLING));
	}


	static TreeNode* SubNodeGetter(treenode x) { return x; }
	static void SubNodeAdder(treenode x, TreeNode* obj) {}
	static T* SdtSubNodeGetter(treenode x) { return x->object<T>(); }
	static void SdtSubNodeAdder(treenode x, T* obj) { x->addSimpleData((SimpleDataType*)obj, 0); }
	static void SdtSubNodeBindingAdder(treenode x, T* obj) { x->addSimpleData((SimpleDataType*)obj, 1); }
	static void CouplingSdtSubNodeAdder(treenode x, T* obj) { x->addCouplingData((CouplingDataType*)obj, 0); }
	static void CouplingSdtSubNodeBindingAdder(treenode x, T* obj) { x->addCouplingData((CouplingDataType*)obj, 1); }
	static void ObjSubNodeAdder(treenode x, T* obj)
	{
		SimpleDataType* objPtr = (SimpleDataType*)obj;
		objPtr->holder->up = x->up; 
		x->destroy();
	}

	static T* ObjPtrGetter(treenode x)
	{
		treenode partner = x->dataType == DATA_POINTERCOUPLING ? x->object<CouplingDataType>()->partner().get() : 0;
		if (partner)
			return partner->object<T>();
		return 0;
	}
	static void ObjPtrAdder(treenode x, T* obj)
	{
		SimpleDataType* objPtr = (SimpleDataType*)obj;
		AssertionMethod()(objPtr->holder != 0, "Adding object that is not bound to the tree");
		x->pointTo(objPtr->holder);
	}
	static void CouplingSdtPtrAdder(treenode x, T* obj)
	{
		CouplingDataType* objPtr = (CouplingDataType*)obj;
		AssertionMethod()(objPtr->holder != 0, "Adding object that is not bound to the tree");
		x->joinTo(objPtr->holder);
	}

	static T* ObjCouplingGetter(treenode x)
	{
		treenode partner = x->dataType == DATA_POINTERCOUPLING ? x->object<CouplingDataType>()->partner().get() : 0;
		if (partner)
			return partner->ownerObject->object<T>();
		return 0;
	}
	static void ObjCouplingAdder(treenode x, T* obj)
	{
		using ODTHelper = FlexSimPrivateTypes::ODTHelper;
		ObjectDataType* objPtr = (ObjectDataType*)obj;
		AssertionMethod()(ODTHelper::holder(objPtr) != 0, "Adding object that is not bound to the tree");
		x->joinTo(ODTHelper::assertAttribute(objPtr, "stored", 0)->subnodes.add()->addData(DATA_POINTERCOUPLING));
	}



private:
	static T* ObjPortForwarder(treenode partner)
	{
		//  outside to inside
		if (partner->subnodes.length > 1) {
			TreeNode* rank2 = partner->subnodes[2];
			if (rank2->dataType == DATA_POINTERCOUPLING) {
				TreeNode* nextPartner = rank2->object<CouplingDataType>()->partner();
				if (nextPartner) {
					return ObjPortForwarder(nextPartner);
				}
			}
		} else { // inside to outside
			TreeNode* upNode = partner->up;
			if (upNode->dataType == DATA_POINTERCOUPLING) {
				TreeNode* nextPartner = upNode->object<CouplingDataType>()->partner();
				if (nextPartner) {
					return ObjPortForwarder(nextPartner);
				}
			}
		}
		return partner->ownerObject->object<T>();
	}
public:
	static T* ObjPortGetter(TreeNode * x)
	{
		treenode partner = x->dataType == DATA_POINTERCOUPLING ? x->object<CouplingDataType>()->partner().get() : 0;
		if (!validlink(partner, "")) return nullptr;

		return ObjPortForwarder(partner);
	}

	static void PortAdder(treenode x, T* obj, treenode otherList)
	{
		x->subnodes.add()->value = 0.0;
		x->subnodes.add()->value = (TreeNode*)nullptr;
		if (obj) {
			treenode other = otherList->subnodes.add()->addData(DATA_POINTERCOUPLING);
			other->subnodes.add()->addData(DATA_FLOAT);
			other->subnodes.add()->addData(DATA_POINTERCOUPLING);
			x->joinTo(other);
		}
	}
	static void InPortAdder(treenode x, T* obj)
	{
		using ODTHelper = FlexSimPrivateTypes::ODTHelper;
		ObjectDataType* objPtr = (ObjectDataType*)obj;
		AssertionMethod()(obj == nullptr || ODTHelper::holder(objPtr) != 0, "Adding object that is not bound to the tree");
		PortAdder(x, obj, obj ? ODTHelper::connectionsin(objPtr) : nullptr);
	}
	static void OutPortAdder(treenode x, T* obj)
	{
		using ODTHelper = FlexSimPrivateTypes::ODTHelper;
		ObjectDataType* objPtr = (ObjectDataType*)obj;
		AssertionMethod()(obj == nullptr || ODTHelper::holder(objPtr) != 0, "Adding object that is not bound to the tree");
		PortAdder(x, obj, obj ? ODTHelper::connectionsout(objPtr) : nullptr);
	}
	static void CenterPortAdder(treenode x, T* obj)
	{
		using ODTHelper = FlexSimPrivateTypes::ODTHelper;
		ObjectDataType* objPtr = (ObjectDataType*)obj;
		AssertionMethod()(obj == nullptr || ODTHelper::holder(objPtr) != 0, "Adding object that is not bound to the tree");
		PortAdder(x, obj, obj ? ODTHelper::connectionscenter(objPtr) : nullptr);
	}

	/*********************************************************************
	OK, Here are the list of classes that this header file sets up for you.
	**********************************************************************/

	/*********************************************************************
	NodeListArray<TheClass>::SubNodeType
	This one represents a simple list of sub-nodes
	**********************************************************************/
	typedef NodeListArray<TreeNode, SubNodeAdder, SubNodeGetter, rankOffset, AssertionMethod> SubNodeType;

	/*********************************************************************
	NodeListArray<TheClass>::ObjPtrType
	This one represents a list of direct one-way pointers to odt or sdt objects,
	For example, you may do:
	NodeListArray<NetworkNode>::ObjPtrType myNetNodes;
	Then dereferencing myNetNodes[arrayIndex] will get you back a NetworkNode*
	**********************************************************************/
	typedef NodeListArray<T, ObjPtrAdder, ObjPtrGetter, rankOffset, AssertionMethod> ObjPtrType;

	/*********************************************************************
	NodeListArray<TheClass>::CouplingSdtPtrType
	This one represents a list of two-way pointers to coupling sdt objects. It is like
	ObjPtrType in that each item in the list is a coupling node that points to an
	object, but it also assumes the other side of the reference is a coupling sdt, so
	when adding, it will join the nodes together with a two-way pointer instead of just
	a one-way pointer to the object. This is useful when you have coupling nodes where
	one side of the coupling is your custom coupling class (you would use the
	CouplingSdtSubNodeType for that side), and the other is just a vanilla coupling node
	bound to that class. On the vanilla side, you would use CouplingSdtPtrType. Note that when
	using this and adding connections to the list, you should add the
	CouplingSdtSubNodeType first, then add the CouplingSdtPtrType (the vanilla side)
	last to properly establish the connection.
	**********************************************************************/
	typedef NodeListArray<T, CouplingSdtPtrAdder, ObjPtrGetter, rankOffset, AssertionMethod> CouplingSdtPtrType;
	typedef NodeListArray<T, CouplingSdtPtrAdder, ObjPtrGetter, OneBasedRankOffset, AssertionMethod> CouplingSdtPtrTypeOneBased;

	/*********************************************************************
	NodeListArray<TheClass>::ObjStoredAttCouplingType
	This one represents a list of two-way couplings to odt objects. The other side of the
	coupling will be stored in the "stored" attribute of each object.
	NodeListArray<NetworkNode>::ObjStoredAttCouplingType myNetNodes;
	myNetNodes[arrayIndex] will then retrieve a NetworkNode*
	**********************************************************************/
	typedef NodeListArray<T, ObjCouplingAdder, ObjCouplingGetter, rankOffset, AssertionMethod> ObjStoredAttCouplingType;

	/*********************************************************************
	NodeListArray<TheClass, YourAdder>::ObjCouplingType
	This one represents a list of two-way couplings to odt objects. It's like
	ObjStoredAttCouplingType except the other side of the
	coupling is stored where you want it to be stored, so you have to add the adder yourself

	NodeListArray<NetworkNode, myAddToNetNodesVar>::ObjCouplingType myNetNodes;
	myNetNodes[arrayIndex] will then retrieve a NetworkNode*. Note you have to define
	the function myAddToNetNodesVar, which in this example should look like this:
	void myAddToNetNodesVar(treenode x, NetworkNode* y) {
	nodejoin(x, nodeadddata(nodeinsertinto(y->node_v_backpointer), DATATYPE_COUPLING);
	}

	Or for simplicity, you can instead just define the container for adding on the other side of the coupling by using the
	CustomCouplingAdder to do this:
	class MyType {
	static TreeNode* GetOtherContainer(OtherType* other) {return other->myTypeList;}
	NodeListArray<OtherType, NodeListArray<OtherType>::CustomCouplingAdder<GetOtherContainer>>::SdtSubSubNodeType otherTypeList;
	};
	**********************************************************************/
	typedef NodeListArray<T, Adder, ObjCouplingGetter, rankOffset, AssertionMethod> ObjCouplingType;

	/*********************************************************************
	NodeListArray<TheClass>::OutObjectType
	This one represents a list of objects connected to an object's output ports (zero-based)
	**********************************************************************/
	typedef NodeListArray<T, InPortAdder, ObjPortGetter, rankOffset, AssertionMethod> OutObjectType;
	typedef NodeListArray<T, InPortAdder, ObjPortGetter, OneBasedRankOffset, AssertionMethod> OutObjectTypeOneBased;

	/*********************************************************************
	NodeListArray<TheClass>::InObjectType
	This one represents a list of objects connected to an object's input ports (zero-based)
	**********************************************************************/
	typedef NodeListArray<T, OutPortAdder, ObjPortGetter, rankOffset, AssertionMethod> InObjectType;
	typedef NodeListArray<T, OutPortAdder, ObjPortGetter, OneBasedRankOffset, AssertionMethod> InObjectTypeOneBased;

	/*********************************************************************
	NodeListArray<TheClass>::CenterObjectType
	This one represents a list of objects connected to an object's input ports (zero-based)
	**********************************************************************/
	typedef NodeListArray<T, CenterPortAdder, ObjPortGetter, rankOffset, AssertionMethod> CenterObjectType;
	typedef NodeListArray<T, CenterPortAdder, ObjPortGetter, OneBasedRankOffset, AssertionMethod> CenterObjectTypeOneBased;

	/*********************************************************************
	NodeListArray<TheClass>::SdtSubNodeType
	This one represents a straight list of sdt's.

	NodeListArray<MySdt>::SdtSubNodeType mySdts;
	myNetNodes[arrayIndex] will then retrieve the MySdt* stored directly in the given sub-node.
	**********************************************************************/
	typedef NodeListArray<T, SdtSubNodeAdder, SdtSubNodeGetter, rankOffset, AssertionMethod> SdtSubNodeType;
	typedef NodeListArray<T, SdtSubNodeBindingAdder, SdtSubNodeGetter, rankOffset, AssertionMethod> SdtSubNodeBindingType;
	typedef NodeListArray<T, SdtSubNodeBindingAdder, SdtSubNodeGetter, OneBasedRankOffset, AssertionMethod> SdtSubNodeBindingTypeOneBased;

	/*********************************************************************
	NodeListArray<TheClass>::CouplingSdtSubNodeType
	This one represents a straight list of coupling sdt's. It's just like SdtSubNodeType, except
	the adder will use nodeaddcouplingdata() instead of nodeaddsimpledata().

	NodeListArray<MySdt>::CouplingSdtSubNodeType mySdts;
	myNetNodes[arrayIndex] will then retrieve the MySdt* stored directly in the given sub-node.
	**********************************************************************/
	typedef NodeListArray<T, CouplingSdtSubNodeAdder, SdtSubNodeGetter, rankOffset, AssertionMethod> CouplingSdtSubNodeType;
	typedef NodeListArray<T, CouplingSdtSubNodeBindingAdder, SdtSubNodeGetter, rankOffset, AssertionMethod> CouplingSdtSubNodeBindingType;
	typedef NodeListArray<T, CouplingSdtSubNodeBindingAdder, SdtSubNodeGetter, OneBasedRankOffset, AssertionMethod> CouplingSdtSubNodeBindingTypeOneBased;
	/*********************************************************************
	NodeListArray<TheClass>::ObjSubNodeType
	This one represents a straight list of odt's.

	NodeListArray<MyObj>::ObjSubNodeType myObjs;
	myObjs[arrayIndex] will then retrieve the MyObj* stored directly in the given sub-node.
	to add, you do myObjs.add(createinstance(theClass, model())->object<MyObj>());
	**********************************************************************/
	typedef NodeListArray<T, ObjSubNodeAdder, SdtSubNodeGetter, rankOffset, AssertionMethod> ObjSubNodeType;
	typedef NodeListArray<T, ObjSubNodeAdder, SdtSubNodeGetter, OneBasedRankOffset, AssertionMethod> ObjSubNodeTypeOneBased;

	/*********************************************************************
	NodeListArray::NodePtrType:
	This one represents a list of one-way pointers to nodes. This is just like the
	NodeListArray::ObjPtrType, except it returns a TreeNode*, i.e. the node itself instead of the odt/sdt.
	This can be used if you're pointing to nodes that don't necessarily have object data.
	NodeListArray::NodePtrType myNetNodes;
	myNetNodes[arrayIndex] will then get back a treenode that is the network node.
	**********************************************************************/
	typedef NodeListArray<TreeNode, NodePtrAdder, NodePtrGetter, rankOffset, AssertionMethod> NodePtrType;

	/*********************************************************************
	NodeListArray::StoredAttCouplingType:
	This one represents a list of two-way couplings to objects. This is just like the
	NodeListArray::ObjStoredAttCouplingType, except it returns a TreeNode*, i.e. the node itself instead of the odt/sdt.
	Like ObjListArray, the other side of the coupling will be stored in the "stored" attribute
	of the object.
	NodeListArray::StoredAttCouplingType myNetNodes;
	myNetNodes[arrayIndex] will then get back a treenode that is the network node.
	**********************************************************************/
	typedef NodeListArray<TreeNode, StoredAttCouplingAdder, StoredAttCouplingGetter, rankOffset, AssertionMethod> StoredAttCouplingType;
	typedef NodeListArray<TreeNode, StoredAttCouplingAdder, StoredAttCouplingGetter, OneBasedRankOffset, AssertionMethod> StoredAttCouplingTypeOneBased;

	/*********************************************************************
	NodeListArray::SubNodeCouplingType:
	This one represents a list of two-way couplings to nodes. This will store the other side of the
	coupling as a sub-node of the node referenced, and when dereferenced it will return the node that
	contains the coupling sub-node.
	**********************************************************************/
	typedef NodeListArray<TreeNode, SubNodeCouplingAdder, SubNodeCouplingGetter, rankOffset, AssertionMethod> SubNodeCouplingType;

	/*********************************************************************
	NodeListArray<MyObj>::SdtSubNodeCouplingType:
	This one represents a list of two-way couplings to objects. This will store the other side of the
	coupling as a sub-node of the object referenced, and when dereferenced it will return the object
	whose holder node contains the coupling sub-node. It's just like SubNodeCouplingType, except it returns
	an object reference instead of a node reference.
	**********************************************************************/
	typedef NodeListArray<T, SdtSubNodeCouplingAdder, SdtSubNodeCouplingGetter, rankOffset, AssertionMethod> SdtSubNodeCouplingType;

	/*********************************************************************
	NodeListArray<OtherType, OtherTypeAdder>::SdtSubSubNodeCouplingType:
	This one represents a list of two-way couplings to objects. This will store the other side of the
	coupling as a sub-sub-node of the object referenced, and when dereferenced it will return the object
	whose holder node contains the parent of the coupling sub-node. It's just like SdtSubNodeCouplingType,
	except it returns up(up(theCouplingPartner)) instead of just one up(). Also, in this case you must
	define the adder, or just the container for the other side of the coupling by using the
	CustomCouplingAdder to do this:
	class MyType {
	static TreeNode* GetOtherContainer(OtherType* other) {return other->myTypeList;}
	NodeListArray<OtherType, NodeListArray<OtherType>::CustomCouplingAdder<GetOtherContainer>>::SdtSubSubNodeType otherTypeList;
	};

	class OtherType {
	NodeListArray<MyType>::ObjCouplingType myTypeList;
	}
	**********************************************************************/
	typedef NodeListArray<T, Adder, SdtSubSubNodeCouplingGetter, rankOffset, AssertionMethod> SdtSubSubNodeCouplingType;

	class IteratorElement
	{
		NodeListArray* list;
		TreeNode::IteratorElement nodeElement;
		int curIndex;
	public:
		IteratorElement() : curIndex(0), nodeElement() {}
		IteratorElement(NodeListArray* list, int curIndex) : list(list), curIndex(curIndex), nodeElement(list->parent, curIndex + 1) {}
		IteratorElement(IteratorElement& other) : list(other.list), curIndex(other.curIndex), nodeElement(other.nodeElement) {}
		T* operator ->() const { return Getter(nodeElement.element); }
		T* operator * () const { return Getter(nodeElement.element); }
		operator T*() const { return Getter(nodeElement.element); }
		IteratorElement& operator = (IteratorElement& other)
		{
			nodeElement = other.nodeElement;
			return *this;
		}
	};

	// Iterator for NodeListArray: for use with std iterator algorithms
	class Iterator : public std::iterator<std::random_access_iterator_tag, IteratorElement, ptrdiff_t, IteratorElement*, IteratorElement>
	{
		NodeListArray * list;
		ptrdiff_t curIndex;
	public:
		Iterator() : list(0), curIndex(-1) {}
		Iterator(NodeListArray* list, int curIndex) : list(list), curIndex(curIndex) {}
		Iterator(const Iterator& other) : list(other.list), curIndex(other.curIndex) {}
		Iterator& operator = (const Iterator& other) { list = other.list; curIndex = other.curIndex; return *this; }
		bool operator == (const Iterator& other) const { return list == other.list && curIndex == other.curIndex; }
		bool operator != (const Iterator& other) const { return !(operator == (other)); }
		//T* operator * () const {return list->operator[](curIndex);}
		//T* operator ->() {return list->operator[](curIndex);}
		IteratorElement operator * () { return IteratorElement(list, curIndex); }
		Iterator& operator ++() { curIndex++; return *this; }
		Iterator& operator ++(int x) { curIndex++; return *this; }
		Iterator& operator --() { curIndex--; return *this; }
		Iterator& operator --(int x) { curIndex--; return *this; }
		Iterator operator +(ptrdiff_t n) const { return Iterator(list, curIndex + n); }
		Iterator operator -(ptrdiff_t n) const { return Iterator(list, curIndex - n); }
		ptrdiff_t operator -(const Iterator& other) const { return curIndex - other.curIndex; }
		bool operator <(const Iterator& other) const { return curIndex < other.curIndex; }
		bool operator <=(const Iterator& other) const { return curIndex <= other.curIndex; }
		bool operator >(const Iterator& other) const { return curIndex > other.curIndex; }
		bool operator >=(const Iterator& other) const { return curIndex > other.curIndex; }
		Iterator& operator +=(ptrdiff_t n) { curIndex -= n; return *this; }
		Iterator& operator -=(ptrdiff_t n) { curIndex -= n; return *this; }
		T* operator [](ptrdiff_t n) { return list[curIndex + n]; }
	};
	// container iteration methods
	Iterator begin() { return Iterator(this, 0); }
	Iterator end() { return Iterator(this, size()); }
	Iterator rbegin() { return Iterator(this, size() - 1); }
	Iterator rend() { return Iterator(this, -1); }
	// vector-esque methods
	void push_back(T* obj) { add(obj); }
	void pop_back() { remove(size() - rankOffset); }
	Iterator insert(Iterator position, const T*& obj)
	{
		add(obj, position.curIndex);
		return position;
	}
	T* back() const
	{
		if (size() == 0)
			return 0;
		return Getter(parent->last);
	}
	T* front() const
	{
		if (size() == 0)
			return 0;
		return Getter(parent->first);
	}

};


}

// COPYRIGHT 2006   F L E X S I M   C O R P O R A T I O N .  ALL RIGHTS RESERVED.

