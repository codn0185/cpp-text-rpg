#include "SkillSystem.h"

#include "UISystem.h"

#include <algorithm>

using namespace std;

SkillDataRow::SkillDataRow(EPlayerJob playerJob, map<int, vector<SkillData>> skillsByLevel)
	: playerJob(playerJob), skillsByLevel(skillsByLevel)
{
}

const std::map<EPlayerJob, SkillDataRow> SKILL_TABLE = {
	{EPlayerJob::None, SkillDataRow(EPlayerJob::None, {
		{0,		{SkillData("기본 공격",		1.0f, 1, 0, 0)}},
	})},
	{EPlayerJob::Warrior, SkillDataRow(EPlayerJob::Warrior, {
		{0,		{SkillData("대검 휘두르기",	1.0f, 1, 0, 0)}},
		{2,		{SkillData("폭풍 베기",		1.4f, 1, 20, 4)}},
		{5,		{SkillData("대지 분쇄",		0.75f, 3, 15, 3)}},
		{10,	{SkillData("최후의 일격",	2.7f, 1, 60, 6)}},
	})},
	{EPlayerJob::Mage, SkillDataRow(EPlayerJob::Mage, {
		{0,		{SkillData("파이어볼",		1.0f, 1, 0, 0)}},
		{2,		{SkillData("전격 방출",		1.3f, 1, 10, 2)}},
		{5,		{SkillData("얼음 화살",		0.8f, 3, 45, 4)}},
		{10,	{SkillData("메테오 스트라이크", 3.0, 1, 80, 7)}},
	})},
	{EPlayerJob::Rogue, SkillDataRow(EPlayerJob::Rogue, {
		{0,		{SkillData("단검 베기",		1.0f, 1, 0, 0)}},
		{5,		{SkillData("잔상 5연격",		0.6f, 5, 15, 2)}},
		{2,		{SkillData("급소 찌르기",	1.6f, 1, 35, 4)}},
		{10,	{SkillData("핏빛 난무",		0.7f, 9, 70, 6)}},
	})},
	{EPlayerJob::Archer, SkillDataRow(EPlayerJob::Archer, {
		{0,		{SkillData("화살 쏘기",		1.0f, 1, 0, 0)}},
		{2,		{SkillData("3중 연사",		0.7f, 3, 15, 2)}},
		{5,		{SkillData("관통 화살",		1.5f, 1, 25, 3)}},
		{10,	{SkillData("필살의 사격",	2.4f, 1, 50, 5)}},
	})},
};

void SkillSystem::InitializePlayerSkills(Player* player)
{
	player->resetSkills(); // 스킬 초기화

	if (SKILL_TABLE.find(player->getJob()) == SKILL_TABLE.end()) // 플레이어의 직업 스킬 확인
	{
		return;
	}

	for (const auto& [requiredLevel, AcquiredSkills] : SKILL_TABLE.at(player->getJob()).skillsByLevel)
	{
		if (player->getLevel() >= requiredLevel) // 현재 레벨 이하
		{
			for (const SkillData& skillData : AcquiredSkills)
			{
				player->addSkill(&skillData);
			}
		}
	}
}

const vector<const SkillData*> SkillSystem::UnlockSkillsForCurrentLevel(Player* player)
{
	vector<const SkillData*> unlockedSkills; // 해금된 스킬들

	if (SKILL_TABLE.find(player->getJob()) == SKILL_TABLE.end()) // 플레이어의 직업 스킬 확인
	{
		return unlockedSkills;
	}

	for (const auto& [requiredLevel, AcquiredSkills] : SKILL_TABLE.at(player->getJob()).skillsByLevel) // 직업 스킬 순회
	{
		if (player->getLevel() == requiredLevel) // 현재 레벨과 일치
		{
			for (const SkillData& skillData : AcquiredSkills)
			{
				player->addSkill(&skillData);
				unlockedSkills.push_back(&skillData);
			}
		}
	}

	return unlockedSkills;
}

bool SkillSystem::CanUse(const shared_ptr<Skill> skill, const Character* character)
{
	if (!skill->isReady()) return false; // 쿨다운
	if (character->getCurrentMP() < skill->getMPCost()) return false; // 마나 부족
	return true; // 사용 가능
}

void SkillSystem::UseSkill(shared_ptr<Skill> skill, Character* attacker, Character* target)
{
	if (!CanUse(skill, attacker)) return; // 스킬 사용 불가능

	// 스킬 사용
	attacker->setCurrentMP(attacker->getCurrentMP() - skill->getMPCost()); // 마나 소모
	skill->startCooldown(); // 쿨다운 시작
	int singleHitDamage = max(1, int(skill->getDamageMultiplier() * attacker->getPower()) - target->getDefence());
	int hitCount = skill->getAttackCount();
	while (!target->isDead() && hitCount--)
	{
		target->takeDamage(singleHitDamage);
		UISystem::PrintBattleLog(attacker, target, singleHitDamage);
	}
}
