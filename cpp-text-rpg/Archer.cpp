#include "Archer.h"

#include <iostream>

Archer::Archer(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence), attackCount(3)
{
	setJob(EPlayerJob::Archer);
}

void Archer::attack(Character* target)
{
	for (int i = 0; i < attackCount; i++)
	{
		int damage = power - target->getDefence();
		if (damage <= 0)
		{
			damage = 1;
		}
		target->takeDamage(damage);
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
