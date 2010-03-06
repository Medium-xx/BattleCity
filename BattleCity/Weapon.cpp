#include "Weapon.h"

Weapon::Weapon():m_CoolDown(0.5){
	m_fProjectileSpeed = 60.0;
	m_fDamage = 1.0;
}

bool Weapon::IsReady(){
	return m_CoolDown.TimeIsUp();
}

void Weapon::Reload(){
	m_CoolDown.SetTimer();
}


