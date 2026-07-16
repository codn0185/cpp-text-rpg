#include "CrafterSystem.h"

using namespace std;

bool CrafterSystem::CraftItem(EItemID itemID, Inventory* inventory)
{
	// 캐스팅
	const Potion* potion = static_cast<const Potion*>(ITEM_TABLE.at(itemID).get());
	if (potion == nullptr)
	{
		return false;
	}

	// 재료 부족
	for (const auto& [requiredItemID, requiredCount] : potion->ingredients)
	{
		if (inventory->getItemCount(requiredItemID) < requiredCount)
		{
			return false;
		}
	}

	// 제작
	for (const auto& [requiredItemID, requiredCount] : potion->ingredients)
	{
		inventory->removeItem(requiredItemID, requiredCount);
	}
	inventory->addItem(itemID);

	return true;
}
