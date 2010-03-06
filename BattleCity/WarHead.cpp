#include "WarHead.h"
#include "GameConfiguration.h"

WarHead::~WarHead(void)
{
}

void WarHead::Render(){
	float angle;
	switch(m_Direction){
		case UP:  
			angle = 0;
			break;
		case DOWN:
			angle = M_PI;
			break;
		case LEFT:
			angle = -M_PI_2;
			break;
		case RIGHT:
			angle = +M_PI_2;
	}
	
	Vector2d screen_point = GameConfiguration::GetOnScreenPosition(m_Position);
	m_pSprite->RenderEx(screen_point.x,screen_point.y,angle);
}
