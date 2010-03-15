#include "SoundManager.h"
#include "GameConfiguration.h"

SoundManager::SoundManager(void)
{
	m_aEffects[TANK_MOVING] = GameConfiguration::pResourceManager->GetEffect("tank_move");
	m_aEffects[TANK_FIRING] = GameConfiguration::pResourceManager->GetEffect("fire");
	//	if(GameConfiguration::pHGE->Channel_IsPlaying(m_hChannel))
	// GameConfiguration::pHGE->Channel_Stop(m_hChannel);
}

SoundManager::~SoundManager(void)
{
}


void SoundManager::PlayEffect(SoundEffectType type,bool bWithLoop)
{
	if(type == TANK_FIRING)
	{
		GameConfiguration::pHGE->Effect_Play(m_aEffects[type]);
		return;
	}
	m_vecTankMovingChannels[type].push_back(GameConfiguration::pHGE->Effect_PlayEx(m_aEffects[type],100,0,1.0f, bWithLoop));
}

void SoundManager::StopEffect(SoundEffectType type)
{
	if(m_vecTankMovingChannels[type].empty())
		return;
	HCHANNEL tmp = m_vecTankMovingChannels[type].back();
	if(GameConfiguration::pHGE->Channel_IsPlaying(tmp))
		GameConfiguration::pHGE->Channel_Stop(tmp);

	m_vecTankMovingChannels[type].pop_back();
}