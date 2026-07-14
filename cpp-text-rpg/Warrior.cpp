#include "Warrior.h"

#include "UISystem.h"

#include <iostream>

Warrior::Warrior(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::Warrior);
}

void Warrior::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}

void Warrior::showAttackMessage() const
{
	cout << "대검 휘두르기!" << "\n";
}

void Warrior::applyBonusStat()
{
	setDefence(getDefence() + 30);
}

void Warrior::removeBonusStat()
{
	setDefence(getDefence() - 30);
}
