#include <vector>
#include <cmd-executor.h>

#define MIN_ARG 2

int main(int argc, char* argv[]){
	std::vector<std::string> args;

	if(std::string(argv[1]) == "install"){
		installCmd();
		return 0;
	}

	for(int i = 2; i < argc; i++){
		args.push_back(argv[i]);
	}	
	
	CmdExecutor executor = CmdExecutor();
	executor.runCmd(argv[1], args);

	return 0;
}

