#include <nlohmann/json.hpp>
#include <options.hpp>
#include <iostream>

#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {
    //json opt = getOptions(); // load options file
    //std::cout << opt.dump(4) << std::endl;

    //getAssets("1.19.3", "assets/");
    getResources("1.19.3", "assets/");

    return 0;
}