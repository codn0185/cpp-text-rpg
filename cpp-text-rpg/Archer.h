#pragma once

#include "Player.h"

class Archer : public Player
{
private:
	int attackCount;
public:
	Archer(std::string name, int hp, int mp, int power, int defence);

	void attack(Character* target) override;
	void showAttackMessage() const override;

	void applyBonusStat() override;
	void removeBonusStat() override;
};

