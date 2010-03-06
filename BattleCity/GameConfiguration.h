#pragma once
#include "config.h"
class GameConfiguration
{
public:
	static float fDeltaTime;
	static HGE* pHGE;
	static Point ScreenCenter;
	static hgeResourceManager* pResourceManager;
	static void Update() { fDeltaTime = pHGE->Timer_GetDelta();}
	static Point GetOnScreenPosition(const Vector2d& gamePosition);
	static const int ScreenWidth = 800;
	static const int ScreenHeight = 600;
	
//	GameConfiguration(void);
//	~GameConfiguration(void);
};
