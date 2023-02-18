#include "soundHandler.h"

// sound handler constructor
soundHandlerV2::soundHandlerV2() {
    // setup sounds
    this->sounds = std::vector<sound> (this->soundLimit);
}

int soundHandlerV2::play(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos) {
    // get a free id
    this->id = 0;
    while ( this->sounds[this->id].status() == sf::SoundSource::Status::Playing ) {
        // increment the counter to check the next slot for a free sound object
        this->id++;
        // if id exceeds 255, reset it and return -1
        if (id >= this->soundLimit) {
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
    else if (soundId.substr(0,10) == "music_disc") { this->sounds[id].sfxType = 2; }
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

int soundHandlerV2::update(int id) {
    // Sound Postition calculation
    sf::Vector3f sfxPos = this->sounds[id].sfxPos;
    sf::Vector3f playerPos = this->playerPos;
    sf::Vector3f soundPos = sfxPos - playerPos;
    // set sound postion
    this->sounds[id].setPosition(soundPos.x, soundPos.y, soundPos.z);

    // set secondary volume - the category volume
    float xtra = 1;
    if ( xtra == 1 ) { xtra = this->volume_music; }
    if ( xtra == 2 ) { xtra = this->volume_noteblock; }
    if ( xtra == 3 ) { xtra = this->volume_wheather; }
    if ( xtra == 4 ) { xtra = this->volume_blocks; }
    if ( xtra == 5 ) { xtra = this->volume_hostile; }
    if ( xtra == 6 ) { xtra = this->volume_friendly; }
    if ( xtra == 7 ) { xtra = this->volume_players; }
    if ( xtra == 8 ) { xtra = this->volume_ambient; }
    if ( xtra == 9 ) { xtra = this->volume_voice; }
    // calculate volume
    int volume = this->volume_master * xtra * 100;

    //std::cout << volume << " " << id << "          \r";

    this->sounds[id].setVolume(volume);

    return 0;
}

int soundHandlerV2::updateAll() {
    // go through each sound object...
    for (long unsigned i = 0; i < this->sounds.size(); i++) {
        if (this->sounds[i].status() != sf::SoundSource::Playing) { continue; } // ..skip if sound is not playing..
        // ...and update it
        update(i);
    }

    return 0;
}