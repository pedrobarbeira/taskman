#ifndef _SCHEMAS_H
#define _SCHEMAS_H

#include <sstream>

class TableSchema{
private:
	int instanceId;
	std::string tableName;
public:
	explicit TableSchema(std::string tableName, int instanceId):
		tableName(tableName), instanceId(instanceId){};

	virtual ~TableSchema(){};
	
	virtual std::string addStmt() = 0;
	virtual std::string selectStmt() = 0;
	virtual std::string updateStmt() = 0;
	virtual	std::string deleteStmt();
};

class TaskSchema : public TableSchema{
public:
	~TaskSchema(){};

	std::string addStmt() override;
	std::string selectStmt() override;
	std::string updateStmt() override;
};

class ProjectSchema : public TableSchema{
private:
	std::string name;
	std::string course;
	
public:	
	
	explicit ProjectSchema(int id):
		TableSchema("projects", id), name(""), course(""){};
	
	explicit ProjectSchema(std::string name, std::string course):
		TableSchema("projects", 0), name(name), course(course){};
	
	explicit ProjectSchema(int id, std::string name, std::string course):
		TableSchema("projects", id), name(name), course(course){};

	~ProjectSchema(){};

	std::string addStmt() override;
	std::string selectStmt() override;
	std::string updateStmt() override;
};

#endif //_SCHEMAS_H_
