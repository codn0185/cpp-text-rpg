#pragma once

#include "IState.h"
#include "GameStateMachine.h"

class IGameState : public IState<GameStateMachine>
{
public:
	using IState<GameStateMachine>::IState;
};
