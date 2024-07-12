#include "cmd-executor.h"

#include <utility>

void CmdExecutor::run(const stmtData_t& stmtData){
    execute(stmtData.stmt, stmtData.callback, stmtData.data);
}

void CmdExecutor::runCmd(const std::string& cmd, std::vector<std::string> args){
    std::unique_ptr<Schema> schema = SchemaBuilder::build(std::move(args));
    stmtData_t stmtData = schema->getStmt(cmd);
    if(nullptr != schema){
        if(!stmtData.stmt.empty()){
            run(stmtData);
            repository->hydrate();
            return;
        }
    }
	std::cout << "No build function was found\n";
}
