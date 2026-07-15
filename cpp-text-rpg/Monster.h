#pragma once

#include "Character.h"
#include "Item.h"
#include "RandomSystem.h"

#include <map>

using namespace std;

enum class EMosnterType
{
	Slime,
	Goblin,
	Skeleton,
};

struct MonsterDataRow
{
	EMosnterType monsterType;
	string name;
	string description;
	int maxHP;
	int maxMP;
	int power;
	int defence;

	MonsterDataRow(EMosnterType monsterType, string name, string description, int maxHP, int maxMP, int power, int defence);
};

extern const map<EMosnterType, MonsterDataRow> MONSTER_TABLE;

class Monster : public Character
{
protected:
	EMosnterType monsterType;

public:
	Monster(EMosnterType monsterType);
	Monster(string name, int maxHP, int maxMP, int power, int defence);

	// Getters
	EMosnterType getMonsterType();

	// Setters
	void setMonsterType(EMosnterType monsterType);
};
