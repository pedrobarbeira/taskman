#include <cmd-executor.h>
#include <server/server.h>
#include <test/test.h>
#define MIN_ARG 2

std::vector<std::string> tokenize(std::string str){
	std::vector<std::string> tokens;
    unsigned long last = 0;
	for(unsigned long i = 0; i < str.size(); i++){
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

int run_server(){
    auto server = Server::BuildServer(1337);
    try{
        server->listen();
    }catch(const std::exception& e){
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void run_shell(){
    auto repository = std::make_unique<Repository>();
    auto executor = std::make_unique<CmdExecutor>(std::move(repository));
	while(true){
		std::string userInput;
		std::cout << "$>> ";
		std::getline(std::cin, userInput);

		std::vector<std::string> tokens = tokenize(userInput);		

		std::string cmd = tokens[0];
		if(cmd == "exit"){
			break;
		}
	
		std::vector<std::string> args(++tokens.begin(), tokens.end());

		executor->runCmd(cmd, args);
	}
    repository = executor->getRepository();
}

int main(int argc, char* argv[]){

	if(argc == 1){
		run_shell();
		return 0;	
	}
	
	std::vector<std::string> args;

    if(std::string(argv[1]) == "server"){
        return run_server();
    }

    if(std::string(argv[1]) == "test"){
        return run_tests();
    }

	if(std::string(argv[1]) == "install"){
        db_install();
		return 0;
	}

	for(int i = 2; i < argc; i++){
		args.emplace_back(argv[i]);
	}

    auto repository = std::make_unique<Repository>();
    auto executor = std::make_unique<CmdExecutor>(std::move(repository));
	executor->runCmd(argv[1], args);

	return 0;
}

