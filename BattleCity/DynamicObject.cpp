#include "DynamicObject.h"
#include "GameConfiguration.h"
#include "Rectangle.h"

DynamicObject::DynamicObject(void)
{
	m_Speed = Vector2d(0,0);
	m_Acceleration = Vector2d(0,0);
}

DynamicObject::~DynamicObject(void)
{
}

void DynamicObject::Move(Direction direction){
	Turn(direction);
	switch(m_Direction){
		case UP:
			SetSpeed(0,-1.0);
			break;
		case DOWN:
			SetSpeed(0,+1.0);
			break;
		case LEFT:
			SetSpeed(-1.0,0);
			break;
		case RIGHT:
			SetSpeed(1.0,0);
	}
}

void DynamicObject::Update(float fDeltaTime){
	m_Position = m_Position + (m_Speed*fDeltaTime);
	m_Rectangle.Move(m_Speed*fDeltaTime);
}

void DynamicObject::SetSpeed(const Vector2d& Speed){
	SetSpeed(Speed.x,Speed.y);
}


void DynamicObject::SetSpeed(float fSpeedX,float fSpeedY){
	m_Speed = Vector2d(m_fMaxSpeed*fSpeedX,m_fMaxSpeed*fSpeedY);
}

void DynamicObject::Stop(){
	SetSpeed(0,0);
}