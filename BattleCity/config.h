#pragma once

#include "hge.h"
#include "hgefont.h"
#include <string>
#include <hgeresource.h>
#include <hgeanim.h>
#include <math.h>
#include "hgevector.h"
#include <vector>
#include <queue>
#include "helper.h"


typedef hgeVector Vector2d;
typedef Vector2d Point;


const double EPS = 1e-6;
//enum Direction{FORWARD,BACKWARD};
enum Direction { UP, DOWN, LEFT, RIGHT};
enum State {IDLE, MOVING};
enum SoundEffectType { TANK_MOVING, TANK_FIRING };
enum TEAM_ID { PLAYERS, BOTS };

const unsigned int CELL_SIZE = 8;

#define SAFE_DELETE(a) {if ((a) != NULL) delete (a); (a) = NULL;}

class ActionPerformer;
class ActionController;
class GameObject;
class GameConfiguration;
class DynamicObject;
class Tank;
class Scene;
class SoundManager;
class Warhead;