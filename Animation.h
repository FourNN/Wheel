#pragma once
#include "Util.h"
#include "Timer.h"
#include "Atlas.h"
#include "Vector2.h"
#include <vector>
#include <functional>


class Animation
{
public:
    Animation();
    ~Animation()=default;
    void reset();
    void set_position(const Vector2&position);
    void set_loop(bool is_loop);
    void set_interval(float interval);
    void set_on_finished(std::function<void()>on_finished);
    void add_frame(IMAGE*image,int num_h);
    void add_frame(Atlas*atlas);
    void on_update(float delta);
    void on_render(const Camera&camera);
    
private:
    struct Frame
    {
        Rect rect_src;
        IMAGE*image;
        Frame()=default;
        ~Frame()=default;
        Frame(IMAGE*image,const Rect&rect_src):image(image),rect_src(rect_src){}
    };
    Timer timer_;
    Vector2 position_;
    bool is_loop=false;
    size_t idx_frame=0;
    std::vector<Frame>frame_list_;
    std::function<void()>on_finished_;
};
