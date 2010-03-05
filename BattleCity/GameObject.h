#pragma once
#include "config.h"
class GameObject
{
protected:
	Point m_Position;
public:
	GameObject(void);
	GameObject(const Point& position):m_Position(position){}
	virtual void Render(){};
	virtual void Update(float fDeltaTime){};
	virtual ~GameObject(void);
};
