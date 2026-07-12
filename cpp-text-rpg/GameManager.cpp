#include "GameManager.h"

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
	case EGameState::PLAYER_STAT_REGISTRATION:
		onPlayerResitration();
		break;
	case EGameState::PALYER_JOB_SELECTION:
		onJobSelection();
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

void GameManager::onJobSelection()
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
