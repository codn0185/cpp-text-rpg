#include "Slime.h"

Slime::Slime() : Monster(EMosnterType::Slime)
{
}

EItemID Slime::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::SLIME_JELLY, EItemID::WATER};
	return RandomSystem::getRandom(itemIDs, {2, 3});
}