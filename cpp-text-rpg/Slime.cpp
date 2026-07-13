#include "Slime.h"

Slime::Slime(string name, int hp, int power, int defence) : Monster(name, hp, power, defence)
{
	setMonsterType(EMosnterType::Slime);
}

EItemID Slime::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::SLIME_JELLY, EItemID::WATER};
	return RandomSystem::getRandom(itemIDs, {2, 3});
}