#pragma once

class Timer
{
float m_fSeconds;
float m_fStartTime;
public:
	Timer(float fSeconds);
	~Timer(void);

	bool TimeIsUp();
	void SetTimer();

	
};
