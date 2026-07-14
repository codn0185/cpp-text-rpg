#pragma once

#include "Item.h"

#include <map>

using namespace std;

template <typename ItemID_T>
class Inventory
{
protected:
	int maxSlotCount; // 인벤토리 슬롯 수
	int maxStackSize; // 슬롯 당 스택 개수

	map<ItemID_T, int> inventory; // 인벤토리

public:
	Inventory(int maxSlotCount, int maxStackSize = 1);
	~Inventory() = default;

	int getMaxSlotCount();
	int getMaxStackSize();

	void setMaxSlotCount(int maxSlotCount);
	void setMaxStackSize(int maxStackSize);

	int getUsedSlotCount(); // 사용 중인 슬롯 개수
	bool isFullSlot(); // 슬롯 가득 찼는지 여부
	int addItem(ItemID_T itemID, int amount = 1); // 아이템 추가 (추가 못하고 남은 수 반환)

	virtual void displayInventroy() = 0; // 인벤토리 출력
};


