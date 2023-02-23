#include "comms.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstddef>
#include <cstring>

// constructor of server object
server::server(std::string ip, int port) {
    this->ip = ip;
    this->port = port;
}

std::vector<uint8_t> server::_pack_variant(auto data) {
}

std::vector<uint8_t> server::_pack_data(auto data) {
}

// get the status of a server
json server::status() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Error creating socket\n";
        return json::parse(R"({"error": "task sucsessfully failed!"})");
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(this->ip.c_str());
    servaddr.sin_port = htons(this->port);

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) == -1) {
        std::cerr << "Error connecting to server\n";
        return json::parse(R"({"error": "task sucsessfully failed!"})");
    }

    const char* data = "\x00\x00\t127.0.0.1\t25565\x01";

    std::cout << data << std::endl;

    // Send byte array over socket
    int num_bytes = send(sockfd, data, sizeof(data), 0);
    if (num_bytes == -1) {
        std::cerr << "Error sending data\n";
        return 1;
    }

    const int MAX_BUFFER_SIZE = 1024;
    char buffer[MAX_BUFFER_SIZE];
    num_bytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (num_bytes == -1) {
        std::cerr << "Error receiving data\n";
        return json::parse(R"({"error": "task sucsessfully failed!"})");
    }

    // Process received data
    std::cout << "Received " << num_bytes << " bytes: " << buffer << "\n";

    return json::parse(R"({"error": "task sucsessfully failed!"})");
}