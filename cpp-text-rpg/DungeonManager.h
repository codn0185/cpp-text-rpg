#pragma once

#include "Monster.h"

#include <string>
#include <vector>
#include <map>

enum class EDungeonFloor
{
	None,   // 던전 밖
	Floor1, // 1층
	Floor2, // 2층
	Floor3, // 3층
	Boss,   // 보스
};

struct DungeonFloorData
{
	EDungeonFloor dungeonFloor;       // 던전 층
	std::string name;                 // 이름
	EDungeonFloor prerequisiteFloor;  // 해금 조건을 수행할 던전 층
	int requiredKillCount;            // 해금에 필요한 처치 횟수

	DungeonFloorData(EDungeonFloor dungeonFloor, std::string name, EDungeonFloor prerequisiteFloor = EDungeonFloor::None, int requiredKillCount = 0);

	bool canUnlock(EDungeonFloor currentDugeonFloor, int sessionKillCount) const; // 해금 조건 만족 여부 반환
};

extern const std::map<EDungeonFloor, DungeonFloorData> DUNGEON_FLOOR_TABLE; // 던전 층 테이블

struct DungeonFloorSpawnData
{
	EDungeonFloor dungeonFloor;        // 던전 층
	std::vector<EMonsterType> monsterTypes; // 소환할 몬스터 타입들
	std::vector<float> weights;      // 소환할 몬스터 가중치들

	DungeonFloorSpawnData(EDungeonFloor dungeonFloor, std::vector<EMonsterType> monsterTypes, std::vector<float> weights);
};

extern const std::map<EDungeonFloor, DungeonFloorSpawnData> DUNGEON_FLOOR_SPAWN_DATA; // 던전 층 소환 테이블


class DungeonManager
{
private:
	std::vector<EDungeonFloor> dungeonFloorMenuList;         // 던전 입장 시 등장할 던전 층 선택 메뉴 목록
	std::map<EDungeonFloor, bool> dungeonFloorAvailableList; // 각 던전 층 입장 가능 여부들
	std::map<EDungeonFloor, int> dungeonFloorMaxKillCount;   // 각 던전 층 최고 처치 횟수

	EDungeonFloor currentDungeonFloor; // 현재 던전 층 위치
	int sessionKillCount;              // 현재 던전 층의 몬스터 연속 처치 횟수

public:
	DungeonManager();
	~DungeonManager() = default;

	void displayDungeonFloorMenu() const; // 던전 입장 시 층 선택 메뉴 출력 및 목록 반환
	void displayDungeonEnterMessage(EDungeonFloor dungeonFloor) const; // 던전 입장 메시지 출력
	void displayAccessDeniedMessage(EDungeonFloor dungeonFloor) const; // 던전 접근 거부 메시지 출력
	void displayUnlockProgress() const;

	const std::vector<EDungeonFloor> getDungeonFloorMenuList() const; // 던전 메뉴 리스트 반환

	bool isAvailable(EDungeonFloor dungeonFloor) const; // 진입 가능 여부 반환
	void checkAndUnlockFloor(); // 해금 확인

	bool tryEnterDungeonFloor(EDungeonFloor dungeonFloor); // 던전 층 입장 시도 (입장 실패 시 false 반환, 입장 성공 시 true 반환)
	bool tryEnterDungeonFloor(int MenuIndex); // 던전 층 입장 시도 (메뉴 인덱스 사용)

	void onMonsterKilled(); // 몬스터 처치 시 호출 (처치 수 증가 및 해금 확인)
	void onExit(); // 던전 나갈 시 호출 (현재 던전 층 및 처치 수 저장 후 초기화)

	Monster* getRandomMonsterByCurrentDungeonFloor(); // 현재 던전 층에 등장 가능한 무작위 몬스터 소환
	void returnMonster(Monster* monster); // 몬스터 
};

