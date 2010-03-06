#pragma once
#include "GameObject.h"
#include "Timer.h"

class Weapon:public GameObject
{
	float m_fProjectileSpeed;
	float m_fDamage;
	Timer m_CoolDown;

public:
	Weapon();
	bool IsReady();
	void Reload();
	inline float ProjectileSpeed()  { return m_fProjectileSpeed; }
};