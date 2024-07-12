//
// Created by pbarbeira on 20-06-2024.
//

#ifndef TASKMAN_TABLE_DATA_H
#define TASKMAN_TABLE_DATA_H

#include <string>

static const std::string PROJECTS_TABLE = "projects";
static const std::string TASKS_TABLE = "tasks";

typedef struct TableData {
    int instanceId;
    std::string tableName;

    explicit TableData(std::string tableName, int instanceId):
            instanceId(instanceId), tableName(std::move(tableName)){};
} TableData;

typedef struct ProjectData : public TableData{
    std::string name;
    std::string course;

    explicit ProjectData(int instanceId):
        TableData(PROJECTS_TABLE, instanceId){};
} ProjectData;

typedef struct TaskData : public TableData{
    std::shared_ptr<ProjectData> projectData;
    std::string name;
    std::string description;
    long long due_by{};

    explicit TaskData(int instanceId):
        TableData(TASKS_TABLE, instanceId){};
} TaskData;


#endif //TASKMAN_TABLE_DATA_H
