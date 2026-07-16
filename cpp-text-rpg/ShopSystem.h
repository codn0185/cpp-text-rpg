#pragma once

#include "Player.h"
#include "Inventory.h"
#include "Item.h"

#include <unordered_map>

struct ShopDataRow
{
	EItemID itemID;
	int salePrice; // 판매 가격
	int purchasePrice; // 구매 가격

	ShopDataRow(EItemID itemID, int salePrice, int purchasePrice);
};

extern const std::unordered_map<EItemID, ShopDataRow> SHOP_TABLE;

class ShopSystem
{
public:
	static bool PruchaseItem(Player* player, Inventory* inventory, EItemID itemID, int count = 1); // 아이템 구매 (구매 성공 시 인벤토리 반영 및 true 반환, 구매 실패 시 false 반환)
	static bool SaleItem(Player* player, Inventory* inventory, EItemID itemID, int count = 1); // 아이템 판매 (판매 성공 시 인벤토리 반영 및 true 반환, 판매 실패 시 false 반환)
};

