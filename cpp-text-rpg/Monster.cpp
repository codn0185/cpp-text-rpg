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

Monster::Monster(EMosnterType monsterType) : monsterType(monsterType)
{
	const MonsterDataRow& row = MONSTER_TABLE.at(monsterType);
	setName(row.name);
	setMaxHP(row.maxHP);
	setMaxMP(row.maxMP);
	setPower(row.power);
	setDefence(row.defence);

	reset();
}

Monster::Monster(string name, int maxHP, int maxMP, int power, int defence)
{
	setName(name);
	setMaxHP(maxHP);
	setMaxMP(maxMP);
	setPower(power);
	setDefence(defence);

	reset();
}

EMosnterType Monster::getMonsterType()
{
	return monsterType;
}

void Monster::setMonsterType(EMosnterType monsterType)
{
	this->monsterType = monsterType;
}
