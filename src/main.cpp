#include <nlohmann/json.hpp>
#include <iostream>

#include <options/options.hpp>
//#include <getAssets/getAssets.hpp>
#include <comms/comm.h>

using json = nlohmann::json;

int main() {
    server stest;
    std::cout << stest.ip << std::endl;
    std::cout << stest.status()["error"] << std::endl;
    return 0;
}