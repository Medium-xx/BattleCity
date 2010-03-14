#include "Tank.h"
#include "GameConfiguration.h"

Tank::Tank(int health, float fMaxSpeed,Vector2d pos, bool team, Direction direction):DynamicObject(pos,fMaxSpeed), m_iHealth(health),m_bTeam(team)
{
	m_hMoving = GameConfiguration::pResourceManager->GetEffect("tank_move");
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

WarHead* Tank::Fire(){	
	if(!m_Weapon.IsReady())
		return NULL;
	m_Weapon.Reload();

	m_vecEffects.push_back(new SoundEffect("fire"));

	Point pos;
	switch(m_Direction){
		case UP:
			pos = Point(m_Position.x,m_Rectangle.m_A.y);
			break;
		case DOWN:
			pos = Point(m_Position.x,m_Rectangle.m_B.y);
			break;
		case LEFT:
			pos = Point(m_Rectangle.m_A.x,m_Position.y);
			break;
		case RIGHT:
			pos = Point(m_Rectangle.m_B.x,m_Position.y);
	}
	WarHead* ret = new WarHead(pos,m_Direction,m_Weapon.ProjectileSpeed(),GameConfiguration::pResourceManager->GetSprite("s_bullet"));
	return ret;	
}

void Tank::Move(Direction direction){
	DynamicObject::Move(direction);
	if(!GameConfiguration::pHGE->Channel_IsPlaying(m_hChannel))
		m_hChannel = GameConfiguration::pHGE->Effect_Play(m_hMoving);	
}

void Tank::Stop(){
	DynamicObject::Stop();
//	if(GameConfiguration::pHGE->Channel_IsPlaying(m_hChannel))
		GameConfiguration::pHGE->Channel_Stop(m_hChannel);
}

Geometry::Segment Tank::GetHeadSegment() const{
	switch(m_Direction){
		case UP:
			return Geometry::Segment(m_Rectangle.m_A,Point(m_Rectangle.m_B.x,m_Rectangle.m_A.y));
		case DOWN:
			return Geometry::Segment(Point(m_Rectangle.m_A.x,m_Rectangle.m_B.y),m_Rectangle.m_B);
		case RIGHT:
			return Geometry::Segment(Point(m_Rectangle.m_B.x,m_Rectangle.m_A.y),m_Rectangle.m_B);
		case LEFT:
			return Geometry::Segment(m_Rectangle.m_A,Point(m_Rectangle.m_A.x,m_Rectangle.m_B.y));
	}
	return Geometry::Segment();
}