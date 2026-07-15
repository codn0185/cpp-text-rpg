#pragma once

#include "Player.h"
#include "Character.h"

#include <map>

class UISystem
{
private:
	static const std::map<EPlayerJob, std::string> jobNames;
public:
	static void PrintPlayerStat(Player* player);
	static void PrintBattleLog(Character* attacker, Character* defender, int damage);
};

