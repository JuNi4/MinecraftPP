//include the GLGE dependencys
#include "glgeErrors.h"
#include "GLGEKlasses.h"
#include "glgeVars.h"
#include "glgeFuncs.h"

//include the OpenGL dependencys
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

//include the needed default librarys
#include <iostream>

//////////////////////////
//Default GLGE callbacks//
//////////////////////////

//the default display callback for GLGE
void glgeDefaultDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(glgeHasDisplayCallback)
    {
        ((void(*)())glgeDisplayCallback)();
    }

    glutSwapBuffers();
}

//the default timer function for GLGE
void glgeDefaultTimer(int)
{
    //initalise the redrawing of the screen
    glutPostRedisplay();

    //update the time since last tick
    glgeDeltaTime = (glutGet(GLUT_ELAPSED_TIME) - glgeTickTime);
    
    //update the start time of the tick
    glgeTickTime = glutGet(GLUT_ELAPSED_TIME);

    //calculate the current frames per second
    glgeCurrentFPS = 1000/glgeDeltaTime;

    //output all OpenGL errors
    GLenum error;
    //loop over all errors
    while((error = glGetError()) != GL_NO_ERROR)
    {
        //output the error and connect it to the OpenGL error
        if(glgeErrorOutput)
        {
            printf(GLGE_ERROR_OPEN_GL_ERROR, getGLErrorString(error));
        }
        //stop the script
        exit(1);
    }

    //recalculate the window aspect
    glgeWindowAspect = ((float)glutGet(GLUT_WINDOW_WIDTH))/((float)glutGet(GLUT_WINDOW_HEIGHT));

    //if GLGE has an additional main function, call it
    if(glgeHasMainCallback)
    {
        ((void(*)())glgeMainCallback)();
    }

    //recall this function so that it is calld {glgeMaxFPS} times a second
    glutTimerFunc(1000/glgeMaxFPS,glgeDefaultTimer,0);
}

//default keyboard function
void glgeDefaultKeyFunc(unsigned char key, int, int)
{
    //store the pressed key
    glgePressedKeys.keyUpdate(key, true);
}

//default keyboard up function
void glgeDefaultKeyUpFunc(unsigned char key, int, int)
{
    //store wich key is no longer pressed
    glgePressedKeys.keyUpdate(key, false);
}

//special keyboard function
void glgeDefaultSpecKeyFunc(int key, int, int)
{
    //store the pressed key
    glgePressedKeys.keyUpdate(key, true);
}

//special keyboard up func
void glgeDefaultSpecKeyUpFunc(int key, int, int)
{
    //store which key is no longer pressed
    glgePressedKeys.keyUpdate(key, false);
}