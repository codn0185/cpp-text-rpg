#pragma once

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

enum class EShopState
{
	SHOP_INIT, // 상점 진입 - 선택에 따라 다음 상태 이동


};

class ShopManager
{
};

