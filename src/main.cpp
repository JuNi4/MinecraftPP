#include <iostream>

#include <curl/curl.h>

#include <nlohmann/json.hpp>

#include <options/options.hpp>
//#include <getAssets/getAssets.hpp>
#include <comms/comms.h>
#include <sounds/sound.h>

#include <os.hpp>
#include <utils.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[]) {

    soundHandler x;

    if (argc < 2) { return 1; }

    x.setKey(argv[1]);

    x.play();

    return 0;
}