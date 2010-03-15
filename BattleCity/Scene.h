#pragma once
#include "hgeresource.h"
#include "GameObject.h"
#include "Map.h"
#include "WarHead.h"


class Tank;

using std::vector;
using std::pair;

class Scene
{
private:
//	hgeResourceManager* m_pResourceManager;
	Tank* m_pPlayer1;
	Map* m_pMap;
	std::vector<GameObject*> dynamic_objects;
	std::vector<Warhead*> m_vecpWarheads;
	std::vector<Tank*> m_vecpTanks;

	std::vector<Point> m_vecBotSpawns;
	vector<pair<hgeAnimation*,Vector2d > > m_vecpAnimation;

	void RemoveDestroyed(std::vector<DynamicObject*>& vec);
	void PlayAnimation(hgeAnimation*,Point renderPosition);

//	std::vector<GameObject*> layers[3];
public:
	void Render();
	void Update();
	Scene();
	void LoadMap(const char* filename,int x0,int y0);
	void AddWarhead(Warhead* x) { m_vecpWarheads.push_back(x);}
	bool TryToMoveTankSuccess(Tank& tank);
	void MoveWarhead(Warhead&);
	~Scene(void);
};
