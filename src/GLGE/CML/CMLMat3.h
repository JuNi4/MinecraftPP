#ifndef _CMLMAT3_H_
#define _CMLMAT3_H_
#pragma once
#include "CMLVec3.h"

struct mat3
{
    float m[3][3];

    mat3();
    mat3(float m00, float m01, float m02, 
         float m10, float m11, float m12,
         float m20, float m21, float m22);

    mat3 operator+(mat3 c);
    mat3 operator+(float c);
    void operator+=(mat3 c);
    void operator+=(float c);

    mat3 operator-(mat3 c);
    mat3 operator-(float c);
    void operator-=(mat3 c);
    void operator-=(float c);

    mat3 operator*(mat3 c);
    mat3 operator*(float s);
    vec3 operator*(vec3 v);
    void operator*=(mat3 c);
    void operator*=(float s);
};

#endif