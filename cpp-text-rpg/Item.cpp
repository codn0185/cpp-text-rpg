#include "Item.h"

Item::Item(EItemID itemID, string name, int price) : itemID(itemID), name(name), price(price)
{
}

// 아이템 테이블
map<EItemID, Item*> ITEM_TABLE = {
	{EItemID::SLIME_JELLY, new Item(EItemID::SLIME_JELLY, "슬라임의 끈적한 젤리", 15)},
	{EItemID::GOBLIN_BLOOD, new Item(EItemID::GOBLIN_BLOOD, "고블린의 오염된 피", 15)},
	{EItemID::SKELETON_BONE, new Item(EItemID::SKELETON_BONE, "스켈레톤의 부서진 뼈", 15)},
	{EItemID::WATER, new Item(EItemID::WATER, "물", 5)},
	{EItemID::HEALING_HERB, new Item(EItemID::HEALING_HERB, "치료 허브", 25)},
	{EItemID::MANA_DUST, new Item(EItemID::MANA_DUST, "마나 가루", 20)},
};