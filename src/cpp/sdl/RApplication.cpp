#include "pch.h"
#include "RApplication.hpp"

RApplication::RApplication()
	:m_isRunning(false)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_PNG);
	TTF_Init();
}


RApplication::~RApplication() {
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void RApplication::run() {
	m_isRunning = true;
	while (m_isRunning) {
		procEvents();
	}
}
void RApplication::procEvents() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			m_isRunning = false;
			break;
		}
	}



}
void RApplication::set_main_window(RWindow* pWin) {
		this ->m_mainWindow = pWin;
}
