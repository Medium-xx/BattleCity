#include "ActionPerformer.h"
#include "DynamicObject.h"
#include "config.h"
#include "GameConfiguration.h"
#include "Tank.h"
#include "SoundManager.h"
#include "WarHead.h"
#include "Scene.h"

ActionPerformer::ActionPerformer(void)
{
}

ActionPerformer::~ActionPerformer(void)
{
}

void ActionPerformer::MoveTank(Tank& tank, Direction direction){
	Point tank_position = tank.GetPosition();
	if(tank.GetState() != MOVING)
		GameConfiguration::pSoundManager->PlayEffect(TANK_MOVING,true);
	tank.Move(direction);
	

	if(GameConfiguration::pWorld->TryToMoveTankSuccess(tank))
		return;

	// unsuccessful
	tank.SetPosition(tank_position);
}

void ActionPerformer::StopTank(Tank& tank){
	if(tank.GetState() == IDLE)
		return;
	GameConfiguration::pSoundManager->StopEffect(TANK_MOVING);
	tank.Stop();
}

void ActionPerformer::Fire(Tank& tank){
	Warhead* x = tank.Fire();
	if(x == NULL)
		return;

	GameConfiguration::pWorld->AddWarhead(x);

	GameConfiguration::pSoundManager->PlayEffect(TANK_FIRING);

}

void ActionPerformer::MoveWarhead(Warhead& warhead)
{
	warhead.Update(GameConfiguration::fDeltaTime);
	GameConfiguration::pWorld->MoveWarhead(warhead);
}