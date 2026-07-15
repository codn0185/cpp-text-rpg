#include "Skeleton.h"

#include "UISystem.h"

Skeleton::Skeleton() : Monster(EMosnterType::Skeleton)
{
}

void Skeleton::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}
