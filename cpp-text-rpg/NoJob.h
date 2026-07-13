#pragma once

#include "Player.h"

class NoJob : public Player
{
public:
	NoJob(string name, int hp, int mp, int power, int defence);

	void showAttackMessage() const override;

	void applyBonusStat() override;
	void removeBonusStat() override;
};

