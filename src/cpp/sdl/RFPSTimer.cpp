#include "pch.h"
#include "RFPSTimer.hpp"
#include"config.h"
RFPSTimer::RFPSTimer()
	:m_prevFrameTime(0),
	 m_prevDrawTime(0),
	 m_timePerFrame(1000/DEF_FPS_NUM),
	 m_frameCount(0),
     m_frameBeginCountTime(0)
{

}
bool RFPSTimer::wait() {
	Uint32 curTime = SDL_GetTicks();
	if(1000 <=(curTime-this->m_frameBeginCountTime)){
		this->m_frameCount=0;
		this->m_frameBeginCountTime = curTime;
	}else{
		++this->m_frameCount;
	}

	Uint32 diff = curTime - this->m_prevFrameTime;
	if (this->m_timePerFrame < diff) {
		if (this->m_timePerFrame * 4  > (curTime - this->m_prevDrawTime)) {
			this->m_prevFrameTime = curTime;
			return false;
		}
	}else if (this->m_timePerFrame > diff) {
		SDL_Delay(this->m_timePerFrame - diff);
		this->m_prevFrameTime = SDL_GetTicks();
	}
	else {
		this->m_prevFrameTime = curTime;
	}

	this->m_prevDrawTime = this->m_prevFrameTime;

	return true;



	
}
