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
	int rewardExp;

	MonsterDataRow(EMosnterType monsterType, string name, string description, int maxHP, int maxMP, int power, int defence, int rewardExp) :
		monsterType(monsterType), name(name), description(description), maxHP(maxHP), maxMP(maxMP), power(power), defence(defence), rewardExp(rewardExp)
	{
	}
};

extern const map<EMosnterType, MonsterDataRow> MONSTER_TABLE;

class Monster : public Character
{
protected:
	EMosnterType monsterType;
	int rewardExp;

public:
	Monster(EMosnterType monsterType);
	Monster(string name, int maxHP, int maxMP, int power, int defence);

	virtual EItemID getDropItemID() = 0;

	// Getters
	EMosnterType getMonsterType();
	int getRewardExp();

	// Setters
	void setMonsterType(EMosnterType monsterType);
	void setRewardExp(int rewardExp);
};
