#include "CMLMat4.h"

mat4::mat4()
{
    m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
    m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
    m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
    m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
}
mat4::mat4(float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33)
{
    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
    m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}

mat4 mat4::operator+(mat4 c)
{
    return mat4(m[0][0] + c.m[0][0], m[0][1] + c.m[0][1], m[0][2] + c.m[0][2], m[0][3] + c.m[0][3],
                m[1][0] + c.m[1][0], m[1][1] + c.m[1][1], m[1][2] + c.m[1][2], m[1][3] + c.m[1][3],
                m[2][0] + c.m[2][0], m[2][1] + c.m[2][1], m[2][2] + c.m[2][2], m[2][3] + c.m[2][3],
                m[3][0] + c.m[3][0], m[3][1] + c.m[3][1], m[3][2] + c.m[3][2], m[3][3] + c.m[3][3]);
}
mat4 mat4::operator+(float c)
{
    return mat4(m[0][0] + c, m[0][1] + c, m[0][2] + c, m[0][3] + c,
                m[1][0] + c, m[1][1] + c, m[1][2] + c, m[1][3] + c,
                m[2][0] + c, m[2][1] + c, m[2][2] + c, m[2][3] + c,
                m[3][0] + c, m[3][1] + c, m[3][2] + c, m[3][3] + c);
}
void mat4::operator+=(mat4 c)
{
    m[0][0] += c.m[0][0]; m[0][1] += c.m[0][1]; m[0][2] += c.m[0][2]; m[0][3] += c.m[0][3];
    m[1][0] += c.m[1][0]; m[1][1] += c.m[1][1]; m[1][2] += c.m[1][2]; m[1][3] += c.m[1][3];
    m[2][0] += c.m[2][0]; m[2][1] += c.m[2][1]; m[2][2] += c.m[2][2]; m[2][3] += c.m[2][3];
    m[3][0] += c.m[3][0]; m[3][1] += c.m[3][1]; m[3][2] += c.m[3][2]; m[3][3] += c.m[3][3];
}
void mat4::operator+=(float c)
{
    m[0][0] += c; m[0][1] += c; m[0][2] += c; m[0][3] += c;
    m[1][0] += c; m[1][1] += c; m[1][2] += c; m[1][3] += c;
    m[2][0] += c; m[2][1] += c; m[2][2] += c; m[2][3] += c;
    m[3][0] += c; m[3][1] += c; m[3][2] += c; m[3][3] += c;
}

mat4 mat4::operator-(mat4 c)
{
    return mat4(m[0][0] - c.m[0][0], m[0][1] - c.m[0][1], m[0][2] - c.m[0][2], m[0][3] - c.m[0][3],
                m[1][0] - c.m[1][0], m[1][1] - c.m[1][1], m[1][2] - c.m[1][2], m[1][3] - c.m[1][3],
                m[2][0] - c.m[2][0], m[2][1] - c.m[2][1], m[2][2] - c.m[2][2], m[2][3] - c.m[2][3],
                m[3][0] - c.m[3][0], m[3][1] - c.m[3][1], m[3][2] - c.m[3][2], m[3][3] - c.m[3][3]);
}
mat4 mat4::operator-(float c)
{
    return mat4(m[0][0] - c, m[0][1] - c, m[0][2] - c, m[0][3] - c,
                m[1][0] - c, m[1][1] - c, m[1][2] - c, m[1][3] - c,
                m[2][0] - c, m[2][1] - c, m[2][2] - c, m[2][3] - c,
                m[3][0] - c, m[3][1] - c, m[3][2] - c, m[3][3] - c);
}
void mat4::operator-=(mat4 c)
{
    m[0][0] -= c.m[0][0]; m[0][1] -= c.m[0][1]; m[0][2] -= c.m[0][2]; m[0][3] -= c.m[0][3];
    m[1][0] -= c.m[1][0]; m[1][1] -= c.m[1][1]; m[1][2] -= c.m[1][2]; m[1][3] -= c.m[1][3];
    m[2][0] -= c.m[2][0]; m[2][1] -= c.m[2][1]; m[2][2] -= c.m[2][2]; m[2][3] -= c.m[2][3];
    m[3][0] -= c.m[3][0]; m[3][1] -= c.m[3][1]; m[3][2] -= c.m[3][2]; m[3][3] -= c.m[3][3];
}
void mat4::operator-=(float c)
{
    m[0][0] -= c; m[0][1] -= c; m[0][2] -= c; m[0][3] -= c;
    m[1][0] -= c; m[1][1] -= c; m[1][2] -= c; m[1][3] -= c;
    m[2][0] -= c; m[2][1] -= c; m[2][2] -= c; m[2][3] -= c;
    m[3][0] -= c; m[3][1] -= c; m[3][2] -= c; m[3][3] -= c;
}

mat4 mat4::operator*(mat4 c)
{
    mat4 out;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            float num = 0;
            for(int k = 0; k < 4; k++)
            {
                num += this->m[i][k]*c.m[k][j];
            }
            out.m[i][j] = num;
        }
    }
    return out;
}
mat4 mat4::operator*(float s)
{
    mat4 out;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            out.m[i][j] *= s;
        }
    }
    return out;
}
vec4 mat4::operator*(vec4 v)
{
    vec4 out;
    out.x = m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z + m[0][3]*v.w;
    out.y = m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z + m[1][3]*v.w;
    out.z = m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z + m[2][3]*v.w;
    out.w = m[3][0]*v.x + m[3][1]*v.y + m[3][2]*v.z + m[3][3]*v.w;
    return out;
}
void mat4::operator*=(mat4 c)
{
    mat4 t = *this;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            float num = 0;
            for(int k = 0; k < 4; k++)
            {
                num += this->m[i][k]*c.m[k][j];
            }
            t.m[i][j] = num;
        }
    }
    *this = t;
}
void mat4::operator*=(float s)
{
    mat4 t = *this;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            t.m[i][j] *= s;
        }
    }
    *this = t;
}