#ifndef _CMLVEC4_H_
#define _CMLVEC4_H_
#pragma once

struct vec4
{
    float x,y,z,w;

    vec4();

    vec4(float x, float y, float z, float w);

    vec4 operator+(vec4 v);

    void operator+=(vec4 v);

    vec4 operator-(vec4 v);

    void operator-=(vec4 v);

    float operator*(vec4 v);

    void operator*=(vec4 v);

    vec4 operator/(vec4 v);

    void operator/=(vec4 v);

    bool operator==(vec4 v);

    bool operator>=(vec4 v);

    bool operator<=(vec4 v);

    bool operator<(vec4 v);

    bool operator>(vec4 v);

    float length();

    void normalize();

    vec4 scale(vec4 v);
};

#endif