#include "sound.h"
#include <SFML/Audio/Music.hpp>

#ifndef _SOUND_HANDLER_H_
#define _SOUND_HANDLER_H_

class soundHandler {
    private:
        sf::Vector3f _player;

        int _masterVolume = 50;
        int _musicVolume = 100;

        int _lastId = -1;

        int stop[256];
        int running[256];

        /**
         * @brief The audio player function
         */
        void _player(int id, std::string sound_id, float pitch, bool enable3D, sf::Vector3f pos);
    public:
        /**
         * @brief Construct a new sound Handler
         */
        soundHandler();

        int call(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos = sf::Vector3f (0.f, 0.f, 0.f));
}

#endif