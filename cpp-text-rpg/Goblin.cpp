#include "Goblin.h"

Goblin::Goblin(string name, int hp, int power, int defence) : Monster(name, hp, power, defence)
{
	setMonsterType(EMosnterType::Goblin);
	setDropItem(new Item("고블린의 오염된 피", 15));
}