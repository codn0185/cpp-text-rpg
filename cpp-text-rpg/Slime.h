#pragma once

#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();

	EItemID getDropItemID() override;
};

