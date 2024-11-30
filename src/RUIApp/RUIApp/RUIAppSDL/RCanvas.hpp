#pragma once
#include"framework.h"
class RUI_SDL_EXPORTS RCanvas
{
	LIB_TYPE(SDL_Renderer)* m_pRenderer;
	LIB_TYPE(TTF_Font)* m_pSmallFont;
	LIB_TYPE(TTF_Font)* m_pNormFont;
	unsigned m_drawColor;

public:
	RCanvas(SDL_Renderer* p,LIB_TYPE(TTF_Font)* pSmall, LIB_TYPE(TTF_Font)* pNorm)
		:m_pRenderer(p),
		 m_pSmallFont(pSmall),
		 m_pNormFont(pNorm)
	{}
	void draw_rect(int x, int y, int w, int h);
	void draw_text(int size,int x, int y, const char* lpszText);
};

