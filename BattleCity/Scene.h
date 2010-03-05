#pragma once
#include "Tank.h"
#include "hgeresource.h"

class Scene
{
public:
	Tank player;
	void Render();
	void Update(const PressedKeys& pressedKeys);
	Scene(hgeResourceManager* pResourceManager);
	~Scene(void);
};
