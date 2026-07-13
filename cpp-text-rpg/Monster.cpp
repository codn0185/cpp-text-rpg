#include "Monster.h"

Monster::Monster(string name, int hp, int power, int defence)
{
	setName(name);
	setHP(hp);
	setPower(power);
	setDefence(defence);
}

Item* Monster::getDropItem()
{
	return dropItem;
}

EMosnterType Monster::getMonsterType()
{
	return monsterType;
}

void Monster::setDropItem(Item* dropItem)
{
	this->dropItem = dropItem;
}

void Monster::setMonsterType(EMosnterType monsterType)
{
	this->monsterType = monsterType;
}
