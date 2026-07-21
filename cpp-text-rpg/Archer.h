#pragma once

#include "Player.h"

class Archer : public Player
{
private:
	int attackCount;
public:
	Archer(std::string name, int maxHP, int maxMP, int power, int defence, int level = 0, int exp = 0, int gold = 0);

	void attack(Character* target) override;
	void showAttackMessage() const override;

	void applyBonusStat() override;
	void removeBonusStat() override;
};

