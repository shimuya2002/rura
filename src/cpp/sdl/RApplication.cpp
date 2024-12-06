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

	if (nullptr != this->m_mainWindow) {
		this->m_mainWindow->onIdle();
	}
	else {
	}
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			m_isRunning = false;
			return;
			
		}
	}

	

}

void RApplication::set_main_window(RWindow* pWin) {
		this ->m_mainWindow = pWin;
}
const char* RApplication::get_app_dir_path(){
	return SDL_GetBasePath();
}
long long int RApplication::read_text_from_file(const char* lpszFile,unsigned char* pDst){
	SDL_RWops* pOps=SDL_RWFromFile(lpszFile,"r");
	Sint64 fileSize=SDL_RWsize(pOps);
	if(nullptr!=pDst){
		memset(pDst,0,fileSize);
		SDL_RWread(pOps,pDst,fileSize,1);
	}
	SDL_FreeRW(pOps);
	return fileSize+1;
}
