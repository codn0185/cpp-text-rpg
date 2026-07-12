#include "Rogue.h"

#include <iostream>

Rogue::Rogue(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::Rogue);
}

void Rogue::showAttackMessage() const
{
	cout << "단검 찌르기!" << "\n";
}