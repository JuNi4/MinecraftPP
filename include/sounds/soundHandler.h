#include "sound.h"

#ifndef _SOUND_HANDLER_H_
#define _SOUND_HANDLER_H_

class soundHandler {
    private:
        sf::Vector3f _player(0.0f, 0.0f, 0.0f);

        int _masterVolume = 50;
        int _musicVolume = 100;

        int _lastId = -1;

        /**
         * @brief The audio player function
         */
        void _player(int id, std::string sound_id, float pitch, bool 3DAudio, sf::Vector3f pos(0.0f, 0.0f, 0.0f));
    public:
        char* stop[];
        char* running[];

        /**
         * @brief Construct a new sound Handler
         */
        soundHandler();

        int call(std::string soundId, float pitch, bool 3DAudio, sf::Vector3f pos(0.f, 0.f, 0.f));
}

#endif