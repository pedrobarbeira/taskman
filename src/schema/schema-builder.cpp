#include "include/schema-builder.h"

std::unique_ptr<Schema> SchemaBuilder::build(std::vector<std::string> args){
	if(!args.empty()){
        std::string table = args[0];
        buildFunction buildFunction = buildMap[table];
        if(nullptr != buildFunction){
            std::vector<std::string> params(args.begin() + 1, args.end());
            return buildFunction(params);
        }
    }
    return nullptr;
}

std::unique_ptr<Schema> buildProject(const std::vector<std::string>& params){
    int id = NO_ID;
    std::string name;
    std::string course;
    for(const auto& param : params){
        std::string paramValue = getParamValue(param);
        if(param.find("id") != std::string::npos){
            if(id == NO_ID) id = std::stoi(paramValue);
            else return nullptr;
        }
        else if(param.find("name") != std::string::npos){
            if(name.empty()) name = std::move(paramValue);
            else return nullptr;
        }
        else if(param.find("course") != std::string::npos){
            if(course.empty()) course = std::move(paramValue);
            else return nullptr;
        }
    }
    return ProjectSchema::Build(id, name, course);
}

std::unique_ptr<Schema> buildTask(const std::vector<std::string>& params){
    return nullptr;
}

