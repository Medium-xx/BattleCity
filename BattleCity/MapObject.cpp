#include "MapObject.h"

MapObject::MapObject(Vector2d pos, hgeSprite* sprite, UINT layer):GameObject(pos),m_pSprite(sprite),m_iLayer(layer)
{
}

MapObject::~MapObject(void)
{
}

void MapObject::Render(Vector2d pos, UINT layer)
{
	if (layer == m_iLayer)
		if(m_pSprite) m_pSprite->Render(pos.x, pos.y);
}