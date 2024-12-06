#pragma once
#include"framework.h"
struct RMouseState{

	int x,y;
	bool leftButtonDown;
};
class RUI_SDL_EXPORTS RCanvas
{
	LIB_TYPE(SDL_Renderer)* m_pRenderer;
	LIB_TYPE(TTF_Font)* m_pSmallFont;
	LIB_TYPE(TTF_Font)* m_pNormFont;
	unsigned m_drawColor;
	RMouseState m_mouse_state;
public:
	RCanvas(LIB_TYPE(SDL_Renderer)* p,LIB_TYPE(TTF_Font)* pSmall, LIB_TYPE(TTF_Font)* pNorm,RMouseState& mState)
		:m_pRenderer(p),
		 m_pSmallFont(pSmall),
		 m_pNormFont(pNorm),
		 m_mouse_state(mState)
	{}
	void draw_rect(int x, int y, int w, int h);
	void draw_text(int size,int x, int y, const char* lpszText);
	void set_draw_color(unsigned c){
		this->m_drawColor=c;
	}
	bool draw_button(int x,int y,const char* lpszText);

private:
	void draw_text(int size,int x, int y,int * w,int *h, const char* lpszText);

};

