#pragma once

#include "Player.h"
#include "Skill.h"

#include <vector>
#include <map>

struct SkillDataRow
{
	EPlayerJob playerJob;
	std::map<int, std::vector<SkillData>> skillsByLevel;

	SkillDataRow(EPlayerJob playerJob, std::map<int, std::vector<SkillData>> skillsByLevel);
};

extern const std::map<EPlayerJob, SkillDataRow> SKILL_TABLE;

class SkillSystem
{
private:

public:
	static void InitializePlayerSkills(Player* player); // 플레이어의 스킬 초기 설정
	static const std::vector<const SkillData*> UnlockSkillsForCurrentLevel(Player* player); // 현재 레벨에 맞는 스킬 해금

	static bool CanUse(const Skill* skill, const Character* character); // 스킬 사용 가능 여부 반환
	static void ApplySkill(Skill* skill, Character* attacker, Character* target); // 스킬 사용 및 적용
};

