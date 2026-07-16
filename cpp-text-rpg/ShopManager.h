#pragma once

#include "Item.h"
#include "Player.h"
#include "Inventory.h"

#include <unordered_map>

enum class EShopState
{
	SHOP_ENTER, // 상점 진입 - 선택에 따라 다음 상태 이동
	SHOP_PURCHASE, // 구매 상점 - 아이템 구매
	SHOP_SALE, // 판매 상점 - 아이템 판매
	SHOP_EXIT, // 상점 나가기 - 현재 상태 머신 종료
};

class ShopManager
{
private:
	EShopState currentShopState;
	bool isRunning;

	Player* player;
	Inventory* backpackInventory;
	Inventory* stockInventory;

public:
	ShopManager(Player* player, Inventory* backpackInventory, Inventory* stockInventory);

	void run();
	void update();
	void switchShopState(EShopState newState);

	void onShopEnter();
	void onShopPurchase();
	void onShopSale();
	void onShopExit();
};

