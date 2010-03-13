#pragma once
#include "GameObject.h"

struct MapObject : public GameObject
{
	MapObject(Vector2d pos, hgeSprite* sprite, UINT layer);
	~MapObject(void);
	void Render(Vector2d pos, UINT layer);
private:
	hgeSprite* m_pSprite;
	UINT m_iLayer;
};