#pragma once

#include "Player.h"
#include "Ingredient.h"

#include <iostream>
#include <vector>
#include <map>

// 포션 ID
enum class EPotionID
{
	HP_POTION_20,
	MP_POTION_20,
};

// 포션 타입
enum class EPotionType
{
	HP_POTION,
	MP_POTION,
};

// 포션 데이터
struct PotionDataRow
{
	EPotionID potionID; // 포션 ID
	EPotionType potionType; // 포션 타입
	string name; // 포션 이름
	string description; // 포션 설명
	vector<pair<EIngredientID, int>> ingredients; // 재료 (아이템, 개수)

	PotionDataRow(EPotionID potionID, EPotionType potionType, string name, string description = "", vector<pair<EIngredientID, int>> ingredients = {}) :
		potionID(potionID), potionType(potionType), name(name), description(description), ingredients(ingredients)
	{
	}
};

// 포션 테이블
extern map<EPotionID, PotionDataRow> POTION_TABLE;

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

