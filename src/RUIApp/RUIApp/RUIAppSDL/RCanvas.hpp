#pragma once
#include"framework.h"
class RUI_SDL_EXPORTS RCanvas
{
	LIB_TYPE(SDL_Renderer)* m_pRenderer;

public:
	RCanvas(SDL_Renderer* p)
		:m_pRenderer(p)
	{}

};

