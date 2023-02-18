#include "../sound.h"
#include <SFML/Audio/Music.hpp>
#include <future>

#ifndef _SOUND_HANDLER_H_
#define _SOUND_HANDLER_H_

class soundHandlerV2 {
    public:
        // the maximum amounts of sounds
        int soundLimit = 255; // maximum of 255!
        // a list holding all sound objects
        std::vector<sound> sounds; // ToDo: make it dynamic
        // the absolute position of the player
        sf::Vector3f playerPos;

        float volume_master = 1.f;
        float volume_music = 1.f;
        float volume_noteblock = 1.f;
        float volume_wheather = 1.f;
        float volume_blocks = 1.f;
        float volume_hostile = 1.f;
        float volume_friendly = 1.f;
        float volume_players = 1.f;
        float volume_ambient = 1.f;
        float volume_voice = 1.f;

        // the last id that was used
        int id = 0;

        /**
         * @brief Construct a new sound Handler
         */
        soundHandlerV2();

        /**
         * @brief Plays a selected sound
         * 
         * @param soundId The ID of the sound
         * @param pitch The pitch of a sound. This also changes the speed
         * @param enable3D 3D Audio.
         * @param pos The position of the sound in 3d space
         * @return int the id of the sound or a negative number for errors
         */
        int play(std::string soundId, float pitch = 1, bool enable3D = false, sf::Vector3f pos = sf::Vector3f (0.f, 0.f, 0.f));

        /**
         * @brief Updates the position and volume of a sound
         * 
         * @param id The id of the sound in the sounds array
         * @return int Whether or not is was sucsessfull
         */
        int update(int id);

        /**
         * @brief Updates all sound sources
         * 
         * @return int Whether or not is was sucsessfull
         */
        int updateAll();
};

#endif