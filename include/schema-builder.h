#ifndef _SCHEMA_BUILDER_H
#define _SCHEMA_BUILDER_H

#include <vector>
#include <map>
#include "schemas.h"
#include <memory>
#include <string>

#define TASK "task"
#define PROJECT "project"

typedef std::unique_ptr<TableSchema> (*BuildFunction)(std::vector<std::string> params);

class SchemaBuilder{
public:
	static std::unique_ptr<TableSchema> build(std::vector<std::string> args); 
};

std::unique_ptr<TableSchema> buildTask(std::vector<std::string>);
std::unique_ptr<TableSchema> buildProject(std::vector<std::string>);


#endif //_SCHEMA_BUILDER_H_
