#pragma once
#include "Camera.h"
#include <graphics.h>
#pragma comment(lib,"WINMM.lib")
#pragma comment(lib,"MSIMG32.lib")

struct Rect
{
    int x,y;
    int w,h;
};

inline void putimage_ex(const Camera&camera,IMAGE*image,const Rect*rect_dst,const Rect*rect_src=nullptr)
{
    static BLENDFUNCTION blend_function={AC_SRC_OVER,0,255,AC_SRC_ALPHA};
    const Vector2&pos_camera=camera.get_position();
    AlphaBlend(
        GetImageHDC(GetWorkingImage()),
        static_cast<int>(rect_dst->x-pos_camera._x),
        static_cast<int>(rect_dst->y-pos_camera._y),
        rect_dst->w,
        rect_dst->h,
        GetImageHDC(image),
        rect_src?rect_src->x:0,
        rect_src?rect_src->y:0,
        rect_src?rect_src->w:image->getwidth(),
        rect_src?rect_src->h:image->getheight(),
        blend_function
        );
}

inline void load_audio(LPCTSTR path,LPCTSTR id)
{
    static TCHAR str_cmd[512];
    _stprintf_s(str_cmd,_T("open %s alias %s"),path,id);
    mciSendString(str_cmd,nullptr,0,nullptr);
    
}

inline void play_audio(LPCTSTR id,bool is_loop=false)
{
    static TCHAR str_cmd[512];
    _stprintf_s(str_cmd,_T("play %s %s from 0"),id,is_loop?_T("repeat"):_T(""));
    mciSendString(str_cmd,nullptr,0,nullptr);
}

inline void stop_audio(LPCTSTR id)
{
    static TCHAR str_cmd[512];
    _stprintf_s(str_cmd,_T("stop %s"),id);
    mciSendString(str_cmd,nullptr,0,nullptr);
}