#include "cmd-executor.h"

#define ADD "add"
#define REMOVE "rm"
#define UPDATE "update"
#define VIEW "view"
#define CHECK "check"
#define UNCHECK "uncheck"

CmdExecutor::CmdExecutor(){
	fTable[ADD] = &addCmd;
	fTable[UPDATE] = &updateCmd;
	fTable[REMOVE] = &removeCmd;
	fTable[VIEW] = &viewCmd;
	fTable[CHECK] = &checkCmd;
	fTable[UNCHECK] = &uncheckCmd;
}

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
