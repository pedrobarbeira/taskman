//
// Created by pbarbeira on 20-06-2024.
//

#ifndef TASKMAN_SOCKET_H
#define TASKMAN_SOCKET_H

#include <string>

class Socket{
private:
    int port;
public:
    explicit Socket(int port):
        port(port){};

    std::string getRequestStr();
};

#endif //TASKMAN_SOCKET_H
