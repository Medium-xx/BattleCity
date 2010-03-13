#pragma once
#include "Tank.h"
#include "hgeresource.h"
#include "GameObject.h"
#include "Map.h"

class Scene
{
private:
//	hgeResourceManager* m_pResourceManager;
	Tank player;
	Map* m_pMap;
	std::vector<GameObject*> dynamic_objects;
//	std::vector<GameObject*> layers[3];
public:
	void Render();
	void Update(const PressedKeys& pressedKeys);
	Scene();
	void LoadMap(const char* filename);
	~Scene(void);
};
