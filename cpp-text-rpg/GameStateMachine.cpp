#include "GameStateMachine.h"

#include "GameStartState.h"

GameStateMachine::GameStateMachine()
	: IStateMachine<GameStateMachine>(new GameStartState(this))
{
}

GameStateMachine::~GameStateMachine()
{
	delete player;
	delete inventory;
}
