#include "SpawnSystem.h"

#include "RandomSystem.h"

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

Monster* SpawnSystem::GetMonsterFromPool(EMonsterType mosnterType)
{
	auto& mosnterPoolMap = GetInstance().mosnterPoolMap;
	if (mosnterPoolMap[mosnterType].empty())
	{
		mosnterPoolMap[mosnterType].push(new Monster(mosnterType));
	}

	Monster* monster = mosnterPoolMap[mosnterType].front();
	mosnterPoolMap[mosnterType].pop();

	monster->reset();
	return monster;
}

Monster* SpawnSystem::GetRandomMonsterFromPool(const vector<EMonsterType>& monsterTypes, const vector<float>& weights)
{
	// 몬스터 타입 없음
	if (monsterTypes.empty())
	{
		return nullptr;
	}

	// 가중치 없음 - 동일 가중치 설정
	if (weights.empty())
	{
		EMonsterType mosnterType = RandomSystem::GetRandomByWeight<EMonsterType>(monsterTypes, vector<float>(monsterTypes.size(), 1.0f));
		return GetMonsterFromPool(mosnterType);
	}

	// 가중치 기반 확률로 몬스터 반환
	EMonsterType mosnterType = RandomSystem::GetRandomByWeight<EMonsterType>(monsterTypes, weights);
	return GetMonsterFromPool(mosnterType);
}

void SpawnSystem::ReturnMonsterToPool(Monster* monster)
{
	GetInstance().mosnterPoolMap[monster->getMonsterType()].push(monster);
}
