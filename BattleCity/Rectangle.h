#pragma once

#include "config.h"



namespace Geometry{

class Segment;

class Rectangle:public hgeRect
{
public:
	float m_fWidth;
	float m_fHeight;
	Rectangle(float x1,float y1,float x2,float y2);
	Rectangle(const hgeRect& rect);
	void Move(const Vector2d& dV);
	void SetPosition(const Vector2d& position);
	
	bool IntersectsSegment(const Segment&) const;
	Rectangle(void);
	~Rectangle(void);
};

}
