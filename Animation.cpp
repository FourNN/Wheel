#include "Animation.h"

void Animation::set_interval(float interval)
{
    timer_.set_wait_time(interval);
}

void Animation::on_update(float delta)
{
    timer_.on_update(delta);
}

void Animation::reset()
{
    timer_.restart();
    idx_frame=0;
}

void Animation::set_loop(bool is_loop)
{
    this->is_loop=is_loop;
}

void Animation::set_on_finished(std::function<void()>on_finished)
{
    this->on_finished_=on_finished;
}

void Animation::add_frame(Atlas* atlas)
{
    for(size_t i=0;i<atlas->get_size();i++)
    {
        IMAGE*image=atlas->get_image(static_cast<int>(i));
        int width=image->getwidth();
        int height=image->getheight();
        Rect rect_src;
        rect_src.x=0;
        rect_src.y=0;
        rect_src.w=width;
        rect_src.h=height;
        frame_list_.emplace_back(image,rect_src);
        
    }
}

Animation::Animation()
{
    timer_.set_one_shoot(false);
    timer_.set_on_time_out([&]()
    {
        idx_frame++;
        if(idx_frame>=frame_list_.size())
        {
            idx_frame=is_loop?0:frame_list_.size()-1;
        }
        
    });
}

void Animation::on_render(const Camera& camera)
{
    const Frame&frame=frame_list_[idx_frame];
    Rect rect_dst;
    rect_dst.x=static_cast<int>(position_._x-(frame.rect_src.w/2));
    rect_dst.y=static_cast<int>(position_._y-(frame.rect_src.h/2));
    rect_dst.w=frame.rect_src.w;
    rect_dst.h=frame.rect_src.h;
    putimage_ex(
        camera,
        frame.image,
        &rect_dst,
        &frame.rect_src
        );
}

void Animation::set_position(const Vector2& position)
{
    this->position_=position;
}

void Animation::add_frame(IMAGE* image, int num_h)
{
    int width=image->getwidth();
    int height=image->getheight();
    int width_frame=width/num_h;
    for(size_t i=0;i<num_h;i++)
    {
        Rect rect_src;
        rect_src.x=i*width_frame;
        rect_src.y=0;
        rect_src.w=width_frame;
        rect_src.h=height;
        frame_list_.emplace_back(image,rect_src);
    }
}




