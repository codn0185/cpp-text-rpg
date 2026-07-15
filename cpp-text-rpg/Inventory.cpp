#include "Inventory.h"

using namespace std;

Slot::Slot(EItemID itemID, int count)
	: itemID(itemID), count(count)
{
}

bool Slot::CompareByPrice(const Slot& slot1, const Slot& slot2)
{
	int price1 = ITEM_TABLE.at(slot1.itemID)->price;
	int price2 = ITEM_TABLE.at(slot2.itemID)->price;
	return price1 < price2; // price 오름차순
}

bool Slot::CompareByName(const Slot& slot1, const Slot& slot2)
{
	string name1 = ITEM_TABLE.at(slot1.itemID)->name;
	string name2 = ITEM_TABLE.at(slot2.itemID)->name;
	return name1 < name2; // name 오름차순
}

bool Slot::CompareByCount(const Slot& slot1, const Slot& slot2)
{
	int count1 = slot1.count;
	int count2 = slot2.count;
	return count1 < count2; // count 오름차순
}


Inventory::Inventory(int maxSlotCount, int maxStackSize)
	: maxSlotCount(maxSlotCount), maxStackSize(maxStackSize)
{
}

int Inventory::getUsedSlotCount()
{
	int slots = 0;
	for (const auto& [itemID, count] : inventory)
	{
		if (count % maxStackSize)
		{
			slots++;
		}
		slots += count / maxStackSize;
	}
	return slots;
}

bool Inventory::isFullSlot()
{
	return getUsedSlotCount() == maxSlotCount;
}

int Inventory::addItem(EItemID itemID, int amount)
{
	// 추가 가능한 아이템 개수
	int roomAmount = maxStackSize * (maxSlotCount - getUsedSlotCount()); // 빈 슬롯
	int reminder = inventory[itemID] % maxStackSize; // 최대치가 아닌 슬롯을 차지하는 아이템 크기
	if (reminder != 0)
	{
		roomAmount += maxStackSize - (reminder); // 최대치가 아닌 슬롯
	}
	// 아이템 추가 및 반환
	if (roomAmount >= amount) // 모두 획득
	{
		inventory[itemID] += amount;
		return 0;
	}
	else // 일부 획득 (나머지 반환)
	{
		inventory[itemID] += roomAmount;
		return amount - roomAmount;
	}

}

bool Inventory::removeItem(EItemID itemID, int amount)
{
	if (inventory[itemID] >= amount)
	{
		inventory[itemID] -= amount;
		return true;
	}
	return false;
}

int Inventory::getItemCount(EItemID itemID) const
{
	if (inventory.find(itemID) != inventory.end())
	{
		return inventory.at(itemID);
	}
	return 0;
}

const map<EItemID, int> Inventory::getInventory(std::vector<EItemID> itemIDFilters, std::vector<EItemType> itemTypeFilters) const
{
	map<EItemID, int> filteredInventory;
	for (const auto& [itemID, count] : inventory)
	{
		EItemType itemType = ITEM_TABLE.at(itemID)->itemType;
		if (
			(itemIDFilters.empty() || find(itemIDFilters.begin(), itemIDFilters.end(), itemID) != itemIDFilters.end()) &&
			(itemTypeFilters.empty() || find(itemTypeFilters.begin(), itemTypeFilters.end(), itemType) != itemTypeFilters.end()) &&
			count != 0
			)
		{
			filteredInventory[itemID] = count;
		}
	}

	return filteredInventory;
}

const vector<pair<EItemID, int>> Inventory::getSlots() const
{
	vector<pair<EItemID, int>> slots;
	for (const auto& [itemID, count] : inventory)
	{
		int fullSlots = count / maxStackSize;
		int leftCounts = count % maxStackSize;

		while (fullSlots--)
		{
			slots.push_back(pair(itemID, maxStackSize));
		}
		if (leftCounts)
		{
			slots.push_back(pair(itemID, leftCounts));
		}
	}
	return slots;
}

int Inventory::getMaxSlotCount()
{
	return maxSlotCount;
}

int Inventory::getMaxStackSize()
{
	return maxStackSize;
}

void Inventory::setMaxSlotCount(int maxSlotCount)
{
	this->maxSlotCount = maxSlotCount;
}

void Inventory::setMaxStackSize(int maxStackSize)
{
	this->maxStackSize = maxStackSize;
}
