#include "soundHandler.h"
#include <future>

soundHandler::soundHandler() {}

void soundHandler::_player(int id, std::string soundId, float pitch, bool 3DAudio, sf::Vector3f pos(0.0f, 0.0f, 0.0f)) {
    // create a sound object
    sound sfx;

    // set key
    sfx.setKey(soundId);

    // set up pitch
    sfx.setPitch(pitch);

    // set 3D audio
    sfx.enable3DAudio(3DAudio);

    // play sound
    sdx.play();

    // keep sound alive
    while (sfx.getStatus() = sf::SoundSource::Status::Playing) {
        if (3DAudio) {
            sfx.pos = pos - this->_player;
        }
        float vol = this->_masterVolume/100 * this->_musicVolume/100;
        sfx.setVolume(vol);
    }
}

int soundHandler::call(std::string soundId, float pitch, bool 3DAudio, sf::Vector3f pos(0.f, 0.f, 0.f)) {
    // Increment the last id counter
    this->_lastId++;
    // run the sound asyncronisly
    std::future<void> ft = std::async(this->_player, this->_lastId, soundId, pitch, 3DAudio, pos);
    // add id to running
    this->running.pushback(this->_lastId);
    // return ID
    return this->_lastId;
}