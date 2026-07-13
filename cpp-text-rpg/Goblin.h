#pragma once

#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin(string name, int hp, int power, int defence);

	EItemID getDropItemID() override;
};

