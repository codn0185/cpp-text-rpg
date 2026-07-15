#pragma once

#include "Monster.h"

class Skeleton : public Monster
{
public:
	Skeleton();

	void attack(Character* target) override;
};
