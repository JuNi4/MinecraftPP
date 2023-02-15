#include "sound.h"
#include <fstream>
#include <utils.hpp>

json soundHandler::_setupSoundList() {
    // check if sounds.json exists
    if (! std::filesystem::is_regular_file("assets/resources/minecraft/sounds.json") ) {
        return json::parse(R"({"error": "sounds.json does not exist"})");
    }

    // load file
    std::fstream f ("assets/resources/minecraft/sounds.json");

    // get size of file
    int begin = f.tellg();
    f.seekg (0, std::ios::end);
    int end = f.tellg();
    f.seekg (0, std::ios::beg);

    int size = end-begin;

    // create a new char, containing the whole file
    char * fcontent = new char[size];

    f.read(fcontent, size);

    // close file
    f.close();

    json data = json::parse( fcontent );

    return data;

}

std::string soundHandler::_getFileFromKey(std::string key) {
    // check if sound data exists
    if ( this->_soundList[key] == nullptr ) { return ""; }
    // get sound data
    json soundData = this->_soundList[key];

    // check if sound data has files attached
    if ( soundData["sounds"] == nullptr && length(soundData["sounds"]) > 0 ) { return ""; }

    // generate a random number
    std::srand(time(NULL)); // set current time as seed
    int id = std::rand() % length(soundData["sounds"]);

    // Play the sound file
    std::string file = "";
    if ( soundData["sounds"][id].is_string() ) {
        file = soundData["sounds"][id];
    } else {
        file = soundData["sounds"][id]["name"];
    }
    return file;
}

soundHandler::soundHandler() {
    this->_soundList = this->_setupSoundList();
}

void soundHandler::setKey(std::string key) {
    this->_file = key;
}

int soundHandler::play() {
    // there is still a bug
    // get name of sound file
    std::string file = this->_getFileFromKey(this->_file);
    
    // check if file name is empty
    if (file == "") { return 1; }

    // un "nest" sound files
    bool done = false;

    // get index of file name in sound list
    try {
        unsigned int index = _soundList.at(file); // this is causing a type error sometimes, at least with the key music.creative
    } catch (nlohmann::json_abi_v3_11_2::detail::out_of_range) {
        done = true;
    }

    while ( !done ) {
        // get new file name/path
        file = this->_getFileFromKey(file);
        // set new size and index values
        try {
            unsigned int index = _soundList.at(file);
        } catch (nlohmann::json_abi_v3_11_2::detail::out_of_range) {
            done = true;
        }
    }
    
    // construct the path to the file
    std::string path = "celluloid assets/resources/minecraft/sounds/"+ file +".ogg";
    // implement a proper play method
    system(path.c_str());
    return 0;
}

void soundHandler::reloadSoundList() {
    this->_soundList = this->_setupSoundList();
}