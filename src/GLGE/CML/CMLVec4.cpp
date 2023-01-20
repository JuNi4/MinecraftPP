#include "CMLVec4.h"
#include <math.h>

vec4::vec4()
{
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

vec4::vec4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vec4 vec4::operator+(vec4 v)
{
    return vec4(this->x+v.x,this->y+v.y,this->z+v.z,this->w+w);
}

void vec4::operator+=(vec4 v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z; 
    this->w += v.w;
}

vec4 vec4::operator-(vec4 v)
{
    return vec4(this->x-v.x,this->y-v.y,this->z-v.z,this->w-v.w);
}

void vec4::operator-=(vec4 v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    this->w -= v.w;
}

float vec4::operator*(vec4 v)
{
    return (this->x*v.x) + (this->y*v.y) + (this->z*v.z) + (this->w*v.w);
}

void vec4::operator*=(vec4 v)
{
    this->x *= v.x;
    this->y *= v.y;
    this->z *= v.z;
    this->w *= v.w;
}

vec4 vec4::operator/(vec4 v)
{
    return vec4(this->x/v.x,this->y/v.y,this->z/v.z,this->w/v.w);
}

void vec4::operator/=(vec4 v)
{
    this->x /= v.x;
    this->y /= v.y;
    this->z /= v.z;
    this->w /= v.w;
}

bool vec4::operator==(vec4 v)
{
    return((this->x==v.x)&&(this->y==v.y)&&(this->z==v.z)&&(this->w==v.w));
}

bool vec4::operator>=(vec4 v)
{
    return((this->x>=v.x)&&(this->y>=v.y)&&(this->z>=v.z)&&(this->w>=v.w));
}

bool vec4::operator<=(vec4 v)
{
    return((this->x<=v.x)&&(this->y<=v.y)&&(this->z<=v.z)&&(this->w<=v.w));
}

bool vec4::operator<(vec4 v)
{
    return((this->x<v.x)&&(this->y<v.y)&&(this->z<v.z)&&(this->w<v.w));
}

bool vec4::operator>(vec4 v)
{
    return((this->x>v.x)&&(this->y>v.y)&&(this->z>v.z)&&(this->w>v.w));
}

float vec4::length()
{
    return std::sqrt((this->x*this->x)+(this->y*this->y)+(this->z*this->z)+(this->w*this->w));
}

void vec4::normalize()
{
    float len = this->length();
    this->x /= len;
    this->y /= len;
    this->z /= len;
    this->w /= len;
}

vec4 vec4::scale(vec4 v)
{
    return vec4(this->x*v.x,this->y*v.y,this->z*v.z,this->w*v.w);
}