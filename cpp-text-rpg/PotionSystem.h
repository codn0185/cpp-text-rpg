#pragma once

#include "Player.h"

class PotionSystem
{
private:
	int hpPotionCount;
	int hpPotionIncreasedAmount;

	int mpPotionCount;
	int mpPotionIncreasedAmount;

public:
	PotionSystem();
	~PotionSystem() = default;

	// Use Potion
	bool useHPPotion(Player* player);
	bool useMPPotion(Player* player);

	// Getters
	int getHPPotionCount();
	int getMPPotionCount();

	// Setters
	void setHPPotionCount(int hpPotionCount);
	void setMPPotionCount(int mpPotionCount);
};

