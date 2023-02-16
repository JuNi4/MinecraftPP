/**
 * @file sound.h
 * @author @JuNi4
 * @brief A sound system for minecraft sounds and more
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <nlohmann/json.hpp>
#include <SFML/Audio/Music.hpp>

using json = nlohmann::json;

#ifndef _SOUNDS_H_
#define _SOUNDS_H_

/**
 * @brief Simple acsess to (minecraft) sounds
 * 
 */
class soundHandler {
    private:
        /**
         * @brief The path to a file to be playd
         */
        std::string _file;

        // volume
        //int _volume = 100;

        // Variable to hold the sound list
        json _soundList;

        // Read the sounds.json into a json object
        json _setupSoundList();

        // Get the sound file from a minecraft sound key
        std::string _getFileFromKey(std::string key);

        // sfml music object
        sf::Music _sound;

    public:
        // Sound position vector (Relative to player)
        sf::Vector3f pos;

        /**
         * @brief Construct a new sound Handler object
         */
        soundHandler();

        /**
         * @brief Set the File path
         * 
         * @param key The sound name used by Minecraft
         */
        void setKey(std::string key);

        /**
         * @brief Set the Volume of the sound being played
         * 
         * @param volume The valume of the sound, max & default value is 100
         */
        void setVolume(int volume);

        /**
         * @brief Set the Pitch of the sound being played
         * 
         * @param pitch The pitch value, default is 1
         */
        void setPitch(float pitch);

        /**
         * @brief Set the Position Vector of the sound source
         * 
         * @param x The X coordinate of the sound source
         * @param y The Y coordinate of the sound source
         * @param z The Z coordinate of the sound source
         */
        void setPosition(float x, float y, float z);

        /**
         * @brief Playes a random sound from the sound file list from a key from the sound list
         * 
         * @return int Whether or not the playing of a sound was sucsessfull
         */
        int play();

        /**
         * @brief Pauses the sound
         */
        void pause();

        /**
         * @brief Resumes the sound if paused
         */
        void resume();

        /**
         * @brief Stops the sound being played and rewinds
         */
        void stop();

        //void destroy();

        sf::SoundSource::Status status();

        /**
         * @brief Re reads the sounds.json and stores it in a json object
         */
        void reloadSoundList();
};

#endif