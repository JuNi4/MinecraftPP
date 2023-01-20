#ifndef _CMLMAT2_H_
#define _CMLMAT2_H_
#pragma once
#include "CMLVec2.h"

/**
 * @brief mat2 is a 2*2 matrix, compleated with multiplication, scaling, addition and subtarction. It is included in CML/CMLMatrices.hpp
 */
struct mat2
{
    //define the storage array of the matrix
    float m[2][2];

    /**
     * @brief Construct a new 2*2 matrix
     * default constructor, all values are 0
     */
    mat2();
    /**
     * @brief Construct a new 2*2 matrix
     * 
     * @param m00 the top left item of the matrix
     * @param m01 the top right item of the matrix
     * @param m10 the bottom left item of the matrix
     * @param m11 the bottom right item of the matrix
     */
    mat2(float m00, float m01, 
         float m10, float m11);

    /**
     * @brief add two 2*2 matrices together and return the result
     * 
     * @param c the other matrix
     * @return mat2 the sum of the two matrices
     */
    mat2 operator+(mat2 c);
    /**
     * @brief add a constant value to the matrix
     * 
     * @param c the value that is going to be added to all values of the matrix
     * @return mat2 the matrix + c
     */
    mat2 operator+(float c);
    /**
     * @brief add a 2*2 matrix to this matrix
     * 
     * @param c the other matrix
     */
    void operator+=(mat2 c);
    /**
     * @brief add a constant value to this matrix
     * 
     * @param c the constant value
     */
    void operator+=(float c);

    /**
     * @brief subtract a 2*2 matrix from this matrix and return the result
     * 
     * @param c the other matrix
     * @return mat2 this matrix - the other matrix
     */
    mat2 operator-(mat2 c);
    /**
     * @brief subtract a constant value from the matrix and return the result
     * 
     * @param c the constant value
     * @return mat2 this matrix - the constant value
     */
    mat2 operator-(float c);
    /**
     * @brief subtract a 2*2 matrix from this matrix
     * 
     * @param c the other matrix
     */
    void operator-=(mat2 c);
    /**
     * @brief subtract a constant value form this matrix
     * 
     * @param c the constant value
     */
    void operator-=(float c);

    /**
     * @brief multiply this matric with another matrix and return the result
     * 
     * @param c the other matrix
     * @return mat2 the product of the two matrices
     */
    mat2 operator*(mat2 c);
    /**
     * @brief scale the matrix and return the result
     * 
     * @param s the scale to scale the matrix
     * @return mat2 the scaled matrix
     */
    mat2 operator*(float s);
    /**
     * @brief multiply this matrix by an vector and return the result
     * 
     * @param v the vector
     * @return vec2 the product of this matrix and the vector
     */
    vec2 operator*(vec2 v);
    /**
     * @brief multiply this matrix by another matrix
     * 
     * @param c the other matrix
     */
    void operator*=(mat2 c);
    /**
     * @brief scale this matrix
     * 
     * @param s the scale
     */
    void operator*=(float s);

    /////////////////
    //EXPERIMENTAL!//
    /////////////////
    /**
     * @brief calculate the determinant of this matrix
     * 
     * @return float the determinant of this matrix
     */
    float determinant();

    /**
     * @brief calculate the invers of the matrix
     * 
     * @return mat2 the inverse matrix
     */
    mat2 inverse();
};
#endif