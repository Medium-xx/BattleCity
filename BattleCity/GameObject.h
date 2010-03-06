#pragma once
#include "config.h"
#include "Effect.h"

class GameObject
{
protected:
	Point m_Position;
	std::vector<Effect*> m_vecEffects;	

	float m_fWidth;
	float m_fHeight;

public:
	GameObject(void);
	GameObject(const Point& position):m_Position(position){}
	virtual void Render(){};
	virtual void Update(float fDeltaTime){};
	virtual ~GameObject(void);
};
