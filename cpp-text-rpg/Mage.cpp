#include "Mage.h"

#include <iostream>

Mage::Mage(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::Mage);
}

void Mage::showAttackMessage() const
{
	cout << "화염구 발사!" << "\n";
}

void Mage::applyBonusStat()
{
	setCurrentMP(getCurrentMP() + 30);
	setMaxMP(getMaxMP() + 30);
}

void Mage::removeBonusStat()
{
	setCurrentMP(getCurrentMP() - 30);
	setMaxMP(getMaxMP() - 30);
}
