#include "pch.h"
#include "RFPSTimer.hpp"

bool RFPSTimer::wait() {
	Uint32 curTime = SDL_GetTicks();
	if(1000 <=(curTime-this->m_frameBeginCountTime)){
		this->m_frameCount=0;
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
