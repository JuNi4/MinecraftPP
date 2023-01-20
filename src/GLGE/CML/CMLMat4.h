#ifndef _CMLMAT4_H_
#define _CMLMAT4_H_
#pragma once
#include "CMLVec4.h"

struct mat4
{
    float m[4][4];

    mat4();
    mat4(float m00, float m01, float m02, float m03,
         float m10, float m11, float m12, float m13,
         float m20, float m21, float m22, float m23,
         float m30, float m31, float m32, float m33);

    mat4 operator+(mat4 c);
    mat4 operator+(float c);
    void operator+=(mat4 c);
    void operator+=(float c);

    mat4 operator-(mat4 c);
    mat4 operator-(float c);
    void operator-=(mat4 c);
    void operator-=(float c);

    mat4 operator*(mat4 c);
    mat4 operator*(float s);
    vec4 operator*(vec4 v);
    void operator*=(mat4 c);
    void operator*=(float s);
};

#endif