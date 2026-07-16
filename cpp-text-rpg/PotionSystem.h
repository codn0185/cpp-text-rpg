#pragma once

#include "Player.h"
#include "Inventory.h"

#include <vector>
#include <map>
#include <algorithm>

class PotionSystem
{
private:
	static std::string FormatIngredients(std::map<EItemID, int> ingredients);
public:
	// Use Potion
	static bool UsePotion(Player* player, Inventory* inventory, EItemID potionID); // 포션 사용 (성공 시 true, 실패 시 false 반환)

	// Show & Search
	static void ShowAllRecipes();
	static void SearchByPotionName(std::string potionName);
	static void SearchByIngredient(std::string ingredientName);

	// get
	static std::vector<EItemID> GetPotionIDs();
};

