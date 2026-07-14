#pragma once

#include "Singleton.h"

#include <map>

using namespace std;

struct LevelDataRow
{
	int targetLevel;
	int requiredExp;

	LevelDataRow(int targetLevel, int requiredExp) :targetLevel(targetLevel), requiredExp(requiredExp)
	{
	}
};


class LevelSystem
{
private:
	static const map<int, LevelDataRow> LEVEL_TABLE;

	int currentLevel;
	int currentExp;

	void checkLevelUp();

public:
	LevelSystem();
	~LevelSystem() = default;

	void addExp(int amount);
	int getCurrentLevel();
	int getCurrentExp();
	int getRequiredExp();
	int getMaxLevel();
};

