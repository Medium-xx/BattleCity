#pragma once
#include "gameobject.h"
#include "Segment.h"

class DynamicObject :
	public GameObject
{
protected:
	Vector2d m_Speed, m_Acceleration;
	float m_fMaxSpeed;
	Direction m_Direction;
	State m_State;
	TEAM_ID m_TeamId;
public:
	DynamicObject(void);
	DynamicObject(const Point& position,float fMaxSpeed = 0,Direction direction = UP):GameObject(position),m_fMaxSpeed(fMaxSpeed),m_Direction(direction){ m_State = IDLE;}
	virtual void Stop();
	void SetMaxSpeed(float fMaxSpeed) { m_fMaxSpeed  = fMaxSpeed; }
	void Turn(Direction direction) { m_Direction = direction; }
	void SetSpeedDirection(Direction direction);
	bool HeadLineIntersects(const DynamicObject&);
	virtual Geometry::Segment GetHeadSegment() const { return Geometry::Segment();}
	virtual void Move(Direction direction);
	void SetAcceleration(float fAccelerationX,float fAccelerationY) { m_Acceleration = Vector2d(fAccelerationX,fAccelerationY); }
	State GetState() const  { return m_State; }
	TEAM_ID GetTeamId() { return m_TeamId; }
	virtual void Update(float fDeltaTime);
	virtual ~DynamicObject(void);
private:

	void SetSpeed(float fSpeedX,float fSpeedY);
	void SetSpeed(const Vector2d& Speed);

};
