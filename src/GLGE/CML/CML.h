/**
 * @file CML.h
 * @author MALHINDS
 * @brief CML is short for C++ extended Math Library. It adds a few features I think are missing in the default C++ math library.
 * List of features:
 * vectors:
 *  - 2 dimensional vector (vec2) of floates
 *  - 3 dimensional vector (vec3) of floates
 *  - 4 dimensional vector (vec4) of floates
 *  - n dimensional vector (vec)  of floates
 * matrices:
 *  - 2*2 matrix (mat2) of floates (float m[2][2])
 *  - 3*3 matrix (mat3) of floates (float m[3][3])
 *  - 4*4 matrix (mat4) of floates (float m[4][4])
 * miscelanius:
 *  - quaternions (Quaternion) of floates (w,x,y,z)
 * 
 * Intention:
 *  the CML library is designed to help handling more advanced mathematics and help in an 3D enviroment. 
 *  I tried to code the features in this library as fast and as accurad as possible, so I don't have to write
 *  the same code over all my projects again
 * 
 * Function:
 *  To use the CML library, drag the CML folder into your project folder and include "CML/CML.h". 
 *  Else, you can include single features by including just this header file (say you only want matrices
 *  and vector presets, just include "CML/CMLMatrices.hpp". All dependencys will be automatically included.)
 * @version 1.0
 * @date 2022-11-18
 */
//check if library is allready included
#ifndef _CML_H_
#define _CML_H_
//include all sub modules of CML
//include the Vectors
    #include "CMLVec2.h"
    #include "CMLVec3.h"
    #include "CMLVec4.h"
    #include "CMLVector.h"
//include all the matrices
    #include "CMLMat2.h"
    #include "CMLMat3.h"
    #include "CMLMat4.h"
//include the Quaternions
    #include "CMLQuaternion.h"
//end of file
#endif