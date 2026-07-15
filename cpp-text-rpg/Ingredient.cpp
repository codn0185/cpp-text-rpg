#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient(EItemID itemID, string name, string description, int price)
	: Item(itemID, EItemType::INGREDIENT, name, description, price)
{
}
