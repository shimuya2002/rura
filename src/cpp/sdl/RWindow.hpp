#pragma once
#include"framework.h"
#include"RCanvas.hpp"
#include"RFPSTimer.hpp"
typedef void (*IdleHandler)();
typedef void (*PaintHandler)(RCanvas*);
class RUI_SDL_EXPORTS RWindow
{

	LIB_TYPE(SDL_Window)* m_window;
	LIB_TYPE(SDL_Renderer)* m_renderer;
	IdleHandler m_onIdle;
	PaintHandler m_onPaint;
	RFPSTimer m_pFPSTimer;
	LIB_TYPE(TTF_Font)* m_smallFont;
	LIB_TYPE(TTF_Font)* m_normFont;
public:
	RWindow();

	~RWindow();

	void show();
	void show(int w, int h);

	void close();
	void onIdle();

	void set_idle_handler(IdleHandler h) {
		m_onIdle = h;
	}
	void set_paint_handler(PaintHandler h) {
		m_onPaint = h;
	}
	void load_font(const char* path, int small, int norm);

	void release_font();

};

