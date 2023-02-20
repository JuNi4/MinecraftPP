/**
 * @file comms.h
 * @author JuNi
 * @brief WIP Server communication library
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <nlohmann/json.hpp>

#ifndef _COMMS_H_
#define _COMMS_H_

using json = nlohmann::json;

class server {
    private:
        /**
         * @brief Packs anything to bytes to be send to a socket
         * 
         */
        std::vector<uint8_t> _pack(std::string pack);
    public:

    std::string ip;
    int port;

    /**
     * @brief Construct a new server object
     * 
     * @param ip The ip of the server
     * @param port The port of the server
     */
    server(std::string ip = "127.0.0.1", int port = 25565);

    /**
     * @brief Gets the status of a minecraft server.
     * 
     * @return json The status report from the server.
     */
    json status();
};

#endif