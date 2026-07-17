#include "Item.h"

#include "Potion.h"
#include "Ingredient.h"

using namespace std;

const map<EItemID, shared_ptr<Item>> ITEM_TABLE = {
	// 포션
	{EItemID::HP_POTION_20, make_shared<Item>(Item(EItemID::HP_POTION_20, EItemType::POTION, "HP 포션 (소형)", "HP를 20만큼 회복한다.", true, {{EItemID::BOTTLE, 1}, {EItemID::WATER, 2}, {EItemID::HEALING_HERB, 3}}))},
	{EItemID::MP_POTION_20, make_shared<Item>(Item(EItemID::MP_POTION_20, EItemType::POTION, "MP 포션 (소형)", "MP를 20만큼 회복한다.", true, {{EItemID::BOTTLE, 1}, {EItemID::WATER, 2}, {EItemID::MANA_DUST, 3}}))},

	// 재료
	{EItemID::BOTTLE, make_shared<Item>(Item(EItemID::BOTTLE, EItemType::INGREDIENT, "공병", ""))},
	{EItemID::WATER, make_shared<Item>(Item(EItemID::WATER, EItemType::INGREDIENT, "물", ""))},
	{EItemID::HEALING_HERB, make_shared<Item>(Item(EItemID::HEALING_HERB, EItemType::INGREDIENT, "치료 허브", ""))},
	{EItemID::MANA_DUST, make_shared<Item>(Item(EItemID::MANA_DUST, EItemType::INGREDIENT, "마나 가루", ""))},
	// 기타
	{EItemID::SLIME_JELLY, make_shared<Item>(Item(EItemID::SLIME_JELLY, EItemType::MISC, "슬라임의 끈적한 젤리", ""))},
	{EItemID::GOBLIN_BLOOD, make_shared<Item>(Item(EItemID::GOBLIN_BLOOD, EItemType::MISC, "고블린의 오염된 피", ""))},
	{EItemID::SKELETON_BONE, make_shared<Item>(Item(EItemID::SKELETON_BONE, EItemType::MISC, "스켈레톤의 부서진 뼈", ""))},

};

Item::Item(EItemID itemID, EItemType itemType, string name, string description, bool isCraftable, map<EItemID, int> ingredients)
	: itemID(itemID), itemType(itemType), name(name), description(description), isCraftable(isCraftable), ingredients(ingredients)
{
}
