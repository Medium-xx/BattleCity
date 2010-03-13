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

const unsigned int CELLSIZE = 8;

#define SAFE_DELETE (a) {if (a != NULL) delete a; a = NULL;}