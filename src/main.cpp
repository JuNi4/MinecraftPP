#include <iostream>

#include <curl/curl.h>

#include <nlohmann/json.hpp>

#include <options/options.hpp>
#include <getAssets/getAssets.hpp>
#include <comms/comms.h>
#include <sounds/sound.h>

#include <os.hpp>
#include <utils.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[]) {

    // check if assets folder exists
    if (!std::filesystem::is_directory("assets")) {
        std::filesystem::create_directory("assets");
    }
    // check if assets and resources are present
    if (!std::filesystem::is_directory("assets/minecraft")) {
        getAssets("1.19.3");
    }
    if (!std::filesystem::is_directory("assets/resources")) {
        getResources("1.19.3");
    }

    soundHandler x;

    if (argc < 2) { return 1; }

    x.setKey(argv[1]);

    x.play();

    return 0;
}