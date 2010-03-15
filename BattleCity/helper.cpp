#include "helper.h"
#include "config.h"
#include "GameConfiguration.h"



int KeyboardManager::IndexToKey[KeyboardManager::NUM_KEYS] = { HGEK_DOWN, HGEK_LEFT, HGEK_RIGHT, HGEK_UP, HGEK_SPACE};
int KeyboardManager::KeyToIndex[1<<8];

void KeyboardManager::Init(){
	for(int i = 0; i < KeyboardManager::NUM_KEYS; ++i)
		KeyToIndex[IndexToKey[i]] = i;
}

KeyboardManager::KeyboardManager(){
	KeyboardManager::Init();
}

bool KeyboardManager::IsKeyPressed(int key) const
{
	return m_aiPressed[KeyboardManager::KeyToIndex[key]];
}

void KeyboardManager::Listen(){
	for(int i = 0; i < KeyboardManager::NUM_KEYS; ++i){
		if(GameConfiguration::pHGE->Input_GetKeyState(KeyboardManager::IndexToKey[i]))
		{
			if(i<4 && m_aiPressed[i] == false)
				PushPressed(i);

			m_aiPressed[i] = true;
		}
		else
		{		
			if(i<4)
				PopPressed(i);

			m_aiPressed[i] = false;
		}
	}
	if(std::count(m_aiPressed,m_aiPressed+4,true)==0)
		pressed.clear();

//	if(std::count(m_aiPressed,m_aiPressed+3,false) == 0){
//		int z = 0;
//	}
}

int KeyboardManager::GetLastMovingKey() const
{
	if(pressed.empty())
		return 0;
	else
		return KeyboardManager::IndexToKey[pressed.back()];
}

void KeyboardManager::PushPressed(int key)
{
	PopPressed(key);
	pressed.push_back(key);
}

void KeyboardManager::PopPressed(int key)
{
	if(m_aiPressed[key]){
		for(std::vector<int>::iterator it = pressed.begin(); it!=pressed.end(); ++it)
			if(*it == key){
				pressed.erase(it);
				break;
			}
	}
}


float DirectionToAngle(Direction direction)
{
	switch(direction){
		case UP:
			return 0.0f;
		case DOWN:
			return M_PI;
		case LEFT:
			return -M_PI_2;
		case RIGHT:
			return M_PI_2;
	}

	return 0.0f;
}