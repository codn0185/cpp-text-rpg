#include "Skeleton.h"

Skeleton::Skeleton(string name, int hp, int power, int defence) : Monster(name, hp, power, defence)
{
	setMonsterType(EMosnterType::Skeleton);
	setDropItem(new Item("스켈레톤의 고운 뼛가루", 12));
}