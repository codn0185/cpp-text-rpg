#pragma once

#include "Items.h"
#include "Monsters.h"

#include <vector>
#include <map>

struct DropItemCandidate
{
	EItemID itemID;
	float dropWeight;
	int minCount;
	int maxCount;

	DropItemCandidate(EItemID itemID, float dropWeight, int minCount, int maxCount);
};

struct RewardDataRow
{
	int exp;
	int gold;
	std::vector<DropItemCandidate> dropItemCandidates;

	RewardDataRow(int exp, int gold, std::vector<DropItemCandidate> dropItemCandidates);
};

extern const std::map<EMonsterType, RewardDataRow> REWARD_TABLE;

struct Reward
{
	int exp;
	int gold;
	EItemID itemID;
	int itemCount;

	Reward(int exp, int gold, EItemID itemID, int itemCount);
};

class RewardSystem
{
private:

public:
	static Reward GetReward(EMonsterType mosnterType); // 보상 반환
};

