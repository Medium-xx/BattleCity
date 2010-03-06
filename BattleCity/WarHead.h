#pragma once
#include "DynamicObject.h"

class WarHead:public DynamicObject
{
private:
	hgeSprite* m_pSprite;
public:
	WarHead(Point pos,Direction direction,float fSpeed, hgeSprite* spr = NULL):DynamicObject(pos,fSpeed,direction),m_pSprite(spr) { this->Move(direction); }
	~WarHead(void);
	void SetSprite(hgeSprite* pSpr) { m_pSprite = pSpr; }
	virtual void Render();
};
