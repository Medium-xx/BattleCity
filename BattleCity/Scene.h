#pragma once
#include "Tank.h"
#include "hgeresource.h"
#include "GameObject.h"

class Scene
{
private:
	hgeResourceManager* m_pResourceManager;
	Tank player;
	std::vector<GameObject*> layers[3];
public:
	void Render();
	void Update(const PressedKeys& pressedKeys);
	Scene();
	~Scene(void);
};
