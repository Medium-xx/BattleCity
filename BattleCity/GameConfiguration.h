#pragma once
#include "config.h"
class GameConfiguration
{
public:
	static float fDeltaTime;
	static HGE* pHGE;
	static void Update() { fDeltaTime = pHGE->Timer_GetDelta();}
//	GameConfiguration(void);
//	~GameConfiguration(void);
};
