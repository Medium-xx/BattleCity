#pragma once
#include "config.h"



class ActionPerformer
{
public:
	ActionPerformer(void);
	~ActionPerformer(void);
	void MoveTank(Tank&, Direction);
	void StopTank(Tank&);
	void MoveWarhead(Warhead&);

	void Fire(Tank&);
};
