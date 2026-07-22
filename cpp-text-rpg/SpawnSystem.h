#pragma once

#include "Monster.h"

#include <map>
#include <queue>

class SpawnSystem
{
private:
	std::map<EMosnterType, std::queue<Monster*>> mosnterPoolMap;

public:
	SpawnSystem();
	~SpawnSystem();

	Monster* getMonsterFromPool(EMosnterType mosnterType);
	Monster* getRandomMonsterFromPool();
	void returnMonsterToPool(Monster* monster);
};

