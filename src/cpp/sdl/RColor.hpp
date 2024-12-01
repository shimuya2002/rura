#pragma once
#include"framework.h"
#define COLOR_WHITE (0xFFFFFFFF)

class RColor: public SDL_Color{
public:
    RColor(unsigned c){
        this->r =((c & 0x00FF0000)>>16);
        this->g=((c & 0x0000FF00)>>8);
        this->b=(c & 0x000000FF);
        this->a=((c & 0xFF000000)>>24);
    }
};

