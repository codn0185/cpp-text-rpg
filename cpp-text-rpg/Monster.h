#pragma once

#include "Character.h"

#include <map>

enum class EMonsterType
{
	Slime,
	Goblin,
	Skeleton,
};

struct MonsterDataRow
{
	EMonsterType monsterType;
	std::string name;
	std::string description;
	int maxHP;
	int maxMP;
	int power;
	int defence;

	MonsterDataRow(EMonsterType monsterType, std::string name, std::string description, int maxHP, int maxMP, int power, int defence);
};

extern const std::map<EMonsterType, MonsterDataRow> MONSTER_TABLE;

class Monster : public Character
{
protected:
	EMonsterType monsterType;

public:
	Monster(EMonsterType monsterType);
	Monster(std::string name, int maxHP, int maxMP, int power, int defence);

	// Getters
	EMonsterType getMonsterType();

	// Setters
	void setMonsterType(EMonsterType monsterType);
};
