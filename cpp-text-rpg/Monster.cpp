#include "Monster.h"

MonsterDataRow::MonsterDataRow(EMosnterType monsterType, string name, string description, int maxHP, int maxMP, int power, int defence)
	: monsterType(monsterType), name(name), description(description), maxHP(maxHP), maxMP(maxMP), power(power), defence(defence)
{
}

const map<EMosnterType, MonsterDataRow> MONSTER_TABLE = {
	{EMosnterType::Slime, MonsterDataRow(EMosnterType::Slime, "슬라임", "", 250, 0, 80, 45)},
	{EMosnterType::Goblin, MonsterDataRow(EMosnterType::Goblin, "고블린", "", 300, 0, 115, 40)},
	{EMosnterType::Skeleton, MonsterDataRow(EMosnterType::Skeleton, "스켈레톤", "", 270, 0, 130, 30)},
};

Monster::Monster(EMosnterType monsterType)
	: monsterType(monsterType), Character(
		MONSTER_TABLE.at(monsterType).name,
		MONSTER_TABLE.at(monsterType).maxHP,
		MONSTER_TABLE.at(monsterType).maxMP,
		MONSTER_TABLE.at(monsterType).power,
		MONSTER_TABLE.at(monsterType).defence
	)
{
}

Monster::Monster(string name, int maxHP, int maxMP, int power, int defence)
	: Character(name, maxHP, maxMP, power, defence)
{
}

EMosnterType Monster::getMonsterType()
{
	return monsterType;
}

void Monster::setMonsterType(EMosnterType monsterType)
{
	this->monsterType = monsterType;
}
