#include "Potion.h"

const map<EPotionID, Potion> POTION_TABLE = {
	{EPotionID::HP_POTION_20, Potion(EPotionID::HP_POTION_20, EPotionType::HP_POTION, "HP 포션 (소형)", "HP를 20만큼 회복한다.", 30, 20, {{EIngredientID::WATER, 1}, {EIngredientID::HEALING_HERB, 2}})},
	{EPotionID::MP_POTION_20, Potion(EPotionID::MP_POTION_20, EPotionType::MP_POTION, "MP 포션 (소형)", "MP를 20만큼 회복한다.", 30, 20, {{EIngredientID::WATER, 1}, {EIngredientID::MANA_DUST, 2}})},
};

Potion::Potion(EPotionID potionID, EPotionType potionType, string name, string description, int price, int amount, vector<pair<EIngredientID, int>> ingredients)
	: Item(EItemType::POTION, name, description, price), potionID(potionID), potionType(potionType), amount(amount), ingredients(ingredients)
{
}

bool Potion::canUse()
{
	return true;
}
