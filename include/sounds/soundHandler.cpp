#include "soundHandler.h"

// sound handler constructor
soundHandler::soundHandler() {}

void soundHandler::player(int id, std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // create a sound object
    sound sfx;

    // set key
    sfx.setKey(soundId);

    // set up pitch
    sfx.setPitch(pitch);

    // set 3D audio
    sfx.enable3DAudio(enable3D);

    // play sound
    sfx.play();

    // check if id is forced to stop
    bool done = false;
    try {
        this->stop.at(id);
        done = true;
    } catch (std::out_of_range) {}

    // keep sound alive
    while (sfx.status() == sf::SoundSource::Status::Playing && ! done ) {
        // if 3d sound is enabled, set the sound position
        if (enable3D) {
            sfx.pos = pos - this->playerPos;
        }
        // calculate the volume
        float mv = (float) (this->_masterVolume) / 100.f;
        float muv = (float) (this->_musicVolume) / 100.f;
        // set the volume
        sfx.setVolume(mv*muv*100);
        
        // check if id is in stop list
        try {
            this->stop.at(id);
            done = true;
        } catch (std::out_of_range) {}
    }

    // remove id from stop
    try {
        this->stop.at(id);
        this->stop.erase(std::next(this->stop.begin(), this->stop.at(id)));
    } catch (std::out_of_range) {}

    // remove id from running
    this->running.erase(std::next(this->running.begin(), this->running.at(id)));

}

int soundHandler::getId() {
    // Increment the last id counter
    this->_lastId++;

    // if id is bigger than allowed, reset id counter
    if (this->_lastId > 255) {
        this->_lastId = 0;
    }

    // check if id already exists
    bool done = false;

    try {
        this->running.at(this->_lastId);
        done = true;
    } catch (std::out_of_range) {}

    // if id already exists, check the next on
    while ( done && this->_lastId <= 256 ) {
        // increment id counter
        this->_lastId++;
        // chekc if this id is free
        try {
            this->running.at(this->_lastId);
            done = true;
        } catch (std::out_of_range) {}
    }

    // if the id counter exceeds 255, it will return a -1 as an error
    if (_lastId == 256) {
        this->_lastId = 0;
        return -1;
    }

    // add id to running
    this->running.push_back(this->_lastId);
    // return ID
    return this->_lastId;
}

void soundHandler::call(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // get a free ID
    this->id = getId();
    // Play sound
    this->player(id, soundId, pitch, enable3D, pos);
}