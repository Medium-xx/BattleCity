#pragma once
#include "config.h"


class PressedKeys{
	const static int NUM_KEYS = 5;
	bool m_arriPressed[NUM_KEYS];
	static int IndexToKey[];
	static int KeyToIndex[];
	
public:
	static void Init();
	PressedKeys();

	bool IsKeyPressed(int key) const;
};