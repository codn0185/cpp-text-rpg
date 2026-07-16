#include "GameManager.h"

#include <iostream>

using namespace std;

GameManager::GameManager() :isRunning(true)
{
	spawnManager = new SpawnManager();
	combatManager = new CombatManager();

	backpackInventory = new Inventory(10, 5); // 배낭
	stockInventory = new Inventory(30, 20); // 창고
}

GameManager::~GameManager()
{
	delete player;

	delete spawnManager;
	delete combatManager;

	delete backpackInventory;
	delete stockInventory;
}

void GameManager::run()
{
	while (isRunning)
	{
		update();
	}
}

void GameManager::update()
{
	switch (currentGameState)
	{
	case EGameState::GAME_START:
		onGameStart();
		break;
	case EGameState::PLAYER_REGISTRATION:
		onPlayerResitration();
		break;
	case EGameState::MAIN_MENU:
		onMainMenu();
		break;
	case EGameState::DUNGEON_ENTER:
		onDungeonEnter();
		break;
	case EGameState::DUNGEON_COMBAT:
		onDungeonCombat();
		break;
	case EGameState::INVENTORY_OPEN:
		onInventoryOpen();
		break;
	case EGameState::POTION_SHOP_ENTER:
		onPotionShopEnter();
		break;
	case EGameState::GAME_EXIT:
		onGameExit();
		break;
	default:
		break;
	}
}

void GameManager::switchGameState(EGameState newGameState)
{
	currentGameState = newGameState;
}

void GameManager::onGameStart()
{
	std::cout << "===========================================" << "\n";
	std::cout << "          [ 던전 탈출 텍스트 RPG ]          " << "\n";
	std::cout << "===========================================" << "\n";

	switchGameState(EGameState::PLAYER_REGISTRATION);
}

void GameManager::onPlayerResitration()
{
	// === 플레이어 이름, 스탯 입력 ===

	string name;
	const int SIZE = 4;
	int stat[SIZE] = {0}; // HP, MP, 공격력, 방어력

	// 이름 입력
	std::cout << "용사의 이름을 입력해주세요: ";
	InputSystem::InputString(name);

	// HP, MP 입력
	while (true)
	{
		std::cout << "HP와 MP를 입력해주세요: ";
		if (InputSystem::InputInt(stat[0], 51, INT_MAX) && InputSystem::InputInt(stat[1], 51, INT_MAX))
		{
			break;
		}
		std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
	}

	// 공격력, 방어력 입력
	while (true)
	{
		std::cout << "공격력과 방어력을 입력해주세요: ";
		if (InputSystem::InputInt(stat[2], 51, INT_MAX) && InputSystem::InputInt(stat[3], 51, INT_MAX))
		{
			break;
		}
		std::cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
	}

	// 플레이어 등록
	player = new NoJob(name, stat[0], stat[1], stat[2], stat[3]);
	std::cout << "\n\n";
	UISystem::PrintPlayerStat(player);

	// === 스탯 업그레이드 (w/ 포션) ===
	backpackInventory->addItem(EItemID::HP_POTION_20, 5);
	backpackInventory->addItem(EItemID::MP_POTION_20, 5);
	std::cout << "\n\n";
	std::cout << "HP 포션 " << backpackInventory->getItemCount(EItemID::HP_POTION_20) << "개, MP 포션 " << backpackInventory->getItemCount(EItemID::MP_POTION_20) << "개가 기본 지급되었습니다." << "\n";

	bool isGameStart = false;
	while (!isGameStart)
	{
		// 강화 메뉴 출력
		std::cout << "============================================" << "\n";
		std::cout << "< 캐릭터 강화 >" << "\n";
		std::cout << "1. HP UP    2. MP UP    3. 공격력 2배" << "\n";
		std::cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작" << "\n";
		std::cout << "============================================" << "\n";

		int option = InputSystem::InputIntUnitlValid(0, 5, "번호를 선택해주세요: ", "* 잘못된 입력입니다.\n");
		switch (option)
		{
		case 0:
			std::cout << "게임을 시작합니다!" << "\n";
			isGameStart = true;
			break;
		case 1:
			PotionSystem::UsePotion(player, backpackInventory, EItemID::HP_POTION_20);
			break;
		case 2:
			PotionSystem::UsePotion(player, backpackInventory, EItemID::MP_POTION_20);
			break;
		case 3:
			player->setPower(2 * player->getPower());
			std::cout << "* 공격력이 2배 증가했습니다. (현재 공격력: " << player->getPower() << ")" << "\n";
			break;
		case 4:
			player->setDefence(2 * player->getDefence());
			std::cout << "* 방어력이 2배 증가했습니다. (현재 방어력: " << player->getDefence() << ")" << "\n";
			break;
		case 5:
			std::cout << "\n\n";
			UISystem::PrintPlayerStat(player);
			break;
		}
		std::cout << "\n\n";
	}

	// === 플레이어 직업 선택 ===

	std::cout << "\n\n";
	std::cout << name + "님, 직업을 선택해주세요!" << "\n";
	std::cout << "1. 전사   2. 마법사   3. 도적   4. 궁수" << "\n";

	int jobNumber = InputSystem::InputIntUnitlValid(1, 4, "선택: ", "* 잘못된 입력입니다.\n");
	switch (jobNumber)
	{
	case 1:
		player = Player::ChangeJob(player, EPlayerJob::Warrior);
		std::cout << "* 전사로 전직하였습니다. (방어력 +30)" << "\n";
		break;
	case 2:
		player = Player::ChangeJob(player, EPlayerJob::Mage);
		std::cout << "* 마법사로 전직하였습니다. (MP +30)" << "\n";
		break;
	case 3:
		player = Player::ChangeJob(player, EPlayerJob::Rogue);
		std::cout << "* 도적으로 전직하였습니다. (공격력 +30)" << "\n";
		break;
	case 4:
		player = Player::ChangeJob(player, EPlayerJob::Archer);
		std::cout << "* 궁수로 전직하였습니다. (HP +30)" << "\n";
		break;
	}
	UISystem::PrintPlayerStat(player);
	std::cout << "\n\n";

	switchGameState(EGameState::MAIN_MENU);
}

void GameManager::onMainMenu()
{
	std::cout << "" << "\n";
	std::cout << "=============== < 메인 메뉴 > ===============" << "\n";
	std::cout << "1. 던전 입장" << "\n";
	std::cout << "2. 인벤토리 확인" << "\n";
	std::cout << "3. 포션 제작소" << "\n";
	std::cout << "0. 게임 종료" << "\n";
	std::cout << "============================================" << "\n";

	int option = InputSystem::InputIntUnitlValid(1, 3, "선택: ", "* 잘못된 입력입니다.\n");
	switch (option)
	{
	case 1:
		switchGameState(EGameState::DUNGEON_ENTER);
		break;
	case 2:
		switchGameState(EGameState::INVENTORY_OPEN);
		break;
	case 3:
		switchGameState(EGameState::POTION_SHOP_ENTER);
		break;
	case 0:
		switchGameState(EGameState::GAME_EXIT);
		break;
	default:
		break;
	}
}

void GameManager::onDungeonEnter()
{
	std::cout << "\n\n";
	std::cout << "================= < 던전 > =================" << "\n";
	std::cout << "1. 들어가기" << "\n";
	std::cout << "2. 스탯 확인" << "\n";
	std::cout << "3. 인벤토리 확인" << "\n";
	std::cout << "0. 던전 나가기" << "\n";
	std::cout << "============================================" << "\n";

	int option = InputSystem::InputIntUnitlValid(0, 3, "선택: ", "* 잘못된 입력입니다.\n");
	switch (option)
	{
	case 1:
		switchGameState(EGameState::DUNGEON_COMBAT);
		break;
	case 2:
		UISystem::PrintPlayerStat(player);
		break;
	case 3:
		InventorySystem::DisplayInventory(backpackInventory, "배낭 인벤토리");
		break;
	case 0:
		switchGameState(EGameState::MAIN_MENU);
		break;
	default:
		break;
	}
}

void GameManager::onDungeonCombat()
{
	Monster* monster = spawnManager->getRandomMonsterFromPool();

	combatManager->start(player, backpackInventory, monster);
	while (combatManager->isCombatRunning)
	{
		combatManager->update();
	}

	if (combatManager->getCurrentCombatState() == ECombatState::PlayerVictory) // 전투 승리
	{
		// 보상 확인
		const Reward& reward = RewardSystem::GetReward(monster->getMonsterType());
		int rewardExp = reward.exp;
		int rewardGold = reward.gold;
		EItemID dropItemID = reward.itemID;
		int dropCount = reward.itemCount;
		map<EItemID, int> droppedItems = {{dropItemID, dropCount}}; // TODO 이후 몬스터가 여러 종류의 아이템을 드랍하는 경우 수정

		// 경험치 획득
		std::cout << "\n";
		int prevLevel = player->getLevel();
		int prevExp = player->getExp();
		std::cout << " > +" << rewardExp << " EXP (" << prevExp + rewardExp << "/" << LevelSystem::GetRequiredExp(player) << ")" << "\n";
		LevelSystem::AddExp(player, rewardExp);

		// 골드 획득
		std::cout << "\n";
		cout << " > +" << rewardGold << "G 획득" << "\n";
		player->setGold(player->getGold() + rewardGold);

		// 드랍 아이템 확인
		std::cout << "\n";
		for (const auto& [itemID, count] : droppedItems)
		{
			std::cout << " > " << monster->getName() << "이(가) \"" << ITEM_TABLE.at(itemID)->name << "\"을(를) " << count << "개 드랍했습니다." << "\n";
		}

		// 아이템 획득 및 남는 아이템 구하기
		map<EItemID, int> addedItems = InventorySystem::AddItemsToInventroy(backpackInventory, droppedItems);
		for (const auto& [addedItemID, addedCount] : addedItems)
		{
			std::cout << "    -> \"" << ITEM_TABLE.at(addedItemID)->name << "\" " << addedCount << "개를 배낭에 보관했습니다." << "\n";
		}

		// 가방 가득차면 자동으로 용량 늘린 후 추가하기 (임시)
		if (!droppedItems.empty())
		{
			int currentSlotSize = backpackInventory->getMaxSlotCount();
			backpackInventory->setMaxSlotCount(2 * currentSlotSize);

			cout << "가방이 가득 찼습니다!" << "\n";
			cout << " > 인벤토리 자동 확장! (" << currentSlotSize << " -> " << backpackInventory->getMaxSlotCount() << ")" << "\n";

			map<EItemID, int> addedItems = InventorySystem::AddItemsToInventroy(backpackInventory, droppedItems);
			for (const auto& [addedItemID, addedCount] : addedItems)
			{
				std::cout << "    -> \"" << ITEM_TABLE.at(addedItemID)->name << "\" " << addedCount << "개를 배낭에 보관했습니다." << "\n";
			}

		} // 아래 아이템 교체 로직 실행 X

		// 남은 아이템 확인
		for (const auto& [remainedItemID, renmainedCount] : droppedItems)
		{
			string remainedItemName = ITEM_TABLE.at(remainedItemID)->name;
			std::cout << "배낭 공간이 부족합니다!" << " \"" << remainedItemName << "\" " << renmainedCount << "개와 교체할 슬롯을 선택하세요." << "\n";
			InventorySystem::DisplayInventory(backpackInventory, "배낭 인벤토리");
			std::cout << "교체할 슬롯 번호를 선택하세요. (0: 아이템 포기)" << "\n";
			while (true)
			{
				int slotNumber = InputSystem::InputIntUnitlValid(0, backpackInventory->getUsedSlotCount(), "선택: ", "* 잘못된 입력입니다.\n");
				if (slotNumber == 0)
				{
					std::cout << "    -> \"" << remainedItemName << "\"을(를) 포기합니다." << "\n";
				}
				else
				{
					const vector<Slot>& inventorySlots = backpackInventory->getInventorySlots();
					const Slot& slot = inventorySlots[slotNumber - 1];
					EItemID abandonedItemID = slot.itemID;
					int abandonedAmount = slot.count;

					backpackInventory->removeItem(abandonedItemID, abandonedAmount);
					backpackInventory->addItem(remainedItemID, renmainedCount);

					std::cout << "    -> \"" << ITEM_TABLE.at(abandonedItemID)->name << "\" " << abandonedAmount << " 개를 버리고 \"" << remainedItemName << "\" " << renmainedCount << "개를 획득합니다." << "\n";
					break;
				}
			}
		}

		// 전투 종료 후 던전 입구로 귀환
		switchGameState(EGameState::DUNGEON_ENTER);
	}
	else if (combatManager->getCurrentCombatState() == ECombatState::PlayerDefeat) // 전투 패배
	{
		// TODO: GameOver 상태 추가해서 전환
		player->setCurrentHP(1);
		switchGameState(EGameState::MAIN_MENU);
	}

	spawnManager->returnMonsterToPool(monster);
}

void GameManager::onInventoryOpen()
{
	std::cout << "\n\n";
	std::cout << "========== < 인벤토리 열기 > ==========" << "\n";
	std::cout << "1: 창고 열기" << "\n";
	std::cout << "2: 배낭 열기" << "\n";
	std::cout << "0: 메인 메뉴" << "\n";

	int sortNum;
	string sortStr;
	bool onInventoryOpen = true;
	int option = InputSystem::InputIntUnitlValid(0, 2, "선택: ", "* 잘못된 입력입니다.\n");
	while (onInventoryOpen)
	{
		switch (option)
		{
		case 0:
			switchGameState(EGameState::MAIN_MENU);
			onInventoryOpen = false;
			break;
		case 1: // 창고 - stockInventory
			InventorySystem::DisplayInventory(stockInventory, "창고");
			std::cout << " > 정렬 방식 선택" << "\n";
			std::cout << "  1. 이름 (오름차순)    2. 이름 (내림차순)" << "\n";
			std::cout << "  3. 개수 (오름차순)    4. 개수 (내림차순)" << "\n";
			std::cout << "  5. 가격 (오름차순)    6. 가격 (내림차순)" << "\n";
			std::cout << "  7. 종류 (오름차순)    8. 종류 (내림차순)" << "\n";

			while (true)
			{
				cout << "입력 (0: 뒤로가기): ";
				if (InputSystem::InputInt(sortNum, 0, 8))
				{
					break;
				}
				cout << "다시 입력하세요." << "\n";
			}

			switch (sortNum)
			{
			case 0:
				onInventoryOpen = false;
				break;
			case 1: // 이름 (오름차순)
				sortStr = "이름 (오름차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Name, false);
				break;
			case 2: // 이름 (내림차순)
				sortStr = "이름 (내림차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Name, true);
				break;
			case 3: // 개수 (오름차순)
				sortStr = "개수 (오름차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Count, false);
				break;
			case 4: // 개수 (내림차순)
				sortStr = "개수 (내림차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Count, true);
				break;
			case 5: // 가격 (오름차순)
				sortStr = "가격 (오름차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Price, false);
				break;
			case 6: // 가격 (내림차순)
				sortStr = "가격 (내림차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Price, true);
				break;
			case 7: // 종류 (오름차순)
				sortStr = "종류 (오름차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Type, false);
				break;
			case 8: // 종류 (내림차순)
				sortStr = "종류 (내림차순)";
				InventorySystem::SortInventorySlots(stockInventory, EInventorySortKey::Type, true);
				break;
			default:
				break;
			}

			InventorySystem::DisplayInventory(stockInventory, "창고 [" + sortStr + "]");
			break;
		case 2: // 배낭 - backpackInventory
			InventorySystem::DisplayInventory(backpackInventory, "배낭");
			std::cout << " > 정렬 방식 선택" << "\n";
			std::cout << "  1. 이름 (오름차순)    2. 이름 (내림차순)" << "\n";
			std::cout << "  3. 개수 (오름차순)    4. 개수 (내림차순)" << "\n";
			std::cout << "  5. 가격 (오름차순)    6. 가격 (내림차순)" << "\n";
			std::cout << "  7. 종류 (오름차순)    8. 종류 (내림차순)" << "\n";

			while (true)
			{
				cout << "입력 (0: 뒤로가기): ";
				if (InputSystem::InputInt(sortNum, 0, 8))
				{
					break;
				}
				cout << "다시 입력하세요." << "\n";
			}

			switch (sortNum)
			{
			case 0:
				onInventoryOpen = false;
				break;
			case 1: // 이름 (오름차순)
				sortStr = "이름 (오름차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Name, false);
				break;
			case 2: // 이름 (내림차순)
				sortStr = "이름 (내림차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Name, true);
				break;
			case 3: // 개수 (오름차순)
				sortStr = "개수 (오름차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Count, false);
				break;
			case 4: // 개수 (내림차순)
				sortStr = "개수 (내림차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Count, true);
				break;
			case 5: // 가격 (오름차순)
				sortStr = "가격 (오름차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Price, false);
				break;
			case 6: // 가격 (내림차순)
				sortStr = "가격 (내림차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Price, true);
				break;
			case 7: // 종류 (오름차순)
				sortStr = "종류 (오름차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Type, false);
				break;
			case 8: // 종류 (내림차순)
				sortStr = "종류 (내림차순)";
				InventorySystem::SortInventorySlots(backpackInventory, EInventorySortKey::Type, true);
				break;
			default:
				break;
			}

			InventorySystem::DisplayInventory(backpackInventory, "배낭 [" + sortStr + "]");
			break;
		default:
			break;
		}
	}
}

void GameManager::onPotionShopEnter()
{
	std::cout << "\n\n";
	std::cout << "============== < 포션 제작소 > ==============" << "\n";
	std::cout << "1. 전체 레시피 보기" << "\n";
	std::cout << "2. 검색 - 포션 이름" << "\n";
	std::cout << "3. 검색 - 재료 이름" << "\n";
	std::cout << "4. 인벤토리 확인" << "\n";
	std::cout << "5. 포션 제작" << "\n";
	std::cout << "0. 돌아가기" << "\n";
	std::cout << "============================================" << "\n";

	string target;
	int option = InputSystem::InputIntUnitlValid(0, 5, "선택: ", "* 잘못된 입력입니다.\n");
	switch (option)
	{
	case 1:
		// 전체 레시피 보기
		PotionSystem::ShowAllRecipes();
		break;
	case 2:
		// 포션 이름 검색
		std::cout << "검색할 포션 이름: ";
		InputSystem::InputString(target);
		PotionSystem::SearchByPotionName(target);
		break;
	case 3:
		// 포션 재료 검색
		std::cout << "검색할 재료 이름: ";
		InputSystem::InputString(target);
		PotionSystem::SearchByIngredient(target);
		break;
	case 4:
		InventorySystem::DisplayInventory(backpackInventory);
		break;
	case 5:
	{
		PotionSystem::ShowAllRecipes();
		vector<EItemID> potionIDs = PotionSystem::GetPotionIDs();

		int targetNum = InputSystem::InputIntUnitlValid(0, (int) potionIDs.size(), "제작할 포션 선택: ", "* 잘못된 입력입니다.\n");
		if (targetNum != 0)
		{
			EItemID potionID = potionIDs[targetNum - 1];
			if (CrafterSystem::CraftItem(potionID, backpackInventory))
			{
				cout << " > \"" << ITEM_TABLE.at(potionID)->name << "\" 제작 성공!" << "\n";
			}
			else
			{
				cout << " > 재료가 부족하여 제작할 수 없습니다." << "\n";
			}
		}
		break;
	}
	case 0:
		switchGameState(EGameState::MAIN_MENU);
		break;
	default:
		break;
	}
}

void GameManager::onGameExit()
{
	std::cout << "============================================" << "\n";
	std::cout << "                  게임 종료                  " << "\n";
	std::cout << "============================================" << "\n";
	isRunning = false;
}
