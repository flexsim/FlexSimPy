#pragma once

#include "CouplingDataType.h"
#include "TreeNode.h"

namespace FlexSim {

class FlexSimEvent : public CouplingDataType
{
	public:
	TreeNode* object() {return partner();}
	double time;
	NodeRef involved;
	int code;
	static const int DATA_SIZE = 68;
	char data[DATA_SIZE];
	int64_t eventcounter;

	FlexSimEvent() :
			time(0),
			involved(0),
			code(0) {
		data[0] = 0;
	}

	FlexSimEvent(TreeNode* object, double time, TreeNode* involved, int code, const char* _data = 0) : 
			CouplingDataType(object),
			time(time),
			involved(involved),
			code(code){
		data[0] = 0;
		if (_data) {
			char* copyPoint = data;
			// I don't use strncpy because I don't want to be dependent on <string.h>
			while ((*(copyPoint++) = *(_data++)) != 0 && copyPoint - data < 68)
				;
			data[DATA_SIZE - 1] = 0;// make sure it's null terminated
		}
	}

	engine_export virtual void execute();
	virtual const char* getClassFactory(){return "FlexSimEvent";}
	engine_export virtual void bind();
	engine_export virtual void getDescription(char* toStr, size_t maxSize);
	engine_export virtual void getEventDataDescription(char* toStr, size_t maxSize);

protected:
	CallPoint* getListenerCallPoint(){return (CallPoint*)*((void**)&(data[0]));}
#ifdef FLEXSIM_ENGINE_COMPILE
public:
	bool isChildClass() {return *((void**)this) != *((void**)&childChecker);}
private:
	static FlexSimEvent childChecker;
#endif
public:
	template<class LambdaType = std::function<void()>>
	static FlexSimEvent* create(treenode focus, double time, const char* description, LambdaType callback)
	{
		class LambdaEvent : public FlexSimEvent {
		public:
			LambdaEvent(treenode focus, double time, LambdaType callback, const char* description = nullptr)
				: FlexSimEvent(focus, time, nullptr, 0, description),
				callback(callback)
			{}
			LambdaEvent(treenode focus, double time, LambdaType&& callback, const char* description = nullptr)
				: FlexSimEvent(focus, time, nullptr, 0, description),
				callback(std::move(callback))
			{}
			LambdaType callback;
			virtual void execute() override { callback(); }
			virtual const char* getClassFactory() override { return "LambdaEvent"; }
			virtual void getDescription(char* toStr, size_t maxSize) override
			{
				toStr[0] = 0;
				const char* src;
				if (data[0] != 0)
					src = data;
				else src = "Anonymous Lambda Event";

				char* copyPoint = toStr;
				// I don't use strncpy because I don't want to be dependent on <string.h>
				while ((*(copyPoint++) = *(src++)) != 0 && copyPoint - toStr < maxSize)
					;
				toStr[maxSize - 1] = 0;// make sure it's null terminated
			}

			virtual void getEventDataDescription(char* toStr, size_t maxSize) override
			{
				toStr[0] = 0;
			}
		};
		return new LambdaEvent(focus, time, callback, description);
	}
};

class ValueChangeListener : public FlexSimEvent
{
public:
	engine_export ~ValueChangeListener();
	enum ChangeRule {
		Change = 0,
		Increase = 1,
		Decrease = 2,
		ArriveAtValue = 3,
		IncreaseToValue = 4,
		DecreaseToValue = 5,
		IncreaseToOrThroughValue = 6,
		DecreaseToOrThroughValue = 7,
		FirstIncrease = 8,
		FirstDecrease = 9,
		Update = 10,
	};
	ValueChangeListener() {}
	void setFirstOldOldValue()
	{
		if (changeRule == FirstIncrease)
			oldOldValue = DBL_MAX;
		else if (changeRule == FirstDecrease)
			oldOldValue = -DBL_MAX;
	}
	ValueChangeListener(ChangeRule changeRule, double changeValue) : changeRule(changeRule), changeValue(changeValue)
	{
		setFirstOldOldValue();
	}
	ValueChangeListener(ChangeRule changeRule) : changeRule(changeRule), changeValue(0.0)
	{
		setFirstOldOldValue();
	}

	ChangeRule changeRule;
	double changeValue;
	double oldOldValue = 0;
	double lastRate = 0;
	class KineticLevelCrossEvent : public FlexSimEvent
	{
	public:
		virtual const char* getClassFactory() override { return "KineticLevelCrossEvent"; }
		KineticLevelCrossEvent(ValueChangeListener* listener, double time) : FlexSimEvent(listener->holder, time, nullptr, 0) {}
		KineticLevelCrossEvent() : FlexSimEvent() {}
		virtual void execute() override {
			TreeNode* partnerNode = partner();
			if (validlink(partnerNode, ""))
				partnerNode->objectAs(ValueChangeListener)->onKineticLevelCrossed();
		}
	};
	FlexSimEvent* kineticLevelCrossEvent = nullptr;
	TrackedVariable* variable = nullptr;
	engine_export virtual void bind() override;
	engine_export void init();
	engine_export void onKineticLevelCrossed();
private:
	/// <summary>	Initializes the kinetic level listening. </summary>
	/// <remarks>	Anthony.johnson, 3/2/2016. </remarks>
	/// <returns>	true if it should call onChangeRuleMet immediately. </returns>
	bool initKineticLevelListening(double newValue, double oldValue);
public:
	virtual void onChangeRuleMet(const Variant& newValue, const Variant& oldValue) {}
	engine_export virtual void execute() override;
	engine_export static bool isRuleMetForInitialValue(ChangeRule changeRule, double changeValue, double initialValue);
};

class ComboStateChangeEvent : public FlexSimEvent
{
public:
	virtual bool isClassType(const char* className) override;
	virtual const char* getClassFactory() override { return "ComboStateChangeEvent"; }
	virtual void execute() override;
};

class MessageEvent : public FlexSimEvent {
public:
	static const int EVENT_SENDMESSAGE = 19;
	Variant p1;
	Variant p2;
	Variant p3;
	MessageEvent() : FlexSimEvent()
	{}
	MessageEvent(treenode toobject, double time, treenode fromobject, const Variant& p1, const Variant& p2, const Variant& p3)
		: FlexSimEvent(toobject, time, fromobject, EVENT_SENDMESSAGE, NULL),
		p1(p1), p2(p2), p3(p3)
	{}
	MessageEvent(treenode toobject, double time, treenode fromobject, double p1, double p2, double p3)
		: FlexSimEvent(toobject, time, fromobject, EVENT_SENDMESSAGE, NULL),
		p1(p1), p2(p2), p3(p3)
	{}
	engine_export virtual void execute() override;
	engine_export virtual const char* getClassFactory() override { return "SendMessageEvent"; }
	engine_export virtual void bind() override;
	engine_export virtual void getDescription(char* toStr, size_t maxSize) override;
	engine_export virtual void getEventDataDescription(char* toStr, size_t maxSize) override;
};



}

