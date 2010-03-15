#pragma once
#include "config.h"

class SoundManager
{
public:
	SoundManager(void);
	~SoundManager(void);

	void PlayEffect(SoundEffectType type,bool bWithLoop = false);
	void StopEffect(SoundEffectType type);
private:
	HEFFECT m_aEffects[10];
	std::vector<HCHANNEL> m_vecTankMovingChannels[10];
};
