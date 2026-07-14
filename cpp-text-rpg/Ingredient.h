#pragma once

#include "Item.h"

#include <string>
#include <map>

using namespace std;

// 재료 구조체
struct Ingredient : public Item
{
	Ingredient(EItemID itemID, string name, string description = "", int price = 0);
};
