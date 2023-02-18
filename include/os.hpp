/**
 * @file os.hpp
 * @author JuNi4
 * @brief Simple os related things
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifndef _OS_H_
#define _OS_H_

#include <iostream>

namespace os {

/**
 * @brief gets the type of the operating system
*/
std::string getOsName()
{
    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}

std::string getOsDelimiter()
{
    #ifdef _WIN32
    return "\\";
    #elif _WIN64
    return "\\";
    #else
    return "/";
    #endif
}

std::string getUserName() {
    #ifdef __linux__
    return std::getenv("USER");
    #else
    return "NONE";
    #endif
}

// end of namespace
};

#endif