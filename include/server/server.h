//
// Created by pbarbeira on 20-06-2024.
//

#ifndef TASKMAN_SERVER_H
#define TASKMAN_SERVER_H

#include "../cmd-executor.h"
#include "socket.h"
#include <iostream>
#include <vector>

class Server {
    int port;
    std::unique_ptr<Repository> repository;
    std::unique_ptr<CmdExecutor> executor;

    explicit Server(int port):
            port(port),
            repository(std::make_unique<Repository>()),
            executor(std::make_unique<CmdExecutor>(std::move(repository))){};
public:
    static std::unique_ptr<Server> BuildServer(int port);

    void listen();

};


#endif //TASKMAN_SERVER_H
