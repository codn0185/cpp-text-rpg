#include "NoJob.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

NoJob::NoJob(std::string name, int maxHP, int maxMP, int power, int defence, int level, int exp, int gold)
	: Player(name, maxHP, maxMP, power, defence, level, exp, gold, EPlayerJob::None)
{
}

void NoJob::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}

void NoJob::showAttackMessage() const
{
	cout << "펀치 날리기!" << "\n";
}

void NoJob::applyBonusStat()
{
}

void NoJob::removeBonusStat()
{
}
