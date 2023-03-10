/**
 * @brief Just some things
 * 
 */

#ifndef _UTILS_H_
#define _UTILS_H_
#pragma once

#include <iostream>
#include <vector>
#include "os.hpp"

/**
 * @brief gets the length of a string
 * 
 * @param value The string to get the length of
 * @return int The length of the string
 */
int length(auto value) {
    return end(value) - begin(value);
}


namespace utils {

/**
 * @brief Gets the default path for mc++
 * 
 * @return const char* The path
 */
const char* mcppPath() {
    const char* osname = os::getOsName().c_str();
    // linux path
    if ( osname == "Linux" ) {
        return (std::string("/home/") + os::getUserName() + std::string("/.minecraftpp/")).c_str();
    }
    // windows path
    else if ( std::string(osname).substr(0,3) == "Win" ) {
        return (std::string("C:\\users\\") + os::getUserName() + std::string("\\appdata\\roaming\\")).c_str();
    }
    // Mac Os path
    else if ( osname == "Mac OSX" ) {
        return "None";
    }

    return "None";
}

/*
//
// @brief Checks if a vector has a target avlue
// 
// @param arr The std::vector
// @param value The value to look for
// @return true Enemy spottet
// @return false Has not been found
//
bool hasS(std::vector<int> arr, int value) {
    for (long unsigned i = 0; i < arr.size(); i++) {
        if (arr[i] == value) { return true; }
    }
    return false;
}

//
// @brief Checks if a vector has a target avlue
// 
// @param arr The std::vector
// @param value The value to look for
// @return true Enemy spottet
// @return false Has not been found
//
bool hasS(std::vector<std::string> arr, std::string value) {
    for (long unsigned i = 0; i < arr.size(); i++) {
        if (arr[i] == value) { return true; }
    }
    return false;
}
//
// @brief Checks if a vector has a target avlue
// 
// @param arr The std::vector
// @param value The value to look for
// @return true Enemy spottet
// @return false Has not been found
//

bool hasC(std::vector<char*> arr, char* value) {
    for (long unsigned i = 0; i < arr.size(); i++) {
        if (arr[i] == value) { return true; }
    }
    return false;
}
//
// @brief Checks if a vector has a target avlue
// 
// @param arr The std::vector
// @param value The value to look for
// @return true Enemy spottet
// @return false Has not been found
//

bool hasF(std::vector<float> arr, float value) {
    for (long unsigned i = 0; i < arr.size(); i++) {
        if (arr[i] == value) { return true; }
    }
    return false;
}
*/

};


#endif