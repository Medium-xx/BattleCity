#include "Rectangle.h"
#include "config.h"
#include "Segment.h"

using namespace Geometry;

Rectangle::Rectangle(void)
{
}

Rectangle::~Rectangle(void)
{
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2){
	if(x1>x2) std::swap(x2,x1);
	if(y1>y2) std::swap(y2,y1);

	m_fWidth = x2-x1;
	m_fHeight = y2-y1;
	
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

Rectangle::Rectangle(const hgeRect& rect){
	*this = Rectangle(rect.x1,rect.y1,rect.x2,rect.y2);
}

void Rectangle::Move(const Vector2d& dV){
	x1 += dV.x;
	y1 += dV.y;
	x2 += dV.x;
	y2 += dV.y;
	
}

void Rectangle::SetPosition(const Vector2d& position){
	x1 = position.x - m_fWidth*0.5f;
	y1 = position.y - m_fHeight*0.5f;
	x2 = position.x + m_fWidth*0.5f;
	y2 = position.y + m_fHeight*0.5f;
}

bool Rectangle::IntersectsSegment(const Segment& seg) const{
	if(seg.B.y - seg.A.y < EPS) // horizontal
	{
		if(seg.A.y < y1 || seg.A.y > y2)
			return false;
		return seg.A.x<=x1 && seg.B.x >= x1 || seg.A.x<=x2 && seg.B.x >= x2 || seg.A.x>=x1 && seg.B.x<=x2;
	}
	else // vertical
	{
		if(seg.A.x < x1 || seg.A.x > x2)
			return false;
		return seg.A.y<=y1 && seg.B.y >= y1 || seg.A.y<=y2 && seg.B.y >= y2 || seg.A.y>=y1 && seg.B.y<=y2;

	}	
}