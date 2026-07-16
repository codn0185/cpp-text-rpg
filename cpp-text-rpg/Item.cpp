#include "Item.h"

#include "Potion.h"
#include "Ingredient.h"

using namespace std;

const map<EItemID, shared_ptr<Item>> ITEM_TABLE = {
	// 포션
	{EItemID::HP_POTION_20, make_shared<Item>(Potion(EItemID::HP_POTION_20, EPotionType::HP_POTION, "HP 포션 (소형)", "HP를 20만큼 회복한다.", 30, 20, {{EItemID::WATER, 1}, {EItemID::HEALING_HERB, 2}}))},
	{EItemID::MP_POTION_20, make_shared<Item>(Potion(EItemID::MP_POTION_20, EPotionType::MP_POTION, "MP 포션 (소형)", "MP를 20만큼 회복한다.", 30, 20, {{EItemID::WATER, 1}, {EItemID::MANA_DUST, 2}}))},
	// 재료
	{EItemID::BOTTLE, make_shared<Item>(Ingredient(EItemID::BOTTLE, "공병", "", 3))},
	{EItemID::WATER, make_shared<Item>(Ingredient(EItemID::WATER, "물", "", 5))},
	{EItemID::HEALING_HERB, make_shared<Item>(Ingredient(EItemID::HEALING_HERB, "치료 허브", "", 25))},
	{EItemID::MANA_DUST, make_shared<Item>(Ingredient(EItemID::MANA_DUST, "마나 가루", "", 20))},
	// 기타
	{EItemID::SLIME_JELLY, make_shared<Item>(Ingredient(EItemID::SLIME_JELLY, "슬라임의 끈적한 젤리", "", 15))},
	{EItemID::GOBLIN_BLOOD, make_shared<Item>(Ingredient(EItemID::GOBLIN_BLOOD, "고블린의 오염된 피", "", 15))},
	{EItemID::SKELETON_BONE, make_shared<Item>(Ingredient(EItemID::SKELETON_BONE, "스켈레톤의 부서진 뼈", "", 15))},
};

Item::Item(EItemID itemID, EItemType itemType, string name, string description, int price)
	: itemID(itemID), itemType(itemType), name(name), description(description), price(price)
{
}
