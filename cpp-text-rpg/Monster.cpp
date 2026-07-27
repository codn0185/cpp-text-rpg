#include "Monster.h"

#include "UISystem.h"

using namespace std;

MonsterDataRow::MonsterDataRow(EMonsterType monsterType, string name, string description, int maxHP, int maxMP, int power, int defence)
	: monsterType(monsterType), name(name), description(description), maxHP(maxHP), maxMP(maxMP), power(power), defence(defence)
{
}

const map<EMonsterType, MonsterDataRow> MONSTER_TABLE = {
	// 1층
	{ EMonsterType::Slime,     MonsterDataRow(EMonsterType::Slime,     "슬라임",   "",	250, 0,  80, 45) },
	{ EMonsterType::Goblin,    MonsterDataRow(EMonsterType::Goblin,    "고블린",   "",	300, 0, 115, 40) },
	{ EMonsterType::Bat,       MonsterDataRow(EMonsterType::Bat,       "박쥐",     "",	270, 0, 130, 30) },

	// 2층
	{ EMonsterType::Zombie,    MonsterDataRow(EMonsterType::Zombie,    "좀비",     "",	550, 0, 140, 50) },
	{ EMonsterType::Skeleton,  MonsterDataRow(EMonsterType::Skeleton,  "스켈레톤", "",	420, 0, 160, 75) },
	{ EMonsterType::Ghost,     MonsterDataRow(EMonsterType::Ghost,     "고스트",   "",	380, 50, 185, 40) },

	// 3층
	{ EMonsterType::Ork,       MonsterDataRow(EMonsterType::Ork,       "오크",     "",	950, 0, 240, 65) },
	{ EMonsterType::Lizardman, MonsterDataRow(EMonsterType::Lizardman, "리자드맨", "",	750, 0, 210, 85) },
	{ EMonsterType::Gargoyle,  MonsterDataRow(EMonsterType::Gargoyle,  "가고일",   "",	800, 30, 225, 110) },

	// 보스방
	{ EMonsterType::Dragon,    MonsterDataRow(EMonsterType::Dragon,    "드래곤",   "",	2400, 200, 320, 150) }
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

Monster::Monster(EMonsterType monsterType, string name, int maxHP, int maxMP, int power, int defence)
	: Character(name, maxHP, maxMP, power, defence)
{
}

void Monster::attack(Character* target)
{
	int damage = power - target->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	target->takeDamage(damage);
	UISystem::PrintBattleLog(this, target, damage);
}

EMonsterType Monster::getMonsterType()
{
	return monsterType;
}

void Monster::setMonsterType(EMonsterType monsterType)
{
	this->monsterType = monsterType;
}
