#include "Skeleton.h"

Skeleton::Skeleton() : Monster(EMosnterType::Skeleton)
{
}

EItemID Skeleton::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::SKELETON_BONE, EItemID::MANA_DUST};
	return RandomSystem::getRandom(itemIDs, {3, 2});
}