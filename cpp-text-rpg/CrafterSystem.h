#pragma once

#include "Inventory.h"
#include "Items.h"

class CrafterSystem
{
public:
	static bool CraftItem(EItemID itemID, Inventory* inventory); // 아이템 제작 (제작 성공 시 true 반환, 제작 실패 시 false 반환)
};

