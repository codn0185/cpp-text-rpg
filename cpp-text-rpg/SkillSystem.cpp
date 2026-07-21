#include "SkillSystem.h"

using namespace std;

SkillDataRow::SkillDataRow(EPlayerJob playerJob, map<int, vector<Skill>> skillsByLevel)
	: playerJob(playerJob), skillsByLevel(skillsByLevel)
{
}

const std::map<EPlayerJob, SkillDataRow> SKILL_TABLE = {
	{EPlayerJob::None, SkillDataRow(EPlayerJob::None, {
		{0, {Skill("기본 공격", 1.0f, 1, 0, 0)}},
	})},
	{EPlayerJob::Warrior, SkillDataRow(EPlayerJob::Warrior, {
		{0, {Skill("대검 휘두르기", 1.0f, 1, 0, 0)}},
		{2, {Skill("폭풍 베기", 1.4f, 1, 20, 4)}},
		{5, {Skill("대지 분쇄", 0.7f, 3, 15, 3)}},
		{10, {Skill("최후의 일격", 2.7f, 1, 60, 6)}},
	})},
	{EPlayerJob::Mage, SkillDataRow(EPlayerJob::Mage, {
		{0, {Skill("파이어볼", 1.0f, 1, 0, 0)}},
		{2, {Skill("전격 방출", 1.3f, 1, 10, 2)}},
		{5, {Skill("얼음 화살", 0.8f, 3, 45, 4)}},
		{10, {Skill("메테오 스트라이크", 3.0, 1, 80, 7)}},
	})},
	{EPlayerJob::Rogue, SkillDataRow(EPlayerJob::Rogue, {
		{0, {Skill("단검 베기", 1.0f, 1, 0, 0)}},
		{5, {Skill("잔상 5연격", 0.3f, 5, 15, 2)}},
		{2, {Skill("급소 찌르기", 1.6f, 1, 35, 4)}},
		{10, {Skill("핏빛 난무", 0.4f, 9, 70, 6)}},
	})},
	{EPlayerJob::Archer, SkillDataRow(EPlayerJob::Archer, {
		{0, {Skill("화살 쏘기", 1.0f, 1, 0, 0)}},
		{2, {Skill("3중 연사", 0.6f, 3, 15, 2)}},
		{5, {Skill("관통 화살", 1.5f, 1, 25, 3)}},
		{10, {Skill("필살의 사격", 2.4f, 1, 50, 5)}},
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
			for (const Skill& skill : AcquiredSkills)
			{
				player->addSkill(&skill);
			}
		}
	}
}

const vector<const Skill*> SkillSystem::UnlockSkillsForCurrentLevel(Player* player)
{
	if (SKILL_TABLE.find(player->getJob()) == SKILL_TABLE.end()) // 플레이어의 직업 스킬 확인
	{
		return;
	}

	vector<const Skill*> unlockedSkills; // 해금된 스킬들
	for (const auto& [requiredLevel, AcquiredSkills] : SKILL_TABLE.at(player->getJob()).skillsByLevel)
	{
		if (player->getLevel() == requiredLevel) // 현재 레벨과 일치
		{
			for (const Skill& skill : AcquiredSkills)
			{
				player->addSkill(&skill);
				unlockedSkills.push_back(&skill);
			}
		}
	}

	return unlockedSkills;
}
