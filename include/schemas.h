#ifndef _SCHEMAS_H
#define _SCHEMAS_H

#include <sstream>

class TableSchema{
public:
	virtual std::string addStmt() = 0;
};

class TaskSchema : public TableSchema{
public:
	std::string addStmt() override;
};

class ProjectSchema : public TableSchema{
public:
	int id;
	std::string name;
	std::string course;

	explicit ProjectSchema(std::string name = "", std::string course = ""):
		id(0), name(name), course(course){};

	explicit ProjectSchema(int id = 0, std::string name = "", std::string course = ""):
		id(id), name(name), course(course){};

	std::string addStmt() override;
};

#endif //_SCHEMAS_H_
