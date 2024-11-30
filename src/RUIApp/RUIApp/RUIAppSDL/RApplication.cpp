#include "pch.h"
#include "RApplication.hpp"
void RApplication::run() {
	timeBeginPeriod(1);
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
