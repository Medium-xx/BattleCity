#pragma once
#include "Weapon.h"
#include "config.h"
#include <hgeanim.h>
#include <hgeresource.h>
#include "DynamicObject.h"
#include "Warhead.h"
#include "Weapon.h"
#include "Segment.h"

class Tank: public DynamicObject
{
public:
	Tank(int health = 10, float fMaxSpeed = 0, Vector2d pos = Vector2d(0,0), bool team = false, Direction direction = UP);
	virtual ~Tank(void);

	virtual void Render();
	virtual void Move(Direction direction);
	virtual void Stop();
	void Promote();
	void SetSprite(Direction direction) { m_pSprite = m_arrpTurnSprites[direction]; }
	WarHead* Fire();

	Geometry::Segment GetHeadSegment() const ;
	

private:
	int			m_iHealth;
	int			m_iRank;
	bool		m_bTeam;
	Weapon		m_Weapon;
	
	HEFFECT m_hMoving;
	HCHANNEL m_hChannel;

	hgeSprite*	m_pSprite;
	hgeSprite*  m_arrpTurnSprites[4];
};
