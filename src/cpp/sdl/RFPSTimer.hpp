#pragma once
#include"framework.h"
class RUI_SDL_EXPORTS RFPSTimer
{
	unsigned m_prevFrameTime;
	unsigned m_prevDrawTime;
	unsigned m_timePerFrame;
	int m_curFrameCount;
	int m_prevSecondFrameNum;
	unsigned m_frameBeginCountTime;
public:
	RFPSTimer();
	bool wait();
	int get_cur_frame_count(){
		return this->m_curFrameCount;
	}

	int get_prev_second_frame_num(){
		return this->m_prevSecondFrameNum;
	}
	
};

