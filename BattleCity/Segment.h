#pragma once
#include "config.h"

namespace Geometry{

class Segment
{
public:
	Point m_A,m_B;

	Segment(const Point& A,const Point& B):m_A(A),m_B(B){}

	Segment(void);
	~Segment(void);
};


}