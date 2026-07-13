#pragma once

#include "Character.h"
#include "Item.h"
#include "RandomSystem.h"

enum class EMosnterType
{
	Slime,
	Goblin,
	Skeleton,
};

class Monster : public Character
{
protected:
	EMosnterType monsterType;

public:
	Monster(string name, int hp, int power, int defence);

	virtual EItemID getDropItemID() = 0;

	// Getters
	EMosnterType getMonsterType();

	// Setters
	void setMonsterType(EMosnterType monsterType);
};
