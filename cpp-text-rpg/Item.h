#pragma once

#include <string>
#include <map>

using namespace std;

enum class EItemID
{
	NONE,
	SLIME_JELLY,
	GOBLIN_BLOOD,
	SKELETON_BONE,
	WATER,
	HEALING_HERB,
	MANA_DUST,
};

struct Item
{
	EItemID itemID;
	string name;
	int price;

	Item(EItemID itemID, string name, int price);
};

// 아이템 테이블
extern map<EItemID, Item*> ITEM_TABLE;
