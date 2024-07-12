//
// Created by pbarbeira on 20-06-2024.
//

#include "../../include/schema/schema-project.h"

std::unique_ptr<Schema> ProjectSchema::Build(int id, std::string name, std::string course){
    auto schema = std::unique_ptr<ProjectSchema>( new ProjectSchema());
    schema->tableData->instanceId = id;
    schema->tableData->name = std::move(name);
    schema->tableData->course = std::move(course);
    return schema;
}

stmtData_t ProjectSchema::addStmt(){
    std::stringstream ss;
    ss << "insert into projects(name, course) values('"
       << this->tableData->name << "', '" << this->tableData->course
       << "');";
    return buildStmtData(ss.str(), nullptr, nullptr);
}

stmtData_t ProjectSchema::selectStmt() {
    std::stringstream ss;
    ss << "select * from " << this->tableData->tableName
        << (this->tableData->instanceId != -1 ? " where id = " + std::to_string(this->tableData->instanceId) : "")
        << ";";
    return buildStmtData(ss.str(), ProjectSchema::callback, (void*) "Select statement");
}

int ProjectSchema::callback(void* data, int argc, char** argv, char** colName){
    std::vector<std::string> params;
    params.reserve(argc);
    for(int i = 0; i < argc; i++){
        params.emplace_back(argv[i] ? argv[i] : "");
    }
    std::unique_ptr<Schema> schema = ProjectSchema::Build(std::stoi(params[0]), params[1], params[2]);
    auto projectSchema = (ProjectSchema*) schema.get();
    std::unique_ptr<ProjectData> projectData = std::move(projectSchema->tableData);
    buffer_projectData.push_back(std::move(projectData));
    return 0;
}

stmtData_t ProjectSchema::updateStmt() {
    std::stringstream ss;
        ss << "update " << this->tableData->tableName
       << " set " << (this->hasName() ? "name = \'" + this->tableData->name + "\'" : "")
                << ((this->hasName() && this->hasCourse()) ? ", " : "")
                << (this->hasCourse() ? "course = \'" + this->tableData->course + "\'" : "")
       << " where id=" << this->tableData->instanceId << ';';
    return buildStmtData(ss.str(), nullptr, nullptr);
}

stmtData_t ProjectSchema::deleteStmt() {
    std::stringstream ss;
    ss << "delete from " << tableData->tableName <<
       " where id = " << tableData->instanceId << ";";
    return buildStmtData(ss.str(), nullptr, nullptr);
}