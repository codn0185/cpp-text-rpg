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
};

