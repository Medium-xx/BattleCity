#include "WarHead.h"
#include "GameConfiguration.h"

WarHead::~WarHead(void)
{
}

WarHead::WarHead(Point pos,Direction direction,float fSpeed, hgeSprite* spr):DynamicObject(pos,fSpeed,direction),m_pSprite(spr) 
{ 
	this->Move(direction); 
}

Point WarHead::GetHitPoint(){
	float height2 = m_pSprite->GetHeight()/2.0f;
	switch(m_Direction){
		case UP:
			return Point(m_Position.x,m_Position.y+height2);
		case DOWN:
			return Point(m_Position.x,m_Position.y-height2);
		case LEFT:
			return Point(m_Position.x-height2,m_Position.y);
		case RIGHT:
			return Point(m_Position.x+height2,m_Position.y);
	}
	return Point(0,0);
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
	
	//Vector2d screen_point = GameConfiguration::GetOnScreenPosition(m_Position);
	m_pSprite->RenderEx(m_Position.x,m_Position.y,angle);
}

Geometry::Segment WarHead::GetHeadSegment() const{
	//float height2 = m_pSprite->GetHeight()/2.0f;
	float width2 = m_pSprite->GetWidth()/2.0f+2.0f;

	switch(m_Direction){
		case UP:
		case DOWN:
			return Geometry::Segment(Point(m_Position.x-width2,m_Position.y),Point(m_Position.x+width2,m_Position.y));
		case LEFT:
		case RIGHT:
			return Geometry::Segment(Point(m_Position.x,m_Position.y-width2),Point(m_Position.x,m_Position.y+width2));
	}
	return Geometry::Segment();
}