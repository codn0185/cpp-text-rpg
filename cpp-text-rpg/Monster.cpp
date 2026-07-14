#include "Monster.h"

const map<EMosnterType, MonsterDataRow> MONSTER_TABLE = {
	{EMosnterType::Slime, MonsterDataRow(EMosnterType::Slime, "슬라임", "", 250, 0, 80, 45, 30)},
	{EMosnterType::Goblin, MonsterDataRow(EMosnterType::Goblin, "고블린", "", 300, 0, 115, 40, 32)},
	{EMosnterType::Skeleton, MonsterDataRow(EMosnterType::Skeleton, "스켈레톤", "", 270, 0, 130, 30, 35)},
};

Monster::Monster(EMosnterType monsterType) : monsterType(monsterType)
{
	const MonsterDataRow& row = MONSTER_TABLE.at(monsterType);
	setName(row.name);
	setMaxHP(row.maxHP);
	setMaxMP(row.maxMP);
	setPower(row.power);
	setDefence(row.defence);
	setRewardExp(row.rewardExp);

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

int Monster::getRewardExp()
{
	return rewardExp;
}

void Monster::setMonsterType(EMosnterType monsterType)
{
	this->monsterType = monsterType;
}

void Monster::setRewardExp(int rewardExp)
{
	this->rewardExp = rewardExp;
}
