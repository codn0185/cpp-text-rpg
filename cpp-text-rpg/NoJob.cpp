#include "NoJob.h"

#include <iostream>

NoJob::NoJob(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::None);
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
