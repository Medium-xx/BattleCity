#include "Scene.h"
#include "config.h"
#include "helper.h"
#include "GameConfiguration.h"
#include "ActionPerformer.h"
#include "Warhead.h"

Scene::Scene()
{
	KeyboardManager::Init();
	GameConfiguration::ScreenCenter = Point(400,400);
	//HSTREAM ch;
	//ch = GameConfiguration::pHGE->Stream_Play(pResourceManager->GetStream("theme"),true);
	//GameConfiguration::pHGE->Stream_Free(ch);
	//player = Tank(10,30.0,Vector2d(100,100),false,UP);
	m_pPlayer1 = new Tank(10,30.0,Point(100,100),BOTS,UP,new PlayerController());
	m_vecpTanks.push_back(m_pPlayer1);
}

Scene::~Scene(void)
{
	delete m_pMap;
}

void Scene::Update(){
/*
	


	if(pressedKeys.IsKeyPressed(HGEK_SPACE)){

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
*/
	for(UINT i = 0; i < m_vecpTanks.size();++i)
		m_vecpTanks[i]->PerformAction();




	for(UINT i = 0; i < m_vecpWarheads.size();++i)
		GameConfiguration::pActionPerformer->MoveWarhead(*m_vecpWarheads[i]);

	RemoveDestroyed(reinterpret_cast<std::vector<DynamicObject*>& >(m_vecpWarheads));
	RemoveDestroyed(reinterpret_cast<std::vector<DynamicObject*>& >(m_vecpTanks));

	for(UINT i = 0; i < m_vecpAnimation.size();++i)
		if(m_vecpAnimation[i].first->IsPlaying())
			m_vecpAnimation[i].first->Update(GameConfiguration::fDeltaTime);
		else{
			std::swap(m_vecpAnimation[i],m_vecpAnimation.back());
			m_vecpAnimation.pop_back();
		}
	



}

void Scene::RemoveDestroyed(std::vector<DynamicObject*>& vec){
	for(UINT i = 0; i < vec.size(); ++i)
		if(vec[i]->IsDestroyed())
		{
			SAFE_DELETE(vec[i]);
			std::swap(vec[i],vec.back());
			vec.pop_back();
		}

}

void Scene::Render()
{
//	PlayAnimation(GameConfiguration::pResourceManager->GetAnimation("a_tank_explosion"));

	m_pMap -> Render(0);
	for(UINT i = 0; i < m_vecpTanks.size(); ++i)
		m_vecpTanks[i]->Render();

	for(UINT i = 0; i < m_vecpWarheads.size();++i)
		m_vecpWarheads[i]->Render();


	m_pMap -> Render(1);

	for(UINT i = 0; i < m_vecpAnimation.size(); ++i)
		m_vecpAnimation[i].first->Render(m_vecpAnimation[i].second.x,m_vecpAnimation[i].second.y);
}

void Scene::LoadMap(const char * filename,int x0,int y0)
{
	m_pMap = new Map(filename,x0,y0);
	m_pPlayer1->SetPosition(m_pMap->GetPlayer1SpawnPosition());
	m_vecBotSpawns = m_pMap->GetBotSpawns();
	if(!m_vecBotSpawns.empty())
		m_vecpTanks.push_back(new Tank(10,30.0,m_vecBotSpawns[0],BOTS,UP,new BotController()));
}

bool Scene::TryToMoveTankSuccess(Tank& tank)
{
	if(!m_pMap->CanPlace(tank))
		return false;
	
	for(UINT i = 0; i < m_vecpTanks.size(); ++i)
	{
		if((&tank) == m_vecpTanks[i])
			continue;
		if(tank.HeadLineIntersects(*m_vecpTanks[i]))
			return false;
	}
		
	return true;
}

void Scene::MoveWarhead(Warhead& warhead)
{
	if(warhead.IsDestroyed())
		return;

	if(m_pMap->CheckAndDestroy(warhead))
	{
		warhead.Destroy();
		return;
	}
	for(UINT i = 0; i <m_vecpTanks.size(); ++i)
		if(warhead.GetTeamId()!=m_vecpTanks[i]->GetTeamId() &&  warhead.HeadLineIntersects(*m_vecpTanks[i])){
			warhead.Destroy();
			m_vecpTanks[i]->Destroy();
			//PlayAnimation(GameConfiguration::pResourceManager->GetAnimation("a_tank_explosion"),m_vecpTanks[i]->GetPosition());
			return;
		}

	for(UINT i = 0; i < m_vecpWarheads.size(); ++i)
		if(&warhead != m_vecpWarheads[i] && warhead.HeadLineIntersects(*m_vecpWarheads[i])){
			warhead.Destroy();
			m_vecpWarheads[i]->Destroy();
			return;
		}
}

void Scene::PlayAnimation(hgeAnimation* animation, Point renderPosition)
{
	m_vecpAnimation.push_back(std::make_pair(animation,renderPosition));
	animation->Play();
}