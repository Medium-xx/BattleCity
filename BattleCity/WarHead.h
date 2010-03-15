#pragma once
#include "DynamicObject.h"
#include "Segment.h"


class Warhead:public DynamicObject
{
private:
	hgeSprite* m_pSprite;
	Point m_HitPoint;
public:
	Warhead(Point pos,Direction direction,float fSpeed, hgeSprite* spr = NULL, TEAM_ID = PLAYERS);
	~Warhead(void);
	void SetSprite(hgeSprite* pSpr) { m_pSprite = pSpr; }
	Point GetHitPoint();
	virtual void Render();
	Geometry::Segment GetHeadSegment() const;

};
