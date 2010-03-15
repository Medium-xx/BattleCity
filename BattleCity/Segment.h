#pragma once
#include "config.h"

namespace Geometry{

class Segment
{
public:
	Point A,B;

	Segment(const Point& A,const Point& B):A(A),B(B){}

	Segment(void);
	~Segment(void);
};


}