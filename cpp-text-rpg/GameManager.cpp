#include "GameManager.h"

GameManager::GameManager()
{
	potionSystem = new PotionSystem();
	player = new NoJob();
}

GameManager::~GameManager()
{
	delete potionSystem;
	delete player;
}

void GameManager::run()
{
	while (currentGameState != EGameState::GAME_EXIT)
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
}

void GameManager::onPlayerResitration()
{
}

		cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << "\n";
{
}

void GameManager::onMainMenu()
{
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
}
