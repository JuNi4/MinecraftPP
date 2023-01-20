#include "CMLMat2.h"

mat2::mat2()
{
    m[0][0] = 0; m[0][1] = 0;
    m[1][0] = 0; m[1][1] = 0;
}
/**
 * @brief Construct a new 2*2 matrix
 * 
 * @param m00 the top left item of the matrix
 * @param m01 the top right item of the matrix
 * @param m10 the bottom left item of the matrix
 * @param m11 the bottom right item of the matrix
 */
mat2::mat2(float m00, float m01, 
    float m10, float m11)
{
    m[0][0] = m00; m[0][1] = m01;
    m[1][0] = m10; m[1][1] = m11;
}

/**
 * @brief add two 2*2 matrices together and return the result
 * 
 * @param c the other matrix
 * @return mat2 the sum of the two matrices
 */
mat2 mat2::operator+(mat2 c)
{
    return mat2(m[0][0] + c.m[0][0], m[0][1] + c.m[0][1], 
                m[1][0] + c.m[1][0], m[1][1] + c.m[1][1]);
}
/**
 * @brief add a constant value to the matrix
 * 
 * @param c the value that is going to be added to all values of the matrix
 * @return mat2 the matrix + c
 */
mat2 mat2::operator+(float c)
{
    return mat2(m[0][0] + c, m[0][1] + c, 
                m[1][0] + c, m[1][1] + c);
}
/**
 * @brief add a 2*2 matrix to this matrix
 * 
 * @param c the other matrix
 */
void mat2::operator+=(mat2 c)
{
    m[0][0] += c.m[0][0]; m[0][1] += c.m[0][1];
    m[1][0] += c.m[1][0]; m[1][1] += c.m[1][1];
}
/**
 * @brief add a constant value to this matrix
 * 
 * @param c the constant value
 */
void mat2::operator+=(float c)
{
    m[0][0] += c; m[0][1] += c;
    m[1][0] += c; m[1][1] += c;
}

/**
 * @brief subtract a 2*2 matrix from this matrix and return the result
 * 
 * @param c the other matrix
 * @return mat2 this matrix - the other matrix
 */
mat2 mat2::operator-(mat2 c)
{
    return mat2(m[0][0] - c.m[0][0], m[0][1] - c.m[0][1], 
                m[1][0] - c.m[1][0], m[1][1] - c.m[1][1]);
}
/**
 * @brief subtract a constant value from the matrix and return the result
 * 
 * @param c the constant value
 * @return mat2 this matrix - the constant value
 */
mat2 mat2::operator-(float c)
{
    return mat2(m[0][0] - c, m[0][1] - c, 
                m[1][0] - c, m[1][1] - c);
}
/**
 * @brief subtract a 2*2 matrix from this matrix
 * 
 * @param c the other matrix
 */
void mat2::operator-=(mat2 c)
{
    m[0][0] -= c.m[0][0]; m[0][1] -= c.m[0][1];
    m[1][0] -= c.m[1][0]; m[1][1] -= c.m[1][1];
}
/**
 * @brief subtract a constant value form this matrix
 * 
 * @param c the constant value
 */
void mat2::operator-=(float c)
{
    m[0][0] -= c; m[0][1] -= c;
    m[1][0] -= c; m[1][1] -= c;
}

/**
 * @brief multiply this matric with another matrix and return the result
 * 
 * @param c the other matrix
 * @return mat2 the product of the two matrices
 */
mat2 mat2::operator*(mat2 c)
{
    mat2 out;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            out.m[i][j] = m[i][0] * c.m[0][j] + m[i][1] * c.m[1][j];
        }
    }
    return out;
}
/**
 * @brief scale the matrix and return the result
 * 
 * @param s the scale to scale the matrix
 * @return mat2 the scaled matrix
 */
mat2 mat2::operator*(float s)
{
    mat2 out;
    out.m[0][0] = m[0][0]*s;
    out.m[1][0] = m[1][0]*s;
    out.m[0][1] = m[0][1]*s;
    out.m[1][1] = m[1][1]*s;
    return out;
}
/**
 * @brief multiply this matrix by an vector and return the result
 * 
 * @param v the vector
 * @return vec2 the product of this matrix and the vector
 */
vec2 mat2::operator*(vec2 v)
{
    vec2 out;
    out.x = m[0][0]*v.x + m[0][1]*v.y;
    out.y = m[1][0]*v.x + m[1][1]*v.y;
    return out;
}
/**
 * @brief multiply this matrix by another matrix
 * 
 * @param c the other matrix
 */
void mat2::operator*=(mat2 c)
{
    mat2 t = *this;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            t.m[i][j] = m[i][0] * c.m[0][j] + m[i][1] * c.m[1][j];
        }
    }
    *this = t;
}
/**
 * @brief scale this matrix
 * 
 * @param s the scale
 */
void mat2::operator*=(float s)
{
    m[0][0] *= s;
    m[1][0] *= s;
    m[0][1] *= s;
    m[1][1] *= s;
}

/////////////////
//EXPERIMENTAL!//
/////////////////
/**
 * @brief calculate the determinant of this matrix
 * 
 * @return float the determinant of this matrix
 */
float mat2::determinant()
{
    return (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
}

/**
 * @brief calculate the invers of the matrix
 * 
 * @return mat2 the inverse matrix
 */
mat2 mat2::inverse()
{
    mat2 out = *this;
    //divide 1 by the determinant of the matrix
    float det = 1/out.determinant();
    //do the inverse thingy
    out.m[0][0] = m[1][1]*det; out.m[0][1] = -m[0][1]*det;
    out.m[1][0] = -m[1][0]*det; out.m[1][1] = m[0][0]*det;
    //return the matrix
    return out;
}