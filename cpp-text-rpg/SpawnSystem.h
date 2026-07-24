#pragma once

#include "Singleton.h"
#include "Monster.h"

#include <map>
#include <queue>

class SpawnSystem : public Singleton<SpawnSystem>
{
private:
	std::map<EMonsterType, std::queue<Monster*>> mosnterPoolMap;

public:
	SpawnSystem();
	~SpawnSystem();

	static Monster* GetMonsterFromPool(EMonsterType mosnterType);
	static Monster* GetRandomMonsterFromPool(const std::vector<EMonsterType>& monsterTypes, const std::vector<float>& weights = {});
	static void ReturnMonsterToPool(Monster* monster);
};

