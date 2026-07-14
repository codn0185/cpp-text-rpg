#include "Rogue.h"

#include "UISystem.h"

#include <iostream>

Rogue::Rogue(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence), attackCount(5)
{
	setJob(EPlayerJob::Rogue);
}

void Rogue::attack(Character* target)
{
	for (int i = 0; i < attackCount; i++)
	{
		int damage = power / attackCount - target->getDefence();
		if (damage <= 0)
		{
			damage = 1;
		}
		target->takeDamage(damage);
		UISystem::PrintBattleLog(this, target, damage);
		if (target->isDead())
		{
			return;
		}
	}
}

void Rogue::showAttackMessage() const
{
	cout << "단검 찌르기!" << "\n";
}

void Rogue::applyBonusStat()
{
	setPower(getPower() + 30);
}

void Rogue::removeBonusStat()
{
	setPower(getPower() - 30);
}
