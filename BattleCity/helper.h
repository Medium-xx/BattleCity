#pragma once
#include "config.h"

enum Direction;
class KeyboardManager
{
	const static int NUM_KEYS = 5;
	bool m_aiPressed[NUM_KEYS];
	static int IndexToKey[];
	static int KeyToIndex[];
	
	std::vector<int> pressed;

	void PushPressed(int i);
	void PopPressed(int i);

public:
	static void Init();
	KeyboardManager();

	bool IsKeyPressed(int key) const;
	int GetLastMovingKey() const;
	void Listen(); 
};

float DirectionToAngle(Direction);