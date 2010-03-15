#include "GameConfiguration.h"
#include "ActionPerformer.h"
#include "SoundManager.h"

HGE* GameConfiguration::pHGE = NULL;
float GameConfiguration::fDeltaTime = 0.1f;
Point GameConfiguration::ScreenCenter = Vector2d(400,300);
hgeResourceManager* GameConfiguration::pResourceManager = NULL;
ActionPerformer* GameConfiguration::pActionPerformer = new ActionPerformer();
Scene* GameConfiguration::pWorld = NULL;
SoundManager* GameConfiguration::pSoundManager = NULL;
KeyboardManager* GameConfiguration::pKeyboardManager = new KeyboardManager();

Point GameConfiguration::GetOnScreenPosition(const Vector2d& gamePosition){
	Vector2d P = gamePosition - ScreenCenter;
	P.y = SCREEN_HEIGHT/2 - P.y;
	P.x = SCREEN_WIDTH/2  + P.x;
	return P;
}