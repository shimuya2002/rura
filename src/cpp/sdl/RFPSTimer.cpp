#include "pch.h"
#include "RFPSTimer.hpp"
#include"config.h"
RFPSTimer::RFPSTimer()
	:m_prevFrameTime(0),
	 m_prevDrawTime(0),
	 m_timePerFrame(1000/DEF_FPS_NUM),
	 m_curFrameCount(0),
     m_frameBeginCountTime(0),
	 m_prevSecondFrameNum(0)
{

}
bool RFPSTimer::wait() {

	Uint32 curTime = SDL_GetTicks();
	if(1000 <=(curTime-this->m_frameBeginCountTime)){
		this->m_prevSecondFrameNum=this->m_curFrameCount;
		this->m_curFrameCount=0;
		this->m_frameBeginCountTime = curTime;
	}else{
		++this->m_curFrameCount;
	}

	Uint32 diff = curTime - this->m_prevFrameTime;
	if (this->m_timePerFrame < diff) {
		if (this->m_timePerFrame * 4  > (curTime - this->m_prevDrawTime)) {
			this->m_prevFrameTime = curTime;
			return false;
		}
	}else if (this->m_timePerFrame > diff) {
		Uint32 sleepTime = this->m_timePerFrame - diff;
		
		SDL_Delay(sleepTime);
		this->m_prevFrameTime = SDL_GetTicks();
	}
	else {
		this->m_prevFrameTime = curTime;
	}

	this->m_prevDrawTime = this->m_prevFrameTime;

	return true;



	
}
