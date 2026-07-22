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

Monster* SpawnSystem::getMonsterFromPool(EMosnterType mosnterType)
{
	if (mosnterPoolMap[mosnterType].empty())
	{
		switch (mosnterType)
		{
		case EMosnterType::Slime:
			mosnterPoolMap[mosnterType].push(new Slime());
			break;
		case EMosnterType::Goblin:
			mosnterPoolMap[mosnterType].push(new Goblin());
			break;
		case EMosnterType::Skeleton:
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
	vector<EMosnterType> mosnterTypes = {EMosnterType::Slime, EMosnterType::Goblin, EMosnterType::Skeleton};
	EMosnterType mosnterType = RandomSystem::GetRandomByWeight<EMosnterType>(mosnterTypes, {1, 1, 1});

	return getMonsterFromPool(mosnterType);
}

void SpawnSystem::returnMonsterToPool(Monster* monster)
{
	mosnterPoolMap[monster->getMonsterType()].push(monster);
}
