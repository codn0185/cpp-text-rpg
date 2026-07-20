#include "GameStateMachine.h"

#include "GameStartState.h"

GameStateMachine::GameStateMachine()
	: IStateMachine<GameStateMachine>(new GameStartState(this))
{
}