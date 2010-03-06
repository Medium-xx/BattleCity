#pragma once
#include "Weapon.h"
#include "config.h"
#include <hgeanim.h>
#include <hgeresource.h>
#include "DynamicObject.h"
#include "Warhead.h"
#include "Weapon.h"

class Tank: public DynamicObject
{
public:
	Tank(int health = 10, float fMaxSpeed = 0, Vector2d pos = Vector2d(0,0), bool team = false, hgeSprite* sprite = 0 );
	virtual ~Tank(void);

	virtual void Render();
	virtual void Move(Direction direction);
	virtual void Stop();
	void Promote();
	WarHead* Fire();
	

private:
	int			m_iHealth;
	int			m_iRank;
	bool		m_bTeam;
	Weapon		m_Weapon;
	
	HEFFECT m_hMoving;
	HCHANNEL m_hChannel;

	hgeSprite*	m_pSprite;
};
