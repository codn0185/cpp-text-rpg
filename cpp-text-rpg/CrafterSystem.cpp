#include "CrafterSystem.h"

using namespace std;

bool CrafterSystem::CraftItem(EItemID itemID, Inventory* inventory)
{
	const auto& item = ITEM_TABLE.at(itemID).get();

	// 제작 불가
	if (!item->isCraftable)
	{
		return false;
	}

	// 재료 부족
	for (const auto& [requiredItemID, requiredCount] : item->ingredients)
	{
		if (inventory->getItemCount(requiredItemID) < requiredCount)
		{
			return false;
		}
	}

	// 제작
	for (const auto& [requiredItemID, requiredCount] : item->ingredients)
	{
		inventory->removeItem(requiredItemID, requiredCount);
	}
	inventory->addItem(itemID);

	return true;
}
