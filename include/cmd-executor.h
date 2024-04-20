#ifndef _CMD_EXECUTOR_H
#define _CMD_EXECUTOR_H

#include "sql-cmd.h"

typedef void (*Command)(std::unique_ptr<TableSchema> schema);

class CmdExecutor{
	private:	
		std::map<std::string, Command> fTable;
	public:	
		CmdExecutor();
		void runCmd(std::string cmdStr, std::vector<std::string> args);
};

#endif //_CMD_EXECUTOR_H_
