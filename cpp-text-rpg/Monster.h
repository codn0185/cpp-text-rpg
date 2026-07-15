#pragma once

#include "Character.h"

#include <map>

enum class EMosnterType
{
	Slime,
	Goblin,
	Skeleton,
};

struct MonsterDataRow
{
	EMosnterType monsterType;
	std::string name;
	std::string description;
	int maxHP;
	int maxMP;
	int power;
	int defence;

	MonsterDataRow(EMosnterType monsterType, std::string name, std::string description, int maxHP, int maxMP, int power, int defence);
};

extern const std::map<EMosnterType, MonsterDataRow> MONSTER_TABLE;

class Monster : public Character
{
protected:
	EMosnterType monsterType;

public:
	Monster(EMosnterType monsterType);
	Monster(std::string name, int maxHP, int maxMP, int power, int defence);

	// Getters
	EMosnterType getMonsterType();

	// Setters
	void setMonsterType(EMosnterType monsterType);
};
