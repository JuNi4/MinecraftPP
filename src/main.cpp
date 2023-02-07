#include <nlohmann/json.hpp>
#include <iostream>

#include "options/options.hpp"
//#include <options/keyCodes.cpp>
//#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    options::deleteOptionsFile();
    options::importConfig();
    std::cout << LWJGEKeys::convertKey(30) << "\n";
    return 0;
}