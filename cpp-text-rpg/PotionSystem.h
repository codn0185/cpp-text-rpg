#pragma once

#include "Player.h"
#include "Items.h"

#include <vector>
#include <map>

class PotionSystem
{
private:
	std::map<EItemID, int> potionInventory;

	std::string formatIngredients(std::vector<std::pair<EItemID, int>> ingredients);
public:
	PotionSystem();
	~PotionSystem() = default;

	// Show
	void showAllRecipes();

	// Search
	void searchByPotionName(std::string potionName);
	void searchByIngredient(std::string ingredientName);

	// Use Potion
	bool usePotion(Player* player, EItemID potionID);
	bool useHPPotion(Player* player);
	bool useMPPotion(Player* player);

	// Getters
	int getPotionCount(EItemID potionID);
	int getHPPotionCount();
	int getMPPotionCount();

	// Setters
	void setPotionCount(EItemID potionID, int count);
	void setHPPotionCount(int count);
	void setMPPotionCount(int count);
};

