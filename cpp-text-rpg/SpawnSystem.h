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
	Monster* getRandomMonsterFromPool(const std::vector<EMonsterType>& monsterTypes, const std::vector<float>& weights = {});
	void returnMonsterToPool(Monster* monster);
};

