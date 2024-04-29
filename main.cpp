#include <cmd-executor.h>
#include <string.h>

#define MIN_ARG 2

std::vector<std::string> tokenize(std::string str){
	std::vector<std::string> tokens;
	int last = 0;
	for(int i = 0; i < str.size(); i++){
		if(i == str.size() - 1){
			tokens.push_back(str.substr(last));
			break;
		}
		if(str[i] == ' '){
			tokens.push_back(str.substr(last, i-last));
			last = i + 1;
		}
	}
	return tokens;
}

void run_shell(){
	while(1){
		std::string userInput;
		std::cout << "$>> ";
		std::getline(std::cin, userInput);

		std::vector<std::string> tokens = tokenize(userInput);		

		std::string cmd = tokens[0];
		if(cmd == "exit"){
			return;
		}
	
		std::vector<std::string> args(++tokens.begin(), tokens.end());

		CmdExecutor::runCmd(cmd, args);
	}
}

int main(int argc, char* argv[]){
	if(argc == 1){
		run_shell();
		return 0;	
	}
	
	std::vector<std::string> args;

	if(std::string(argv[1]) == "install"){
		installCmd();
		return 0;
	}

	for(int i = 2; i < argc; i++){
		args.push_back(argv[i]);
	}	
	
	CmdExecutor::runCmd(argv[1], args);

	return 0;
}

