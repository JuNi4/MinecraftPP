#include "CMLQuaternion.h"
#include <math.h>
#include <iostream>

Quaternion::Quaternion()
{
    w = 0;
    x = 0;
    y = 0;
    z = 0;
}

Quaternion::Quaternion(float w, float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Quaternion::Quaternion(float Angle, vec3 v)
{
    float HalfAngleInRadians = (Angle/2.f);

    float sinHalfAngle = std::sin(HalfAngleInRadians);
    float cosHalfAngle = std::cos(HalfAngleInRadians);

    x = v.x * sinHalfAngle;
    y = v.y * sinHalfAngle;
    z = v.z * sinHalfAngle;
    w = cosHalfAngle;
}

Quaternion::~Quaternion(){}

Quaternion Quaternion::operator+(Quaternion q)
{
    return Quaternion(this->w+q.w,this->x+q.x,this->y+q.y,this->z+q.z);
}
void Quaternion::operator+=(Quaternion q)
{
    this->x += q.x;
    this->y += q.y;
    this->z += q.z;
    this->w += q.w;
}

Quaternion Quaternion::operator-(Quaternion q)
{
    return Quaternion(this->w-q.w,this->x-q.x,this->y-q.y,this->z-q.z);
}
void Quaternion::operator-=(Quaternion q)
{
    this->x -= q.x;
    this->y -= q.y;
    this->z -= q.z;
    this->w -= q.w;
}

Quaternion Quaternion::operator*(Quaternion q)
{
    Quaternion out;
    out.w = (w*q.w) - (x*q.x) - (y*q.y) - (z*q.z);
    out.x = (x*q.w) + (w*q.x) + (y*q.z) - (z*q.y);
    out.y = (y*q.w) + (w*q.y) + (z*q.x) - (x*q.z);
    out.z = (z*q.w) + (w*q.z) + (x*q.y) - (y*q.x);
    return out;
}
Quaternion Quaternion::operator*(vec3 v)
{
    float nw = - (x*v.x) - (y*v.y) - (z*v.z);
    float nx =   (w*v.x) + (y*v.z) - (z*v.y);
    float ny =   (w*v.y) + (z*v.x) - (x*v.z);
    float nz =   (w*v.z) + (x*v.y) - (y*v.x);
    return Quaternion(nw,nx,ny,nz);
}
void Quaternion::operator*=(Quaternion q)
{
    Quaternion out = *this;
    out.w = (w*q.w) - (x*q.x) - (y*q.y) - (z*q.z);
    out.x = (x*q.w) + (w*q.x) + (y*q.z) - (z*q.y);
    out.y = (y*q.w) + (w*q.y) + (z*q.x) - (x*q.z);
    out.z = (z*q.w) + (w*q.z) + (x*q.y) - (y*q.x);
    *this = out;
}

Quaternion Quaternion::operator/(Quaternion q)
{
    return Quaternion(this->w/q.w,this->x/q.x,this->y/q.y,this->z/q.z);
}
void Quaternion::operator/=(Quaternion q)
{
    this->w /= q.w;
    this->x /= q.x;
    this->y /= q.y;
    this->z /= q.z;
}

Quaternion Quaternion::operator/(float f)
{
    return Quaternion(this->w/f,this->x/f,this->y/f,this->z/f);
}
void Quaternion::operator/=(float f)
{
    this->w /= f;
    this->x /= f;
    this->y /= f;
    this->z /= f;
}

Quaternion Quaternion::conjugate()
{
    return Quaternion(w, -x, -y, -z);
}
void Quaternion::conjugateThis()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
}

float Quaternion::length()
{
    return std::sqrt((this->w*this->w)+(this->x*this->x)+(this->y*this->y)+(this->z*this->z));
}

Quaternion Quaternion::normal()
{
    float len = this->length();
    return Quaternion(this->w/len, this->x/len, this->y/len, this->z/len);
}
void Quaternion::normalizeThis()
{
    float len = this->length();
    this->w /= len;
    this->x /= len;
    this->y /= len;
    this->z /= len;
}

Quaternion Quaternion::invert()
{
    Quaternion out  = *this;
    float lens = out.length(); lens *= lens;
    out.conjugateThis();
    out /= lens;
    return out;
}
void Quaternion::invertThis()
{
    float lens = this->length(); lens*=lens;
    this->conjugate();
    *this /= lens;
}