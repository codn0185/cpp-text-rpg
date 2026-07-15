#include "Mage.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

Mage::Mage(string name, int hp, int mp, int power, int defence) : Player(name, hp, mp, power, defence)
{
	setJob(EPlayerJob::Mage);
}

void Mage::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
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
