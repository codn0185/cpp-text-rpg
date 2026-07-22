#pragma once

#include "Players.h"
#include "Monsters.h"
#include "Inventory.h"

enum class ECombatState
{
	InitBattle,
	PlayerTurn,
	CheckVictory,
	MonsterTurn,
	CheckDefeat,
	PlayerVictory,
	PlayerDefeat,

	PlayerUsingItem,
	PlayerSelectingSkill,
};

class CombatManager
{
private:
	ECombatState currentCombatState;

	Player* player;
	Inventory* inventory;
	Monster* monster;

public:
	bool isCombatRunning;

	CombatManager();

	void start(Player* player, Inventory* inventory, Monster* monster);
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

	void onPlayerUsingItem();
	void onPlayerSelectingSkill();
};
