#pragma once

#include "Monster.h"

#include <map>
#include <queue>

class SpawnSystem
{
private:
	std::map<EMonsterType, std::queue<Monster*>> mosnterPoolMap;

public:
	SpawnSystem();
	~SpawnSystem();

	Monster* getMonsterFromPool(EMonsterType mosnterType);
	Monster* getRandomMonsterFromPool(std::vector<EMonsterType> monsterTypes, std::vector<float> weights = {});
	void returnMonsterToPool(Monster* monster);
};

