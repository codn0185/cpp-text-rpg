#pragma once

#include "Inventory.h"

class InventorySystem
{
private:
	// int maxSlots;
	// vector<EIngredientID> inventory;

public:
	Inventory* backpackInventory; // 배낭 인벤토리
	Inventory* stockInventory; // 창고 인벤토리

	InventorySystem();
	~InventorySystem() = default;

	int addToBackpack(EItemID itemID, int amount = 1);
	bool removeFromBackpack(EItemID itemID, int amount = 1);

	void displayBackpackInventory();
	void displayStockInventory();
};
