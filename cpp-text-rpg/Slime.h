#pragma once

#include "Monster.h"

class Slime : public Monster
{
public:
	Slime(string name, int hp, int power, int defence);

	EItemID getDropItemID() override;
};

