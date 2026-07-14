#pragma once

#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();

	EItemID getDropItemID() override;
};

