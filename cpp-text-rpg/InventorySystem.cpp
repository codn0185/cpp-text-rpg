#include "InventorySystem.h"

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

void InventorySystem::addItem(EItemID itemID)
{
	if (!isFull())
	{
		inventory.push_back(itemID);
	}
}

EItemID InventorySystem::removeItem(int slot)
{
	slot--;
	if (slot < 0 || inventory.size() <= slot)
	{
		return EItemID::NONE;
	}

	EItemID itemID = inventory[slot];
	inventory.erase(inventory.begin() + slot);
	return itemID;
}

void InventorySystem::displayInventory()
{
	cout << "========== < 인벤토리 (" << inventory.size() << "/" << maxSlots << ") > ==========" << "\n";
	for (int i = 0; i < inventory.size(); i++)
	{
		EItemID itemID = inventory[i];
		cout << i + 1 << ". " << ITEM_TABLE[itemID]->name << " (" << ITEM_TABLE[itemID]->price << "g)" << "\n";
	}
	cout << "\n\n";
}
