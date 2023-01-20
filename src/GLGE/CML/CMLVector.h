#ifndef _CMLVECTOR_H_
#define _CMLVECTOR_H_
#pragma once
#include <string>
#include <vector>

class vec
{
public:
    vec();

    vec(std::vector<float> vals);

    int size();

    float getComponent(int id);

    std::vector<float> getContent();

    void setId(int i, float v);

    void set(std::vector<float> vals, int start);

    std::string print();

    vec operator+(vec v);
    void operator+=(vec v);

    vec operator-(vec v);
    void operator-=(vec v);

    float operator*(vec v);

    vec operator/(vec v);
    vec operator/(float v);

    void operator/=(vec v);
    void operator/=(float v);

    float length();

private:
    std::vector<float> val;
};

#endif