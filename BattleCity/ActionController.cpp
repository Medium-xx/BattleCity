#include "ActionController.h"
#include "helper.h"
#include "config.h"
#include "GameConfiguration.h"
#include "ActionPerformer.h"
#include "Tank.h"

void PlayerController::PerformAction(Tank& player){
	
	int last_moving_key_pressed = GameConfiguration::pKeyboardManager->GetLastMovingKey();
	switch(last_moving_key_pressed){
		case HGEK_UP:
			GameConfiguration::pActionPerformer->MoveTank(player,UP);		    		
			break;
		case HGEK_DOWN:
			GameConfiguration::pActionPerformer->MoveTank(player,DOWN);		    		
			break;
		case HGEK_LEFT:
			GameConfiguration::pActionPerformer->MoveTank(player,LEFT);		    		
			break;
		case HGEK_RIGHT:
			GameConfiguration::pActionPerformer->MoveTank(player,RIGHT);	
			break;
		default:
			GameConfiguration::pActionPerformer->StopTank(player);
	}

	if(GameConfiguration::pKeyboardManager->IsKeyPressed(HGEK_SPACE))
		GameConfiguration::pActionPerformer->Fire(player);
}

void BotController::PerformAction(Tank& bot){
	static int count = 0;
	static Direction dir = LEFT;

	if(count == 0){
		dir = static_cast<Direction>(GameConfiguration::pHGE->Random_Int(0,3));
		count = 10;
	}
	else --count;

	GameConfiguration::pActionPerformer->MoveTank(bot,dir);


	if(GameConfiguration::pHGE->Random_Int(0,4) == 0)
		GameConfiguration::pActionPerformer->Fire(bot);

}