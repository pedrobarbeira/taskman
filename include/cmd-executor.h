#ifndef CMD_EXECUTOR_H
#define CMD_EXECUTOR_H

#include "schema-builder.h"
#include <string>
#include <utility>

class CmdExecutor{
private:
    std::unique_ptr<Repository> repository;

    static void run(const stmtData_t& stmtData);
    void readBuffers();
public:
    explicit CmdExecutor(std::unique_ptr<Repository> repository):
        repository(std::move(repository)){};

    void runCmd(const std::string& cmdStr, std::vector<std::string> args);

    std::unique_ptr<Repository> getRepository(){
        return std::move(repository);
    }
};

int projectSchema_callback(void*, int, char**, char**);

#endif //CMD_EXECUTOR_H
