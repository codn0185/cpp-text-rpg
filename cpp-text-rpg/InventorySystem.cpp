#include "InventorySystem.h"

#include "ShopSystem.h"

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
	const vector<Slot> inventorySlots = inventory->getInventorySlots();
	for (int i = 0; i < inventorySlots.size(); i++)
	{
		const Slot& slot = inventorySlots[i];
		const string& name = ITEM_TABLE.at(slot.itemID)->name;
		const int& price = SHOP_TABLE.at(slot.itemID).salePrice;

		cout << " > " << i + 1 << ". " << name << " (" << price << "g) ── [" << slot.count << "/" << maxStackSize << "]" << "\n";
	}
	cout << "\n\n";
}

void InventorySystem::DisplayItemCounts(map<EItemID, int> items, string name)
{
	cout << "\n\n";
	cout << "============= < " << name << " > =============" << "\n";
	int num = 1;
	for (const auto& [itemID, count] : items)
	{
		const string& name = ITEM_TABLE.at(itemID)->name;
		const int& price = SHOP_TABLE.at(itemID).salePrice;

		cout << " > " << num++ << ". " << name << " (" << price << "g) ── [" << count << "개" << "]" << "\n";
	}
	cout << "\n\n";
}

void InventorySystem::SortInventorySlots(Inventory* inventory, EInventorySortKey sortKey, bool reverse)
{
	inventory->compact();
	switch (sortKey)
	{
	case EInventorySortKey::Name:
		inventory->sortSlots(Slot::CompareByPrice, reverse);
		break;
	case EInventorySortKey::Count:
		inventory->sortSlots(Slot::CompareByCount, reverse);
		break;
	case EInventorySortKey::Price:
		inventory->sortSlots(Slot::CompareByPrice, reverse);
		break;
	case EInventorySortKey::Type:
		inventory->sortSlots(Slot::CompareByType, reverse);
		break;
	default:
		break;
	}
}
