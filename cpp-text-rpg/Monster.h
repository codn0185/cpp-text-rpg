#pragma once

#include "Character.h"

#include <map>

enum class EMonsterType
{
	// 1층
	Slime,
	Goblin,
	Bat,

	// 2층
	Skeleton,
	Zombie,
	Ghost,

	// 3층
	Ork,
	Lizardman,
	Gargoyle,

	// 보스
	Dragon,
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

	void attack(Character* target) override;

	// Getters
	EMonsterType getMonsterType();

	// Setters
	void setMonsterType(EMonsterType monsterType);
};
