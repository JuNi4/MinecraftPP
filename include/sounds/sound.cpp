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

soundHandler::soundHandler() {
    this->_soundList = this->_setupSoundList();
}

void soundHandler::setKey(std::string key) {
    this->_file = key;
}

int soundHandler::play() {
    // check if sound data exists
    if ( this->_soundList[this->_file] == nullptr ) { return 1; }
    // get sound data
    json soundData = this->_soundList[this->_file];

    // check if sound data has files attached
    if ( soundData["sounds"] == nullptr && length(soundData["sounds"]) > 0 ) { return 1; }

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
    
    std::string path = "celluloid assets/resources/minecraft/sounds/"+ file +".ogg";
    // implement a proper play method
    system(path.c_str());
    return 0;
}

void soundHandler::reloadSoundList() {
    this->_soundList = this->_setupSoundList();
}