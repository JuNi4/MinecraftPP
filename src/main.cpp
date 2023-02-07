#include <nlohmann/json.hpp>
#include <iostream>

//#include "options/options.hpp"
#include "options/keyCodes.hpp"
//#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    std::cout << LWJGEKeys::convertKey(30) << "\n";
    return 0;
}