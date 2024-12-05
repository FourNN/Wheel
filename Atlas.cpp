#include "Atlas.h"

void Atlas::clear()
{
    img_list.clear();
}
void Atlas::add_image(const IMAGE& img)
{
    img_list.push_back(img);
}

int Atlas::get_size() const
{
    return static_cast<int>(img_list.size());
}

IMAGE* Atlas::get_image(int idx)
{
    if(idx<0||idx>=img_list.size())return nullptr;
    return &img_list[idx];
}

void Atlas::load(LPCTSTR path_template, int num)
{
    img_list.clear();
    img_list.resize(num);
    TCHAR path_file[256];
    for(size_t i=0;i<num;i++)
    {
        _stprintf_s(path_file,path_template,i+1);
        loadimage(&img_list[i],path_file);
    }
}




