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
	int rewardExp;
	std::vector<DropItemCandidate> dropItemCandidates;

	RewardDataRow(int rewardExp, std::vector<DropItemCandidate> dropItemCandidates);
};

extern const std::map<EMosnterType, RewardDataRow> REWARD_TABLE;

struct Reward
{
	int rewardExp;
	EItemID itemID;
	int itemCount;

	Reward(int rewardExp, EItemID itemID, int itemCount);
};

class RewardSystem
{
private:

public:
	static Reward GetReward(EMosnterType mosnterType); // 보상 반환
};

