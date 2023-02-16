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
    // setup sound list
    this->_soundList = this->_setupSoundList();
    // setup sound position
    sf::Vector3f v1(0.0f, 0.0f, 0.0f);
    this->pos = v1;
    this->_sound.setPosition(v1);
}

void soundHandler::setKey(std::string key) {
    // set the sound key
    this->_file = key;
}

void soundHandler::setVolume(int volume) {
    // set the volume
    this->_sound.setVolume(volume);
}

void soundHandler::setPitch(float pitch) {
    this->_sound.setPitch(pitch);
}

void soundHandler::setPosition(float x, float y, float z) {
    // Create a new vector with the specified position
    sf::Vector3f v1(x, y, z);
    // replace the old position
    this->pos = v1;
    this->_sound.setPosition(v1);

    // set sound mode to relative
    this->_sound.setRelativeToListener(true);
}

void soundHandler::enable3DAudio(bool enable) {
    // enable/disable 3D audio
    this->_sound.setRelativeToListener(enable);
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
    if (this->_soundList[file] == nullptr) {
        done = true;
    }

    while ( !done ) {
        // get new file name/path
        file = this->_getFileFromKey(file);
        // set new size and index values
        if (this->_soundList[file] == nullptr) { done = true; }
    }
    
    // construct the path to the file
    std::string path = "assets/resources/minecraft/sounds/"+ file +".ogg";
    // implement a proper play method
    //system(path.c_str());
    std::cout << path << std::endl;
    // Open it from an audio file
    if (! this->_sound.openFromFile(path) )
    {
        return 1;
    }

    this->_sound.play();

    return 0;
}

void soundHandler::pause() {
    this->_sound.pause();
}

void soundHandler::resume() {
    if (this->_sound.getStatus() == sf::SoundSource::Status::Paused) {
        this->_sound.play();
    }
}

void soundHandler::stop() {
    this->_sound.stop();
}

/*
void soundHandler::destroy() {
    this->stop();
    this->_sound.c
}
*/

sf::SoundSource::Status soundHandler::status() {
    return this->_sound.getStatus();
}

void soundHandler::reloadSoundList() {
    this->_soundList = this->_setupSoundList();
}