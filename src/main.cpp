#include <nlohmann/json.hpp>
#include <iostream>

#include <getAssets/getAssets.cpp>
#include <options/options.cpp>
//#include <options/keyCodes.cpp>
//#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    options::deleteOptionsFile();
    options::importConfig();
    std::cout << LWJGEKeys::convertKey(30) << "\n";
    return 0;
}