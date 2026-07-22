#include "Slime.h"

#include "UISystem.h"

Slime::Slime() : Monster(EMonsterType::Slime)
{
}

void Slime::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}
