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
    sdx.play();

    // keep sound alive
    while (sfx.getStatus() = sf::SoundSource::Status::Playing && ! std::find( this->stop.begin, this->stop.end, id ) != this->stop.end ) {
        if (enable3D) {
            sfx.pos = pos - this->_player;
        }
        float vol = this->_masterVolume/100 * this->_musicVolume/100;
        sfx.setVolume(vol);
    }

    // remove id from stop
    if (std::find( this->stop.begin, this->stop.end, id ) != this->stop.end ) {
        std::remove( this->stop.begin, this->stop.end, std::find( this->stop.begin, this->stop.end, id ) );
    }

    // remove id from running
    std::remove( this->running.begin, this->running.end, std::find( this->running.begin, this->running.end, id ) );

}

int soundHandler::call(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // Increment the last id counter
    this->_lastId++;
    // run the sound asyncronisly
    std::future<void> ft = std::async(this->_player, this->_lastId, soundId, pitch, enable3D, pos);
    // add id to running
    this->running.pushback(this->_lastId);
    // return ID
    return this->_lastId;
}