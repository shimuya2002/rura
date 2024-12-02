#include "pch.h"
#include "RWindow.hpp"
#include "RColor.hpp"
#include "config.h"
RWindow::RWindow()
		:m_window(nullptr),
		m_renderer(nullptr),
		m_onIdle(nullptr),
		m_onPaint(nullptr),
		m_smallFont(nullptr),
		m_normFont(nullptr)
	{}
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

	if(nullptr==this->m_smallFont && nullptr==this->m_normFont){
		this->load_font(DEF_FONT,DEF_SMALL_FONT_SIZE,DEF_NORM_FONT_SIZE);
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
	SDL_RenderClear(this->m_renderer);
	RCanvas canvas(this->m_renderer,this->m_smallFont,this->m_normFont);
	if (this->m_pFPSTimer.wait() && nullptr!=this->m_onPaint) {
		this->m_onPaint(&canvas);
		

		
	}
	canvas.set_draw_color(COLOR_WHITE);
	char buf[16];
	snprintf(buf,16,"%d FPS",this->m_pFPSTimer.get_prev_second_frame_num());
	canvas.draw_text(0,0,0,buf);
	SDL_RenderPresent(this->m_renderer);
	
}
void RWindow::load_font(const char* path, int small, int norm) {
		this->release_font();
		this->m_smallFont = TTF_OpenFont(path, small);
		if(nullptr==this->m_smallFont){
			//std::cerr<<__FILE__<<" "<<__LINE__<<":Failed to load small font.FILE_PATH="<<path<<std::endl;

		}
		this->m_normFont= TTF_OpenFont(path, norm);
		if(nullptr==this->m_smallFont){
			//std::cerr<<__FILE__<<" "<<__LINE__<<":Failed to load norm font.FILE_PATH="<<path<<std::endl;

		}
		
}

void RWindow::release_font() {
		if (nullptr != this->m_smallFont) {
			TTF_CloseFont(this->m_smallFont);
			this->m_smallFont = nullptr;
		}
		if (nullptr != this->m_normFont) {
			TTF_CloseFont(this->m_normFont);
			this->m_normFont = nullptr;
		}
	}
