#pragma once

#include "Monster.h"

class Skeleton : public Monster
{
public:
	Skeleton();

	EItemID getDropItemID() override;
};
