#include "RewardSystem.h"

#include "RandomSystem.h"


DropItemCandidate::DropItemCandidate(EItemID itemID, float dropWeight, int minCount, int maxCount)
	: itemID(itemID), dropWeight(dropWeight), minCount(minCount), maxCount(maxCount)
{
}

RewardDataRow::RewardDataRow(int rewardExp, vector<DropItemCandidate> dropItemCandidates)
	: rewardExp(rewardExp), dropItemCandidates(dropItemCandidates)
{
}

const map<EMosnterType, RewardDataRow> REWARD_TABLE = {
	{EMosnterType::Slime, RewardDataRow(30, {
		DropItemCandidate(EItemID::SLIME_JELLY, 40., 1, 3),
		DropItemCandidate(EItemID::WATER, 30., 1, 3),
	})},
	{EMosnterType::Goblin, RewardDataRow(32, {
		DropItemCandidate(EItemID::GOBLIN_BLOOD, 40., 1, 3),
		DropItemCandidate(EItemID::HEALING_HERB, 30., 1, 2),
	})},
	{EMosnterType::Skeleton, RewardDataRow(35, {
		DropItemCandidate(EItemID::SKELETON_BONE, 40., 1, 3),
		DropItemCandidate(EItemID::MANA_DUST, 30., 1, 2),
	})},
};

Reward::Reward(int rewardExp, EItemID itemID, int itemCount)
	: rewardExp(), itemID(itemID), itemCount(itemCount)
{
}

Reward RewardSystem::getReward(EMosnterType mosnterType)
{
	vector<float> weights;
	for (DropItemCandidate dropItemCandidate : REWARD_TABLE.at(mosnterType).dropItemCandidates)
	{
		weights.push_back(dropItemCandidate.dropWeight);
	}

	int rewardExp = REWARD_TABLE.at(mosnterType).rewardExp;
	DropItemCandidate dropItem = RandomSystem::GetRandomByWeight<DropItemCandidate>(REWARD_TABLE.at(mosnterType).dropItemCandidates, weights);
	int dropItemCount = RandomSystem::GetRandomInt(dropItem.minCount, dropItem.maxCount);

	return Reward(rewardExp, dropItem.itemID, dropItemCount);
}
