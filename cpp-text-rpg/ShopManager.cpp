#include "ShopManager.h"

#include "ShopSystem.h"
#include "InputSystem.h"
#include "InventorySystem.h"

#include <iostream>

using namespace std;

ShopManager::ShopManager(Player* player, Inventory* backpackInventory, Inventory* stockInventory)
	: currentShopState(EShopState::SHOP_ENTER), isRunning(true), player(player), backpackInventory(backpackInventory), stockInventory(stockInventory)
{
}

void ShopManager::run()
{
	while (isRunning)
	{
		update();
	}
}

void ShopManager::update()
{
	switch (currentShopState)
	{
	case EShopState::SHOP_ENTER:
		onShopEnter();
		break;
	case EShopState::SHOP_PURCHASE:
		onShopPurchase();
		break;
	case EShopState::SHOP_SALE:
		onShopSale();
		break;
	case EShopState::SHOP_EXIT:
		onShopExit();
		break;
	default:
		break;
	}
}

void ShopManager::switchShopState(EShopState newState)
{
	currentShopState = newState;
}

void ShopManager::onShopEnter()
{
	cout << "=============== < 상점 > ===============" << "\n";
	cout << "1. 구매" << "\n";
	cout << "2. 판매" << "\n";
	cout << "3. 인벤토리" << "\n";
	cout << "0. 메인 메뉴" << "\n";
	cout << "========================================" << "\n";

	int option = InputSystem::InputIntUnitlValid(0, 3, "선택: ", "* 잘못된 입력입니다.\n");
	switch (option)
	{
	case 0:
		switchShopState(EShopState::SHOP_EXIT);
		break;
	case 1:
		switchShopState(EShopState::SHOP_PURCHASE);
		break;
	case 2:
		switchShopState(EShopState::SHOP_SALE);
		break;
	case 3:
		InventorySystem::DisplayInventory(backpackInventory, "창고");
		InventorySystem::DisplayInventory(stockInventory, "배낭");
		break;
	default:
		break;
	}
}

void ShopManager::onShopPurchase()
{
	vector<EItemID> itemIDs;
	for (const auto& [itemID, shopDataRow] : SHOP_TABLE)
	{
		itemIDs.push_back(itemID);
	}

	cout << "=============== < 구매 상점 > ===============" << "\n";
	for (int i = 0; i < itemIDs.size(); i++)
	{
		EItemID itemID = itemIDs[i];
		string itemName = ITEM_TABLE.at(itemID)->name;
		int purchasePrice = SHOP_TABLE.at(itemID).purchasePrice;
		cout << i + 1 << ". " << itemName << " ── (" << purchasePrice << "g)" << "\n";
	}
	cout << "============================================" << "\n";

	// 구매할 아이템 선택
	int itemNum = InputSystem::InputIntUnitlValid(0, itemIDs.size(), "아이템 구매 (0: 뒤로가기): ", "* 잘못된 입력입니다.\n");
	if (itemNum == 0) // 뒤로가기
	{
		switchShopState(EShopState::SHOP_ENTER);
		return;
	}

	// 구매할 개수 선택
	const EItemID purchaseItemID = itemIDs[itemNum - 1]; // 구매할 아이템 ID
	const string purchaseItemName = ITEM_TABLE.at(purchaseItemID)->name; // 구매할 아이템 이름
	int purchaseCount = InputSystem::InputIntUnitlValid(0, INT_MAX, "구매 개수: ", "* 잘못된 입력입니다.\n"); // 구매할 아이템 개수
	if (purchaseCount == 0) // 0개 구매 - 구매 목록 다시 보여주기
	{
		return;
	}

	// 구매 시도 - 이후 구매 목록 다시 보여주기
	bool success = ShopSystem::PruchaseItem(player, backpackInventory, purchaseItemID, purchaseCount);
	if (!success) // 구매 실패
	{
		cout << " > \"" << purchaseItemName << "\" " << purchaseCount << "개 구매에 실패하였습니다." << "\n";
	}
	else // 구매 성공
	{
		cout << " > \"" << purchaseItemName << "\" " << purchaseCount << "개 구매 성공!" << "\n";
	}
}

void ShopManager::onShopSale()
{
}

void ShopManager::onShopExit()
{
	isRunning = false;
}
