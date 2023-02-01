#include <nlohmann/json.hpp>
#include "data/options.hpp"
#include <iostream>

using json = nlohmann::json;

int main() {
    json opt = getOptions(); // load options file
    std::cout << opt.dump(4) << std::endl;
    return 0;
}