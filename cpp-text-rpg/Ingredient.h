#pragma once

#include "Item.h"

#include <string>
#include <map>

using namespace std;

// 재료 ID
enum class EIngredientID
{
	NONE,
	SLIME_JELLY,
	GOBLIN_BLOOD,
	SKELETON_BONE,
	WATER,
	HEALING_HERB,
	MANA_DUST,
};

// 재료 구조체
struct Ingredient : public Item
{
	EIngredientID ingredientID;
	string name;
	int price;

	Ingredient(EIngredientID ingredientID, string name, int price);

	bool canUse() override;
};

// 재료 테이블
extern const map<EIngredientID, Ingredient> INGREDIENT_TABLE;
