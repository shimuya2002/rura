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
	int m_canvasW,m_canvasH;
public:
	RCanvas(LIB_TYPE(SDL_Renderer)* p,LIB_TYPE(TTF_Font)* pSmall, LIB_TYPE(TTF_Font)* pNorm,RMouseState& mState,int w,int h)
		:m_pRenderer(p),
		 m_pSmallFont(pSmall),
		 m_pNormFont(pNorm),
		 m_mouse_state(mState),
		 m_canvasW(w),
		 m_canvasH(h)
	{}
	void draw_rect(int x, int y, int w, int h);
	void draw_text(int size,int x, int y, const char* lpszText);
	void set_draw_color(unsigned c){
		this->m_drawColor=c;
	}
	bool draw_button(int x,int y,const char* lpszText);
	int get_canvas_width();
	int get_canvas_height();
private:
	void draw_text(int size,int x, int y,int * w,int *h, const char* lpszText);

};

