#ifndef _CMLVEC3_H_
#define _CMLVEC3_H_
#pragma once

struct vec3
{
    float x,y,z;

    vec3();

    vec3(float x, float y, float z);

    vec3 operator+(vec3 v);

    void operator+=(vec3 v);

    vec3 operator-(vec3 v);

    void operator-=(vec3 v);

    float operator*(vec3 v);

    void operator*=(vec3 v);

    vec3 operator/(vec3 v);

    void operator/=(vec3 v);

    bool operator==(vec3 v);

    bool operator>=(vec3 v);

    bool operator<=(vec3 v);

    bool operator<(vec3 v);

    bool operator>(vec3 v);

    float length();

    void normalize();

    vec3 cross(vec3 v);

    vec3 scale(vec3 v);
};

#endif