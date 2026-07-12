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
