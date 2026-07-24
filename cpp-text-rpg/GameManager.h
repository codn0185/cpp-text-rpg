#pragma once

#include "Singleton.h"

#include "ShopManager.h"
#include "DungeonManager.h"
#include "CombatManager.h"

enum class EGameState
{
	// 게임 초기
	GAME_START, // 게임 시작
	PLAYER_REGISTRATION, // 플레이어 이름 및 스탯 입력, 직업 선택

	// 메뉴 선택 화면
	MAIN_MENU, // 메인 메뉴

	// 던전
	DUNGEON_ENTER, // 던전 입장
	DUNGEON_SELECT_FLOOR, // 던전 층 선택
	DUNGEON_COMBAT, // 몬스터 전투
	DUNGEON_COMBAT_RESULT, // 몬스터 전투 결과 (계속하기/돌아가기 선택)

	// 인벤토리
	INVENTORY_OPEN, // 인벤토리 확인 (창고, 배낭)

	// 상점
	SHOP_ENTER, // 상점 입장

	// 포션 제작소
	POTION_SHOP_ENTER, // 포션 제작소 입장

	// 게임 종료
	GAME_EXIT,
};

class GameManager : public Singleton<GameManager>
{
private:
	EGameState currentGameState = EGameState::GAME_START; // 현재 게임 상태
	bool isRunning;

	DungeonManager* dungeonManager; // 던전 매니저
	CombatManager* combatManager; // 전투 매니저

	Player* player; // 플레이어

	Inventory* backpackInventory; // 배낭 인벤토리
	Inventory* stockInventory; // 창고 인벤토리

public:
	GameManager();
	~GameManager();

	// 실행
	void run();

	// 게임 업데이트
	void update();

	// 게임 상태 전환
	void switchGameState(EGameState newGameState);

	// === 게임 상태 별 기능 ===

	void onGameStart(); // 게임 시작

	void onPlayerResitration(); // 플레이어 이름 및 스탯 입력, 직업 선택

	void onMainMenu(); // 메인 메뉴 

	void onDungeonEnter(); // 던전 입장
	void onDungeonSelectFloor(); // 던전 층 선택
	void onDungeonCombat(); // 몬스터와 전투
	void onDungeonCombatResult(); // 몬스터와 전투 결과

	void onInventoryOpen();

	void onShopEnter(); // 상점 입장

	void onPotionShopEnter(); // 포션 제작소 입장

	void onGameExit(); // 게임 종료
};

