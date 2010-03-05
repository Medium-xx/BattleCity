#include "Tank.h"

Tank(int health, float speed, vec2d pos, bool team, hgeSprite* sprite):m_iHealth(health),m_fSpeed(speed),m_Position(pos),m_Team(team),m_pSprite(sprite)
{
}

Tank::~Tank(void)
{
}
