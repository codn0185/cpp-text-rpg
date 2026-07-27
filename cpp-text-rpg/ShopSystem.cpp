#include "ShopSystem.h"

using namespace std;

ShopDataRow::ShopDataRow(EItemID itemID, int salePrice, int purchasePrice)
	: itemID(itemID), salePrice(salePrice), purchasePrice(purchasePrice)
{
}

const unordered_map<EItemID, ShopDataRow> SHOP_TABLE =
{
	{EItemID::HP_POTION_20, ShopDataRow(EItemID::HP_POTION_20, 100, 200)},
	{EItemID::MP_POTION_20, ShopDataRow(EItemID::MP_POTION_20, 100, 200)},

	{EItemID::BOTTLE, ShopDataRow(EItemID::BOTTLE, 5, 10)},
	{EItemID::WATER, ShopDataRow(EItemID::WATER, 10, 20)},
	{EItemID::HEALING_HERB, ShopDataRow(EItemID::HEALING_HERB, 25, 50)},
	{EItemID::MANA_DUST, ShopDataRow(EItemID::MANA_DUST, 25, 50)},

	{EItemID::SLIME_JELLY, ShopDataRow(EItemID::SLIME_JELLY, 15, 30)},
	{EItemID::GOBLIN_DAGGER, ShopDataRow(EItemID::GOBLIN_DAGGER, 15, 30)},
	{EItemID::SKELETON_BONE, ShopDataRow(EItemID::SKELETON_BONE, 15, 30)},
};

bool ShopSystem::PruchaseItem(Player* player, Inventory* inventory, EItemID itemID, int count)
{
	int currentGold = player->getGold();
	int purchasePrice = SHOP_TABLE.at(itemID).purchasePrice * count;

	// 골드 부족으로 구매 실패
	if (currentGold < purchasePrice)
	{
		return false;
	}

	// 아이템 구매 - 골드 소모 및 인벤토리에 아이템 추가
	player->setGold(currentGold - purchasePrice);
	inventory->addItem(itemID, count);
	return true;
}

bool ShopSystem::SaleItem(Player* player, Inventory* inventory, EItemID itemID, int count)
{
	int currentGold = player->getGold();
	int salePrice = SHOP_TABLE.at(itemID).salePrice * count;

	// 아이템 부족으로 판매 실패
	if (!inventory->hasItem(itemID, count))
	{
		return false;
	}

	// 아이템 판매 - 골드 추가 및 인벤토리에서 아이템 제거
	player->setGold(currentGold + salePrice);
	inventory->removeItem(itemID, count);
	return true;
}
