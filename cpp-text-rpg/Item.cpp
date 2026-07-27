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
	{EItemID::GOBLIN_DAGGER, make_shared<Item>(Item(EItemID::GOBLIN_DAGGER, EItemType::MISC, "고블린의 조잡한 단검", ""))},
	{EItemID::BAT_FANG, make_shared<Item>(Item(EItemID::BAT_FANG, EItemType::MISC, "박쥐의 날카로운 이빨", ""))},

	{EItemID::ZOMBIE_LEATHER, make_shared<Item>(Item(EItemID::ZOMBIE_LEATHER, EItemType::MISC, "좀비의 부패한 가죽", ""))},
	{EItemID::SKELETON_BONE, make_shared<Item>(Item(EItemID::SKELETON_BONE, EItemType::MISC, "스켈레톤의 단단한 뼛조각", ""))},
	{EItemID::GHOST_ESSENCE, make_shared<Item>(Item(EItemID::GHOST_ESSENCE, EItemType::MISC, "고스트의 원혼 정수", ""))},

	{EItemID::ORK_TENDON, make_shared<Item>(Item(EItemID::ORK_TENDON, EItemType::MISC, "오크의 질긴 힘줄", ""))},
	{EItemID::LIZARDMAN_SCALE, make_shared<Item>(Item(EItemID::LIZARDMAN_SCALE, EItemType::MISC, "리자드맨의 붉은 비늘", ""))},
	{EItemID::GARGOYLE_SHARD, make_shared<Item>(Item(EItemID::GARGOYLE_SHARD, EItemType::MISC, "가고일의 석상 파편", ""))},

	{EItemID::DRAGON_CORE, make_shared<Item>(Item(EItemID::DRAGON_CORE, EItemType::MISC, "드래곤 코어", ""))},

};

Item::Item(EItemID itemID, EItemType itemType, string name, string description, bool isCraftable, map<EItemID, int> ingredients)
	: itemID(itemID), itemType(itemType), name(name), description(description), isCraftable(isCraftable), ingredients(ingredients)
{
}
