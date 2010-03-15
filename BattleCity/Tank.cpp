#include "Tank.h"
#include "GameConfiguration.h"

Tank::Tank(int health, float fMaxSpeed,Vector2d pos, TEAM_ID team, Direction direction,ActionController* pActionController):DynamicObject(pos,fMaxSpeed), m_iHealth(health),																											m_pActionController(pActionController)
{
//	m_hMoving = GameConfiguration::pResourceManager->GetEffect("tank_move");
	m_TeamId = team;
	m_arrpTurnSprites[DOWN] = GameConfiguration::pResourceManager->GetSprite("s_player1_down");
	m_arrpTurnSprites[UP] = GameConfiguration::pResourceManager->GetSprite("s_player1_up");
	m_arrpTurnSprites[LEFT] = GameConfiguration::pResourceManager->GetSprite("s_player1_left");
	m_arrpTurnSprites[RIGHT] = GameConfiguration::pResourceManager->GetSprite("s_player1_right");
	this->SetSprite(direction);
	m_Direction = direction;
	float width = m_pSprite->GetWidth()/2.0f;
	float height = m_pSprite->GetHeight()/2.0f;
	m_Rectangle = Geometry::Rectangle(m_Position.x - width,m_Position.y - height, m_Position.x + width, m_Position.y + height);
}

Tank::~Tank(void)
{
	SAFE_DELETE(m_pActionController);
}

void Tank::Render(){

	this->SetSprite(m_Direction);

	//Vector2d screen_point = GameConfiguration::GetOnScreenPosition(m_Position);
	m_pSprite->Render(m_Position.x,m_Position.y);

	for(UINT i =0 ; i < m_vecEffects.size();++i)
	{
		m_vecEffects[i]->Render();
		delete m_vecEffects[i];
	}

	m_vecEffects.clear();
}

Warhead* Tank::Fire(){	
	if(!m_Weapon.IsReady())
		return NULL;
	m_Weapon.Reload();


	Point pos;
	switch(m_Direction){
		case UP:
			pos = Point(m_Position.x,m_Rectangle.y1);
			break;
		case DOWN:
			pos = Point(m_Position.x,m_Rectangle.y2);
			break;
		case LEFT:
			pos = Point(m_Rectangle.x1,m_Position.y);
			break;
		case RIGHT:
			pos = Point(m_Rectangle.x2,m_Position.y);
	}
	Warhead* ret = new Warhead(pos,m_Direction,m_Weapon.ProjectileSpeed(),GameConfiguration::pResourceManager->GetSprite("s_bullet"),GetTeamId());
	return ret;	
}

/*
void Tank::Move(Direction direction){
	DynamicObject::Move(direction);
//	if(!GameConfiguration::pHGE->Channel_IsPlaying(m_hChannel))
//		m_hChannel = GameConfiguration::pHGE->Effect_Play(m_hMoving);	
}
*/

/*
void Tank::Stop(){
	DynamicObject::Stop();
	//	if(GameConfiguration::pHGE->Channel_IsPlaying(m_hChannel))
	GameConfiguration::pHGE->Channel_Stop(m_hChannel);
}
*/

Geometry::Segment Tank::GetHeadSegment() const{
	switch(m_Direction){
		case UP:
			return Geometry::Segment(Point(m_Rectangle.x1,m_Rectangle.y1),Point(m_Rectangle.x2,m_Rectangle.y1));
		case DOWN:
			return Geometry::Segment(Point(m_Rectangle.x1,m_Rectangle.y2),Point(m_Rectangle.x2,m_Rectangle.y2));
		case RIGHT:
			return Geometry::Segment(Point(m_Rectangle.x2,m_Rectangle.y1),Point(m_Rectangle.x2,m_Rectangle.y2));
		case LEFT:
			return Geometry::Segment(Point(m_Rectangle.x1,m_Rectangle.y1),Point(m_Rectangle.x1,m_Rectangle.y2));
	}
	return Geometry::Segment();
}

void Tank::PerformAction(){
	m_pActionController->PerformAction(*this);
}