#pragma once

#include "Monster.h"

#include <map>
#include <queue>
#include <random>

class SpawnManager
{
private:
	mt19937 gen_;
	uniform_int_distribution<int> dist_;

	map<EMosnterType, queue<Monster*>> mosnterPoolMap;

public:
	SpawnManager();
	~SpawnManager();

	Monster* getMonsterFromPool(EMosnterType mosnterType);
	Monster* getRandomMonsterFromPool();
	void returnMonsterToPool(Monster* monster);
};

