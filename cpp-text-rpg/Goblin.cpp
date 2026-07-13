#include "Goblin.h"

Goblin::Goblin(string name, int hp, int power, int defence) : Monster(name, hp, power, defence)
{
	setMonsterType(EMosnterType::Goblin);
}

EItemID Goblin::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::GOBLIN_BLOOD, EItemID::HEALING_HERB};
	return RandomSystem::getRandom(itemIDs, {3, 2});
}