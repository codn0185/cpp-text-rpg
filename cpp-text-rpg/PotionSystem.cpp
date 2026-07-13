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
	player->increaseMaxHP(hpPotionIncreasedAmount, true);

	return true;
}

bool PotionSystem::useMPPotion(Player* player)
{
	if (mpPotionCount == 0)
	{
		return false;
	}

	mpPotionCount--;
	player->increaseMaxMP(mpPotionIncreasedAmount, true);

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
