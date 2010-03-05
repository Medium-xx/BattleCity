#pragma once
#include "Weapon.h"
#include "hgesprite.h"

struct vec2d
{
	float x, y;
};

class Tank
{
public:
	Tank(int health = 10, float speed = 1, vec2d pos = {0, 0}, bool team = false, hgeSprite* sprite);
	~Tank(void);

	void Draw();
	void Promote();
private:
	int			m_iHealth;
	float		m_fSpeed;
	vec2d		m_Position;
	int			m_iRank;
	Weapon		m_Weapon;
	bool		m_bTeam;

	hgeSprite*	m_pSpr;
};
