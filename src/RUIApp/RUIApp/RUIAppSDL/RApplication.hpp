#pragma once
#include"framework.h"
class RUI_SDL_EXPORTS RApplication
{
	bool m_isRunning;
public:
	void run();
	void procEvents();

};

