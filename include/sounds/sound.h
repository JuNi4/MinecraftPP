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

        int _volume = 1;

        json _soundList;

        json _setupSoundList();

        std::string _getFileFromKey(std::string key);

    public:
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

        void setVolume(int volume);

        int play();

        void reloadSoundList();
};

#endif