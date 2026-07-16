#include "CombatManager.h"

#include "UISystem.h"
#include "InputSystem.h"
#include "InventorySystem.h"
#include "PotionSystem.h"

#include <iostream>

using namespace std;

CombatManager::CombatManager()
{
}

void CombatManager::start(Player* player, Inventory* inventory, Monster* monster)
{
	this->player = player;
	this->inventory = inventory;
	this->monster = monster;
	isCombatRunning = true;
	switchCombatState(ECombatState::InitBattle);
}

ECombatState CombatManager::getCurrentCombatState()
{
	return currentCombatState;
}

void CombatManager::run()
{
	while (isCombatRunning)
	{
		update();
	}
}

void CombatManager::update()
{
	switch (currentCombatState)
	{
	case ECombatState::InitBattle:
		onBattleInit();
		break;
	case ECombatState::PlayerTurn:
		onPlayerTurn();
		break;
	case ECombatState::CheckVictory:
		onCheckVictory();
		break;
	case ECombatState::MonsterTurn:
		onMonsterTurn();
		break;
	case ECombatState::CheckDefeat:
		onCheckDefeat();
		break;
	case ECombatState::PlayerVictory:
		onPlayerVictory();
		break;
	case ECombatState::PlayerDefeat:
		onPlayerDefeat();
		break;
	case ECombatState::PlayerUsingItem:
		onPlayerUsingItem();
		break;
	default:
		break;
	}
}

void CombatManager::switchCombatState(ECombatState newCombatState)
{
	currentCombatState = newCombatState;
}

void CombatManager::onBattleInit()
{
	cout << monster->getName() << "이(가) 나타났다!" << "\n";

	switchCombatState(ECombatState::PlayerTurn);
}

void CombatManager::onPlayerTurn()
{
	cout << "\n\n";
	cout << "================= < 전투 > =================" << "\n";
	cout << "[" << player->getName() << " vs " << monster->getName() << "]" << "\n";
	cout << "어떻게 할까?" << "\n";
	cout << "1. 공격하기" << "\n";
	cout << "2. 스탯 확인" << "\n";
	cout << "3. 아이템 사용" << "\n";
	cout << "============================================" << "\n";

	int option = InputSystem::InputIntUnitlValid(1, 3, "입력: ", "* 잘못된 입력입니다.\n");

	switch (option)
	{
	case 1:
		player->showAttackMessage();
		player->attack(monster);
		switchCombatState(ECombatState::CheckVictory);
		break;
	case 2:
		UISystem::PrintPlayerStat(player);
		break;
	case 3:
		switchCombatState(ECombatState::PlayerUsingItem);
		break;
	default:
		break;
	}
}

void CombatManager::onCheckVictory()
{
	if (monster->isDead())
	{
		cout << monster->getName() << "을(를) 처치했습니다!" << "\n";
		switchCombatState(ECombatState::PlayerVictory);
	}
	else
	{
		switchCombatState(ECombatState::MonsterTurn);
	}
}

void CombatManager::onMonsterTurn()
{
	cout << " > " << monster->getName() << "의 턴!" << "\n";
	monster->attack(player);
	switchCombatState(ECombatState::CheckDefeat);
}

void CombatManager::onCheckDefeat()
{
	if (player->isDead())
	{
		switchCombatState(ECombatState::PlayerDefeat);
	}
	else
	{
		switchCombatState(ECombatState::PlayerTurn);
	}
}

void CombatManager::onPlayerVictory()
{
	cout << "\n" << "========== 전투 승리 ==========" << "\n";
	cout << monster->getName() << "와(과)의 전투에서 승리하였다!" << "\n";
	isCombatRunning = false;
}

void CombatManager::onPlayerDefeat()
{
	cout << "\n" << "========== 전투 패배 ==========" << "\n";
	cout << monster->getName() << "에게 패배했습니다..." << "\n";
	isCombatRunning = false;
}

void CombatManager::onPlayerUsingItem()
{
	const map<EItemID, int> itemCounts = inventory->getItemCounts({}, {EItemType::POTION});
	InventorySystem::DisplayItemCounts(itemCounts);

	int option = InputSystem::InputIntUnitlValid(0, (int) itemCounts.size(), "사용할 아이템 선택 (0: 뒤로가기): ", "* 잘못된 입력입니다.\n");
	if (option == 0) // 뒤로가기
	{
		switchCombatState(ECombatState::PlayerTurn);
	}
	else // 아이템 사용
	{
		EItemID potionID = next(itemCounts.begin(), option - 1)->first;
		if (PotionSystem::UsePotion(player, inventory, potionID)) // 아이템 사용 성공 시 상태 전환
		{
			switchCombatState(ECombatState::CheckVictory);
		}
	}
}
