#include "LevelSystem.h"

const map<int, LevelDataRow> LevelSystem::LEVEL_TABLE = {
	{0, LevelDataRow(1, 100)},
	{1, LevelDataRow(2, 100)},
	{2, LevelDataRow(3, 100)},
	{3, LevelDataRow(4, 100)},
	{4, LevelDataRow(5, 100)},
};

LevelSystem::LevelSystem() : currentLevel(0), currentExp(0)
{
}

void LevelSystem::checkLevelUp()
{
	if (currentLevel == getMaxLevel())
	{
		return;
	}
	while (currentExp >= getRequiredExp())
	{
		currentExp -= getRequiredExp();
		currentLevel++;
	}
}

void LevelSystem::addExp(int amount)
{
	currentExp += amount;
	checkLevelUp();
}

int LevelSystem::getCurrentLevel()
{
	return currentLevel;
}

int LevelSystem::getCurrentExp()
{
	return currentExp;
}

int LevelSystem::getRequiredExp()
{
	if (LEVEL_TABLE.find(currentLevel) == LEVEL_TABLE.end())
	{
		return 0;
	}
	return LEVEL_TABLE.at(currentLevel).requiredExp;
}

int LevelSystem::getMaxLevel()
{
	return LEVEL_TABLE.rbegin()->second.targetLevel;
}
