#include "SpawnManager.h"

#include "Monsters.h"

SpawnManager::SpawnManager() : gen_(std::random_device{}())
{
}

SpawnManager::~SpawnManager()
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

Monster* SpawnManager::getMonsterFromPool(EMosnterType mosnterType)
{
	if (mosnterPoolMap[mosnterType].empty())
	{
		switch (mosnterType)
		{
		case EMosnterType::Slime:
			mosnterPoolMap[mosnterType].push(new Slime("슬라임", 120, 25, 60));
			break;
		case EMosnterType::Goblin:
			mosnterPoolMap[mosnterType].push(new Goblin("고블린", 100, 35, 40));
			break;
		case EMosnterType::Skeleton:
			mosnterPoolMap[mosnterType].push(new Skeleton("스켈레톤", 75, 50, 30));
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

Monster* SpawnManager::getRandomMonsterFromPool()
{
	vector<EMosnterType> mosnterTypes = {EMosnterType::Slime, EMosnterType::Goblin, EMosnterType::Skeleton};
	uniform_int_distribution<size_t> dist_(0, mosnterTypes.size() - 1);
	EMosnterType mosnterType = mosnterTypes[dist_(gen_)];

	return getMonsterFromPool(mosnterType);
}

void SpawnManager::returnMonsterToPool(Monster* monster)
{
	mosnterPoolMap[monster->getMonsterType()].push(monster);
}
