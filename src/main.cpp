#include <nlohmann/json.hpp>
#include <iostream>

#include <optionsSingle.hpp>
//#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    options::deleteOptionsFile();
    options::createOptionsFile();
    std::cout << LWJGEKeys::convertKey(30) << "\n";
    return 0;
}