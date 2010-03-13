#include "Map.h"
#include "GameConfiguration.h"
#include <fstream>
#include <map>

class MapBuilder
{
public:
	MapBuilder()
	{
		debris['#'] = new MapObject(Vector2d(0,0), GameConfiguration::pResourceManager->GetSprite("s_brick_wall"),0);
		debris['*'] = new MapObject(Vector2d(0,0), GameConfiguration::pResourceManager->GetSprite("s_bush"),1);
		debris['.'] = new MapObject(Vector2d(0,0), NULL,0);
	};
	~MapBuilder()
	{
		debris.clear(); // delete mapobject pointers
	};
	MapObject* GetMapObject(const char name)
	{
		MapObject* newobject = new MapObject(Vector2d(0,0),NULL,0);
		*newobject = *(debris[name]);
		return newobject;
	}
private:
	std::map <char, MapObject*> debris;
};

Map::Map(const char* filename)
{
	std::ifstream input(filename);
	MapBuilder builder;

	input >> m_Levelname >> m_iSizeX >> m_iSizeY;
	data.resize(m_iSizeY);
	for(UINT i = 0; i < m_iSizeY; ++i)
		data[i].resize(m_iSizeX);
	input.get();
	char* buffer = new char[m_iSizeX+1];
	for(UINT i = 0; i < m_iSizeY; ++i)
	{
		input.getline(buffer, m_iSizeX+1);
		for(UINT j = 0; j < m_iSizeX; ++j)
			data[i][j] = builder.GetMapObject(buffer[j]);
	}
	delete[] buffer;
}

Map::~Map()
{
	for(UINT i = 0; i < m_iSizeY; ++i)
		for(UINT j = 0; i < m_iSizeX; ++j)
			if(data[i][j]) delete data[i][j];
}

void Map::Render(UINT layer)
{
	for (UINT i = 0; i < m_iSizeY; ++i)
		for (UINT j = 0; j < m_iSizeX; ++j)
			data[i][j]->Render(Vector2d((m_iSizeX - i - 1) * CELLSIZE, (m_iSizeY - j - 1) * CELLSIZE), layer);
}