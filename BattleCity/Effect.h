#pragma once
#include "config.h"

class Effect
{
public:
	virtual void Render()=0;
};

class SoundEffect:public Effect{
	HEFFECT m_hEffect;
public:
	SoundEffect(char name[]);
	void Render();
};
