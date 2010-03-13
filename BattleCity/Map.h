#pragma once

#include <vector>
#include <string>
#include "MapObject.h"

class Map
{
public:
	Map(const char* filename);
	~Map();
	void Render(UINT layer);
private:
	std::string m_Levelname;
	UINT m_iSizeX, m_iSizeY;
	std::vector<std::vector<MapObject*>> data;
};