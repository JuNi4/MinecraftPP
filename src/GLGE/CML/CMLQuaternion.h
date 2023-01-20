#include "CMLVec3.h"

#ifndef _CMLQUATERNION_H_
#define _CMLQUATERNION_H_
#pragma once

class Quaternion
{
public:
    float w,x,y,z;

    Quaternion();

    Quaternion(float w, float x, float y, float z);

    Quaternion(float Angle, vec3 vector);

    ~Quaternion();

    Quaternion operator+(Quaternion q);
    void operator+=(Quaternion q);

    Quaternion operator-(Quaternion q);
    void operator-=(Quaternion q);

    Quaternion operator*(Quaternion q);
    Quaternion operator*(vec3 v);
    void operator*=(Quaternion q);

    Quaternion operator/(Quaternion q);
    void operator/=(Quaternion q);

    Quaternion operator/(float f);
    void operator/=(float f);

    Quaternion conjugate();
    void conjugateThis();

    float length();

    Quaternion normal();
    void normalizeThis();

    Quaternion invert();
    void invertThis();
};

#endif