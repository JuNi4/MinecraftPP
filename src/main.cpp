#include <nlohmann/json.hpp>
#include <iostream>

#include <options/options.hpp>
#include <getAssets/getAssets.hpp>

using json = nlohmann::json;

int main() {
    getAssets("1.19.3");
    return 0;
}