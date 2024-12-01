#pragma once
#include"framework.h"
class RColor: public SDL_Color{
public:
    RColor(unsigned c){
        this->r =((c & 0x00FF0000)>>16);

    }
};