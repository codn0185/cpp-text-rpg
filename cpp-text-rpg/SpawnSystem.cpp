#include "SpawnSystem.h"

#include "RandomSystem.h"
#include "Monsters.h"

using namespace std;

SpawnSystem::SpawnSystem()
{
}

SpawnSystem::~SpawnSystem()
{
	for (auto iter = mosnterPoolMap.begin(); iter != mosnterPoolMap.end(); iter++)
	{
		auto q = iter->second;
		while (!q.empty())
		{
			delete q.front();
			q.pop();
		}
	}
}

Monster* SpawnSystem::getMonsterFromPool(EMonsterType mosnterType)
{
	if (mosnterPoolMap[mosnterType].empty())
	{
		switch (mosnterType)
		{
		case EMonsterType::Slime:
			mosnterPoolMap[mosnterType].push(new Slime());
			break;
		case EMonsterType::Goblin:
			mosnterPoolMap[mosnterType].push(new Goblin());
			break;
		case EMonsterType::Skeleton:
			mosnterPoolMap[mosnterType].push(new Skeleton());
			break;
		default:
			break;
		}
	}

	Monster* monster = mosnterPoolMap[mosnterType].front();
	mosnterPoolMap[mosnterType].pop();

	monster->reset();
	return monster;
}

Monster* SpawnSystem::getRandomMonsterFromPool()
{
	vector<EMonsterType> mosnterTypes = {EMonsterType::Slime, EMonsterType::Goblin, EMonsterType::Skeleton};
	EMonsterType mosnterType = RandomSystem::GetRandomByWeight<EMonsterType>(mosnterTypes, {1, 1, 1});

	return getMonsterFromPool(mosnterType);
}

void SpawnSystem::returnMonsterToPool(Monster* monster)
{
	mosnterPoolMap[monster->getMonsterType()].push(monster);
}
