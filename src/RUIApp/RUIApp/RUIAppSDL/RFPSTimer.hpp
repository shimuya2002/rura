#pragma once
#include"framework.h"
class RUI_SDL_EXPORTS RFPSTimer
{
	unsigned m_prevFrameTime;
	unsigned m_prevDrawTime;
	unsigned m_timePerFrame;

public:
	bool wait();
};

