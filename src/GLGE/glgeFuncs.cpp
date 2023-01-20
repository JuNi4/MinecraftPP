//include the GLGE dependencys
#include "glgeErrors.h"
#include "glgeVars.h"
#include "glgeDefaultFuncs.h"

//include the CML dependencys
#include "CML/CMLVec2.h"

//include the default librarys
#include <iostream>
#include <fstream>

//include the OpenGL dependencys
#include <GL/glew.h>
#include <GL/freeglut.h>


/**
 * @brief Create a Window
 * 
 * this function is only called internaly in GLGE
 * 
 * @param n the name of the window
 * @param s the size of the window
 * @param p the position of the window
 */
void createWindow(const char* n, vec2 s, vec2 p)
{
    //check for errors in the window creation
    bool error = false;
    if (glgeHasMainWindow)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_TWO_WINDOWS);
        }
        error = true;
    }
    //if an error occured, return
    if (error)
    {
        if(glgeErrorOutput)
        {
            std::cerr << GLGE_ERROR_STR_WINDOW_SUB_FUNC<< std::endl;
        }
        //stop the program
        exit(1);
    }
    //if no error occured, create the window
    glutInitWindowSize(s.x,s.y);
    glutInitWindowPosition(p.x,p.y);
    glutCreateWindow(n);

    //initalise glew
    if (glewInit() != GLEW_OK)
    {
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_GLEW_INIT_FAILED, glewGetErrorString(glewInit()));
            std::cerr << GLGE_ERROR_STR_GLEW_INIT << std::endl;
        }
        //stop the program
        exit(1);
    }

    //say that an window was created
    glgeHasMainWindow = true;

    //bind the window update function
    glutDisplayFunc(glgeDefaultDisplay);
    //bind the timer function
    glutTimerFunc(0, glgeDefaultTimer, 0);
    //bind the keyboard down and up function
    glutKeyboardFunc(glgeDefaultKeyFunc);
    glutKeyboardUpFunc(glgeDefaultKeyUpFunc);
    //bind the keyboard down and up function for special keys
    glutSpecialFunc(glgeDefaultSpecKeyFunc);
    glutSpecialUpFunc(glgeDefaultSpecKeyUpFunc);

    //say to cull backfasing triangles
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    //setup the depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);
}

//read a file
bool readFile(const char* filename, std::string& output)
{
    //create a new ifstream object containing the file
    std::ifstream f(filename);

    //check if the file can be read
    bool ret = false;

    //check if the file is opend
    if(f.is_open())
    {
        //create a variable to store a single line
        std::string line;
        //loop over all lines in the file and store them
        while(getline(f, line))
        {
            //add the lines to the output
            output.append(line);
            //add a new line character to the output
            output.append("\n");
        }
        //close the file
        f.close();

        //say that the file could be opend
        ret = true;
    }
    else
    {
        //else print an error message
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_FILE_NOT_FOUND, filename);
        }
    }

    //return if the file could be read
    return ret;
}

//convert an error code into an string
char* getGLErrorString(unsigned int error)
{
    //check for all errors OpenGL has and return theyre name
    if (error == GL_NO_ERROR)
    {
        return (char*)"GL_NO_ERROR";
    }
    else if (error == GL_INVALID_ENUM)
    {
        return (char*)"GL_INVALIDE_ENUM";
    }
    else if (error == GL_INVALID_VALUE)
    {
        return (char*)"GL_INVALIDE_VALUE";
    }
    else if (error == GL_INVALID_OPERATION)
    {
        return (char*)"GL_INVALIDE_OPERATION";
    }
    else if (error == GL_STACK_OVERFLOW)
    {
        return (char*)"GL_STACK_OVERFLOW";
    }
    else if (error == GL_STACK_UNDERFLOW)
    {
        return (char*)"GL_STACK_UNDERFLOW";
    }
    else if (error == GL_OUT_OF_MEMORY)
    {
        return (char*)"GL_OUT_OF_MEMORY";
    }
    else if (error == GL_TABLE_TOO_LARGE)
    {
        return (char*)"GL_TABLE_TOO_LARGE";
    }
    else if (error == GL_INVALID_FRAMEBUFFER_OPERATION)
    {
        return (char*)"GL_INVALID_FRAMEBUFFER_OPERATION";
    }
    else
    {
        //if the error dosn't match any known error code, output an standart error
        return (char*)"GLGE_UNKNOWN_GL_ERROR";
    }
}