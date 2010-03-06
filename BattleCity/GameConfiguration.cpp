#include "GameConfiguration.h"
HGE* GameConfiguration::pHGE = NULL;
float GameConfiguration::fDeltaTime;
Point GameConfiguration::ScreenCenter = Vector2d(400,300);
hgeResourceManager* GameConfiguration::pResourceManager = NULL;


Point GameConfiguration::GetOnScreenPosition(const Vector2d& gamePosition){
	Vector2d P = gamePosition - ScreenCenter;
	P.y = ScreenHeight/2 - P.y;
	P.x = ScreenWidth/2  + P.x;
	return P;
}