#include "CMLMat3.h"

mat3::mat3()
{
    m[0][0] = 0; m[0][1] = 0; m[0][2] = 0;
    m[1][0] = 0; m[1][1] = 0; m[1][2] = 0;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = 0;
}
mat3::mat3(float m00, float m01, float m02, 
        float m10, float m11, float m12,
        float m20, float m21, float m22)
{
    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
}

mat3 mat3::operator+(mat3 c)
{
    return mat3(m[0][0] + c.m[0][0], m[0][1] + c.m[0][1], m[0][2] + c.m[0][2],
                m[1][0] + c.m[1][0], m[1][1] + c.m[1][1], m[1][2] + c.m[1][2],
                m[2][0] + c.m[2][0], m[2][1] + c.m[2][1], m[2][2] + c.m[2][2]);
}
mat3 mat3::operator+(float c)
{
    return mat3(m[0][0] + c, m[0][1] + c, m[0][2] + c,
                m[1][0] + c, m[1][1] + c, m[1][2] + c,
                m[2][0] + c, m[2][1] + c, m[2][2] + c);
}
void mat3::operator+=(mat3 c)
{
    m[0][0] += c.m[0][0]; m[0][1] += c.m[0][1]; m[0][2] += c.m[0][2];
    m[1][0] += c.m[1][0]; m[1][1] += c.m[1][1]; m[1][2] += c.m[1][2];
    m[2][0] += c.m[2][0]; m[2][1] += c.m[2][1]; m[2][2] += c.m[2][2];
}
void mat3::operator+=(float c)
{
    m[0][0] += c; m[0][1] += c; m[0][2] += c;
    m[1][0] += c; m[1][1] += c; m[1][2] += c;
    m[2][0] += c; m[2][1] += c; m[2][2] += c;
}

mat3 mat3::operator-(mat3 c)
{
    return mat3(m[0][0] - c.m[0][0], m[0][1] - c.m[0][1], m[0][2] - c.m[0][2],
                m[1][0] - c.m[1][0], m[1][1] - c.m[1][1], m[1][2] - c.m[1][2],
                m[2][0] - c.m[2][0], m[2][1] - c.m[2][1], m[2][2] - c.m[2][2]);
}
mat3 mat3::operator-(float c)
{
    return mat3(m[0][0] - c, m[0][1] - c, m[0][2] - c,
                m[1][0] - c, m[1][1] - c, m[1][2] - c,
                m[2][0] - c, m[2][1] - c, m[2][2] - c);
}
void mat3::operator-=(mat3 c)
{
    m[0][0] -= c.m[0][0]; m[0][1] -= c.m[0][1]; m[0][2] -= c.m[0][2];
    m[1][0] -= c.m[1][0]; m[1][1] -= c.m[1][1]; m[1][2] -= c.m[1][2];
    m[2][0] -= c.m[2][0]; m[2][1] -= c.m[2][1]; m[2][2] -= c.m[2][2];
}
void mat3::operator-=(float c)
{
    m[0][0] -= c; m[0][1] -= c; m[0][2] -= c;
    m[1][0] -= c; m[1][1] -= c; m[1][2] -= c;
    m[2][0] -= c; m[2][1] -= c; m[2][2] -= c;
}

mat3 mat3::operator*(mat3 c)
{
    mat3 out;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            out.m[i][j] = m[i][0] * c.m[0][j] + m[i][1] * c.m[1][j];
        }
    }
    return out;
}
mat3 mat3::operator*(float s)
{
    mat3 out;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            out.m[i][j] *= s;
        }
    }
    return out;
}
vec3 mat3::operator*(vec3 v)
{
    vec3 out;
    out.x = m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z;
    out.y = m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z;
    out.z = m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z;
    return out;
}
void mat3::operator*=(mat3 c)
{
    mat3 t = *this;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            t.m[i][j] = m[i][0] * c.m[0][j] + m[i][1] * c.m[1][j];
        }
    }
    *this = t;
}
void mat3::operator*=(float s)
{
    mat3 t = *this;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            t.m[i][j] *= s;
        }
    }
    *this = t;
}
