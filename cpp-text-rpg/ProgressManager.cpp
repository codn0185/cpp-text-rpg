#include "ProgressManager.h"

#include <iostream>

using namespace std;

DungeonProgressDataRow::DungeonProgressDataRow(EDungeonProgress dungeonProgress, string dungeonDisplayName, int targetKillCount, vector<EMonsterType> spawnMonsterTypes, vector<float> spawnMonsterweights)
	: dungeonProgress(dungeonProgress), dungeonDisplayName(dungeonDisplayName), targetKillCount(targetKillCount), spawnMonsterTypes(spawnMonsterTypes), spawnMonsterweights(spawnMonsterweights)
{
}

const map<EDungeonProgress, DungeonProgressDataRow> DUNGEON_PROGRESS_TABLE = {
	{EDungeonProgress::Floor1, DungeonProgressDataRow(
		EDungeonProgress::Floor1,
		"던전 1층",
		10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f}
		)},
	{EDungeonProgress::Floor2, DungeonProgressDataRow(
		EDungeonProgress::Floor2,
		"던전 2층",
		10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f}
		)},
	{EDungeonProgress::Floor3, DungeonProgressDataRow(
		EDungeonProgress::Floor3,
		"던전 3층",
		10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f}
		)},
	{EDungeonProgress::Boss, DungeonProgressDataRow(
		EDungeonProgress::Boss,
		"보스방",
		10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f}
		)},
};

ProgressManager::ProgressManager()
	: currentDungeonProgress(EDungeonProgress::None)
{
	unlockedDungeonProgresses[EDungeonProgress::None] = true;
	unlockedDungeonProgresses[EDungeonProgress::Floor1] = true;
	unlockedDungeonProgresses[EDungeonProgress::Floor2] = false;
	unlockedDungeonProgresses[EDungeonProgress::Floor3] = false;
	unlockedDungeonProgresses[EDungeonProgress::Boss] = false;
}

EDungeonProgress ProgressManager::getCurrentDungeonProgress()
{
	return currentDungeonProgress;
}

void ProgressManager::setCurrentDungeonProgress(EDungeonProgress dungeonProgress)
{
	this->currentDungeonProgress = dungeonProgress;
}

void ProgressManager::unlockDungeonProgress(EDungeonProgress dungeonProgress)
{
	setCurrentDungeonProgress(dungeonProgress);
}

bool ProgressManager::tryUnlockDungeonProgress(EDungeonProgress dungeonProgress)
{
	return false;
}

void ProgressManager::displayDungeonSelection()
{
}

void ProgressManager::displayDungeonEnterMessage(EDungeonProgress dungeonProgress)
{
	const string& displayName = DUNGEON_PROGRESS_TABLE.at(dungeonProgress).dungeonDisplayName;

	std::cout << "=======================================" << "\n";
	switch (dungeonProgress)
	{
	case EDungeonProgress::None:
		break;
	case EDungeonProgress::Floor1:
		std::cout << "🦇 [" << displayName << "]에 입장합니다." << "\n";
		break;
	case EDungeonProgress::Floor2:
		std::cout << "⛏️ [" << displayName << "]에 입장합니다." << "\n";
		break;
	case EDungeonProgress::Floor3:
		std::cout << "🛡️ [" << displayName << "]에 입장합니다." << "\n";
		break;
	case EDungeonProgress::Boss:
		std::cout << "🔥 [" << displayName << "]에 입장합니다." << "\n";
		break;
	default:
		break;
	}
}

void ProgressManager::displayAccessDeniedMessage(EDungeonProgress dungeonProgress)
{
	const string& displayName = DUNGEON_PROGRESS_TABLE.at(dungeonProgress).dungeonDisplayName;

	std::cout << "=======================================" << "\n";
	std::cout << "🚫 [접근 불가] 입장할 수 없습니다!" << "\n";
	switch (dungeonProgress)
	{
	case EDungeonProgress::None:
		break;
	case EDungeonProgress::Floor1:
		std::cout << "🔒 [" << displayName << "]은 아직 해금되지 않은 구역입니다. 이전 구역을 먼저 클리어하세요." << "\n";
		break;
	case EDungeonProgress::Floor2:
		std::cout << "🔒 [" << displayName << "]은 아직 해금되지 않은 구역입니다. 이전 구역을 먼저 클리어하세요." << "\n";
		break;
	case EDungeonProgress::Floor3:
		std::cout << "🔒 [" << displayName << "]은 아직 해금되지 않은 구역입니다. 이전 구역을 먼저 클리어하세요." << "\n";
		break;
	case EDungeonProgress::Boss:
		std::cout << "🔒 [" << displayName << "]은 아직 해금되지 않은 구역입니다. 이전 구역을 먼저 클리어하세요." << "\n";
		break;
	default:
		break;
	}
}

bool ProgressManager::tryEnterDungeonProgress(EDungeonProgress dungeonProgress)
{
	if (unlockedDungeonProgresses[dungeonProgress]) // 입장 가능
	{
		displayDungeonEnterMessage(dungeonProgress);
		setCurrentDungeonProgress(dungeonProgress);
		return true;
	}
	else // 입장 불가
	{
		displayAccessDeniedMessage(dungeonProgress);
		return false;
	}
}
