/**
 * @file glgeDefaultFuncs.h
 * @author DM8AT
 * @brief this is a file designed to be used only internaly by the GLGE library
 * 
 * in this file, all the functions needed for behind the sceens operations of GLGE are stored
 * 
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _GLGE_DEFAULT_FUNCS_H_
#define _GLGE_DEFAULT_FUNCS_H_

/**
 * @brief this is the default display function for GLGE
 * update the screen
 */
void glgeDefaultDisplay();

/**
 * @brief this is the default timer function for GLGE
 * limit the timer to the set maximal frames per second
 */
void glgeDefaultTimer(int);

/**
 * @brief the default keyboard function for key presses
 * store the pressed keys
 * @param key the pressed key
 */
void glgeDefaultKeyFunc(unsigned char key, int, int);

/**
 * @brief the default keyboard function for lifting a key
 * store wich keys aren't pressed
 * @param key the key that is no longer pressed
 */
void glgeDefaultKeyUpFunc(unsigned char key, int, int);

/**
 * @brief this function is called when a special key is pressed
 * store the pressed keys
 * @param key the pressed key
 */
void glgeDefaultSpecKeyFunc(int key, int, int);

/**
 * @brief this function is called when a special key gets released
 * store the pressed keys
 * @param key the released key
 */
void glgeDefaultSpecKeyUpFunc(int key, int, int);

#endif