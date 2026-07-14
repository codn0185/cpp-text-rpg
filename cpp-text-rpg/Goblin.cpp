#include "Goblin.h"

#include "UISystem.h"

Goblin::Goblin() : Monster(EMosnterType::Goblin)
{
}

void Goblin::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}

EItemID Goblin::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::GOBLIN_BLOOD, EItemID::HEALING_HERB};
	return RandomSystem::getRandom(itemIDs, {3, 2});
}