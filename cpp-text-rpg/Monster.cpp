#include "Monster.h"

Item Monster::getDropItem()
{
	return dropItem;
}

void Monster::setDropItem(Item dropItem)
{
	this->dropItem = dropItem;
}
