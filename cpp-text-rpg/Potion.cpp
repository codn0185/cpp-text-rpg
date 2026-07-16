#include "Potion.h"

using namespace std;

Potion::Potion(EItemID potionID, EPotionType potionType, string name, string description, int price, int amount, map<EItemID, int> ingredients)
	: Item(potionID, EItemType::POTION, name, description, price), potionType(potionType), amount(amount), ingredients(ingredients)
{
}
