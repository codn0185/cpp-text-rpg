#pragma once

#include "Singleton.h"

#include "Player.h"

using namespace std;

enum class EGameState
{
	/*
	[ 게임 흐름 ]
	이름 입력 + 스탯 설정
		-> 직업 선택
		-> 메인 메뉴
			1. 던전 입장 -> 몬스터 전투 -> 아이템 드롭 -> 인벤토리 저장
			2. 인벤토리 확인
			3. 포션 제작소 -> 레시피 보기 / 검색
			0. 게임 종료
	*/

	// 게임 시작
	GAME_START, // 게임 시작
	PLAYER_REGISTRATION, // 플레이어 이름 및 스탯 입력, 직업 선택

	// 메뉴 선택 화면
	MAIN_MENU, // 메인 메뉴

	// 1. 던전
	DUNGEON_ENTER, // 던전 입장
	DUNGEON_COMBAT, // 몬스터 전투
	DUNGEON_REWARD, // 아이템 획득

	// 2. 인벤토리 확인
	INVENTORY_VIEW, // 인벤토리 확인

	// 3. 포션 제작소
	POTION_SHOP_ENTER, // 포션 제작소 입장
	POTION_SHOP_SEARCH, // 포션 검색 (전체 레시피 / 이름 검색 / 재료 검색)

	// 0. 게임 종료
	GAME_EXIT,
};

class GameManager : public Singleton<GameManager>
{
private:
	EGameState currentGameState = EGameState::GAME_START; // 현재 게임 상태

	Player* player = nullptr; // 플레이어

public:
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
	void onDungeonCombat(); // 몬스터와 전투
	void onDungeonReward(); // 전투 보상

	void onInventoryView(); // 인벤토리 확인

	void onPotionShopEnter(); // 포션 제작소 입장
	void onPotionShopSearch(); // 포션 검색

	void onGameExit(); // 게임 종료
};

