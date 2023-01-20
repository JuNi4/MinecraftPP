#include "CMLVector.h"
#include <math.h>

vec::vec()
{
    this->val = {};
}

vec::vec(std::vector<float> vals)
{
    this->val = vals;
}

int vec::size()
{
    return this->val.size();
}

float vec::getComponent(int id)
{
    return val[id];
}

std::vector<float> vec::getContent()
{
    return val;
}

void vec::setId(int i, float v)
{
    this->val[i] = v;
}

void vec::set(std::vector<float> vals, int start)
{
    for(int i = 0; i < (int)vals.size(); i++)
    {
        this->val[start+i] = vals[i];
    }
}

std::string vec::print()
{
    std::string out;
    for(int i = 0; i < this->size(); i++)
    {
        out.append(std::to_string(this->val[i]));
        if(i != this->size())
        {
            out.append(", ");
        }
    }
    return out;
}

vec vec::operator+(vec v)
{
    if(this->size() != v.size())
    {
        return vec();
    }
    std::vector<float> t = v.getContent();
    vec out;
    for(int i = 0; i < this->size(); i++)
    {
        out.setId(i, this->val[i]+t[i]);
    }
    return out;
}
void vec::operator+=(vec v)
{
    if(this->size() != v.size())
    {
        return;
    }
    for(int i = 0; i < this->size(); i++)
    {
        this->val[i] += v.getComponent(i);
    }
}

vec vec::operator-(vec v)
{
    if(this->size() != v.size())
    {
        return vec();
    }
    std::vector<float> t = v.getContent();
    vec out;
    for(int i = 0; i < this->size(); i++)
    {
        out.setId(i, this->val[i]-t[i]);
    }
    return out;
}
void vec::operator-=(vec v)
{
    if(this->size() != v.size())
    {
        return;
    }
    for(int i = 0; i < this->size(); i++)
    {
        this->val[i] -= v.getComponent(i);
    }
}

float vec::operator*(vec v)
{
    if(this->size() != v.size())
    {
        return -1.f;
    }

    float out;
    for(int i = 0; i < this->size(); i++)
    {
        out += (this->val[i]*v.getComponent(i));
    }
    return out;
}

vec vec::operator/(vec v)
{
    if(this->size() != v.size())
    {
        return vec();
    }

    std::vector<float> out;
    for(int i = 0; i < this->size(); i++)
    {
        out[i] = this->val[i]/v.getComponent(i);
    }
    return vec(out);
}
vec vec::operator/(float v)
{
    std::vector<float> out;
    for(int i = 0; i < this->size(); i++)
    {
        out[i] = this->val[i]/v;
    }
    return vec(out);
}

void vec::operator/=(vec v)
{
    if(this->size() != v.size())
    {
        return;
    }

    for(int i = 0; i < this->size(); i++)
    {
        this->val[i] /= v.getComponent(i);
    }
}
void vec::operator/=(float v)
{
    for(int i = 0; i < this->size(); i++)
    {
        this->val[i] /= v;
    }
}

float vec::length()
{
    float out;
    for(int i = 0; i < this->size(); i++)
    {
        out += this->val[i]*this->val[i];
    }
    std::sqrt(out);
    return out;
}