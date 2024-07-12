//
// Created by pbarbeira on 20-06-2024.
//

#include "../../include/schema/schema-task.h"
#include <iostream>

std::unique_ptr<TaskSchema> TaskSchema::Build(int id, const std::shared_ptr<ProjectData>& projectData, std::string name, std::string description, int due_bye) {
    auto taskSchema = std::unique_ptr<TaskSchema>(new TaskSchema);
    taskSchema->tableData->instanceId = id;
    taskSchema->tableData->projectData = projectData;
    taskSchema->tableData->name = std::move(name);
    taskSchema->tableData->description = std::move(description);
    taskSchema->tableData->due_by = due_bye;
    return taskSchema;
}

stmtData_t TaskSchema::addStmt(){

}

int TaskSchema::callback(void* data, int argc, char** argv, char** colName){
    for(int i = 0 ; i < argc; i++){
        std::cout << argv[i] << " " << colName[i];
    }
}

stmtData_t TaskSchema::selectStmt() {
    std::stringstream ss;
    ss << "select * from " << this->tableData->tableName
       << (this->tableData->instanceId != -1 ? " where id = " + std::to_string(this->tableData->instanceId) : "")
       << ";";
    return buildStmtData(ss.str(), TaskSchema::callback, (void*) "Select statement");
}

stmtData_t TaskSchema::updateStmt() {

    return buildStmtData("", nullptr, nullptr);
}

stmtData_t TaskSchema::deleteStmt() {
    std::stringstream ss;
    ss << "delete from " << tableData->tableName <<
       " where id = " << tableData->instanceId << ";";
    return buildStmtData(ss.str(), nullptr, nullptr);
}
