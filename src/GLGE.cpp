//include the GLGE dependencys
#include "GLGE.h"
#include "GLGE/glgeErrors.h"
#include "GLGE/glgeVars.h"
#include "GLGE/glgeFuncs.h"

//include the OpenGL dependencys
#include <GL/freeglut.h>

//include the standart librarys
#include <math.h>
#include <iostream>

////////////////////
//Public functions//
////////////////////

//init function for glge
void glgeInit(int argc, char** argv)
{
    //error check
    bool error = false;
    //if argc = 0, the length of argv is 0 --> output error, but only if error output is enabled
    if (argc == 0)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_ARGC_OUT_OF_BOUNDS, argc);
        }
        error = true;
    }
    //if argv is the nullpointer, output an error if error output is enabled
    if (argv == nullptr)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_NULLPOINTER_INP_INIT);
        }
        error = true;
    }
    //if an error occoured, stop the function
    if (error)
    {
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_GLGE_INIT_ERROR << std::endl;
        }
        //stop the program
        exit(1);
    }

    glutInit(&argc, argv);
}

//first window creation methode
void glgeCreateWindow(const char* name, vec2 size, vec2 pos)
{
    //check for erros in the inputs
    bool error = false;
    //check if the size parameters are correct
    if (size.x <= 0 || size.y <= 0)
    {
        //if the size parameters are invalide, start to print an error
        if (glgeErrorOutput)
        {
            //print diffrent messages depending on the input size
            if (size.x < 0 || size.y < 0)
            {
                printf(GLGE_ERROR_WINDOW_SIZE_NEGATIVE);
            }
            else
            {
                printf(GLGE_ERROR_WINDOW_SIZE_ZERO);
            }
        }
        //say that an error occured
        error = true;
    }
    //check if the name pointer is invalide
    if (name == nullptr)
    {
        //print an error message
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_WINDOW_NAME_NULLPOINTER);
        }
        //say that an error occured
        error = true;
    }
    //check if the position is negative
    if (pos < vec2(0,0))
    {
        //print an error message
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_WINDOW_NEGATIVE_POSITION);
        }
        //say that an error occured
        error = true;
    }
    //if an error occured, return
    if (error)
    {
        //print an error message
        if (glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_WINDOW_INPUT_ERROR << std::endl;
        }
        //stop the program
        exit(1);
    }
    //start the window creation
    createWindow(name, size, pos);
}

//second window creation methode
void glgeCreateWindow(const char* name, int width, int height, vec2 pos)
{
    //check for erros in the inputs
    bool error = false;
    //check if the size parameters are correct
    if (width <= 0 || height <= 0)
    {
        //if the size parameters are invalide, start to print an error
        if (glgeErrorOutput)
        {
            //print diffrent messages depending on the input size
            if (width < 0 || height < 0)
            {
                printf(GLGE_ERROR_WINDOW_SIZE_NEGATIVE);
            }
            else
            {
                printf(GLGE_ERROR_WINDOW_SIZE_ZERO);
            }
        }
        //say that an error occured
        error = true;
    }
    //check if the name pointer is invalide
    if (name == nullptr)
    {
        //print an error message
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_WINDOW_NAME_NULLPOINTER);
        }
        //say that an error occured
        error = true;
    }
    //check if the position is negative
    if (pos < vec2(0,0))
    {
        //print an error message
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_WINDOW_NEGATIVE_POSITION);
        }
        //say that an error occured
        error = true;
    }
    //if an error occured, return
    if (error)
    {
        //print an error message
        if (glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_WINDOW_INPUT_ERROR << std::endl;
        }
        //stop the program
        exit(1);
    }
    //start the window creation
    createWindow(name, vec2(width, height), pos);
}

//set if GLGE should output errors
void glgeSetErrorOutput(bool in)
{
    //set the boolean to controll error output
    glgeErrorOutput = in;
}

//get if GLGE should output errors
bool glgeGetErrorOutput()
{
    //return if GLGE should output errors
    return glgeErrorOutput;
}

//set if GLGE should print warnings
void glgeSetWarningOutput(bool out)
{
    glgeWarningOutput = out;
}

//get if GLGE should print warnings to the console
bool glgeGetWarningOutput()
{
    return glgeWarningOutput;
}

//start the main loop of GLGE
void glgeRunMainLoop()
{
    //start the glut main loop
    glutMainLoop();
}

//first function to set the clear color
void glgeSetClearColor(float r, float g, float b, bool normalise)
{
    //check for errors in the input
    bool error = false;
    //check if the values are negative
    if (r < 0 || g < 0 || b < 0)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_NEGAITVE_COLOR_VAL);
        }
        error = true;
    }

    //if the values need to be normalised, normalise them
    if (normalise)
    {
        r /= 255.f;
        g /= 255.f;
        b /= 255.f;
    }

    //check for out of bound values
    if (r > 1.f || g > 1.f || b > 1.f)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_COLOR_VALUE_OUT_OF_BOUNDS);
        }
        error = true;
    }

    //if an error occured, exit
    if (error)
    {
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_SET_CLEAR_COLOR << std::endl;
        }
        exit(1);
    }

    //finaly, set the clear color
    glClearColor(r,g,b,1.f);
}

//second function to set the clear color
void glgeSetClearColor(vec3 color, bool normalise)
{
    //check for errors in the input
    bool error = false;
    //check if the values are negative
    if (color.x < 0 || color.y < 0 || color.z < 0)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_NEGAITVE_COLOR_VAL);
        }
        error = true;
    }

    //if the values need to be normalised, normalise them
    if (normalise)
    {
        color /= vec3(255,255,255);
    }

    //check for out of bound values
    if (color.x > 1.f || color.y > 1.f || color.z > 1.f)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_COLOR_VALUE_OUT_OF_BOUNDS);
        }
        error = true;
    }

    //if an error occured, exit
    if (error)
    {
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_SET_CLEAR_COLOR << std::endl;
        }
        exit(1);
    }

    //finaly, set the clear color
    glClearColor(color.x,color.y,color.z,1.f);
}

//thired function to set the clear color
void glgeSetClearColor(vec4 color, bool normalise)
{
    //check for errors in the input
    bool error = false;
    //check if the values are negative
    if (color.x < 0 || color.y < 0 || color.z < 0)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_NEGAITVE_COLOR_VAL);
        }
        error = true;
    }

    //if the values need to be normalised, normalise them
    if (normalise)
    {
        color /= vec4(255,255,255,1);
    }

    //check for out of bound values
    if (color.x > 1.f || color.y > 1.f || color.z > 1.f)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_COLOR_VALUE_OUT_OF_BOUNDS);
        }
        error = true;
    }

    //if an error occured, exit
    if (error)
    {
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_SET_CLEAR_COLOR << std::endl;
        }
        exit(1);
    }

    //finaly, set the clear color
    glClearColor(color.x,color.y,color.z,1.f);
}

//bind a display func callback
void glgeBindDisplayFunc(void (*func)())
{
    //check if an error occured
    bool error = false;
    if(func == nullptr)
    {
        //print an error
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_FUNC_IS_NULLPOINTER);
        }
        //say that an error occured
        error = true;
    }

    //if an error occured, exit
    if(error)
    {
        //print an exit message
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_BIND_DISPLAY_CALLBACK << std::endl;
        }
        //stop the program
        exit(1);
    }

    //set the display callback
    glgeDisplayCallback = func;

    //say that an display callback is bound
    glgeHasDisplayCallback = true;
}

//debind a display func callback
void glgeClearDisplayFunc()
{
    //set the display func callback to the nullpointer
    glgeDisplayCallback = nullptr;

    //say that no display function is bound
    glgeHasDisplayCallback = false;
}

//bind a main callback function
void glgeBindMainFunc(void (*func)())
{
    //check if an error occured
    bool error = false;
    if(func == nullptr)
    {
        //print an error
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_FUNC_IS_NULLPOINTER);
        }
        //say that an error occured
        error = true;
    }

    //if an error occured, exit
    if(error)
    {
        //print an exit message
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_BIND_MAIN_CALLBACK << std::endl;
        }
        //stop the program
        exit(1);
    }

    //set the display callback
    glgeMainCallback = func;

    //say that an display callback is bound
    glgeHasMainCallback = true;
}

//unbind the main callback
void glgeClearMainFunc()
{
    //set the main function callback to the nullpointer
    glgeMainCallback = nullptr;

    //say that no main callback is bound
    glgeHasMainCallback = false;
}

void glgeSetMaxFPS(int fps)
{
    //check for errors
    bool error = false;
    //check if the maximal frames per second are less or equal to 0
    if (fps <= 0)
    {
        //output an error message
        if (glgeErrorOutput)
        {
            printf(GLGE_ERROR_FPS_LESS_ONE);
        }
        //say that an error occured
        error = true;
    }

    //if an error occured, break
    if (error)
    {
        //output an exit message
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_SET_MAX_FPS << std::endl;
        }
        //stop the program
        exit(1);
    }

    //set the maximal frames per second
    glgeMaxFPS = fps;
}

//get the current frames per second
int glgeGetCurrentFPS()
{
    //return the current FPS
    return glgeCurrentFPS;
}

//get the maximal frames per second
int glgeGetMaxFPS()
{
    //return the max FPS
    return glgeMaxFPS;
}

//return if GLGE has an additional main function bound
bool glgeHasMainFunc()
{
    return glgeHasMainCallback;
}

//return if GLGE has an additional display function bound
bool glgeHasDisplayFunc()
{
    return glgeHasDisplayCallback;
}

//return if GLGE has a window bound
bool glgeHasWindow()
{
    return glgeHasMainWindow;
}

//set the move matrix name
void glgeSetMoveMatrixName(const char* name)
{
    //check if the input is valide
    if(name == nullptr)
    {
        //output an error message and say where the error occured
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_INVALIDE_INPUT);
            std::cerr << GLGE_ERROR_STR_GLGE_SET_MOV_MAT_NAME << std::endl;
        }
        //stop the program
        exit(1);
    }
    //sore the name for the move matrix
    glgeMoveMatrix = (char*)name;
}

//get the momantan name of the move matrix
char* glgeGetMoveMatrixName()
{
    //return the name of the move matrix
    return glgeMoveMatrix;
}

//get the aspect of the window
float glgeGetWindowAspect()
{
    //return the window aspect
    return glgeWindowAspect;
}

//return the pressed keys
Keys glgeGetKeys()
{
    //return the pressed keys
    return glgePressedKeys;
}

//get the delta time
float glgeGetDeltaTime()
{
    //return the delta time
    return glgeDeltaTime;
}