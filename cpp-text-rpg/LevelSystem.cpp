#include "LevelSystem.h"

#include "SkillSystem.h"

#include <iostream>

using namespace std;

const map<int, LevelDataRow> LEVEL_TABLE = {
	{0, LevelDataRow(1, 100, Stat(10, 7, 5, 3))},
	{1, LevelDataRow(2, 120, Stat(10, 7, 5, 3))},
	{2, LevelDataRow(3, 150, Stat(10, 7, 5, 3))},
	{3, LevelDataRow(4, 200, Stat(10, 7, 5, 3))},
	{4, LevelDataRow(5, 270, Stat(10, 7, 5, 3))},
};

LevelSystem::LevelSystem()
{
}

void LevelSystem::CheckLevelUp(Player* player)
{
	int currentLevel = player->getLevel();
	int currentExp = player->getExp();


	// 레벨 업
	while (player->getExp() >= GetRequiredExp(player))
	{
		// 최대 레벨 확인
		if (player->getLevel() == GetMaxLevel())
		{
			return;
		}

		// 관련 정보 변수로 저징
		int prevLevel = player->getLevel();
		int prevExp = player->getExp();

		int nextLevel = prevLevel + 1;
		int nextExp = prevExp - GetRequiredExp(player);
		Stat stat = LEVEL_TABLE.at(prevLevel).increaseStat;

		string levelUpStr = "Lv. " + to_string(prevLevel) + " -> Lv. " + to_string(nextLevel);
		string statIncreaseStr;
		if (stat.hp)
		{
			statIncreaseStr += "HP +" + to_string(stat.hp) + ", ";
		}
		if (stat.mp)
		{
			statIncreaseStr += "MP +" + to_string(stat.mp) + ", ";
		}
		if (stat.power)
		{
			statIncreaseStr += "공격력 +" + to_string(stat.power) + ", ";
		}
		if (stat.defence)
		{
			statIncreaseStr += "방어력 +" + to_string(stat.defence) + ", ";
		}
		statIncreaseStr.erase(statIncreaseStr.length() - 2);

		// 플레이어 정보 업데이트
		player->increaseStat(stat);
		player->setLevel(nextLevel);
		player->setExp(nextExp);
		player->reset();
		const vector<const SkillData*> unlockedSkills = SkillSystem::UnlockSkillsForCurrentLevel(player);

		// 레벨 업 메시지 출력
		cout << "======================================" << "\n";
		cout << " > Level Up!" << "\n";
		cout << "    -> " << levelUpStr << "\n";
		cout << "    -> " << statIncreaseStr << "\n";
		if (!unlockedSkills.empty())
		{
			cout << " > 새로운 스킬 해금!" << "\n";
		}
		for (const SkillData* skillData : unlockedSkills)
		{
			cout << "    -> " << skillData->getInfoText() << "\n";
		}
		cout << "======================================" << "\n";
	}
}

int LevelSystem::GetRequiredExp(const Player* player)
{
	if (LEVEL_TABLE.find(player->getLevel()) == LEVEL_TABLE.end())
	{
		return 0;
	}
	return LEVEL_TABLE.at(player->getLevel()).requiredExp;
}

int LevelSystem::GetMaxLevel()
{
	return LEVEL_TABLE.rbegin()->second.targetLevel;
}


void LevelSystem::AddExp(Player* player, const int amount)
{
	player->setExp(player->getExp() + amount);
	CheckLevelUp(player);
}