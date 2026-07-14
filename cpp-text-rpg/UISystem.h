#pragma once

#include "Player.h"
#include "Character.h"

#include <map>

using namespace std;

class UISystem
{
private:
	static const map<EPlayerJob, string> jobNames;
public:
	static void PrintPlayerStat(Player* player);
	static void PrintBattleLog(Character* attacker, Character* defender, int damage);
};

