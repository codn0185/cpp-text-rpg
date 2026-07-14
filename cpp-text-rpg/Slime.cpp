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

EIngredientID Slime::getDropItemID()
{
	vector<EIngredientID> itemIDs = {EIngredientID::SLIME_JELLY, EIngredientID::WATER};
	return RandomSystem::getRandom<EIngredientID>(itemIDs, {2, 3});
}