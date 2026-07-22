#include "Goblin.h"

#include "UISystem.h"

Goblin::Goblin() : Monster(EMonsterType::Goblin)
{
}

void Goblin::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}
