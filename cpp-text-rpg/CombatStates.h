#pragma once

#include "CombatState.h"


/*
1. 전투 진입
2. 플레이어 턴 (공격 / 스탯 화인 / 아이템 사용 / 도망가기)
3. 몬스터 사망 확인
4. 몬스터 턴 (공격)
5. 플레이어 사망 확인
6. 플레이어 턴 vs. 7. 도망가기
*/


class InitCombatState : public CombatState
{
public:
	void enter(CombatManager* manager) override;
	void update(CombatManager* manager) override;
	void exit(CombatManager* manager) override;
};

class PlayerTurnCombatState : public CombatState
{
public:
	void enter(CombatManager* manager) override;
	void update(CombatManager* manager) override;
	void exit(CombatManager* manager) override;
};

class CheckVictoryCombatState : public CombatState
{
public:
	void enter(CombatManager* manager) override;
	void update(CombatManager* manager) override;
	void exit(CombatManager* manager) override;
};

class EnemyTurnCombatState : public CombatState
{
public:
	void enter(CombatManager* manager) override;
	void update(CombatManager* manager) override;
	void exit(CombatManager* manager) override;
};

class CheckDefeatCombatState : public CombatState
{
public:
	void enter(CombatManager* manager) override;
	void update(CombatManager* manager) override;
	void exit(CombatManager* manager) override;
};

class EscapeAttempCombatState : public CombatState
{
public:
	void enter(CombatManager* manager) override;
	void update(CombatManager* manager) override;
	void exit(CombatManager* manager) override;
};