#pragma once

#include <string>
#include <map>

using namespace std;

enum EItemID
{
	// 포션
	HP_POTION_20,
	MP_POTION_20,
	// 재료
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
	string name;
	string description;
	int price;

	Item(EItemID itemID, EItemType itemType, string name, string description = "", int price = 0);
};

extern const map<EItemID, Item*> ITEM_TABLE;
