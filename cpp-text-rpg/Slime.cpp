#include "Slime.h"

Slime::Slime(string name, int hp, int power, int defence) : Monster(name, hp, power, defence)
{
	setMonsterType(EMosnterType::Slime);
	setDropItem(new Item("슬라임의 끈적한 젤리", 10));
}
