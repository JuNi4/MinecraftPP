#include <nlohmann/json.hpp>
#include <iostream>

#include <options/options.hpp>
#include <options/keyCodes.hpp>
//#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    deleteOptionsFile();
    std::cout << convertKey(30) << "\n";
    return 0;
}