#pragma once

#include <vector>
#include <string>
#include "MapObject.h"
#include "tank.h"
#include "WarHead.h"

class Geometry::Segment;

class Map
{
public:
	Map(const char* filename,int x0,int y0);
	~Map();
	void Render(UINT layer);
	bool CanPlace(const Tank& rect);
	const Point& GetPlayer1SpawnPosition() { return m_Player1Spawn; }
	std::vector<Point> GetBotSpawns() { return m_vecBotSpawns; }
	bool CheckAndDestroy(const Warhead& X);
private:
	std::string m_Levelname;

	UINT m_iSizeX, m_iSizeY;
	std::vector<std::vector<MapObject*>> data;
	int x0,y0;
	Point m_Player1Spawn;
	std::vector<Point> m_vecBotSpawns;

	char m_field[300][300];

	bool IsEmpty(float x0,float y0);
	bool HasCollisions(const Geometry::Segment& seg);
	void Destroy(Geometry::Segment& HeadSegment);
	void DestroyCell(int i,int j);
	bool OutOfBounds(const Geometry::Segment&) const;
};