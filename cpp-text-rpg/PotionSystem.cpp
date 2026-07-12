#include "PotionSystem.h"

PotionSystem::PotionSystem() : hpPotionCount(5), hpPotionIncreasedAmount(20), mpPotionCount(5), mpPotionIncreasedAmount(20)
{
}

bool PotionSystem::useHPPotion(Player* player)
{
	if (hpPotionCount == 0)
	{
		return false;
	}

	hpPotionCount--;
	int currentHP = player->getHP();
	player->setHP(currentHP + hpPotionIncreasedAmount);

	return true;
}

bool PotionSystem::useMPPotion(Player* player)
{
	if (mpPotionCount == 0)
	{
		return false;
	}

	mpPotionCount--;
	int currentMP = player->getMP();
	player->setMP(currentMP + mpPotionIncreasedAmount);

	return true;
}

int PotionSystem::getHPPotionCount()
{
	return hpPotionCount;
}

int PotionSystem::getMPPotionCount()
{
	return mpPotionCount;
}

void PotionSystem::setHPPotionCount(int hpPotionCount)
{
	this->hpPotionCount = hpPotionCount;
}

void PotionSystem::setMPPotionCount(int mpPotionCount)
{
	this->mpPotionCount = mpPotionCount;
}
