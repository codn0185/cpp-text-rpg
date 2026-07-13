#pragma once

#include "Player.h"
#include "Item.h"

#include <vector>
#include <map>
#include <algorithm>

class PotionSystem
{
private:
	int hpPotionCount;
	int hpPotionIncreasedAmount;

	int mpPotionCount;
	int mpPotionIncreasedAmount;

	// 포션 레시피
// 	vector < vector < string>> 

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

