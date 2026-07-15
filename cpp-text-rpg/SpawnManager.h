#pragma once

#include "Monster.h"

#include <map>
#include <queue>

class SpawnManager
{
private:
	std::map<EMosnterType, std::queue<Monster*>> mosnterPoolMap;

public:
	SpawnManager();
	~SpawnManager();

	Monster* getMonsterFromPool(EMosnterType mosnterType);
	Monster* getRandomMonsterFromPool();
	void returnMonsterToPool(Monster* monster);
};

