#pragma once

#include "IGameState.h"

class GameExitState : public IGameState
{
public:
	using IGameState::IGameState;

	bool needInput() override;
	void handleInput(std::istream& in) override;
	void onEnter() override;
	void onExit() override;
};

