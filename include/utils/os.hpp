/**
 * @file os.hpp
 * @author JuNi4
 * @brief Simple os related things
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
*/

#ifdef _WIN32 || _WIN64 // Windows specific includes

#include <windows.h>
#include <Lmcons.h>

#endif

// include guard
#ifndef _OS_H_
#define _OS_H_
#pragma once

#include <iostream>

// namespace os
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
    #ifdef _WIN32 || _WIN64
    return "\\";
    #else
    return "/";
    #endif
}

std::string getUserName() {
    #ifdef __linux__ // linux specific username function
    return std::getenv("USER");
    #elif _WIN32 || _WIN64 // windows specific function
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);
    #endif
}

// end of namespace
};

#endif