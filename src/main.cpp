#include <nlohmann/json.hpp>
#include <options.hpp>
#include <iostream>

#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    deleteOptionsFile();
    createOptionsFile();
    return 0;
}