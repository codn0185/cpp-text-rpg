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
	vector<EItemID> itemIDs;
	for (const auto& [itemID, shopDataRow] : SHOP_TABLE)
	{
		itemIDs.push_back(itemID);
	}

	cout << "=============== < 판매 상점 > ===============" << "\n";
	for (int i = 0; i < itemIDs.size(); i++)
	{
		EItemID itemID = itemIDs[i];
		string itemName = ITEM_TABLE.at(itemID)->name;
		int salePrice = SHOP_TABLE.at(itemID).salePrice;
		int stockCount = backpackInventory->getItemCount(itemID);
		cout << i + 1 << ". " << itemName << " ── (" << salePrice << "g) [재고: " << stockCount << "개]" << "\n";
	}
	cout << "============================================" << "\n";

	// 판매할 아이템 선택
	int itemNum = InputSystem::InputIntUnitlValid(0, itemIDs.size(), "아이템 판매 (0: 뒤로가기): ", "* 잘못된 입력입니다.\n");
	if (itemNum == 0) // 뒤로가기
	{
		switchShopState(EShopState::SHOP_ENTER);
		return;
	}

	// 판매할 개수 선택
	const EItemID saleItemID = itemIDs[itemNum - 1]; // 판매할 아이템 ID
	const string saleItemName = ITEM_TABLE.at(saleItemID)->name; // 판매할 아이템 이름
	const int stockItemCount = backpackInventory->getItemCount(saleItemID); // 아이템 재고 개수
	if (stockItemCount == 0) // 재고 없음
	{
		cout << " > \"" << saleItemName << "\"의 재고가 부족합니다!" << "\n";
		return;
	}
	int saleCount = InputSystem::InputIntUnitlValid(0, INT_MAX, "판매 개수: ", "* 잘못된 입력입니다.\n"); // 구매할 아이템 개수
	if (saleCount == 0) // 0개 판매 - 판매 목록 다시 보여주기
	{
		return;
	}

	// 판매 시도 - 이후 판매 목록 다시 보여주기
	bool success = ShopSystem::PruchaseItem(player, backpackInventory, saleItemID, saleCount);
	if (!success) // 판매 실패
	{
		cout << " > \"" << saleItemName << "\" " << saleCount << "개 판매에 실패하였습니다." << "\n";
	}
	else // 판매 성공
	{
		cout << " > \"" << saleItemName << "\" " << saleCount << "개 판매 성공!" << "\n";
	}
}

void ShopManager::onShopExit()
{
	isRunning = false;
}
