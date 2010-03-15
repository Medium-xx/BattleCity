#pragma once
#include "Weapon.h"
#include "config.h"
#include <hgeanim.h>
#include <hgeresource.h>
#include "DynamicObject.h"
#include "Warhead.h"
#include "Weapon.h"
#include "Segment.h"
#include "ActionController.h"

class Tank: public DynamicObject
{
public:
	Tank(int health = 10, float fMaxSpeed = 0, Vector2d pos = Vector2d(0,0), TEAM_ID team = PLAYERS, Direction direction = UP, ActionController* pActionController = NULL);
	virtual ~Tank(void);

	virtual void Render();
//	virtual void Move(Direction direction);
//	virtual void Stop();
	void Promote();
	void SetSprite(Direction direction) { m_pSprite = m_arrpTurnSprites[direction]; }
	Warhead* Fire();
	void PerformAction();

	Geometry::Segment GetHeadSegment() const ;

	

private:
	int			m_iHealth;
	int			m_iRank;
	Weapon		m_Weapon;
	ActionController* m_pActionController;
	
//	HEFFECT m_hMoving;
//	HCHANNEL m_hChannel;

	hgeSprite*	m_pSprite;
	hgeSprite*  m_arrpTurnSprites[4];
};
