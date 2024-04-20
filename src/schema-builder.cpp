#include "schema-builder.h"
#include <iostream>

std::map<std::string, BuildFunction> buildMap = {
	{ TASK, buildTask },
	{ PROJECT, buildProject }
};

std::unique_ptr<TableSchema> buildTask(std::vector<std::string> params){
	return nullptr;	
}

std::unique_ptr<TableSchema> buildProject(std::vector<std::string> params){
	return std::make_unique<ProjectSchema>(params[0], params[1]);
}

std::unique_ptr<TableSchema> SchemaBuilder::build(std::vector<std::string> args){
	if(args.empty()){
		return nullptr;
	}	
	std::string type = args[0];
	BuildFunction buildFunction = buildMap[type];
	if(!buildFunction){
		return nullptr;
	}
	std::vector<std::string> params(args.begin() + 1, args.end());
	return buildFunction(params);
}
