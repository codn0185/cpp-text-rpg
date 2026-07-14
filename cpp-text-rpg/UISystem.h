#pragma once

#include "Player.h"
#include "LevelSystem.h"

#include <map>

using namespace std;

class UISystem
{
private:
	static const map<EPlayerJob, string> jobNames;
public:
	static void PrintPlayerStat(Player* player);
};

