#include "Tank.h"
#include "GameConfiguration.h"

Tank::Tank(int health, float fMaxSpeed,Vector2d pos, bool team, hgeSprite* sprite):DynamicObject(pos,fMaxSpeed), m_iHealth(health),m_bTeam(team),m_pSprite(sprite)
{
	m_hMoving = GameConfiguration::pResourceManager->GetEffect("tank_move");
}

Tank::~Tank(void)
{
}

void Tank::Render(){
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

	for(int i =0 ; i < m_vecEffects.size();++i)
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
			pos = Point(m_Position.x,m_Position.y+14);
			break;
		case DOWN:
			pos = Point(m_Position.x,m_Position.y-14);
			break;
		case LEFT:
			pos = Point(m_Position.x-11,m_Position.y);
			break;
		case RIGHT:
			pos = Point(m_Position.x+11,m_Position.y);
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