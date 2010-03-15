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
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	static const float UPDATE_TIME;
	static ActionPerformer* pActionPerformer;
	static Scene* pWorld;
	static SoundManager* pSoundManager;
	static KeyboardManager* pKeyboardManager;
	
//	GameConfiguration(void);
//	~GameConfiguration(void);
};
