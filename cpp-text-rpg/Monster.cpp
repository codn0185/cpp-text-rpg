#include "Monster.h"

Monster::Monster(string name, int hp, int power, int defence)
{
	setName(name);
	setMaxHP(hp);
	setPower(power);
	setDefence(defence);

	reset();
}

EMosnterType Monster::getMonsterType()
{
	return monsterType;
}

void Monster::setMonsterType(EMosnterType monsterType)
{
	this->monsterType = monsterType;
}
