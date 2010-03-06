#include "Timer.h"
#include "GameConfiguration.h"

Timer::Timer(float fSeconds)
{
	m_fSeconds = fSeconds;
	m_fStartTime = 0;
}

bool Timer::TimeIsUp(){
	return GameConfiguration::pHGE->Timer_GetTime() - m_fStartTime > m_fSeconds;
}

void Timer::SetTimer(){
	m_fStartTime = GameConfiguration::pHGE->Timer_GetTime();
}

Timer::~Timer(void)
{
}
