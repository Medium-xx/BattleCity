#include "Scene.h"
#include "config.h"
#include "helper.h"
#include "GameConfiguration.h"
#include "Warhead.h"

Scene::Scene()
{
	PressedKeys::Init();
	GameConfiguration::ScreenCenter = Point(400,400);
	HSTREAM ch;
	//ch = GameConfiguration::pHGE->Stream_Play(pResourceManager->GetStream("theme"),true);
	//GameConfiguration::pHGE->Stream_Free(ch);
	player = Tank(10,30.0,Vector2d(100,100),false,GameConfiguration::pResourceManager->GetSprite("s_tank"));
}

Scene::~Scene(void)
{
}

void Scene::Update(const PressedKeys& pressedKeys){
//	static
	int keyhold = 0;
	if(pressedKeys.IsKeyPressed(HGEK_UP)&&(keyhold = HGEK_UP))
		player.Move(UP);		    			
	if(pressedKeys.IsKeyPressed(HGEK_DOWN)&&(keyhold = HGEK_DOWN))
		player.Move(DOWN);
	if(pressedKeys.IsKeyPressed(HGEK_LEFT)&&(keyhold = HGEK_LEFT))
		player.Move(LEFT);
	if(pressedKeys.IsKeyPressed(HGEK_RIGHT)&&(keyhold = HGEK_RIGHT))
		player.Move(RIGHT);

	if(!keyhold)
		player.Stop();

	if(pressedKeys.IsKeyPressed(HGEK_SPACE)){
		WarHead* x = player.Fire();
		if(x != NULL)
			layers[1].push_back(x);
	}
	
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < layers[i].size(); ++j)
			layers[i][j]->Update(0.1);

//	if(GameConfiguration::pHGE->Input_	GetKeyState(keyhold))


	player.Update(0.1f);

}

void Scene::Render(){
	for(int i = 0; i < 3; ++i){
		if(i==1) player.Render();
		for(int j = 0; j < layers[i].size(); ++j)
			layers[i][j] -> Render();
	}
}
