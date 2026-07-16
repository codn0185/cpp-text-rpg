#include "ShopManager.h"

ShopDataRow::ShopDataRow(EItemID itemID, int salePrice, int purchasePrice)
	: itemID(itemID), salePrice(salePrice), purchasePrice(purchasePrice)
{
}

const std::unordered_map<EItemID, ShopDataRow> SHOP_TABLE =
{
	{EItemID::HP_POTION_20, ShopDataRow(EItemID::HP_POTION_20, 100, 200)},
	{EItemID::MP_POTION_20, ShopDataRow(EItemID::MP_POTION_20, 100, 200)},

	{EItemID::BOTTLE, ShopDataRow(EItemID::BOTTLE, 5, 10)},
	{EItemID::WATER, ShopDataRow(EItemID::WATER, 10, 20)},
	{EItemID::HEALING_HERB, ShopDataRow(EItemID::HEALING_HERB, 25, 50)},
	{EItemID::MANA_DUST, ShopDataRow(EItemID::MANA_DUST, 25, 50)},

	{EItemID::SLIME_JELLY, ShopDataRow(EItemID::SLIME_JELLY, 15, 30)},
	{EItemID::GOBLIN_BLOOD, ShopDataRow(EItemID::GOBLIN_BLOOD, 15, 30)},
	{EItemID::SKELETON_BONE, ShopDataRow(EItemID::SKELETON_BONE, 15, 30)},
};
