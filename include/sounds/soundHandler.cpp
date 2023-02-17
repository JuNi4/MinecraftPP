#include "soundHandler.h"
#include <future>

soundHandler::soundHandler() {}

void soundHandler::_player(int id, std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
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

    // keep sound alive
    while (sfx.status() = sf::SoundSource::Status::Playing && this->stop.at(id) > this->stop.size() ) {
        if (enable3D) {
            sfx.pos = pos - this->_playerPos;
        }
        float vol = this->_masterVolume/100 * this->_musicVolume/100;
        sfx.setVolume(vol);
    }

    // remove id from stop
    if (this->stop.at(id) > this->stop.size()) {
        this->stop.erase(std::next(this->stop.begin(), this->stop.at(id)));
    }

    // remove id from running
    this->running.erase(std::next(this->running.begin(), this->running.at(id)));

}

int soundHandler::call(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // Increment the last id counter
    this->_lastId++;
    // run the sound asyncronisly
    std::future<void> ft = std::async(this->_player, this->_lastId, soundId, pitch, enable3D, pos);
    // add id to running
    this->running.push_back(this->_lastId);
    // return ID
    return this->_lastId;
}