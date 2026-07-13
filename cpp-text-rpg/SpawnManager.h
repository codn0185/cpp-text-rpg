#pragma once

#include "Monster.h"
#include "RandomSystem.h"

#include <map>
#include <queue>

class SpawnManager
{
private:
	map<EMosnterType, queue<Monster*>> mosnterPoolMap;

public:
	SpawnManager();
	~SpawnManager();

	Monster* getMonsterFromPool(EMosnterType mosnterType);
	Monster* getRandomMonsterFromPool();
	void returnMonsterToPool(Monster* monster);
};

