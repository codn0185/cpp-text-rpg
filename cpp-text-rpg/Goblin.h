#pragma once

#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();

	void attack(Character* target) override;
};

