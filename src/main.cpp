// C++ Default Librarys
#include <iostream>

// Other Peoples Librarys
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Custom librarys
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

    // sound object
    sound x;

    // check if required arguements are present
    if (argc < 2) { return 1; }
    // optionally: set volume
    if (argc >= 3) { 
        std::string volume = argv[2];
        x.setVolume( std::stoi(volume) );
    }

    // loop indefinitly
    while (0) {
        // set the sound file
        x.setKey(argv[1]);
        // play the sound file
        x.play();
        // wait for the sound file to finish
        while (x.status() == sf::SoundSource::Status::Playing) {}
    }
    
    return 0;
}