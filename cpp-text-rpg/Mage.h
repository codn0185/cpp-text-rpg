#pragma once

#include "Player.h"

class Mage : public Player
{
public:
	Mage(std::string name, int hp, int mp, int power, int defence);

	void attack(Character* target) override;
	void showAttackMessage() const override;

	void applyBonusStat() override;
	void removeBonusStat() override;
};

