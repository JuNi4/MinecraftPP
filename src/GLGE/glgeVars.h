/**
 * @file glgeVars.h
 * @author DM8AT
 * @brief this file stores all behind-the-sceens variables used by GLGE. DO NOT CHANGE OUTSIDE OF GLGE!
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//check for double include
#ifndef _GLGE_VARS_H_
#define _GLGE_VARS_H_

//include needed dependencys
#include "GLGEKlasses.h"

///////////
//CLASSES//
///////////

////////////////////
//Private Constans//
////////////////////

extern const char* glgePresets[];

/////////////////////
//Private Variables//
/////////////////////

//should error be outputed?
extern bool glgeErrorOutput;

//should warnings be outputed?
extern bool glgeWarningOutput;

//is an main window created?
extern bool glgeHasMainWindow;

//additional display function
extern void (*glgeDisplayCallback)();

//is an display callback bound?
extern bool glgeHasDisplayCallback;

//the maximal frames per second the window should run on
extern int glgeMaxFPS;

//the current frames per second the window is running on
extern int glgeCurrentFPS;

//the time sinse the last update
extern float glgeDeltaTime;

//the time the last tick started at
extern float glgeTickTime;

//a callback for a function called every tick
extern void (*glgeMainCallback)();

//is a main callback function bound?
extern bool glgeHasMainCallback;

//store the name for the move matrix
extern char* glgeMoveMatrix;

//store the window aspect
extern float glgeWindowAspect;

//store all pressed keys
extern Keys glgePressedKeys;

#endif