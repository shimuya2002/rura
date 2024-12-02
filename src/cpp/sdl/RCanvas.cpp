#include "pch.h"
#include "RCanvas.hpp"
#include"RRect.hpp"
#include"RColor.hpp"
void RCanvas::draw_rect(int x, int y, int w, int h) {
	RRect rect(x, y, w, h);
	SDL_RenderDrawRect(this->m_pRenderer, &rect);
}
void RCanvas::draw_text(int size, int x, int y, const char* lpszText) {

	RColor color(this->m_drawColor);
	SDL_Surface* pSurf=TTF_RenderText_Solid(0 == size ? this->m_pSmallFont : this->m_pNormFont, lpszText, color);
	if (nullptr != pSurf) {

		SDL_Texture* pTex=SDL_CreateTextureFromSurface(this->m_pRenderer, pSurf);
		
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