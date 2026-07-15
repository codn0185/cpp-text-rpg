#include "Inventory.h"

using namespace std;

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

const std::map<EItemID, int> Inventory::getInventory() const
{
	return inventory;
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