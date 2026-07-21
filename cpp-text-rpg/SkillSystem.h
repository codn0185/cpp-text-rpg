#pragma once

#include "Player.h"
#include "Skill.h"

#include <vector>
#include <map>

struct SkillDataRow
{
	EPlayerJob playerJob;
	std::map<int, std::vector<Skill>> skillsByLevel;

	SkillDataRow(EPlayerJob playerJob, std::map<int, std::vector<Skill>> skillsByLevel);
};

extern const std::map<EPlayerJob, SkillDataRow> SKILL_TABLE;

class SkillSystem
{
private:

public:
	static void InitializePlayerSkills(Player* player); // 플레이어의 스킬 초기 설정
	static const std::vector<const Skill*> UnlockSkillsForCurrentLevel(Player* player); // 현재 레벨에 맞는 스킬 해금
};

