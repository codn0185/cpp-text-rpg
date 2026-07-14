#pragma once

#include "Ingredient.h"

#include <vector>

class InventorySystem
{
private:
	int maxSlots;
	vector<EIngredientID> inventory;

public:
	InventorySystem();
	~InventorySystem() = default;

	bool isFull();
	int getSize();

	void addItem(EIngredientID itemID);
	EIngredientID removeItem(int slot);

	void displayInventory();
};

//  포션 인벤토리 & 재료 인벤토리 분류