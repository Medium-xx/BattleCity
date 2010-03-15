#include "WarHead.h"
#include "GameConfiguration.h"
#include "Rectangle.h"
#include "helper.h"

Warhead::~Warhead(void)
{
}

Warhead::Warhead(Point pos,Direction direction,float fSpeed, hgeSprite* spr,TEAM_ID team):DynamicObject(pos,fSpeed,direction),m_pSprite(spr) 
{ 
	m_TeamId = team;
	hgeRect a;
	m_Rectangle = Geometry::Rectangle(*(spr->GetBoundingBoxEx(m_Position.x,m_Position.y,DirectionToAngle(direction),1.0,1.0,&a)));
	this->Turn(direction); 
	this->SetSpeedDirection(direction);
}

Point Warhead::GetHitPoint(){
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

void Warhead::Render(){
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

Geometry::Segment Warhead::GetHeadSegment() const{
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
