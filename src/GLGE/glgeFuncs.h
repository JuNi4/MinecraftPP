/**
 * @file glgeFuncs.h
 * @author DM8AT
 * @brief this file stores all private functions used behind the sceens by OpenGL
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//check for double include
#ifndef _GLGE_FUNCS_H_
#define _GLGE_FUNCS_H_

//include needed defines
#include <string>

//include the CML functions
#include "CML/CMLVec2.h"

/**
 * @brief Create a Window
 * 
 * behind the sceens function for GLGE
 * 
 * @param n the name of the window
 * @param s the size of the window
 * @param p the position of the window
 */
void createWindow(const char* n, vec2 s, vec2 p);

/**
 * @brief read a file
 * 
 * @param filename the name of the file
 * @param output a pointer to a string to write to
 * @return true the file could be read | 
 * @return false the file can't be found
 */
bool readFile(const char* filename, std::string& output);

/**
 * @brief convert an error code from OpenGL into an error string
 * 
 * @param error the error code
 * @return char* a string created from the error index
 */
char* getGLErrorString(unsigned int error);

#endif