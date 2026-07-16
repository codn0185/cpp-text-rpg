#pragma once

#include <string>
#include <map>
#include <memory>

enum EItemID
{
	// 포션
	HP_POTION_20,
	MP_POTION_20,
	// 재료
	BOTTLE, // 공병 (포션 재료 및 포션 사용 시 자동 반환)
	WATER,
	HEALING_HERB,
	MANA_DUST,
	// 기타
	SLIME_JELLY,
	GOBLIN_BLOOD,
	SKELETON_BONE,
};

enum EItemType
{
	POTION, // 포션
	INGREDIENT, // 재료
	MISC, // 기타
};

struct Item
{
	EItemID itemID;
	EItemType itemType;
	std::string name;
	std::string description;
	int price;

	bool isCraftable; // 제작 가능 여부
	std::map<EItemID, int> ingredients; // 제작 재료

	Item(
		EItemID itemID,
		EItemType itemType,
		std::string name,
		std::string description = "",
		int price = 0,
		bool isCraftable = false,
		std::map<EItemID, int> ingredients = {}
	);
};

extern const std::map<EItemID, std::shared_ptr<Item>> ITEM_TABLE;
