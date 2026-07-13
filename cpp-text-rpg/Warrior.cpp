#include "Warrior.h"

#include <iostream>

Warrior::Warrior(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::Warrior);
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
