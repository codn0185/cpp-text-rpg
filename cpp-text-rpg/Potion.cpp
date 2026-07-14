#include "Potion.h"

Potion::Potion(EItemID potionID, EPotionType potionType, string name, string description, int price, int amount, vector<pair<EItemID, int>> ingredients)
	: Item(potionID, EItemType::POTION, name, description, price), potionType(potionType), amount(amount), ingredients(ingredients)
{
}
