#pragma once

#include "Monster.h"

#include <string>
#include <vector>
#include <map>

enum class EDungeonProgress
{
	None,   // 던전 밖
	Floor1, // 1층
	Floor2, // 2층
	Floor3, // 3층
	Boss,   // 보스
};

struct DungeonProgressDataRow
{
	EDungeonProgress dungeonProgress;            // 진행도
	std::string dungeonDisplayName;              // 이름
	int targetKillCount;                         // 목표 처리 횟수
	std::vector<EMonsterType> spawnMonsterTypes; // 소환할 몬스터 종류
	std::vector<float> spawnMonsterweights;      // 소환할 몬스터 가중치

	DungeonProgressDataRow(EDungeonProgress dungeonProgress, std::string dungeonDisplayName, int targetKillCount, std::vector<EMonsterType> spawnMonsterTypes, std::vector<float> spawnMonsterweights);
};

extern const std::map<EDungeonProgress, DungeonProgressDataRow> DUNGEON_PROGRESS_TABLE;

class ProgressManager
{
private:

	EDungeonProgress currentDungeonProgress;
	std::map<EDungeonProgress, bool> unlockedDungeonProgresses;

public:
	ProgressManager();
	~ProgressManager() = default;

	EDungeonProgress getCurrentDungeonProgress();
	void setCurrentDungeonProgress(EDungeonProgress dungeonProgress);

	void unlockDungeonProgress(EDungeonProgress dungeonProgress);
	bool tryUnlockDungeonProgress(EDungeonProgress dungeonProgress);

	void displayDungeonSelection();
	void displayDungeonEnterMessage(EDungeonProgress dungeonProgress);
	void displayAccessDeniedMessage(EDungeonProgress dungeonProgress);

	bool tryEnterDungeonProgress(EDungeonProgress dungeonProgress);
};

