#include <nlohmann/json.hpp>
#include <options.hpp>
#include <iostream>

#include <getAssets/getAssets.cpp>

using json = nlohmann::json;

int main() {

    setOption("title", "lol");

    json opt = getOptions(); // load options file
    std::cout << opt.dump(4) << std::endl;

    return 0;
}