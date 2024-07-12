#ifndef TASKMAN_SCHEMA_PROJECT_H
#define TASKMAN_SCHEMA_PROJECT_H

#include <utility>
#include "schema.h"
#include "../model/table-data.h"

class ProjectSchema : public Schema{
private:
    stmtData_t addStmt() override;
    stmtData_t selectStmt() override;
    stmtData_t updateStmt() override;
    stmtData_t deleteStmt() override;

    inline bool hasName() const{ return !this->tableData->name.empty(); }
    inline bool hasCourse() const{ return !this->tableData->course.empty(); }

    static int callback(void* data, int argc, char** argv, char** colName);

    explicit ProjectSchema():
            tableData(std::make_unique<ProjectData>(-1)){};
public:
    std::unique_ptr<ProjectData> tableData;

    static std::unique_ptr<Schema> Build(int id, std::string name, std::string course);

    int getId() const override{
        return tableData->instanceId;
    }

    std::string getTable() const override{
        return tableData->tableName;
    };

    ~ProjectSchema() override= default;
};

#endif //TASKMAN_SCHEMA_PROJECT_H
