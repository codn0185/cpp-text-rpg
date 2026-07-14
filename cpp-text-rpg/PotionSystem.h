#pragma once

#include "Player.h"
#include "Potion.h"
#include "Ingredient.h"

#include <vector>
#include <map>

class PotionSystem
{
private:
	map<EPotionID, int> potionInventory;

	string formatIngredients(vector<pair<EIngredientID, int>> ingredients);
public:
	PotionSystem();
	~PotionSystem() = default;

	// Show
	void showAllRecipes();

	// Search
	void searchByPotionName(string potionName);
	void searchByIngredient(string ingredientName);

	// Use Potion
	bool usePotion(Player* player, EPotionID potionID);
	bool useHPPotion(Player* player);
	bool useMPPotion(Player* player);

	// Getters
	int getPotionCount(EPotionID potionID);
	int getHPPotionCount();
	int getMPPotionCount();

	// Setters
	void setPotionCount(EPotionID potionID, int count);
	void setHPPotionCount(int count);
	void setMPPotionCount(int count);
};

