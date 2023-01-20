#include "glgeVars.h"

///////////
//CLASSES//
///////////



////////////////////
//Private Constans//
////////////////////

const char* glgePresets[] = {
                             "CUBE"
                            };

/////////////////////
//Private Variables//
/////////////////////

//should error be outputed?
bool glgeErrorOutput = true;

//should warnings be outputed?
bool glgeWarningOutput = true;

//is an main window created?
bool glgeHasMainWindow = false;

//additional display function
void (*glgeDisplayCallback)() = nullptr;

//is an display callback bound?
bool glgeHasDisplayCallback = false;

//the maximal frames per second the window should run on
int glgeMaxFPS = 60;

//the current frames per second the window is running on
int glgeCurrentFPS = 0;

//the time sinse the last update
float glgeDeltaTime = 0.f;

//the time the last tick started at
float glgeTickTime = 0.f;

//a callback for a function called every tick
void (*glgeMainCallback)() = nullptr;

//is a main callback function bound?
bool glgeHasMainCallback = false;

//store the name for the move matrix
char* glgeMoveMatrix = (char*)"moveMat";

//store the window aspect
float glgeWindowAspect = 1.f;

Keys glgePressedKeys = Keys();