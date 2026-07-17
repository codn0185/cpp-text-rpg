#include "Inventory.h"

#include "ShopSystem.h"

#include <algorithm>

using namespace std;

Slot::Slot(EItemID itemID, int count)
	: itemID(itemID), count(count)
{
}

bool Slot::CompareByPrice(const Slot& slot1, const Slot& slot2)
{
	int price1 = SHOP_TABLE.at(slot1.itemID).salePrice;
	int price2 = SHOP_TABLE.at(slot2.itemID).salePrice;
	return price1 < price2; // price 오름차순
}

bool Slot::CompareByType(const Slot& slot1, const Slot& slot2)
{
	EItemType type1 = ITEM_TABLE.at(slot1.itemID)->itemType;
	EItemType type2 = ITEM_TABLE.at(slot2.itemID)->itemType;
	return type1 < type2; // EItemType 오름차순
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

void Inventory::clearEmptySlots()
{
	for (auto iter = inventorySlots.begin(); iter != inventorySlots.end(); )
	{
		if (iter->count == 0)
		{
			iter = inventorySlots.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void Inventory::compact()
{
	clearEmptySlots(); // 빈 슬롯 제거

	// 아이템 순서 확인
	vector<EItemID> itemIDs; // 아이템 등장 순서
	for (const Slot& slot : inventorySlots)
	{
		if (find(itemIDs.begin(), itemIDs.end(), slot.itemID) == itemIDs.end()) // 동일 종류 아이템 중 첫 등장
		{
			itemIDs.push_back(slot.itemID);
		}
	}

	// 순서대로 아이템 배치
	inventorySlots.clear();
	for (const EItemID& itemID : itemIDs)
	{
		int count = itemCounts[itemID];
		while (count)
		{
			int temp = min(maxStackSize, count);
			inventorySlots.push_back(Slot(itemID, temp));
			count -= temp;
		}
	}
}

int Inventory::getUsedSlotCount()
{
	clearEmptySlots();
	return (int) inventorySlots.size();
}

bool Inventory::isFullSlot()
{
	return getUsedSlotCount() == maxSlotCount;
}

int Inventory::getItemCount(EItemID itemID)
{
	return itemCounts[itemID];
}

bool Inventory::hasItem(EItemID itemID, int count)
{
	return itemCounts[itemID] >= count;
}

int Inventory::addItem(EItemID itemID, int amount)
{
	// 동일한 종류 아이템 슬롯 우선 채우기
	for (Slot& slot : inventorySlots)
	{
		if (itemID == slot.itemID)
		{
			int temp = min(amount, maxStackSize - slot.count); // 해당 슬롯에 추가 가능한 개수
			slot.count += temp;
			amount -= temp;
			itemCounts[itemID] += temp;
			if (amount == 0)
			{
				return 0;
			}
		}
	}

	// 빈 슬롯에 아이템 채우기
	while (!isFullSlot())
	{
		Slot slot(itemID, min(amount, maxStackSize));
		inventorySlots.push_back(slot);
		amount -= slot.count;
		itemCounts[itemID] += slot.count;
		if (amount == 0)
		{
			break;
		}
	}

	return amount;  // 남은 개수 반환
}

bool Inventory::removeItem(EItemID itemID, int amount)
{
	// 제거할 개수가 충분한지 확인
	if (itemCounts[itemID] < amount)
	{
		return false; // 개수 부족하여 제거 불가
	}

	// 아이템 제거
	itemCounts[itemID] -= amount; // 개수 업데이트
	for (Slot& slot : inventorySlots)
	{
		if (itemID == slot.itemID)
		{
			int temp = min(amount, slot.count);
			slot.count -= temp;
			amount -= temp;
			if (amount == 0)
			{
				break;
			}
		}
	}
	clearEmptySlots(); // 빈 슬롯 제거
	return true; // 제거 완료
}

const vector<Slot> Inventory::getInventorySlots(vector<EItemID> itemIDFilters, vector<EItemType> itemTypeFilters) const
{
	vector<Slot> filteredInventorySlots;
	for (const Slot& slot : inventorySlots)
	{
		EItemType itemType = ITEM_TABLE.at(slot.itemID)->itemType;
		if (
			(itemIDFilters.empty() || find(itemIDFilters.begin(), itemIDFilters.end(), slot.itemID) != itemIDFilters.end()) &&
			(itemTypeFilters.empty() || find(itemTypeFilters.begin(), itemTypeFilters.end(), itemType) != itemTypeFilters.end()) &&
			slot.count != 0
			)
		{
			filteredInventorySlots.push_back(slot);
		}
	}
	return filteredInventorySlots;
}

const map<EItemID, int> Inventory::getItemCounts(vector<EItemID> itemIDFilters, vector<EItemType> itemTypeFilters) const
{
	map<EItemID, int> filteredItemCounts;
	for (const auto& [itemID, count] : itemCounts)
	{
		EItemType itemType = ITEM_TABLE.at(itemID)->itemType;
		if (
			(itemIDFilters.empty() || find(itemIDFilters.begin(), itemIDFilters.end(), itemID) != itemIDFilters.end()) &&
			(itemTypeFilters.empty() || find(itemTypeFilters.begin(), itemTypeFilters.end(), itemType) != itemTypeFilters.end()) &&
			count != 0
			)
		{
			filteredItemCounts[itemID] = count;
		}
	}
	return filteredItemCounts;
}

void Inventory::sortSlots(function<bool(const Slot&, const Slot&)> compare, bool reverse)
{
	if (!reverse)
	{
		sort(inventorySlots.begin(), inventorySlots.end(), compare);
	}
	else
	{
		sort(inventorySlots.rbegin(), inventorySlots.rend(), compare);
	}
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
