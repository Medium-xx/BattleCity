#pragma once
#include "DynamicObject.h"
#include "Segment.h"


class WarHead:public DynamicObject
{
private:
	hgeSprite* m_pSprite;
	Point m_HitPoint;
public:
	WarHead(Point pos,Direction direction,float fSpeed, hgeSprite* spr = NULL);
	~WarHead(void);
	void SetSprite(hgeSprite* pSpr) { m_pSprite = pSpr; }
	Point GetHitPoint();
	virtual void Render();
	Geometry::Segment GetHeadSegment() const;

};
