//
// Created by pbarbeira on 24-06-2024.
//

#include "../include/repository.h"

std::vector<std::shared_ptr<ProjectData>> buffer_projectData;
std::vector<std::shared_ptr<TaskData>> buffer_taskData;

template<typename T>
void loadBuffer(std::vector<std::shared_ptr<T>> buffer, std::shared_ptr<TRepository<T>> repository){
    for(auto & i : buffer){
        int id = i->instanceId;
        repository->add(id, i);
    }
    buffer.clear();
}

void Repository::hydrate() {
    loadBuffer(buffer_projectData, projects);
    loadBuffer(buffer_taskData, tasks);
}