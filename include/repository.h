//
// Created by pbarbeira on 20-06-2024.
//

#ifndef TASKMAN_REPOSITORY_H
#define TASKMAN_REPOSITORY_H

#include <unordered_map>
#include <memory>
#include <vector>
#include <iostream>
#include "model/table-data.h"

extern std::vector<std::shared_ptr<ProjectData>> buffer_projectData;
extern std::vector<std::shared_ptr<TaskData>> buffer_taskData;

template<typename T>
class TRepository{
private:
    std::unordered_map<int, std::shared_ptr<T>> cache;
public:
    TRepository(){
        cache.clear();
    }
    std::shared_ptr<T> getById(int id) {
        if(cache.find(id) != cache.end()){
            return cache[id];
        }
        return nullptr;
    };

    void add(int id, std::shared_ptr<T> data) {
        cache[id] = data;
    };

    void remove(int id){
        return this->projects;
    };

    int size(){
        return cache.size();
    }
};

class Repository{
private:
    std::shared_ptr<TRepository<ProjectData>> projects;
    std::shared_ptr<TRepository<TaskData>> tasks;
public:
    explicit Repository(){
        projects = std::make_shared<TRepository<ProjectData>>();
        tasks = std::make_shared<TRepository<TaskData>>();
    }

    void print(){
        std::cout << projects->getById(12)->tableName << std::endl;
    }

    void hydrate();
};

#endif //TASKMAN_REPOSITORY_H
