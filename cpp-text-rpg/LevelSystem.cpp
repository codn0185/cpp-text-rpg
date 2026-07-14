#include "LevelSystem.h"

const map<int, LevelDataRow> LevelSystem::LEVEL_TABLE = {
	{0, LevelDataRow(1, 100, Stat(10, 7, 5, 3))},
	{1, LevelDataRow(2, 120, Stat(10, 7, 5, 3))},
	{2, LevelDataRow(3, 150, Stat(10, 7, 5, 3))},
	{3, LevelDataRow(4, 200, Stat(10, 7, 5, 3))},
	{4, LevelDataRow(5, 270, Stat(10, 7, 5, 3))},
};

LevelSystem::LevelSystem()
{
}

void LevelSystem::checkLevelUp(Player* player)
{
	int currentLevel = player->getLevel();
	int currentExp = player->getExp();

	if (player->getLevel() == getMaxLevel())
	{
		return;
	}
	while (player->getExp() >= getRequiredExp(player))
	{
		player->setExp(player->getExp() - getRequiredExp(player));
		player->setLevel(player->getLevel() + 1);
	}
}

void LevelSystem::addExp(Player* player, int amount)
{
	player->setExp(player->getExp() + amount);
	checkLevelUp(player);
}

int LevelSystem::getRequiredExp(Player* player)
{
	if (LEVEL_TABLE.find(player->getLevel()) == LEVEL_TABLE.end())
	{
		return 0;
	}
	return LEVEL_TABLE.at(player->getLevel()).requiredExp;
}

int LevelSystem::getMaxLevel()
{
	return LEVEL_TABLE.rbegin()->second.targetLevel;
}
