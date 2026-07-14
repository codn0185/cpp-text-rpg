#pragma once

#include "Players.h"
#include "Monsters.h"
#include "UISystem.h"

#include <iostream>

enum class ECombatState
{
	InitBattle,
	PlayerTurn,
	CheckVictory,
	MonsterTurn,
	CheckDefeat,
	PlayerVictory,
	PlayerDefeat,
};

class CombatManager
{
private:
	ECombatState currentCombatState;

	Player* player;
	Monster* monster;

public:
	bool isCombatRunning;

	CombatManager();

	void start(Player* player, Monster* monster);
	ECombatState getCurrentCombatState();

	// === State Machines ===
	void run();
	void update();
	void switchCombatState(ECombatState newCombatState);

	void onBattleInit();
	void onPlayerTurn();
	void onCheckVictory();
	void onMonsterTurn();
	void onCheckDefeat();
	void onPlayerVictory();
	void onPlayerDefeat();
};
