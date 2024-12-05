#include "Camera.h"

#include "Atlas.h"

const Vector2& Camera::get_position() const
{
    return position;
}

const Vector2& Camera::get_size() const
{
    return size;
}

void Camera::set_size(const Vector2 vec)
{
    this->size=vec;
}

void Camera::set_position(const Vector2 pos)
{
    this->position=pos;
}

void Camera::look_at(const Vector2& target)
{
    position=target-size/2.0f;
}



