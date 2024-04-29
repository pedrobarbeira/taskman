#include "cmd-executor.h"

void CmdExecutor::runCmd(std::string cmd, std::vector<std::string> args){
	Command cmdFunction = fTable[cmd];
	if(cmdFunction){
		std::unique_ptr<TableSchema> schema = SchemaBuilder::build(args);
		if(schema != nullptr){	
			cmdFunction(std::move(schema));
		}
		return;
	}
	std::cout << "No build function was found\n";
}
