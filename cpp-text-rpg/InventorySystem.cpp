#include "InventorySystem.h"

InventorySystem::InventorySystem() : maxSlots(10)
{
}

InventorySystem::~InventorySystem()
{
	for (Item* item : inventory)
	{
		delete item;
	}
}

bool InventorySystem::isFull()
{
	return inventory.size() == maxSlots;
}

int InventorySystem::getSize()
{
	return inventory.size();
}

void InventorySystem::addItem(Item* item)
{
	if (!isFull())
	{
		inventory.push_back(item);
	}
}

Item* InventorySystem::removeItem(int slot)
{
	slot--;
	if (slot < 0 || inventory.size() <= slot)
	{
		return nullptr;
	}

	Item* item = inventory[slot];
	inventory.erase(inventory.begin() + slot);
	return item;
}

void InventorySystem::displayInventory()
{
	cout << "========== < 인벤토리 (" << inventory.size() << "/" << maxSlots << ") > ==========" << "\n";
	for (int i = 0; i < inventory.size(); i++)
	{
		Item* item = inventory[i];
		cout << i + 1 << ". " << item->name << " (" << item->price << "g)" << "\n";
	}
	cout << "\n\n";
}
