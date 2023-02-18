// C++ Default Librarys
#include <iostream>

// Other Peoples Librarys
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Custom librarys
#include <options/options.hpp>
#include <getAssets/getAssets.hpp>
#include <comms/comms.h>
#include <sounds/v2/soundHandler.h>

#include <os.hpp>
#include <utils.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[]) {

    // get a sound id from arguments
    std::string key;

    if (argc < 2) { 
        key = "music.creative";
    } else {
        key = argv[1];
    }

    // create sound handler object
    soundHandlerv2 x;

    // play id from arguments
    std::cout << x.play(key, 1.f, true, sf::Vector3f(-10.f, 0.f, 0.f)) << "\n";

    x.playerPos = sf::Vector3f(0.f,0.f,0.f);

    x.updateAll();

    // wait, so the sound does not stop
    while (x.sounds[x.id].status() == sf::SoundSource::Status::Playing) {}

    return 0;
}