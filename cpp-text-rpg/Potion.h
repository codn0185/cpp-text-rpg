#pragma once

#include "Item.h"
#include "Ingredient.h"

#include <vector>

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
	std::vector<std::pair<EItemID, int>> ingredients;

	Potion(EItemID itemID, EPotionType potionType, std::string name, std::string description = "", int price = 0, int amount = 0, std::vector<std::pair<EItemID, int>> ingredients = {});
};
