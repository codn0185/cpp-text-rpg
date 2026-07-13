#pragma once

#include "Character.h"

#include "Item.h"

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
	Item* dropItem;

public:
	Monster(string name, int hp, int power, int defence);

	// Getters
	Item* getDropItem();
	EMosnterType getMonsterType();

	// Setters
	void setDropItem(Item* dropItem);
	void setMonsterType(EMosnterType monsterType);
};
