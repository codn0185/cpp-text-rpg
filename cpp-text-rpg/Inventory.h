#pragma once

#include "Items.h"

#include <vector>
#include <map>
#include <algorithm>

struct Slot
{
	EItemID itemID;
	int count;

	Slot(EItemID itemID, int count);

	// 오름차순 정렬
	static bool CompareByPrice(const Slot& slot1, const Slot& slot2);
	static bool CompareByName(const Slot& slot1, const Slot& slot2);
	static bool CompareByCount(const Slot& slot1, const Slot& slot2);
};

class Inventory
{
private:
	int maxSlotCount; // 인벤토리 슬롯 수
	int maxStackSize; // 슬롯 당 스택 개수

	std::map<EItemID, int> inventory; // 인벤토리

	std::vector<Slot> inventorySlots; // 인벤토리 슬롯 (실제로 보여지는 영역)
	std::map<EItemID, int> itemCounts; // 아이템 개수 (숨겨진 영역)

	void clearEmptySlots();

public:
	Inventory(int maxSlotCount, int maxStackSize = 1);
	~Inventory() = default;

	void compact(); // 아이템 압축

	int getUsedSlotCount(); // 사용 중인 슬롯 개수
	bool isFullSlot(); // 슬롯 가득 찼는지 여부

	int addItem(EItemID itemID, int amount = 1); // 아이템 추가 (추가 못하고 남은 수 반환)
	bool removeItem(EItemID itemID, int amount = 1); // 아이템 제거 (제거 가능 여부 반환)

	const vector<Slot> getInventorySlots(std::vector<EItemID> itemIDFilters = {}, std::vector<EItemType> itemTypeFilters = {}); // 슬롯들 가져오기 (필터 적용)

	int getItemCount(EItemID itemID); // 아이템 개수 반환
	const std::map<EItemID, int> getInventory(std::vector<EItemID> itemIDFilters = {}, std::vector<EItemType> itemTypeFilters = {}) const; // 인벤토리 가져오기 (필터 EItemID / EItemType)

	const std::vector<std::pair<EItemID, int>> getSlots() const; // 슬롯 가져오기

	// Getters
	int getMaxSlotCount();
	int getMaxStackSize();

	// Setters
	void setMaxSlotCount(int maxSlotCount);
	void setMaxStackSize(int maxStackSize);
};


