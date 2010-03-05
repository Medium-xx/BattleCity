#include "DynamicObject.h"
#include "GameConfiguration.h"

DynamicObject::DynamicObject(void)
{
	m_Speed = Vector2d(0,0);
	m_Acceleration = Vector2d(0,0);
}

DynamicObject::~DynamicObject(void)
{
}

void DynamicObject::Update(float fDeltaTime){
	SetSpeed(m_Speed + (m_Acceleration*fDeltaTime));
	m_Position = m_Position + (m_Speed*fDeltaTime);
}

void DynamicObject::SetSpeed(const Vector2d& Speed){
	SetSpeed(Speed.x,Speed.y);
}


void DynamicObject::SetSpeed(float fSpeedX,float fSpeedY){
	m_Speed = Vector2d(fSpeedX,fSpeedY);
}
