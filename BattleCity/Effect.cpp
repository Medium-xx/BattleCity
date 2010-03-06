#include "Effect.h"
#include "GameConfiguration.h"

SoundEffect::SoundEffect(char name[])
{
	m_hEffect = GameConfiguration::pResourceManager->GetEffect(name);
}

void SoundEffect::Render(){
	GameConfiguration::pHGE->Effect_Play(m_hEffect);
}