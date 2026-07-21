#include "Rogue.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

Rogue::Rogue(std::string name, int maxHP, int maxMP, int power, int defence, int level, int exp, int gold)
	: Player(name, maxHP, maxMP, power, defence, level, exp, gold, EPlayerJob::Rogue)
{
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
