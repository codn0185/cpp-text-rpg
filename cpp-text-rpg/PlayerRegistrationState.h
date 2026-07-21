#pragma once

#include "IGameState.h"

#include <string>

class PlayerRegistrationState : public IGameState
{
private:
	enum class EInputStep
	{
		InputName,
		InputHPAndMP,
		InputPowerAndDefence,
		Complete,
	};

	EInputStep currentStep = EInputStep::InputName;

	std::string name;
	static const int SIZE = 4;
	int stat[SIZE] = {0}; // HP, MP, 공격력, 방어력

public:
	using IGameState::IGameState;

	bool needInput() override;
	void handleInput(std::istream& in) override;
	void onEnter() override;
	void onExit() override;
};

