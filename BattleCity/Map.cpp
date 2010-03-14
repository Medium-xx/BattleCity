#include "Map.h"
#include "GameConfiguration.h"
#include <fstream>
#include <map>
#include "tank.h"

class MapBuilder
{
public:
	MapBuilder()
	{
		debris['#'] = new MapObject(Vector2d(0,0), GameConfiguration::pResourceManager->GetSprite("s_brick_wall"),0);
		debris['*'] = new MapObject(Vector2d(0,0), GameConfiguration::pResourceManager->GetSprite("s_bush"),1);
		debris['.'] = debris['+'] = new MapObject(Vector2d(0,0), NULL,0);
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

Map::Map(const char* filename,int x0,int y0)
{
	this->x0 = x0;
	this->y0 = y0;

	m_Player1Spawn = Point((float)CELL_SIZE,(float)CELL_SIZE);
	
	std::ifstream input(filename);
	MapBuilder builder;

	input >> m_Levelname >> m_iSizeY >> m_iSizeX;
	data.resize(m_iSizeY);
	for(UINT i = 0; i < m_iSizeY; ++i)
		data[i].resize(m_iSizeX);
	input.get();
	
	for(UINT i = 0; i < m_iSizeY; ++i)
	{
		input.getline(m_field[i], m_iSizeX+1);
		for(UINT j = 0; j < m_iSizeX; ++j)
		{
			data[i][j] = builder.GetMapObject(m_field[i][j]);
			if(m_field[i][j] == '+')
			{
				m_Player1Spawn = Point(CELL_SIZE*(j+1.0f),CELL_SIZE*(i+1.0f));
				m_field[i][j] = '.';
			}
		}
	}
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
			if(data[i][j]!=NULL)
				data[i][j]->Render(Vector2d(j * CELL_SIZE+0.0f, i * CELL_SIZE+0.0f), layer);
}

bool Map::CanPlace(const Tank& tank){
	const Geometry::Segment head_segment = tank.GetHeadSegment();
	return !this->HasCollisions(head_segment);
	//int di = 
	/*	return IsEmpty(rect.m_A.x,rect.m_A.y)&&
			IsEmpty(rect.m_A.x,rect.m_B.y)&&
			IsEmpty(rect.m_B.x,rect.m_A.y)&&
			IsEmpty(rect.m_B.x,rect.m_B.y);*/
	return true;
}
 
bool Map::IsEmpty(float x0,float y0){
	int i = (int)floor(y0/CELL_SIZE + EPS);
	int j = (int)floor(x0/CELL_SIZE + EPS);
	return m_field[i][j] != '#';
}

bool Map::CheckAndDestroy(const WarHead& X){
	Geometry::Segment head_segment = X.GetHeadSegment();
	if(!HasCollisions(head_segment))
		return false;
	
	Destroy(head_segment);
	return true;
}

std::pair<int,int> GetIndeces(Point A){
	return std::make_pair((int)floor(A.y/CELL_SIZE+EPS),(int)floor(A.x/CELL_SIZE+EPS));
}

bool Map::HasCollisions(const Geometry::Segment &seg){
	typedef std::pair<int,int> pii;
	pii ind1 = GetIndeces(seg.m_A);
	pii ind2 = GetIndeces(seg.m_B);

	int di = ind2.first - ind1.first > 0 ? 1:0;
	int dj = ind2.second - ind1.second > 0 ? 1:0;

	if(di == 0 && dj == 0)
		return m_field[ind1.first][ind1.second] == '#';

	if(di == 0)
		for(int j = ind1.second; j <= ind2.second; j+=dj)
		{
			if(m_field[ind1.first][j] == '#') 
				return true;
		}
	else
		for(int i = ind1.first; i <= ind2.first ; i+=di)	
		{
			if(m_field[i][ind1.second] == '#') 
				return true;
		}

			

	return false;
}


void Map::Destroy(Geometry::Segment& seg){
	typedef std::pair<int,int> pii;
	pii ind1 = GetIndeces(seg.m_A);
	pii ind2 = GetIndeces(seg.m_B);

	int di = ind2.first - ind1.first > 0 ? 1:0;
	int dj = ind2.second - ind1.second > 0 ? 1:0;

	if(di == 0 && dj == 0)
	{
		DestroyCell(ind1.first,ind1.second);
		return;
	}

	if(di == 0)
		for(int j = ind1.second; j <= ind2.second; j+=dj)
			DestroyCell(ind1.first,j);
	else
		for(int i = ind1.first; i <= ind2.first ; i+=di)	
			DestroyCell(i,ind1.second);

}

void Map::DestroyCell(int i,int j){
	if(m_field[i][j] == '#'){
		m_field[i][j] = '.';
		SAFE_DELETE(data[i][j]);
	}
}