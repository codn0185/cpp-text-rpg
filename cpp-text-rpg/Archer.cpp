#include "Archer.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

Archer::Archer(std::string name, int maxHP, int maxMP, int power, int defence, int level, int exp, int gold)
	: Player(name, maxHP, maxMP, power, defence, level, exp, gold, EPlayerJob::Archer)
{
}

void Archer::attack(Character* target)
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

void Archer::showAttackMessage() const
{
	cout << "화살 쏘기!" << "\n";
}

void Archer::applyBonusStat()
{
	setCurrentHP(getCurrentHP() + 30);
	setMaxHP(getMaxHP() + 30);
}

void Archer::removeBonusStat()
{
	setCurrentHP(getCurrentHP() - 30);
	setMaxMP(getMaxMP() - 30);
}
