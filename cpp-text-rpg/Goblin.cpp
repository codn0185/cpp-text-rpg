#include "Goblin.h"

Goblin::Goblin() : Monster(EMosnterType::Goblin)
{
}

EItemID Goblin::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::GOBLIN_BLOOD, EItemID::HEALING_HERB};
	return RandomSystem::getRandom(itemIDs, {3, 2});
}