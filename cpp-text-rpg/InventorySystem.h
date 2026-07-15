#pragma once

#include "Inventory.h"

#include <map>

class InventorySystem
{
public:
	static std::map<EItemID, int> AddItemsToInventroy(Inventory* inventory, std::map<EItemID, int>& items); // 인벤토리에 아이템을 추가하고 남는 아이템 적용

	static void DisplayInventory(Inventory* inventory, std::string name = "인벤토리");
	static void DisplayItems(std::map<EItemID, int> items, std::string name = "아이템 리스트");
};
