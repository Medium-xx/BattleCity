#pragma once

#include "config.h"

namespace Geometry{

class Rectangle
{
public:
	Point m_A,m_B;
	float m_fWidth;
	float m_fHeight;
	Rectangle(float x0,float y0,float x1,float y1);
	void Move(const Vector2d& dV);
	void SetPosition(const Vector2d& position);
	Rectangle(void);
	~Rectangle(void);
};

}
