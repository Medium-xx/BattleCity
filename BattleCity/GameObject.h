#pragma once
#include "config.h"
#include "Effect.h"
#include "Rectangle.h"


class GameObject
{
protected:
	Point m_Position;
	bool m_bDestroyed;
	std::vector<Effect*> m_vecEffects;	

	Geometry::Rectangle m_Rectangle;

public:
	GameObject(void);
	GameObject(const Point& position):m_Position(position),m_bDestroyed(false){}
	void SetPosition(const Point& position) { m_Position = position; m_Rectangle.SetPosition(position); }
	Point GetPosition() { return m_Position; }
	const Geometry::Rectangle& GetRectangle() const  { return m_Rectangle; }
	bool Intersects(const GameObject&);
	void Destroy() { m_bDestroyed = true; }
	bool IsDestroyed() const { return m_bDestroyed; }
	virtual void Render(){};
	virtual void Update(float fDeltaTime){};
	virtual ~GameObject(void);
};
