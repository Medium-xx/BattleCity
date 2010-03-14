#include "Scene.h"
#include "config.h"
#include "helper.h"
#include "GameConfiguration.h"
#include "Warhead.h"

Scene::Scene()
{
	PressedKeys::Init();
	GameConfiguration::ScreenCenter = Point(400,400);
	//HSTREAM ch;
	//ch = GameConfiguration::pHGE->Stream_Play(pResourceManager->GetStream("theme"),true);
	//GameConfiguration::pHGE->Stream_Free(ch);
	player = Tank(10,30.0,Vector2d(100,100),false,UP);
}

Scene::~Scene(void)
{
	delete m_pMap;
}

void Scene::Update(const PressedKeys& pressedKeys){

	const Point& player_position = player.GetPosition();
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
			m_vecpWarHeads.push_back(x);
	}
	
	std::vector<WarHead*> warheads;
	for(int i = 0; i < (int)m_vecpWarHeads.size(); ++i)
 		if(m_pMap->CheckAndDestroy(*m_vecpWarHeads[i])){
			SAFE_DELETE(m_vecpWarHeads[i]);
		}
		else
			warheads.push_back(m_vecpWarHeads[i]);

	m_vecpWarHeads = warheads;
	
	for(int i = 0; i < (int)m_vecpWarHeads.size(); ++i)
		m_vecpWarHeads[i]->Update(0.1f);

//	if(GameConfiguration::pHGE->Input_	GetKeyState(keyhold))


	player.Update(0.1f);


	if(!m_pMap->CanPlace(player))
		player.SetPosition(player_position);

}

void Scene::Render()
{
	m_pMap -> Render(0);
	player.Render();
	for(int j = 0; j < (int)m_vecpWarHeads.size(); ++j)
		m_vecpWarHeads[j] -> Render();
	m_pMap -> Render(1);
}

void Scene::LoadMap(const char * filename,int x0,int y0)
{
	m_pMap = new Map(filename,x0,y0);
	player.SetPosition(m_pMap->GetPlayer1SpawnPosition());
}