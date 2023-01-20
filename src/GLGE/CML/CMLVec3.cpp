#include "CMLVec3.h"
#include <math.h>

vec3::vec3()
{
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3 vec3::operator+(vec3 v)
{
    return vec3(this->x+v.x,this->y+v.y,this->z+v.z);
}

void vec3::operator+=(vec3 v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z; 
}

vec3 vec3::operator-(vec3 v)
{
    return vec3(this->x-v.x,this->y-v.y,this->z-v.z);
}

void vec3::operator-=(vec3 v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z; 
}

float vec3::operator*(vec3 v)
{
    return (this->x*v.x) + (this->y*v.y) + (this->z*v.z);
}

void vec3::operator*=(vec3 v)
{
    this->x *= v.x;
    this->y *= v.y;
    this->z *= v.z; 
}

vec3 vec3::operator/(vec3 v)
{
    return vec3(this->x/v.x,this->y/v.y,this->z/v.z);
}

void vec3::operator/=(vec3 v)
{
    this->x /= v.x;
    this->y /= v.y;
    this->z /= v.z; 
}

bool vec3::operator==(vec3 v)
{
    return((this->x==v.x)&&(this->y==v.y)&&(this->z==v.z));
}

bool vec3::operator>=(vec3 v)
{
    return((this->x>=v.x)&&(this->y>=v.y)&&(this->z>=v.z));
}

bool vec3::operator<=(vec3 v)
{
    return((this->x<=v.x)&&(this->y<=v.y)&&(this->z<=v.z));
}

bool vec3::operator<(vec3 v)
{
    return((this->x<v.x)&&(this->y<v.y)&&(this->z<v.z));
}

bool vec3::operator>(vec3 v)
{
    return((this->x>v.x)&&(this->y>v.y)&&(this->z>v.z));
}

float vec3::length()
{
    return std::sqrt((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
}

void vec3::normalize()
{
    float len = this->length();
    this->x /= len;
    this->y /= len;
    this->z /= len;
}

vec3 vec3::cross(vec3 v)
{
    return vec3((this->y*v.z) - (this->z*v.y), (this->z*v.x) - (this->x*v.z), (this->x*v.y) - (this->y*v.x));
}

vec3 vec3::scale(vec3 v)
{
    return vec3(this->x*v.x,this->y*v.y,this->z*v.z);
}