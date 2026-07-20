#pragma once

#include "IStateMachine.h"

class GameStateMachine : public IStateMachine<GameStateMachine>
{
public:
	GameStateMachine();
};

