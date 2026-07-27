#include "RewardSystem.h"

#include "RandomSystem.h"

using namespace std;

DropItemCandidate::DropItemCandidate(EItemID itemID, float dropWeight, int minCount, int maxCount)
	: itemID(itemID), dropWeight(dropWeight), minCount(minCount), maxCount(maxCount)
{
}

RewardDataRow::RewardDataRow(int exp, int gold, vector<DropItemCandidate> dropItemCandidates)
	: exp(exp), gold(gold), dropItemCandidates(dropItemCandidates)
{
}

const map<EMonsterType, RewardDataRow> REWARD_TABLE = {
	{EMonsterType::Slime, RewardDataRow(30, 12, {
		DropItemCandidate(EItemID::SLIME_JELLY, 40., 1, 3),
		DropItemCandidate(EItemID::WATER, 30., 1, 3),
	})},
	{EMonsterType::Goblin, RewardDataRow(32, 14, {
		DropItemCandidate(EItemID::GOBLIN_DAGGER, 40., 1, 3),
		DropItemCandidate(EItemID::HEALING_HERB, 30., 1, 2),
	})},
	{EMonsterType::Bat, RewardDataRow(28, 11, {
		DropItemCandidate(EItemID::BAT_FANG, 40., 1, 3),
		DropItemCandidate(EItemID::MANA_DUST, 30., 1, 2),
	})},

	{EMonsterType::Zombie, RewardDataRow(60, 25, {
		DropItemCandidate(EItemID::ZOMBIE_LEATHER, 40., 1, 3),
		DropItemCandidate(EItemID::BOTTLE, 10., 1, 2),
	})},
	{EMonsterType::Skeleton, RewardDataRow(57, 28, {
		DropItemCandidate(EItemID::SKELETON_BONE, 40., 1, 3),
		DropItemCandidate(EItemID::HEALING_HERB, 30., 1, 2),
	})},
	{EMonsterType::Ghost, RewardDataRow(70, 20, {
		DropItemCandidate(EItemID::GHOST_ESSENCE, 40., 1, 3),
		DropItemCandidate(EItemID::MANA_DUST, 30., 1, 2),
	})},

	{EMonsterType::Ork, RewardDataRow(135, 52, {
		DropItemCandidate(EItemID::ORK_TENDON, 40., 1, 3),
		DropItemCandidate(EItemID::BOTTLE, 10., 1, 2),
	})},
	{EMonsterType::Lizardman, RewardDataRow(127, 55, {
		DropItemCandidate(EItemID::LIZARDMAN_SCALE, 40., 1, 3),
		DropItemCandidate(EItemID::HEALING_HERB, 30., 1, 2),
	})},
	{EMonsterType::Gargoyle, RewardDataRow(130, 57, {
		DropItemCandidate(EItemID::GARGOYLE_SHARD, 40., 1, 3),
		DropItemCandidate(EItemID::MANA_DUST, 30., 1, 2),
	})},

	{EMonsterType::Dragon, RewardDataRow(300, 150, {
		DropItemCandidate(EItemID::DRAGON_CORE, 1., 1, 1),
	})},
};

Reward::Reward(int exp, int gold, EItemID itemID, int itemCount)
	: exp(exp), gold(gold), itemID(itemID), itemCount(itemCount)
{
}

Reward RewardSystem::GetReward(EMonsterType mosnterType)
{
	// REWARD_TABLE에 없음
	if (REWARD_TABLE.find(mosnterType) == REWARD_TABLE.end())
	{
		return Reward(0, 0, EItemID::NONE, 0);
	}

	vector<float> weights; // 아이템 가중치
	for (DropItemCandidate dropItemCandidate : REWARD_TABLE.at(mosnterType).dropItemCandidates)
	{
		weights.push_back(dropItemCandidate.dropWeight);
	}

	int rewardExp = REWARD_TABLE.at(mosnterType).exp;
	int rewardGold = REWARD_TABLE.at(mosnterType).gold;
	DropItemCandidate dropItem = RandomSystem::GetRandomByWeight<DropItemCandidate>(REWARD_TABLE.at(mosnterType).dropItemCandidates, weights);
	int dropItemCount = RandomSystem::GetRandomInt(dropItem.minCount, dropItem.maxCount);

	return Reward(rewardExp, rewardGold, dropItem.itemID, dropItemCount);
}
