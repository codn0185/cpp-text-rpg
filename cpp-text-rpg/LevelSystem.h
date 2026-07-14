#pragma once

#include "Singleton.h"
#include "Player.h"

#include <iostream>
#include <map>

using namespace std;

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

class LevelSystem
{
private:
	static const map<int, LevelDataRow> LEVEL_TABLE;

	void checkLevelUp(Player* player);

public:
	LevelSystem();
	~LevelSystem() = default;

	int getMaxLevel();
	int getRequiredExp(Player* player);

	void addExp(Player* player, int amount);
};

