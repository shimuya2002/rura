#include "pch.h"
#include "RWindow.hpp"
RWindow::~RWindow() {
	this->release_font();
	close();
}

void RWindow::show() {
	this->show(640, 480);
}
void RWindow::show(int w, int h){
	if (nullptr == this->m_renderer && nullptr==this->m_window) {
		SDL_CreateWindowAndRenderer(w,h, SDL_WINDOW_OPENGL, &this->m_window, &this->m_renderer);
	}
	else {
		
	}
}
void RWindow::close() {
	if (nullptr != this->m_renderer) {
		SDL_DestroyRenderer(this->m_renderer);
		this->m_renderer = nullptr;
	}
	if (this->m_window) {
		SDL_DestroyWindow(this->m_window);
		this->m_window = nullptr;
	}
}
void  RWindow::onIdle() {
	if (nullptr != this->m_onIdle) {
		this->m_onIdle();
	}
	if (this->m_pFPSTimer.wait() && nullptr!=this->m_onPaint) {
		RCanvas canvas(this->m_renderer,this->m_smallFont,this->m_normFont);
		this->m_onPaint(&canvas);
	}
	
}