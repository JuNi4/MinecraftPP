/**
 * @brief Just some things
 * 
 */
#include <iostream>
#include <vector>

#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * @brief gets the length of a string
 * 
 * @param value The string to get the length of
 * @return int The length of the string
 */
int length(auto value) {
    return end(value) - begin(value);
}

/*
namespace lol_notalreadydefined_u_idiot_utils {

//
// @brief Checks if a vector has a target avlue
// 
// @param arr The std::vector
// @param value The value to look for
// @return true Enemy spottet
// @return false Has not been found
//
bool hasI(std::vector<int> arr, int value) {
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

};
*/
#endif