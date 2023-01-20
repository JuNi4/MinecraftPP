#include "CMLVec2.h"
#include <math.h>

vec2::vec2()
{
    x = 0;
    y = 0;
}

vec2::vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec2 vec2::operator+(vec2 v)
{
    return vec2(this->x+v.x,this->y+v.y);
}

void vec2::operator+=(vec2 v)
{
    this->x += v.x;
    this->y += v.y;
}

vec2 vec2::operator-(vec2 v)
{
    return vec2(this->x-v.x,this->y-v.y);
}

void vec2::operator-=(vec2 v)
{
    this->x -= v.x;
    this->y -= v.y;
}

float vec2::operator*(vec2 v)
{
    return (this->x*v.x) + (this->y*v.y);
}

void vec2::operator*=(vec2 v)
{
    this->x *= v.x;
    this->y *= v.y;
}

vec2 vec2::operator/(vec2 v)
{
    return vec2(this->x/v.x,this->y/v.y);
}

void vec2::operator/=(vec2 v)
{
    this->x /= v.x;
    this->y /= v.y;
}

bool vec2::operator==(vec2 v)
{
    return((this->x==v.x)&&(this->y==v.y));
}

bool vec2::operator>=(vec2 v)
{
    return((this->x>=v.x)&&(this->y>=v.y));
}

bool vec2::operator<=(vec2 v)
{
    return((this->x<=v.x)&&(this->y<=v.y));
}

bool vec2::operator<(vec2 v)
{
    return((this->x<v.x)&&(this->y<v.y));
}

bool vec2::operator>(vec2 v)
{
    return((this->x>v.x)&&(this->y>v.y));
}

float vec2::length()
{
    return std::sqrt((this->x*this->x)+(this->y*this->y));
}

void vec2::normalize()
{
    float len = this->length();
    this->x /= len;
    this->y /= len;
}

vec2 vec2::scale(vec2 v)
{
    return vec2(this->x*v.x,this->y*v.y);
}