#pragma once
#include "config.h"
#include "Effect.h"
#include "Rectangle.h"


class GameObject
{
protected:
	Point m_Position;
	std::vector<Effect*> m_vecEffects;	

	Geometry::Rectangle m_Rectangle;

public:
	GameObject(void);
	GameObject(const Point& position):m_Position(position){}
	void SetPosition(const Point& position) { m_Position = position; m_Rectangle.SetPosition(position); }
	Point GetPosition() { return m_Position; }
	const Geometry::Rectangle& GetRectangle() { return m_Rectangle; }
	virtual void Render(){};
	virtual void Update(float fDeltaTime){};
	virtual ~GameObject(void);
};
