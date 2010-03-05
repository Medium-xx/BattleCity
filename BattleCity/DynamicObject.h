#pragma once
#include "gameobject.h"

class DynamicObject :
	public GameObject
{
protected:
	Vector2d m_Speed, m_Acceleration;
	float m_fMaxSpeedX;
public:
	DynamicObject(void);
	DynamicObject(const Point& position):GameObject(position){}
	void SetSpeed(float fSpeedX,float fSpeedY);
	void SetSpeed(const Vector2d& Speed);
	void SetMaxSpeed(float fMaxSpeedX) { m_fMaxSpeedX  = fMaxSpeedX; }
	void SetAcceleration(float fAccelerationX,float fAccelerationY) { m_Acceleration = Vector2d(fAccelerationX,fAccelerationY); }
	virtual void Update(float fDeltaTime);
	virtual ~DynamicObject(void);
};
