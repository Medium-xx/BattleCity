#pragma once
#include "Tank.h"
#include "hgeresource.h"
#include "GameObject.h"
#include "Map.h"
#include "WarHead.h"

class Scene
{
private:
//	hgeResourceManager* m_pResourceManager;
	Tank player;
	Map* m_pMap;
	std::vector<GameObject*> dynamic_objects;
	std::vector<WarHead*> m_vecpWarHeads;
//	std::vector<GameObject*> layers[3];
public:
	void Render();
	void Update(const PressedKeys& pressedKeys);
	Scene();
	void LoadMap(const char* filename,int x0,int y0);
	~Scene(void);
};
