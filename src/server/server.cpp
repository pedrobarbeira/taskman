//
// Created by pbarbeira on 20-06-2024.
//

#include "../../include/server/server.h"

std::unique_ptr<Server> Server::BuildServer(int port){
    return std::unique_ptr<Server>(new Server(port));
}

void Server::listen() {
    std::cout << "Listening on port " << this->port << '\n';
    std::unique_ptr<Socket> socket = std::make_unique<Socket>(this->port);
    while(true){
        try{
            std::string cmdStr = socket->getRequestStr();
            //parse String
            std::vector<std::string> params;
            std::vector<std::string> args(params.begin() + 1, params.end());
            executor->runCmd(params[0], args);
        }catch(const std::exception& e){
            std::cout << e.what() << '\n';
        }
    }
}

#include "../../include/server/server.h"
