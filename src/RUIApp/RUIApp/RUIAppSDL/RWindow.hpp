#pragma once
#include"framework.h"
#include"RCanvas.hpp"
#include"RFPSTimer.hpp"
typedef void (*PaintHandler)(RCanvas*);
class RUI_SDL_EXPORTS RWindow
{

	LIB_TYPE(SDL_Window)* m_window;
	LIB_TYPE(SDL_Renderer)* m_renderer;
	PaintHandler m_onPaint;
	RFPSTimer m_pFPSTimer;
	
public:
	RWindow()
	:m_window(nullptr),
	 m_renderer(nullptr),
     m_onPaint(nullptr)
	{}

	~RWindow();

	void show();
	void close();
	void onIdle();

	void set_paint_handler(PaintHandler h) {
		m_onPaint = h;
	}

};

