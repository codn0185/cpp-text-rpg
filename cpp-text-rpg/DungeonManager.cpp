#include "DungeonManager.h"

#include "SpawnSystem.h"
#include "InputSystem.h"

#include <iostream>
#include <algorithm>

using namespace std;


DungeonFloorData::DungeonFloorData(EDungeonFloor dungeonFloor, string name, EDungeonFloor prerequisiteFloor, int requiredKillCount, vector<EMonsterType> monsterTypes, vector<float> weights)
	: dungeonFloor(dungeonFloor), name(name), prerequisiteFloor(prerequisiteFloor), requiredKillCount(requiredKillCount), monsterTypes(monsterTypes), weights(weights)
{
}

bool DungeonFloorData::canUnlock(EDungeonFloor currentDugeonFloor, int sessionKillCount) const
{
	return (currentDugeonFloor == prerequisiteFloor) && (sessionKillCount >= requiredKillCount);
}

const map<EDungeonFloor, DungeonFloorData> DUNGEON_FLOOR_TABLE = {
	{EDungeonFloor::None, DungeonFloorData(EDungeonFloor::None, "지상", EDungeonFloor::None, 0,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f})},
	{EDungeonFloor::Floor1, DungeonFloorData(EDungeonFloor::Floor1, "던전 1층", EDungeonFloor::None, 0,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f})},
	{EDungeonFloor::Floor2, DungeonFloorData(EDungeonFloor::Floor2, "던전 2층", EDungeonFloor::Floor1, 10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f})},
	{EDungeonFloor::Floor3, DungeonFloorData(EDungeonFloor::Floor3, "던전 3층", EDungeonFloor::Floor2, 10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f})},
	{EDungeonFloor::Boss, DungeonFloorData(EDungeonFloor::Boss, "보스 방", EDungeonFloor::Floor3, 10,
		{EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton},
		{1.0f, 1.0f, 1.0f})},
};


DungeonManager::DungeonManager()
	: currentDungeonFloor(EDungeonFloor::None), sessionKillCount(0)
{
	dungeonFloorMenuList = {
		EDungeonFloor::Floor1,
		EDungeonFloor::Floor2,
		EDungeonFloor::Floor3,
		EDungeonFloor::Boss,
	};
	dungeonFloorAvailables = {
		{EDungeonFloor::Floor1, true},
		{EDungeonFloor::Floor2, false},
		{EDungeonFloor::Floor3, false},
		{EDungeonFloor::Boss, false},
	};
	dungeonFloorMaxKillCounts = {
		{EDungeonFloor::Floor1, 0},
		{EDungeonFloor::Floor2, 0},
		{EDungeonFloor::Floor3, 0},
		{EDungeonFloor::Boss, 0},
	};
}

void DungeonManager::displayDungeonFloorMenu() const
{
	cout << "═══════════════ < 던전 입장 > ═══════════════" << "\n";
	for (int i = 0; i < dungeonFloorMenuList.size(); i++)
	{
		EDungeonFloor dungeonFloor = dungeonFloorMenuList[i];
		const DungeonFloorData& dungeonFloorDataRow = DUNGEON_FLOOR_TABLE.at(dungeonFloor);
		string name = dungeonFloorDataRow.name;
		if (isAvailable(dungeonFloor))
		{
			string str;
			cout << i + 1 << ". ✅ [" << name << "] (💀 최고 연속 처치 - " << dungeonFloorMaxKillCounts.at(dungeonFloor) << ")" << "\n";
		}
		else
		{
			const DungeonFloorData& prerequisiteDungeonFloorData = DUNGEON_FLOOR_TABLE.at(dungeonFloorDataRow.prerequisiteFloor);
			cout << i + 1 << ". 🚫 [" << name << "] (🎯 해금 조건: \"" << prerequisiteDungeonFloorData.name << "\"에서 " << dungeonFloorDataRow.requiredKillCount << " 연속 처치)" << "\n";
		}
	}
	cout << "────────────────────────────────────────────" << "\n";
	cout << "0. 🔙 돌아가기" << "\n";
	cout << "════════════════════════════════════════════" << "\n";
}

void DungeonManager::displayDungeonEnterMessage(EDungeonFloor dungeonProgress) const
{
	const string& name = DUNGEON_FLOOR_TABLE.at(dungeonProgress).name;
	string emoji = dungeonProgress != EDungeonFloor::Boss ? "⚔️" : "👑";

	cout << "───────────────────────────────────────" << "\n";
	cout << emoji << " [" << name << "]에 입장합니다!" << "\n";
	cout << "───────────────────────────────────────" << "\n";
}

void DungeonManager::displayAccessDeniedMessage(EDungeonFloor dungeonProgress) const
{
	const string& name = DUNGEON_FLOOR_TABLE.at(dungeonProgress).name;

	cout << "───────────────────────────────────────" << "\n";
	cout << "🚫 [" << name << "]에 입장할 수 없습니다! " << "\n";
	cout << " > 아직 해금되지 않은 구역입니다. 이전 구역을 먼저 클리어하세요." << "\n";
	cout << "───────────────────────────────────────" << "\n";
}

void DungeonManager::displayUnlockProgress() const
{
	for (const auto& [targetFloor, requirement] : DUNGEON_FLOOR_TABLE)
	{
		if (currentDungeonFloor == requirement.prerequisiteFloor)
		{
			string currentDungeonFloorName = DUNGEON_FLOOR_TABLE.at(currentDungeonFloor).name;
			string targetDungeonFloorName = requirement.name;
			int targetKillCount = requirement.requiredKillCount;
			string progressBar;
			for (int i = 0; i < sessionKillCount; i++)
			{
				progressBar += "■";
			}
			for (int i = 0; i < targetKillCount - sessionKillCount; i++)
			{
				progressBar += "□";
			}

			cout << "[" << currentDungeonFloorName << " ➔ " << targetDungeonFloorName << "] "
				<< "진행도: [" << progressBar << "] "
				<< "(" << sessionKillCount << "/" << targetKillCount << ")" << "\n";
		}
	}
}

const std::vector<EDungeonFloor> DungeonManager::getDungeonFloorMenuList() const
{
	return dungeonFloorMenuList;
}

bool DungeonManager::isAvailable(EDungeonFloor dungeonFloor) const
{
	if (dungeonFloorAvailables.find(dungeonFloor) == dungeonFloorAvailables.end())
	{
		return false;
	}
	return dungeonFloorAvailables.at(dungeonFloor);
}

void DungeonManager::checkAndUnlockFloor()
{
	for (const auto& [targetFloor, requirement] : DUNGEON_FLOOR_TABLE)
	{
		if (isAvailable(targetFloor)) // 이미 해금된 던전 층
		{
			continue;
		}
		if (requirement.canUnlock(currentDungeonFloor, sessionKillCount)) // 조건 만족
		{
			// 던전 층 해금
			dungeonFloorAvailables[targetFloor] = true;
			// 플레이어 알림
			cout << "━━━━━━━━━━━ <🎉 새로운 던전 해금> ━━━━━━━━━━━" << "\n";
			cout << "🔓 [" << DUNGEON_FLOOR_TABLE.at(targetFloor).name << "] 이(가) 해금되었습니다!" << "\n";
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "\n";
		}

	}
}

bool DungeonManager::tryEnterDungeonFloor(EDungeonFloor dungeonFloor)
{
	if (!isAvailable(dungeonFloor)) // 접근 불가
	{
		displayAccessDeniedMessage(dungeonFloor);
		return false;
	}
	// 던전 입장
	displayDungeonEnterMessage(dungeonFloor);
	currentDungeonFloor = dungeonFloor;
	return true;
}

bool DungeonManager::tryEnterDungeonFloor(int MenuIndex)
{
	return tryEnterDungeonFloor(dungeonFloorMenuList.at(MenuIndex));
}

void DungeonManager::onMonsterKilled()
{
	sessionKillCount++;
	checkAndUnlockFloor();
}

void DungeonManager::onExit()
{
	// 최고 기록 저장
	dungeonFloorMaxKillCounts[currentDungeonFloor] = max(dungeonFloorMaxKillCounts[currentDungeonFloor], sessionKillCount);
	// 초기화
	currentDungeonFloor = EDungeonFloor::None;
	sessionKillCount = 0;
}

Monster* DungeonManager::getRandomMonsterByCurrentDungeonFloor()
{
	return SpawnSystem::GetRandomMonsterFromPool(
		DUNGEON_FLOOR_TABLE.at(currentDungeonFloor).monsterTypes,
		DUNGEON_FLOOR_TABLE.at(currentDungeonFloor).weights
	);
}

void DungeonManager::returnMonster(Monster* monster)
{
	SpawnSystem::ReturnMonsterToPool(monster);
}
