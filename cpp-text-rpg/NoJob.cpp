#include "NoJob.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

NoJob::NoJob(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::None);
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
