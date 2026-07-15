#pragma once

#include "Item.h"

#include <string>

// 재료 구조체
struct Ingredient : public Item
{
	Ingredient(EItemID itemID, std::string name, std::string description = "", int price = 0);
};
