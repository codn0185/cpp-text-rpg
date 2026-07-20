#pragma once

#include "IState.h"
#include "GameStateMachine.h";

class IGameState : public IState<GameStateMachine>
{
};
