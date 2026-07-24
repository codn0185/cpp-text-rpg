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

Monster* SpawnSystem::getRandomMonsterFromPool(vector<EMonsterType> monsterTypes, vector<float> weights)
{
	// 몬스터 타입 없음
	if (monsterTypes.empty())
	{
		return nullptr;
	}

	// 가중치 없음 - 동일 가중치로 지정
	if (weights.empty())
	{
		weights.assign(monsterTypes.size(), 1.0f);
	}

	// 가중치 기반 확률로 몬스터 반환
	EMonsterType mosnterType = RandomSystem::GetRandomByWeight<EMonsterType>(monsterTypes, weights);
	return getMonsterFromPool(mosnterType);
}

void SpawnSystem::returnMonsterToPool(Monster* monster)
{
	mosnterPoolMap[monster->getMonsterType()].push(monster);
}
