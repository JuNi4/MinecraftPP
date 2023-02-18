#include "soundHandler.h"

/**
 * @brief Checks if a vector has a target avlue
 * 
 * @param arr The std::vector
 * @param value The value to look for
 * @return true Enemy spottet
 * @return false Has not been found
 */
bool hasI(std::vector<int> arr, int value) {
    for (long unsigned i = 0; i < arr.size(); i++) {
        if (arr[i] == value) { return true; }
    }
    return false;
}


// sound handler constructor
soundHandler::soundHandler() {}

// the sound player script that play a sound
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
    bool done = hasI(this->stop, id);

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
        done = hasI(this->stop, id);
    }

    // remove id from stop
    if (done == hasI(this->stop, id)) {
        this->stop.erase(std::next(this->stop.begin(), this->stop.at(id)));
    }

    // remove id from running
    this->running.erase(std::next(this->running.begin(), this->running.at(id)));

}

int soundHandler::getId() {
    // Set counter to zero
    this->_lastId = 0;

    // check if id already exists
    bool done = hasI(this->running, this->_lastId);

    // if id already exists, check the next on
    while ( done && this->_lastId <= 256 ) {
        // increment id counter
        this->_lastId++;
        // chekc if this id is free
        done = hasI(this->running, this->_lastId);
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

int soundHandler::play(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // get a free ID
    this->id = getId();
    // make sure id is not -1
    if (this->id == -1) { return -1; }
    // Play sound
    //this->player(id, soundId, pitch, enable3D, pos);
    auto x = std::async(std::launch::async, &soundHandler::player, this, this->id, soundId, pitch, enable3D, pos);

    return this->id;
}