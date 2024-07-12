#ifndef SCHEMA_BUILDER_H
#define SCHEMA_BUILDER_H

#include "data-access.h"
#include "schema/schema-project.h"
#include "schema/schema-task.h"

#define PROJECT "project"
#define TASK "task"

typedef std::function<std::unique_ptr<Schema>(const std::vector<std::string>& params)> buildFunction;

std::unique_ptr<Schema> buildProject(const std::vector<std::string>& params);
std::unique_ptr<Schema> buildTask(const std::vector<std::string>&);

class SchemaBuilder{
private:
    static inline std::unordered_map<std::string, buildFunction> buildMap = {
            { TASK, buildTask },
            { PROJECT, buildProject }
    };
public:
	static std::unique_ptr<Schema> build(std::vector<std::string> args);
};

#endif //SCHEMA_BUILDER_H
