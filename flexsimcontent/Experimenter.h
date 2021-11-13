#pragma once

#include <mutex>
#include <condition_variable>
#include <chrono>
#include "DataTypes.h"
#include "DatabaseConnection.h"

class COptQuestClient;

namespace FlexSim 
{

namespace Database
{
	class SQLiteConnection;
}

class Experimenter : public ObjectDataType
{
public:
	class ExperimentJob : public SimpleDataType
	{
	public:
		virtual int estimateCPUs() { return 0; };
		virtual Array getPreviewTasks() { return Array(); };
		virtual bool onExperimentStart(int numCPUs, int runID, Database::Connection* db) = 0;
		virtual void onTasksReceived(Database::Connection* db, Array tasks, Array willExecute) {}
		virtual void onTaskFinish(Database::Connection* db, Map task) {}
		virtual void onStop() {}

		static Map getCurrentParamValues();

		void submitTask(Map task);
		void submitStopTask();

		Variant submitTask(FLEXSIMINTERFACE);
		Variant submitStopTask(FLEXSIMINTERFACE);
		Variant getPreviewTasks(FLEXSIMINTERFACE);

		double id = 0;
		engine_export virtual void bind() override;
	};

	class BasicJob : public ExperimentJob
	{
	public:
		treenode scenarios;
		double numReps;
		double runTime;
		double warmupTime;

		Array createTasks();

		virtual int estimateCPUs() override;
		virtual Array getPreviewTasks() override;
		virtual bool onExperimentStart(int numCPUs, int runID, Database::Connection* db) override;
		virtual void bind() override;
		virtual const char* getClassFactory() override { return "ExperimenterBasicJob"; }
	};

	class Connection
	{
	private:
		static std::vector<std::unique_ptr<Connection>> connections;
		static std::mutex connectionsMutex;

	protected:
		static void onAccept(Connection* con);

	public:
		Connection() {}

		static Connection* factory();
		static void destruct(Connection* con);
		static void destructAll();

		virtual bool listenOnPort(int port) = 0;
		virtual Connection* accept() = 0;
		virtual bool connect(const char* ipAddr, int port) = 0;
		virtual void close() = 0;

		virtual bool send(const std::string& msg) = 0;
		virtual bool send(const char* msg, size_t len) = 0;

		virtual bool recvShortMsg(std::string& msg, unsigned int msMaxWait = 0) = 0;
		virtual bool recvLongMsg(char* buffer, size_t len) = 0;

		virtual std::string getIPAddr() = 0;
		virtual int getPort() = 0;

		virtual ~Connection() {}
	};

private:
	static bool connectionStartup();
	static void connectionShutdown();

	static std::vector<Connection*> connections;

	// Accessing the Experimenter
public:
	engine_export static Experimenter* getExperimenter(bool assert = false);

	// Main control
public:
	engine_export void run(ExperimentJob* job);
	engine_export void runMany(Array jobList);
private:
	bool canStartJob(ExperimentJob* job);
	bool runCore(ExperimentJob* job);
	void runNext();
public:
	engine_export void stop();

	engine_export TreeNode* getDBConnection();

	// this could be an applicationcommand
	// but since only the Experimenter uses it,
	// it's in this class.
	engine_export Variant SHA1(const Variant& value);

	double saveStateForEachReplication = 0;
	double saveStatisticsData = 0;
	double resetAfterEachReplication = 0;
	double useCloudNodes = 0;

private:
	std::atomic_bool stopping = false;
	std::atomic_uint nrAliveThreads = 0;
	double runID = 0;
	
private:
	void handleSeedByTime();
	int getBestNumCPUs(int jobEstimate);

engine_private:
	static Array createChildProcesses(int numCPUs, const char* token, int startPort = 9000);
	static void writePortsFile(Array ports);
private:
	bool createProxyChildren(Array cloudNodes);
	static Array parsePortsInProxyResponse(const char* response);

private:
	void createManagerThreads(const char* baseAddr, const char* token, Array ports);
	
	static bool createChildProcess(int port, const char* token, char compileDir);
	static bool handshake(Connection* con, const char* token, bool verifyOnly = false);

	static void s_finish(void* self);
	void finish();

	std::mutex allThreadMutex;
	std::mutex mainThreadMutex;
	std::condition_variable mainThreadCV;
	bool childProceed = false;
	
	void executeOnMainThread(std::function<void()>& callback);

	std::function<void()>* currentCallback = nullptr;
	static void s_executeOnMainThreadCallback(void* self);
	void executeOnMainThreadCallback();
	void postExecuteOnMainThreadMessage();

	// Experiment manager and child
	std::string dirMapStr;

	std::unique_ptr<char[]> projectBuffer;
	size_t projectBufferSize;
	void saveProjectBuffer();

	void manageChild(Connection* conn);

	struct TimeUpdateInfo
	{
		Experimenter* experimenter;
		unsigned int taskID;
		double progress;
	};

	Map timeUpdates;

	static void s_onTimeUpdate(void* timeChangeInfo);
	void onTimeUpdate(unsigned int taskID, double progress);

engine_private:
	static void runChildExperiment(int port, const char* token);
private:
	static Connection* waitForCompleteHandshake(Connection* listener, const char* token);
	static bool getDirectories(Connection* con);
	static bool getProjectBuffer(Connection* con, char*& projectBuffer);
	static void childStartup();
	static bool loadProjectTree(char* projectBuffer, bool doUnload);
	static void restoreOriginalState(char* projectBuffer);

	// Jobs and Tasks
public:
	NodeListArray<ExperimentJob>::SdtSubNodeBindingTypeOneBased jobs;

	void submitTask(Map task);
	void submitStopTask();

private:
	Array jobList;
	ObjRef<ExperimentJob> activeJob;

	std::mutex submitMutex;
	Array submitList;

	std::mutex executeMutex;
	std::condition_variable executeCV;
	Array executeList;
	Array executeJSONList;

	static void s_approveTasks(void* self);
	void approveTasks();
	void finishTask(Map task);

	static void s_addStopTask(void* self);
	void addStopTask();

	// Database File
public:
	TreeNode* dbNode;

private:
	Database::SQLiteConnection* __getDBConnection();

public:
	__declspec(property(get = __getDBConnection)) Database::SQLiteConnection* db;

private:
	int getActiveJobID();
	unsigned int initializeDatabase();
	Array approveTasksForDB(Array tasks);
	void recordResultsInDB(Map task, TreeNode* results);

public:
	// User callbacks
	TreeNode* onStartOfJob;
	TreeNode* onStartOfReplication;
	TreeNode* onEndOfWarmup;
	TreeNode* onEndOfReplication;
	TreeNode* onEndOfJob;

public:
	void onReplicationWarmup();

private:
	// functions called by the child process
	Map currentTask;
	void onReplicationReset();	
	void onReplicationComplete();

	// functions called by the parent process
	void onJobEnd();

	// functions to process the state file data from the child process
	void onStateFileChunkReceived(Map task, int chunkID, TreeNode* dataNode);

	// functions to process pfm/statistic data from the child process
	void onPFMsReceived(Map task, const char* treeBuffer);
	
	// ODT stuff
public:
	engine_export virtual void bindVariables() override;
	engine_export virtual void bindEvents() override;
	engine_export virtual TreeNode* getEventInfoObject(const char* eventTitle) override;
};

}

