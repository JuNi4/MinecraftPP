#include "comm.h"

server::server(std::string ip, int port) {
    this->ip = ip;
    this->port = port;
}

json server::status() {
    return json::parse(R"({"error": "task sucsessfully failed!"})");
}