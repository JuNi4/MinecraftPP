#include "soundHandler.h"

// sound handler constructor
soundHandler::soundHandler() {
    // setup sounds
    this->sounds = std::vector<sound> (this->soundLimit);
}

int soundHandler::play(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // get a free id
    while ( this->sounds[this->id].status() == sf::SoundSource::Status::Playing ) {
        // increment the counter to check the next slot for a free sound object
        this->id++;
        // if id exceeds 255, reset it and return -1
        if (id > this->soundLimit) {
            this->id = 0;
            return -1;
        }
    }

    int id = this->id;

    // when id has been found, play the sound
    this->sounds[id].setKey(soundId);

    // set the sound type
    if      (soundId.substr(0,7) == "ambient")     { this->sounds[id].sfxType = 8; }
    else if (soundId.substr(0,5) == "block")       { this->sounds[id].sfxType = 4; }
    else if (soundId.substr(0,6) == "entity")      { this->sounds[id].sfxType = 6; }
    else if (soundId.substr(0,4) == "item")        { this->sounds[id].sfxType = 7; }
    else if (soundId.substr(0,5) == "music")       { this->sounds[id].sfxType = 8; }
    else if (soundId.substr(0,10) == "music_disc") { this->sounds[id].sfxType = 8; }
    else if (soundId.substr(0,8) == "wheather")    { this->sounds[id].sfxType = 3; }
    else { this->sounds[id].sfxType = 0; }

    // set 3D audio to user specified state
    this->sounds[id].enable3DAudio(enable3D);

    // set the absolute sound position
    this->sounds[id].sfxPos = pos;

    // set the pitch of the sound
    this->sounds[id].setPitch(pitch);

    // play the sound
    this->sounds[id].play();

    // return the id of the sound
    return id;
}

int soundHandler::update(int id) {
    // Sound Postition calculation
    sf::Vector3f sfxPos = this->sounds[id].sfxPos;
    sf::Vector3f playerPos = this->playerPos;
    sf::Vector3f soundPos = sfxPos - playerPos;
    // set sound postion
    this->sounds[id].setPosition(soundPos.x, soundPos.y, soundPos.z);

    // set secondary volume - the category volume
    float xtra;
    switch (this->sounds[id].sfxType) {
        case 1: xtra = this->volume_music;
        case 2: xtra = this->volume_noteblock;
        case 3: xtra = this->volume_wheather;
        case 4: xtra = this->volume_blocks;
        case 5: xtra = this->volume_hostile;
        case 6: xtra = this->volume_friendly;
        case 7: xtra = this->volume_players;
        case 8: xtra = this->volume_ambient;
        case 9: xtra = this->volume_voice;
        default: xtra = 1.f;
    }
    // calculate volume
    int volume = this->volume_master * xtra * 100;

    this->sounds[id].setVolume(volume);

    return 0;
}

int soundHandler::updateAll() {
    // go through each sound object...
    for (long i = 0; i < this->sounds.size(); i++) {
        // ...and update it
        update(i);
    }

    return 0;
}