#ifndef _CMLVEC2_H_
#define _CMLVEC2_H_
#pragma once

struct vec2
{
    float x,y;

    vec2();

    vec2(float x, float y);

    vec2 operator+(vec2 v);

    void operator+=(vec2 v);

    vec2 operator-(vec2 v);

    void operator-=(vec2 v);

    float operator*(vec2 v);

    void operator*=(vec2 v);

    vec2 operator/(vec2 v);

    void operator/=(vec2 v);

    bool operator==(vec2 v);

    bool operator>=(vec2 v);

    bool operator<=(vec2 v);

    bool operator<(vec2 v);

    bool operator>(vec2 v);

    float length();

    void normalize();

    vec2 scale(vec2 v);
};

#endif