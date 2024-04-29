#ifndef _CMD_EXECUTOR_H
#define _CMD_EXECUTOR_H

#include "sql-cmd.h"

#define ADD "add"
#define REMOVE "rm"
#define UPDATE "update"
#define LIST "list"
#define CHECK "check"
#define UNCHECK "uncheck"

typedef void (*Command)(std::unique_ptr<TableSchema> schema);

class CmdExecutor{
	private:	
		static inline std::map<std::string, Command> fTable = {
			{ ADD, &addCmd },
			{ REMOVE, &removeCmd },
			{ UPDATE, &updateCmd },
			{ LIST, &listCmd },
			{ CHECK, &checkCmd },
			{ UNCHECK, &uncheckCmd}
		};
	public:	
		static void runCmd(std::string cmdStr, std::vector<std::string> args);
};

#endif //_CMD_EXECUTOR_H_
