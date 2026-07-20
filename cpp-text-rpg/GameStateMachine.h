#pragma once

#include "IStateMachine.h"

#include "Player.h"
#include "Inventory.h"

class GameStateMachine : public IStateMachine<GameStateMachine>
{
public:
	Player* player;
	Inventory* inventory;

	GameStateMachine();
	~GameStateMachine();
};

