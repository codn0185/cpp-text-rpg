#include "Warrior.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

Warrior::Warrior(std::string name, int maxHP, int maxMP, int power, int defence, int level, int exp, int gold)
	: Player(name, maxHP, maxMP, power, defence, level, exp, gold, EPlayerJob::Warrior)
{
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
