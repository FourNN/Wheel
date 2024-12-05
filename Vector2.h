#pragma once
#include <cmath>


class Vector2
{
public:
    float _x=0;
    float _y=0;
    Vector2()=default;
    ~Vector2()=default;
    Vector2(float x,float y):_x(x),_y(y){}
    Vector2 operator+(const Vector2&vec)const;
    Vector2& operator+=(const Vector2&vec);
    Vector2& operator-=(const Vector2&vec);
    Vector2 operator-(const Vector2&vec)const;
    float operator*(const Vector2&vec)const;
    Vector2 operator*(float val)const;
    Vector2& operator*=(float val);
    Vector2 operator/(float val)const;
    Vector2& operator/=(float val);
    float length();
    Vector2 normalize();
    bool approx(const Vector2&target)const;

    
};
