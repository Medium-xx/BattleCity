#include "Scene.h"
#include "config.h"
#include "helper.h"

Scene::Scene(hgeResourceManager* pResourceManager)
{
	PressedKeys::Init();
	player = Tank(10,Vector2d(100,100),false,pResourceManager->GetSprite("s_tank"));
}

Scene::~Scene(void)
{
}

void Scene::Update(const PressedKeys& pressedKeys){
	if(pressedKeys.IsKeyPressed(HGEK_UP)){
		player.SetSpeed(0,10.0); 		    			
	}
	if(pressedKeys.IsKeyPressed(HGEK_DOWN)){
		player.SetSpeed(0,-10.0);
	}
	if(pressedKeys.IsKeyPressed(HGEK_LEFT))
		player.SetSpeed(-10.0,0);
	if(pressedKeys.IsKeyPressed(HGEK_RIGHT))
		player.SetSpeed(10.0,0);


	player.Update(0.1f);

	player.SetSpeed(0,0);
}

void Scene::Render(){
	player.Render();
}
