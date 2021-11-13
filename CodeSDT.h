#pragma once
#include "BasicClasses.h"
#include "SimpleDataType.h"

namespace FlexSim {

class CodeSDT : public SimpleDataType
{
public:
	virtual Variant evaluate(const VariantParams& params) override final;
	virtual Variant evaluate(CallPoint* callPoint) { return 0; }
	virtual Variant evaluate(int code, TreeNode* c, TreeNode* classObj, EventDataStruct* data, TreeNode* i, CallPoint* callPoint) { return evaluate(callPoint); }
	virtual bool isConnected() { return false; }
	static bool isReturnValOverriddenByListener;
	static Variant overriddenReturnVal;
	static CodeSDT* getNonFlexScriptCode(TreeNode* node);
};


}