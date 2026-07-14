#pragma once

#include "Item.h"
#include "Ingredient.h"

#include <vector>
#include <map>

// 포션 타입
enum class EPotionType
{
	HP_POTION,
	MP_POTION,
};


// 포션 구조체
struct Potion : public Item
{
	EPotionType potionType;
	int amount;
	vector<pair<EItemID, int>> ingredients;

	Potion(EItemID itemID, EPotionType potionType, string name, string description = "", int price = 0, int amount = 0, vector<pair<EItemID, int>> ingredients = {});
};
