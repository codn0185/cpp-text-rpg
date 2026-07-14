#include "Item.h"

Item::Item(EItemType itemType, string name, string description, int price)
	: itemType(itemType), name(name), description(description), price(price)
{
}
