#pragma once
#include"framework.h"
class RRect:public SDL_Rect{
public:
    RRect(int _x,int _y,int  _w,int  _h){
        this->x=_x;
        this->y=_y;
        this->w=_w;
        this->h=_h;
    }
};