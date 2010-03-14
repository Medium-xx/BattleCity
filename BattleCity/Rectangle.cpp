#include "Rectangle.h"
#include "config.h"

using namespace Geometry;

Rectangle::Rectangle(void)
{
}

Rectangle::~Rectangle(void)
{
}

Rectangle::Rectangle(float x0, float y0, float x1, float y1){
	if(x0>x1) std::swap(x0,x1);
	if(y0>y1) std::swap(y0,y1);

	m_fWidth = x1-x0;
	m_fHeight = y1-y0;
	
	m_A = Point(x0,y0);
	m_B = Point(x1,y1);
}

void Rectangle::Move(const Vector2d& dV){
	m_A += dV;
	m_B += dV;
}

void Rectangle::SetPosition(const Vector2d& position){
	m_A = Point(position.x - m_fWidth*0.5f, position.y - m_fHeight*0.5f);
	m_B = Point(position.x + m_fWidth*0.5f, position.y + m_fHeight*0.5f);
}