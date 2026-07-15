#pragma once

#include "Player.h"

#include <map>

struct LevelDataRow
{
	int targetLevel;
	int requiredExp;
	Stat increaseStat;

	LevelDataRow(int targetLevel, int requiredExp, Stat increaseStat)
		: targetLevel(targetLevel), requiredExp(requiredExp), increaseStat(increaseStat)
	{
	}
};

extern const std::map<int, LevelDataRow> LEVEL_TABLE;

class LevelSystem
{
private:
	static void CheckLevelUp(Player* player);

public:
	LevelSystem();
	~LevelSystem() = default;

	static int GetMaxLevel();
	static int GetRequiredExp(Player* player);

	static void AddExp(Player* player, int amount);
};

