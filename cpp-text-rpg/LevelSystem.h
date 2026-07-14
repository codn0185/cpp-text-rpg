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


class LevelSystem : public Singleton<LevelSystem>
{
private:
	static const map<int, LevelDataRow> LEVEL_TABLE;

	int currentLevel = 0;
	int currentExp = 0;

	void checkLevelUp();

public:
	void addExp(int amount);
	int getCurrentLevel();
	int getCurrentExp();
	int getRequiredExp();
	int getMaxLevel();
};

