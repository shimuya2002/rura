#include "pch.h"
#include "RCanvas.hpp"
#include"RRect.hpp"
#include"RColor.hpp"
void RCanvas::draw_rect(int x, int y, int w, int h) {
	RRect rect(x, y, w, h);
	SDL_RenderDrawRect(this->m_pRenderer, &rect);
}
void RCanvas::draw_text(int size, int x, int y, const char* lpszText) {
	this->draw_text(size,x,y,nullptr,nullptr,lpszText);
}
void RCanvas::draw_text(int size,int x, int y,int * w,int *h, const char* lpszText){

	RColor color(this->m_drawColor);
	SDL_Surface* pSurf=TTF_RenderText_Solid(0 == size ? this->m_pSmallFont : this->m_pNormFont, lpszText, color);
	if (nullptr != pSurf) {

		SDL_Texture* pTex=SDL_CreateTextureFromSurface(this->m_pRenderer, pSurf);
		if(nullptr!=w){
			*w=pSurf->w;
		}
		if(nullptr!=h){
			*h=pSurf->h;
		}
		if (nullptr != pTex) {
			RRect src(0, 0, pSurf->w, pSurf->h);
			RRect dst(x, y, x+pSurf->w, y+pSurf->h);
			SDL_RenderCopy(this->m_pRenderer, pTex, &src, &dst);
		
			SDL_DestroyTexture(pTex);
		}else{
		//	std::cerr<<__FILE__ << " "<<__LINE__<<":Failed to create text source texture."<<std::endl;

		}
		SDL_FreeSurface(pSurf);
	}else{
		//std::cerr<<__FILE__ << " "<<__LINE__<<":Failed to create font render surface."<<std::endl;
	}
}
bool RCanvas::draw_button(int x,int y,const char* lpszText){
	int w,h;
	this->draw_text(1, x,y,&w,&h,lpszText);
	this->draw_rect(x,y,w,h);
	if(this->m_mouse_state.leftButtonDown &&
	   (this->m_mouse_state.x>x && (x+w)>this->m_mouse_state.x) &&
	   (this->m_mouse_state.y>y && (y+h)>this->m_mouse_state.y)){
		return true;
	}
	return false;
}
int RCanvas::get_canvas_width(){
	return m_canvasW;
}
int RCanvas::get_canvas_height(){
	return m_canvasH;
}
