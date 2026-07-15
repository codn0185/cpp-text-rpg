#pragma once

#include "Items.h"

#include <vector>
#include <map>
#include <algorithm>

class Inventory
{
private:
	int maxSlotCount; // 인벤토리 슬롯 수
	int maxStackSize; // 슬롯 당 스택 개수

	std::map<EItemID, int> inventory; // 인벤토리

public:
	Inventory(int maxSlotCount, int maxStackSize = 1);
	~Inventory() = default;

	int getUsedSlotCount(); // 사용 중인 슬롯 개수
	bool isFullSlot(); // 슬롯 가득 찼는지 여부

	int addItem(EItemID itemID, int amount = 1); // 아이템 추가 (추가 못하고 남은 수 반환)
	bool removeItem(EItemID itemID, int amount = 1); // 아이템 제거 (제거 가능 여부 반환)

	int getItemCount(EItemID itemID) const; // 아이템 개수 반환
	const std::map<EItemID, int> getInventory(std::vector<EItemID> filters = {}) const; // 인벤토리 가져오기

	const std::vector<std::pair<EItemID, int>> getSlots() const; // 슬롯 가져오기

	// Getters
	int getMaxSlotCount();
	int getMaxStackSize();

	// Setters
	void setMaxSlotCount(int maxSlotCount);
	void setMaxStackSize(int maxStackSize);
};


