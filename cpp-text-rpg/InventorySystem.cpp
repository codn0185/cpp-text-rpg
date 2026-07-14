#include "InventorySystem.h"

#include <iostream>

InventorySystem::InventorySystem() : maxSlots(10)
{
}

bool InventorySystem::isFull()
{
	return inventory.size() == maxSlots;
}

int InventorySystem::getSize()
{
	return inventory.size();
}

void InventorySystem::addItem(EIngredientID itemID)
{
	if (!isFull())
	{
		inventory.push_back(itemID);
	}
}

EIngredientID InventorySystem::removeItem(int slot)
{
	slot--;
	if (slot < 0 || inventory.size() <= slot)
	{
		return EIngredientID::NONE;
	}

	EIngredientID itemID = inventory[slot];
	inventory.erase(inventory.begin() + slot);
	return itemID;
}

void InventorySystem::displayInventory()
{
	cout << "========== < 인벤토리 (" << inventory.size() << "/" << maxSlots << ") > ==========" << "\n";
	for (int i = 0; i < inventory.size(); i++)
	{
		EIngredientID itemID = inventory[i];
		cout << i + 1 << ". " << INGREDIENT_TABLE.at(itemID).name << " (" << INGREDIENT_TABLE.at(itemID).price << "g)" << "\n";
	}
	cout << "\n\n";
}
