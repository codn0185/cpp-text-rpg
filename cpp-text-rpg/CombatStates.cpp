#include "CombatStates.h"

// InitCombatState
void InitCombatState::enter(CombatManager* manager)
{
	manager->isCombatRunning = true;
	// 몬스터 조우 메시지 출력
	// 몬스터 정보 출력
}

void InitCombatState::update(CombatManager* manager)
{
	// 선공 결정 (플레이어 턴)
	manager->switchState(make_unique<PlayerTurnCombatState>(manager));
}

void InitCombatState::exit(CombatManager* manager)
{
}

// PlayerTurnCombatState
void PlayerTurnCombatState::enter(CombatManager* manager)
{
	// 플레이어 턴 알림
	// 플레이어 스탯 출력
}

void PlayerTurnCombatState::update(CombatManager* manager)
{
	// 플레이어 행동 결정
}

void PlayerTurnCombatState::exit(CombatManager* manager)
{
	//
}

// EnemyTurnCombatState
void EnemyTurnCombatState::enter(CombatManager* manager)
{
	//
}

void EnemyTurnCombatState::update(CombatManager* manager)
{
	//
}

void EnemyTurnCombatState::exit(CombatManager* manager)
{
	//
}

// CheckVictoryCombatState
void CheckVictoryCombatState::enter(CombatManager* manager)
{
}

void CheckVictoryCombatState::update(CombatManager* manager)
{
}

void CheckVictoryCombatState::exit(CombatManager* manager)
{
}

// CheckDefeatCombatState
void CheckDefeatCombatState::enter(CombatManager* manager)
{
}

void CheckDefeatCombatState::update(CombatManager* manager)
{
}

void CheckDefeatCombatState::exit(CombatManager* manager)
{
}

// EscapeAttempCombatState
void EscapeAttempCombatState::enter(CombatManager* manager)
{
}

void EscapeAttempCombatState::update(CombatManager* manager)
{
}

void EscapeAttempCombatState::exit(CombatManager* manager)
{
}
