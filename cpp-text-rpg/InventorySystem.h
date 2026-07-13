#pragma once

#include "Item.h"

#include <iostream>
#include <vector>

class InventorySystem
{
private:
	int maxSlots;
	vector<EItemID> inventory;

public:
	InventorySystem();
	~InventorySystem() = default;

	bool isFull();
	int getSize();

	void addItem(EItemID itemID);
	EItemID removeItem(int slot);

	void displayInventory();
};

