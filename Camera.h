#pragma once
#include "Vector2.h"
class Camera
{
public:
    Camera()=default;
    ~Camera()=default;
    void set_size(const Vector2 vec);
    const Vector2& get_size()const;
    void set_position(const Vector2 pos);
    const Vector2& get_position()const;
    void look_at(const Vector2&target);
private:
    Vector2 size;
    Vector2 position;
};
