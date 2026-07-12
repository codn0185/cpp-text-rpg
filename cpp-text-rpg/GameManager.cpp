#include "GameManager.h"

#include <iostream>

GameManager::GameManager()
{
	potionSystem = new PotionSystem();
}

GameManager::~GameManager()
{
	delete potionSystem;
	delete player;
}

void GameManager::run()
{
	while (true)
	{
		update();
		if (currentGameState == EGameState::GAME_EXIT)
		{
			break;
		}
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
	case EGameState::DUNGEON_REWARD:
		onDungeonReward();
		break;
	case EGameState::INVENTORY_VIEW:
		onInventoryView();
		break;
	case EGameState::POTION_SHOP_ENTER:
		onPotionShopEnter();
		break;
	case EGameState::POTION_SHOP_SEARCH:
		onPotionShopSearch();
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
	cout << "===========================================" << "\n";
	cout << "          [ 던전 탈출 텍스트 RPG ]          " << "\n";
	cout << "===========================================" << "\n";

	switchGameState(EGameState::PLAYER_REGISTRATION);
}

void GameManager::onPlayerResitration()
{
	// === 플레이어 이름, 스탯 입력 ===

	string name;
	const int SIZE = 4;
	int stat[SIZE] = {0}; // HP, MP, 공격력, 방어력

	// 이름 입력
	cout << "용사의 이름을 입력해주세요: ";
	cin >> name;

	// HP, MP 입력
	while (true)
	{
		cout << "HP와 MP를 입력해주세요: ";
		cin >> stat[0] >> stat[1];

		if (stat[0] > 50 && stat[1] > 50)
		{
			break;
		}

		cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
	}

	// 공격력, 방어력 입력
	while (true)
	{
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> stat[2] >> stat[3];

		if (stat[2] > 50 && stat[3] > 50)
		{
			break;
		}

		cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
	}

	// 플레이어 등록
	player = new NoJob(name, stat[0], stat[1], stat[2], stat[3]);
	UISystem::PrintPlayerStat(player);

	// === 스탯 업그레이드 (w/ 포션) ===

	cout << "\n\n";
	cout << "HP 포션 " << potionSystem->getHPPotionCount() << "개, MP 포션 " << potionSystem->getMPPotionCount() << "개가 기본 지급되었습니다." << "\n";

	bool isGameStart = false;
	while (!isGameStart)
	{

		// 강화 메뉴 출력
		cout << "============================================" << "\n";
		cout << "< 캐릭터 강화 >" << "\n";
		cout << "1. HP UP    2. MP UP    3. 공격력 2배" << "\n";
		cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작" << "\n";
		cout << "============================================" << "\n";

		// 번호 선택
		cout << "번호를 선택해주세요: ";
		int option;
		cin >> option;

		switch (option)
		{
		case 0:
			cout << "게임을 시작합니다!" << "\n";
			isGameStart = true;
			break;
		case 1:
			if (potionSystem->useHPPotion(player))
			{
				cout << "* HP가 20 증가했습니다. (HP 포션 차감: 남은 포션 " << potionSystem->getHPPotionCount() << "개)" << "\n";
			}
			else
			{
				cout << "* 포션 부족" << "\n";
			}
			break;
		case 2:
			if (potionSystem->useMPPotion(player))
			{
				cout << "* MP가 20 증가했습니다. (MP 포션 차감: 남은 포션 " << potionSystem->getMPPotionCount() << "개)" << "\n";
			}
			else
			{
				cout << "* 포션 부족" << "\n";
			}
			break;
		case 3:
			player->setPower(2 * player->getPower());
			cout << "* 공격력이 2배 증가했습니다. (현재 공격력: " << player->getPower() << ")" << "\n";
			break;
		case 4:
			player->setDefence(2 * player->getDefence());
			cout << "* 방어력이 2배 증가했습니다. (현재 방어력: " << player->getDefence() << ")" << "\n";
			break;
		case 5:
			UISystem::PrintPlayerStat(player);
			break;
		}
		cout << "\n\n";
	}

	// === 플레이어 직업 선택 ===

	cout << "\n\n";
	cout << name + "님, 직업을 선택해주세요!" << "\n";
	cout << "1. 전사   2. 마법사   3. 도적   4. 궁수" << "\n";

	cout << "선택: ";
	int jobNumber;
	cin >> jobNumber;

	switch (jobNumber)
	{
	case 1:
		player->setDefence(player->getDefence() + 30);
		player = new Warrior(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		cout << "* 전사로 전직하였습니다. (방어력 +30)" << "\n";
		break;
	case 2:
		player->setMP(player->getMP() + 30);
		player = new Mage(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		cout << "* 마법사로 전직하였습니다. (MP +30)" << "\n";
		break;
	case 3:
		player->setPower(player->getPower() + 30);
		player = new Rogue(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		cout << "* 도적으로 전직하였습니다. (공격력 +30)" << "\n";
		break;
	case 4:
		player->setHP(player->getHP() + 30);
		player = new Archer(player->getName(), player->getHP(), player->getMP(), player->getPower(), player->getDefence());
		cout << "* 궁수로 전직하였습니다. (HP +30)" << "\n";
		break;
	}
	cout << "\n\n";

	switchGameState(EGameState::MAIN_MENU);
}

void GameManager::onMainMenu()
{
	cout << "" << "\n";
	cout << "============================================" << "\n";
	cout << "< 메인 메뉴 >" << "\n";
	cout << "1. 던전 입장" << "\n";
	cout << "2. 인벤토리 확인" << "\n";
	cout << "3. 포션 제작소" << "\n";
	cout << "0. 게임 종료" << "\n";
	cout << "============================================" << "\n";


	int option;
	cout << "선택: ";
	cin >> option;

	switch (option)
	{
	case 1:
		switchGameState(EGameState::DUNGEON_ENTER);
		break;
	case 2:
		switchGameState(EGameState::INVENTORY_VIEW);
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
}

void GameManager::onDungeonCombat()
{
}

void GameManager::onDungeonReward()
{
}

void GameManager::onInventoryView()
{
}

void GameManager::onPotionShopEnter()
{
}

void GameManager::onPotionShopSearch()
{
}

void GameManager::onGameExit()
{
	cout << "============================================" << "\n";
	cout << "게임 종료" << "\n";
	cout << "============================================" << "\n";
}
