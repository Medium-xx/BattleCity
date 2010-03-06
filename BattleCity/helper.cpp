#include "helper.h"
#include "config.h"
#include "GameConfiguration.h"



int PressedKeys::IndexToKey[PressedKeys::NUM_KEYS] = { HGEK_DOWN, HGEK_LEFT, HGEK_RIGHT, HGEK_UP, HGEK_SPACE};
int PressedKeys::KeyToIndex[1<<8];

void PressedKeys::Init(){
	for(int i = 0; i < PressedKeys::NUM_KEYS; ++i)
		KeyToIndex[IndexToKey[i]] = i;
}

PressedKeys::PressedKeys(){
	for(int i = 0; i < PressedKeys::NUM_KEYS; ++i){
		if(GameConfiguration::pHGE->Input_GetKeyState(PressedKeys::IndexToKey[i]))
			m_arriPressed[i] = true;
		else
			m_arriPressed[i] = false;
	}
}

bool PressedKeys::IsKeyPressed(int key) const
{
	return m_arriPressed[PressedKeys::KeyToIndex[key]];
}