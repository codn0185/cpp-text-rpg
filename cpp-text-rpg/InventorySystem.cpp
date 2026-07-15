#include "InventorySystem.h"

#include <iostream>
#include <vector>

using namespace std;

map<EItemID, int> InventorySystem::AddItemsToInventroy(Inventory* inventory, map<EItemID, int>& items)
{
	map<EItemID, int> addedItems; // 추가된 아이템들

	// 아이템 추가
	for (auto& [itemID, count] : items)
	{
		int leftCount = inventory->addItem(itemID, count);
		int addedCount = count - leftCount;

		count = leftCount;

		if (addedCount > 0)
		{
			addedItems[itemID] += addedCount;
		}
	}

	// 개수 0인 아이템 제거
	for (auto it = items.begin(); it != items.end(); )
	{
		if (it->second == 0)
		{
			it = items.erase(it);
		}
		else
		{
			++it;
		}
	}

	return addedItems;
}

void InventorySystem::DisplayInventory(Inventory* inventory, string name)
{
	int usedSlots = inventory->getUsedSlotCount();
	int maxSlots = inventory->getMaxSlotCount();
	int maxStackSize = inventory->getMaxStackSize();

	cout << "\n\n";
	cout << "======== < " << name << " (" << usedSlots << "/" << maxSlots << ") > ========" << "\n";
	vector<pair<EItemID, int>> slots = inventory->getSlots();
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
