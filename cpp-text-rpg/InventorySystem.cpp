#include "InventorySystem.h"

#include <iostream>

InventorySystem::InventorySystem()
	: backpackInventory(new Inventory(3, 1)), stockInventory(new Inventory(20, 30))
{
}

int InventorySystem::addToBackpack(EItemID itemID, int amount)
{
	return backpackInventory->addItem(itemID, amount);
}

bool InventorySystem::removeFromBackpack(EItemID itemID, int amount)
{
	return backpackInventory->removeItem(itemID, amount);;
}

void InventorySystem::displayBackpackInventory()
{
	int usedSlots = backpackInventory->getUsedSlotCount();
	int maxSlots = backpackInventory->getMaxSlotCount();
	int maxStackSize = backpackInventory->getMaxStackSize();

	cout << "\n\n";
	cout << "======== < 배낭 인벤토리 (" << usedSlots << "/" << maxSlots << ") > ========" << "\n";
	vector<pair<EItemID, int>> slots = backpackInventory->getSlots();
	for (int i = 0; i < slots.size(); i++)
	{
		EItemID itemID = slots[i].first;
		int count = slots[i].second;
		string name = ITEM_TABLE.at(itemID)->name;
		int price = ITEM_TABLE.at(itemID)->price;

		cout << " > " << i + 1 << ". " << name << " (" << price << "g) ── [" << count << "/" << maxStackSize << "]" << "\n";
	}
	cout << "\n\n";
}

void InventorySystem::displayStockInventory()
{
	int usedSlots = stockInventory->getUsedSlotCount();
	int maxSlots = stockInventory->getMaxSlotCount();
	int maxStackSize = stockInventory->getMaxStackSize();

	cout << "\n\n";
	cout << "======== < 배낭 인벤토리 (" << usedSlots << "/" << maxSlots << ") > ========" << "\n";
	vector<pair<EItemID, int>> slots = stockInventory->getSlots();
	for (int i = 0; i < slots.size(); i++)
	{
		EItemID itemID = slots[i].first;
		int count = slots[i].second;
		string name = ITEM_TABLE.at(itemID)->name;
		int price = ITEM_TABLE.at(itemID)->price;

		cout << " > " << i + 1 << ". " << name << " (" << price << "g) ── [" << count << "/" << maxStackSize << "]" << "\n";
	}
	cout << "\n\n";
}
