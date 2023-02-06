#include <nlohmann/json.hpp>
#include <options.hpp>
#include <iostream>

#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    deleteOptionsFile();
    deleteOptionsFile("data/keyBinds.txt");
    importConfig();
    return 0;
}