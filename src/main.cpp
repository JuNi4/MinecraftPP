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

int main() {

    soundHandler x;

    x.setKey("entity.skeleton_horse.step_water");

    x.play();

    return 0;
}