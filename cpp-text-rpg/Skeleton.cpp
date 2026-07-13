#include "Skeleton.h"

Skeleton::Skeleton(string name, int hp, int power, int defence) : Monster(name, hp, power, defence)
{
	setMonsterType(EMosnterType::Skeleton);
}

EItemID Skeleton::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::SKELETON_BONE, EItemID::MANA_DUST};
	return RandomSystem::getRandom(itemIDs, {3, 2});
}