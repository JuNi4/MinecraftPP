/**
 * @brief Just some things
 * 
 */

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

#endif