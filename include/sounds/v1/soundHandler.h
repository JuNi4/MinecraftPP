#include "../sound.h"
#include <SFML/Audio/Music.hpp>
#include <future>

#ifndef _SOUND_HANDLER_H_
#define _SOUND_HANDLER_H_

class soundHandler {
    private:
        int _masterVolume = 50;
        int _musicVolume = 100;

        int _lastId = -1;

    public:
        sf::Vector3f playerPos;
        std::vector<int> stop = {};
        std::vector<int> running = {};

        int id = 0;

        /**
         * @brief The audio player function
         */
        void player(int id, std::string soundId, float pitch, bool enable3D, sf::Vector3f pos = sf::Vector3f (0.f, 0.f, 0.f));

        /**
         * @brief Construct a new sound Handler
         */
        soundHandler();

        int getId();

        /**
         * @brief A simple function that plays a sound
         * 
         * @param soundId A string telling the programm which sound to play
         * @param pitch The Pitch of the sound being played
         * @param enable3D whether or not the audo will be played in 3D space
         * @param pos The position of the sound
         */
        int play(std::string soundId, float pitch, bool enable3D, sf::Vector3f pos = sf::Vector3f (0.f, 0.f, 0.f));

};

#endif