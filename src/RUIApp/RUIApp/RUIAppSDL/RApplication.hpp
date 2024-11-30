#pragma once
#include"framework.h"
#include"RWindow.hpp"
class RUI_SDL_EXPORTS RApplication
{
	bool m_isRunning;
	RWindow* m_mainWindow;

public:
	RApplication();
	~RApplication();

	void run();
	void procEvents();

	void set_main_window(RWindow* pWin) {
		this ->m_mainWindow = pWin;
	}


	

};

