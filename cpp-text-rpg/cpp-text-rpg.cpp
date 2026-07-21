#include "GameManager.h"
#include "GameStateMachine.h"

int main()
{
	GameManager& gm = GameManager::GetInstance();
	gm.run();

	// 	GameStateMachine game;
	// 	game.run();
}
