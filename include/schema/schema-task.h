//
// Created by pbarbeira on 20-06-2024.
//

#ifndef TASKMAN_SCHEMA_TASK_H
#define TASKMAN_SCHEMA_TASK_H

#include "schema.h"
#include "../model/table-data.h"

#define CHECK "check"

class TaskSchema : public Schema{
private:
    stmtData_t addStmt() override;
    stmtData_t selectStmt() override;
    stmtData_t updateStmt() override;
    stmtData_t deleteStmt() override;

    static int callback(void* data, int argc, char** argv, char** colName);

    explicit TaskSchema():
            tableData(std::make_unique<TaskData>(-1)){};
public:
    std::unique_ptr<TaskData> tableData;

    static std::unique_ptr<TaskSchema> Build(int id, const std::shared_ptr<ProjectData>& projectData, std::string name, std::string description, int due_bye);

    int getId() const override{
        return tableData->instanceId;
    }

    std::string getTable() const override{
        return tableData->tableName;
    };
};

#endif //TASKMAN_SCHEMA_TASK_H
