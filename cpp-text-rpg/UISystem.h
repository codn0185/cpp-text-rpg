#pragma once

#include "Player.h"
#include "Character.h"

#include <map>

class UISystem
{
private:
	static const std::map<EPlayerJob, std::string> jobNames;
public:
	static void PrintPlayerStat(const Player* player);
	static void PrintBattleLog(const Character* attacker, const Character* defender, const int damage);
};

