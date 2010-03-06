#pragma once

#include "hge.h"
#include "hgefont.h"
#include <string>
#include <hgeresource.h>
#include <hgeanim.h>
#include <math.h>
#include "hgevector.h"
#include <vector>
#include "helper.h"


typedef hgeVector Vector2d;
typedef Vector2d Point;


const double EPS = 1e-6;
//enum Direction{FORWARD,BACKWARD};
enum Direction { UP, DOWN, LEFT, RIGHT};