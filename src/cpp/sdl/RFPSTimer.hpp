#pragma once
#include"framework.h"
class RUI_SDL_EXPORTS RFPSTimer
{
	unsigned m_prevFrameTime;
	unsigned m_prevDrawTime;
	unsigned m_timePerFrame;
	int m_frameCount;
	unsigned m_frameBeginCountTime;
public:
	RFPSTimer();
	bool wait();
	int get_cur_frame_count(){
		return this->m_frameCount;
	}
};

