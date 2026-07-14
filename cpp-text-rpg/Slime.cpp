#include "Slime.h"

#include "UISystem.h"

Slime::Slime() : Monster(EMosnterType::Slime)
{
}

void Slime::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}

EItemID Slime::getDropItemID()
{
	vector<EItemID> itemIDs = {EItemID::SLIME_JELLY, EItemID::WATER};
	return RandomSystem::getRandom(itemIDs, {2, 3});
}