#pragma once

#include "Item.h"

#include <iostream>
#include <vector>

class InventorySystem
{
private:
	int maxSlots;
	vector<Item*> inventory;

public:
	InventorySystem();
	~InventorySystem();

	bool isFull();
	int getSize();

	void addItem(Item* item);
	Item* removeItem(int slot);

	void displayInventory();
};

