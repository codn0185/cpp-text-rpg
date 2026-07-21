#include "SkillSystem.h"

using namespace std;

SkillDataRow::SkillDataRow(EPlayerJob playerJob, map<int, vector<Skill>> skillsByLevel)
	: playerJob(playerJob), skillsByLevel(skillsByLevel)
{
}

const std::map<EPlayerJob, SkillDataRow> SKILL_TABLE = {
	{EPlayerJob::None, SkillDataRow(EPlayerJob::None, {
		{0, {Skill("기본 공격", 1.0, 1, 0, 0)}},
	})},
	{EPlayerJob::Warrior, SkillDataRow(EPlayerJob::Warrior, {
		{0, {Skill("대검 휘두르기", 1.0, 1, 0, 0)}},
		{2, {Skill("폭풍 베기", 1.4, 1, 20, 4)}},
		{5, {Skill("대지 분쇄", 0.7, 3, 15, 3)}},
		{10, {Skill("최후의 일격", 2.7, 1, 60, 6)}},
	})},
	{EPlayerJob::Mage, SkillDataRow(EPlayerJob::Mage, {
		{0, {Skill("파이어볼", 1.0, 1, 0, 0)}},
		{2, {Skill("전격 방출", 1.3, 1, 10, 2)}},
		{5, {Skill("얼음 화살", 0.8, 3, 45, 4)}},
		{10, {Skill("메테오 스트라이크", 3.0, 1, 80, 7)}},
	})},
	{EPlayerJob::Rogue, SkillDataRow(EPlayerJob::Rogue, {
		{0, {Skill("단검 베기", 1, 1, 0, 0)}},
		{5, {Skill("잔상 5연격", 0.3, 5, 15, 2)}},
		{2, {Skill("급소 찌르기", 1.6, 1, 35, 4)}},
		{10, {Skill("핏빛 난무", 0.4, 9, 70, 6)}},
	})},
	{EPlayerJob::Archer, SkillDataRow(EPlayerJob::Archer, {
		{0, {Skill("화살 쏘기", 1, 1, 0, 0)}},
		{2, {Skill("3중 연사", 0.6, 3, 15, 2)}},
		{5, {Skill("관통 화살", 1.5, 1, 25, 3)}},
		{10, {Skill("필살의 사격", 2.4, 1, 50, 5)}},
	})},
};
