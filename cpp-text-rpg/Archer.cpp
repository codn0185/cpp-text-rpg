#include "Archer.h"

#include <iostream>

Archer::Archer(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::Archer);
}

void Archer::showAttackMessage() const
{
	cout << "화살 쏘기!" << "\n";
}