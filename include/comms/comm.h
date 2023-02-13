#include <iostream>
#include <nlohmann/json.hpp>

#ifndef _COMMS_H_
#define _COMMS_H_

using json = nlohmann::json;

class server {
    public:

    std::string ip;
    int port;

    /**
     * @brief Construct a new server object
     * 
     * @param ip The ip of the server
     * @param port The port of the server
     */
    server(std::string ip = "localhost", int port = 25565);

    /**
     * @brief Gets the status of a minecraft server.
     * 
     * @return json The status report from the server.
     */
    json status();
};

#endif