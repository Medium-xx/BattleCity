#pragma once
#include "gameobject.h"

class DynamicObject :
	public GameObject
{
protected:
	Vector2d m_Speed, m_Acceleration;
	float m_fMaxSpeed;
	Direction m_Direction;
public:
	DynamicObject(void);
	DynamicObject(const Point& position,float fMaxSpeed = 0,Direction direction = UP):GameObject(position),m_fMaxSpeed(fMaxSpeed),m_Direction(direction){}
	virtual void Stop();
	void SetMaxSpeed(float fMaxSpeed) { m_fMaxSpeed  = fMaxSpeed; }
	void Turn(Direction direction) { m_Direction = direction; }
	virtual void Move(Direction direction);
	void SetAcceleration(float fAccelerationX,float fAccelerationY) { m_Acceleration = Vector2d(fAccelerationX,fAccelerationY); }
	virtual void Update(float fDeltaTime);
	virtual ~DynamicObject(void);
private:

	void SetSpeed(float fSpeedX,float fSpeedY);
	void SetSpeed(const Vector2d& Speed);

};
