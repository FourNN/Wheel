#include "Vector2.h"



Vector2 Vector2::operator+(const Vector2& vec) const
{
    return Vector2{_x+vec._x,_y+vec._y};
}
Vector2& Vector2::operator+=(const Vector2& vec)
{
    _x+=vec._x;
    _y+=vec._y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
    return Vector2{_x-vec._x,_y-vec._y};
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
    _x-=vec._x;
    _y-=vec._y;
    return *this;
}
Vector2 Vector2::operator*(float val) const
{
    return Vector2{_x*val,_y*val};
}

float Vector2::operator*(const Vector2& vec) const
{
    return _x*vec._x+_y*vec._y;
}

Vector2& Vector2::operator*=(float val)
{
    _x*=val;
    _y*=val;
    return *this;
}

Vector2 Vector2::operator/(float val) const
{
    return Vector2{_x/val,_y/val};
}

Vector2& Vector2::operator/=(float val)
{
    _x/=val;
    _y/=val;
    return *this;
}

float Vector2::length()
{
    return sqrt(_x*_x+_y*_y);
}

Vector2 Vector2::normalize()
{
    float len=length();
    if(len==0.0f)return Vector2{0,0};
    return Vector2{_x/len,_y/len};
}

bool Vector2::approx(const Vector2& target)const
{
    return (*this-target).length()<=0.0001f;
}








