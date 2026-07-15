#pragma once

#include "Player.h"



class Rogue :public Player
{
private:
	int attackCount;
public:
	Rogue(std::string name, int hp, int mp, int power, int defence);

	void attack(Character* target) override;
	void showAttackMessage() const override;

	void applyBonusStat() override;
	void removeBonusStat() override;
};

