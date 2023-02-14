#include <iostream>

#include <curl/curl.h>

#include <nlohmann/json.hpp>

#include <options/options.hpp>
//#include <getAssets/getAssets.hpp>
#include <comms/comms.h>

#include <os.hpp>
#include <utils.hpp>

using json = nlohmann::json;

int main() {
    server stest;
    std::cout << stest.status() << std::endl;
    return 0;
}