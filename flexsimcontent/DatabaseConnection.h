#pragma once

#include "ObjectDataType.h"
#include "DataTypes.h"

namespace FlexSim {
namespace Database {

class Connection;

class DataType {
	int val;
public:
	DataType() {}
	DataType(int val) : val(val) {}
	operator int() { return val; }

	static const int Unknown = 0;
	static const int Char = 1;
	static const int VarChar = 2;
	static const int NChar = 3;
	static const int NVarChar = 4;
	static const int Text = 5;
	static const int Bool = 6;
	static const int Int = 7;
	static const int SmallInt = 8;
	static const int BigInt = 9;
	static const int Decimal = 10;
	static const int Numeric = 11;
	static const int Double = 12;
	static const int Float = 13;
	static const int Real = 14;
	static const int Date = 15;
	static const int DateTime = 16;
	static const int Time = 17;
	static const int Interval = 18;

	engine_export static int fromString(const char*);
	static int fromString(const std::string& str) { return fromString(str.c_str()); }
	void bindInterface();

};

class ResultSetDelegate {
public:
	virtual ~ResultSetDelegate() {}
	virtual bool fetchNext() { return false; }
	virtual Variant operator [](int fieldNum) { return Variant(); }
	virtual Variant operator [](const char* fieldName) { return Variant(); }
	virtual std::string getFieldName(int fieldNum) { return ""; }
	engine_export const char* getFieldName_cstr(int fieldNum);
	virtual int getNumFields() { return 0; }
};

class ResultSet {
private:
	std::shared_ptr<ResultSetDelegate> delegate;
public:
	~ResultSet() {}
	void destruct() { this->~ResultSet(); }
	ResultSet() {}
	void construct() { new (this) ResultSet(); }
	ResultSet(ResultSet&& other) : delegate(std::move(other.delegate)) {}
	void copyConstruct(const ResultSet& other) { delegate = other.delegate; }
	ResultSet& operator =(const ResultSet& other) { delegate = other.delegate;  return *this; }
	engine_export void bindInterface();

	ResultSet(std::shared_ptr<ResultSetDelegate>&& _delegate)
	{
		delegate = std::move(_delegate);
	}
	bool fetchNext() { if (delegate) return delegate->fetchNext(); return false; }
	Variant operator [](int fieldNum) { if (!delegate) throw "ResultSet.getField() called on empty ResultSet."; return delegate->operator [](fieldNum);}
	Variant operator [](const char* fieldName) { if (!delegate) throw "ResultSet.getField() called on empty ResultSet."; return delegate->operator [](fieldName); }
#ifdef FLEXSIM_ENGINE_COMPILE
	std::string getFieldName(int fieldNum) { if (!delegate) throw "ResultSet.getField() called on empty ResultSet."; return delegate->getFieldName(fieldNum); }
#else
	std::string getFieldName(int fieldNum) { if (!delegate) throw "ResultSet.getField() called on empty ResultSet."; return delegate->getFieldName_cstr(fieldNum); }
#endif
	int __getNumFields() { if (!delegate) throw "ResultSet.getField() called on empty ResultSet."; return delegate->getNumFields(); }
	__declspec(property(get = __getNumFields)) int numFields;

	engine_export void cloneTo(Table& dest);

};

class PreparedStatement : public SimpleDataType
{
public:
	PreparedStatement() {}
	virtual const char* getClassFactory() override { return "DatabasePreparedStatement"; }
	virtual void bind() override;
	ByteBlock _statement;
	std::string __statement() { return _statement.getBuffer(); }
	__declspec(property(get = __statement)) std::string statement;
	virtual void bindInterface() override;
	virtual ResultSet execute() { return ResultSet(); }
	virtual void bindParam(int paramNum, const Variant& val, int type = DataType::Unknown) { }
	virtual void bindParam(const char* paramName, const Variant& val, int type = DataType::Unknown) { }
	ObjRef<Connection> connection;
};

class Connection : public SimpleDataType {
public:

	virtual void bind() override;
	virtual const char* getClassFactory() override { return "DatabaseConnection"; }
	virtual void bindInterface() override;
	static Connection* global(const char* name);
	
	ByteBlock dbType;
	ByteBlock dbAddress;
	ByteBlock dbName;
	ByteBlock dbString;
	ByteBlock userID;
	ByteBlock password;
	double useManualDBString = 0;
	NodeListArray<PreparedStatement>::SdtSubNodeBindingType preparedStatements;

	virtual bool connect() { return false; }
	virtual bool __isConnected() { return false; }
	__declspec(property(get = __isConnected)) bool isConnected;
	int __i_isConnected() { return isConnected; }
	virtual void disconnect() { preparedStatements.clear(); }

	virtual ResultSet query(const char* query) { return ResultSet(); }
	engine_export virtual PreparedStatement* prepareStatement(const char* query) { return nullptr; }


	virtual std::string __lastError() { return ""; }
	engine_export const char* __lastErrorCStr();
	__declspec(property(get = __lastErrorCStr)) const char* lastError;

	virtual int getNumFields() { return 0; }

	virtual std::string getFieldName(int fieldNum) { return ""; }
	virtual Variant getValue(int row, int col) { return Variant(); }

	engine_export bool setConnectionState(bool connectionState) 
	{ 
		bool initialState = isConnected; 
		if (initialState == connectionState)
			return initialState; 
		if (connectionState)
			connect(); 
		else disconnect(); 
		return initialState;
	}

	virtual void commit() {}
};

} // end Database namespace
} // end FlexSim namespace
