#include "CombatManager.h"

#include "UISystem.h"

#include <iostream>

using namespace std;

CombatManager::CombatManager()
{
}

void CombatManager::start(Player* player, Monster* monster)
{
	this->player = player;
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
	cout << monster->getName() << "이/가 나타났다!" << "\n";

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

	int option;
	cout << "선택: ";
	cin >> option;

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
		// 아이템 사용
		break;
	default:
		break;
	}
}

void CombatManager::onCheckVictory()
{
	if (monster->isDead())
	{
		cout << monster->getName() << "를/을 처치했습니다!" << "\n";
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
	cout << monster->getName() << "와/과의 전투에서 승리하였다!" << "\n";
	isCombatRunning = false;
}

void CombatManager::onPlayerDefeat()
{
	cout << "\n" << "========== 전투 패배 ==========" << "\n";
	cout << monster->getName() << "에게 패배했습니다..." << "\n";
	isCombatRunning = false;
}
