#include "Inventory.h"

template<typename ItemID_T>
Inventory<ItemID_T>::Inventory(int maxSlotCount, int maxStackSize)
	: maxSlotCount(maxSlotCount), maxStackSize(maxStackSize)
{
}

template<typename ItemID_T>
int Inventory<ItemID_T>::getUsedSlotCount()
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

template<typename ItemID_T>
bool Inventory<ItemID_T>::isFullSlot()
{
	return getUsedSlotCount() == maxSlotCount;
}

template<typename ItemID_T>
int Inventory<ItemID_T>::addItem(ItemID_T itemID, int amount)
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

template<typename ItemID_T>
bool Inventory<ItemID_T>::removeItem(ItemID_T itemID, int amount)
{
	if (inventory[itemID] >= amount)
	{
		inventory[itemID] - amount;
		return true;
	}
	return false;
}

template<typename ItemID_T>
int Inventory<ItemID_T>::getMaxSlotCount()
{
	return maxSlotCount;
}

template<typename ItemID_T>
int Inventory<ItemID_T>::getMaxStackSize()
{
	return maxStackSize;
}

template<typename ItemID_T>
void Inventory<ItemID_T>::setMaxSlotCount(int maxSlotCount)
{
	this->maxSlotCount = maxSlotCount;
}

template<typename ItemID_T>
void Inventory<ItemID_T>::setMaxStackSize(int maxStackSize)
{
	this->maxStackSize = maxStackSize;
}