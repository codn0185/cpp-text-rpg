#include "Monster.h"

using namespace std;

MonsterDataRow::MonsterDataRow(EMonsterType monsterType, string name, string description, int maxHP, int maxMP, int power, int defence)
	: monsterType(monsterType), name(name), description(description), maxHP(maxHP), maxMP(maxMP), power(power), defence(defence)
{
}

const map<EMonsterType, MonsterDataRow> MONSTER_TABLE = {
	{EMonsterType::Slime, MonsterDataRow(EMonsterType::Slime, "슬라임", "", 250, 0, 80, 45)},
	{EMonsterType::Goblin, MonsterDataRow(EMonsterType::Goblin, "고블린", "", 300, 0, 115, 40)},
	{EMonsterType::Skeleton, MonsterDataRow(EMonsterType::Skeleton, "스켈레톤", "", 270, 0, 130, 30)},
};

Monster::Monster(EMonsterType monsterType)
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

EMonsterType Monster::getMonsterType()
{
	return monsterType;
}

void Monster::setMonsterType(EMonsterType monsterType)
{
	this->monsterType = monsterType;
}
